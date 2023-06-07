#include "databaseview.h"
#include "ui_databaseview.h"
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlDatabase>
#include <QMessageBox>
#include <QtSql/QSqlTableModel>
#include <QtSql/QSqlRecord>
#include <QFile>


DatabaseWorker::DatabaseWorker(QSqlTableModel *model, QObject *parent)
    : QObject(parent), model_(model)
{
}

void DatabaseWorker::addRecord(const QString &name, const QByteArray &image)
{
    QSqlRecord record = model_->record();
    record.setValue("name", name);
    record.setValue("image", QVariant(image));
    if (!model_->insertRecord(-1, record)) {
        emit error("Failed to add record.");
        return;
    }
    if (!model_->submitAll()) {
        emit error("Failed to submit changes.");
        return;
    }
}

void DatabaseWorker::updateRecord(int row, const QString &name, const QByteArray &image)
{
    QSqlRecord record = model_->record(row);
    record.setValue("name", name);

    record.setValue("image", QVariant(image));
    if (!model_->setRecord(row, record)) {
       emit error("Failed to update record.");
    }

    if (!model_->submitAll()) {
        emit error("Failed to submit changes.");
        return;
    }
}

void DatabaseWorker::deleteRecord(int row)
{
    if (!model_->removeRow(row)) {
        emit error("Failed to delete record.");
    }

    if (!model_->submitAll()) {
        emit error("Failed to submit delete.");
        return;
    }
}



databaseview::databaseview(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::databaseview)
{
    ui->setupUi(this);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("test.db");
    if (!db.open()) {
        QMessageBox::warning(this, "Error", "Failed to open database.");
        return;
    }

    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS person (id INTEGER PRIMARY KEY AUTOINCREMENT, name VARCHAR(50), image BLOB)");

    QSqlTableModel *model = new QSqlTableModel(this, db);
    model->setTable("person");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();

    worker = new DatabaseWorker(model, this);

    ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(0, true);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    connect(ui->addBtn, &QPushButton::clicked, [this]() {


        QString imagePath = ui->filePathEdit->text();
        QFile imagefile(imagePath);

        if (!imagefile.open(QIODevice::ReadOnly)) {
            QMessageBox::warning(this, "Error", "Failed to open file");
            return;
        }
        QByteArray data = imagefile.readAll();
        imagefile.close();

        emit addRecord(ui->nameEdit->text(), data);
    });

    connect(ui->updateBtn, &QPushButton::clicked, [this, model]() {
        if (!ui->tableView->currentIndex().isValid()) {
            QMessageBox::warning(this, "Error", "Please select a record.");
            return;
        }
        int row = ui->tableView->currentIndex().row();

        QString imagePath = ui->filePathEdit->text();
        QFile imagefile(imagePath);

        if (!imagefile.open(QIODevice::ReadOnly)) {
            QMessageBox::warning(this, "Error", "Failed to open file");
            return;
        }
        QByteArray data = imagefile.readAll();
        imagefile.close();

        emit updateRecord(row, ui->nameEdit->text(), data);
    });

    connect(ui->deleteBtn, &QPushButton::clicked, [this, model]() {
        if (!ui->tableView->currentIndex().isValid()) {
            QMessageBox::warning(this, "Error", "Please select a record.");
            return;
        }
        int row = ui->tableView->currentIndex().row();
        emit deleteRecord(row);
    });

    connect(this, &databaseview::addRecord, worker, &DatabaseWorker::addRecord);
    connect(this, &databaseview::updateRecord, worker, &DatabaseWorker::updateRecord);
    connect(this, &databaseview::deleteRecord, worker, &DatabaseWorker::deleteRecord);
    connect(worker, &DatabaseWorker::error, this, &databaseview::showError);
    worker->moveToThread(&workerThread);
    connect(&workerThread, &QThread::finished, worker, &QObject::deleteLater);
    workerThread.start();
}

void databaseview::showError(const QString &msg)
{
    QMessageBox::warning(this, "Error", msg);
}

databaseview::~databaseview()
{
    workerThread.quit();
    workerThread.wait();
    delete ui;
}

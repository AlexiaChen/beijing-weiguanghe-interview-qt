#ifndef DATABASEVIEW_H
#define DATABASEVIEW_H

#include <QWidget>
#include <QThread>

namespace Ui {
class databaseview;
}

class QSqlTableModel;
class DatabaseWorker;

class DatabaseWorker : public QObject
{
    Q_OBJECT

public:
    explicit DatabaseWorker(QSqlTableModel *model, QObject *parent = nullptr);

public slots:
    void addRecord(const QString &name, const QByteArray &image);
    void updateRecord(int row, const QString &name, const QByteArray &image);
    void deleteRecord(int row);

signals:
    void error(const QString &msg);

private:
    QSqlTableModel *model_;
};

class databaseview : public QWidget
{
    Q_OBJECT

public:
    explicit databaseview(QWidget *parent = nullptr);
    ~databaseview();

signals:
    void addRecord(const QString &name, const QByteArray &image);
    void updateRecord(int row, const QString &name, const QByteArray &image);
    void deleteRecord(int row);

public slots:
    void showError(const QString &msg);

private:
    Ui::databaseview *ui;
    QThread workerThread;
    DatabaseWorker *worker;
};

#endif // DATABASEVIEW_H

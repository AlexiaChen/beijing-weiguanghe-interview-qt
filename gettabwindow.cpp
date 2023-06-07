#include "gettabwindow.h"
#include "ui_gettabwindow.h"
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QMessageBox>

GetTabWindow::GetTabWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GetTabWindow)
{
    ui->setupUi(this);

    QGridLayout *layout = new QGridLayout(this);
    QLabel *label1 = new QLabel("Label 1", this);
    QPushButton *btn1 = new QPushButton("send get request");


    label1->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    label1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);


    layout->addWidget(label1, 0, 0);
    layout->addWidget(btn1, 0, 1);

    layout->setAlignment(Qt::AlignCenter);

    setLayout(layout);

    connect(btn1, &QPushButton::clicked, [this, label1]() {
        QNetworkAccessManager *manager = new QNetworkAccessManager(this);
        connect(manager, &QNetworkAccessManager::finished, [this, label1](QNetworkReply *reply) {
            if (reply->error() != QNetworkReply::NoError) {
                QMessageBox::warning(this, "Error", reply->errorString());
                return;
            }
            label1->setText(reply->readAll());
        });
        manager->get(QNetworkRequest(QUrl("http://119.180.25.95:8088/videoServer/webCams")));
    });
}

GetTabWindow::~GetTabWindow()
{
    delete ui;
}

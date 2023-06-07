#include "higerwidgetview.h"
#include "ui_higerwidgetview.h"
#include <QLabel>
#include <QGridLayout>

HigerWidgetView::HigerWidgetView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HigerWidgetView)
{
    ui->setupUi(this);

    QGridLayout *layout = new QGridLayout(this);
    QLabel *label1 = new QLabel("Label 1", this);
    label1->setStyleSheet("background-color: red;");
    QLabel *label2 = new QLabel("Label 2", this);
    label2->setStyleSheet("background-color: green;");
    QLabel *label3 = new QLabel("Label 3", this);
    label3->setStyleSheet("background-color: blue;");
    QLabel *label4 = new QLabel("Label 4", this);
    label4->setStyleSheet("background-color: yellow;");

    label1->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    label2->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    label3->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    label4->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    label1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    label2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    label3->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    label4->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    layout->addWidget(label1, 0, 0);
    layout->addWidget(label2, 0, 1);
    layout->addWidget(label3, 1, 0);
    layout->addWidget(label4, 1, 1);
    layout->setAlignment(Qt::AlignCenter);

    setLayout(layout);
}

HigerWidgetView::~HigerWidgetView()
{
    delete ui;
}

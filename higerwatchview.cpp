#include "higerwatchview.h"
#include "ui_higerwatchview.h"
#include <QPainter>
#include <QTimer>
#include <QTime>

HigerWatchView::HigerWatchView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HigerWatchView)
{
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(1000);
}

HigerWatchView::~HigerWatchView()
{
    delete ui;
}

void HigerWatchView::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(width() / 2, height() / 2);
    int side = qMin(width(), height());
    painter.scale(side / 200.0, side / 200.0);

    // Draw the hour hand
//    painter.save();
//    painter.rotate(30.0 * ((QTime::currentTime().hour() + QTime::currentTime().minute() / 60.0)));
//    painter.setPen(Qt::NoPen);
//    painter.setBrush(Qt::black);
//    static const QPointF hourHand[3] = {
//        QPointF(7.0, 8.0),
//        QPointF(-7.0, 8.0),
//        QPointF(0, -40.0)
//    };
//    painter.drawConvexPolygon(hourHand, 3);
//    painter.restore();

    // Draw the minute hand
    painter.save();
    painter.rotate(6.0 * (QTime::currentTime().minute() + QTime::currentTime().second() / 60.0));
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::black);
    static const QPointF minuteHand[3] = {
        QPointF(7.0, 8.0),
        QPointF(-7.0, 8.0),
        QPointF(0, -70.0)
    };
    painter.drawConvexPolygon(minuteHand, 3);
    painter.restore();

    // Draw the second hand
    painter.save();
    painter.rotate(6.0 * QTime::currentTime().second());
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::red);
    static const QPointF secondHand[3] = {
        QPointF(2.0, 8.0),
        QPointF(-2.0, 8.0),
        QPointF(0, -90.0)
    };
    painter.drawConvexPolygon(secondHand, 3);
    painter.restore();

    // Draw the center point
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::black);
    painter.drawEllipse(-5, -5, 10, 10);
}

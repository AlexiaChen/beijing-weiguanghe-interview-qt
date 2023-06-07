#ifndef HIGERWATCHVIEW_H
#define HIGERWATCHVIEW_H

#include <QObject>
#include <QWidget>

namespace Ui {
class HigerWatchView;
}

class HigerWatchView : public QWidget
{
    Q_OBJECT

public:
    explicit HigerWatchView(QWidget *parent = nullptr);
    ~HigerWatchView();

protected:
    void paintEvent(QPaintEvent *event);

private:
    Ui::HigerWatchView *ui;
};

#endif // HIGERWATCHVIEW_H

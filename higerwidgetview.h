#ifndef HIGERWIDGETVIEW_H
#define HIGERWIDGETVIEW_H

#include <QObject>
#include <QWidget>

namespace Ui {
class HigerWidgetView;
}

class HigerWidgetView : public QWidget
{
    Q_OBJECT

public:
    explicit HigerWidgetView(QWidget *parent = nullptr);
    ~HigerWidgetView();

private:
    Ui::HigerWidgetView *ui;
};

#endif // HIGERWIDGETVIEW_H

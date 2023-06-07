#ifndef GETTABWINDOW_H
#define GETTABWINDOW_H

#include <QWidget>

namespace Ui {
class GetTabWindow;
}

class GetTabWindow : public QWidget
{
    Q_OBJECT

public:
    explicit GetTabWindow(QWidget *parent = nullptr);
    ~GetTabWindow();

private:
    Ui::GetTabWindow *ui;
};

#endif // GETTABWINDOW_H

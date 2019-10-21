#ifndef BOXWINDOW_H
#define BOXWINDOW_H

#include <QMainWindow>

namespace Ui {
class BoxWindow;
}

class BoxWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit BoxWindow(QWidget *parent = nullptr);
    ~BoxWindow();

private slots:
    void backToMain();
private:
    Ui::BoxWindow *ui;
};

#endif // BOXWINDOW_H

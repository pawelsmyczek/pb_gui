#ifndef BOXWINDOW_H
#define BOXWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QPushButton>

namespace Ui {
class BoxWindow;
}

class BoxWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit BoxWindow(QWidget *parent = nullptr);
    ~BoxWindow();

public slots:
    void changeTitle(bool);
private slots:
    void backToMain();
private:
    Ui::BoxWindow *ui;
    QString title;
};

#endif // BOXWINDOW_H

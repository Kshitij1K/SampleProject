#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

class run_stuff {
    public:
    run_stuff(int argc, char** argv);
    int run_func();

    private:
    QApplication app;
    MainWindow* window;
};

#endif // MAINWINDOW_H

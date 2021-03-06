#include "yourlibrary/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

run_stuff::run_stuff(int argc, char** argv):
app(argc, argv) {
    window = new MainWindow;
}

int run_stuff::run_func() {
	window->show();
	return app.exec();
};

#include "yourlibrary/moc_mainwindow.cpp"
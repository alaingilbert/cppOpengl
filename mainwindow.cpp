#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    engine = new Engine();
    setCentralWidget(engine);
    setWindowTitle("Test");
    setEnabled(true);
    setMinimumSize(800, 600);
}

MainWindow::~MainWindow() {
    delete ui;
    delete engine;
}

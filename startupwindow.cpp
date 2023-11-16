#include "startupwindow.h"
#include "ui_startupwindow.h"

StartupWindow::StartupWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StartupWindow)
{
    ui->setupUi(this);
    ui->verticalLayout_2->setAlignment(Qt::AlignHCenter);
}

StartupWindow::~StartupWindow()
{
    delete ui;
}

void StartupWindow::on_openProjectButton_clicked()
{
    MainWindow * x = new MainWindow(nullptr, 4);
    this->close();
    x->show();
    x->on_actionLoad_triggered();
}


void StartupWindow::on_newProjectButton_clicked()
{
    SetPixelSizeWindow * x = new SetPixelSizeWindow();
    x->show();
    this->close();
}


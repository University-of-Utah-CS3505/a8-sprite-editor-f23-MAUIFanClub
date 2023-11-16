#include "startupwindow.h"
#include "ui_startupwindow.h"
#include "setpixelsizewindow.h"

StartupWindow::StartupWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StartupWindow)
{
    ui->setupUi(this);
    ui->verticalLayout_2->setAlignment(Qt::AlignHCenter);
    filesystem = new FileSystem();
}

StartupWindow::~StartupWindow()
{
    delete ui;
}

void StartupWindow::on_openProjectButton_clicked()
{
    //QString filename = QFileDialog::getOpenFileName(this, tr("Open File"), "C://", "Sprite Editor Project (*.ssp);;");
    MainWindow * x = new MainWindow(nullptr, 2);
    this->close();
    x->show();
    x->on_actionLoad_triggered();
}


void StartupWindow::on_newProjectButton_clicked()
{
    setPixelSizeWindow * x = new setPixelSizeWindow();
    x->show();
    this->close();
    // show set pixel size
    // set pixel size should have a confirm type button where it opens the main editor with the given pixel size as parameter
}


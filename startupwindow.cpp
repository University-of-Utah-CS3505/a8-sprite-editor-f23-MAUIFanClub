#include "startupwindow.h"
#include "ui_startupwindow.h"
#include "setpixelsizewindow.h"

StartupWindow::StartupWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StartupWindow)
{
    ConnectFileSystem();
    ui->setupUi(this);
    ui->verticalLayout_2->setAlignment(Qt::AlignHCenter);

}

StartupWindow::~StartupWindow()
{
    delete ui;
}

void StartupWindow::ConnectFileSystem()
{
    QObject::connect(this, &StartupWindow::loadJson, &filesystem, &FileSystem::loadJson);
}

void StartupWindow::on_openProjectButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Open File"), "C://", "Sprite Editor Project (*.ssp);;");
    emit loadJson(filename);
}


void StartupWindow::on_newProjectButton_clicked()
{
    setPixelSizeWindow * x = new setPixelSizeWindow();
    x->show();
    this->close();
    // show set pixel size
    // set pixel size should have a confirm type button where it opens the main editor with the given pixel size as parameter
}


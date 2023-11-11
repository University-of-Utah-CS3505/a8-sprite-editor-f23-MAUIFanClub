#ifndef STARTUPWINDOW_H
#define STARTUPWINDOW_H

#include <QMainWindow>

namespace Ui {
class StartupWindow;
}

class StartupWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StartupWindow(QWidget *parent = nullptr);
    ~StartupWindow();

private slots:
    void on_openProjectButton_clicked();

    void on_newProjectButton_clicked();

private:
    Ui::StartupWindow *ui;
};

#endif // STARTUPWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_InstallBtn_clicked();

    void on_ShowBtn_clicked();

    void on_ReservationBtn_clicked();

    void on_AvailableBtn_clicked();

    void on_actionAbout_triggered();

    void on_ExitBtn_clicked();

    void on_actionExit_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

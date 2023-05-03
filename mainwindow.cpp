#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // QTableWidget section

    ui->tableWidget->setColumnWidth(0,300);

    ui->tableWidget_2->setColumnWidth(0,113);
    ui->tableWidget_2->setColumnWidth(1,100);
    ui->tableWidget_2->setColumnWidth(2,78);
    ui->tableWidget_2->setColumnWidth(3,78);
    ui->tableWidget_2->setColumnWidth(4,85);
    ui->tableWidget_2->setColumnWidth(5,85);

    // QSpinbox section

    ui->BusNo1->setMinimum(1);
    ui->BusNo2->setMinimum(1);
    ui->BusNo3->setMinimum(1);
    ui->BusNo4->setMinimum(1);
    ui->SeatNo->setMinimum(1);

    ui->BusNo1->setMaximum(9);
    ui->BusNo2->setMaximum(9);
    ui->BusNo3->setMaximum(9);
    ui->BusNo4->setMaximum(9);
    ui->SeatNo->setMaximum(32);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Arrays

QString driversname[10];
QString arrtime[10];
QString deptime[10];
QString from[10];
QString tothis[10];
QString passenger[10][32];

void MainWindow::on_InstallBtn_clicked()
{
    int busnum;
    busnum = ui->BusNo1->text().toInt();

    driversname[busnum] = ui->DriversNameIn->text();
    arrtime[busnum] = ui->ArrTimeIn->text();
    deptime[busnum] = ui->DepTimeIn->text();
    from[busnum] = ui->FromIn->text();
    tothis[busnum] = ui->ToIn->text();

    QMessageBox msg;
    msg.setText("New bus installed successfully.");
    msg.exec();

    QTime defTime(00, 00);
    ui->DriversNameIn->setText("");
    ui->ArrTimeIn->setTime(defTime);
    ui->DepTimeIn->setTime(defTime);
    ui->FromIn->setText("");
    ui->ToIn->setText("");
}

void MainWindow::on_ReservationBtn_clicked()
{
    int busnum;
    busnum = ui->BusNo2->text().toInt();
    int seatnum;
    seatnum = ui->SeatNo->text().toInt();

    passenger[busnum][seatnum] = ui->PassengersNameIn->text();

    QMessageBox msg;
    msg.setText("The seat is reserved successfully.");
    msg.exec();

    ui->PassengersNameIn->setText("");
}

void MainWindow::on_ShowBtn_clicked()
{
    int busnum;
    busnum = ui->BusNo3->text().toInt();

    QString dNameOut = driversname[busnum];
    QString arrTimeOut = arrtime[busnum];
    QString depTimeOut = deptime[busnum];
    QString fromOut = from[busnum];
    QString toOut = tothis[busnum];
    ui->DriversNameOut->setText(dNameOut);
    ui->ArrTimeOut->setText(arrTimeOut);
    ui->DepTimeOut->setText(depTimeOut);
    ui->FromOut->setText(fromOut);
    ui->ToOut->setText(toOut);

    for (int seatnum = 1; seatnum <= 32; seatnum++)
    {
        QString pNameOut = passenger[busnum][seatnum];
        ui->tableWidget->setItem(seatnum-1, 0, new QTableWidgetItem(pNameOut));
    }
}

void MainWindow::on_AvailableBtn_clicked()
{
    int busnum;
    busnum = ui->BusNo4->text().toInt();

    QString dNameOut = driversname[busnum];
    QString arrTimeOut = arrtime[busnum];
    QString depTimeOut = deptime[busnum];
    QString fromOut = from[busnum];
    QString toOut = tothis[busnum];

    ui->tableWidget_2->setItem(busnum-1, 1, new QTableWidgetItem(dNameOut));
    ui->tableWidget_2->setItem(busnum-1, 2, new QTableWidgetItem(arrTimeOut));
    ui->tableWidget_2->setItem(busnum-1, 3, new QTableWidgetItem(depTimeOut));
    ui->tableWidget_2->setItem(busnum-1, 4, new QTableWidgetItem(fromOut));
    ui->tableWidget_2->setItem(busnum-1, 5, new QTableWidgetItem(toOut));

    int count = 0;
    for (int seatnum = 1; seatnum <= 32; seatnum++)
    {
        QString pNameOut = passenger[busnum][seatnum];
        if (pNameOut == "")
            count++;
    }

    QString availSeat = QString::number(count);
    QString notAvail = "Full bus";

    if (count == 0)
        ui->tableWidget_2->setItem(busnum-1, 0, new QTableWidgetItem(notAvail));
    else
        ui->tableWidget_2->setItem(busnum-1, 0, new QTableWidgetItem(availSeat));
}


void MainWindow::on_actionAbout_triggered()
{
    QMessageBox msg;
    msg.setText("Bus Reservation System by Ali Rabiei\n\nVersion 1.01\nDate: June 28, 2021");
    msg.exec();
}

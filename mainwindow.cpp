#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "../../cpp/PortScanningTool/SokcetConnection.cpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->IPLineEdit->setPlaceholderText("Enter the ip");
    ui->startPortLineEdit->setPlaceholderText("Enter the start port");
    ui->endPortLineEdit->setPlaceholderText("Enter the end port");
    ui->textEdit->setPlaceholderText("Opend ports...");
    ui->textEdit->setReadOnly(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_scanButton_clicked()
{
    ui->textEdit->clear();
    QString ip=ui->IPLineEdit->text();
    int sPort= ui->startPortLineEdit->text().toInt();
    int ePort= ui->endPortLineEdit->text().toInt();
   const char* myIp= ip.toStdString().c_str();
    SokcetConnection socket(myIp,sPort,ePort);
    socket.connection();
    for (auto &port : socket.ls) {
        ui->textEdit->append(QString::number(port));
        qDebug() << port << "is Open";
    }

}


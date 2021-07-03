#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QString"
#include <QMessageBox>
//#include "functions.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->frame_3->setVisible(false);
    ui->frame->setVisible(false);
    ui->frame_4->setVisible(false);

    client_socket = new QTcpSocket(this);//объявление сокета
    client_socket ->connectToHost("127.0.0.1",33333);//установка подключения
    //как мы подключились?
    connect(client_socket,SIGNAL(connected()),SLOT(slot_connected()));//ожидание сигнала
    connect(client_socket, SIGNAL(readyRead()), SLOT(slot_readyRead()));

}

MainWindow::~MainWindow()
{
    delete ui;
    client_socket->close();
}

void MainWindow:: slot_connected()
{   //
    QMessageBox Msg;
    Msg.setText("Connected!!!");
    Msg.exec();
}


void MainWindow:: slot_readyRead()
{
    QByteArray array;
    std::string message = "";

    while(client_socket->bytesAvailable()>0)
    {
        array = client_socket->readAll();
        message += array.toStdString();
    }
    if(message == "auth_true")
    {
        ui->frame_2->setVisible(false);
        ui->frame->setVisible(true);
    }
    if(message == "1")
    {
        ui->lineEdit_5 -> insert(QString::fromStdString(message));
    }
    QMessageBox Msg;
    Msg.setText(QString::fromStdString(message));
    Msg.exec();
}

void MainWindow:: slot_send_to_server(QString message)
{
    QByteArray array;
    array.append(message);
    client_socket->write(array);
}

void MainWindow:: slot_disconnected()
{
    client_socket->close();
}

void MainWindow::on_pushButton_vhod_clicked() //при нажатии кнопки войти
{        
    QString log = ui->lineEdit_2->text(); //считавает значение логина
    QString pass = ui->lineEdit->text(); //считваем значение пароля

    QString message = "auth&"+log+"&"+pass;
 //   ui->lineEdit -> insert(QString(message));
    slot_send_to_server(message);
   // if(k) ///
 // {
 //      ui->frame_2->setVisible(false);
 //      ui->frame->setVisible(true);
  //}
  // else
  // ui->lineEdit -> insert(QString(log));

}
void MainWindow::on_pushButton_reg_clicked() //при нажатии кнопки зарегистрироваться
{
    QString log = ui->lineEdit_2->text(); //считавает значение логина
    QString pass = ui->lineEdit->text(); //считваем значение пароля

    QString message = "reg&"+log+"&"+pass;
    slot_send_to_server(message);

}

void MainWindow::on_pushButton_nach_clicked() //при нажатии на кнопку начать игру
{
    QString razmer = ui->lineEdit_5->text(); //считавает размерность
    //QMessageBox::information(this, "Title",ui->comboBox->currentText());
    QString res =  ui->comboBox->currentText(); //считваем крустик/нолик
    ui->frame_3->setVisible(true);
    ui->frame->setVisible(false);


    QMessageBox Msg;
    bool krest = (ui->textBrowser->find("15"));
    Msg.exec();
  //  QString value =    //->itemData(comboBox->currentIndex()); //считваем значение

    // QString message = "reg&"+log+"&"+pass;
   // slot_send_to_server(message);
    //ui->frame_3->setVisible(true);
    //ui->frame->setVisible(false);
}

void MainWindow::on_pushButton_konch_clicked()
{
    ui->frame_3->setVisible(false);
    ui->frame->setVisible(true);
}

void MainWindow::on_pushButton_4_clicked()
{
   // ui->frame_4->setVisible(true);
   // ui->frame->setVisible(false);
    QString log = ui->lineEdit_2->text();

    QString message = "status&"+log;
    slot_send_to_server(message);
}

void MainWindow::on_pushButton_vozvrat_clicked()
{
    ui->frame_4->setVisible(false);
    ui->frame->setVisible(true);
}



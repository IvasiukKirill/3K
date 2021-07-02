#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>

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
    //void on_frame_customContextMenuRequested(const QPoint &pos);

    void on_pushButton_vhod_clicked();

    void on_pushButton_nach_clicked();

    void on_pushButton_konch_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_vozvrat_clicked();

    void on_pushButton_reg_clicked();

private:
    Ui::MainWindow *ui;
    QTcpSocket *client_socket; //ссылка на сокет

private slots:
    void slot_connected();
    void slot_readyRead();
    void slot_send_to_server(QString message);
    void slot_disconnected();
};
#endif // MAINWINDOW_H

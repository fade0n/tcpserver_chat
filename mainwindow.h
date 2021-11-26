#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>
#include <QTcpSocket>
#include <QObject>
#include <QByteArray>
#include <QDebug>
#include <QtSql>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_start_clicked();
    void on_stop_clicked();
    void newuser();
    void slotReadClient();

private:
    Ui::MainWindow *ui;

    QTcpServer *tcpServer;

    int server_status;

    QSqlDatabase db;

    QMap<int,QTcpSocket *> clients;
    QMap<QString,QTcpSocket *> users;
    QMap<QTcpSocket *,QTcpSocket *> pm;

};
#endif // MAINWINDOW_H

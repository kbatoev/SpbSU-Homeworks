#pragma once

#include "netconfiguration.h"
#include <QTcpServer>
#include <QMessageBox>

class Server : public NetConfiguration
{
    Q_OBJECT
public:
    Server(QWidget *parent = 0, QLabel *serverStatusLabel = 0, QComboBox *comboBox = 0,
           QLineEdit *portLineEdit = 0, QPushButton *connectButton = 0);
    ~Server();

private slots:
    void dealWithMessage(QString message);
    void establishedConnection();

    void sessionOpened();



private:
    QTcpServer *tcpServer;
    QLabel *serverStatusLabel;
    QString ipAddress;

};


#pragma once

#include "netconfiguration.h"
#include <QTcpSocket>
#include <QHostInfo>
#include <QNetworkConfigurationManager>

class Client : public NetConfiguration
{
    Q_OBJECT

public:
    Client(QWidget *parent = 0, QLabel *serverStatusLabel = 0, QLineEdit *ipLineEdit = 0,
           QLineEdit *portLineEdit = 0, QPushButton *connectButton = 0);

private slots:
    void dealWithMessage(const QString &message);
    void establishedConnection();

    void enableConnectButton();
    void establishConnection();

private:
    QLabel *statusLabel;
    QLineEdit *ipLineEdit;
    QLineEdit *portLineEdit;
    QPushButton *connectButton;

    QString ipAddress;
    int port;
};


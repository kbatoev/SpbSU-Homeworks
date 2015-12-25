#pragma once

#include "netconfiguration.h"
#include <QTcpSocket>
#include <QHostInfo>
#include <QNetworkConfigurationManager>

class Client : public NetConfiguration
{
    Q_OBJECT

public:
    Client(QWidget *parent = 0, QLabel *serverStatusLabel = 0, QComboBox *comboBox = 0,
           QLineEdit *portLineEdit = 0, QPushButton *connectButton = 0);

private slots:
    void dealWithMessage(QString message);
    void establishedConnection();

    void enableConnectButton();
    void establishConnection();

private:
    QLabel *statusLabel;
    QComboBox *comboBox;
    QLineEdit *portLineEdit;
    QPushButton *connectButton;

    QString ipAddress;
    int port;
};


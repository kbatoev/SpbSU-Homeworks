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
    void sessionOpened();
    void enableConnectButton();
    void establishConnection();
    void establishedConnection();

private:
    QLabel *statusLabel;
    QComboBox *comboBox;
    QLineEdit *portLineEdit;
    QPushButton *connectButton;

    quint16 blockSize;

    QString ipAddress;
    int port;
};

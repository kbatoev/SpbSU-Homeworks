#pragma once

#include <QDialog>
#include <QNetworkSession>
#include <QLabel>
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>
#include <QtWidgets>
#include <QtNetwork>

class NetConfiguration : public QDialog
{
    Q_OBJECT

public:
    NetConfiguration(QWidget *parent = 0, QLabel *serverStatusLabel = 0, QComboBox *comboBox = 0,
                     QLineEdit *portLineEdit = 0, QPushButton *connectButton = 0);


protected slots:
    virtual void sessionOpened() = 0;
    void sendMessage(QString message);

protected:
    QNetworkSession *networkSession;
    QTcpSocket *tcpSocket;
};

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

public slots:
    void sendMessage(QString message);


signals:
    void connected();

protected slots:
    virtual void sessionOpened() = 0;
    void readMessage();

protected:
    QNetworkSession *networkSession;
    QTcpSocket *tcpSocket;
    QString receivedMessage;
    quint16 blockSize;

    bool hasNoMessages;
};


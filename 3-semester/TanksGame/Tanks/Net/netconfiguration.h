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

    void sendMessage(QString message);

    QString getReceivedMessage() const;

protected slots:
    virtual void dealWithMessage(QString message) = 0;
    virtual void establishedConnection() = 0;
    void readMessage();

signals:
    void connected();
    void received(QString message);

protected:
    QTcpSocket *tcpSocket;
    QString receivedMessage;
    quint16 blockSize;

    bool isWaitingForFirstMessage;
};


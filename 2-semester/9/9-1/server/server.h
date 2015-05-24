#pragma once

#include <QDialog>

#include <QtWidgets>
#include <QtNetwork>

#include <stdlib.h>

class QLabel;
class QPushButton;
class QTcpServer;
class QNetworkSession;

class Server : public QDialog
{
    Q_OBJECT

public:
    Server(QWidget *parent = 0);
    ~Server();

private slots:
    void disconnectFromClient();
    void rememberClientSocket();
    void readMessageFromClient();
    void sendMessageToClient();

private:
    const QString destroyedConnection = "CONNECTION DESTROYED";
    const QString establishedConnection = "CONNECTION ESTABLISHED";

    void sendMessageToClient(const QString &message);
    void drawWindow();
    void enableSendWidgets();
    void disableSendWidgets();

    QLabel *statusLabel;
    QPushButton *quitButton;

    QTextEdit *chat;
    QLineEdit *messageLine;
    QPushButton *sendButton;
    QGridLayout *mainLayout;


    QTcpServer *tcpServer;
    QTcpSocket *tcpSocket;
    quint16 blockSize;
};


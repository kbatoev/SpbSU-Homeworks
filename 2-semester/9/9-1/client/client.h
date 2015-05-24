#pragma once

#include <QtWidgets>
#include <QtNetwork>

#include <QDialog>
#include <QTcpSocket>
#include <QTextEdit>

class QComboBox;
class QDialogButtonBox;
class QLabel;
class QLineEdit;
class QPushButton;
class QTcpSocket;
class QNetworkSession;

class Client : public QDialog
{
    Q_OBJECT

public:
    Client(QWidget *parent = 0);
    ~Client();

private slots:
    void connectToServer();
    void writeMessageToServer();
    void readMessageFromServer();
    void displayError(QAbstractSocket::SocketError socketError);
    void enableConnectButton();

private:
    void enableSendButton();
    void disableSendButton();

    void drawWindow();
    QLabel *hostLabel;
    QLabel *portLabel;
    QComboBox *hostCombo;
    QLineEdit *portLineEdit;

    QPushButton *connectButton;
    QPushButton *quitButton;

    QTcpSocket *tcpSocket;
    quint16 blockSize;

    QTextEdit *chat;
    QLineEdit *messageLine;
    QPushButton *sendButton;
    QGridLayout *mainLayout;
};


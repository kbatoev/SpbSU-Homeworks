#include "client.h"

#include <QtWidgets>
#include <QtNetwork>


Client::Client(QWidget *parent, QLabel *serverStatusLabel, QLineEdit *ipLineEdit,
               QLineEdit *portLineEdit, QPushButton *connectButton) :
    NetConfiguration(parent),
    ipLineEdit(ipLineEdit),
    portLineEdit(portLineEdit),
    connectButton(connectButton)
{
    isWaitingForFirstMessage = true;

    this->portLineEdit->setValidator(new QIntValidator(1, 65535, this));

    this->connectButton->setEnabled(false);
    connect(this->ipLineEdit, SIGNAL(textChanged(QString)), this, SLOT(enableConnectButton()));
    connect(this->portLineEdit, SIGNAL(textChanged(QString)), this, SLOT(enableConnectButton()));
    connect(this->connectButton, SIGNAL(clicked()), this, SLOT(establishConnection()));
}

void Client::dealWithMessage(QString message)
{
    if (isWaitingForFirstMessage)
    {
        isWaitingForFirstMessage = false;
        establishedConnection();
    }
    else
    {
        emit received(message);
    }
}

void Client::establishedConnection()
{
    ipAddress = ipLineEdit->text();
    port = portLineEdit->text().toInt();
    emit connected();
}

void Client::enableConnectButton()
{
    connectButton->setEnabled(!ipLineEdit->text().isEmpty() && !portLineEdit->text().isEmpty());
}

void Client::establishConnection()
{
    connectButton->setEnabled(false);
    blockSize = 0;
    tcpSocket->connectToHost(ipLineEdit->text(), portLineEdit->text().toInt());
}



#include "client.h"

#include <QtWidgets>
#include <QtNetwork>


Client::Client(QWidget *parent, QLabel *serverStatusLabel, QComboBox *comboBox,
               QLineEdit *portLineEdit, QPushButton *connectButton) :
    NetConfiguration(parent),
    comboBox(comboBox),
    portLineEdit(portLineEdit),
    connectButton(connectButton)
{
    isWaitingForFirstMessage = true;

    // find out name of this machine
    QString name = QHostInfo::localHostName();
    if (!name.isEmpty())
    {
        this->comboBox->addItem(name);
        QString domain = QHostInfo::localDomainName();
        if (!domain.isEmpty())
            comboBox->addItem(name + QChar('.') + domain);
    }

    if (name != QString("localhost"))
        comboBox->addItem(QString("localhost"));

    // find out IP addresses of this machine
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    // add non-localhost addresses
    for (int i = 0; i < ipAddressesList.size(); ++i)
    {
        if (!ipAddressesList.at(i).isLoopback())
            comboBox->addItem(ipAddressesList.at(i).toString());
    }

    // add localhost addresses
    for (int i = 0; i < ipAddressesList.size(); ++i)
    {
        if (ipAddressesList.at(i).isLoopback())
            comboBox->addItem(ipAddressesList.at(i).toString());
    }

    this->portLineEdit->setValidator(new QIntValidator(1, 65535, this));

    this->connectButton->setEnabled(false);
    connect(this->comboBox, SIGNAL(editTextChanged(QString)), this, SLOT(enableConnectButton()));
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
    ipAddress = comboBox->currentText();
    port = portLineEdit->text().toInt();
    emit connected();
}

void Client::enableConnectButton()
{
    connectButton->setEnabled(!comboBox->currentText().isEmpty() && !portLineEdit->text().isEmpty());
}

void Client::establishConnection()
{
    connectButton->setEnabled(false);
    blockSize = 0;
    tcpSocket->connectToHost(comboBox->currentText(), portLineEdit->text().toInt());
}



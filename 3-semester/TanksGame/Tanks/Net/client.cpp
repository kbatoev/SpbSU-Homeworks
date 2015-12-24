#include "client.h"

#include <QtWidgets>
#include <QtNetwork>


Client::Client(QWidget *parent, QLabel *serverStatusLabel, QComboBox *comboBox,
               QLineEdit *portLineEdit, QPushButton *connectButton) :
    statusLabel(serverStatusLabel),
    comboBox(comboBox),
    portLineEdit(portLineEdit),
    connectButton(connectButton)
{
    networkSession = nullptr;
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

    statusLabel->setText(tr("This examples requires that you run the Server as well. "
                            "Choose ip address in comboBox and write port in LineEdit"));

    tcpSocket = new QTcpSocket(this);

    this->connectButton->setEnabled(false);
    connect(this->comboBox, SIGNAL(editTextChanged(QString)), this, SLOT(enableConnectButton()));
    connect(this->portLineEdit, SIGNAL(textChanged(QString)), this, SLOT(enableConnectButton()));
    connect(this->connectButton, SIGNAL(clicked()), this, SLOT(establishConnection()));
}


void Client::sessionOpened()
{

}

void Client::enableConnectButton()
{
    connectButton->setEnabled((!networkSession || networkSession->isOpen()) &&
                              !comboBox->currentText().isEmpty() &&
                              !portLineEdit->text().isEmpty());
}

void Client::establishConnection()
{
    connectButton->setEnabled(false);
    blockSize = 0;
    tcpSocket->connectToHost(comboBox->currentText(), portLineEdit->text().toInt());
}

void Client::establishedConnection()
{
    ipAddress = comboBox->currentText();
    port = portLineEdit->text().toInt();

    comboBox->setEnabled(false);
    portLineEdit->setEnabled(false);

    comboBox->setVisible(false);
    portLineEdit->setVisible(false);
    connectButton->setVisible(false);
}




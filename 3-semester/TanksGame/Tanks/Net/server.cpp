#include "server.h"

Server::Server(QWidget *parent, QLabel *serverStatusLabel, QComboBox *comboBox,
               QLineEdit *portLineEdit, QPushButton *connectButton) :
    NetConfiguration(parent),
    serverStatusLabel(serverStatusLabel)
{
    tcpServer = new QTcpServer(this);

    sessionOpened();

    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(establishedConnection()));
}

Server::~Server()
{
    delete tcpServer;
}

void Server::sessionOpened()
{
    if (!tcpServer->listen())
    {
        QMessageBox::critical(this, tr("Tank Server"),
                              tr("Unable to start the server: %1.")
                              .arg(tcpServer->errorString()));
        close();
        return;
    }

    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    // use the first non-localhost IPv4 address
    for (int i = 0; i < ipAddressesList.size(); ++i)
    {
        if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
            ipAddressesList.at(i).toIPv4Address())
        {
            ipAddress = ipAddressesList.at(i).toString();
            break;
        }
    }
    if (ipAddress.isEmpty())
    {
        ipAddress = QHostAddress(QHostAddress::LocalHost).toString();
    }
    serverStatusLabel->setText(tr("The server is running on\n\nIP: %1\nport: %2\n\n"
                            "Run the Client now.")
                         .arg(ipAddress).arg(tcpServer->serverPort()));

}

void Server::dealWithMessage(QString message)
{
    emit received(message);
}

void Server::establishedConnection()
{
    tcpSocket = tcpServer->nextPendingConnection();
    emit connected();
}

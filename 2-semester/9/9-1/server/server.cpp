#include "server.h"

Server::Server(QWidget *parent)
    :   QDialog(parent), tcpServer(0), tcpSocket(0), blockSize(0)
{

    tcpServer = new QTcpServer(this);
    if (!tcpServer->listen())
    {
        QMessageBox::critical(this, tr("Chat Server"), tr("Unable to start the server: %1.")
                              .arg(tcpServer->errorString()));
        close();
        return;
    }

    drawWindow();

    connect(quitButton, SIGNAL(clicked()), this, SLOT(disconnectFromClient()));
    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(rememberClientSocket()));
    connect(sendButton, SIGNAL(clicked()), this, SLOT(sendMessageToClient()));
}

Server::~Server()
{
    delete statusLabel;
    delete quitButton;

    delete chat;
    delete messageLine;
    delete sendButton;
    delete mainLayout;

    delete tcpServer;
    delete tcpSocket;
}

void Server::disconnectFromClient()
{
    sendMessageToClient(destroyedConnection);
}

void Server::drawWindow()
{
    statusLabel = new QLabel;
    statusLabel->setText(tr("Server's port is %1").arg(tcpServer->serverPort()));
    quitButton = new QPushButton(tr("Quit"));
    quitButton->setAutoDefault(false);


    mainLayout = new QGridLayout;
    chat = new QTextEdit();
    chat->setReadOnly(true);
    messageLine = new QLineEdit;
    messageLine->setEnabled(false);

    sendButton = new QPushButton("&Send");
    sendButton->setEnabled(false);

    mainLayout->addWidget(statusLabel, 0, 0, 1, 4);
    mainLayout->addWidget(quitButton, 0, 4, 1, 1);
    mainLayout->addWidget(chat, 1, 0, 5, 4);
    mainLayout->addWidget(messageLine, 6, 0, 1, 4);
    mainLayout->addWidget(sendButton, 6, 4, 1, 1);

    setLayout(mainLayout);

    setWindowTitle(tr("Chat Server"));
}

void Server::enableSendWidgets()
{
    messageLine->setEnabled(true);
    messageLine->setFocus();
    sendButton->setEnabled(true);
}

void Server::disableSendWidgets()
{
    messageLine->setEnabled(false);
    sendButton->setEnabled(false);
}

void Server::rememberClientSocket()
{
    tcpSocket = tcpServer->nextPendingConnection(); // incoming connection
    connect(tcpSocket, SIGNAL(disconnected()), tcpSocket, SLOT(deleteLater()));
    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(readMessageFromClient()));
    enableSendWidgets();
    sendMessageToClient(establishedConnection);
}

void Server::readMessageFromClient()
{
    QDataStream in(tcpSocket);
    in.setVersion(QDataStream::Qt_4_0);

    if (blockSize == 0)
    {
        if (tcpSocket->bytesAvailable() < (int)sizeof(quint16))
            return;

        in >> blockSize;
    }

    if (tcpSocket->bytesAvailable() < blockSize)
        return;

    QString message;
    in >> message;
    chat->append(message);

    if (!message.compare(destroyedConnection))
        disableSendWidgets();

    blockSize = 0;
}

void Server::sendMessageToClient()
{
    sendMessageToClient("Server: " + messageLine->text());
}

void Server::sendMessageToClient(const QString &message)
{
    messageLine->setText("");
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_0);
    out << (quint16)0;
    out << message;
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));

    chat->append(message);
    tcpSocket->write(block);
}


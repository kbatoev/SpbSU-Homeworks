#include "client.h"

Client::Client(QWidget *parent)
:   QDialog(parent), tcpSocket(0), blockSize(0)
{
    tcpSocket = new QTcpSocket(this);
    drawWindow();

    connect(hostCombo, SIGNAL(editTextChanged(QString)), this, SLOT(enableConnectButton()));
    connect(portLineEdit, SIGNAL(textChanged(QString)), this, SLOT(enableConnectButton()));

    connect(connectButton, SIGNAL(clicked()), this, SLOT(connectToServer()));

    connect(quitButton, SIGNAL(clicked()), this, SLOT(disconnectFromServer()));
    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(readMessageFromServer()));
    connect(sendButton, SIGNAL(clicked()), this, SLOT(writeMessageToServer()));
    connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(displayError(QAbstractSocket::SocketError)));

}

Client::~Client()
{
    delete hostLabel;
    delete portLabel;
    delete hostCombo;
    delete portLineEdit;
    delete quitButton;
    delete connectButton;
    delete chat;
    delete messageLine;
    delete sendButton;
    delete tcpSocket;
    delete mainLayout;
}

void Client::disconnectFromServer()
{
    if (tcpSocket->isOpen())
        writeMessageToServer("CONNECTION DESTROYED");
}

void Client::drawWindow()
{
    hostLabel = new QLabel(tr("&Server name:"));
    portLabel = new QLabel(tr("Server port:"));

    hostCombo = new QComboBox;
    hostCombo->setEditable(true);

    hostCombo->addItem(QString("localhost"));

    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();

    for (int i = 0; i < ipAddressesList.size(); ++i)
        if (!ipAddressesList.at(i).isLoopback())
            hostCombo->addItem(ipAddressesList.at(i).toString());
    for (int i = 0; i < ipAddressesList.size(); ++i)
        if (ipAddressesList.at(i).isLoopback())
            hostCombo->addItem(ipAddressesList.at(i).toString());

    portLineEdit = new QLineEdit;
    portLineEdit->setValidator(new QIntValidator(1, 65535, this));
    hostLabel->setBuddy(hostCombo);
    portLabel->setBuddy(portLineEdit);

    quitButton = new QPushButton(tr("Quit"));
    quitButton->setAutoDefault(false);
    connectButton = new QPushButton(tr("Connect"));
    connectButton->setAutoDefault(false);
    connectButton->setEnabled(false);

    sendButton = new QPushButton("&Send");
    sendButton->setAutoDefault(true);
    sendButton->setEnabled(false);

    chat = new QTextEdit();
    chat->setReadOnly(true);
    messageLine = new QLineEdit;
    messageLine->setEnabled(false);

    mainLayout = new QGridLayout;
    mainLayout->addWidget(hostLabel, 0, 0);
    mainLayout->addWidget(hostCombo, 0, 1);
    mainLayout->addWidget(portLabel, 1, 0);
    mainLayout->addWidget(portLineEdit, 1, 1);

    mainLayout->addWidget(quitButton, 0, 3, 1, 1);
    mainLayout->addWidget(connectButton, 1, 3, 1, 1);

    mainLayout->addWidget(chat, 4, 0, 1, 3);
    mainLayout->addWidget(messageLine, 5, 0, 1, 2);
    mainLayout->addWidget(sendButton, 5, 3, 1, 1);
    setLayout(mainLayout);

    setWindowTitle(tr("Chat Client"));
    portLineEdit->setFocus();
}

void Client::enableConnectButton()
{
    connectButton->setEnabled(!hostCombo->currentText().isEmpty() && !portLineEdit->text().isEmpty());
}

void Client::connectToServer()
{
    tcpSocket->abort();
    tcpSocket->connectToHost(hostCombo->currentText(), portLineEdit->text().toInt());
}

void Client::writeMessageToServer()
{
    writeMessageToServer("Client: " + messageLine->text());
}

void Client::writeMessageToServer(const QString &message)
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

void Client::readMessageFromServer()
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
        disableSendButton();
    if (!message.compare(establishedConnection))
        enableSendButton();

    blockSize = 0;
}

void Client::displayError(QAbstractSocket::SocketError socketError)
{
    switch (socketError)
    {
    case QAbstractSocket::RemoteHostClosedError:
        break;
    case QAbstractSocket::HostNotFoundError:
        QMessageBox::information(this, tr("Fortune Client"),
                                 tr("The host was not found. Please check the "
                                    "host name and port settings."));
        break;
    case QAbstractSocket::ConnectionRefusedError:
        QMessageBox::information(this, tr("Fortune Client"),
                                 tr("The connection was refused by the peer. "
                                    "Make sure the fortune server is running, "
                                    "and check that the host name and port "
                                    "settings are correct."));
        break;
    default:
        QMessageBox::information(this, tr("Fortune Client"),
                                 tr("The following error occurred: %1.")
                                 .arg(tcpSocket->errorString()));
    }

}

void Client::enableSendButton()
{
    sendButton->setEnabled(true);
    connectButton->setEnabled(false);
    messageLine->setEnabled(true);
    messageLine->setFocus();
}

void Client::disableSendButton()
{
    connectButton->setEnabled(true);
    sendButton->setEnabled(false);
    messageLine->setEnabled(false);
}




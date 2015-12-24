#include "netconfiguration.h"

NetConfiguration::NetConfiguration(QWidget *parent, QLabel *serverStatusLabel, QComboBox *comboBox,
                                   QLineEdit *portLineEdit, QPushButton *connectButton) :
    QDialog(parent)
{

}

void NetConfiguration::sendMessage(QString message)
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_0);

    out << (quint16)0;
    out << message;
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));

    //QTcpSocket *clientConnection = tcpServer->nextPendingConnection();

    //connect(clientConnection, SIGNAL(disconnected()), clientConnection, SLOT(deleteLater()));

    tcpSocket->write(block);
    //clientConnection->disconnectFromHost();
}

void NetConfiguration::readMessage()
{
    QDataStream in(tcpSocket);
    in.setVersion(QDataStream::Qt_4_0);


    in >> blockSize;

    if (tcpSocket->bytesAvailable() < blockSize)
        return;

    in >> receivedMessage;
}


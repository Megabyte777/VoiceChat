#ifndef CHATCLIENT_H
#define	CHATCLIENT_H

#include <QUdpSocket>
#include <QTimer>
#include <QNetworkInterface>
#include "AudioHelper.h"

class ChatClient : public QObject {
	Q_OBJECT
	
	QUdpSocket udpSocket;
	QHostAddress myAddress;
	QString myNickname;
	QTimer sendTimer;
	AudioHelper audio;
	
	static const int PORT = 4815;
	QString PING;
	QString HELLO;
	QString BYE;
	QString AUDIO;
	static const int SEND_PERIOD = 100;
	static const int UPDATE_PERIOD = 60;
	
private slots:
	void processPendingDatagrams();
	void sendAudio();
	
public:
	ChatClient();
	void join(QString);
	void leave();
	void startSendingAudio();
	void stopSendingAudio();
	void updateUserList();
	
signals:
	void userConnected(QHostAddress IP, QString nickname);
	void userDisconnected(QHostAddress IP);
};

#endif	/* CHATCLIENT_H */
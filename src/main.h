#ifndef MAIN_H
#define MAIN_H

#include "HBaseClient.h"

#include <QCoreApplication>
#include <QFutureWatcher>

class MainApp : public QCoreApplication
{
	Q_OBJECT

public:
	MainApp(int argc, char** argv);
	int run();

public slots:
	void handleFinished();
	void handleExit();

protected:
	virtual void timerEvent(QTimerEvent *event);

private:
	AsyncHBase::HBaseClient* hbase_client;
};

class PendingRequest : public QFutureWatcher<void>
{
	Q_OBJECT

public:
	PendingRequest(AsyncHBase::PutRequest* pr) : QFutureWatcher<void>(), _pr(pr) {}
	~PendingRequest();

private:
	AsyncHBase::PutRequest* _pr;
};

#endif // MAIN_H

#ifndef FORWARDERMANAGER_H
#define FORWARDERMANAGER_H

#include "TLogger.h"

#include <QObject>

class ForwarderManagerPrivate;

class ForwarderManager : public QObject {
	Q_OBJECT
	Q_DISABLE_COPY(ForwarderManager)
	T_LOGGER_DECLARE(ForwarderManager);

public:
	ForwarderManager(const QString& name, const QString& zquorum, unsigned int delay, unsigned int flush_interval, const QString& socket, QObject* parent = 0);
	~ForwarderManager();

	void finish();

private:
	Q_DECLARE_PRIVATE(ForwarderManager);
	ForwarderManagerPrivate* d_ptr;
};

#endif // FORWARDERMANAGER_H

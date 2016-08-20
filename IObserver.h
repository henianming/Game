#ifndef IOBSERVER
#define IOBSERVER

#include "EventDef.h"

class IObserver {
public:
	virtual void GetNotify(EVENTTYPE eventType, MSG notifyContext) = 0;
};

#endif //IOBSERVER
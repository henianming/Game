#ifndef ISUBJECT
#define ISUBJECT

#include "EventDef.h"

class ISubject {
public:
	virtual bool AddObserver(EVENTTYPE eventType, IObserver *observer) = 0;
	virtual bool DelObserver(EVENTTYPE eventType, IObserver *observer) = 0;
	virtual void Notify(EVENTTYPE eventType, MSG notifyContext) = 0;
};

#endif //ISUBJECT
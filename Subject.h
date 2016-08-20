#ifndef SUBJECT
#define SUBJECT

#include "ISubject.h"
#include "IObserver.h"
#include <map>
#include <list>

#include <iostream>

class Subject : public ISubject {
private:
	std::map<EVENTTYPE, std::list<IObserver*>*> m_observerMap;

public:
	virtual bool AddObserver(EVENTTYPE eventType, IObserver *observer);
	virtual bool DelObserver(EVENTTYPE eventType, IObserver *observer);
	virtual void Notify(EVENTTYPE eventType, MSG notifyContext);
};

#endif //SUBJECT
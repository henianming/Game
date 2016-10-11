#ifndef SUBJECT
#define SUBJECT

#include "SingletonTemplate.h"

#include "EventDef.h"
#include "IObserver.h"
#include <map>
#include <list>

class Subject : public SingletonTemplate<Subject> {
private:
	static std::map<EVENTTYPE, std::list<IObserver*>*> m_observerMap;

public:
	bool Init();
	void UnInit();

	virtual bool AddObserver(EVENTTYPE eventType, IObserver *observer);
	virtual bool DelObserver(EVENTTYPE eventType, IObserver *observer);
	virtual void Notify(EVENTTYPE eventType, GAMEMSG notifyContext);
};

#endif //SUBJECT
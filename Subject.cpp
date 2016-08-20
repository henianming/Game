#include "Subject.h"

typedef std::map<EVENTTYPE, std::list<IObserver*>*>::iterator it_eEVENTTYPEpList;

bool Subject::AddObserver(EVENTTYPE eventType, IObserver *observer) {
	it_eEVENTTYPEpList mapIt(m_observerMap.find(eventType));
	if (mapIt == m_observerMap.end()) {
		m_observerMap[eventType] = new std::list<IObserver*>();
		mapIt = m_observerMap.find(eventType);
	}

	std::list<IObserver*> *obList = mapIt->second;
	std::list<IObserver*>::iterator listIt(obList->begin());
	while (listIt != obList->end()) {
		if ((int)(*listIt) == (int)observer) {
			std::cout << "ÖØ¸´Ìí¼Ó¶©ÔÄÕß" << std::endl;
			return false;
		}

		listIt++;
	}
	mapIt->second->push_back(observer);
	return true;
}

bool Subject::DelObserver(EVENTTYPE eventType, IObserver *observer) {
	it_eEVENTTYPEpList mapIt(m_observerMap.find(eventType));
	if (mapIt != m_observerMap.end()) {
		std::list<IObserver*> *obList = mapIt->second;
		std::list<IObserver*>::iterator listIt(obList->begin());
		while (listIt != obList->end()) {
			if ((int)(*listIt) == (int)observer) {
				obList->erase(listIt);
				if (obList->size() == 0) {
					delete obList;
					m_observerMap.erase(mapIt);
				}
				return true;
			}

			listIt++;
		}
	}
	return false;
}

void Subject::Notify(EVENTTYPE eventType, MSG notifyContext) {
	it_eEVENTTYPEpList mapIt(m_observerMap.find(eventType));
	if (mapIt == m_observerMap.end()) {
		return;
	} else {
		std::list<IObserver*> *obList = mapIt->second;
		std::list<IObserver*>::iterator listIt(obList->begin());
		while (listIt != obList->end()) {
			(*listIt)->GetNotify(eventType, notifyContext);

			listIt++;
		}
	}
}
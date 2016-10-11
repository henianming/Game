#include "Subject.h"

#include <Windows.h>

typedef std::map<EVENTTYPE, std::list<IObserver*>*>::iterator it_eEVENTTYPEpList;

bool Subject::Init() {
	MessageBox(0, L"Subject::Init", L"out", MB_OK);

	return true;
}

void Subject::UnInit() {
	MessageBox(0, L"Subject::UnInit", L"out", MB_OK);

	it_eEVENTTYPEpList mIt = m_observerMap.begin();
	while (mIt != m_observerMap.end()) {
		if (mIt->second != NULL) {
			delete mIt->second;
		}
		mIt++;
	}
}

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
			//std::cout << "ÖØ¸´Ìí¼Ó¶©ÔÄÕß" << std::endl;
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

void Subject::Notify(EVENTTYPE eventType, GAMEMSG notifyContext) {
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

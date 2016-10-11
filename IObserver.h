#ifndef IOBSERVER
#define IOBSERVER

class IObserver {
public:
	virtual void GetNotify(EVENTTYPE eventType, GAMEMSG notifyContext) = 0;
};

#endif //IOBSERVER
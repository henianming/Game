#ifndef GLOBALDATA
#define GLOBALDATA

#include "SingletonTemplate.h"

class GlobalData : public SingletonTemplate<GlobalData> {
public:
	bool Init();
	void UnInit();
};

#endif //GLOBALDATA

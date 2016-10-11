#include "GlobalData.h"

#include <Windows.h>

bool GlobalData::Init() {
	MessageBox(0, L"GlobalData::Init", L"out", MB_OK);

	return true;
}

void GlobalData::UnInit() {
	MessageBox(0, L"GlobalData::UnInit", L"out", MB_OK);
}

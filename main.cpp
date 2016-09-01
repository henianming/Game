#include <windows.h>

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg) {
	case WM_KEYUP:
		switch (wParam) {
		case VK_RETURN:
			MessageBox(0, L"Enter", L"Msg", MB_OK);
			break;
		case VK_ESCAPE:
			DestroyWindow(hWnd);
			break;
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}

void InitWNDCLASS(WNDCLASS &wc, HINSTANCE hInstance) {
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = static_cast<HBRUSH>(GetStockObject(BLACK_BRUSH));
	wc.hCursor = LoadCursor(0, IDC_ARROW);
	wc.hIcon = LoadIcon(0, IDI_APPLICATION);
	wc.hInstance = hInstance;
	wc.lpfnWndProc = WndProc;
	wc.lpszClassName = L"Direct Main Window Class";
	wc.lpszMenuName = 0;
	wc.style = CS_HREDRAW | CS_VREDRAW;
}

void MsgLoop() {
	MSG msg = {};
	while (msg.message != WM_QUIT) {
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE)) {
			DispatchMessage(&msg);
		}
	}
}

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hInstancePrev, LPSTR cmdLine, int showWindowCommand) {
	WNDCLASS wc;

	InitWNDCLASS(wc, hInstance);

	if (!RegisterClass(&wc)) {
		MessageBox(0, L"RegisterClass Failed!", L"Error", MB_OK);
	}

	HWND hWnd = CreateWindow(L"Direct Main Window Class", L"Direct Main Window",
							 WS_OVERLAPPEDWINDOW,
							 CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
							 0, 0, hInstance, 0);

	ShowWindow(hWnd, showWindowCommand);

	MsgLoop();
	return 0;
}
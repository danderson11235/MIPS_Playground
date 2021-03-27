#include <Windows.h>
#include <iostream>

LRESULT CALLBACK winCallBack(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow){
	//setup window
	WNDCLASS windowClass = {};
	windowClass.style = CS_HREDRAW | CS_VREDRAW;
	windowClass.lpszClassName = "MIPS playground Class";
	windowClass.lpfnWndProc = winCallBack;
	

	RegisterClass(&windowClass);

	HWND hwnd = CreateWindowEx(0, windowClass.lpszClassName, "MIPS playground", windowClass.style,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, NULL,
		hInstance,
		NULL);
	if (hwnd == NULL) return 1;
	ShowWindow(hwnd, nCmdShow);

	MSG msg = {};
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}
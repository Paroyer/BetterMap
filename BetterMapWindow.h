#ifndef BETTERMAPWINDOW_H
#define BETTERMAPWINDOW_H

#include "cwmods/cwsdk.h"
#include "imgui-1.73/imgui.h"
#include "imgui-1.73/examples/imgui_impl_dx11.h"
#include "imgui-1.73/examples/imgui_impl_win32.h"


class BetterMapMod;
class BuildWindow {
	bool QuestIconEnable = false;
	bool QuestNameEnable = false;
	bool OthersEnable = false;
	bool ShowMapBorderEnable = false;
	bool ShowFlightPointEnable = false;
	bool IncreaseMapZoomEnable = false;
	bool IncreaseMinimapRotationEnable = false;

	bool wantMouse = false;
	bool wantKeyboard = false;
	bool initialized = false;

	cube::Game* game;
	BetterMapMod* mod;
public:
	BuildWindow(BetterMapMod* mod); 
	void Present();
	void Initialize();
	void Update();
	int WindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	void OnGetMouseState(DIMOUSESTATE* diMouse);
	void OnGetKeyboardState(BYTE* diKeys);

};

#endif // BETTERMAPWINDOW_H
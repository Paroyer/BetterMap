#ifndef BETTERMAPMOD_H
#define BETTERMAPMOD_H
#include "CWSDK/cwsdk.h"
#include "DButton.h"
#include "BetterMapWindow.h"

class BetterMapMod : GenericMod {
private:
	DButton Button = DButton(DIK_GRAVE);
	cube::Game* game;
	BetterMapwindow* BetterMapWindow;

public:
	

private:
	void PrintMessagePrefix();
	bool InOtherGUI();

	// Event handlers
	virtual void Initialize() override;
	virtual void OnGameTick(cube::Game* game) override;
	virtual void OnGetKeyboardState(BYTE* diKeys) override;
	virtual void OnGetMouseState(DIMOUSESTATE* diMouse) override;
	virtual void OnPresent(IDXGISwapChain* SwapChain, UINT SyncInterval, UINT Flags) override;
	virtual int OnWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) override;
	virtual int OnChat(std::wstring* msg) override;
};

#endif

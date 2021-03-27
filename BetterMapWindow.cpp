#include "BetterMapWindow.h"
#include "BetterMapMod.h"

void DrawCursor(cube::Game* game);

BetterMapwindow::BetterMapwindow(BetterMapMod* BetterMapWindow) {//DontChange BuildWindow
	this->BetterMapWindow = BetterMapWindow;
}

void BetterMapwindow::Present() {
	if (!initialized) {
		if (!Initialize()) {
			return;
		}
	}

	if (!game->gui.map_open) {//Show With Map
		wantMouse = false;
		wantKeyboard = false;
		return;
	}

	ImGui::GetStyle().Colors[ImGuiCol_WindowBg] = ImVec4(0.10f, 0.10f, 0.10f, 1.00f);//Background Color
	ImGui::GetStyle().Colors[ImGuiCol_TitleBgActive] = ImVec4(0.10f, 0.10f, 0.10f, 1.00f);//TitleBarColor
	ImGuiIO& io = ImGui::GetIO();
	io.IniFilename = nullptr;
	wantMouse = io.WantCaptureMouse;
	wantKeyboard = io.WantCaptureKeyboard;
	io.DisplaySize = ImVec2((float)game->width, (float)game->height);
	io.Fonts->AddFontFromFileTTF("resource1.dat", 16.0f);//Font

	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();
	ImVec2 size(300, 220);//Windows Size
	ImGui::SetNextWindowSize(size);
	ImGui::SetNextWindowPos(ImVec2(50, 75), ImGuiCond_Once);
	ImGui::Begin("BetterMap Mod", nullptr, size, -1.0, ImGuiWindowFlags_NoResize);

	ImGui::Separator();

	ImGui::Checkbox("Quest Icon", &QuestIconEnable);
	if (QuestIconEnable) {
		WriteByte(CWOffset(0x5F6AE), 0xEB);
	}

	ImGui::Checkbox("Quest Name", &QuestNameEnable);
	if (QuestNameEnable) {
		WriteByte(CWOffset(0x283CE8), 0x80);
	}

	ImGui::Checkbox("Lore / Shrine / Treasure", &OthersEnable);
	if (OthersEnable) {
		WriteByte(CWOffset(0x283358 + 1), 0x80);
	}

	ImGui::Checkbox("Map Border", &ShowMapBorderEnable);
	if (ShowMapBorderEnable) {
		WriteByte(CWOffset(0x2F5934), 0x70);
		WriteByte(CWOffset(0x2F5939), 0xEB);
		WriteByte(CWOffset(0x2F57E9), 0xC7);
		WriteByte(CWOffset(0x2F57E9 + 1), 0x85);
		WriteByte(CWOffset(0x2F57E9 + 6), 0x00);
		WriteByte(CWOffset(0x2F57E9 + 7), 0x00);
		WriteByte(CWOffset(0x2F57E9 + 8), 0x00);
		WriteByte(CWOffset(0x2F57E9 + 9), 0x00);
	}

	ImGui::Checkbox("Flight Point", &ShowFlightPointEnable);
	if (ShowFlightPointEnable) {
		WriteByte(CWOffset(0x2849CF + 1), 0x80);
		WriteByte(CWOffset(0x285416), 0x70);
	}

	ImGui::Checkbox("Increase Map Zoom", &IncreaseMapZoomEnable);
	if (IncreaseMapZoomEnable) {
		WriteByte(CWOffset(0x97F13 + 1), 0x08);
		WriteByte(CWOffset(0x97F01 + 1), 0x83);
		WriteByte(CWOffset(0x97F07 + 1), 0xFE);
		WriteByte(CWOffset(0x97F07 + 2), 0xFF);
		WriteByte(CWOffset(0X97F07 + 3), 0xFF);
		WriteByte(CWOffset(0x97F07 + 4), 0xFF);
		WriteByte(CWOffset(0x97F07 + 5), 0x2B);
		WriteByte(CWOffset(0x97F07 + 6), 0xC7);
		WriteByte(CWOffset(0X97F07 + 7), 0x3B);
		WriteByte(CWOffset(0x97F07 + 8), 0xC2);
		WriteByte(CWOffset(0x97F07 + 9), 0x0F);
		WriteByte(CWOffset(0x97F07 + 0x0A), 0x4C);
		WriteByte(CWOffset(0x97F25 + 1), 0x80);
		WriteByte(CWOffset(0x2F45A6 + 1), 0x8B);
		WriteByte(CWOffset(0x2F45A6 + 2), 0xC0);
		WriteByte(CWOffset(0X2F45A6 + 3), 0x90);
		WriteByte(CWOffset(0x2F7F9A + 1), 0x80);
	}

	ImGui::Checkbox("Increase Map Rotation", &IncreaseMinimapRotationEnable);
	if (IncreaseMinimapRotationEnable) {
		WriteByte(CWOffset(0xE6515), 0xEB);
		WriteByte(CWOffset(0xE6515 + 1), 0x06);
	}

	if (!QuestIconEnable) {
		WriteByte(CWOffset(0x5F6AE), 0x75);
	}	
	if (!QuestNameEnable) {
		WriteByte(CWOffset(0x283CE8), 0x84);
	}
	if (!OthersEnable) {
		WriteByte(CWOffset(0x283358 + 1), 0x84);
	}
	if (!ShowMapBorderEnable) {
		WriteByte(CWOffset(0x2F5934), 0x7C);
		WriteByte(CWOffset(0x2F5939), 0x7C);
		WriteByte(CWOffset(0x2F57E9), 0x81);
		WriteByte(CWOffset(0x2F57E9 + 1), 0xBD);
		WriteByte(CWOffset(0x2F57E9 + 6), 0xFF);
		WriteByte(CWOffset(0x2F57E9 + 7), 0xFF);
		WriteByte(CWOffset(0x2F57E9 + 8), 0xFF);
		WriteByte(CWOffset(0x2F57E9 + 9), 0x7F);
	}
	if (!ShowFlightPointEnable) {
		WriteByte(CWOffset(0x2849CF + 1), 0x84);
		WriteByte(CWOffset(0x285416), 0x74);
	}
	if (!IncreaseMapZoomEnable) {
		WriteByte(CWOffset(0x97F13 + 1), 0x06);
		WriteByte(CWOffset(0x97F01 + 1), 0x8B);
		WriteByte(CWOffset(0x97F07 + 1), 0x00);
		WriteByte(CWOffset(0x97F07 + 2), 0x00);
		WriteByte(CWOffset(0X97F07 + 3), 0x00);
		WriteByte(CWOffset(0x97F07 + 4), 0x00);
		WriteByte(CWOffset(0x97F07 + 5), 0x8B);
		WriteByte(CWOffset(0x97F07 + 6), 0xC1);
		WriteByte(CWOffset(0X97F07 + 7), 0x2B);
		WriteByte(CWOffset(0x97F07 + 8), 0xC7);
		WriteByte(CWOffset(0x97F07 + 9), 0x0F);
		WriteByte(CWOffset(0x97F07 + 0x0A), 0x48);
		WriteByte(CWOffset(0x97F25 + 1), 0x84);
		WriteByte(CWOffset(0x2F45A6 + 1), 0x0F);
		WriteByte(CWOffset(0x2F45A6 + 2), 0x49);
		WriteByte(CWOffset(0X2F45A6 + 3), 0xC0);
		WriteByte(CWOffset(0x2F7F9A + 1), 0x88);
	}
	if (!IncreaseMinimapRotationEnable) {
		WriteByte(CWOffset(0xE6515), 0xF3);
		WriteByte(CWOffset(0xE6515 + 1), 0x0F);
	}

	ImGui::End();
	ImGui::EndFrame();
	ImGui::Render();
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
	DrawCursor(this->game);
}

bool BetterMapwindow::Initialize() 
{
	HWND hWnd = GetActiveWindow();
	if (!hWnd) return false;
	game = cube::GetGame();
	initialized = true;
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGui::StyleColorsDark(); 
	ImGui_ImplWin32_Init(hWnd);
	ImGui_ImplDX11_Init(cube::GetID3D11Device(), cube::GetID3D11DeviceContext());
	return true;
}

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);//DontTouch
int BetterMapwindow::WindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {//DontTouch
	ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam);
	if (wantMouse) {
		switch (msg) {
			case WM_LBUTTONDOWN:
			case WM_RBUTTONDOWN:
				return 1;
		}
	}
	if (wantKeyboard) return 1;
	return 0;
}

void BetterMapwindow::OnGetKeyboardState(BYTE* diKeys) {//DontTouch
	if (wantKeyboard) {
		memset(diKeys, 0, 256);
	}
}

void BetterMapwindow::OnGetMouseState(DIMOUSESTATE* diMouse) {//DontTouch
	if (wantMouse) {
		diMouse->rgbButtons[0] = 0;
		diMouse->rgbButtons[1] = 0;
		diMouse->rgbButtons[2] = 0;
	}
}

void DrawCursor(cube::Game* game)
{
	float guiScale = game->options.guiScale;
	FloatVector2 cursorPosition = game->plasma_engine->mouse_position;
	plasma::Matrix<float>* trans = &game->gui.cursor_node->transformation->matrix;
	plasma::Matrix<float> oldTrans = *trans;
	*trans = trans->scale(guiScale).translate(cursorPosition.x - (cursorPosition.x / guiScale), cursorPosition.y - (cursorPosition.y / guiScale), 0);

	game->gui.cursor_node->Draw(0);

	*trans = oldTrans;
}
#include "BetterMapMod.h"

bool DivideKeyPress = false;

void BetterMapMod::PrintMessagePrefix() { 
	game->PrintMessage(L"[");
	game->PrintMessage(L"BetterMap Mod", 135, 206, 250);
	game->PrintMessage(L"] ");
}

bool BetterMapMod::InOtherGUI() {
	cube::GUI* gui = &game->gui;
	plasma::Node* nodes[] = {
		gui->startmenu_node,
		gui->character_selection_node,
		gui->character_creation_node,
		gui->equipment_inventory_widget->node,
		gui->crafting_inventory_widget->node,
		gui->multiplayer_widget->node,
		gui->vendor_inventory_widget->node,
		gui->adaption_widget->node,
		gui->voxel_widget->node,
		gui->enchant_widget->node,
		gui->question_widget->node,
		gui->system_widget->node,
		gui->controls_widget->node,
		gui->options_widget->node
	};

	for (plasma::Node* node : nodes) {
		if (!node) continue;
		auto data = &node->display->visibility.data;
		auto frame = node->display->visibility.current_frame;

		if (data->at(frame)) {
			return true;
		}
	}

	if (gui->chat_widget->typebox_active) return true;
	if (gui->map_open) return true;
	if (gui->esc_menu_displayed) return true;

	return false;
}


// Event handlers
void BetterMapMod::Initialize() { 

	BetterMapWindow = new BetterMapwindow(this); 
}

void BetterMapMod::OnGameTick(cube::Game* game) { 
	this->game = game;
}

void BetterMapMod::OnGetKeyboardState(BYTE* diKeys) {
	if (DivideKeyPress == true) {
		WriteByte(CWOffset(0xA38D3), 0x90);
		WriteByte(CWOffset(0xA38D3 + 1), 0x90);
		WriteByte(CWOffset(0xA38D3 + 2), 0x90);
		WriteByte(CWOffset(0xA38D3 + 3), 0x90);
		WriteByte(CWOffset(0xA38D3 + 4), 0x90);
		WriteByte(CWOffset(0xA38D3 + 5), 0x90);
		WriteByte(CWOffset(0xA38D3 + 6), 0x90);
		WriteByte(CWOffset(0xA38D3 + 7), 0x90);
		WriteByte(CWOffset(0xA38EE), 0x90);
		WriteByte(CWOffset(0xA38EE + 1), 0x90);
		WriteByte(CWOffset(0xA38EE + 2), 0x90);
		WriteByte(CWOffset(0xA38EE + 3), 0x90);
		WriteByte(CWOffset(0xA38EE + 4), 0x90);
		WriteByte(CWOffset(0xA38EE + 5), 0x90);
		WriteByte(CWOffset(0xA38EE + 6), 0x90);
		game->Walk_Z = 1.f;
	}
	static DButton DivideKey(181);
	BetterMapWindow->OnGetKeyboardState(diKeys);
	DivideKey.Update(diKeys);
	if (DivideKey.Pressed()) {
		if (DivideKeyPress == true) {
			DivideKeyPress = false;
			WriteByte(CWOffset(0xA38D3), 0xF3);
			WriteByte(CWOffset(0xA38D3 + 1), 0x0F);
			WriteByte(CWOffset(0xA38D3 + 2), 0x11);
			WriteByte(CWOffset(0xA38D3 + 3), 0x91);
			WriteByte(CWOffset(0xA38D3 + 4), 0x70);
			WriteByte(CWOffset(0xA38D3 + 5), 0x1D);
			WriteByte(CWOffset(0xA38D3 + 6), 0x00);
			WriteByte(CWOffset(0xA38D3 + 7), 0x00);
			WriteByte(CWOffset(0xA38EE), 0x48);
			WriteByte(CWOffset(0xA38EE + 1), 0x89);
			WriteByte(CWOffset(0xA38EE + 2), 0x81);
			WriteByte(CWOffset(0xA38EE + 3), 0x6C);
			WriteByte(CWOffset(0xA38EE + 4), 0x1D);
			WriteByte(CWOffset(0xA38EE + 5), 0x00);
			WriteByte(CWOffset(0xA38EE + 6), 0x00);
		}
		else {
		DivideKeyPress = true;
		}
	}
}

void BetterMapMod::OnGetMouseState(DIMOUSESTATE* diMouse) { 
	BetterMapWindow->OnGetMouseState(diMouse);

}

void BetterMapMod::OnPresent(IDXGISwapChain* SwapChain, UINT SyncInterval, UINT Flags) {
	BetterMapWindow->Present();
}

int BetterMapMod::OnWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	return BetterMapWindow->WindowProc(hwnd, uMsg, wParam, lParam);
}

int BetterMapMod::OnChat(std::wstring* msg) {
	if (!wcscmp(msg->c_str(), L"/bettermap info")) {
		game->PrintMessage(L"[Quest Icon] Show the quest icons on the map\n", 135, 206, 250);
		game->PrintMessage(L"[Quest Name] Show the quest Names on the map\n", 135, 206, 250);
		game->PrintMessage(L"[Lore/Shrine/Treasure] Show those on the map, tho cant use shrine until you get there\n", 135, 206, 250);
		return 1;
	}		
	return 0;
}
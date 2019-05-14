#ifndef _MODULECHARACTERSELECTION_H_
#define _MODULECHARACTERSELECTION_H_
#include"Module.h"
#include "Animation.h"
#include "ModuleTextures.h"
#include "Globals.h"

class ModuleCharacterSelection :public Module {
public:
	ModuleCharacterSelection();
	~ModuleCharacterSelection();
	bool Start();
	update_status Update();
	bool CleanUp();

public:
	SDL_Rect background;
	SDL_Rect ukyoletters;
	SDL_Rect charactersrect;
	Animation UkyoIdle;
	Animation SelectionAnimation;
	SDL_Texture* graphics = nullptr;
};
#endif //
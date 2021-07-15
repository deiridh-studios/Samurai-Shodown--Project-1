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
	SDL_Rect charactersrect;
	Animation GenAnP1;
	Animation GenAnP2;
	Animation GalfordP1;
	Animation GalfordP2;
	Animation HaohmaruP1;
	Animation HaohmaruP2;
	Animation UkyoP1;
	Animation UkyoP2;
	Animation CharlotteP1;
	Animation CharlotteP2;
	Animation TamTamP1;
	Animation TamTamP2;
	Animation EarthquakeP1;
	Animation EarthquakeP2;
	Animation NakoruruP1;
	Animation NakoruruP2;
	Animation WanFuP1;
	Animation WanFuP2;
	Animation HanzoP1;
	Animation HanzoP2;
	Animation JubeiP1;
	Animation JubeiP2;
	Animation KyoshiroP1;
	Animation KyoshiroP2;
	Animation SelectionAnimation;
	Animation SelectionAnimationP1;
	Animation SelectionAnimationP2;
	Mix_Chunk* passingmenu;
	Mix_Chunk* entermenu;
	SDL_Texture* graphics = nullptr;
};
#endif //
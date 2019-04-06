#ifndef _MODULESCENEWELCOME_H
#define _MODULESCENEWELCOME_H
#include"Module.h"
#include "Animation.h"
#include "ModuleTextures.h"
#include "Globals.h"

class ModuleSceneWelcome :public Module {
public:
	ModuleSceneWelcome();
	~ModuleSceneWelcome();
	bool Start();
	update_status Update();
	bool CleanUp();

public:
	SDL_Rect rectbackground;
	SDL_Rect rectword;
	SDL_Texture* graphics = nullptr;
	SDL_Texture* graphics2 = nullptr;
	Animation Words;
	Animation Title;
};
#endif //
#ifndef _MODULEBACKGROUNG_H
#define _MODULEBACKGROUND_H
#include"Module.h"
#include "Animation.h"
#include "ModuleTextures.h"
#include "SDL/include/SDL.h"
class ModuleBackground :public Module {
public:
	ModuleBackground();
	~ModuleBackground();
	bool Start();
	update_status Update();
	bool CleanUp();

public:
	SDL_Rect rectbackground;
	int scrollleft;
	int scrollright;
	int x1 = 0;
	Animation back;
	SDL_Texture* graphics = nullptr;
};
#endif //
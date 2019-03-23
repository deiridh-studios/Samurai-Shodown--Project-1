#ifndef _MODULEBACKGROUNG_H
#define _MODULEBACKGROUND_H
#include"Module.h"
#include "SDL/include/SDL.h"
class ModuleBackground :public Module {
public:
	ModuleBackground();
	~ModuleBackground();
	bool Init();
	update_status Update();

public:
	SDL_Rect rectbackground;
	int scrollleft;
	int scrollright;
};
#endif //
#ifndef _MODULESCENEEARTHQUAKE_H
#define _MODULESCENEEARTHQUAKE_H
#include"Module.h"
#include "Animation.h"
#include "ModuleTextures.h"
#include "Globals.h"

struct Mix_Chunk;

class ModuleSceneEarthquake :public Module {
public:
	ModuleSceneEarthquake();
	~ModuleSceneEarthquake();
	bool Start();
	update_status Update();
	bool CleanUp();

public:
	Mix_Chunk* earthquake;
	SDL_Rect rectbackground;
	int scrollleft;
	int scrollright;
	int x1 = 0;
	Animation back;
	Animation AWithWeapon;
	Animation BWithWeapon;
	Animation ABWithWeapon;
	Animation AWithoutWeapon;
	Animation BWithoutWeapon;
	Animation ABWithoutWeapon;
	Animation CWithoutWeapon;
	Animation DWithoutWeapon;
	Animation CDWithoutWeapon;
	Animation rectangletextA;
	Animation rectangletextB;
	Animation rectangletextAB;
	Animation rectangletextA2;
	Animation rectangletextB2;
	Animation rectangletextAB2;
	Animation rectangletextC2;
	Animation rectangletextD2;
	Animation rectangletextCD2;
	Animation APushing;
	Animation BPushing;
	Animation CPushing;
	Animation DPushing;
	Animation ANormal;
	Animation BNormal;
	Animation CNormal;
	Animation DNormal;
	Animation IdleUkyo1;
	Animation strongerkickUkyo1;
	Animation kickUkyo1;
	Animation punchUkyo1;
	Animation clashswordsUkyo1;
	Animation strongerslashUkyo1;
	Animation IdleUkyo2;
	Animation clashswordsUkyo2;
	SDL_Texture* graphics = nullptr;
	SDL_Texture* graphics2 = nullptr;
	SDL_Texture* graphics3 = nullptr;
};
#endif //
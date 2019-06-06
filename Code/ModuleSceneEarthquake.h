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
	Animation Idle2Ukyo1;
	Animation AWithWeaponUkyo1;
	Animation BWithWeaponUkyo1;
	Animation ABWithWeaponUkyo1;
	Animation AWithoutWeaponUkyo1;
	Animation ABWithoutWeaponUkyo1;
	Animation CWithoutWeaponUkyo1;
	Animation CDWithoutWeaponUkyo1;
	Animation clashswordsUkyo1;
	Animation IdleUkyo2;
	Animation clashswordsUkyo2;
	Animation HittedUkyo2;
	Animation WalkingUkyo2;
	Animation rectangletextempty;
	SDL_Texture* graphics = nullptr;
	SDL_Texture* graphics2 = nullptr;
	SDL_Texture* graphics3 = nullptr;
};
#endif //
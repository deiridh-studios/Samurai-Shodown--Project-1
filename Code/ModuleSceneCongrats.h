#ifndef _MODULESCENECONGRATS_H
#define _MODULESCENECONGRATS_H
#include"Module.h"
#include "Animation.h"
#include "ModuleTextures.h"
#include "Globals.h"

class ModuleSceneCongrats :public Module {
public:
	ModuleSceneCongrats();
	~ModuleSceneCongrats();
	bool Start();
	update_status Update();
	bool CleanUp();

public:
	SDL_Rect UkyoPlayer2WIN;
	SDL_Rect UkyoPlayer1WIN;
	SDL_Rect UkyoPlayer2LOSE;
	SDL_Rect UkyoPlayer1LOSE;
	SDL_Rect lettersfinished;
	Animation backgroundUkyo1;
	Animation backgroundUkyo2;
	Animation letters;
	SDL_Texture* graphics = nullptr;
	int font_victory;
	char victory_text[2];
};
#endif //
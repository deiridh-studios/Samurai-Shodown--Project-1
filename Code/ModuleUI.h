#ifndef __ModuleUI_H__
#define __ModuleUI_H__

#include "Module.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleUI :public Module {
public:
	ModuleUI();
	~ModuleUI();
	bool Start();
	update_status Update();
	bool CleanUp();
	void DamageTaken(int, int);
	



private:
	int font_score;
	char time_text[10];
	uint time;
	uint initialtime;
	SDL_Rect lifeplayer1;
	SDL_Rect lifeplayer2;
	SDL_Rect lifebarplayer1;
	SDL_Rect ukyoplayer1rect;
	SDL_Rect ukyoplayer2rect;
	SDL_Rect lifebarplayer2;
	SDL_Rect komessage;
	char axisx[10];
	char axisy[10];
	int player1life;
	int player2life;
	SDL_Texture *textlife;

};
#endif

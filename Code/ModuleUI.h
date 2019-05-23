#ifndef __ModuleUI_H__
#define __ModuleUI_H__

#include "Module.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleUI :public Module {
public:
	ModuleUI();
	~ModuleUI();
	bool Init();
	update_status Update();
	bool CleanUp();
	void DamageTaken(int, int);
	
public:
	bool play;
	int credits;
	bool doinitialtime;
private:
	int font_score;
	int font_score_white;
	int font_points;
	int font_credits;
	char time_text[10];
	uint time;
	uint initialtime;
	SDL_Rect lifeplayer1;
	SDL_Rect lifeplayer2;
	SDL_Rect lifebarplayer1;
	SDL_Rect lifebarplayer2;
	SDL_Rect lifebarplayer1red;
	SDL_Rect lifebarplayer2red;
	SDL_Rect lifebarplayer1white;
	SDL_Rect lifebarplayer2white;
	SDL_Rect ukyoplayer1rect;
	SDL_Rect ukyoplayer2rect;
	SDL_Rect komessage;
	SDL_Rect komessagewhite;
	SDL_Rect endmessage;
	SDL_Rect endmessagewhite;
	SDL_Rect nameplayer;
	SDL_Rect victorymarker;
	SDL_Rect level4rect;
	SDL_Rect creditrect;
	SDL_Rect creditsrect;
	char axisx[10];
	char axisy[10];
	int player1life;
	int player2life;
	SDL_Texture *textlife;
	SDL_Texture *level4;
	int koblink;
	int timeblink;
	int lifeblink;
	int pointsp1;
	int pointsp2;
	char points1[10];
	char points2[10];
	char creditsc[10];
	int roundsp1;
	int roundsp2;
	int rounds;


};
#endif

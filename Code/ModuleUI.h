#ifndef __ModuleUI_H__
#define __ModuleUI_H__

#include "Module.h"
#include "Globals.h"

struct SDL_Texture;
struct Mix_Chunk;


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
	bool startplay;
	int credits;
	bool doinitialtime;
	int npow1;
	int npow2;
private:
	int font_score;
	int font_score_white;
	int font_points;
	int font_credits;
	int font_finalpoints;
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
	SDL_Rect hitrect;
	SDL_Rect totalrect;
	SDL_Rect liferect;
	SDL_Rect timerect;
	SDL_Rect powbarempty;
	SDL_Rect powbargreen;
	SDL_Rect powbarempty2;
	SDL_Rect powbargreen2;
	SDL_Rect powbaryellow;
	SDL_Rect powbaryellow2;
	SDL_Rect powbarorange;
	SDL_Rect powbarorange2;
	SDL_Rect powbarred;
	SDL_Rect powbarred2;
	SDL_Rect powbarwhite;
	SDL_Rect powbarwhite2;
	SDL_Rect pow1;
	SDL_Rect pow2;
	SDL_Rect pow3;
	SDL_Rect pow4;
	SDL_Rect fullpow1;
	SDL_Rect fullpow2;
	SDL_Rect fullpow3;
	Mix_Chunk *sumpoints;
	Mix_Chunk *sumpoints2;
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
	char score[10];
	int roundsp1;
	int roundsp2;
	int rounds;
	int lifescore;
	int timescore;
	int hitsscore;
	int totalscore;
	int victory;
	int counter;
	int counterpow1;
	int counterpow2;
	int timepow1;
	int timepow2;
	bool finishpow1;
	bool finishpow2;
	bool finished;


};
#endif

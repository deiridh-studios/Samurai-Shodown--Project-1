#ifndef __ModulePlayer2_H__
#define __ModulePlayer2_H__

#include "Module.h"
#include "Animation.h"
#include "ModulePlayer.h"
#include "Globals.h"
#include "p2Point.h"

#define INPUTSOUTS 8

struct SDL_Texture;
struct Mix_Chunk;
struct Collider;

class ModulePlayer2 : public Module
{
public:
	ModulePlayer2();
	~ModulePlayer2();

	bool Start();
	update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();
	bool CleanUp();
	void OnCollision(Collider*, Collider*);

public:


	SDL_Texture* graphics = nullptr;
	SDL_Texture* graphics2 = nullptr;
	Animation idle;
	Animation forward;
	Animation backward;
	Animation punch;
	Animation kick;
	Animation strongerkick;
	Animation jump;
	Animation appleattack;
	Animation hittedan;
	Animation hittedan_nosword;
	Animation crouch;
	Animation crouchfinished;
	Animation punchair;
	Animation punchcrouch;
	Animation kickair;
	Animation kickcrouch;
	Animation lostweapon;
	Animation clashswords;
	Animation shadow;
	Animation prebattle;
	Animation win;
	Animation firebird;
	Animation rollattack;
	Animation airhitted;
	Animation strongerslash;
	Animation specialcrouchattack;
	Animation runweapon;
	Animation runnoweapon;
	Animation powerfulslash;
	Animation gripwithweapon;
	Animation strongpunch_noweapon;
	Animation punchair_noweapon;
	Animation punchcrouch_noweapon;
	Animation kick_noweapon;
	Animation kickair_noweapon;
	Animation kickcrouch_noweapon;
	Animation agarre_noweapon;
	Animation slash_noweapon;
	Animation dash;
	Animation dashnoweapon;
	Animation protect;
	Animation* current_animation;
	iPoint position;
	Collider* bodyenemy;
	Collider* bodyenemy2;
	Collider* bodyenemy3;
	Collider* enemyattack;
	int mult;
	state actual3;
	inputin inputstate2[60];
	inputout inputstateout2[INPUTSOUTS];
	int inputsouts;
	int jump_timer;
	int punch_timer;
	int kick_timer;
	int specialattack_timer;
	int hitted_timer;
	int nattacks;
	int nattackss;
	bool inattack;
	bool victory;
	bool stopleft;
	bool flip;
	bool stopright;
	bool inair[60];
	bool notfinished;
	bool sword;
	bool pow;
	bool aftercrouch;
	bool movementextra;
	float posx;
	int positionx2;
};
#endif
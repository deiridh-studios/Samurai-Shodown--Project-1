#ifndef __ModulePlayer_H__
#define __ModulePlayer_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"

struct SDL_Texture;
struct Mix_Chunk;
struct Collider;

#define INPUTSOUTS 8

enum state {
	A_NONE = 0,
	A_IDLE,
	A_WALK_FORWARD,
	A_WALK_BACKWARD,
	A_JUMP_NEUTRAL,
	A_JUMP_FORWARD,
	A_JUMP_BACKWARD,
	A_CROUCH,
	A_PUNCH_STANDING,
	A_PUNCH_NEUTRAL_JUMP,
	A_PUNCH_FORWARD_JUMP,
	A_PUNCH_BACKWARD_JUMP,
	A_PUNCH_CROUCH,
	A_KICK_STANDING,
	A_KICK_NEUTRAL_JUMP,
	A_KICK_FORWARD_JUMP,
	A_KICK_BACKWARD_JUMP,
	A_KICK_CROUCH,
	A_TORNADO,
	A_APPLEATTACK,
	A_HITTED,
	A_LOSTWEAPON,
	A_CLASHWEAPONS
};
enum inputin {
	S_NONE = 0,
	S_LEFT_DOWN,
	S_RIGHT_DOWN,
	S_LEFT_AND_RIGHT, //delete with gamepad
	S_JUMP,
	S_JUMP_RIGHT,
	S_JUMP_LEFT,
	S_CROUCH_DOWN,
	S_CROUCH_RIGHT,
	//S_CROUCH_LEFT,
	S_JUMP_AND_CROUCH, //delete with gamepad
	S_T,
	S_Y,
//	S_T_Y,
	S_T_LEFT,
	S_T_RIGHT,
	S_T_JUMP,
	S_T_JUMP_RIGHT,
	S_T_JUMP_LEFT,
	S_T_CROUCH,
	S_T_CROUCH_RIGHT,
	S_Y_LEFT,
	S_Y_RIGHT,
	S_Y_JUMP,
	S_Y_JUMP_RIGHT,
	S_Y_JUMP_LEFT,
	S_Y_CROUCH,
	S_Y_CROUCH_RIGHT,
	S_TORNADO,
	S_APPLEATTACK
};
enum inputout {
	SO_NONE=0,
	SO_LEFT_UP,
	SO_RIGHT_UP,
	SO_CROUCH_UP,
	SO_JUMP_FINISH,
	SO_PUNCH_FINISH,
	SO_KICK_FINISH,
	SO_TORNADO_FINISH,
	SO_APPLEATTACK_FINISH,
	SO_HITTED_FINISH
};

class ModulePlayer : public Module
{
public:
	ModulePlayer();
	~ModulePlayer();

	bool Start();
	update_status PreUpdate();
	update_status Update();
	bool CleanUp();
	void OnCollision(Collider*, Collider*);

public:

	Mix_Chunk *punchsound;
	Mix_Chunk *jumpsound;
	Mix_Chunk *kicksound;
	Mix_Chunk *hittedsound;
	Mix_Chunk *tornadosound;
	SDL_Texture* graphics = nullptr;
	SDL_Texture* graphics2 = nullptr;
	Animation idle;
	Animation forward;
	Animation backward;
	Animation punch;
	Animation kick;
	Animation strongerkick;
	Animation jump;
	Animation jumpforward;
	Animation jumpbackward;
	Animation appleattack;
	Animation tornado;
	Animation hittedan;
	Animation crouch;
	Animation crouchfinished;
	Animation punchair;
	Animation punchcrouch;
	Animation kickair;
	Animation kickcrouch;
	Animation lostweapon;
	Animation clashswords;
	SDL_Rect shadowrect;

	iPoint position;
	int mult;
	state actual;
	inputin inputstate[60];
	inputout inputstateout[INPUTSOUTS];
	Collider* body;
	Collider* body2;
	Collider* body3;
	Collider* attack;
	int jump_timer;
	int punch_timer;
	int kick_timer;
	int tornado_timer;
	int hitted_timer;
	int inputsouts;
	bool victory;
	bool flip;
	bool stopleft;
	bool stopright;

};

#endif
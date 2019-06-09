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
	A_PUNCHL_STANDING,
	A_PUNCHL_NEUTRAL_JUMP,
	A_PUNCHL_FORWARD_JUMP,
	A_PUNCHL_BACKWARD_JUMP,
	A_PUNCHL_CROUCH,
	A_PUNCHS_STANDING,
	A_PUNCHS_NEUTRAL_JUMP,
	A_PUNCHS_FORWARD_JUMP,
	A_PUNCHS_BACKWARD_JUMP,
	A_PUNCHS_CROUCH,
	A_KICKL_STANDING,
	A_KICKL_NEUTRAL_JUMP,
	A_KICKL_FORWARD_JUMP,
	A_KICKL_BACKWARD_JUMP,
	A_KICKL_CROUCH,
	A_KICKS_STANDING,
	A_KICKS_NEUTRAL_JUMP,
	A_KICKS_FORWARD_JUMP,
	A_KICKS_BACKWARD_JUMP,
	A_KICKS_CROUCH,
	A_KICK_STANDING,
	A_KICK_NEUTRAL_JUMP,
	A_KICK_FORWARD_JUMP,
	A_KICK_BACKWARD_JUMP,
	A_KICK_CROUCH,
	A_APPLEATTACK,
	A_HITTED,
	A_HITTED_JUMP,
	A_LOSTWEAPON,
	A_CLASHWEAPONS,
	A_PREBATTLEPOSE,
	A_WINNER,
	A_FIREEAGLE,
	A_ROLLATTACK,
	A_DASH,
	A_BACKDASH,
	A_DASH_NOWEAPON,
	A_BACKDASH_NOWEAPON,
	A_SPECIAL_ATTACK_CROUCH,
	A_RUN_WEAPON,
	A_RUN_NOWEAPON,
	A_POWERFUL_SLASH,
	A_STRONGPUNCH_NOWEAPON,
	A_PUNCH_AIR_NOWEAPON,
	A_PUNCH_CROUCH_NOWEAPON,
	A_KICK_NOWEAPON,
	A_KICK_AIR_NOWEAPON,
	A_KICK_CROUCH_NOWEAPON,
	A_AGARRE_NOWEAPON,
	A_SLASH_NOWEAPON,
	A_PROTECT,
	A_START


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
	S_CROUCH_LEFT,
	S_JUMP_AND_CROUCH, //delete with gamepad
	S_T,
	S_T_LEFT,
	S_T_RIGHT,
	S_T_JUMP,
	S_T_JUMP_RIGHT,
	S_T_JUMP_LEFT,
	S_T_CROUCH,
	S_T_CROUCH_RIGHT,
	S_T_CROUCH_LEFT,
	S_TR,
	S_TR_LEFT,
	S_TR_RIGHT,
	S_TR_JUMP,
	S_TR_JUMP_RIGHT,
	S_TR_JUMP_LEFT,
	S_TR_CROUCH,
	S_TR_CROUCH_RIGHT,
	S_TR_CROUCH_LEFT,
	S_R,
	S_R_LEFT,
	S_R_RIGHT,
	S_R_JUMP,
	S_R_JUMP_RIGHT,
	S_R_JUMP_LEFT,
	S_R_CROUCH,
	S_R_CROUCH_RIGHT,
	S_R_CROUCH_LEFT,
	S_Y,
	S_Y_LEFT,
	S_Y_RIGHT,
	S_Y_JUMP,
	S_Y_JUMP_RIGHT,
	S_Y_JUMP_LEFT,
	S_Y_CROUCH,
	S_Y_CROUCH_RIGHT,
	S_Y_CROUCH_LEFT,
	S_U,
	S_U_LEFT,
	S_U_RIGHT,
	S_U_JUMP,
	S_U_JUMP_RIGHT,
	S_U_JUMP_LEFT,
	S_U_CROUCH,
	S_U_CROUCH_RIGHT,
	S_U_CROUCH_LEFT,
	S_YU,
	S_YU_LEFT,
	S_YU_RIGHT,
	S_YU_JUMP,
	S_YU_JUMP_RIGHT,
	S_YU_JUMP_LEFT,
	S_YU_CROUCH,
	S_YU_CROUCH_RIGHT,
	S_YU_CROUCH_LEFT,
	S_APPLEATTACK,
	S_FIREEAGLE,
	S_DASH,
	S_BACKDASH
};
enum inputout {
	SO_NONE=0,
	SO_LEFT_UP,
	SO_RIGHT_UP,
	SO_CROUCH_UP,
	SO_JUMP_FINISH,
	SO_PUNCH_FINISH,
	SO_KICK_FINISH,
	SO_APPLEATTACK_FINISH,
	SO_FIREEAGLE_FINISH,
	SO_HITTED_FINISH,
	SO_DASH_FINISH,
	SO_BACKDASH_FINISH
};

class ModulePlayer : public Module
{
public:
	ModulePlayer();
	~ModulePlayer();

	bool Start();
	update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();
	bool CleanUp();
	void OnCollision(Collider*, Collider*);

public:

	Mix_Chunk *punchsound;
	Mix_Chunk *jumpsound;
	Mix_Chunk *kicksound;
	Mix_Chunk *hittedsound;
	Mix_Chunk *tornadosound;
	Mix_Chunk *strongattacksound;
	SDL_Texture* graphics = nullptr;
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
	int specialattack_timer;
	int hitted_timer;
	int inputsouts;
	int nattacks;
	int nattackss;
	bool inattack;
	bool victory;
	bool flip;
	bool stopleft;
	bool stopright;
	bool inair[60];
	bool notfinished;
	bool sword;
	float posx;
	bool pow;
	bool aftercrouch;
	bool movementextra;
	int positionx2;
};

#endif
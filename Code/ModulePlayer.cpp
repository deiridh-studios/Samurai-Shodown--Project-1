#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModulePlayer.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleUI.h"
#include "ModulePlayer2.h"
#include "Modulebackground.h"
#include "StateMachine.h"
#include "SDL/include/SDL_timer.h"


ModulePlayer::ModulePlayer()
{
	position.x = 50;
	position.y = 210;

	// Idle animation
	idle.PushBack({ 0, 0, 75, 137 });
	idle.PushBack({ 75, 0, 75, 137 });
	idle.speed = 0.02f;


	// Walk forward animation
	forward.PushBack({ 185, 0, 75, 137 });
	forward.PushBack({ 260, 0, 72, 137 });
	forward.PushBack({ 332, 0, 81, 137 });
	forward.PushBack({ 413, 0, 87, 137 });
	forward.PushBack({ 500, 0, 81, 137 });
	forward.PushBack({ 581, 0, 72, 137 });
	forward.PushBack({ 653, 0, 75, 137 });
	forward.speed = 0.2f;


	// Walk backwards animation
	backward.PushBack({ 653, 0, 75, 137 });
	backward.PushBack({ 581, 0, 72, 137 });
	backward.PushBack({ 500, 0, 81, 137 });
	backward.PushBack({ 413, 0, 87, 137 });
	backward.PushBack({ 332, 0, 81, 137 });
	backward.PushBack({ 260, 0, 72, 137 });
	backward.PushBack({ 185, 0, 75, 137 });
	backward.speed = 0.2f;


	// Kick animation(TO IMPROVE)
	kick.PushBack({  15, 190, 70, 86 });
	kick.PushBack({ 114, 190, 66, 86 });
	kick.PushBack({ 202, 190, 67, 86 });
	kick.PushBack({ 302, 190, 82, 86 });
	kick.PushBack({ 402, 190, 100, 86 });
	kick.speed = 0.2f;



	//crouch
	crouch.PushBack({ 1243 , 274 , 75 , 137 });
	crouch.PushBack({ 1318 , 274 , 68 , 137 });
	crouch.PushBack({ 1386 , 274 , 67 , 137 });
	crouch.speed = 0.2f;
	

	//crouchfinished
	crouchfinished.PushBack({ 1386 , 274 , 67 , 137 });
	crouchfinished.speed = 0.2f;


	// Punch animation (TO IMPROVE)
	punch.PushBack({ 0, 274, 117, 137 });
	punch.PushBack({ 117, 274, 117, 137 });
	punch.PushBack({ 234, 274, 117, 137 });
	punch.PushBack({ 351, 274, 117, 137 });
	punch.PushBack({ 468, 274, 117, 137 });
	punch.PushBack({ 351, 274, 117, 137 });
	punch.PushBack({ 234, 274, 117, 137 });
	punch.PushBack({ 117, 274, 117, 137 });
	punch.PushBack({ 0, 274, 117, 137 });
	punch.speed = 0.4f;

	// Jump
	jump.PushBack({ 761, 0, 75, 137 });
	jump.PushBack({ 836, 0, 68, 137 });
	jump.PushBack({ 904, 0, 75, 137 });
	jump.PushBack({ 979, 0, 61, 137 });
	jump.PushBack({ 1040, 0, 66, 137 });
	jump.PushBack({ 1106, 0, 63, 137 });
	jump.PushBack({ 1106, 0, 63, 137 });
	jump.PushBack({ 1040, 0, 66, 137 });
	jump.PushBack({ 979, 0, 61, 137 });
	jump.PushBack({ 904, 0, 75, 137 });
	jump.PushBack({ 836, 0, 68, 137 });
	jump.PushBack({ 761, 0, 75, 137 });
	jump.speed = 0.1f;


	// Jump Forward
	jumpforward.PushBack({ 761, 0, 75, 137 });
	jumpforward.PushBack({ 836, 0, 68, 137 });
	jumpforward.PushBack({ 904, 0, 75, 137 });
	jumpforward.PushBack({ 979, 0, 61, 137 });
	jumpforward.PushBack({ 1040, 0, 66, 137 });
	jumpforward.PushBack({ 1106, 0, 63, 137 });
	jumpforward.PushBack({ 1169, 0, 61, 137 });
	jumpforward.PushBack({ 1106, 0, 63, 137 });
	jumpforward.PushBack({ 1040, 0, 66, 137 });
	jumpforward.PushBack({ 979, 0, 61, 137 });
	jumpforward.PushBack({ 904, 0, 75, 137 });
	jumpforward.PushBack({ 836, 0, 68, 137 });
	jumpforward.PushBack({ 761, 0, 75, 137 });
	jumpforward.speed = 0.1f;


	// Jump backwards
	jumpbackward.PushBack({ 761, 0, 75, 137 });
	jumpbackward.PushBack({ 836, 0, 68, 137 });
	jumpbackward.PushBack({ 904, 0, 75, 137 });
	jumpbackward.PushBack({ 979, 0, 61, 137 });
	jumpbackward.PushBack({ 1040, 0, 66, 137 });
	jumpbackward.PushBack({ 1106, 0, 63, 137 });
	jumpbackward.PushBack({ 1169, 0, 61, 137 });
	jumpbackward.PushBack({ 1106, 0, 63, 137 });
	jumpbackward.PushBack({ 1040, 0, 66, 137 });
	jumpbackward.PushBack({ 979, 0, 61, 137 });
	jumpbackward.PushBack({ 904, 0, 75, 137 });
	jumpbackward.PushBack({ 836, 0, 68, 137 });
	jumpbackward.PushBack({ 761, 0, 75, 137 });
	jumpbackward.speed = 0.1f;

	//Tornado
	////////////TO DO/////////////////
	tornado.PushBack({ 0, 2384, 106, 96 });
	tornado.PushBack({ 158, 2384, 72, 96 });
	tornado.PushBack({ 298, 2384, 80, 96 });
	tornado.PushBack({ 454, 2384, 66, 96 });
	tornado.PushBack({ 586, 2376, 100, 104 });
	tornado.PushBack({ 746, 2350, 60, 132 });
	tornado.PushBack({ 851, 2376, 103,  104 });
	tornado.PushBack({ 994, 2380, 104, 100 });
	tornado.PushBack({ 1132, 2380, 102, 100 });
	tornado.PushBack({ 1288, 2380, 102, 100 });
	tornado.PushBack({ 1432, 2380, 104, 100 });
	tornado.PushBack({ 1576, 2380, 104, 100 });
	tornado.PushBack({ 1706, 2380, 110, 100 });
	tornado.PushBack({ 1848, 2380, 106, 100 });
	tornado.PushBack({ 0, 2526, 90, 96 });
	tornado.PushBack({ 154, 2498, 90, 126 });
	tornado.PushBack({ 300, 2514, 90, 110 });
	tornado.speed = 0.2f;


	//AppleAttack
	appleattack.PushBack({ 0, 959, 200, 157 });
	appleattack.PushBack({ 200, 959, 200, 157 });
	appleattack.PushBack({ 400, 959, 200, 157 });
	appleattack.PushBack({ 600, 959, 200, 157 });
	appleattack.PushBack({ 800, 959, 200, 157 });
	appleattack.PushBack({ 1000, 959, 200, 157 });
	appleattack.PushBack({ 1200, 959, 200, 157 });
	appleattack.PushBack({ 1400, 959, 200, 157 });
	appleattack.PushBack({ 1600, 959, 200, 157 });
	appleattack.PushBack({ 1800, 959, 200, 157 });
	appleattack.PushBack({ 0, 1115, 200, 157 });
	appleattack.PushBack({ 200, 1115, 200, 157 });
	appleattack.PushBack({ 400, 1115, 200, 157 });
	appleattack.PushBack({ 600, 1115, 200, 157 });
	appleattack.PushBack({ 800, 1115, 200, 157 });
	appleattack.PushBack({ 1000, 1115, 200, 157 });
	appleattack.PushBack({ 1200, 1115, 200, 157 });
	appleattack.PushBack({ 1400, 1115, 200, 157 });
	appleattack.PushBack({ 1600, 1115, 200, 157 });
	appleattack.PushBack({ 1800, 1115, 200, 157 });
	appleattack.PushBack({ 0, 1271, 200, 157 });
	appleattack.PushBack({ 200, 1271, 200, 157 });
	appleattack.PushBack({ 400, 1271, 200, 157 });
	appleattack.PushBack({ 600, 1271, 200, 157 });
	appleattack.PushBack({ 800, 1271, 200, 157 });
	appleattack.PushBack({ 1000, 1271, 200, 157 });
	appleattack.PushBack({ 1200, 1271, 200, 157 });
	appleattack.PushBack({ 1400, 1271, 200, 157 });
	appleattack.PushBack({ 1600, 1271, 200, 157 });
	appleattack.PushBack({ 1800, 1271, 200, 157 });
	appleattack.PushBack({ 0, 1426, 200, 157 });
	appleattack.PushBack({ 200, 1426, 200, 157 });
	appleattack.PushBack({ 400, 1426, 200, 157 });
	appleattack.PushBack({ 600, 1426, 200, 157 });
	appleattack.PushBack({ 800, 1426, 200, 157 });
	appleattack.PushBack({ 1000, 1426, 200, 157 });
	appleattack.PushBack({ 1200, 1426, 200, 157 });
	appleattack.PushBack({ 1400, 1426, 200, 157 });
	appleattack.PushBack({ 1600, 1426, 200, 157 });
	appleattack.PushBack({ 1800, 1426, 200, 157 });
	appleattack.PushBack({ 0, 1582, 200, 157 });
	appleattack.PushBack({ 200, 1582, 200, 157 });
	appleattack.PushBack({ 400, 1582, 200, 157 });
	appleattack.PushBack({ 600, 1582, 200, 157 });
	appleattack.PushBack({ 800, 1582, 200, 157 });
	appleattack.PushBack({ 1000, 1582, 200, 157 });
	appleattack.PushBack({ 1200, 1582, 200, 157 });
	appleattack.PushBack({ 1400, 1582, 200, 157 });
	appleattack.PushBack({ 1600, 1582, 200, 157 });
	appleattack.PushBack({ 1800, 1582, 200, 157 });
	appleattack.PushBack({ 0, 1739, 200, 157 });
	appleattack.PushBack({ 200, 1739, 200, 157 });
	appleattack.PushBack({ 400, 1739, 200, 157 });
	appleattack.PushBack({ 600, 1739, 200, 157 });
	appleattack.PushBack({ 800, 1739, 200, 157 });
	appleattack.PushBack({ 1000, 1739, 200, 157 });
	appleattack.PushBack({ 1200, 1739, 200, 157 });
	appleattack.PushBack({ 1400, 1739, 200, 157 });
	appleattack.PushBack({ 1600, 1739, 200, 157 });
	appleattack.PushBack({ 1800, 1739, 200, 157 });
	appleattack.speed = 0.2f;

	//Animation hitted;
	hittedan.PushBack({ 1920, 0, 67, 137 });
	hittedan.PushBack({ 1987, 0, 75, 137 });
	hittedan.speed = 0.1f;

	//Punch jumping;
	punchair.PushBack({ 1168 , 137 , 76 , 137 });
	punchair.PushBack({ 1244 , 137 , 69 ,  137 });
	punchair.PushBack({ 1313 , 137 , 89 , 137 });
	punchair.PushBack({ 1402 , 137 , 143 , 137 });
	punchair.PushBack({ 1545 , 137 , 147 , 137 });
	punchair.PushBack({ 1692 , 137 , 149 ,  137 });
	punchair.PushBack({ 1313 , 137 , 89 , 137 });
	punchair.PushBack({ 1244 , 137 , 69 ,  137 });
	punchair.PushBack({ 1168 , 137 , 76 , 137 });
	punchair.speed = 0.25f;

	//Punch crouch;
	punchcrouch.PushBack({ 570 , 411 , 169 , 137 });
	punchcrouch.PushBack({ 739 , 411 , 169 , 137 });
	punchcrouch.PushBack({ 908 , 411 , 169 , 137 });
	punchcrouch.PushBack({ 1077 , 411 , 169 , 137 });
	punchcrouch.PushBack({ 1246 , 411 , 169 , 137 });
	punchcrouch.PushBack({ 1415 , 411 , 169 , 137 });
	punchcrouch.PushBack({ 1584 , 411 , 169 , 137 });
	punchcrouch.PushBack({ 1415 , 411 , 169 , 137 });
	punchcrouch.PushBack({ 1246 , 411 , 169 , 137 });
	punchcrouch.PushBack({ 1077 , 411 , 169 , 137 });
	punchcrouch.PushBack({ 908 , 411 , 169 , 137 });
	punchcrouch.PushBack({ 739 , 411 , 169 , 137 });
	punchcrouch.PushBack({ 570 , 411 , 169 , 137 });
	punchcrouch.speed = 0.3f;

	////////////Kick jumping;
	kickair.PushBack({ 511 , 137 , 61 , 137 });
	kickair.PushBack({ 572 , 137 , 83 , 137 });
	kickair.PushBack({ 655 , 137 , 111 , 137 });
	kickair.PushBack({ 766 , 137 , 96 , 137 });
	kickair.speed = 0.3f;

	///////////Kick crouch;
	kickcrouch.PushBack({ 1665, 334, 69, 80});
	kickcrouch.PushBack({ 1734, 334, 67, 80});
	kickcrouch.PushBack({ 1801, 334, 81, 80});
	kickcrouch.PushBack({ 1882, 334, 100,80});
	kickcrouch.PushBack({ 1982, 334, 68, 80});
	kickcrouch.speed = 0.3f;

}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player textures");
	bool ret = true;
	graphics = App->textures->Load("Sprites/UkyoPlayer1SpriteSheet.png");
	punchsound = App->audio->LoadChunk("Audio_FX/Punch.wav");
	kicksound = App->audio->LoadChunk("Audio_FX/Kick.wav");
	jumpsound = App->audio->LoadChunk("Audio_FX/Jump.wav");
	hittedsound = App->audio->LoadChunk("Audio_FX/Hitted.wav");
	tornadosound = App->audio->LoadChunk("Audio_FX/Tornado.wav");
	position.x = 50;
	position.y = 210;
	body = App->collision->AddCollider({ position.x,(position.y - 100),35,20 }, COLLIDER_PLAYER, this);
	body2 = App->collision->AddCollider({ position.x,(position.y - 50),25,15 }, COLLIDER_PLAYER, this);
	body3 = App->collision->AddCollider({ position.x,(position.y - 20),45,35 }, COLLIDER_PLAYER, this);

	actual = A_IDLE;
	for (int i = 0; i < 60; i++) inputstate[i] = S_NONE;
	for (int i = 0; i < 6; i++)inputstateout[i] = SO_NONE;
	jump_timer = 0;
	punch_timer = 0;
	kick_timer = 0;
	tornado_timer = 0;
	inputsouts = 0;
	victory = false;
	flip = false;
	stopleft = stopright = false;
	App->render->camera.x = App->render->camera.y = 0;
	return ret;
}

//Clean Up
bool ModulePlayer::CleanUp() {
	App->textures->Unload(graphics);
	App->textures->Unload(graphics2);
	App->audio->StopChunk();
	App->audio->UnLoadChunk(punchsound);
	App->audio->UnLoadChunk(kicksound);
	App->audio->UnLoadChunk(jumpsound);
	App->audio->UnLoadChunk(hittedsound);
	App->audio->UnLoadChunk(tornadosound);
	return true;
}

update_status ModulePlayer::PreUpdate() {
	stopright = false;
	stopleft = false;
	if (position.x > App->player2->position.x&&position.y == 210)flip = true;
	else if (position.x < App->player2->position.x&&position.y == 210)flip = false;
	for (int i = 59; i > 0; i--)inputstate[i] = inputstate[i - 1];
	inputstate[0] = S_NONE;
	for (int i = 0; i < INPUTSOUTS; i++) inputstateout[i] = SO_NONE;
	inputsouts = 0;
	Preupdate(jump_timer, punch_timer, kick_timer, tornado_timer, hitted_timer, inputsouts, position, flip, actual, inputstate, inputstateout, App->player);
	CheckSpecialAttacks(inputstate);
	return UPDATE_CONTINUE;
}


// Update: draw background
update_status ModulePlayer::Update()
{
	//Animation* current_animation = &idle;
	int speed = 2;
	CheckState(jump_timer, punch_timer, kick_timer, tornado_timer, inputsouts, actual, inputstate, inputstateout);


	////////////////////GODMODE/////////////////////////

	if (App->input->keyboardstate[SDL_SCANCODE_F5] == KEY_PUSHED) {
		if (body->to_delete != false) {
			body = App->collision->AddCollider({ position.x,(position.y - 100),35,20 }, COLLIDER_PLAYER, this);
			body2 = App->collision->AddCollider({ position.x,(position.y - 50),25,15 }, COLLIDER_PLAYER, this);
			body3 = App->collision->AddCollider({ position.x,(position.y - 20),45,35 }, COLLIDER_PLAYER, this);
		}
		else {
			body->to_delete = true;
			body2->to_delete = true;
			body3->to_delete = true;
		}

	}
	
		// Draw everything --------------------------------------
	SDL_Rect r = ExecuteState(jump_timer, punch_timer, kick_timer, tornado_timer, hitted_timer, actual, flip, speed, mult, stopright, stopleft, *body, *body2, *body3, &attack, position, App->player)->GetCurrentFrame();

	if (actual != A_TORNADO) {
		if (flip == false)	App->render->Blit(graphics, position.x, position.y - r.h, &r);
		else App->render->Blit(graphics, position.x, position.y - r.h, &r, 1.0F, true, true);
	}
	else App->render->Blit(graphics2, position.x, position.y - r.h, &r);
	return UPDATE_CONTINUE;
}




void ModulePlayer::OnCollision(Collider* player, Collider* other) {
	if (player->type == COLLIDER_PLAYER) {
		if (other->type == COLLIDER_ENEMY_SHOT) {
			actual = A_HITTED;
			if (hitted_timer == 0)hitted_timer = 1;
		}
		if (other->type == COLLIDER_WALL_LEFT) {
			stopleft = true;
		}
		if (other->type == COLLIDER_WALL_RIGHT) {
			stopright = true;
		}
		if (other->type == COLLIDER_ENEMY) {
				if (flip == false) {
				stopright = true;
			}
			else {
				stopleft = true;
			}
		}
	}
	else {
		if (other->type == COLLIDER_ENEMY) {
			player->to_delete = true;
		}
	}
}
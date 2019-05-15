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


	// Walk forward animation (To IMPROVE)
	forward.PushBack({ 185, 0, 75, 137 });
	forward.PushBack({ 260, 0, 72, 137 });
	forward.PushBack({ 332, 0, 81, 137 });
	forward.PushBack({ 413, 0, 87, 137 });
	forward.PushBack({ 500, 0, 81, 137 });
	forward.PushBack({ 581, 0, 72, 137 });
	forward.PushBack({ 653, 0, 75, 137 });
	forward.speed = 0.2f;

	// Walk backwards animation (To Do)
	//backward.PushBack({ 330, 2088, 86, 122 });
	backward.PushBack({ 653, 0, 75, 137 });
	backward.PushBack({ 581, 0, 72, 137 });
	backward.PushBack({ 500, 0, 81, 137 });
	backward.PushBack({ 413, 0, 87, 137 });
	backward.PushBack({ 332, 0, 81, 137 });
	backward.PushBack({ 260, 0, 72, 137 });
	backward.PushBack({ 185, 0, 75, 137 });
	backward.speed = 0.2f;



	// Kick animation(TO IMPROVE)
	kick.PushBack({ 1497, 159, 67, 100 });
	kick.PushBack({ 1569, 159, 83, 100 });
	kick.PushBack({ 1659, 159, 102, 100 });
	kick.PushBack({ 1764, 159, 113, 100 });
	kick.PushBack({ 1887, 159, 84, 100 });
	kick.PushBack({ 1975, 159, 67, 100 });
	kick.speed = 0.3f;



	//crouch
	//crouch.PushBack({ 654 , 1880 , 80 , 132 });
	crouch.PushBack({ 740 , 1926 , 100 , 86 });
	crouch.speed = 0.2f;


	// Punch animation (TO IMPROVE)
	punch.PushBack({ 1205, 2009, 77, 118 });
	punch.PushBack({ 1281, 1998, 72, 130 });
	punch.PushBack({ 1353,2005, 82, 122 });
	punch.PushBack({ 1353,2005, 82, 122 });
	punch.PushBack({ 1353,2005, 82, 122 });
	punch.PushBack({ 1448, 2019, 135, 109 });
	punch.PushBack({ 1570, 2027, 138, 103 });
	punch.PushBack({ 1708, 2026, 136, 100 });
	punch.PushBack({ 1317, 2159, 134, 107 });
	punch.PushBack({ 1317, 2159, 134, 107 });
	punch.PushBack({ 1457, 2165, 127, 103 });
	punch.PushBack({ 1583, 2160, 141, 97 });
	punch.PushBack({ 1721, 2137, 79, 120 });
	punch.speed = 0.4f;

	// Jump
	//jump.PushBack({ 1446, 16, 66, 122 });
	jump.PushBack({ 761, 0, 75, 137 });
	jump.PushBack({ 836, 0, 68, 137 });
	jump.PushBack({ 904, 0, 75, 137 });
	jump.PushBack({ 979, 0, 61, 137 });
	jump.PushBack({ 1040, 0, 66, 137 });
	jump.PushBack({ 1106, 0, 63, 137 });
	jump.PushBack({ 1169, 0, 61, 137 });
	jump.PushBack({ 1230, 0, 66, 137 });
	jump.PushBack({ 1296, 0, 61, 137 });
	jump.PushBack({ 1357, 0, 75, 137 });
	jump.speed = 0.1f;


	// Jump Forward
	jumpforward.PushBack({ 1788 , 23 , 71 , 113 });
	jumpforward.PushBack({ 1788 , 23 , 71 , 113 });
	jumpforward.PushBack({ 1680 , 36 , 92 , 95 });
	jumpforward.PushBack({ 2063 , 58 , 86 , 70 });
	jumpforward.PushBack({ 2167 , 71 , 84 , 68 });
	jumpforward.PushBack({ 2270 , 65 , 76 , 83 });
	jumpforward.PushBack({ 2388 , 68 , 86 , 64 });

	jumpforward.PushBack({ 1680 , 36 , 92 , 95 });
	jumpforward.speed = 0.1f;


	// Jump backwards
	jumpbackward.PushBack({ 1512 , 18 , 62 , 113 });
	jumpbackward.PushBack({ 1512 , 18 , 62 , 113 });
	jumpbackward.PushBack({ 1680 , 36 , 92 , 95 });
	jumpbackward.PushBack({ 2388 , 68 , 86 , 64 });
	jumpbackward.PushBack({ 2270 , 65 , 76 , 83 });
	jumpbackward.PushBack({ 2167 , 71 , 84 , 68 });
	jumpbackward.PushBack({ 2063 , 58 , 86 , 70 });
	jumpbackward.PushBack({ 1680 , 36 , 92 , 95 });


	jumpbackward.speed = 0.1f;

	//Tornado
	////////////Animation tornado;
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

	////////////Animation hitted;
	hittedan.PushBack({ 254, 30, 90, 102 });
	hittedan.PushBack({ 368, 30, 84, 102 });
	hittedan.speed = 0.1f;

	////////////Punch jumping;
	punchair.PushBack({ 1125 , 530 , 102 , 115 });
	punchair.PushBack({ 1272 , 530 , 69 ,  115 });
	punchair.PushBack({ 1374 , 530 , 102 , 115 });
	punchair.PushBack({ 1476 , 530 , 132 , 115 });
	punchair.PushBack({ 1611 , 530 , 126 , 115 });
	punchair.PushBack({ 1767 , 530 , 93 ,  115 });
	punchair.speed = 0.25f;

	////////////Punch crouch;
	punchcrouch.PushBack({ 1146 , 396 , 93 , 70 });
	punchcrouch.PushBack({ 1244 , 401 , 119 , 70 });
	punchcrouch.PushBack({ 1358 , 399 , 125 , 75 });
	punchcrouch.PushBack({ 1482 , 410 , 130 , 74 });
	punchcrouch.PushBack({ 1617 , 412 , 130 , 74 });
	punchcrouch.PushBack({ 1748 , 414 , 97 , 72 });
	punchcrouch.PushBack({ 1838 , 419 , 82 , 64 });
	punchcrouch.speed = 0.3f;

	////////////Kick jumping;
	kickair.PushBack({ 117 , 863 , 91 , 108 });
	kickair.PushBack({ 207 , 863 , 107 , 91 });
	kickair.PushBack({ 333 , 863 , 112 , 93 });
	kickair.speed = 0.25f;

	///////////Kick crouch;
	kickcrouch.PushBack({ 26 , 849, 72, 113 });
	kickcrouch.PushBack({ 128 ,849 , 81,  113 });
	kickcrouch.PushBack({ 211 ,849 , 102, 113 });
	kickcrouch.PushBack({ 341 ,849 , 100,  113 });
	kickcrouch.PushBack({ 482 ,849 , 80, 113 });
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
		if (other->type == COLLIDER_WALL) {
			if (position.x > 0) position.x = 670 - 23 * SCREEN_SIZE;
			else position.x = 0;
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
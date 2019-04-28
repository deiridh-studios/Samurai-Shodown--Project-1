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
#include "SDL/include/SDL_timer.h"


ModulePlayer::ModulePlayer()
{
	position.x = 50;
	position.y = 210;

	// Idle animation
	idle.PushBack({ 628, 560, 74, 116 });
	idle.PushBack({ 710, 558, 72, 118 });
	idle.PushBack({ 790, 558, 70, 118 });
	idle.PushBack({ 628, 680, 74, 118 });
	idle.PushBack({ 710, 680, 72, 118 });
	idle.PushBack({ 790, 680, 70, 118 });
	idle.speed = 0.2f;

	// Walk forward animation (To IMPROVE)
	forward.PushBack({ 898, 1530, 80, 120 });
	forward.PushBack({ 978, 1524, 74, 126 });
	forward.PushBack({ 1052, 1522, 60, 128 });
	forward.PushBack({ 1112, 1530, 76, 120 });
	

	forward.speed = 0.2f;
	
	// Walk backwards animation (To Do)
	//backward.PushBack({ 330, 2088, 86, 122 });
	backward.PushBack({ 436, 2088, 80, 122 });
	backward.PushBack({ 536, 2092, 84, 118 });
	backward.PushBack({ 650, 2078, 76, 122 });
	backward.PushBack({ 760, 2084, 62, 126 });
	backward.PushBack({ 842, 2092, 80, 118 });
	backward.speed = 0.2f;
	
	// Kick animation(TO IMPROVE)
	kick.PushBack({ 1497, 159, 67, 100});
	kick.PushBack({ 1569, 159, 83, 100});
	kick.PushBack({ 1659, 159, 102, 100});
	kick.PushBack({ 1764, 159, 113, 100});
	kick.PushBack({ 1887, 159, 84, 100});
	kick.PushBack({ 1975, 159, 67, 100});
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
	jump.PushBack({ 1510, 16, 66, 122 });
	jump.PushBack({ 1510, 16, 66, 122 });
	jump.PushBack({ 1590, 36, 84, 96 });
	jump.PushBack({ 1692, 36, 80, 96 });
	jump.PushBack({ 1794, 16, 68, 122 });
	jump.speed = 0.1f;


	// Jump Forward
	jumpforward.PushBack({ 1788 , 23 , 71 , 113});
	jumpforward.PushBack({ 1788 , 23 , 71 , 113 });
	jumpforward.PushBack({ 1680 , 36 , 92 , 95 });
	jumpforward.PushBack({2063 , 58 , 86 , 70  });
	jumpforward.PushBack({2167 , 71 , 84 , 68  });
	jumpforward.PushBack({2270 , 65 , 76 , 83  });
	jumpforward.PushBack({2388 , 68 , 86 , 64  });

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
	tornado.PushBack({ 158, 2384, 72, 96});
	tornado.PushBack({ 298, 2384, 80, 96});
	tornado.PushBack({ 454, 2384, 66, 96});
	tornado.PushBack({ 586, 2376, 100, 104});
	tornado.PushBack({ 746, 2350, 60, 132});
	tornado.PushBack({ 851, 2376, 103,  104});
	tornado.PushBack({ 994, 2380, 104, 100});
	tornado.PushBack({ 1132, 2380, 102, 100});
	tornado.PushBack({ 1288, 2380, 102, 100});
	tornado.PushBack({ 1432, 2380, 104, 100});
	tornado.PushBack({ 1576, 2380, 104, 100});
	tornado.PushBack({ 1706, 2380, 110, 100});
	tornado.PushBack({ 1848, 2380, 106, 100});
	tornado.PushBack({ 0, 2526, 90, 96});
	tornado.PushBack({ 154, 2498, 90, 126});
	tornado.PushBack({ 300, 2514, 90, 110});
	tornado.speed = 0.2f;

	////////////Animation hitted;
	hittedan.PushBack({ 254, 30, 90, 102 });
	hittedan.PushBack({ 368, 30, 84, 102 });
	hittedan.speed = 0.1f;

	////////////Punch jumping;
	punchair.PushBack({1125 , 530 , 102 , 115});
	punchair.PushBack({1272 , 530 , 69 ,  115});
	punchair.PushBack({1374 , 530 , 102 , 115});
	punchair.PushBack({1476 , 530 , 132 , 115});
	punchair.PushBack({1611 , 530 , 126 , 115});
	punchair.PushBack({1767 , 530 , 93 ,  115});
	punchair.speed = 0.25f;

	////////////Punch crouch;
	punchcrouch.PushBack({1146 , 396 , 93 , 70});
	punchcrouch.PushBack({1244 , 401 , 119 , 70});
	punchcrouch.PushBack({1358 , 399 , 125 , 75});
	punchcrouch.PushBack({1482 , 410 , 130 , 74});
	punchcrouch.PushBack({1617 , 412 , 130 , 74});
	punchcrouch.PushBack({1748 , 414 , 97 , 72});
	punchcrouch.PushBack({1838 , 419 , 82 , 64});
	punchcrouch.speed = 0.3f;

	////////////Kick jumping;
	kickair.PushBack({117 , 863 , 91 , 108});
	kickair.PushBack({207 , 863 , 107 , 91});
	kickair.PushBack({333 , 863 , 112 , 93});
	kickair.speed = 0.25f;

	///////////Kick crouch;
	kickcrouch.PushBack({ 26 , 849, 72, 113});
	kickcrouch.PushBack({ 128 ,849 , 81,  113});
	kickcrouch.PushBack({ 211 ,849 , 102, 113});
	kickcrouch.PushBack({ 341 ,849 , 100,  113});
	kickcrouch.PushBack({ 482 ,849 , 80, 113});
	kickcrouch.speed = 0.3f;

	
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player textures");
	bool ret = true;
	graphics = App->textures->Load("Sprites/spritesHaohmaruFIXED.png"); // arcade version
	graphics2 = App->textures->Load("sprites/spritesHaohmaruFIXED.png");
	punchsound = App->audio->LoadChunk("Audio_FX/Punch.wav");
	kicksound = App->audio->LoadChunk("Audio_FX/Kick.wav");
	jumpsound = App->audio->LoadChunk("Audio_FX/Jump.wav");
	hittedsound = App->audio->LoadChunk("Audio_FX/Hitted.wav");
	tornadosound = App->audio->LoadChunk("Audio_FX/Tornado.wav");
	position.x = 50;
	position.y = 210;
	body = App->collision->AddCollider({ position.x,(position.y-100),35,20 }, COLLIDER_PLAYER, this);
	body2 = App->collision->AddCollider({ position.x,(position.y - 50),25,15 }, COLLIDER_PLAYER, this);
	body3 = App->collision->AddCollider({ position.x,(position.y - 20),45,35 }, COLLIDER_PLAYER, this);
	
	//actual = A_IDLE;
	actual = A_IDLE;
	//actual = NONE;
	//right = false;
	//left = false;
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
	if (actual != A_HITTED) {
		//CHECK LEFT AND RIGHT//
		bool left = false;
		bool right = false;
		if (App->input->keyboardstate[SDL_SCANCODE_D] == KEY_PUSHED || App->input->keyboardstate[SDL_SCANCODE_D] == KEY_REPEAT) {
			if (flip == true) left = true;
			else right = true;
		}
		if (App->input->keyboardstate[SDL_SCANCODE_A] == KEY_PUSHED || App->input->keyboardstate[SDL_SCANCODE_A] == KEY_REPEAT) {
			if (flip == true) right = true;
			else left = true;
		}
		if (right == true && left == true)inputstate[0] = S_LEFT_AND_RIGHT;
		else if (right == true)inputstate[0] = S_RIGHT_DOWN;//App->input->keyboardstate[SDL_SCANCODE_D] == KEY_PUSHED) {inputstate[0] = S_RIGHT_DOWN; LOG("RIGHT_DOWN\n");}
		else if (App->input->keyboardstate[SDL_SCANCODE_D] == KEY_PULLED) {
			if(flip==true)inputstateout[inputsouts] = SO_LEFT_UP;
			else inputstateout[inputsouts] = SO_RIGHT_UP;
			if (inputstate[0] == S_RIGHT_DOWN&&flip==false)inputstate[0] = S_NONE;
			else if(inputstate[0] == S_LEFT_DOWN && flip == true)inputstate[0] = S_NONE;
			inputsouts++;
		}
		else if (left == true)/*(App->input->keyboardstate[SDL_SCANCODE_A] == KEY_PUSHED)*/ inputstate[0] = S_LEFT_DOWN;
		else if (App->input->keyboardstate[SDL_SCANCODE_A] == KEY_PULLED) {
			if (flip == true)inputstateout[inputsouts] = SO_RIGHT_UP;
			else inputstateout[inputsouts] = SO_LEFT_UP;
			if (inputstate[0] == S_LEFT_DOWN&&flip==false)inputstate[0] = S_NONE;
			else if (inputstate[0] == S_RIGHT_DOWN && flip == true)inputstate[0] = S_NONE;
			inputsouts++;
		}

		//CHECK JUMP AND JUMP WITH DIRECTION//
		bool jump = false;
		if (App->input->keyboardstate[SDL_SCANCODE_W] == KEY_PUSHED || App->input->keyboardstate[SDL_SCANCODE_W] == KEY_REPEAT)jump = true;
		if (jump == true) {
			if (inputstate[0] == S_RIGHT_DOWN)inputstate[0] = S_JUMP_RIGHT;
			else if (inputstate[0] == S_LEFT_DOWN)inputstate[0] = S_JUMP_LEFT;
			else inputstate[0] = S_JUMP;
		}

		//CHECK CROUCH AND CROUCH WITH DIRECTION//
		bool crouch = false;
		if (App->input->keyboardstate[SDL_SCANCODE_S] == KEY_PUSHED || App->input->keyboardstate[SDL_SCANCODE_S] == KEY_REPEAT)crouch = true;
		if (crouch == true) {
			if (inputstate[0] == S_JUMP) inputstate[0] = S_JUMP_AND_CROUCH;
			else if (inputstate[0] == S_RIGHT_DOWN) { inputstate[0] = S_CROUCH_RIGHT; LOG("CROUCH_RIGHT"); }
			//CROUCH LEFT
			else inputstate[0] = S_CROUCH_DOWN;
		}
		else if (App->input->keyboardstate[SDL_SCANCODE_S] == KEY_PULLED) {
			inputstateout[inputsouts] = SO_CROUCH_UP;
			if (inputstate[0] == S_CROUCH_DOWN)inputstate[0] = S_NONE;
			inputsouts++;
		}

		//CHECK PUNCH AND VARIATIONS OF IT//
		bool punch = false;
		if (App->input->keyboardstate[SDL_SCANCODE_T] == KEY_PUSHED || App->input->keyboardstate[SDL_SCANCODE_T] == KEY_REPEAT) punch = true;
		if (punch == true) {
			if (inputstate[0] == S_RIGHT_DOWN)inputstate[0] = S_T_RIGHT;
			else if (inputstate[0] == S_LEFT_DOWN)inputstate[0] = S_T_LEFT;
			else if (inputstate[0] == S_JUMP) inputstate[0] = S_T_JUMP;
			else if (inputstate[0] == S_LEFT_AND_RIGHT) inputstate[0] = S_T;
			else if (inputstate[0] == S_JUMP_AND_CROUCH) inputstate[0] = S_T;
			else if (inputstate[0] == S_JUMP_LEFT) inputstate[0] = S_T_JUMP_LEFT;
			else if (inputstate[0] == S_JUMP_RIGHT) inputstate[0] = S_T_JUMP_RIGHT;
			else if (inputstate[0] == S_CROUCH_DOWN) inputstate[0] = S_T_CROUCH;
			else if (inputstate[0] == S_CROUCH_RIGHT) inputstate[0] = S_T_CROUCH_RIGHT;
			else if (inputstate[0] == S_NONE)inputstate[0] = S_T;
		}

		//CHECK KICK AND VARIATIONS OF IT//
		bool kick = false;
		if (App->input->keyboardstate[SDL_SCANCODE_Y] == KEY_PUSHED || App->input->keyboardstate[SDL_SCANCODE_Y] == KEY_REPEAT) kick = true;
		if (kick == true) {
			if (inputstate[0] == S_RIGHT_DOWN)inputstate[0] = S_Y_RIGHT;
			else if (inputstate[0] == S_LEFT_DOWN)inputstate[0] = S_Y_LEFT;
			else if (inputstate[0] == S_JUMP) inputstate[0] = S_Y_JUMP;
			else if (inputstate[0] == S_LEFT_AND_RIGHT) inputstate[0] = S_Y;
			else if (inputstate[0] == S_JUMP_AND_CROUCH) inputstate[0] = S_Y;
			else if (inputstate[0] == S_JUMP_LEFT) inputstate[0] = S_Y_JUMP_LEFT;
			else if (inputstate[0] == S_JUMP_RIGHT) inputstate[0] = S_Y_JUMP_RIGHT;
			else if (inputstate[0] == S_CROUCH_DOWN) inputstate[0] = S_Y_CROUCH;
			else if (inputstate[0] == S_CROUCH_RIGHT) inputstate[0] = S_Y_CROUCH_RIGHT;
			else if (inputstate[0] == S_NONE)inputstate[0] = S_Y;
			//else inputstate[0] = S_NONE;
		}

	}
	//CHECK TIMERS//
	if (jump_timer > 0) {
		//if (SDL_GetTicks() - jump_timer > JUMP_TIME){
		if (position.y == 210) {
			inputstateout[inputsouts] = SO_JUMP_FINISH;
			//if (inputstate[0] == S_JUMP)inputstate[0] = S_NONE;
			//else if (inputstate[0] == S_JUMP_LEFT)inputstate[0] = S_NONE;
			//else if (inputstate[0] == S_JUMP_RIGHT)inputstate[0] = S_NONE;
			inputsouts++;
			jump_timer = 0;
		}
	}
	if (punch_timer == 3) {
		inputstateout[inputsouts] = SO_PUNCH_FINISH;
		//if (inputstate[0] == S_T)inputstate[0] = S_NONE;
		//else if (inputstate[0] == S_T_LEFT)inputstate[0] = S_NONE;
		//else if (inputstate[0] == S_T_RIGHT)inputstate[0] = S_NONE;
		inputsouts++;
		punch_timer = 0;
	}
	if (kick_timer == 3) {
		inputstateout[inputsouts] = SO_KICK_FINISH;
		//if (inputstate[0] == S_Y)inputstate[0] = S_NONE;
		inputsouts++;
		kick_timer = 0;
	}
	if (tornado_timer == 3) {
		inputstateout[inputsouts] = SO_TORNADO_FINISH;
		//if (inputstate[0] == S_TORNADO)inputstate[0] = S_NONE;
		inputsouts++;
		tornado_timer = 0;
	}
	if (hitted_timer == 3) {
		inputstateout[inputsouts] = SO_HITTED_FINISH;
		inputsouts++;
		hitted_timer = 0;
	}
	/*if (punch_timer > 0) {
		if (SDL_GetTicks() - punch_timer > PUNCH_TIME) {
			inputstate[0] = S_PUNCH_FINISH;
			punch_timer = 0;
		}
	}
	if (kick_timer > 0) {
		if (SDL_GetTicks() - kick_timer > KICK_TIME) {
			inputstate[0] = S_KICK_FINISH;
			kick_timer = 0;
		}
	}*/
	CheckSpecialAttacks();
	return UPDATE_CONTINUE;
}


// Update: draw background
update_status ModulePlayer:: Update()
{
	Animation* current_animation = &idle;
	int speed = 2;
	CheckState();
	
	switch (actual) {
	case A_IDLE:
		current_animation = &idle;
		if (flip == false) {
			body->SetPos(position.x + 18, (position.y - 80));
			body2->SetPos(position.x + 20, (position.y - 57));
			body3->SetPos(position.x + 10, (position.y - 40));
		}
		else {
			body->SetPos(position.x +18, (position.y - 80));
			body2->SetPos(position.x+26, (position.y - 57));
			body3->SetPos(position.x +16, (position.y - 40));
		}

		break;
	case A_WALK_FORWARD:
		current_animation = &forward;
		if (flip == false) {
			body->SetPos(position.x + 18, (position.y - 80));
			body2->SetPos(position.x + 20, (position.y - 57));
			body3->SetPos(position.x + 10, (position.y - 40));
		}
		else {
			body->SetPos(position.x + 18, (position.y - 80));
			body2->SetPos(position.x + 26, (position.y - 57));
			body3->SetPos(position.x + 16, (position.y - 40));
		}

		if (flip == false) {
			/*if ((position.x + 23 * SCREEN_SIZE) < (App->player2->position.x)) position.x += speed;
			else if(position.y>App->player2->position.y) position.x += speed;*/
			if(stopright==false)position.x += speed;
			if ((App->background->cameraleft.x < position.x) && (App->background->cameraright.x < 670))App->render->camera.x -= speed;// *1.25;
		}
		else {
			/*if ((position.x) > (App->player2->position.x + 23 * SCREEN_SIZE)) position.x -= speed;
			else if (position.y > App->player2->position.y) position.x -= speed;*/
			if (stopleft == false)position.x -= speed;
			if ((App->background->cameraright.x > position.x + 70) && App->background->cameraleft.x > 0)App->render->camera.x += speed;// *1.25;
		}
		break;
	case A_WALK_BACKWARD:
		current_animation = &backward;
		if (flip == false) {
			body->SetPos(position.x + 18, (position.y - 80));
			body2->SetPos(position.x + 20, (position.y - 57));
			body3->SetPos(position.x + 10, (position.y - 40));
		}
		else {
			body->SetPos(position.x + 18, (position.y - 80));
			body2->SetPos(position.x + 26, (position.y - 57));
			body3->SetPos(position.x + 16, (position.y - 40));
		}

		if (flip == false) {
			//if (position.x > App->background->cameraleft.x) position.x -= speed / 2;
			//else if (position.y > App->player2->position.y) position.x -= speed/2;
			if (stopleft == false)position.x -= speed/2;
			if ((App->background->cameraleft.x > 0) && (App->background->cameraright.x > (App->player2->position.x + (23 * SCREEN_SIZE)))) App->render->camera.x += speed;// *1.25;
		}
		else {
			//if (position.x + 23 * SCREEN_SIZE < App->background->cameraright.x - 1) position.x += speed / 2;
			//else if (position.y > App->player2->position.y) position.x += speed/2;
			if (stopright == false)position.x += speed/2;
			if ((App->background->cameraleft.x < App->player2->position.x) && (App->background->cameraright.x < 670)) App->render->camera.x -= speed;// *1.25;
		}
		break;
	case A_JUMP_NEUTRAL:
		current_animation = &jump;
		if (flip == false) {
			body->SetPos(position.x + 10, (position.y - 90));
			body2->SetPos(position.x + 12, (position.y - 69));
			body3->SetPos(position.x + 5, (position.y - 55));
		}
		else {
			body->SetPos(position.x + 35, (position.y - 90));
			body2->SetPos(position.x + 42, (position.y - 69));
			body3->SetPos(position.x + 30, (position.y - 55));
		}

		if (position.y == 210) {
			App->audio->PlayChunk(jumpsound);
			mult = 2;
		}
		if (position.y <= 80) {
			mult = -2;
		}
		position.y -= speed * mult;
		break;
	case A_JUMP_FORWARD:
		current_animation = &jumpforward;
		if (flip == false) {
			body->SetPos(position.x + 10, (position.y - 90));
			body2->SetPos(position.x + 12, (position.y - 69));
			body3->SetPos(position.x + 5, (position.y - 55));
		}
		else {
			body->SetPos(position.x + 35, (position.y - 90));
			body2->SetPos(position.x + 42, (position.y - 69));
			body3->SetPos(position.x + 30, (position.y - 55));
		}

		if (position.y == 210) {
			App->audio->PlayChunk(jumpsound);
			mult = 2;
		}
		if (position.y <= 80) mult = -2;
		position.y -= speed * mult;
		if (flip == false) {
			//if ((position.x + 23 * SCREEN_SIZE) < (App->player2->position.x)) position.x += speed / 2;
			//else if (position.y < App->player2->position.y)position.x += speed / 2;
			if (stopright == false)position.x += speed/2;
			if ((App->background->cameraleft.x < position.x) && (App->background->cameraright.x < 670))App->render->camera.x -= speed;// *1.25;
		}
		else {
			//if ((position.x) > (App->player2->position.x + 23 * SCREEN_SIZE)) position.x -= speed / 2;
		//	else if (position.y < App->player2->position.y)position.x -= speed / 2;
			if (stopleft == false)position.x -= speed/2;
			if ((App->background->cameraright.x > position.x + 70) && App->background->cameraleft.x > 0)App->render->camera.x += speed;// *1.25;
		}
		break;
	case A_JUMP_BACKWARD:
		current_animation = &jumpbackward;
		if (flip == false) {
			body->SetPos(position.x + 10, (position.y - 90));
			body2->SetPos(position.x + 12, (position.y - 69));
			body3->SetPos(position.x + 5, (position.y - 55));
		}
		else {

			body->SetPos(position.x + 35, (position.y - 90));
			body2->SetPos(position.x + 42, (position.y - 69));
			body3->SetPos(position.x + 30, (position.y - 55));
		}

		if (position.y == 210) {
			App->audio->PlayChunk(jumpsound);
			mult = 2;
		}
		if (position.y <= 80) mult = -2;
		position.y -= speed * mult;
		if (flip == false) {
			//if (position.x > App->background->cameraleft.x) position.x -= speed / 2;
			//else if (position.y < App->player2->position.y)position.x -= speed/2;
			if (stopleft == false)position.x -= speed/2;
			if ((App->background->cameraleft.x > 0) && (App->background->cameraright.x > (App->player2->position.x + (23 * SCREEN_SIZE)))) App->render->camera.x += speed;// *1.25;
		}
		else {
			//if (position.x + 23 * SCREEN_SIZE < App->background->cameraright.x - 1) position.x += speed / 2;
			//else if (position.y < App->player2->position.y)position.x += speed/2;
			if (stopright == false)position.x += speed/2;
			if ((App->background->cameraleft.x < App->player2->position.x) && (App->background->cameraright.x < 670)) App->render->camera.x -= speed;// *1.25;
		}
		break;
	case A_CROUCH:
		current_animation = &crouch;
		if (flip == false) {
			body->SetPos(position.x + 50, (position.y - 70));
			body2->SetPos(position.x + 67, (position.y - 54));
			body3->SetPos(position.x + 47, (position.y - 40));
		}
		else {
			body->SetPos(position.x+15, (position.y - 70));
			body2->SetPos(position.x+8, (position.y - 54));
			body3->SetPos(position.x+8, (position.y - 40));
		}
		break;
	case A_PUNCH_STANDING:
		/*if (tornadoactivate == true) {
			current_animation = &tornado;
			if (punch_timer == 1) {
				App->particles->AddParticle(App->particles->tornado, position.x, position.y - 100, COLLIDER_PLAYER_SHOT, 0);
				App->audio->PlayChunk(tornadosound);
				punch_timer = 2;
			}
			if (current_animation->GetFinished() == 1)tornadoactivate = false; punch_timer = 3;
		}
		else {*/
		current_animation = &punch;
		if (punch_timer == 1) {
			App->audio->PlayChunk(punchsound);
			punch_timer = 2;
			if (flip == false) {
				attack = App->collision->AddCollider({ position.x + 60,(position.y - 75),75,50 }, COLLIDER_PLAYER_SHOT, this);
			}
			else {
				attack = App->collision->AddCollider({ position.x +1,(position.y - 75),75,50 }, COLLIDER_PLAYER_SHOT, this);
			}
		}
		if (current_animation->GetFinished() == 1) {
			punch_timer = 3;
			attack->to_delete = true;
		}
		break;
	case A_PUNCH_NEUTRAL_JUMP:

		current_animation = &punchair;
		if (flip == false) {  
			body->SetPos(position.x + 50, (position.y - 120));
			body2->SetPos(position.x + 52, (position.y - 99));
			body3->SetPos(position.x + 45, (position.y - 85));
		}
		else {
			body->SetPos(position.x + 50, (position.y - 120));
			body2->SetPos(position.x + 52, (position.y - 99));
			body3->SetPos(position.x + 45, (position.y - 85));
		}

		if (position.y == 210) {
			App->audio->PlayChunk(jumpsound);
			mult = 2;
		}
		if (position.y <= 80) {
			mult = -2;
		}
		position.y -= speed * mult;
		
		if (punch_timer == 1) {
			App->audio->PlayChunk(punchsound);
			position.x = position.x - 40;
			punch_timer = 2;

			if (flip == false) {
				attack = App->collision->AddCollider({ position.x + 50,(position.y - 110),75,40 }, COLLIDER_PLAYER_SHOT, this);
			}
			else {
				attack = App->collision->AddCollider({ position.x + 5,(position.y - 110),75,40 }, COLLIDER_PLAYER_SHOT, this);
			}
		}
		if (current_animation->GetFinished() == 1) {
			punch_timer = 3;
			position.x = position.x + 40;
			attack->to_delete = true;
		}
		break;
	case A_PUNCH_FORWARD_JUMP:
		current_animation = &punchair;
		if (flip == false) {
			body->SetPos(position.x + 50, (position.y - 120));
			body2->SetPos(position.x + 52, (position.y - 99));
			body3->SetPos(position.x + 45, (position.y - 85));
		}
		else {
			body->SetPos(position.x, (position.y - 120));
			body2->SetPos(position.x, (position.y - 99));
			body3->SetPos(position.x, (position.y - 85));
		}

		if (position.y == 210) {
			App->audio->PlayChunk(jumpsound);
			mult = 2;
		}
		if (position.y <= 80) mult = -2;
		position.y -= speed * mult;
		if (flip == false) {
			//if ((position.x + 23 * SCREEN_SIZE) < (App->player2->position.x)) position.x += speed / 2;
			//else if (position.y < App->player2->position.y)position.x += speed / 2;
			if (stopright == false)position.x += speed/2;
			if ((App->background->cameraleft.x < position.x) && (App->background->cameraright.x < 670))App->render->camera.x -= speed;// *1.25;
		}
		else {
			//if ((position.x) > (App->player2->position.x + 23 * SCREEN_SIZE)) position.x -= speed / 2;
			//else if (position.y < App->player2->position.y)position.x -= speed / 2;
			if (stopleft == false)position.x -= speed/2;
			if ((App->background->cameraright.x > position.x + 70) && App->background->cameraleft.x > 0)App->render->camera.x += speed;// *1.25;
		}
		if (punch_timer == 1) {
			punch_timer = 2;
			App->audio->PlayChunk(punchsound);
			if (flip == false) {
				attack = App->collision->AddCollider({ position.x + 70,(position.y - 110),75,40 }, COLLIDER_PLAYER_SHOT, this);
			}
			else {
				attack = App->collision->AddCollider({ position.x + 1,(position.y - 110),75,40 }, COLLIDER_PLAYER_SHOT, this);
			}
			
		}
		if (current_animation->GetFinished() == 1) {
			attack->to_delete = true;
			punch_timer = 3;
		}
		break;
	case A_PUNCH_BACKWARD_JUMP:
		current_animation = &punchair;
		if (flip == false) {
			body->SetPos(position.x + 50, (position.y - 120));
			body2->SetPos(position.x + 52, (position.y - 99));
			body3->SetPos(position.x + 45, (position.y - 85));
		}
		else {
			body->SetPos(position.x + 50, (position.y - 120));
			body2->SetPos(position.x + 52, (position.y - 99));
			body3->SetPos(position.x + 45, (position.y - 85));
		}

		if (position.y == 210) {
			App->audio->PlayChunk(jumpsound);
			mult = 2;
		}
		if (position.y <= 80) mult = -2;
		position.y -= speed * mult;
		if (flip == false) {
			//if (position.x > App->background->cameraleft.x) position.x -= speed / 2;
			//else if (position.y < App->player2->position.y)position.x -= speed/2;
			if (stopleft == false)position.x -= speed/2;
			if ((App->background->cameraleft.x > 0) && (App->background->cameraright.x > (App->player2->position.x + (23 * SCREEN_SIZE)))) App->render->camera.x += speed;// *1.25;
		}
		else {
			//if (position.x + 23 * SCREEN_SIZE < App->background->cameraright.x - 1) position.x += speed / 2;
			//else if (position.y < App->player2->position.y)position.x += speed/2;
			if (stopright == false)position.x += speed/2;
			if ((App->background->cameraleft.x < App->player2->position.x) && (App->background->cameraright.x < 670)) App->render->camera.x -= speed;// *1.25;
		}
		if (punch_timer == 1) {
			App->audio->PlayChunk(punchsound);
			attack = App->collision->AddCollider({ position.x + 40,(position.y - 110),75,40 }, COLLIDER_PLAYER_SHOT, this);
			punch_timer = 2;
		}
		if (current_animation->GetFinished() == 1) {
			attack->to_delete = true;
			punch_timer = 3;
		}
		break;
	case A_PUNCH_CROUCH:
		current_animation = &punchcrouch;
		if (flip == false) {
			body->SetPos(position.x + 35, (position.y - 65));
			body2->SetPos(position.x + 52, (position.y - 50));
			body3->SetPos(position.x + 32, (position.y - 35));
		}
		else {
			body->SetPos(position.x + 50, (position.y - 65));
			body2->SetPos(position.x + 67, (position.y - 50));
			body3->SetPos(position.x + 47, (position.y - 35));
		}

		if (punch_timer == 1) {
			App->audio->PlayChunk(punchsound);
			punch_timer = 2;
			if (flip == false) {
				attack = App->collision->AddCollider({ position.x + 50,(position.y - 30),75,30 }, COLLIDER_PLAYER_SHOT, this);
			}
			else {
				attack = App->collision->AddCollider({ position.x + 1,(position.y - 30),75,30 }, COLLIDER_PLAYER_SHOT, this);
			}
		}
		if (current_animation->GetFinished() == 1) {
			punch_timer = 3;
			attack->to_delete = true;
		}
		break;
	case A_KICK_STANDING:
		current_animation = &kick;
		if (flip == false) {
			body->SetPos(position.x + 18, (position.y - 80));
			body2->SetPos(position.x + 20, (position.y - 57));
			body3->SetPos(position.x + 20, (position.y - 40));
		}
		else {
			body->SetPos(position.x + 18, (position.y - 80));
			body2->SetPos(position.x + 20, (position.y - 57));
			body3->SetPos(position.x + 20, (position.y - 40));
		}

		if (kick_timer == 1) {
			App->audio->PlayChunk(kicksound);
			kick_timer = 2;
			if(flip == false){
				attack = App->collision->AddCollider({ position.x + 40,(position.y - 90),65,20 }, COLLIDER_PLAYER_SHOT, this);
			
		}
			else {
				attack = App->collision->AddCollider({ position.x + 1,(position.y - 90),65,20 }, COLLIDER_PLAYER_SHOT, this);
			}
	

		}
		if (current_animation->GetFinished() == 1) {
			kick_timer = 3;
			attack->to_delete = true;
			
		}
		break;
	case A_KICK_NEUTRAL_JUMP:
		current_animation = &kickair;
		if (flip == false) {
			body->SetPos(position.x + 10, (position.y - 60));
			body2->SetPos(position.x + 12, (position.y - 49));
			body3->SetPos(position.x + 15, (position.y - 35));
		}
		else {
			body->SetPos(position.x + 35, (position.y - 60));
			body2->SetPos(position.x + 42, (position.y - 49));
			body3->SetPos(position.x + 45, (position.y - 35));
		}
		if (position.y == 210) {
			App->audio->PlayChunk(jumpsound);
			mult = 2;
		}
		if (position.y <= 80) {
			mult = -2;
		}
		position.y -= speed * mult;
		if (kick_timer == 1) {
			App->audio->PlayChunk(kicksound);
			kick_timer = 2;
			if (flip == false) {
				attack = App->collision->AddCollider({ position.x + 40,(position.y - 30),65,20 }, COLLIDER_PLAYER_SHOT, this);
			}
			else {
				attack = App->collision->AddCollider({ position.x + 4,(position.y - 30),65,20 }, COLLIDER_PLAYER_SHOT, this);
			}
		}
		if (current_animation->GetFinished() == 1) {
			kick_timer = 3;
			attack->to_delete = true;
		}
		break;
	case A_KICK_FORWARD_JUMP:
		current_animation = &kickair;
		if (flip == false) {
			body->SetPos(position.x + 10, (position.y - 60));
			body2->SetPos(position.x + 12, (position.y - 49));
			body3->SetPos(position.x + 15, (position.y - 35));
		}
		else {
			body->SetPos(position.x + 35, (position.y - 60));
			body2->SetPos(position.x + 42, (position.y - 49));
			body3->SetPos(position.x + 45, (position.y - 35));
		}

		if (position.y == 210) {
			App->audio->PlayChunk(jumpsound);
			mult = 2;
		}
		if (position.y <= 80) mult = -2;
		position.y -= speed * mult;
		if (flip == false) {
			if ((position.x + 23 * SCREEN_SIZE) < (App->player2->position.x)) position.x += speed / 2;
			else if (position.y < App->player2->position.y)position.x += speed / 2;
			if ((App->background->cameraleft.x < position.x) && (App->background->cameraright.x < 670))App->render->camera.x -= speed;// *1.25;
		}
		else {
			if ((position.x) > (App->player2->position.x + 23 * SCREEN_SIZE)) position.x -= speed/2;
			else if (position.y < App->player2->position.y)position.x -= speed / 2;
			if ((App->background->cameraright.x > position.x + 70) && App->background->cameraleft.x > 0)App->render->camera.x += speed;// *1.25;
		}
		if (kick_timer == 1) {
			App->audio->PlayChunk(kicksound);
			kick_timer = 2;
			if (flip == false) {
				attack = App->collision->AddCollider({ position.x + 50,(position.y - 30),65,20 }, COLLIDER_PLAYER_SHOT, this);
			}
			else {
				attack = App->collision->AddCollider({ position.x + 1,(position.y - 30),65,20 }, COLLIDER_PLAYER_SHOT, this);
			}
		}
		if (current_animation->GetFinished() == 1) {
			kick_timer = 3;
			attack->to_delete = true;
		}
		break;
	case A_KICK_BACKWARD_JUMP:
		current_animation = &kickair;
		if (flip == false) {
			body->SetPos(position.x + 10, (position.y - 60));
			body2->SetPos(position.x + 12, (position.y - 49));
			body3->SetPos(position.x + 15, (position.y - 35));
		}
		else {
			body->SetPos(position.x +35, (position.y - 60));
			body2->SetPos(position.x + 42, (position.y - 49));
			body3->SetPos(position.x + 45, (position.y - 35));
		}

		if (position.y == 210) {
			App->audio->PlayChunk(jumpsound);
			mult = 2;
		}
		if (position.y <= 80) mult = -2;
		position.y -= speed * mult;
		if (flip == false) {
			if (position.x > App->background->cameraleft.x) position.x -= speed / 2;
			else if (position.y < App->player2->position.y)position.x -= speed/2;
			if ((App->background->cameraleft.x > 0) && (App->background->cameraright.x > (App->player2->position.x + (23 * SCREEN_SIZE)))) App->render->camera.x += speed;// *1.25;
		}
		else {
			if (position.x + 23 * SCREEN_SIZE < App->background->cameraright.x - 1) position.x += speed / 2;
			else if (position.y < App->player2->position.y)position.x += speed/2;
			if ((App->background->cameraleft.x < App->player2->position.x) && (App->background->cameraright.x < 670)) App->render->camera.x -= speed;// *1.25;
		}
		if (kick_timer == 1) {
			App->audio->PlayChunk(kicksound);
			kick_timer = 2;
			if (flip == false) {
				attack = App->collision->AddCollider({ position.x + 30,(position.y - 30),65,20 }, COLLIDER_PLAYER_SHOT, this);
			}
			else {
				attack = App->collision->AddCollider({ position.x + 3,(position.y - 30),65,20 }, COLLIDER_PLAYER_SHOT, this);

			}
		}
		if (current_animation->GetFinished() == 1) {
			kick_timer = 3;
			attack->to_delete = true;
		}
		break;
	case A_KICK_CROUCH:
		current_animation = &kickcrouch;
		if (flip == false) {
			body->SetPos(position.x + 15, (position.y - 65));
			body2->SetPos(position.x + 25, (position.y - 50));
			body3->SetPos(position.x + 12, (position.y - 35));
		}
		else {
			body->SetPos(position.x + 50, (position.y - 65));
			body2->SetPos(position.x + 67, (position.y - 50));
			body3->SetPos(position.x + 47, (position.y - 35));
		}

		if (kick_timer == 1) {
			App->audio->PlayChunk(kicksound);
			kick_timer = 2;
			if (flip == false) {
				attack = App->collision->AddCollider({ position.x + 25,(position.y - 30),75,30 }, COLLIDER_PLAYER_SHOT, this);
			}
			else {
				attack = App->collision->AddCollider({ position.x + 1,(position.y - 30),75,30 }, COLLIDER_PLAYER_SHOT, this);
			}
		}
		if (current_animation->GetFinished() == 1) {
			kick_timer = 3;
			attack->to_delete = true;
		}
		break;
	case A_HITTED:
		current_animation = &hittedan;
		if (hitted_timer == 1 && position.y == 210) {
			App->audio->PlayChunk(hittedsound);
			App->UI->DamageTaken(1, 5);
			hitted_timer = 2;
		}
		if (flip == false)position.x -= 1;
		else position.x += 1;
		if (position.y == 130) {
			mult = -1;
		}
		if(position.y<210)position.y -= speed * mult;
		if (current_animation->GetFinished() == 1 && hitted_timer == 2)hitted_timer = 3;
		break;
	case A_TORNADO:
		current_animation = &tornado;
		if (tornado_timer == 1) {
			App->particles->AddParticle(App->particles->tornado, position.x, position.y - 100, COLLIDER_PLAYER_SHOT, 0);
			App->audio->PlayChunk(tornadosound);
			tornado_timer = 2;
		}
		if (current_animation->GetFinished() == 1)tornado_timer = 3;
		break;
	}

	   	
	/*
	////////////////////RIGHT/////////////////////////
	if ((App->input->keyboardstate[SDL_SCANCODE_D] == KEY_REPEAT || App->input->keyboardstate[SDL_SCANCODE_D] == KEY_PUSHED) && actual == NONE && (position.y == 210 || right == true)) {
		if (position.x <= (SCREEN_WIDTH*SCREEN_SIZE - 410)) {
			current_animation = &forward;
			position.x += speed;
			right = true;

			if (App->render->camera.x > (-SCREEN_WIDTH * SCREEN_SIZE))App->render->camera.x -= speed * 1.25;
		}
	}
	else right = false;

	////////////////////LEFT/////////////////////////

	if ((App->input->keyboardstate[SDL_SCANCODE_A] == KEY_REPEAT || App->input->keyboardstate[SDL_SCANCODE_A] == KEY_PUSHED) && actual == NONE && (position.y == 210 || left == true)) {
		if (position.x >= 20) {
			current_animation = &backward;
			position.x -= speed / 2;
			left = true;
			if (App->render->camera.x < 0)	App->render->camera.x += speed * 1.25;
		}
	}
	else (left = false);

	////////////////////JUMP/////////////////////////

	if (((position.y < 210) || ((App->input->keyboardstate[SDL_SCANCODE_W] == KEY_PUSHED|| App->input->keyboardstate[SDL_SCANCODE_W] == KEY_REPEAT) && actual == NONE)) && (position.y >= 130)) {
		current_animation = &jump;

		if (position.y == 210) {
			App->audio->PlayChunk(jumpsound);
			mult = 1;
		}

		if (position.y == 130) {
			mult = -1;
		}
		position.y -= speed * mult;
	}

	////////////////////PUNCH/////////////////////////
	if ((actual == NONE && App->input->keyboardstate[SDL_SCANCODE_T] == KEY_PUSHED) || actual == PUNCH) {
		current_animation = &punch;
		if (actual == NONE)App->audio->PlayChunk(punchsound);
		if(current_animation->GetFinished()==0)actual = PUNCH;
		else actual = NONE;
	}

	///////////////////////CROUCH/////////////////
	if ((actual == NONE && (App->input->keyboardstate[SDL_SCANCODE_S] == KEY_PUSHED|| App->input->keyboardstate[SDL_SCANCODE_S] == KEY_REPEAT)) || actual == CROUCH) {
		current_animation = &crouch;
		if (current_animation->GetFinished() == 0)actual = CROUCH;
		else actual = NONE;
	}
		
		
		
	
	

	////////////////////KICK/////////////////////////

	if ((actual == NONE && App->input->keyboardstate[SDL_SCANCODE_Y] == KEY_PUSHED) || actual == KICK) {
		current_animation = &kick;
		if (actual == NONE)App->audio->PlayChunk(kicksound);
		if (current_animation->GetFinished() == 0)actual = KICK;
		else actual = NONE;
	}

	////////////////////TORNADO/////////////////////////

	if ((actual == NONE && App->input->keyboardstate[SDL_SCANCODE_R] == KEY_PUSHED) || actual == TORNADO) {
		current_animation = &tornado;
		if (actual == NONE) {
			App->particles->AddParticle(App->particles->tornado, position.x, position.y-100, COLLIDER_PLAYER_SHOT, 0);
			App->audio->PlayChunk(tornadosound);
		}
		if (current_animation->GetFinished() == 0)actual = TORNADO;
		else actual = NONE;
	}
	*/
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
	//body->SetPos(position.x, (position.y - 50));
	
	
/*	if (actual == HITTED) {
		current_animation = &hittedan;
		if(current_animation->GetFinished()==1)	actual = NONE;
	}*/
		// Draw everything --------------------------------------
	SDL_Rect r = current_animation->GetCurrentFrame();		

	if (actual != A_TORNADO) {
		if(flip==false)	App->render->Blit(graphics, position.x, position.y - r.h, &r);
		else App->render->Blit(graphics, position.x, position.y - r.h, &r,1.0F,true,true);
	}
	else App->render->Blit(graphics2, position.x, position.y - r.h, &r);
	//if (godmode == true) { LOG("TRUE\n"); }
	//else LOG("TRUE\n");

	return UPDATE_CONTINUE;
}

void ModulePlayer::CheckSpecialAttacks() {
	bool out = false;
	int done = 0;
	int i = 1;
	if (inputstate[0] == S_T_RIGHT) {
		do{
			switch (inputstate[i]) {
			case S_T_RIGHT:	i++; break;
			case S_CROUCH_RIGHT:
				i++;
				if (done == 0)done++;
				break;
			case S_CROUCH_DOWN:
				if (done == 1) done = 2;
				else out = true;
				break;
			case S_RIGHT_DOWN:
				if (i > 6) out = true;
				else i++;
				break;
			default:
				out = true;
				break;
			}
		} while (out == false && done < 2 && i < 60);
		if (done == 2) inputstate[0] = S_TORNADO;
	}
}

void ModulePlayer::CheckState() {
	switch (actual) {
	case A_IDLE:
		switch (inputstate[0]) {
		case S_RIGHT_DOWN: actual = A_WALK_FORWARD; break;
		case S_LEFT_DOWN: actual = A_WALK_BACKWARD; break;
		case S_JUMP: actual = A_JUMP_NEUTRAL; jump_timer = SDL_GetTicks();  break;
		case S_JUMP_RIGHT:actual = A_JUMP_FORWARD; jump_timer = SDL_GetTicks(); break;
		case S_JUMP_LEFT:actual = A_JUMP_BACKWARD; jump_timer = SDL_GetTicks(); break;
		case S_CROUCH_DOWN: actual = A_CROUCH; break;
		case S_CROUCH_RIGHT: actual = A_CROUCH; break;
		case S_T: actual = A_PUNCH_STANDING; punch_timer = 1;  break;
		case S_T_LEFT: actual = A_PUNCH_STANDING; punch_timer = 1;  break;
		case S_T_RIGHT: actual = A_PUNCH_STANDING; punch_timer = 1;  break;
		case S_T_JUMP: actual = A_PUNCH_NEUTRAL_JUMP; jump_timer = SDL_GetTicks(); punch_timer = 1;  break;
		case S_T_JUMP_RIGHT:actual = A_PUNCH_FORWARD_JUMP; jump_timer = SDL_GetTicks(); punch_timer = 1; break;
		case S_T_JUMP_LEFT:actual = A_PUNCH_BACKWARD_JUMP; jump_timer = SDL_GetTicks(); punch_timer = 1; break;
		case S_T_CROUCH: actual = A_PUNCH_CROUCH; punch_timer = 1; break;
		case S_T_CROUCH_RIGHT: actual = A_PUNCH_CROUCH; punch_timer = 1; break;
		case S_Y: actual = A_KICK_STANDING; kick_timer = 1;  break;
		case S_Y_LEFT: actual = A_KICK_STANDING; kick_timer = 1;  break;
		case S_Y_RIGHT: actual = A_KICK_STANDING; kick_timer = 1; break;
		case S_Y_JUMP: actual = A_KICK_NEUTRAL_JUMP; jump_timer = SDL_GetTicks(); kick_timer = 1;  break;
		case S_Y_JUMP_RIGHT:actual = A_KICK_FORWARD_JUMP; jump_timer = SDL_GetTicks(); kick_timer = 1; break;
		case S_Y_JUMP_LEFT:actual = A_KICK_BACKWARD_JUMP; jump_timer = SDL_GetTicks(); kick_timer = 1; break;
		case S_Y_CROUCH: actual = A_KICK_CROUCH; kick_timer = 1; break;
		case S_Y_CROUCH_RIGHT: actual = A_KICK_CROUCH; kick_timer = 1; break;
		case S_TORNADO: actual = A_TORNADO; tornado_timer = 1; break;
		}
		break;
	case A_WALK_FORWARD:
		switch (inputstate[0]) {
		//case S_RIGHT_UP: actual2 = A_IDLE; break;
		case S_LEFT_AND_RIGHT: actual = A_IDLE; break;
		case S_JUMP: actual = A_JUMP_FORWARD; jump_timer = SDL_GetTicks();  break;
		case S_JUMP_RIGHT:actual = A_JUMP_FORWARD; jump_timer = SDL_GetTicks(); break;
		case S_JUMP_LEFT:actual = A_JUMP_BACKWARD; jump_timer = SDL_GetTicks(); break;
		case S_CROUCH_DOWN: actual = A_CROUCH; break;
		case S_CROUCH_RIGHT: actual = A_CROUCH; break;
		case S_T: actual = A_PUNCH_STANDING; punch_timer = 1;  break;
		case S_T_LEFT: actual = A_PUNCH_STANDING; punch_timer = 1;  break;
		case S_T_RIGHT: actual = A_PUNCH_STANDING; punch_timer = 1;  break;
		case S_T_JUMP: actual = A_PUNCH_NEUTRAL_JUMP; jump_timer = SDL_GetTicks(); punch_timer = 1;  break;
		case S_T_JUMP_RIGHT:actual = A_PUNCH_FORWARD_JUMP; jump_timer = SDL_GetTicks(); punch_timer = 1; break;
		case S_T_JUMP_LEFT:actual = A_PUNCH_BACKWARD_JUMP; jump_timer = SDL_GetTicks(); punch_timer = 1; break;
		case S_T_CROUCH: actual = A_PUNCH_CROUCH; punch_timer = 1; break;
		case S_T_CROUCH_RIGHT: actual = A_PUNCH_CROUCH; punch_timer = 1; break;
		case S_Y: actual = A_KICK_STANDING; kick_timer = 1;  break;
		case S_Y_LEFT: actual = A_KICK_STANDING; kick_timer = 1;  break;
		case S_Y_RIGHT: actual = A_KICK_STANDING; kick_timer = 1; break;
		case S_Y_JUMP: actual = A_KICK_NEUTRAL_JUMP; jump_timer = SDL_GetTicks(); kick_timer = 1;  break;
		case S_Y_JUMP_RIGHT:actual = A_KICK_FORWARD_JUMP; jump_timer = SDL_GetTicks(); kick_timer = 1; break;
		case S_Y_JUMP_LEFT:actual = A_KICK_BACKWARD_JUMP; jump_timer = SDL_GetTicks(); kick_timer = 1; break;
		case S_Y_CROUCH: actual = A_KICK_CROUCH; kick_timer = 1; break;
		case S_Y_CROUCH_RIGHT: actual = A_KICK_CROUCH; kick_timer = 1; break;
		case S_TORNADO: actual = A_TORNADO; tornado_timer = 1; break;
		}
		for (int i = 0; i <= inputsouts; i++)if (inputstateout[i] == SO_RIGHT_UP)actual = A_IDLE;
		//if ((position.x > (SCREEN_WIDTH*SCREEN_SIZE - 410)) && actual2 == A_WALK_FORWARD) actual2 = A_IDLE;
		break;
	case A_WALK_BACKWARD:
		switch (inputstate[0]) {
		//case S_LEFT_UP: actual2 = A_IDLE; break;
		case S_LEFT_AND_RIGHT: actual = A_IDLE; break;
		case S_JUMP: actual = A_JUMP_BACKWARD; jump_timer = SDL_GetTicks();  break;
		case S_JUMP_RIGHT:actual = A_JUMP_FORWARD; jump_timer = SDL_GetTicks(); break;
		case S_JUMP_LEFT:actual = A_JUMP_BACKWARD; jump_timer = SDL_GetTicks(); break;
		case S_CROUCH_DOWN: actual = A_CROUCH; break;
		case S_CROUCH_RIGHT: actual = A_CROUCH; break;
		case S_T: actual = A_PUNCH_STANDING; punch_timer = 1;  break;
		case S_T_LEFT: actual = A_PUNCH_STANDING; punch_timer = 1;  break;
		case S_T_RIGHT: actual = A_PUNCH_STANDING; punch_timer = 1;  break;
		case S_T_JUMP: actual = A_PUNCH_NEUTRAL_JUMP; jump_timer = SDL_GetTicks(); punch_timer = 1;  break;
		case S_T_JUMP_RIGHT:actual = A_PUNCH_FORWARD_JUMP; jump_timer = SDL_GetTicks(); punch_timer = 1; break;
		case S_T_JUMP_LEFT:actual = A_PUNCH_BACKWARD_JUMP; jump_timer = SDL_GetTicks(); punch_timer = 1; break;
		case S_T_CROUCH: actual = A_PUNCH_CROUCH; punch_timer = 1; break;
		case S_T_CROUCH_RIGHT: actual = A_PUNCH_CROUCH; punch_timer = 1; break;
		case S_Y: actual = A_KICK_STANDING; kick_timer = 1;  break;
		case S_Y_LEFT: actual = A_KICK_STANDING; kick_timer = 1;  break;
		case S_Y_RIGHT: actual = A_KICK_STANDING; kick_timer = 1; break;
		case S_Y_JUMP: actual = A_KICK_NEUTRAL_JUMP; jump_timer = SDL_GetTicks(); kick_timer = 1;  break;
		case S_Y_JUMP_RIGHT:actual = A_KICK_FORWARD_JUMP; jump_timer = SDL_GetTicks(); kick_timer = 1; break;
		case S_Y_JUMP_LEFT:actual = A_KICK_BACKWARD_JUMP; jump_timer = SDL_GetTicks(); kick_timer = 1; break;
		case S_Y_CROUCH: actual = A_KICK_CROUCH; kick_timer = 1; break;
		case S_Y_CROUCH_RIGHT: actual = A_KICK_CROUCH; kick_timer = 1; break;
		case S_TORNADO: actual = A_TORNADO; tornado_timer = 1; break;
		}
		for (int i = 0; i <= inputsouts; i++)if (inputstateout[i] == SO_LEFT_UP)actual = A_IDLE;
		//if ((position.x <= 20) && actual2 == A_WALK_BACKWARD) actual2 = A_IDLE;
		break;
	case A_JUMP_NEUTRAL:
		switch (inputstate[0]) {
		//case S_JUMP_FINISH: actual2 = A_IDLE; break;
		case S_T: actual = A_PUNCH_NEUTRAL_JUMP; punch_timer = 1;  break;
		case S_T_LEFT: actual = A_PUNCH_NEUTRAL_JUMP; punch_timer = 1;  break;
		case S_T_RIGHT: actual = A_PUNCH_NEUTRAL_JUMP; punch_timer = 1;  break;
		case S_T_JUMP: actual = A_PUNCH_NEUTRAL_JUMP; punch_timer = 1;  break;
		case S_T_JUMP_RIGHT:actual = A_PUNCH_NEUTRAL_JUMP; punch_timer = 1; break;
		case S_T_JUMP_LEFT:actual = A_PUNCH_NEUTRAL_JUMP; punch_timer = 1; break;
		case S_T_CROUCH: actual = A_PUNCH_NEUTRAL_JUMP; punch_timer = 1; break;
		case S_T_CROUCH_RIGHT: actual = A_PUNCH_NEUTRAL_JUMP; punch_timer = 1; break;
		case S_Y: actual = A_KICK_NEUTRAL_JUMP; kick_timer = 1;  break;
		case S_Y_LEFT: actual = A_KICK_NEUTRAL_JUMP; kick_timer = 1;  break;
		case S_Y_RIGHT: actual = A_KICK_NEUTRAL_JUMP; kick_timer = 1; break;
		case S_Y_JUMP: actual = A_KICK_NEUTRAL_JUMP; kick_timer = 1;  break;
		case S_Y_JUMP_RIGHT:actual = A_KICK_NEUTRAL_JUMP; kick_timer = 1; break;
		case S_Y_JUMP_LEFT:actual = A_KICK_NEUTRAL_JUMP; kick_timer = 1; break;
		case S_Y_CROUCH: actual = A_KICK_NEUTRAL_JUMP; kick_timer = 1; break;
		case S_Y_CROUCH_RIGHT: actual = A_KICK_NEUTRAL_JUMP; kick_timer = 1; break;
		}
		for (int i = 0; i <= inputsouts; i++)if (inputstateout[i] == SO_JUMP_FINISH)actual = A_IDLE;
		break;
	case A_JUMP_FORWARD:
		switch (inputstate[0]) {
		//case S_JUMP_FINISH: actual2 = A_IDLE; break;
		case S_T: actual = A_PUNCH_FORWARD_JUMP; punch_timer = 1;  break;
		case S_T_LEFT: actual = A_PUNCH_FORWARD_JUMP; punch_timer = 1;  break;
		case S_T_RIGHT: actual = A_PUNCH_FORWARD_JUMP; punch_timer = 1;  break;
		case S_T_JUMP: actual = A_PUNCH_FORWARD_JUMP; punch_timer = 1;  break;
		case S_T_JUMP_RIGHT:actual = A_PUNCH_FORWARD_JUMP; punch_timer = 1; break;
		case S_T_JUMP_LEFT:actual = A_PUNCH_FORWARD_JUMP; punch_timer = 1; break;
		case S_T_CROUCH: actual = A_PUNCH_FORWARD_JUMP; punch_timer = 1; break;
		case S_T_CROUCH_RIGHT: actual = A_PUNCH_FORWARD_JUMP; punch_timer = 1; break;
		case S_Y: actual = A_KICK_FORWARD_JUMP; kick_timer = 1;  break;
		case S_Y_LEFT: actual = A_KICK_FORWARD_JUMP; kick_timer = 1;  break;
		case S_Y_RIGHT: actual = A_KICK_FORWARD_JUMP; kick_timer = 1; break;
		case S_Y_JUMP: actual = A_KICK_FORWARD_JUMP; kick_timer = 1;  break;
		case S_Y_JUMP_RIGHT:actual = A_KICK_FORWARD_JUMP; kick_timer = 1; break;
		case S_Y_JUMP_LEFT:actual = A_KICK_FORWARD_JUMP; kick_timer = 1; break;
		case S_Y_CROUCH: actual = A_KICK_FORWARD_JUMP; kick_timer = 1; break;
		case S_Y_CROUCH_RIGHT: actual = A_KICK_FORWARD_JUMP; kick_timer = 1; break;
		}
		for (int i = 0; i <= inputsouts; i++)if (inputstateout[i] == SO_JUMP_FINISH)actual = A_IDLE;
		break;
	case A_JUMP_BACKWARD:
		switch (inputstate[0]) {
		//case S_JUMP_FINISH: actual2 = A_IDLE; break;
		case S_T: actual = A_PUNCH_BACKWARD_JUMP; punch_timer = 1;  break;
		case S_T_LEFT: actual = A_PUNCH_BACKWARD_JUMP; punch_timer = 1;  break;
		case S_T_RIGHT: actual = A_PUNCH_BACKWARD_JUMP; punch_timer = 1;  break;
		case S_T_JUMP: actual = A_PUNCH_BACKWARD_JUMP; punch_timer = 1;  break;
		case S_T_JUMP_RIGHT:actual = A_PUNCH_BACKWARD_JUMP; punch_timer = 1; break;
		case S_T_JUMP_LEFT:actual = A_PUNCH_BACKWARD_JUMP; punch_timer = 1; break;
		case S_T_CROUCH: actual = A_PUNCH_BACKWARD_JUMP; punch_timer = 1; break;
		case S_T_CROUCH_RIGHT: actual = A_PUNCH_BACKWARD_JUMP; punch_timer = 1; break;
		case S_Y: actual = A_KICK_BACKWARD_JUMP; kick_timer = 1;  break;
		case S_Y_LEFT: actual = A_KICK_BACKWARD_JUMP; kick_timer = 1;  break;
		case S_Y_RIGHT: actual = A_KICK_BACKWARD_JUMP; kick_timer = 1; break;
		case S_Y_JUMP: actual = A_KICK_BACKWARD_JUMP; kick_timer = 1;  break;
		case S_Y_JUMP_RIGHT:actual = A_KICK_BACKWARD_JUMP; kick_timer = 1; break;
		case S_Y_JUMP_LEFT:actual = A_KICK_BACKWARD_JUMP; kick_timer = 1; break;
		case S_Y_CROUCH: actual = A_KICK_BACKWARD_JUMP; kick_timer = 1; break;
		case S_Y_CROUCH_RIGHT: actual = A_KICK_FORWARD_JUMP; kick_timer = 1; break;
		}
		for (int i = 0; i <= inputsouts; i++)if (inputstateout[i] == SO_JUMP_FINISH)actual = A_IDLE;
		break;
	case A_PUNCH_STANDING:
		switch (inputstate[0]) {
		//case S_PUNCH_FINISH: actual2 = A_IDLE; break;
		}
		for (int i = 0; i <= inputsouts; i++)if (inputstateout[i] == SO_PUNCH_FINISH)actual = A_IDLE;
		break;
	case A_PUNCH_NEUTRAL_JUMP:
		/*switch (inputstate[0]) {
		//case S_PUNCH_FINISH: actual2 = A_JUMP_NEUTRAL; break;
		//case S_JUMP_FINISH: actual2 = A_IDLE; break;
		}*/
		for (int i = 0; i <= inputsouts; i++)if (inputstateout[i] == SO_JUMP_FINISH) {
			actual = A_IDLE;
		}
		for (int i = 0; i <= inputsouts; i++)if (inputstateout[i] == SO_PUNCH_FINISH)actual = A_JUMP_NEUTRAL;
		break;
	case A_PUNCH_FORWARD_JUMP:
		/*switch (inputstate[0]) {
		//case S_PUNCH_FINISH: actual2 = A_JUMP_FORWARD; break;
		//case S_JUMP_FINISH: actual2 = A_IDLE; break;
		}*/
		for (int i = 0; i <= inputsouts; i++)if (inputstateout[i] == SO_JUMP_FINISH)actual = A_IDLE;
		for (int i = 0; i <= inputsouts; i++)if (inputstateout[i] == SO_PUNCH_FINISH)actual = A_JUMP_FORWARD;
		break;
	case A_PUNCH_BACKWARD_JUMP:
		/*switch (inputstate[0]) {
		//case S_PUNCH_FINISH: actual2 = A_JUMP_BACKWARD; break;
		//case S_JUMP_FINISH: actual2 = A_IDLE; break;
		}*/
		for (int i = 0; i <= inputsouts; i++)if (inputstateout[i] == SO_JUMP_FINISH)actual = A_IDLE;
		for (int i = 0; i <= inputsouts; i++)if (inputstateout[i] == SO_PUNCH_FINISH)actual = A_JUMP_BACKWARD;
		break;
	case A_KICK_STANDING:
		switch (inputstate[0]) {
		//case S_KICK_FINISH: actual2 = A_IDLE; break;
		}
		for (int i = 0; i <= inputsouts; i++)if (inputstateout[i] == SO_KICK_FINISH)actual = A_IDLE;
		break;
	case A_KICK_NEUTRAL_JUMP:
		/*switch (inputstate[0]) {
		//case S_KICK_FINISH: actual2 = A_JUMP_NEUTRAL; break;
		//case S_JUMP_FINISH: actual2 = A_IDLE; break;
		}*/
		for (int i = 0; i <= inputsouts; i++)if (inputstateout[i] == SO_JUMP_FINISH)actual = A_IDLE;
		for (int i = 0; i <= inputsouts; i++)if (inputstateout[i] == SO_KICK_FINISH)actual = A_JUMP_NEUTRAL;
		break;
	case A_KICK_FORWARD_JUMP:
		/*switch (inputstate[0]) {
		//case S_KICK_FINISH: actual2 = A_JUMP_FORWARD; break;
		//case S_JUMP_FINISH: actual2 = A_IDLE; break;
		}*/
		for (int i = 0; i <= inputsouts; i++)if (inputstateout[i] == SO_JUMP_FINISH)actual = A_IDLE;
		for (int i = 0; i <= inputsouts; i++)if (inputstateout[i] == SO_KICK_FINISH)actual = A_JUMP_FORWARD;
		break;
	case A_KICK_BACKWARD_JUMP:
		/*switch (inputstate[0]) {
		//case S_KICK_FINISH: actual2 = A_JUMP_BACKWARD; break;
		//case S_JUMP_FINISH: actual2 = A_IDLE; break;
		}*/
		for (int i = 0; i <= inputsouts; i++)if (inputstateout[i] == SO_JUMP_FINISH)actual = A_IDLE;
		for (int i = 0; i <= inputsouts; i++)if (inputstateout[i] == SO_KICK_FINISH)actual = A_JUMP_BACKWARD;
		break;
	case A_CROUCH:
		switch (inputstate[0]) {
		//case S_CROUCH_UP: actual2 = A_IDLE; break;
		case S_T: actual = A_PUNCH_CROUCH; break;
		case S_T_LEFT: actual = A_PUNCH_CROUCH; punch_timer = 1;  break;
		case S_T_RIGHT: actual = A_PUNCH_CROUCH; punch_timer = 1;  break;
		case S_T_JUMP: actual = A_PUNCH_CROUCH; punch_timer = 1;  break;
		case S_T_JUMP_RIGHT:actual = A_PUNCH_CROUCH; punch_timer = 1; break;
		case S_T_JUMP_LEFT:actual = A_PUNCH_CROUCH; punch_timer = 1; break;
		case S_T_CROUCH: actual = A_PUNCH_CROUCH; punch_timer = 1; break;
		case S_T_CROUCH_RIGHT: actual = A_PUNCH_CROUCH; punch_timer = 1; break;
		case S_Y: actual = A_KICK_CROUCH; kick_timer = 1;  break;
		case S_Y_LEFT: actual = A_KICK_CROUCH; kick_timer = 1;  break;
		case S_Y_RIGHT: actual = A_KICK_CROUCH; kick_timer = 1; break;
		case S_Y_JUMP: actual = A_KICK_CROUCH; kick_timer = 1;  break;
		case S_Y_JUMP_RIGHT:actual = A_KICK_CROUCH; kick_timer = 1; break;
		case S_Y_JUMP_LEFT:actual = A_KICK_CROUCH; kick_timer = 1; break;
		case S_Y_CROUCH: actual = A_KICK_CROUCH; kick_timer = 1; break;
		case S_Y_CROUCH_RIGHT: actual = A_KICK_CROUCH; kick_timer = 1; break;
		case S_TORNADO: actual = A_TORNADO; tornado_timer = 1; break;
		}
		for (int i = 0; i <= inputsouts; i++)if (inputstateout[i] == SO_CROUCH_UP)actual = A_IDLE;
		break;
	case A_PUNCH_CROUCH:
		/*switch (inputstate[0]) {
		//case S_PUNCH_FINISH: actual2 = A_CROUCH; break;
		}*/
		for (int i = 0; i <= inputsouts; i++)if (inputstateout[i] == SO_PUNCH_FINISH) {
			if(inputstate[0]==S_CROUCH_DOWN||inputstate[0]==S_CROUCH_RIGHT)actual = A_CROUCH;
			else actual = A_IDLE;
		}
		break;
	case A_KICK_CROUCH:
		/*switch (inputstate[0]) {
		//case S_KICK_FINISH: actual2 = A_CROUCH; break;
		}*/
		for (int i = 0; i <= inputsouts; i++)if (inputstateout[i] == SO_KICK_FINISH) {
			if (inputstate[0] == S_CROUCH_DOWN || inputstate[0] == S_CROUCH_RIGHT)actual = A_CROUCH;
			else actual = A_IDLE;
		}
		break;
	case A_TORNADO:
		for (int i = 0; i <= inputsouts; i++)if (inputstateout[i] == SO_TORNADO_FINISH)actual = A_IDLE;
		break;
	case A_HITTED:
		for (int i = 0; i <= inputsouts; i++)if (inputstateout[i] == SO_HITTED_FINISH)actual = A_IDLE;
		break;
	}
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
			//if (position.x + 11 * SCREEN_SIZE > App->player2->position.x + 11 * SCREEN_SIZE) {
				//position.x = App->player2->position.x + 23 * SCREEN_SIZE;

			if (flip == false) {
				stopright = true;
				//if (position.x + 10 > App->player2->position.x&&position.y==210)position.x = App->player2->position.x - 15 * SCREEN_SIZE;
			}
			//}
			else {
				stopleft = true;//position.x = App->player2->position.x - 23 * SCREEN_SIZE;

				//if (position.x - 10 < App->player2->position.x+23*SCREEN_SIZE&&position.y == 210)position.x = App->player2->position.x + 20 * SCREEN_SIZE;
			}
		}
	}
	else {
		if (other->type == COLLIDER_ENEMY) {
			player->to_delete = true;
		}
	}
}
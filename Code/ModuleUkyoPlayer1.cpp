#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleUkyoPlayer1.h"
#include "ModuleUkyoPlayer2.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleUI.h"
#include "Modulebackground.h"
#include "SDL/include/SDL_timer.h"


ModuleUkyoPlayer1::ModuleUkyoPlayer1()
{
	position.x = 50;
	position.y = 210;

	// Idle animation
	idle.PushBack({ 0, 0, 75, 137 });
	idle.PushBack({ 75, 0, 75, 137 });
	idle.speed = 0.2f;

	// Walking forward
	forward.PushBack({ 185, 0, 75, 137 });
	forward.PushBack({ 260, 0, 72, 137 });
	forward.PushBack({ 332, 0, 81, 137 });
	forward.PushBack({ 413, 0, 87, 137 });
	forward.PushBack({ 500, 0, 81, 137 });
	forward.PushBack({ 581, 0, 72, 137 });
	forward.PushBack({ 653, 0, 75, 137 });
	forward.speed = 0.2f;

	//Walking backward
	backward.PushBack({ 653, 0, 75, 137 });
	backward.PushBack({ 581, 0, 72, 137 });
	backward.PushBack({ 500, 0, 81, 137 });
	backward.PushBack({ 413, 0, 87, 137 });
	backward.PushBack({ 332, 0, 81, 137 });
	backward.PushBack({ 260, 0, 72, 137 });
	backward.PushBack({ 185, 0, 75, 137 });
	backward.speed = 0.2f;
	
	// Jump
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
}

ModuleUkyoPlayer1::~ModuleUkyoPlayer1()
{}

// Load assets
bool ModuleUkyoPlayer1::Start()
{
	LOG("Loading player textures");
	bool ret = true;
	graphics = App->textures->Load("Sprites/UkyoPlayer1SpriteSheet.png");
	position.x = 50;
	position.y = 210;
	body = App->collision->AddCollider({ position.x,(position.y - 100),35,20 }, COLLIDER_PLAYER, this);
	body2 = App->collision->AddCollider({ position.x,(position.y - 50),25,15 }, COLLIDER_PLAYER, this);
	body3 = App->collision->AddCollider({ position.x,(position.y - 20),45,35 }, COLLIDER_PLAYER, this);
	actual = A_IDLE;
	for (int i = 0; i < 60; i++) inputstate[i] = S_NONE;
	for (int i = 0; i < 6; i++) inputstateout[i] = SO_NONE;
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
bool ModuleUkyoPlayer1::CleanUp() {
	App->textures->Unload(graphics);
	App->audio->StopChunk();
	return true;
}

update_status ModuleUkyoPlayer1::PreUpdate() {
	stopright = false;
	stopleft = false;
	if (position.x > App->ukyoplayer2->position.x&&position.y == 210)flip = true;
	else if (position.x < App->ukyoplayer2->position.x&&position.y == 210)flip = false;
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
			if (flip == true)inputstateout[inputsouts] = SO_LEFT_UP;
			else inputstateout[inputsouts] = SO_RIGHT_UP;
			if (inputstate[0] == S_RIGHT_DOWN && flip == false)inputstate[0] = S_NONE;
			else if (inputstate[0] == S_LEFT_DOWN && flip == true)inputstate[0] = S_NONE;
			inputsouts++;
		}
		else if (left == true)/*(App->input->keyboardstate[SDL_SCANCODE_A] == KEY_PUSHED)*/ inputstate[0] = S_LEFT_DOWN;
		else if (App->input->keyboardstate[SDL_SCANCODE_A] == KEY_PULLED) {
			if (flip == true)inputstateout[inputsouts] = SO_RIGHT_UP;
			else inputstateout[inputsouts] = SO_LEFT_UP;
			if (inputstate[0] == S_LEFT_DOWN && flip == false)inputstate[0] = S_NONE;
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
update_status ModuleUkyoPlayer1::Update()
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
			body->SetPos(position.x + 18, (position.y - 80));
			body2->SetPos(position.x + 26, (position.y - 57));
			body3->SetPos(position.x + 16, (position.y - 40));
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
			if (stopright == false)position.x += speed;
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
			if (stopleft == false)position.x -= speed / 2;
			if ((App->background->cameraleft.x > 0) && (App->background->cameraright.x > (App->ukyoplayer2->position.x + (23 * SCREEN_SIZE)))) App->render->camera.x += speed;// *1.25;
		}
		else {
			//if (position.x + 23 * SCREEN_SIZE < App->background->cameraright.x - 1) position.x += speed / 2;
			//else if (position.y > App->player2->position.y) position.x += speed/2;
			if (stopright == false)position.x += speed / 2;
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
			//App->audio->PlayChunk(jumpsound);
			mult = 2;
		}
		if (position.y <= 80) {
			mult = -2;
		}
		position.y -= speed * mult;
		break;

		/*
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
			if (stopright == false)position.x += speed / 2;
			if ((App->background->cameraleft.x < position.x) && (App->background->cameraright.x < 670))App->render->camera.x -= speed;// *1.25;
		}
		else {
			//if ((position.x) > (App->player2->position.x + 23 * SCREEN_SIZE)) position.x -= speed / 2;
			//	else if (position.y < App->player2->position.y)position.x -= speed / 2;
			if (stopleft == false)position.x -= speed / 2;
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
			if (stopleft == false)position.x -= speed / 2;
			if ((App->background->cameraleft.x > 0) && (App->background->cameraright.x > (App->player2->position.x + (23 * SCREEN_SIZE)))) App->render->camera.x += speed;// *1.25;
		}
		else {
			//if (position.x + 23 * SCREEN_SIZE < App->background->cameraright.x - 1) position.x += speed / 2;
			//else if (position.y < App->player2->position.y)position.x += speed/2;
			if (stopright == false)position.x += speed / 2;
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
			body->SetPos(position.x + 15, (position.y - 70));
			body2->SetPos(position.x + 8, (position.y - 54));
			body3->SetPos(position.x + 8, (position.y - 40));
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
		else {
		current_animation = &punch;
		if (punch_timer == 1) {
			App->audio->PlayChunk(punchsound);
			punch_timer = 2;
			if (flip == false) {
				attack = App->collision->AddCollider({ position.x + 60,(position.y - 75),75,50 }, COLLIDER_PLAYER_SHOT, this);
			}
			else {
				attack = App->collision->AddCollider({ position.x + 1,(position.y - 75),75,50 }, COLLIDER_PLAYER_SHOT, this);
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
			if (stopright == false)position.x += speed / 2;
			if ((App->background->cameraleft.x < position.x) && (App->background->cameraright.x < 670))App->render->camera.x -= speed;// *1.25;
		}
		else {
			//if ((position.x) > (App->player2->position.x + 23 * SCREEN_SIZE)) position.x -= speed / 2;
			//else if (position.y < App->player2->position.y)position.x -= speed / 2;
			if (stopleft == false)position.x -= speed / 2;
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
			if (stopleft == false)position.x -= speed / 2;
			if ((App->background->cameraleft.x > 0) && (App->background->cameraright.x > (App->player2->position.x + (23 * SCREEN_SIZE)))) App->render->camera.x += speed;// *1.25;
		}
		else {
			//if (position.x + 23 * SCREEN_SIZE < App->background->cameraright.x - 1) position.x += speed / 2;
			//else if (position.y < App->player2->position.y)position.x += speed/2;
			if (stopright == false)position.x += speed / 2;
			if ((App->background->cameraleft.x < App->player2->position.x) && (App->background->cameraright.x < 670)) App->render->camera.x -= speed;// *1.25;
		}
		if (punch_timer == 1) {
			App->audio->PlayChunk(punchsound);
			punch_timer = 2;
			if (flip == false) {

				attack = App->collision->AddCollider({ position.x + 40,(position.y - 110),75,40 }, COLLIDER_PLAYER_SHOT, this);
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
			if (flip == false) {
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
			if ((position.x) > (App->player2->position.x + 23 * SCREEN_SIZE)) position.x -= speed / 2;
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
			if (position.x > App->background->cameraleft.x) position.x -= speed / 2;
			else if (position.y < App->player2->position.y)position.x -= speed / 2;
			if ((App->background->cameraleft.x > 0) && (App->background->cameraright.x > (App->player2->position.x + (23 * SCREEN_SIZE)))) App->render->camera.x += speed;// *1.25;
		}
		else {
			if (position.x + 23 * SCREEN_SIZE < App->background->cameraright.x - 1) position.x += speed / 2;
			else if (position.y < App->player2->position.y)position.x += speed / 2;
			if ((App->background->cameraleft.x < App->player2->position.x) && (App->background->cameraright.x < 670)) App->render->camera.x -= speed;// *1.25;
		}
		if (kick_timer == 1) {
			App->audio->PlayChunk(kicksound);
			kick_timer = 2;
			if (flip == false) {
				attack = App->collision->AddCollider({ position.x + 30,(position.y - 30),65,20 }, COLLIDER_PLAYER_SHOT, this);
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
			if (flip == true) {
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
		if (flip == false) {
			position.x -= 1;
		}
		else if (flip == true) {
			position.x += 1;
		}
		if (position.y == 130) {
			mult = -1;
		}
		if (position.y < 210)position.y -= speed * mult;
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
		*/
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
		if (flip == false)	App->render->Blit(graphics, position.x, position.y - r.h, &r);
		else App->render->Blit(graphics, position.x, position.y - r.h, &r, 1.0F, true, true);
	}
	
	//if (godmode == true) { LOG("TRUE\n"); }
	//else LOG("TRUE\n");

	return UPDATE_CONTINUE;
}

void ModuleUkyoPlayer1::CheckSpecialAttacks() {
	bool out = false;
	int done = 0;
	int i = 1;
	if (inputstate[0] == S_T_RIGHT) {
		do {
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

void ModuleUkyoPlayer1::CheckState() {
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
			if (inputstate[0] == S_CROUCH_DOWN || inputstate[0] == S_CROUCH_RIGHT)actual = A_CROUCH;
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

void ModuleUkyoPlayer1::OnCollision(Collider* player, Collider* other) {

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
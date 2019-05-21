#include "Globals.h"
#include "Application.h"
#include "StateMachine.h"
#include "ModuleInput.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "Modulebackground.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleAudio.h"
#include "ModuleUI.h"
#include "SDL/include/SDL.h"

void Preupdate(int& jump_timer, int& punch_timer, int& kick_timer, int& tornado_timer, int& hitted_timer, int& inputsouts, iPoint position, bool flip, state actual, inputin inputstate[60], inputout inputstateout[INPUTSOUTS], Module* Player) {
	if (actual != A_HITTED) {
		bool left = false;
		bool right = false;
		if (Player == App->player) {
			if (App->input->keyboardstate[SDL_SCANCODE_D] == KEY_PUSHED || App->input->keyboardstate[SDL_SCANCODE_D] == KEY_REPEAT) {
				if (flip == true) left = true;
				else right = true;
			}
			if (App->input->keyboardstate[SDL_SCANCODE_A] == KEY_PUSHED || App->input->keyboardstate[SDL_SCANCODE_A] == KEY_REPEAT) {
				if (flip == true) right = true;
				else left = true;
			}
		}
		else if (Player == App->player2) {
			if (App->input->keyboardstate[SDL_SCANCODE_RIGHT] == KEY_PUSHED || App->input->keyboardstate[SDL_SCANCODE_RIGHT] == KEY_REPEAT) {
				if (flip == true) left = true;
				else right = true;
			}
			if (App->input->keyboardstate[SDL_SCANCODE_LEFT] == KEY_PUSHED || App->input->keyboardstate[SDL_SCANCODE_LEFT] == KEY_REPEAT) {
				if (flip == true) right = true;
				else left = true;
			}
		}
		if (right == true && left == true)inputstate[0] = S_LEFT_AND_RIGHT;
		else if (right == true)inputstate[0] = S_RIGHT_DOWN;
		else if (left == true) inputstate[0] = S_LEFT_DOWN;
		if (Player == App->player) {
			if (App->input->keyboardstate[SDL_SCANCODE_D] == KEY_PULLED) {
				if (flip == true)inputstateout[inputsouts] = SO_LEFT_UP;
				else inputstateout[inputsouts] = SO_RIGHT_UP;
				if (inputstate[0] == S_RIGHT_DOWN && flip == false)inputstate[0] = S_NONE;
				else if (inputstate[0] == S_LEFT_DOWN && flip == true)inputstate[0] = S_NONE;
				inputsouts++;
			}
			else if (App->input->keyboardstate[SDL_SCANCODE_A] == KEY_PULLED) {
				if (flip == true)inputstateout[inputsouts] = SO_RIGHT_UP;
				else inputstateout[inputsouts] = SO_LEFT_UP;
				if (inputstate[0] == S_LEFT_DOWN && flip == false)inputstate[0] = S_NONE;
				else if (inputstate[0] == S_RIGHT_DOWN && flip == true)inputstate[0] = S_NONE;
				inputsouts++;
			}
		}
		else if (Player == App->player2) {
			if (App->input->keyboardstate[SDL_SCANCODE_RIGHT] == KEY_PULLED) {
				if (flip == true)inputstateout[inputsouts] = SO_LEFT_UP;
				else inputstateout[inputsouts] = SO_RIGHT_UP;
				if (inputstate[0] == S_RIGHT_DOWN && flip == false)inputstate[0] = S_NONE;
				else if (inputstate[0] == S_LEFT_DOWN && flip == true)inputstate[0] = S_NONE;
				inputsouts++;
			}
			else if (App->input->keyboardstate[SDL_SCANCODE_LEFT] == KEY_PULLED) {
				if (flip == true)inputstateout[inputsouts] = SO_RIGHT_UP;
				else inputstateout[inputsouts] = SO_LEFT_UP;
				if (inputstate[0] == S_LEFT_DOWN && flip == false)inputstate[0] = S_NONE;
				else if (inputstate[0] == S_RIGHT_DOWN && flip == true)inputstate[0] = S_NONE;
				inputsouts++;
			}
		}
		//CHECK JUMP AND JUMP WITH DIRECTION//
		bool jump = false;
		if (Player == App->player) {
			if (App->input->keyboardstate[SDL_SCANCODE_W] == KEY_PUSHED || App->input->keyboardstate[SDL_SCANCODE_W] == KEY_REPEAT)jump = true;
		}
		else if (Player == App->player2) {
			if (App->input->keyboardstate[SDL_SCANCODE_UP] == KEY_PUSHED || App->input->keyboardstate[SDL_SCANCODE_UP] == KEY_REPEAT)jump = true;
		}
		if (jump == true) {
			if (inputstate[0] == S_RIGHT_DOWN)inputstate[0] = S_JUMP_RIGHT;
			else if (inputstate[0] == S_LEFT_DOWN)inputstate[0] = S_JUMP_LEFT;
			else inputstate[0] = S_JUMP;
		}

		//CHECK CROUCH AND CROUCH WITH DIRECTION//
		bool crouch = false;
		if (Player == App->player) {
			if (App->input->keyboardstate[SDL_SCANCODE_S] == KEY_PUSHED || App->input->keyboardstate[SDL_SCANCODE_S] == KEY_REPEAT)crouch = true;
		}
		else if (Player == App->player2) {
			if (App->input->keyboardstate[SDL_SCANCODE_DOWN] == KEY_PUSHED || App->input->keyboardstate[SDL_SCANCODE_DOWN] == KEY_REPEAT)crouch = true;
		}
		if (crouch == true) {
			if (inputstate[0] == S_JUMP) inputstate[0] = S_JUMP_AND_CROUCH;
			else if (inputstate[0] == S_RIGHT_DOWN) { inputstate[0] = S_CROUCH_RIGHT; }
			else inputstate[0] = S_CROUCH_DOWN;
		}
		else if (Player == App->player) {
			if (App->input->keyboardstate[SDL_SCANCODE_S] == KEY_PULLED) {
				inputstateout[inputsouts] = SO_CROUCH_UP;
				if (inputstate[0] == S_CROUCH_DOWN)inputstate[0] = S_NONE;
				inputsouts++;
			}
		}
		else if (Player == App->player2) {
			if (App->input->keyboardstate[SDL_SCANCODE_DOWN] == KEY_PULLED) {
				inputstateout[inputsouts] = SO_CROUCH_UP;
				if (inputstate[0] == S_CROUCH_DOWN)inputstate[0] = S_NONE;
				inputsouts++;
			}
		}

		//CHECK PUNCH AND VARIATIONS OF IT//
		bool punch = false;
		if (Player == App->player) {
			if (App->input->keyboardstate[SDL_SCANCODE_T] == KEY_PUSHED || App->input->keyboardstate[SDL_SCANCODE_T] == KEY_REPEAT) punch = true;
		}
		else if (Player == App->player2) {
			if (App->input->keyboardstate[SDL_SCANCODE_G] == KEY_PUSHED || App->input->keyboardstate[SDL_SCANCODE_G] == KEY_REPEAT) punch = true;
		}
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
		if (Player == App->player) {
			if (App->input->keyboardstate[SDL_SCANCODE_Y] == KEY_PUSHED || App->input->keyboardstate[SDL_SCANCODE_Y] == KEY_REPEAT) kick = true;
		}
		else if (Player == App->player2) {
			if (App->input->keyboardstate[SDL_SCANCODE_H] == KEY_PUSHED || App->input->keyboardstate[SDL_SCANCODE_H] == KEY_REPEAT) kick = true;
		}
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
		}
	}
	//CHECK TIMERS//
	if (jump_timer > 0) {
		if (position.y == 210) {
			inputstateout[inputsouts] = SO_JUMP_FINISH;
			inputsouts++;
			jump_timer = 0;
		}
	}
	if (punch_timer == 3) {
		inputstateout[inputsouts] = SO_PUNCH_FINISH;
		inputsouts++;
		punch_timer = 0;
	}
	if (kick_timer == 3) {
		inputstateout[inputsouts] = SO_KICK_FINISH;
		inputsouts++;
		kick_timer = 0;
	}
	if (tornado_timer == 3) {
		inputstateout[inputsouts] = SO_TORNADO_FINISH;
		inputsouts++;
		tornado_timer = 0;
	}	
	if (hitted_timer == 3) {
		inputstateout[inputsouts] = SO_HITTED_FINISH;
		inputsouts++;
		hitted_timer = 0;
	}
}
Animation* ExecuteState(int& jump_timer, int& punch_timer, int& kick_timer, int& tornado_timer, int& hitted_timer, state actual, bool flip, int speed,  int& mult, bool stopright, bool stopleft, Collider& body, Collider& body2, Collider& body3, Collider **attack, iPoint& position, Module* Player) {
	Animation* current_animation=&App->player->idle;
	switch (actual) {
	case A_IDLE:
		current_animation = &App->player->idle;
		if (flip == false) {
			body.SetPos(position.x + 18, (position.y - 80));
			body2.SetPos(position.x + 20, (position.y - 57));
			body3.SetPos(position.x + 10, (position.y - 40));
		}
		else {
			body.SetPos(position.x + 18, (position.y - 80));
			body2.SetPos(position.x + 26, (position.y - 57));
			body3.SetPos(position.x + 16, (position.y - 40));
		}
		break;
	case A_WALK_FORWARD:
		current_animation = &App->player->forward;
		if (flip == false) {
			body.SetPos(position.x + 18, (position.y - 80));
			body2.SetPos(position.x + 20, (position.y - 57));
			body3.SetPos(position.x + 10, (position.y - 40));
		}
		else {
			body.SetPos(position.x + 18, (position.y - 80));
			body2.SetPos(position.x + 26, (position.y - 57));
			body3.SetPos(position.x + 16, (position.y - 40));
		}
		if (flip == false) {
			if (stopright == false)	position.x += speed;
			if (App->player->stopleft == false && App->player2->stopleft == false) {
				if (App->background->cameraright.x < 670)App->render->camera.x -= speed;
			}
		}
		else {
			if (stopleft == false) position.x -= speed;
			if (App->player->stopright == false && App->player2->stopright == false) {
				if (App->background->cameraleft.x > 0)App->render->camera.x += speed;
			}
		}
		break;
	case A_WALK_BACKWARD:
		current_animation = &App->player->backward;
		if (flip == false) {
			body.SetPos(position.x + 18, (position.y - 80));
			body2.SetPos(position.x + 20, (position.y - 57));
			body3.SetPos(position.x + 10, (position.y - 40));
		}
		else {
			body.SetPos(position.x + 18, (position.y - 80));
			body2.SetPos(position.x + 26, (position.y - 57));
			body3.SetPos(position.x + 16, (position.y - 40));
		}
		if (flip == false) {
			if (stopleft == false) position.x -= speed / 2;
			if (App->player->stopright == false && App->player2->stopright == false) {
				if (App->background->cameraleft.x > 0) App->render->camera.x += speed;
			}
		}
		else {
			if (stopright == false)position.x += speed / 2;
			if(App->player->stopleft==false&&App->player2->stopleft==false){
				if (App->background->cameraright.x < 670) App->render->camera.x -= speed;
			}
		}
		break;
	case A_JUMP_NEUTRAL:
		current_animation = &App->player->jump;
		if (flip == false) {
			body.SetPos(position.x + 10, (position.y - 90));
			body2.SetPos(position.x + 12, (position.y - 69));
			body3.SetPos(position.x + 5, (position.y - 55));
		}
		else {
			body.SetPos(position.x + 35, (position.y - 90));
			body2.SetPos(position.x + 42, (position.y - 69));
			body3.SetPos(position.x + 30, (position.y - 55));
		}
		if (position.y == 210) {
			App->audio->PlayChunk(App->player->jumpsound);
			mult = 2;
		}
		if (position.y <= 80) {
			mult = -2;
		}
		position.y -= speed * mult;
		break;
	case A_JUMP_FORWARD:
		current_animation = &App->player->jumpforward;
		if (flip == false) {
			body.SetPos(position.x + 10, (position.y - 90));
			body2.SetPos(position.x + 12, (position.y - 69));
			body3.SetPos(position.x + 5, (position.y - 55));
		}
		else {
			body.SetPos(position.x + 35, (position.y - 90));
			body2.SetPos(position.x + 42, (position.y - 69));
			body3.SetPos(position.x + 30, (position.y - 55));
		}
		if (position.y == 210) {
			App->audio->PlayChunk(App->player->jumpsound);
			mult = 2;
		}
		if (position.y <= 80) mult = -2;
		position.y -= speed * mult;
		if (flip == false) {
			if (stopright == false)	position.x += speed;
			if (App->player->stopleft == false && App->player2->stopleft == false) {
				if (App->background->cameraright.x < 670)App->render->camera.x -= speed;
			}
		}
		else {
			if (stopleft == false) position.x -= speed;
			if (App->player->stopright == false && App->player2->stopright == false) {
				if (App->background->cameraleft.x > 0)App->render->camera.x += speed;
			}
		}
		break;
	case A_JUMP_BACKWARD:
		current_animation = &App->player->jumpbackward;
		if (flip == false) {
			body.SetPos(position.x + 10, (position.y - 90));
			body2.SetPos(position.x + 12, (position.y - 69));
			body3.SetPos(position.x + 5, (position.y - 55));
		}
		else {

			body.SetPos(position.x + 35, (position.y - 90));
			body2.SetPos(position.x + 42, (position.y - 69));
			body3.SetPos(position.x + 30, (position.y - 55));
		}
		if (position.y == 210) {
			App->audio->PlayChunk(App->player->jumpsound);
			mult = 2;
		}
		if (position.y <= 80) mult = -2;
		position.y -= speed * mult;
		if (flip == false) {
			if (stopleft == false) position.x -= speed / 2;
			if (App->player->stopright == false && App->player2->stopright == false) {
				if (App->background->cameraleft.x > 0) App->render->camera.x += speed;
			}
		}
		else {
			if (stopright == false)position.x += speed / 2;
			if (App->player->stopleft == false && App->player2->stopleft == false) {
				if (App->background->cameraright.x < 670) App->render->camera.x -= speed;
			}
		}
		break;
	case A_CROUCH:
		current_animation = &App->player->crouch;
		if (flip == false) {
			body.SetPos(position.x + 50, (position.y - 70));
			body2.SetPos(position.x + 67, (position.y - 54));
			body3.SetPos(position.x + 47, (position.y - 40));
		}
		else {
			body.SetPos(position.x + 15, (position.y - 70));
			body2.SetPos(position.x + 8, (position.y - 54));
			body3.SetPos(position.x + 8, (position.y - 40));
		}
		if (current_animation->GetFinished() == 1) {
			current_animation = &App->player->crouchfinished;
		}
		break;
	case A_PUNCH_STANDING:
		current_animation = &App->player->punch;
		if (punch_timer == 1) {
			App->audio->PlayChunk(App->player->punchsound);
			punch_timer = 2;
			if (flip == false) {
				if (Player == App->player) *attack = App->collision->AddCollider({ position.x + 60,(position.y - 75),75,50 }, COLLIDER_PLAYER_SHOT, App->player);
				else if (Player == App->player2) *attack = App->collision->AddCollider({ position.x + 60,(position.y - 75),75,50 }, COLLIDER_ENEMY_SHOT, App->player2);
			}
			else {
				position.x = position.x - 40;
				if (Player == App->player) *attack = App->collision->AddCollider({ position.x + 1,(position.y - 75),75,50 }, COLLIDER_PLAYER_SHOT, App->player);
				else if (Player == App->player2) *attack = App->collision->AddCollider({ position.x + 1,(position.y - 75),75,50 }, COLLIDER_ENEMY_SHOT, App->player2);
			}
		}
		if (current_animation->GetFinished() == 1) {
			if (flip == true) {
				position.x = position.x + 40;
			}
			punch_timer = 3;
			(*attack)->to_delete = true;
		}
		break;
	case A_PUNCH_NEUTRAL_JUMP:
		current_animation = &App->player->punchair;
		if (flip == false) {
			body.SetPos(position.x + 50, (position.y - 120));
			body2.SetPos(position.x + 52, (position.y - 99));
			body3.SetPos(position.x + 45, (position.y - 85));
		}
		else {
			body.SetPos(position.x + 50, (position.y - 120));
			body2.SetPos(position.x + 52, (position.y - 99));
			body3.SetPos(position.x + 45, (position.y - 85));
		}
		if (position.y == 210) {
			App->audio->PlayChunk(App->player->jumpsound);
			mult = 2;
		}
		if (position.y <= 80) {
			mult = -2;
		}
		position.y -= speed * mult;
		if (punch_timer == 1) {
			App->audio->PlayChunk(App->player->punchsound);
			position.x = position.x - 40;
			punch_timer = 2;
			if (flip == false) {
				if (Player == App->player) *attack = App->collision->AddCollider({ position.x + 50,(position.y - 110),75,40 }, COLLIDER_PLAYER_SHOT, App->player);
				else if (Player == App->player2) *attack = App->collision->AddCollider({ position.x + 50,(position.y - 110),75,40 }, COLLIDER_ENEMY_SHOT, App->player2);
				position.x += 24;
			}
			else {
				if (Player == App->player) *attack = App->collision->AddCollider({ position.x + 5,(position.y - 110),75,40 }, COLLIDER_PLAYER_SHOT, App->player);
				else if (Player == App->player2) *attack = App->collision->AddCollider({ position.x + 5,(position.y - 110),75,40 }, COLLIDER_ENEMY_SHOT, App->player2);
				position.x -= 24;
			}
		}
		if (current_animation->GetFinished() == 1) {
			if (flip == true) {
				position.x += 24;
			}
			else {
				position.x -= 24;
			}
			punch_timer = 3;
			position.x = position.x + 40;
			(*attack)->to_delete = true;
		}
		break;

	case A_PUNCH_FORWARD_JUMP:
		current_animation = &App->player->punchair;
		if (flip == false) {
			body.SetPos(position.x + 50, (position.y - 120));
			body2.SetPos(position.x + 52, (position.y - 99));
			body3.SetPos(position.x + 45, (position.y - 85));
		}
		else {
			body.SetPos(position.x, (position.y - 120));
			body2.SetPos(position.x, (position.y - 99));
			body3.SetPos(position.x, (position.y - 85));
		}

		if (position.y == 210) {
			App->audio->PlayChunk(App->player->jumpsound);
			mult = 2;
		}
		if (position.y <= 80) mult = -2;
		position.y -= speed * mult;
		if (flip == false) {
			if (stopright == false)	position.x += speed;
			if (App->player->stopleft == false && App->player2->stopleft == false) {
				if (App->background->cameraright.x < 670)App->render->camera.x -= speed;
			}
		}
		else {
			if (stopleft == false) position.x -= speed;
			if (App->player->stopright == false && App->player2->stopright == false) {
				if (App->background->cameraleft.x > 0)App->render->camera.x += speed;
			}
		}
		if (punch_timer == 1) {
			punch_timer = 2;
			App->audio->PlayChunk(App->player->punchsound);
			if (flip == false) {
				if (Player == App->player) *attack = App->collision->AddCollider({ position.x + 70,(position.y - 110),75,40 }, COLLIDER_PLAYER_SHOT, App->player);
				else if (Player == App->player2) *attack = App->collision->AddCollider({ position.x + 70,(position.y - 110),75,40 }, COLLIDER_ENEMY_SHOT, App->player2);
				position.x += 24;
			}
			else {
				if (Player == App->player) *attack = App->collision->AddCollider({ position.x + 1,(position.y - 110),75,40 }, COLLIDER_PLAYER_SHOT, App->player);
				else if (Player == App->player2) *attack = App->collision->AddCollider({ position.x + 1,(position.y - 110),75,40 }, COLLIDER_ENEMY_SHOT, App->player2);
				position.x -= 24;
			}
		}
		if (current_animation->GetFinished() == 1) {
			if (flip == true) {
				position.x += 24;
			}
			else {
				position.x -= 24;
			}
			(*attack)->to_delete = true;
			punch_timer = 3;
		}
		break;

	case A_PUNCH_BACKWARD_JUMP:
		current_animation = &App->player->punchair;
		if (flip == false) {
			body.SetPos(position.x + 50, (position.y - 120));
			body2.SetPos(position.x + 52, (position.y - 99));
			body3.SetPos(position.x + 45, (position.y - 85));
		}
		else {
			body.SetPos(position.x + 50, (position.y - 120));
			body2.SetPos(position.x + 52, (position.y - 99));
			body3.SetPos(position.x + 45, (position.y - 85));
		}
		if (position.y == 210) {
			App->audio->PlayChunk(App->player->jumpsound);
			mult = 2;
		}
		if (position.y <= 80) mult = -2;
		position.y -= speed * mult;
		if (flip == false) {
			if (stopleft == false) position.x -= speed / 2;
			if (App->player->stopright == false && App->player2->stopright == false) {
				if (App->background->cameraleft.x > 0) App->render->camera.x += speed;
			}
		}
		else {
			if (stopright == false)position.x += speed / 2;
			if (App->player->stopleft == false && App->player2->stopleft == false) {
				if (App->background->cameraright.x < 670) App->render->camera.x -= speed;
			}
		}
		if (punch_timer == 1) {
			App->audio->PlayChunk(App->player->punchsound);
			punch_timer = 2;
			if (flip == false) {
				if (Player == App->player) *attack = App->collision->AddCollider({ position.x + 40,(position.y - 110),75,40 }, COLLIDER_PLAYER_SHOT, App->player);
				else if (Player == App->player2) *attack = App->collision->AddCollider({ position.x + 40,(position.y - 110),75,40 }, COLLIDER_ENEMY_SHOT, App->player2);
			}
			else {
				if (Player == App->player) *attack = App->collision->AddCollider({ position.x + 1,(position.y - 110),75,40 }, COLLIDER_PLAYER_SHOT, App->player);
				else if (Player == App->player2) *attack = App->collision->AddCollider({ position.x + 1,(position.y - 110),75,40 }, COLLIDER_ENEMY_SHOT, App->player2);
			}
		}
		if (current_animation->GetFinished() == 1) {
			(*attack)->to_delete = true;
			punch_timer = 3;
		}
		break;
	case A_PUNCH_CROUCH:
		current_animation = &App->player->punchcrouch;
		if (flip == false) {
			body.SetPos(position.x + 35, (position.y - 65));
			body2.SetPos(position.x + 52, (position.y - 50));
			body3.SetPos(position.x + 32, (position.y - 35));
		}
		else {
			body.SetPos(position.x + 50, (position.y - 65));
			body2.SetPos(position.x + 67, (position.y - 50));
			body3.SetPos(position.x + 47, (position.y - 35));
		}
		if (punch_timer == 1) {
			App->audio->PlayChunk(App->player->punchsound);
			punch_timer = 2;
			if (flip == false) {
				if (Player == App->player) *attack = App->collision->AddCollider({ position.x + 50,(position.y - 30),75,30 }, COLLIDER_PLAYER_SHOT, App->player);
				else if (Player == App->player2) *attack = App->collision->AddCollider({ position.x + 50,(position.y - 30),75,30 }, COLLIDER_ENEMY_SHOT, App->player2);
			}
			else {
				if (Player == App->player) *attack = App->collision->AddCollider({ position.x + 1,(position.y - 30),75,30 }, COLLIDER_PLAYER_SHOT, App->player);
				else if (Player == App->player2) *attack = App->collision->AddCollider({ position.x + 1,(position.y - 30),75,30 }, COLLIDER_ENEMY_SHOT, App->player2);
				position.x -= 80;
			}
		}
		if (current_animation->GetFinished() == 1) {
			if (flip == true) {
				position.x += 80;
			}
			punch_timer = 3;
			(*attack)->to_delete = true;
		}
		break;
	case A_KICK_STANDING:
		current_animation = &App->player->kick;
		if (flip == false) {
			position.x += 2;
			body.SetPos(position.x + 18, (position.y - 80));
			body2.SetPos(position.x + 20, (position.y - 57));
			body3.SetPos(position.x + 20, (position.y - 40));
		}
		else {
			position.x -= 2;
			body.SetPos(position.x + 18, (position.y - 80));
			body2.SetPos(position.x + 20, (position.y - 57));
			body3.SetPos(position.x + 20, (position.y - 40));
		}
		if (kick_timer == 1) {
			App->audio->PlayChunk(App->player->kicksound);
			kick_timer = 2;
			if (flip == false) {
				if (Player == App->player) *attack = App->collision->AddCollider({ position.x + 40,(position.y - 90),65,20 }, COLLIDER_PLAYER_SHOT, App->player);
				else if (Player == App->player2) *attack = App->collision->AddCollider({ position.x + 40,(position.y - 90),65,20 }, COLLIDER_ENEMY_SHOT, App->player2);
			}
			else {
				if (Player == App->player) *attack = App->collision->AddCollider({ position.x + 1,(position.y - 90),65,20 }, COLLIDER_PLAYER_SHOT, App->player);
				else if (Player == App->player2) *attack = App->collision->AddCollider({ position.x + 1,(position.y - 90),65,20 }, COLLIDER_ENEMY_SHOT, App->player2);
			}
		}
		if (current_animation->GetFinished() == 1) {
			kick_timer = 3;
			(*attack)->to_delete = true;
		}
		break;
	case A_KICK_NEUTRAL_JUMP:
		current_animation = &App->player->kickair;
		if (flip == false) {
			body.SetPos(position.x + 10, (position.y - 60));
			body2.SetPos(position.x + 12, (position.y - 49));
			body3.SetPos(position.x + 15, (position.y - 35));
		}
		else {
			body.SetPos(position.x + 35, (position.y - 60));
			body2.SetPos(position.x + 42, (position.y - 49));
			body3.SetPos(position.x + 45, (position.y - 35));
		}
		if (position.y == 210) {
			App->audio->PlayChunk(App->player->jumpsound);
			mult = 2;
		}
		if (position.y <= 80) {
			mult = -2;
		}
		position.y -= speed * mult;
		if (kick_timer == 1) {
			App->audio->PlayChunk(App->player->kicksound);
			kick_timer = 2;
			if (flip == false) {
				if (Player == App->player) *attack = App->collision->AddCollider({ position.x + 40,(position.y - 30),65,20 }, COLLIDER_PLAYER_SHOT, App->player);
				else if (Player == App->player2) *attack = App->collision->AddCollider({ position.x + 40,(position.y - 30),65,20 }, COLLIDER_ENEMY_SHOT, App->player2);
			}
			else {
				if (Player == App->player) *attack = App->collision->AddCollider({ position.x + 4,(position.y - 30),65,20 }, COLLIDER_PLAYER_SHOT, App->player);
				else if (Player == App->player2) *attack = App->collision->AddCollider({ position.x + 4,(position.y - 30),65,20 }, COLLIDER_ENEMY_SHOT, App->player2);
			}
		}
		if (current_animation->GetFinished() == 1) {
			kick_timer = 3;
			(*attack)->to_delete = true;
		}
		break;
	case A_KICK_FORWARD_JUMP:
		current_animation = &App->player->kickair;
		if (flip == false) {
			body.SetPos(position.x + 10, (position.y - 60));
			body2.SetPos(position.x + 12, (position.y - 49));
			body3.SetPos(position.x + 15, (position.y - 35));
		}
		else {
			body.SetPos(position.x + 35, (position.y - 60));
			body2.SetPos(position.x + 42, (position.y - 49));
			body3.SetPos(position.x + 45, (position.y - 35));
		}
		if (position.y == 210) {
			App->audio->PlayChunk(App->player->jumpsound);
			mult = 2;
		}
		if (position.y <= 80) mult = -2;
		position.y -= speed * mult;
		if (flip == false) {
			if (stopright == false)	position.x += speed;
			if (App->player->stopleft == false && App->player2->stopleft == false) {
				if (App->background->cameraright.x < 670)App->render->camera.x -= speed;
			}
		}
		else {
			if (stopleft == false) position.x -= speed;
			if (App->player->stopright == false && App->player2->stopright == false) {
				if (App->background->cameraleft.x > 0)App->render->camera.x += speed;
			}
		}
		if (kick_timer == 1) {
			App->audio->PlayChunk(App->player->kicksound);
			kick_timer = 2;
			if (flip == false) {
				if (Player == App->player) *attack = App->collision->AddCollider({ position.x + 50,(position.y - 30),65,20 }, COLLIDER_PLAYER_SHOT, App->player);
				else if (Player == App->player2) *attack = App->collision->AddCollider({ position.x + 50,(position.y - 30),65,20 }, COLLIDER_ENEMY_SHOT, App->player2);
			}
			else {
				if (Player == App->player) *attack = App->collision->AddCollider({ position.x + 1,(position.y - 30),65,20 }, COLLIDER_PLAYER_SHOT, App->player);
				else if (Player == App->player2) *attack = App->collision->AddCollider({ position.x + 1,(position.y - 30),65,20 }, COLLIDER_ENEMY_SHOT, App->player2);
			}
		}
		if (current_animation->GetFinished() == 1) {
			kick_timer = 3;
			(*attack)->to_delete = true;
		}
		break;
	case A_KICK_BACKWARD_JUMP:
		current_animation = &App->player->kickair;
		if (flip == false) {
			body.SetPos(position.x + 10, (position.y - 60));
			body2.SetPos(position.x + 12, (position.y - 49));
			body3.SetPos(position.x + 15, (position.y - 35));
		}
		else {
			body.SetPos(position.x + 35, (position.y - 60));
			body2.SetPos(position.x + 42, (position.y - 49));
			body3.SetPos(position.x + 45, (position.y - 35));
		}
		if (position.y == 210) {
			App->audio->PlayChunk(App->player->jumpsound);
			mult = 2;
		}
		if (position.y <= 80) mult = -2;
		position.y -= speed * mult;
		if (flip == false) {
			if (stopleft == false) position.x -= speed / 2;
			if (App->player->stopright == false && App->player2->stopright == false) {
				if (App->background->cameraleft.x > 0) App->render->camera.x += speed;
			}
		}
		else {
			if (stopright == false)position.x += speed / 2;
			if (App->player->stopleft == false && App->player2->stopleft == false) {
				if (App->background->cameraright.x < 670) App->render->camera.x -= speed;
			}
		}
		if (kick_timer == 1) {
			App->audio->PlayChunk(App->player->kicksound);
			kick_timer = 2;
			if (flip == false) {
				if (Player == App->player) *attack = App->collision->AddCollider({ position.x + 30,(position.y - 30),65,20 }, COLLIDER_PLAYER_SHOT, App->player);
				else if (Player == App->player2) *attack = App->collision->AddCollider({ position.x + 30,(position.y - 30),65,20 }, COLLIDER_ENEMY_SHOT, App->player2);
			}
			else {
				if (Player == App->player) *attack = App->collision->AddCollider({ position.x + 1,(position.y - 30),65,20 }, COLLIDER_PLAYER_SHOT, App->player);
				else if (Player == App->player2) *attack = App->collision->AddCollider({ position.x + 1,(position.y - 30),65,20 }, COLLIDER_ENEMY_SHOT, App->player2);
			}
		}
		if (current_animation->GetFinished() == 1) {
			kick_timer = 3;
			(*attack)->to_delete = true;
		}
		break;
	case A_KICK_CROUCH:
		current_animation = &App->player->kickcrouch;
		if (flip == false) {
			body.SetPos(position.x + 15, (position.y - 65));
			body2.SetPos(position.x + 25, (position.y - 50));
			body3.SetPos(position.x + 12, (position.y - 35));
		}
		else {
			body.SetPos(position.x + 50, (position.y - 65));
			body2.SetPos(position.x + 67, (position.y - 50));
			body3.SetPos(position.x + 47, (position.y - 35));
		}

		if (kick_timer == 1) {
			App->audio->PlayChunk(App->player->kicksound);
			kick_timer = 2;
			if (flip == false) {
				if(Player== App->player) *attack = App->collision->AddCollider({ position.x + 25,(position.y - 30),75,30 }, COLLIDER_PLAYER_SHOT, App->player);
				else if(Player==App->player2) *attack = App->collision->AddCollider({ position.x + 25,(position.y - 30),75,30 }, COLLIDER_ENEMY_SHOT, App->player2);
			}
			if (flip == true) {
				if (Player == App->player) *attack = App->collision->AddCollider({ position.x + 1,(position.y - 30),75,30 }, COLLIDER_PLAYER_SHOT, App->player);
				else if (Player == App->player2) *attack = App->collision->AddCollider({ position.x + 1,(position.y - 30),75,30 }, COLLIDER_ENEMY_SHOT, App->player2);
				position.x -= 15;
			}
		}
		if (current_animation->GetFinished() == 1) {
			if (flip == true) {
				position.x += 15;
			}
			kick_timer = 3;
			(*attack)->to_delete = true;
		}
		break;
	case A_HITTED:
		current_animation = &App->player->hittedan;
		if (hitted_timer == 1 /*&& position.y == 210*/&&Player==App->player) {
			App->audio->PlayChunk(App->player->hittedsound);
			App->UI->DamageTaken(1, 5);
			hitted_timer = 2;
		}
		else if (hitted_timer == 1 /*&& position.y == 210*/ && Player == App->player2) {
			App->audio->PlayChunk(App->player->hittedsound);
			App->UI->DamageTaken(2, 5);
			hitted_timer = 2;
		}
		if (flip == false)position.x -= 1;
		else position.x += 1;
		if (position.y == 130) {
			mult = -1;
		}
		mult = -2;
		if (position.y < 210)position.y -= speed * mult*2;
		if (current_animation->GetFinished() == 1 && hitted_timer == 2)hitted_timer = 3;
		break;
	case A_TORNADO:
		current_animation = &App->player->tornado;
		if (tornado_timer == 1) {
			if(Player == App->player) App->particles->AddParticle(App->particles->tornado, position.x, position.y - 100, COLLIDER_PLAYER_SHOT, 0);
			else if(Player == App->player2) App->particles->AddParticle(App->particles->tornado, position.x, position.y - 100, COLLIDER_ENEMY_SHOT, 0);
			App->audio->PlayChunk(App->player->tornadosound);
			tornado_timer = 2;
		}
		if (current_animation->GetFinished() == 1)tornado_timer = 3;
		break;
	}
	return current_animation;
}
void CheckState(int& jump_timer, int& punch_timer, int& kick_timer, int &tornado_timer, int &inputsouts, state& actual, inputin inputstate[60], inputout inputstateout[INPUTSOUTS]) {
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
		case S_T_CROUCH_LEFT: actual = A_PUNCH_CROUCH; punch_timer = 1; break;
		case S_R: actual = A_PUNCHL_STANDING; punch_timer = 1;  break;
		case S_R_LEFT: actual = A_PUNCHL_STANDING; punch_timer = 1;  break;
		case S_R_RIGHT: actual = A_PUNCHL_STANDING; punch_timer = 1;  break;
		case S_R_JUMP: actual = A_PUNCHL_NEUTRAL_JUMP; jump_timer = SDL_GetTicks(); punch_timer = 1;  break;
		case S_R_JUMP_RIGHT:actual = A_PUNCHL_FORWARD_JUMP; jump_timer = SDL_GetTicks(); punch_timer = 1; break;
		case S_R_JUMP_LEFT:actual = A_PUNCHL_BACKWARD_JUMP; jump_timer = SDL_GetTicks(); punch_timer = 1; break;
		case S_R_CROUCH: actual = A_PUNCHL_CROUCH; punch_timer = 1; break;
		case S_R_CROUCH_RIGHT: actual = A_PUNCHL_CROUCH; punch_timer = 1; break;
		case S_R_CROUCH_LEFT: actual = A_PUNCHL_CROUCH; punch_timer = 1; break;
		case S_TR: actual = A_PUNCHS_STANDING; punch_timer = 1;  break;
		case S_TR_LEFT: actual = A_PUNCHS_STANDING; punch_timer = 1;  break;
		case S_TR_RIGHT: actual = A_PUNCHS_STANDING; punch_timer = 1;  break;
		case S_TR_JUMP: actual = A_PUNCHS_NEUTRAL_JUMP; jump_timer = SDL_GetTicks(); punch_timer = 1;  break;
		case S_TR_JUMP_RIGHT:actual = A_PUNCHS_FORWARD_JUMP; jump_timer = SDL_GetTicks(); punch_timer = 1; break;
		case S_TR_JUMP_LEFT:actual = A_PUNCHS_BACKWARD_JUMP; jump_timer = SDL_GetTicks(); punch_timer = 1; break;
		case S_TR_CROUCH: actual = A_PUNCHS_CROUCH; punch_timer = 1; break;
		case S_TR_CROUCH_RIGHT: actual = A_PUNCHS_CROUCH; punch_timer = 1; break;
		case S_TR_CROUCH_LEFT: actual = A_PUNCHS_CROUCH; punch_timer = 1; break;
		case S_Y: actual = A_KICKL_STANDING; kick_timer = 1;  break;
		case S_Y_LEFT: actual = A_KICKL_STANDING; kick_timer = 1;  break;
		case S_Y_RIGHT: actual = A_KICKL_STANDING; kick_timer = 1; break;
		case S_Y_JUMP: actual = A_KICKL_NEUTRAL_JUMP; jump_timer = SDL_GetTicks(); kick_timer = 1;  break;
		case S_Y_JUMP_RIGHT:actual = A_KICKL_FORWARD_JUMP; jump_timer = SDL_GetTicks(); kick_timer = 1; break;
		case S_Y_JUMP_LEFT:actual = A_KICKL_BACKWARD_JUMP; jump_timer = SDL_GetTicks(); kick_timer = 1; break;
		case S_Y_CROUCH: actual = A_KICKL_CROUCH; kick_timer = 1; break;
		case S_Y_CROUCH_RIGHT: actual = A_KICKL_CROUCH; kick_timer = 1; break;
		case S_Y_CROUCH_LEFT: actual = A_KICKL_CROUCH; kick_timer = 1; break;
		case S_U: actual = A_KICK_STANDING; kick_timer = 1;  break;
		case S_U_LEFT: actual = A_KICK_STANDING; kick_timer = 1;  break;
		case S_U_RIGHT: actual = A_KICK_STANDING; kick_timer = 1; break;
		case S_U_JUMP: actual = A_KICK_NEUTRAL_JUMP; jump_timer = SDL_GetTicks(); kick_timer = 1;  break;
		case S_U_JUMP_RIGHT:actual = A_KICK_FORWARD_JUMP; jump_timer = SDL_GetTicks(); kick_timer = 1; break;
		case S_U_JUMP_LEFT:actual = A_KICK_BACKWARD_JUMP; jump_timer = SDL_GetTicks(); kick_timer = 1; break;
		case S_U_CROUCH: actual = A_KICK_CROUCH; kick_timer = 1; break;
		case S_U_CROUCH_RIGHT: actual = A_KICK_CROUCH; kick_timer = 1; break;
		case S_U_CROUCH_LEFT: actual = A_KICK_CROUCH; kick_timer = 1; break;
		case S_YU: actual = A_KICKS_STANDING; kick_timer = 1;  break;
		case S_YU_LEFT: actual = A_KICKS_STANDING; kick_timer = 1;  break;
		case S_YU_RIGHT: actual = A_KICKS_STANDING; kick_timer = 1; break;
		case S_YU_JUMP: actual = A_KICKS_NEUTRAL_JUMP; jump_timer = SDL_GetTicks(); kick_timer = 1;  break;
		case S_YU_JUMP_RIGHT:actual = A_KICKS_FORWARD_JUMP; jump_timer = SDL_GetTicks(); kick_timer = 1; break;
		case S_YU_JUMP_LEFT:actual = A_KICKS_BACKWARD_JUMP; jump_timer = SDL_GetTicks(); kick_timer = 1; break;
		case S_YU_CROUCH: actual = A_KICKS_CROUCH; kick_timer = 1; break;
		case S_YU_CROUCH_RIGHT: actual = A_KICKS_CROUCH; kick_timer = 1; break;
		case S_YU_CROUCH_LEFT: actual = A_KICKS_CROUCH; kick_timer = 1; break;
		case S_TORNADO: actual = A_TORNADO; tornado_timer = 1; break;
		}
		break;
	case A_WALK_FORWARD:
		switch (inputstate[0]) {
		case S_LEFT_AND_RIGHT: actual = A_IDLE; break;
		case S_LEFT_DOWN:actual = A_IDLE; break;
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
		case S_T_CROUCH_LEFT: actual = A_PUNCH_CROUCH; punch_timer = 1; break;
		case S_R: actual = A_PUNCHL_STANDING; punch_timer = 1;  break;
		case S_R_LEFT: actual = A_PUNCHL_STANDING; punch_timer = 1;  break;
		case S_R_RIGHT: actual = A_PUNCHL_STANDING; punch_timer = 1;  break;
		case S_R_JUMP: actual = A_PUNCHL_NEUTRAL_JUMP; jump_timer = SDL_GetTicks(); punch_timer = 1;  break;
		case S_R_JUMP_RIGHT:actual = A_PUNCHL_FORWARD_JUMP; jump_timer = SDL_GetTicks(); punch_timer = 1; break;
		case S_R_JUMP_LEFT:actual = A_PUNCHL_BACKWARD_JUMP; jump_timer = SDL_GetTicks(); punch_timer = 1; break;
		case S_R_CROUCH: actual = A_PUNCHL_CROUCH; punch_timer = 1; break;
		case S_R_CROUCH_RIGHT: actual = A_PUNCHL_CROUCH; punch_timer = 1; break;
		case S_R_CROUCH_LEFT: actual = A_PUNCHL_CROUCH; punch_timer = 1; break;
		case S_TR: actual = A_PUNCHS_STANDING; punch_timer = 1;  break;
		case S_TR_LEFT: actual = A_PUNCHS_STANDING; punch_timer = 1;  break;
		case S_TR_RIGHT: actual = A_PUNCHS_STANDING; punch_timer = 1;  break;
		case S_TR_JUMP: actual = A_PUNCHS_NEUTRAL_JUMP; jump_timer = SDL_GetTicks(); punch_timer = 1;  break;
		case S_TR_JUMP_RIGHT:actual = A_PUNCHS_FORWARD_JUMP; jump_timer = SDL_GetTicks(); punch_timer = 1; break;
		case S_TR_JUMP_LEFT:actual = A_PUNCHS_BACKWARD_JUMP; jump_timer = SDL_GetTicks(); punch_timer = 1; break;
		case S_TR_CROUCH: actual = A_PUNCHS_CROUCH; punch_timer = 1; break;
		case S_TR_CROUCH_RIGHT: actual = A_PUNCHS_CROUCH; punch_timer = 1; break;
		case S_TR_CROUCH_LEFT: actual = A_PUNCHS_CROUCH; punch_timer = 1; break;
		case S_Y: actual = A_KICKL_STANDING; kick_timer = 1;  break;
		case S_Y_LEFT: actual = A_KICKL_STANDING; kick_timer = 1;  break;
		case S_Y_RIGHT: actual = A_KICKL_STANDING; kick_timer = 1; break;
		case S_Y_JUMP: actual = A_KICKL_NEUTRAL_JUMP; jump_timer = SDL_GetTicks(); kick_timer = 1;  break;
		case S_Y_JUMP_RIGHT:actual = A_KICKL_FORWARD_JUMP; jump_timer = SDL_GetTicks(); kick_timer = 1; break;
		case S_Y_JUMP_LEFT:actual = A_KICKL_BACKWARD_JUMP; jump_timer = SDL_GetTicks(); kick_timer = 1; break;
		case S_Y_CROUCH: actual = A_KICKL_CROUCH; kick_timer = 1; break;
		case S_Y_CROUCH_RIGHT: actual = A_KICKL_CROUCH; kick_timer = 1; break;
		case S_Y_CROUCH_LEFT: actual = A_KICKL_CROUCH; kick_timer = 1; break;
		case S_U: actual = A_KICK_STANDING; kick_timer = 1;  break;
		case S_U_LEFT: actual = A_KICK_STANDING; kick_timer = 1;  break;
		case S_U_RIGHT: actual = A_KICK_STANDING; kick_timer = 1; break;
		case S_U_JUMP: actual = A_KICK_NEUTRAL_JUMP; jump_timer = SDL_GetTicks(); kick_timer = 1;  break;
		case S_U_JUMP_RIGHT:actual = A_KICK_FORWARD_JUMP; jump_timer = SDL_GetTicks(); kick_timer = 1; break;
		case S_U_JUMP_LEFT:actual = A_KICK_BACKWARD_JUMP; jump_timer = SDL_GetTicks(); kick_timer = 1; break;
		case S_U_CROUCH: actual = A_KICK_CROUCH; kick_timer = 1; break;
		case S_U_CROUCH_RIGHT: actual = A_KICK_CROUCH; kick_timer = 1; break;
		case S_U_CROUCH_LEFT: actual = A_KICK_CROUCH; kick_timer = 1; break;
		case S_YU: actual = A_KICKS_STANDING; kick_timer = 1;  break;
		case S_YU_LEFT: actual = A_KICKS_STANDING; kick_timer = 1;  break;
		case S_YU_RIGHT: actual = A_KICKS_STANDING; kick_timer = 1; break;
		case S_YU_JUMP: actual = A_KICKS_NEUTRAL_JUMP; jump_timer = SDL_GetTicks(); kick_timer = 1;  break;
		case S_YU_JUMP_RIGHT:actual = A_KICKS_FORWARD_JUMP; jump_timer = SDL_GetTicks(); kick_timer = 1; break;
		case S_YU_JUMP_LEFT:actual = A_KICKS_BACKWARD_JUMP; jump_timer = SDL_GetTicks(); kick_timer = 1; break;
		case S_YU_CROUCH: actual = A_KICKS_CROUCH; kick_timer = 1; break;
		case S_YU_CROUCH_RIGHT: actual = A_KICKS_CROUCH; kick_timer = 1; break;
		case S_YU_CROUCH_LEFT: actual = A_KICKS_CROUCH; kick_timer = 1; break;
		case S_TORNADO: actual = A_TORNADO; tornado_timer = 1; break;
		}
		for (int i = 0; i <= inputsouts; i++)if (inputstateout[i] == SO_RIGHT_UP)actual = A_IDLE;
		break;
	case A_WALK_BACKWARD:
		switch (inputstate[0]) {
		case S_LEFT_AND_RIGHT: actual = A_IDLE; break;
		case S_RIGHT_DOWN:actual = A_IDLE; break;
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
		case S_R: actual = A_PUNCHL_STANDING; punch_timer = 1;  break;
		case S_R_LEFT: actual = A_PUNCHL_STANDING; punch_timer = 1;  break;
		case S_R_RIGHT: actual = A_PUNCHL_STANDING; punch_timer = 1;  break;
		case S_R_JUMP: actual = A_PUNCHL_NEUTRAL_JUMP; jump_timer = SDL_GetTicks(); punch_timer = 1;  break;
		case S_R_JUMP_RIGHT:actual = A_PUNCHL_FORWARD_JUMP; jump_timer = SDL_GetTicks(); punch_timer = 1; break;
		case S_R_JUMP_LEFT:actual = A_PUNCHL_BACKWARD_JUMP; jump_timer = SDL_GetTicks(); punch_timer = 1; break;
		case S_R_CROUCH: actual = A_PUNCHL_CROUCH; punch_timer = 1; break;
		case S_R_CROUCH_RIGHT: actual = A_PUNCHL_CROUCH; punch_timer = 1; break;
		case S_R_CROUCH_LEFT: actual = A_PUNCHL_CROUCH; punch_timer = 1; break;
		case S_TR: actual = A_PUNCHS_STANDING; punch_timer = 1;  break;
		case S_TR_LEFT: actual = A_PUNCHS_STANDING; punch_timer = 1;  break;
		case S_TR_RIGHT: actual = A_PUNCHS_STANDING; punch_timer = 1;  break;
		case S_TR_JUMP: actual = A_PUNCHS_NEUTRAL_JUMP; jump_timer = SDL_GetTicks(); punch_timer = 1;  break;
		case S_TR_JUMP_RIGHT:actual = A_PUNCHS_FORWARD_JUMP; jump_timer = SDL_GetTicks(); punch_timer = 1; break;
		case S_TR_JUMP_LEFT:actual = A_PUNCHS_BACKWARD_JUMP; jump_timer = SDL_GetTicks(); punch_timer = 1; break;
		case S_TR_CROUCH: actual = A_PUNCHS_CROUCH; punch_timer = 1; break;
		case S_TR_CROUCH_RIGHT: actual = A_PUNCHS_CROUCH; punch_timer = 1; break;
		case S_TR_CROUCH_LEFT: actual = A_PUNCHS_CROUCH; punch_timer = 1; break;
		case S_Y: actual = A_KICKL_STANDING; kick_timer = 1;  break;
		case S_Y_LEFT: actual = A_KICKL_STANDING; kick_timer = 1;  break;
		case S_Y_RIGHT: actual = A_KICKL_STANDING; kick_timer = 1; break;
		case S_Y_JUMP: actual = A_KICKL_NEUTRAL_JUMP; jump_timer = SDL_GetTicks(); kick_timer = 1;  break;
		case S_Y_JUMP_RIGHT:actual = A_KICKL_FORWARD_JUMP; jump_timer = SDL_GetTicks(); kick_timer = 1; break;
		case S_Y_JUMP_LEFT:actual = A_KICKL_BACKWARD_JUMP; jump_timer = SDL_GetTicks(); kick_timer = 1; break;
		case S_Y_CROUCH: actual = A_KICKL_CROUCH; kick_timer = 1; break;
		case S_Y_CROUCH_RIGHT: actual = A_KICKL_CROUCH; kick_timer = 1; break;
		case S_Y_CROUCH_LEFT: actual = A_KICKL_CROUCH; kick_timer = 1; break;
		case S_U: actual = A_KICK_STANDING; kick_timer = 1;  break;
		case S_U_LEFT: actual = A_KICK_STANDING; kick_timer = 1;  break;
		case S_U_RIGHT: actual = A_KICK_STANDING; kick_timer = 1; break;
		case S_U_JUMP: actual = A_KICK_NEUTRAL_JUMP; jump_timer = SDL_GetTicks(); kick_timer = 1;  break;
		case S_U_JUMP_RIGHT:actual = A_KICK_FORWARD_JUMP; jump_timer = SDL_GetTicks(); kick_timer = 1; break;
		case S_U_JUMP_LEFT:actual = A_KICK_BACKWARD_JUMP; jump_timer = SDL_GetTicks(); kick_timer = 1; break;
		case S_U_CROUCH: actual = A_KICK_CROUCH; kick_timer = 1; break;
		case S_U_CROUCH_RIGHT: actual = A_KICK_CROUCH; kick_timer = 1; break;
		case S_U_CROUCH_LEFT: actual = A_KICK_CROUCH; kick_timer = 1; break;
		case S_YU: actual = A_KICKS_STANDING; kick_timer = 1;  break;
		case S_YU_LEFT: actual = A_KICKS_STANDING; kick_timer = 1;  break;
		case S_YU_RIGHT: actual = A_KICKS_STANDING; kick_timer = 1; break;
		case S_YU_JUMP: actual = A_KICKS_NEUTRAL_JUMP; jump_timer = SDL_GetTicks(); kick_timer = 1;  break;
		case S_YU_JUMP_RIGHT:actual = A_KICKS_FORWARD_JUMP; jump_timer = SDL_GetTicks(); kick_timer = 1; break;
		case S_YU_JUMP_LEFT:actual = A_KICKS_BACKWARD_JUMP; jump_timer = SDL_GetTicks(); kick_timer = 1; break;
		case S_YU_CROUCH: actual = A_KICKS_CROUCH; kick_timer = 1; break;
		case S_YU_CROUCH_RIGHT: actual = A_KICKS_CROUCH; kick_timer = 1; break;
		case S_YU_CROUCH_LEFT: actual = A_KICKS_CROUCH; kick_timer = 1; break;
		case S_TORNADO: actual = A_TORNADO; tornado_timer = 1; break;
		}
		for (int i = 0; i <= inputsouts; i++)if (inputstateout[i] == SO_LEFT_UP)actual = A_IDLE;
		break;
	case A_JUMP_NEUTRAL:
		switch (inputstate[0]) {
		case S_T: actual = A_PUNCH_NEUTRAL_JUMP; punch_timer = 1;  break;
		case S_T_LEFT: actual = A_PUNCH_NEUTRAL_JUMP; punch_timer = 1;  break;
		case S_T_RIGHT: actual = A_PUNCH_NEUTRAL_JUMP; punch_timer = 1;  break;
		case S_T_JUMP: actual = A_PUNCH_NEUTRAL_JUMP; punch_timer = 1;  break;
		case S_T_JUMP_RIGHT:actual = A_PUNCH_NEUTRAL_JUMP; punch_timer = 1; break;
		case S_T_JUMP_LEFT:actual = A_PUNCH_NEUTRAL_JUMP; punch_timer = 1; break;
		case S_T_CROUCH: actual = A_PUNCH_NEUTRAL_JUMP; punch_timer = 1; break;
		case S_T_CROUCH_RIGHT: actual = A_PUNCH_NEUTRAL_JUMP; punch_timer = 1; break;
		case S_T_CROUCH_LEFT: actual = A_PUNCH_NEUTRAL_JUMP; punch_timer = 1; break;
		case S_R: actual = A_PUNCHL_NEUTRAL_JUMP; punch_timer = 1;  break;
		case S_R_LEFT: actual = A_PUNCHL_NEUTRAL_JUMP; punch_timer = 1;  break;
		case S_R_RIGHT: actual = A_PUNCHL_NEUTRAL_JUMP; punch_timer = 1;  break;
		case S_R_JUMP: actual = A_PUNCHL_NEUTRAL_JUMP; punch_timer = 1;  break;
		case S_R_JUMP_RIGHT:actual = A_PUNCHL_NEUTRAL_JUMP; punch_timer = 1; break;
		case S_R_JUMP_LEFT:actual = A_PUNCHL_NEUTRAL_JUMP; punch_timer = 1; break;
		case S_R_CROUCH: actual = A_PUNCHL_NEUTRAL_JUMP; punch_timer = 1; break;
		case S_R_CROUCH_RIGHT: actual = A_PUNCHL_NEUTRAL_JUMP; punch_timer = 1; break;
		case S_R_CROUCH_LEFT: actual = A_PUNCHL_NEUTRAL_JUMP; punch_timer = 1; break;
		case S_TR: actual = A_PUNCHS_NEUTRAL_JUMP; punch_timer = 1;  break;
		case S_TR_LEFT: actual = A_PUNCHS_NEUTRAL_JUMP; punch_timer = 1;  break;
		case S_TR_RIGHT: actual = A_PUNCHS_NEUTRAL_JUMP; punch_timer = 1;  break;
		case S_TR_JUMP: actual = A_PUNCHS_NEUTRAL_JUMP; punch_timer = 1;  break;
		case S_TR_JUMP_RIGHT:actual = A_PUNCHS_NEUTRAL_JUMP; punch_timer = 1; break;
		case S_TR_JUMP_LEFT:actual = A_PUNCHS_NEUTRAL_JUMP; punch_timer = 1; break;
		case S_TR_CROUCH: actual = A_PUNCHS_NEUTRAL_JUMP; punch_timer = 1; break;
		case S_TR_CROUCH_RIGHT: actual = A_PUNCHS_NEUTRAL_JUMP; punch_timer = 1; break;
		case S_TR_CROUCH_LEFT: actual = A_PUNCHS_NEUTRAL_JUMP; punch_timer = 1; break;
		case S_Y: actual = A_KICKL_NEUTRAL_JUMP; kick_timer = 1;  break;
		case S_Y_LEFT: actual = A_KICKL_NEUTRAL_JUMP; kick_timer = 1;  break;
		case S_Y_RIGHT: actual = A_KICKL_NEUTRAL_JUMP; kick_timer = 1; break;
		case S_Y_JUMP: actual = A_KICKL_NEUTRAL_JUMP; kick_timer = 1;  break;
		case S_Y_JUMP_RIGHT:actual = A_KICKL_NEUTRAL_JUMP; kick_timer = 1; break;
		case S_Y_JUMP_LEFT:actual = A_KICKL_NEUTRAL_JUMP; kick_timer = 1; break;
		case S_Y_CROUCH: actual = A_KICKL_NEUTRAL_JUMP; kick_timer = 1; break;
		case S_Y_CROUCH_RIGHT: actual = A_KICKL_NEUTRAL_JUMP; kick_timer = 1; break;
		case S_Y_CROUCH_LEFT: actual = A_KICKL_NEUTRAL_JUMP; kick_timer = 1; break;
		case S_U: actual = A_KICK_NEUTRAL_JUMP; kick_timer = 1;  break;
		case S_U_LEFT: actual = A_KICK_NEUTRAL_JUMP; kick_timer = 1;  break;
		case S_U_RIGHT: actual = A_KICK_NEUTRAL_JUMP; kick_timer = 1; break;
		case S_U_JUMP: actual = A_KICK_NEUTRAL_JUMP; kick_timer = 1;  break;
		case S_U_JUMP_RIGHT:actual = A_KICK_NEUTRAL_JUMP; kick_timer = 1; break;
		case S_U_JUMP_LEFT:actual = A_KICK_NEUTRAL_JUMP; kick_timer = 1; break;
		case S_U_CROUCH: actual = A_KICK_NEUTRAL_JUMP; kick_timer = 1; break;
		case S_U_CROUCH_RIGHT: actual = A_KICK_NEUTRAL_JUMP; kick_timer = 1; break;
		case S_U_CROUCH_LEFT: actual = A_KICK_NEUTRAL_JUMP; kick_timer = 1; break;
		case S_YU: actual = A_KICKS_NEUTRAL_JUMP; kick_timer = 1;  break;
		case S_YU_LEFT: actual = A_KICKS_NEUTRAL_JUMP; kick_timer = 1;  break;
		case S_YU_RIGHT: actual = A_KICKS_NEUTRAL_JUMP; kick_timer = 1; break;
		case S_YU_JUMP: actual = A_KICKS_NEUTRAL_JUMP; kick_timer = 1;  break;
		case S_YU_JUMP_RIGHT:actual = A_KICKS_NEUTRAL_JUMP; kick_timer = 1; break;
		case S_YU_JUMP_LEFT:actual = A_KICKS_NEUTRAL_JUMP; kick_timer = 1; break;
		case S_YU_CROUCH: actual = A_KICKS_NEUTRAL_JUMP; kick_timer = 1; break;
		case S_YU_CROUCH_RIGHT: actual = A_KICKS_NEUTRAL_JUMP; kick_timer = 1; break;
		case S_YU_CROUCH_LEFT: actual = A_KICKS_NEUTRAL_JUMP; kick_timer = 1; break;

		}
		for (int i = 0; i <= inputsouts; i++)if (inputstateout[i] == SO_JUMP_FINISH)actual = A_IDLE;
		break;
	case A_JUMP_FORWARD:
		switch (inputstate[0]) {
		case S_T: actual = A_PUNCH_FORWARD_JUMP; punch_timer = 1;  break;
		case S_T_LEFT: actual = A_PUNCH_FORWARD_JUMP; punch_timer = 1;  break;
		case S_T_RIGHT: actual = A_PUNCH_FORWARD_JUMP; punch_timer = 1;  break;
		case S_T_JUMP: actual = A_PUNCH_FORWARD_JUMP; punch_timer = 1;  break;
		case S_T_JUMP_RIGHT:actual = A_PUNCH_FORWARD_JUMP; punch_timer = 1; break;
		case S_T_JUMP_LEFT:actual = A_PUNCH_FORWARD_JUMP; punch_timer = 1; break;
		case S_T_CROUCH: actual = A_PUNCH_FORWARD_JUMP; punch_timer = 1; break;
		case S_T_CROUCH_RIGHT: actual = A_PUNCH_FORWARD_JUMP; punch_timer = 1; break;
		case S_T_CROUCH_LEFT: actual = A_PUNCH_NEUTRAL_JUMP; punch_timer = 1; break;
		case S_R: actual = A_PUNCHL_NEUTRAL_JUMP; punch_timer = 1;  break;
		case S_R_LEFT: actual = A_PUNCHL_NEUTRAL_JUMP; punch_timer = 1;  break;
		case S_R_RIGHT: actual = A_PUNCHL_NEUTRAL_JUMP; punch_timer = 1;  break;
		case S_R_JUMP: actual = A_PUNCHL_NEUTRAL_JUMP; punch_timer = 1;  break;
		case S_R_JUMP_RIGHT:actual = A_PUNCHL_NEUTRAL_JUMP; punch_timer = 1; break;
		case S_R_JUMP_LEFT:actual = A_PUNCHL_NEUTRAL_JUMP; punch_timer = 1; break;
		case S_R_CROUCH: actual = A_PUNCHL_NEUTRAL_JUMP; punch_timer = 1; break;
		case S_R_CROUCH_RIGHT: actual = A_PUNCHL_NEUTRAL_JUMP; punch_timer = 1; break;
		case S_R_CROUCH_LEFT: actual = A_PUNCHL_NEUTRAL_JUMP; punch_timer = 1; break;
		case S_TR: actual = A_PUNCHS_NEUTRAL_JUMP; punch_timer = 1;  break;
		case S_TR_LEFT: actual = A_PUNCHS_NEUTRAL_JUMP; punch_timer = 1;  break;
		case S_TR_RIGHT: actual = A_PUNCHS_NEUTRAL_JUMP; punch_timer = 1;  break;
		case S_TR_JUMP: actual = A_PUNCHS_NEUTRAL_JUMP; punch_timer = 1;  break;
		case S_TR_JUMP_RIGHT:actual = A_PUNCHS_NEUTRAL_JUMP; punch_timer = 1; break;
		case S_TR_JUMP_LEFT:actual = A_PUNCHS_NEUTRAL_JUMP; punch_timer = 1; break;
		case S_TR_CROUCH: actual = A_PUNCHS_NEUTRAL_JUMP; punch_timer = 1; break;
		case S_TR_CROUCH_RIGHT: actual = A_PUNCHS_NEUTRAL_JUMP; punch_timer = 1; break;
		case S_TR_CROUCH_LEFT: actual = A_PUNCHS_NEUTRAL_JUMP; punch_timer = 1; break;
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
		}
		for (int i = 0; i <= inputsouts; i++)if (inputstateout[i] == SO_PUNCH_FINISH)actual = A_IDLE;
		break;
	case A_PUNCH_NEUTRAL_JUMP:
		for (int i = 0; i <= inputsouts; i++)if (inputstateout[i] == SO_JUMP_FINISH) {
			actual = A_IDLE;
		}
		for (int i = 0; i <= inputsouts; i++)if (inputstateout[i] == SO_PUNCH_FINISH)actual = A_JUMP_NEUTRAL;
		break;
	case A_PUNCH_FORWARD_JUMP:
		for (int i = 0; i <= inputsouts; i++)if (inputstateout[i] == SO_JUMP_FINISH)actual = A_IDLE;
		for (int i = 0; i <= inputsouts; i++)if (inputstateout[i] == SO_PUNCH_FINISH)actual = A_JUMP_FORWARD;
		break;
	case A_PUNCH_BACKWARD_JUMP:
		for (int i = 0; i <= inputsouts; i++)if (inputstateout[i] == SO_JUMP_FINISH)actual = A_IDLE;
		for (int i = 0; i <= inputsouts; i++)if (inputstateout[i] == SO_PUNCH_FINISH)actual = A_JUMP_BACKWARD;
		break;
	case A_KICK_STANDING:
		for (int i = 0; i <= inputsouts; i++)if (inputstateout[i] == SO_KICK_FINISH)actual = A_IDLE;
		break;
	case A_KICK_NEUTRAL_JUMP:
		for (int i = 0; i <= inputsouts; i++)if (inputstateout[i] == SO_JUMP_FINISH)actual = A_IDLE;
		for (int i = 0; i <= inputsouts; i++)if (inputstateout[i] == SO_KICK_FINISH)actual = A_JUMP_NEUTRAL;
		break;
	case A_KICK_FORWARD_JUMP:
		for (int i = 0; i <= inputsouts; i++)if (inputstateout[i] == SO_JUMP_FINISH)actual = A_IDLE;
		for (int i = 0; i <= inputsouts; i++)if (inputstateout[i] == SO_KICK_FINISH)actual = A_JUMP_FORWARD;
		break;
	case A_KICK_BACKWARD_JUMP:
		for (int i = 0; i <= inputsouts; i++)if (inputstateout[i] == SO_JUMP_FINISH)actual = A_IDLE;
		for (int i = 0; i <= inputsouts; i++)if (inputstateout[i] == SO_KICK_FINISH)actual = A_JUMP_BACKWARD;
		break;
	case A_CROUCH:
		switch (inputstate[0]) {
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
		for (int i = 0; i <= inputsouts; i++)if (inputstateout[i] == SO_PUNCH_FINISH) {
			if (inputstate[0] == S_CROUCH_DOWN || inputstate[0] == S_CROUCH_RIGHT)actual = A_CROUCH;
			else actual = A_IDLE;
		}
		break;
	case A_KICK_CROUCH:
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
void CheckSpecialAttacks(inputin inputstate[60]) {
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
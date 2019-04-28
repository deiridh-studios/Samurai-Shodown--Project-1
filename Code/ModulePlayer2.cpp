#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModulePlayer2.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "Modulebackground.h"
#include "SDL/include/SDL_timer.h"

ModulePlayer2::ModulePlayer2()
{
	position.x = 200;
	position.y = 210;

	// Idle animation
	idle.PushBack({ 3406, 530, 79, 123 });
	idle.PushBack({ 3324, 530, 79, 123 });
	idle.PushBack({ 3243, 530, 79, 123 });
	idle.PushBack({ 3406, 653, 79, 123 });
	idle.PushBack({ 3324, 653, 79, 123 });
	idle.PushBack({ 3243, 653, 79, 123 });
	idle.speed = 0.2f;

	// Walk forward animation (To IMPROVE)
	forward.PushBack({ 2409 , 1298 , 75 , 118 });
	forward.PushBack({ 2482 , 1288 , 60 , 123 });
	forward.PushBack({ 2543 , 1293 , 70 , 129 });
	forward.PushBack({ 2620 , 1298 , 81 , 116 });
	forward.speed = 0.2f;

	// Walk backwards animation (To Do)
	backward.PushBack({ 2615 , 1298 , 81 , 116 });
	backward.PushBack({ 2543 , 1293 , 70 , 129 });
	backward.PushBack({ 2482, 1290 , 60 , 123 });
	backward.PushBack({ 2409 , 1298 , 75 , 118 });
	backward.speed = 0.1f;

	// Kick animation
	kick.PushBack({ 2545, 133, 80, 105 });
	kick.PushBack({ 2459, 133, 81, 102 });
	kick.PushBack({ 2359, 133, 99, 108 });
	kick.PushBack({ 2250, 133, 110, 98 });
	kick.PushBack({ 2459, 133, 81, 102 });
	kick.PushBack({ 2545, 133, 80, 105 });
	kick.PushBack({ 2545, 133, 80, 105 });
	kick.speed = 0.2f;
	
	//crouch
	//crouch.PushBack({ 898 , 1831 , 137 , 104 });
	crouch.PushBack({ 898 , 1831 , 137 , 104 });

	// Punch animation (TO IMPROVE)
	punch.PushBack({ 3368 , 1388 , 83 , 124 });
	punch.PushBack({ 3296 , 1372 , 78 , 137 });
	punch.PushBack({ 3211 , 1398 , 84 , 114 });
	punch.PushBack({ 3078 , 1398 , 134 , 113 });
	punch.PushBack({ 2941 , 1401 , 133 , 108 });
	punch.PushBack({ 2801 , 1406 , 135 , 105 });
	punch.PushBack({ 3327 , 1656 , 138 , 106 });
	punch.PushBack({ 3186 , 1656 , 138 , 106 });
	punch.PushBack({ 3058 , 1656 , 132 , 106 });
	punch.PushBack({ 2920 , 1637 , 139 , 112 });
	punch.PushBack({ 2680 , 1657 , 147 , 100 });
	punch.speed = 0.2f;

	// Jump
	jump.PushBack({ 3234 , 775 , 78 , 116 });
	jump.PushBack({ 3234 , 775 , 78 , 116 });
	jump.PushBack({ 3138 , 791 , 91 , 100 });
	jump.PushBack({ 3046 , 804 , 84 , 88 });
	jump.PushBack({ 3046 , 804 , 84 , 88 });
	jump.PushBack({ 3138 , 791 , 91 , 100 });
	jump.PushBack({ 3138 , 791 , 91 , 100 });
	jump.PushBack({ 3138 , 791 , 91 , 100 });
	jump.speed = 0.1f;
}

ModulePlayer2::~ModulePlayer2()
{}


// Load assets
bool ModulePlayer2::Start()
{
	LOG("Loading player textures");
	bool ret = true;
	graphics = App->textures->Load("Sprites/spritesHaohmaru.png"); // arcade version
	punchsound = App->audio->LoadChunk("Audio_FX/Punch.wav");
	kicksound = App->audio->LoadChunk("Audio_FX/Kick.wav");
	jumpsound = App->audio->LoadChunk("Audio_FX/Jump.wav");
	hitted = App->audio->LoadChunk("Audio_FX/Hitted.wav");
	position.x = 200;
	position.y = 210;
	bodyenemy = App->collision->AddCollider({ position.x,(position.y - 100),35,20 }, COLLIDER_ENEMY, this);
	bodyenemy2 = App->collision->AddCollider({ position.x,(position.y - 50),25,15 }, COLLIDER_ENEMY, this);
	bodyenemy3 = App->collision->AddCollider({ position.x,(position.y - 20),45,35 }, COLLIDER_ENEMY, this);
	actual = NONE;
	actual3 = A_IDLE;
	right = false;
	left = false;
	victory = false;
	for (int i = 0; i < 60; i++) inputstate2[i] = S_NONE;
	for (int i = 0; i < 6; i++)inputstateout2[i] = SO_NONE;
	jump_timer = 0;
	punch_timer = 0;
	kick_timer = 0;
	tornado_timer = 0;
	inputsouts = 0;
	return ret;
}

//Clean Up
bool ModulePlayer2::CleanUp() {
	App->textures->Unload(graphics);
	App->audio->StopChunk();
	App->audio->UnLoadChunk(punchsound);
	App->audio->UnLoadChunk(kicksound);
	App->audio->UnLoadChunk(jumpsound);
	App->audio->UnLoadChunk(hitted);
	return true;
}

update_status ModulePlayer2::PreUpdate() {
	for (int i = 59; i > 0; i--)inputstate2[i] = inputstate2[i - 1];

	for (int i = 0; i < INPUTSOUTS; i++) inputstateout2[i] = SO_NONE;
	inputsouts = 0;

	//CHECK LEFT AND RIGHT//
	bool left = false;
	bool right = false;
	if (App->input->keyboardstate[SDL_SCANCODE_RIGHT] == KEY_PUSHED || App->input->keyboardstate[SDL_SCANCODE_RIGHT] == KEY_REPEAT)right = true;
	if (App->input->keyboardstate[SDL_SCANCODE_LEFT] == KEY_PUSHED || App->input->keyboardstate[SDL_SCANCODE_LEFT] == KEY_REPEAT)left = true;
	if (right == true && left == true)inputstate2[0] = S_LEFT_AND_RIGHT;
	else if (right == true)inputstate2[0] = S_LEFT_DOWN;//App->input->keyboardstate[SDL_SCANCODE_D] == KEY_PUSHED) {inputstate[0] = S_RIGHT_DOWN; LOG("RIGHT_DOWN\n");}
	else if (App->input->keyboardstate[SDL_SCANCODE_RIGHT] == KEY_PULLED) {
		inputstateout2[inputsouts] = SO_LEFT_UP;
		if (inputstate2[0] == S_LEFT_DOWN)inputstate2[0] = S_NONE;
		inputsouts++;
	}
	else if (left == true)/*(App->input->keyboardstate[SDL_SCANCODE_A] == KEY_PUSHED)*/ inputstate2[0] = S_RIGHT_DOWN;
	else if (App->input->keyboardstate[SDL_SCANCODE_LEFT] == KEY_PULLED) {
		inputstateout2[inputsouts] = SO_RIGHT_UP;
		if (inputstate2[0] == S_RIGHT_DOWN)inputstate2[0] = S_NONE;
		inputsouts++;
	}

	//CHECK JUMP AND JUMP WITH DIRECTION//
	bool jump = false;
	if (App->input->keyboardstate[SDL_SCANCODE_UP] == KEY_PUSHED || App->input->keyboardstate[SDL_SCANCODE_UP] == KEY_REPEAT)jump = true;
	if (jump == true) {
		if (inputstate2[0] == S_RIGHT_DOWN)inputstate2[0] = S_JUMP_RIGHT;
		else if (inputstate2[0] == S_LEFT_DOWN)inputstate2[0] = S_JUMP_LEFT;
		else inputstate2[0] = S_JUMP;
	}

	//CHECK CROUCH AND CROUCH WITH DIRECTION//
	bool crouch = false;
	if (App->input->keyboardstate[SDL_SCANCODE_DOWN] == KEY_PUSHED || App->input->keyboardstate[SDL_SCANCODE_DOWN] == KEY_REPEAT)crouch = true;
	if (crouch == true) {
		if (inputstate2[0] == S_JUMP) inputstate2[0] = S_JUMP_AND_CROUCH;
		else if (inputstate2[0] == S_RIGHT_DOWN) { inputstate2[0] = S_CROUCH_RIGHT; LOG("CROUCH_RIGHT"); }
		//CROUCH LEFT
		else inputstate2[0] = S_CROUCH_DOWN;
	}
	else if (App->input->keyboardstate[SDL_SCANCODE_DOWN] == KEY_PULLED) {
		inputstateout2[inputsouts] = SO_CROUCH_UP;
		if (inputstate2[0] == S_CROUCH_DOWN)inputstate2[0] = S_NONE;
		inputsouts++;
	}

	//CHECK PUNCH AND VARIATIONS OF IT//
	if (App->input->keyboardstate[SDL_SCANCODE_H] == KEY_PUSHED) {
		if (inputstate2[0] == S_RIGHT_DOWN)inputstate2[0] = S_T_RIGHT;
		else if (inputstate2[0] == S_LEFT_DOWN)inputstate2[0] = S_T_LEFT;
		/*if (inputstate[0] == S_RIGHT_DOWN) {
			inputstate[0] = S_PUNCH_RIGHT;
			for (int i = 0; i < 60; i++) {
				if (inputstate[i] == S_CROUCH_RIGHT) {
					for (int j = i; j < 60; j++) {
						i = j;
						if (inputstate[j] == S_CROUCH_DOWN) {
							tornadoactivate = true;
							//inputstate[0] = S_T;
						}
						else if (inputstate[j] != S_CROUCH_RIGHT)continue;
					}
				}
				else if (inputstate[i] != S_PUNCH_RIGHT)continue;
			}
		}*/
		else inputstate2[0] = S_T;
	}

	//CHECK KICK AND VARIATIONS OF IT//

	if (App->input->keyboardstate[SDL_SCANCODE_G] == KEY_PUSHED) inputstate2[0] = S_Y;
	//ADD VARIATIONS OF Y IN GAME ALPHA


	//CHECK TIMERS//
	if (jump_timer > 0) {
		//if (SDL_GetTicks() - jump_timer > JUMP_TIME){
		if (position.y == 210) {
			inputstateout2[inputsouts] = SO_JUMP_FINISH;
			if (inputstate2[0] == S_JUMP)inputstate2[0] = S_NONE;
			else if (inputstate2[0] == S_JUMP_LEFT)inputstate2[0] = S_NONE;
			else if (inputstate2[0] == S_JUMP_RIGHT)inputstate2[0] = S_NONE;
			inputsouts++;
			jump_timer = 0;
		}
	}
	if (punch_timer == 3) {
		inputstateout2[inputsouts] = SO_PUNCH_FINISH;
		if (inputstate2[0] == S_T)inputstate2[0] = S_NONE;
		else if (inputstate2[0] == S_T_LEFT)inputstate2[0] = S_NONE;
		else if (inputstate2[0] == S_T_RIGHT)inputstate2[0] = S_NONE;
		inputsouts++;
		punch_timer = 0;
	}
	if (kick_timer == 3) {
		inputstateout2[inputsouts] = SO_KICK_FINISH;
		if (inputstate2[0] == S_Y)inputstate2[0] = S_NONE;
		inputsouts++;
		kick_timer = 0;
	}
	if (tornado_timer == 3) {
		inputstateout2[inputsouts] = SO_TORNADO_FINISH;
		if (inputstate2[0] == S_TORNADO)inputstate2[0] = S_NONE;
		inputsouts++;
		tornado_timer = 0;
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
update_status ModulePlayer2::Update()
{
	Animation* current_animation = &idle;

	int speed = 2;

	CheckState();

	switch (actual3) {
	case A_IDLE:
		current_animation = &idle;
		bodyenemy->SetPos(position.x + 20, (position.y - 80));
		bodyenemy2->SetPos(position.x + 30, (position.y - 57));
		bodyenemy3->SetPos(position.x + 20, (position.y - 40));
		break;
	case A_WALK_FORWARD:
		current_animation = &forward;
		bodyenemy->SetPos(position.x + 12, (position.y - 80));
		bodyenemy2->SetPos(position.x + 25, (position.y - 57));
		bodyenemy3->SetPos(position.x + 10, (position.y - 40));
		if ((position.x) > (App->player->position.x + 23 * SCREEN_SIZE)) position.x -= speed;
		if ((App->background->cameraright.x > position.x + 70) && App->background->cameraleft.x > 0)App->render->camera.x += speed;// *1.25;
		break;
	case A_WALK_BACKWARD:
		current_animation = &backward;
		bodyenemy->SetPos(position.x + 15, (position.y - 80));
		bodyenemy2->SetPos(position.x + 20, (position.y - 57));
		bodyenemy3->SetPos(position.x + 10, (position.y - 40));
		if (position.x+ 23 * SCREEN_SIZE < App->background->cameraright.x - 1) position.x += speed / 2;
		if ((App->background->cameraleft.x < App->player->position.x)&&(App->background->cameraright.x <670)) App->render->camera.x -= speed;// *1.25;
		break;
	case A_JUMP_NEUTRAL:
		current_animation = &jump;
		bodyenemy->SetPos(position.x + 35, (position.y - 90));
		bodyenemy2->SetPos(position.x + 42, (position.y - 69));
		bodyenemy3->SetPos(position.x + 30, (position.y - 55));
		if (position.y == 210) {
			App->audio->PlayChunk(jumpsound);
			mult = 1;
		}
		if (position.y == 130) {
			mult = -1;
		}
		position.y -= speed * mult;
		break;
	case A_JUMP_FORWARD:
		current_animation = &jump;
		bodyenemy->SetPos(position.x + 35, (position.y - 90));
		bodyenemy2->SetPos(position.x + 42, (position.y - 69));
		bodyenemy3->SetPos(position.x + 30, (position.y - 55));
		if (position.y == 210) {
			App->audio->PlayChunk(jumpsound);
			mult = 1;
		}
		if (position.y == 130) mult = -1;
		position.y -= speed * mult;
		if ((position.x) > (App->player->position.x + 23 * SCREEN_SIZE)) position.x -= speed;
		if ((App->background->cameraright.x > position.x + 70) && App->background->cameraleft.x > 0)App->render->camera.x += speed;// *1.25;
		break;
	case A_JUMP_BACKWARD:
		current_animation = &jump;
		bodyenemy->SetPos(position.x + 35, (position.y - 90));
		bodyenemy2->SetPos(position.x + 42, (position.y - 69));
		bodyenemy3->SetPos(position.x + 30, (position.y - 55));
		if (position.y == 210) {
			App->audio->PlayChunk(jumpsound);
			mult = 1;
		}
		if (position.y == 130) mult = -1;
		position.y -= speed * mult;
		if (position.x + 23 * SCREEN_SIZE < App->background->cameraright.x - 1) position.x += speed / 2;
		if ((App->background->cameraleft.x < App->player->position.x) && (App->background->cameraright.x < 670)) App->render->camera.x -= speed;// *1.25;
		break;
	case A_CROUCH:
		current_animation = &crouch;
		bodyenemy->SetPos(position.x + 50, (position.y - 70));
		bodyenemy2->SetPos(position.x + 67, (position.y - 54));
		bodyenemy3->SetPos(position.x + 47, (position.y - 40));
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
			position.x = position.x - 40;
			enemyattack = App->collision->AddCollider({ position.x,(position.y - 75),75,50 }, COLLIDER_ENEMY_SHOT, this);
			punch_timer = 2;
		}
		if (current_animation->GetFinished() == 1) {
			punch_timer = 3;
			enemyattack->to_delete = true;
			position.x = position.x + 40;
		}
		//	}
		break;
		/*case A_PUNCH_NEUTRAL_JUMP:
			if (position.y == 210) {
				App->audio->PlayChunk(jumpsound);
				mult = 1;
			}
			if (position.y == 130) {
				mult = -1;
			}
			position.y -= speed * mult;
			current_animation = &punch;
			if (punch_timer == 1) {
				App->audio->PlayChunk(punchsound);
				punch_timer = 2;
			}
			if (current_animation->GetFinished() == 1)punch_timer = 3;
			break;
		case A_PUNCH_FORWARD_JUMP:
			if (position.y == 210) {
				App->audio->PlayChunk(jumpsound);
				mult = 1;
			}
			if (position.y == 130) mult = -1;
			position.y -= speed * mult;
			position.x += speed;
			if (App->render->camera.x > (-SCREEN_WIDTH * SCREEN_SIZE))App->render->camera.x -= speed * 1.25;
			current_animation = &punch;
			if (punch_timer == 1) {
				App->audio->PlayChunk(punchsound);
				punch_timer = 2;
			}
			if (current_animation->GetFinished() == 1)punch_timer = 3;
			break;
		case A_PUNCH_BACKWARD_JUMP:
			if (position.y == 210) {
				App->audio->PlayChunk(jumpsound);
				mult = 1;
			}
			if (position.y == 130) mult = -1;
			position.y -= speed * mult;
			position.x -= speed / 2;
			if (App->render->camera.x < 0)	App->render->camera.x += speed * 1.25;
			current_animation = &punch;
			if (punch_timer == 1) {
				App->audio->PlayChunk(punchsound);
				punch_timer = 2;
			}
			if (current_animation->GetFinished() == 1)punch_timer = 3;
			break;
		case A_PUNCH_CROUCH:
			punch_timer = 3;
			break;
			//*/
	case A_KICK_STANDING:
		current_animation = &kick;

		if (kick_timer == 1) {
			App->audio->PlayChunk(kicksound);
			position.x = position.x - 20;
			enemyattack = App->collision->AddCollider({ position.x,(position.y - 90),65,20 }, COLLIDER_PLAYER_SHOT, this);
			kick_timer = 2;
		}
		if (current_animation->GetFinished() == 1) {
			kick_timer = 3;
			enemyattack->to_delete = true;
			position.x = position.x + 20;
		}
		break;
		/*case A_KICK_NEUTRAL_JUMP:
			if (position.y == 210) {
				App->audio->PlayChunk(jumpsound);
				mult = 1;
			}
			if (position.y == 130) {
				mult = -1;
			}
			position.y -= speed * mult;
			current_animation = &kick;
			if (kick_timer == 1) {
				App->audio->PlayChunk(kicksound);
				kick_timer = 2;
			}
			if (current_animation->GetFinished() == 1)kick_timer = 3;
			break;
		case A_KICK_FORWARD_JUMP:
			if (position.y == 210) {
				App->audio->PlayChunk(jumpsound);
				mult = 1;
			}
			if (position.y == 130) mult = -1;
			position.y -= speed * mult;
			position.x += speed;
			if (App->render->camera.x > (-SCREEN_WIDTH * SCREEN_SIZE))App->render->camera.x -= speed * 1.25;
			current_animation = &kick;
			if (kick_timer == 1) {
				App->audio->PlayChunk(kicksound);
				kick_timer = 2;
			}
			if (current_animation->GetFinished() == 1)kick_timer = 3;
			break;
		case A_KICK_BACKWARD_JUMP:
			if (position.y == 210) {
				App->audio->PlayChunk(jumpsound);
				mult = 1;
			}
			if (position.y == 130) mult = -1;
			position.y -= speed * mult;
			position.x -= speed / 2;
			if (App->render->camera.x < 0)	App->render->camera.x += speed * 1.25;
			current_animation = &kick;
			if (kick_timer == 1) {
				App->audio->PlayChunk(kicksound);
				kick_timer = 2;
			}
			if (current_animation->GetFinished() == 1)kick_timer = 3;
			break;
		case A_KICK_CROUCH:
			kick_timer = 3;
			break;
			//*/
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

	if ((App->input->keyboardstate[SDL_SCANCODE_RIGHT] == KEY_REPEAT || App->input->keyboardstate[SDL_SCANCODE_RIGHT] == KEY_PUSHED) && actual == NONE && (position.y == 210 || right == true)) {
		if (position.x <= (SCREEN_WIDTH*SCREEN_SIZE - 410)) {
			current_animation = &backward;
			position.x += speed;
			right = true;

			if (App->render->camera.x > (-SCREEN_WIDTH * SCREEN_SIZE))App->render->camera.x -= speed*1.25;
		}
	}
	else right = false;

	////////////////////LEFT/////////////////////////

	if ((App->input->keyboardstate[SDL_SCANCODE_LEFT] == KEY_REPEAT || App->input->keyboardstate[SDL_SCANCODE_LEFT] == KEY_PUSHED) && actual == NONE && (position.y == 210 || left == true)) {
		if (position.x >= 20) {
			current_animation = &forward;
			position.x -= speed/2;
			left = true;
			if (App->render->camera.x > 0)	App->render->camera.x += speed * 1.25;
		}
	}
	else (left = false);


	////////////////////JUMP/////////////////////////

	if (((position.y < 210) || ((App->input->keyboardstate[SDL_SCANCODE_UP] == KEY_PUSHED || App->input->keyboardstate[SDL_SCANCODE_UP] == KEY_REPEAT) && actual == NONE)) && (position.y >= 130)) {
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
	if ((actual == NONE && App->input->keyboardstate[SDL_SCANCODE_H] == KEY_PUSHED) || actual == PUNCH) {
		current_animation = &punch;
		if (actual == NONE)App->audio->PlayChunk(punchsound);
		if (current_animation->GetFinished() == 0)actual = PUNCH;
		else actual = NONE;
	}
	///////////////////////CROUCH/////////////////
	if ((actual == NONE && App->input->keyboardstate[SDL_SCANCODE_S] == KEY_PUSHED) || actual == CROUCH) {
		current_animation = &crouch;
	}

	else actual = NONE;

	////////////////////KICK/////////////////////////

	if ((actual == NONE && App->input->keyboardstate[SDL_SCANCODE_G] == KEY_PUSHED) || actual == KICK) {
		current_animation = &kick;
		if (actual == NONE)App->audio->PlayChunk(kicksound);
		if (current_animation->GetFinished() == 0)actual = KICK;
		else actual = NONE;
	}
	*/
	////////////////////GODMODE/////////////////////////

	if (App->input->keyboardstate[SDL_SCANCODE_F6] == KEY_PUSHED) {
		if (bodyenemy->to_delete != false) {
			bodyenemy = App->collision->AddCollider({ position.x,(position.y - 100),35,20 }, COLLIDER_ENEMY, this);
			bodyenemy2 = App->collision->AddCollider({ position.x,(position.y - 50),25,15 }, COLLIDER_ENEMY, this);
			bodyenemy3 = App->collision->AddCollider({ position.x,(position.y - 20),45,35 }, COLLIDER_ENEMY, this);
		}
		else {
			bodyenemy->to_delete = true;
			bodyenemy2->to_delete = true;
			bodyenemy3->to_delete = true;
		}
	}

	// Draw everything --------------------------------------

	SDL_Rect r = current_animation->GetCurrentFrame();
	App->render->Blit(graphics, position.x, position.y - r.h, &r);
	return UPDATE_CONTINUE;
}

void ModulePlayer2::CheckSpecialAttacks() {
	bool out = false;
	int done = 0;
	int i = 1;
	if (inputstate2[0] == S_T_RIGHT) {
		do {
			switch (inputstate2[i]) {
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
		if (done == 2) inputstate2[0] = S_TORNADO;
	}
}
void ModulePlayer2::CheckState() {
	switch (actual3) {
	case A_IDLE:
		switch (inputstate2[0]) {
		case S_RIGHT_DOWN: actual3 = A_WALK_FORWARD; break;
		case S_LEFT_DOWN: actual3 = A_WALK_BACKWARD; break;
		case S_JUMP: actual3 = A_JUMP_NEUTRAL; jump_timer = SDL_GetTicks();  break;
		case S_JUMP_RIGHT:actual3 = A_JUMP_FORWARD; jump_timer = SDL_GetTicks(); break;
		case S_JUMP_LEFT:actual3 = A_JUMP_BACKWARD; jump_timer = SDL_GetTicks(); break;
		case S_CROUCH_DOWN: actual3 = A_CROUCH; break;
		case S_CROUCH_RIGHT: actual3 = A_CROUCH; break;
		case S_T: actual3 = A_PUNCH_STANDING; punch_timer = 1;  break;
		case S_T_LEFT: actual3 = A_PUNCH_STANDING; punch_timer = 1;  break;
		case S_T_RIGHT: actual3 = A_PUNCH_STANDING; punch_timer = 1;  break;
		case S_Y: actual3 = A_KICK_STANDING; kick_timer = 1;  break;
		case S_TORNADO: actual3 = A_TORNADO; tornado_timer = 1; break;
		}
		break;
	case A_WALK_FORWARD:
		switch (inputstate2[0]) {
			//case S_RIGHT_UP: actual2 = A_IDLE; break;
		case S_LEFT_AND_RIGHT: actual3 = A_IDLE; break;
		case S_JUMP: actual3 = A_JUMP_FORWARD; jump_timer = SDL_GetTicks();  break;
		case S_JUMP_RIGHT:actual3 = A_JUMP_FORWARD; jump_timer = SDL_GetTicks(); break;
		case S_JUMP_LEFT:actual3 = A_JUMP_BACKWARD; jump_timer = SDL_GetTicks(); break;
		case S_CROUCH_DOWN: actual3 = A_CROUCH; break;
		case S_CROUCH_RIGHT: actual3 = A_CROUCH; break;
		case S_T: actual3 = A_PUNCH_STANDING; punch_timer = 1;  break;
		case S_T_LEFT: actual3 = A_PUNCH_STANDING; punch_timer = 1;  break;
		case S_T_RIGHT: actual3 = A_PUNCH_STANDING; punch_timer = 1;  break;
		case S_Y: actual3 = A_KICK_STANDING; kick_timer = 1;  break;
		case S_TORNADO: actual3 = A_TORNADO; tornado_timer = 1; break;
		}
		for (int i = 0; i <= inputsouts; i++)if (inputstateout2[i] == SO_RIGHT_UP)actual3 = A_IDLE;
		//if ((position.x > (SCREEN_WIDTH*SCREEN_SIZE - 410)) && actual2 == A_WALK_FORWARD) actual2 = A_IDLE;
		break;
	case A_WALK_BACKWARD:
		switch (inputstate2[0]) {
			//case S_LEFT_UP: actual2 = A_IDLE; break;
		case S_LEFT_AND_RIGHT: actual3 = A_IDLE; break;
		case S_JUMP: actual3 = A_JUMP_BACKWARD; jump_timer = SDL_GetTicks();  break;
		case S_JUMP_RIGHT:actual3 = A_JUMP_FORWARD; jump_timer = SDL_GetTicks(); break;
		case S_JUMP_LEFT:actual3 = A_JUMP_BACKWARD; jump_timer = SDL_GetTicks(); break;
		case S_CROUCH_DOWN: actual3 = A_CROUCH; break;
		case S_CROUCH_RIGHT: actual3 = A_CROUCH; break;
		case S_T: actual3 = A_PUNCH_STANDING; punch_timer = 1;  break;
		case S_T_LEFT: actual3 = A_PUNCH_STANDING; punch_timer = 1;  break;
		case S_T_RIGHT: actual3 = A_PUNCH_STANDING; punch_timer = 1;  break;
		case S_Y: actual3 = A_KICK_STANDING; kick_timer = 1;  break;
		case S_TORNADO: actual3 = A_TORNADO; tornado_timer = 1; break;
		}
		for (int i = 0; i <= inputsouts; i++)if (inputstateout2[i] == SO_LEFT_UP)actual3 = A_IDLE;
		//if ((position.x <= 20) && actual2 == A_WALK_BACKWARD) actual2 = A_IDLE;
		break;
	case A_JUMP_NEUTRAL:
		switch (inputstate2[0]) {
			//case S_JUMP_FINISH: actual2 = A_IDLE; break;
			//case S_T: actual2 = A_PUNCH_NEUTRAL_JUMP; punch_timer = 1;  break;
			//case S_PUNCH_RIGHT: actual2 = A_PUNCH_STANDING; punch_timer = 1;  break;
			//case S_Y: actual2 = A_KICK_NEUTRAL_JUMP; kick_timer = 1;  break;
		}
		for (int i = 0; i <= inputsouts; i++)if (inputstateout2[i] == SO_JUMP_FINISH)actual3 = A_IDLE;
		break;
	case A_JUMP_FORWARD:
		switch (inputstate2[0]) {
			//case S_JUMP_FINISH: actual2 = A_IDLE; break;
			//case S_T: actual2 = A_PUNCH_FORWARD_JUMP; punch_timer = 1;  break;
			//case S_PUNCH_RIGHT: actual2 = A_PUNCH_STANDING; punch_timer = 1;  break;
			//case S_Y: actual2 = A_KICK_FORWARD_JUMP; kick_timer = 1;  break;
		}
		for (int i = 0; i <= inputsouts; i++)if (inputstateout2[i] == SO_JUMP_FINISH)actual3 = A_IDLE;
		break;
	case A_JUMP_BACKWARD:
		switch (inputstate2[0]) {
			//case S_JUMP_FINISH: actual2 = A_IDLE; break;
			//case S_T: actual2 = A_PUNCH_BACKWARD_JUMP; punch_timer = 1;  break;
			//case S_PUNCH_RIGHT: actual2 = A_PUNCH_STANDING; punch_timer = 1;  break;
			//case S_Y: actual2 = A_KICK_BACKWARD_JUMP; kick_timer = 1;  break;
		}
		for (int i = 0; i <= inputsouts; i++)if (inputstateout2[i] == SO_JUMP_FINISH)actual3 = A_IDLE;
		break;
	case A_PUNCH_STANDING:
		switch (inputstate2[0]) {
			//case S_PUNCH_FINISH: actual2 = A_IDLE; break;
		}
		for (int i = 0; i <= inputsouts; i++)if (inputstateout2[i] == SO_PUNCH_FINISH)actual3 = A_IDLE;
		break;
		/*case A_PUNCH_NEUTRAL_JUMP:
			switch (inputstate[0]) {
			case S_PUNCH_FINISH: actual2 = A_JUMP_NEUTRAL; break;
			case S_JUMP_FINISH: actual2 = A_IDLE; break;
			}
			break;
		case A_PUNCH_FORWARD_JUMP:
			switch (inputstate[0]) {
			case S_PUNCH_FINISH: actual2 = A_JUMP_FORWARD; break;
			case S_JUMP_FINISH: actual2 = A_IDLE; break;
			}
			break;
		case A_PUNCH_BACKWARD_JUMP:
			switch (inputstate[0]) {
			case S_PUNCH_FINISH: actual2 = A_JUMP_BACKWARD; break;
			case S_JUMP_FINISH: actual2 = A_IDLE; break;
			}
			break;*/
	case A_KICK_STANDING:
		switch (inputstate2[0]) {
			//case S_KICK_FINISH: actual2 = A_IDLE; break;
		}
		for (int i = 0; i <= inputsouts; i++)if (inputstateout2[i] == SO_KICK_FINISH)actual3 = A_IDLE;
		break;
		/*case A_KICK_NEUTRAL_JUMP:
			switch (inputstate[0]) {
			case S_KICK_FINISH: actual2 = A_JUMP_NEUTRAL; break;
			case S_JUMP_FINISH: actual2 = A_IDLE; break;
			}
			break;
		case A_KICK_FORWARD_JUMP:
			switch (inputstate[0]) {
			case S_KICK_FINISH: actual2 = A_JUMP_FORWARD; break;
			case S_JUMP_FINISH: actual2 = A_IDLE; break;
			}
			break;
		case A_KICK_BACKWARD_JUMP:
			switch (inputstate[0]) {
			case S_KICK_FINISH: actual2 = A_JUMP_BACKWARD; break;
			case S_JUMP_FINISH: actual2 = A_IDLE; break;
			}
			break;*/
	case A_CROUCH:
		switch (inputstate2[0]) {
			//case S_CROUCH_UP: actual2 = A_IDLE; break;
			//case S_T: actual2 = A_PUNCH_CROUCH; break;
			//case S_Y: actual2 = A_KICK_CROUCH; break;
		case S_TORNADO: actual3 = A_TORNADO; tornado_timer = 1; break;
		}
		for (int i = 0; i <= inputsouts; i++)if (inputstateout2[i] == SO_CROUCH_UP)actual3 = A_IDLE;
		break;
		/*case A_PUNCH_CROUCH:
			switch (inputstate[0]) {
			case S_PUNCH_FINISH: actual2 = A_CROUCH; break;
			}
			break;
		case A_KICK_CROUCH:
			switch (inputstate[0]) {
			case S_KICK_FINISH: actual2 = A_CROUCH; break;
			}
			break;*/
	case A_TORNADO:
		for (int i = 0; i <= inputsouts; i++)if (inputstateout2[i] == SO_TORNADO_FINISH)actual3 = A_IDLE;
		break;
	}
}

void ModulePlayer2::OnCollision(Collider* enemy, Collider* other) {
	//
	if (other->type == COLLIDER_PLAYER_SHOT) {
		actual3 = A_HITTED;
		//if (hitted_timer == 0)hitted_timer = 1;
	}
}
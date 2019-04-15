#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModulePlayer.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "SDL/include/SDL_timer.h"


ModulePlayer::ModulePlayer()
{
	position.x = 50;
	position.y = 210;

	// Idle animation
	idle.PushBack({ 628, 539, 73, 115 });
	idle.PushBack({ 710, 539, 73, 115 });
	idle.PushBack({ 791, 539, 73, 115 });
	idle.PushBack({ 628, 662, 73, 115 });
	idle.PushBack({ 710, 662, 73, 115 });
	idle.PushBack({ 791, 662, 73, 115 });
	idle.speed = 0.2f;

	// Walk forward animation (To IMPROVE)
	forward.PushBack({ 1416, 1295, 79, 123 });
	forward.PushBack({ 1497, 1295, 71, 123 });
	forward.PushBack({ 1566, 1295, 61, 123 });
	forward.PushBack({ 1627, 1295, 74, 123 });
	forward.speed = 0.2f;

	// Walk backwards animation (To Do)
	backward.PushBack({ 1627, 1295, 74, 123 });
	backward.PushBack({ 1566, 1295, 61, 123 });
	backward.PushBack({ 1497, 1295, 71, 123 });
	backward.PushBack({ 1416, 1295, 79, 123 });
	backward.speed = 0.1f;

	// Kick animation
	kick.PushBack({ 1571, 143, 79, 94 });
	kick.PushBack({ 1650, 145, 99, 92 });
	kick.PushBack({ 1749, 142, 110, 92 });
	kick.PushBack({ 1859, 143, 79, 94 });
	kick.PushBack({ 1938, 142, 62, 95 });
	kick.PushBack({ 1571, 143, 79, 94 });
	kick.PushBack({ 1571, 143, 79, 94 });
	kick.speed = 0.2f;
	
	
	//crouch
	
	crouch.PushBack({ 898 , 1831 , 137 , 104 });
	crouch.PushBack({ 898 , 1831 , 137 , 104 });
	crouch.speed = 0.2f;


	// Punch animation (TO IMPROVE)
	punch.PushBack({ 670, 1381, 72, 133 });
	punch.PushBack({ 742, 1381, 73, 133 });
	punch.PushBack({ 815, 1381, 81, 133 });
	punch.PushBack({ 896, 1381, 136, 133 });
	punch.PushBack({ 1032, 1381, 136, 133 });
	punch.PushBack({ 1169, 1381, 136, 133 });
	punch.PushBack({ 1296, 1638, 96, 130 });
	punch.PushBack({ 649, 1614, 133, 144 }); //144
	punch.PushBack({ 781, 1615, 133, 133 });
	punch.PushBack({ 914, 1625, 133, 133 });
	punch.PushBack({ 1190, 1617, 74, 133 });
	punch.speed = 0.2f;

	// Jump
	jump.PushBack({ 810, 783, 61, 112 });
	jump.PushBack({ 810, 783, 61, 112 });
	jump.PushBack({ 896, 804, 71, 91 });
	jump.PushBack({ 983, 814, 76, 81 });
	jump.PushBack({ 983, 814, 76, 81 });
	jump.PushBack({ 983, 814, 76, 81 });
	jump.PushBack({ 896, 804, 71, 91 });
	jump.PushBack({ 896, 804, 71, 91 });
	jump.PushBack({ 896, 804, 71, 91 });
	jump.speed = 0.1f;

	//Tornado
	////////////Animation tornado;
	tornado.PushBack({ 40, 1295, 88, 144});
	tornado.PushBack({ 186, 1295, 70, 144});
	tornado.PushBack({ 326, 1295, 74,144 });
	tornado.PushBack({ 484, 1295, 60, 144 });
	tornado.PushBack({ 615, 1295, 97, 144 });
	tornado.PushBack({ 777, 1295, 59, 1446 });
	tornado.PushBack({ 880, 1295, 100, 144 });
	tornado.PushBack({ 1020, 1295, 100, 144});
	tornado.PushBack({ 1158, 1295, 100, 144});
	tornado.PushBack({ 1317, 1295, 100, 144});
	tornado.PushBack({ 1458, 1295, 100, 144});
	tornado.PushBack({ 1604, 1295, 100, 144 });
	tornado.PushBack({ 1734, 1295, 100, 144 });
	tornado.PushBack({ 1875, 1295, 100, 144});
	tornado.PushBack({ 27, 1461, 85, 122 });
	tornado.PushBack({ 184,1461, 72, 122 });
	tornado.PushBack({ 327,1461, 72, 122 });
	
	
	tornado.speed = 0.1f;

	////////////Animation hitted;
	hittedan.PushBack({ 372, 8, 78, 97 });
	hittedan.PushBack({ 257, 8, 85, 97 });
	hittedan.speed = 0.1f;
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player textures");
	bool ret = true;
	graphics = App->textures->Load("Sprites/spritesHaohmaru.png"); // arcade version
	graphics2 = App->textures->Load("sprites/Haohfix1(tornado apart).png");
	punchsound = App->audio->LoadChunk("Audio_FX/Punch.wav");
	kicksound = App->audio->LoadChunk("Audio_FX/Kick.wav");
	jumpsound = App->audio->LoadChunk("Audio_FX/Jump.wav");
	hittedsound = App->audio->LoadChunk("Audio_FX/Hitted.wav");
	tornadosound = App->audio->LoadChunk("Audio_FX/Tornado.wav");
	body = App->collision->AddCollider({ position.x,(position.y-100),73,95 }, COLLIDER_PLAYER, this);
	//actual = A_IDLE;
	actual2 = A_IDLE;
	actual = NONE;
	//right = false;
	//left = false;
	godmode = false;
	for (int i = 0; i < 60; i++) inputstate[i] = S_NONE;
	for (int i = 0; i < 6; i++)inputstateout[i] = SO_NONE;
	jump_timer = 0;
	punch_timer = 0;
	kick_timer = 0;
	tornado_timer = 0;
	inputsouts = 0;
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

update_status ModulePlayer:: PreUpdate() {
	for (int i = 59; i > 0; i--)inputstate[i] = inputstate[i - 1];
	for (int i = 0; i < INPUTSOUTS; i++)inputstateout[i] = SO_NONE;
	inputsouts = 0;
	
	//CHECK LEFT AND RIGHT//
	bool left = false;
	bool right = false;
	if (App->input->keyboardstate[SDL_SCANCODE_D] == KEY_PUSHED || App->input->keyboardstate[SDL_SCANCODE_D] == KEY_REPEAT)right = true;
	if (App->input->keyboardstate[SDL_SCANCODE_A] == KEY_PUSHED || App->input->keyboardstate[SDL_SCANCODE_A] == KEY_REPEAT)left = true;
	if (right == true && left == true)inputstate[0] = S_LEFT_AND_RIGHT;
	else if (right==true)inputstate[0] = S_RIGHT_DOWN;//App->input->keyboardstate[SDL_SCANCODE_D] == KEY_PUSHED) {inputstate[0] = S_RIGHT_DOWN; LOG("RIGHT_DOWN\n");}
	else if (App->input->keyboardstate[SDL_SCANCODE_D] == KEY_PULLED) {
		inputstateout[inputsouts] = SO_RIGHT_UP;
		if (inputstate[0] == S_RIGHT_DOWN)inputstate[0] = S_NONE;
		inputsouts++;
	}
	else if (left==true)/*(App->input->keyboardstate[SDL_SCANCODE_A] == KEY_PUSHED)*/ inputstate[0] = S_LEFT_DOWN; 
	else if (App->input->keyboardstate[SDL_SCANCODE_A] == KEY_PULLED) {
		inputstateout[inputsouts] = SO_LEFT_UP;
		if (inputstate[0] == S_LEFT_DOWN)inputstate[0] = S_NONE;
		inputsouts++;
	}
	
	//CHECK JUMP AND JUMP WITH DIRECTION//
	bool jump = false;
	if (App->input->keyboardstate[SDL_SCANCODE_W] == KEY_PUSHED || App->input->keyboardstate[SDL_SCANCODE_W] == KEY_REPEAT)jump = true;
	if(jump==true){
		if (inputstate[0] == S_RIGHT_DOWN)inputstate[0] = S_JUMP_RIGHT;
		else if (inputstate[0] == S_LEFT_DOWN)inputstate[0] = S_JUMP_LEFT;
		else inputstate[0] = S_JUMP;
	}

	//CHECK CROUCH AND CROUCH WITH DIRECTION//
	bool crouch = false;
	if (App->input->keyboardstate[SDL_SCANCODE_S] == KEY_PUSHED || App->input->keyboardstate[SDL_SCANCODE_S] == KEY_REPEAT)crouch = true;
	if (crouch==true) {
		if (inputstate[0] == S_JUMP) inputstate[0] = S_JUMP_AND_CROUCH;
		else if (inputstate[0] == S_RIGHT_DOWN) {inputstate[0] = S_CROUCH_RIGHT; LOG("CROUCH_RIGHT");}
		//CROUCH LEFT
		else inputstate[0] = S_CROUCH_DOWN;
	}
	else if (App->input->keyboardstate[SDL_SCANCODE_S] == KEY_PULLED) {
		inputstateout[inputsouts] = SO_CROUCH_UP;
		if (inputstate[0] == S_CROUCH_DOWN)inputstate[0] = S_NONE;
		inputsouts++;
	}

	//CHECK PUNCH AND VARIATIONS OF IT//
	if (App->input->keyboardstate[SDL_SCANCODE_T] == KEY_PUSHED) {
		if (inputstate[0] == S_RIGHT_DOWN)inputstate[0] = S_T_RIGHT;
		else if (inputstate[0] == S_LEFT_DOWN)inputstate[0] = S_T_LEFT;
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
		else inputstate[0] = S_T;
	}

	//CHECK KICK AND VARIATIONS OF IT//

	if (App->input->keyboardstate[SDL_SCANCODE_Y] == KEY_PUSHED) inputstate[0] = S_Y;
	//ADD VARIATIONS OF Y IN GAME ALPHA


	//CHECK TIMERS//
	if (jump_timer > 0){
		//if (SDL_GetTicks() - jump_timer > JUMP_TIME){
		if(position.y==210){
			inputstateout[inputsouts] = SO_JUMP_FINISH;
			if (inputstate[0] == S_JUMP)inputstate[0] = S_NONE;
			else if (inputstate[0] == S_JUMP_LEFT)inputstate[0] = S_NONE;
			else if (inputstate[0] == S_JUMP_RIGHT)inputstate[0] = S_NONE;
			inputsouts++;
			jump_timer = 0;
		}
	}
	if (punch_timer == 3) {
		inputstateout[inputsouts] = SO_PUNCH_FINISH;
		if (inputstate[0] == S_T)inputstate[0] = S_NONE;
		else if (inputstate[0] == S_T_LEFT)inputstate[0] = S_NONE;
		else if (inputstate[0] == S_T_RIGHT)inputstate[0] = S_NONE;
		inputsouts++;
		punch_timer = 0;
	}
	if (kick_timer == 3) {
		inputstateout[inputsouts] = SO_KICK_FINISH;
		if (inputstate[0] == S_Y)inputstate[0] = S_NONE;
		inputsouts++;
		kick_timer = 0;
	}
	if (tornado_timer == 3) {
		inputstateout[inputsouts] = SO_TORNADO_FINISH;
		if (inputstate[0] == S_TORNADO)inputstate[0] = S_NONE;
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
update_status ModulePlayer:: Update()
{
	Animation* current_animation = &idle;
	int speed = 2;
	
	CheckState();
	
	switch (actual2) {
	case A_IDLE:
		current_animation = &idle;
		break;
	case A_WALK_FORWARD:
		current_animation = &forward;
		if (position.x <= (SCREEN_WIDTH*SCREEN_SIZE - 410)) position.x += speed;
		if (App->render->camera.x > (-SCREEN_WIDTH * SCREEN_SIZE))App->render->camera.x -= speed * 1.25;
		break;
	case A_WALK_BACKWARD:
		current_animation = &backward;
		if (position.x > 20) position.x -= speed / 2;
		if (App->render->camera.x < 0)	App->render->camera.x += speed * 1.25;
		break;
	case A_JUMP_NEUTRAL:
		current_animation = &jump;
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
		if (position.y == 210) {
			App->audio->PlayChunk(jumpsound);
			mult = 1;
		}
		if (position.y == 130) mult = -1;
		position.y -= speed * mult;
		position.x += speed;
		if (App->render->camera.x > (-SCREEN_WIDTH * SCREEN_SIZE))App->render->camera.x -= speed * 1.25;
		break;
	case A_JUMP_BACKWARD:
		current_animation = &jump;
		if (position.y == 210) {
			App->audio->PlayChunk(jumpsound);
			mult = 1;
		}
		if (position.y == 130) mult = -1;
		position.y -= speed * mult;
		position.x -= speed / 2;
		if (App->render->camera.x < 0)	App->render->camera.x += speed * 1.25;
		break;
	case A_CROUCH:
		current_animation = &crouch;
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
			}
			if (current_animation->GetFinished() == 1) punch_timer = 3;
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
			kick_timer = 2;
		}
		if (current_animation->GetFinished() == 1)kick_timer = 3;
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
		godmode = !godmode;
		if (godmode == true) body->to_delete = true;
		else body = App->collision->AddCollider({ position.x,(position.y-100),73,95 }, COLLIDER_PLAYER, this);
	}
	body->SetPos(position.x, (position.y - 100));
	
	
	if (actual == HITTED) {
		current_animation = &hittedan;
		if(current_animation->GetFinished()==1)	actual = NONE;
	}
		// Draw everything --------------------------------------
	SDL_Rect r = current_animation->GetCurrentFrame();		

	if(actual2!=A_TORNADO)	App->render->Blit(graphics, position.x, position.y - r.h, &r);
	else App->render->Blit(graphics2, position.x, position.y - r.h, &r);

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
	switch (actual2) {
	case A_IDLE:
		switch (inputstate[0]) {
		case S_RIGHT_DOWN: actual2 = A_WALK_FORWARD; break;
		case S_LEFT_DOWN: actual2 = A_WALK_BACKWARD; break;
		case S_JUMP: actual2 = A_JUMP_NEUTRAL; jump_timer = SDL_GetTicks();  break;
		case S_JUMP_RIGHT:actual2 = A_JUMP_FORWARD; jump_timer = SDL_GetTicks(); break;
		case S_JUMP_LEFT:actual2 = A_JUMP_BACKWARD; jump_timer = SDL_GetTicks(); break;
		case S_CROUCH_DOWN: actual2 = A_CROUCH; break;
		case S_CROUCH_RIGHT: actual2 = A_CROUCH; break;
		case S_T: actual2 = A_PUNCH_STANDING; punch_timer = 1;  break;
		case S_T_LEFT: actual2 = A_PUNCH_STANDING; punch_timer = 1;  break;
		case S_T_RIGHT: actual2 = A_PUNCH_STANDING; punch_timer = 1;  break;
		case S_Y: actual2 = A_KICK_STANDING; kick_timer = 1;  break;
		case S_TORNADO: actual2 = A_TORNADO; tornado_timer = 1; break;
		}
		break;
	case A_WALK_FORWARD:
		switch (inputstate[0]) {
		//case S_RIGHT_UP: actual2 = A_IDLE; break;
		case S_LEFT_AND_RIGHT: actual2 = A_IDLE; break;
		case S_JUMP: actual2 = A_JUMP_FORWARD; jump_timer = SDL_GetTicks();  break;
		case S_JUMP_RIGHT:actual2 = A_JUMP_FORWARD; jump_timer = SDL_GetTicks(); break;
		case S_JUMP_LEFT:actual2 = A_JUMP_BACKWARD; jump_timer = SDL_GetTicks(); break;
		case S_CROUCH_DOWN: actual2 = A_CROUCH; break;
		case S_CROUCH_RIGHT: actual2 = A_CROUCH; break;
		case S_T: actual2 = A_PUNCH_STANDING; punch_timer = 1;  break;
		case S_T_LEFT: actual2 = A_PUNCH_STANDING; punch_timer = 1;  break;
		case S_T_RIGHT: actual2 = A_PUNCH_STANDING; punch_timer = 1;  break;
		case S_Y: actual2 = A_KICK_STANDING; kick_timer = 1;  break;
		case S_TORNADO: actual2 = A_TORNADO; tornado_timer = 1; break;
		}
		for (int i = 0; i <= inputsouts; i++)if (inputstateout[i] == SO_RIGHT_UP)actual2 = A_IDLE;
		//if ((position.x > (SCREEN_WIDTH*SCREEN_SIZE - 410)) && actual2 == A_WALK_FORWARD) actual2 = A_IDLE;
		break;
	case A_WALK_BACKWARD:
		switch (inputstate[0]) {
		//case S_LEFT_UP: actual2 = A_IDLE; break;
		case S_LEFT_AND_RIGHT: actual2 = A_IDLE; break;
		case S_JUMP: actual2 = A_JUMP_BACKWARD; jump_timer = SDL_GetTicks();  break;
		case S_JUMP_RIGHT:actual2 = A_JUMP_FORWARD; jump_timer = SDL_GetTicks(); break;
		case S_JUMP_LEFT:actual2 = A_JUMP_BACKWARD; jump_timer = SDL_GetTicks(); break;
		case S_CROUCH_DOWN: actual2 = A_CROUCH; break;
		case S_CROUCH_RIGHT: actual2 = A_CROUCH; break;
		case S_T: actual2 = A_PUNCH_STANDING; punch_timer = 1;  break;
		case S_T_LEFT: actual2 = A_PUNCH_STANDING; punch_timer = 1;  break;
		case S_T_RIGHT: actual2 = A_PUNCH_STANDING; punch_timer = 1;  break;
		case S_Y: actual2 = A_KICK_STANDING; kick_timer = 1;  break;
		case S_TORNADO: actual2 = A_TORNADO; tornado_timer = 1; break;
		}
		for (int i = 0; i <= inputsouts; i++)if (inputstateout[i] == SO_LEFT_UP)actual2 = A_IDLE;
		//if ((position.x <= 20) && actual2 == A_WALK_BACKWARD) actual2 = A_IDLE;
		break;
	case A_JUMP_NEUTRAL:
		switch (inputstate[0]) {
		//case S_JUMP_FINISH: actual2 = A_IDLE; break;
		//case S_T: actual2 = A_PUNCH_NEUTRAL_JUMP; punch_timer = 1;  break;
		//case S_PUNCH_RIGHT: actual2 = A_PUNCH_STANDING; punch_timer = 1;  break;
		//case S_Y: actual2 = A_KICK_NEUTRAL_JUMP; kick_timer = 1;  break;
		}
		for (int i = 0; i <= inputsouts; i++)if (inputstateout[i] == SO_JUMP_FINISH)actual2 = A_IDLE;
		break;
	case A_JUMP_FORWARD:
		switch (inputstate[0]) {
		//case S_JUMP_FINISH: actual2 = A_IDLE; break;
		//case S_T: actual2 = A_PUNCH_FORWARD_JUMP; punch_timer = 1;  break;
		//case S_PUNCH_RIGHT: actual2 = A_PUNCH_STANDING; punch_timer = 1;  break;
		//case S_Y: actual2 = A_KICK_FORWARD_JUMP; kick_timer = 1;  break;
		}
		for (int i = 0; i <= inputsouts; i++)if (inputstateout[i] == SO_JUMP_FINISH)actual2 = A_IDLE;
		break;
	case A_JUMP_BACKWARD:
		switch (inputstate[0]) {
		//case S_JUMP_FINISH: actual2 = A_IDLE; break;
		//case S_T: actual2 = A_PUNCH_BACKWARD_JUMP; punch_timer = 1;  break;
		//case S_PUNCH_RIGHT: actual2 = A_PUNCH_STANDING; punch_timer = 1;  break;
		//case S_Y: actual2 = A_KICK_BACKWARD_JUMP; kick_timer = 1;  break;
		}
		for (int i = 0; i <= inputsouts; i++)if (inputstateout[i] == SO_JUMP_FINISH)actual2 = A_IDLE;
		break;
	case A_PUNCH_STANDING:
		switch (inputstate[0]) {
		//case S_PUNCH_FINISH: actual2 = A_IDLE; break;
		}
		for (int i = 0; i <= inputsouts; i++)if (inputstateout[i] == SO_PUNCH_FINISH)actual2 = A_IDLE;
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
		switch (inputstate[0]) {
		//case S_KICK_FINISH: actual2 = A_IDLE; break;
		}
		for (int i = 0; i <= inputsouts; i++)if (inputstateout[i] == SO_KICK_FINISH)actual2 = A_IDLE;
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
		switch (inputstate[0]) {
		//case S_CROUCH_UP: actual2 = A_IDLE; break;
		//case S_T: actual2 = A_PUNCH_CROUCH; break;
		//case S_Y: actual2 = A_KICK_CROUCH; break;
		case S_TORNADO: actual2 = A_TORNADO; tornado_timer = 1; break;
		}
		for (int i = 0; i <= inputsouts; i++)if (inputstateout[i] == SO_CROUCH_UP)actual2 = A_IDLE;
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
		for (int i = 0; i <= inputsouts; i++)if (inputstateout[i] == SO_TORNADO_FINISH)actual2 = A_IDLE;
		break;
	}
}

void ModulePlayer::OnCollision(Collider* player, Collider* enemy) {
	if (actual != HITTED) {
		App->audio->PlayChunk(hittedsound);
		//Sprites hitted
		position.x = position.x - 25;
	}
	actual = HITTED;
}
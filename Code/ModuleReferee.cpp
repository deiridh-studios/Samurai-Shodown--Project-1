#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleUI.h"
#include "ModulePlayer2.h"
#include "Modulebackground.h"
#include "StateMachine.h"
#include "ModuleUI.h"
#include "ModuleSlowdown.h"
#include "SDL/include/SDL_timer.h"
#include "ModuleReferee.h"
#include "SDL/include/SDL.h"

ModuleReferee::ModuleReferee(){



// Idle animation
	idle.PushBack({ 85 , 33 , 58 , 94 });
	idle.speed = 0.2f;

// Walk left animation
	walkleft.PushBack({22 , 542 , 58 , 71});
	walkleft.PushBack({92 , 542 , 55 , 71});
	walkleft.PushBack({159 , 542 , 52 , 71});
	walkleft.PushBack({223 , 542 , 67 , 70});
	walkleft.speed = 0.2f;

// Walk righ animation
	walkright.PushBack({494 , 540 , 60 , 72});
	walkright.PushBack({570 , 540 , 59 , 72});
	walkright.PushBack({659 , 540 , 59 , 72});
	walkright.PushBack({732 , 540 , 67 , 72});
	walkright.speed = 0.2f;

//BegginingCombat animation
	startcombat.PushBack({77 , 302 , 41 , 78});
	startcombat.PushBack({160 , 302 , 41 , 78 });
	startcombat.PushBack({223 , 302 , 41 , 78 });
	startcombat.PushBack({285 , 302 , 41 , 78 });
	startcombat.PushBack({337 , 302 , 41 , 78 });//5
	startcombat.PushBack({381 , 302 , 50 , 79 });
	startcombat.PushBack({432 , 302 , 60 , 79});
	startcombat.PushBack({496 , 302 , 60 , 79 });
	startcombat.PushBack({567 , 302 , 60 , 79 });
	startcombat.PushBack({632 , 302 , 60 , 79 });
	startcombat.PushBack({702 , 302 , 60 , 79 });
	startcombat.PushBack({768 , 302 , 60 , 79 });
	startcombat.PushBack({844 , 302 , 60 , 79 });
	startcombat.PushBack({922 , 302 , 60 , 79 });
	startcombat.PushBack({993 , 302 , 60 , 79 });//15
	startcombat.PushBack({1067 , 266 , 37 , 115});
	startcombat.PushBack({1225 , 266 , 37 , 115 });
	startcombat.PushBack({1290 , 266 , 37 , 115 });
	startcombat.PushBack({1361 , 266 , 47 , 114 });
	startcombat.PushBack({1132 , 266 , 74 , 115});//20		   
	startcombat.PushBack({1430 , 266 , 80 , 114});
	startcombat.PushBack({1524 , 266 , 80 , 114 });
	startcombat.PushBack({1622 , 266 , 80 , 114 });//23
	startcombat.speed = 0.2f;

//ending animation
	endingcombat.PushBack({76 , 3030 , 43 , 76});
	endingcombat.PushBack({161 , 3030 , 43 , 76 });
	endingcombat.PushBack({223 , 3030 , 43 , 76 });
	endingcombat.PushBack({284 , 3030 , 43 , 76 });
	endingcombat.PushBack({337 , 3030 , 43 , 76 });
	endingcombat.PushBack({284 , 3030 , 43 , 76 });
	endingcombat.PushBack({447 , 422 , 44 , 79});
	endingcombat.PushBack({520 , 428 , 40 , 74});
	endingcombat.speed = 0.2f;

//hitted player 1 animation
	//hitp1.pushback({84 , 33 , 59 , 94}); //player in the left hits player in the right

	hitp1.PushBack({183 , 33 , 59 , 94 });
	hitp1.PushBack({271 , 33 , 59 , 94 });
	hitp1.PushBack({355 , 33 , 59 , 94 });
	hitp1.PushBack({432 , 33 , 82 , 95});
	hitp1.PushBack({518 , 33 , 76 , 93});
	hitp1.PushBack({600 , 33 , 71 , 95});
	hitp1.PushBack({});
	hitp1.speed = 0.2f;    


//hitted player 2 animation
	//hitp1.pushback({84 , 33 , 59 , 94});//player in the right hits player in the left
	hitp2.PushBack({84 , 166 , 59 , 94 });
	hitp2.PushBack({176 , 166 , 59 , 94 });
	hitp2.PushBack({247 , 166 , 59 , 94 });
	hitp2.PushBack({306 , 166 , 59 , 94 });
	hitp2.PushBack({413 , 166 , 59 , 94 });
	hitp2.PushBack({505 , 166 , 59 , 94 });
	hitp2.PushBack({596 , 166 , 59 , 94 });
	hitp2.PushBack({});
	hitp2.speed = 0.2f;

}
ModuleReferee::~ModuleReferee()
{}
// Load assets
//int contexit = 1, positionbefore;

bool ModuleReferee::Start()
{
	LOG("Loading referee textures");
	bool ret = true;
	graphics = App->textures->Load("Sprites/sprites referee.png");
	position.x = (App->player2->position.x - App->player->position.x) / 2;
	//positionbefore = (App->player2->position.x - App->player->position.x) / 2;
	position.y = 100;
	flip = false;
	return ret;
}

//Clean Up
bool ModuleReferee::CleanUp() {
	App->textures->Unload(graphics);

	return true;
}

update_status ModuleReferee::PreUpdate() {

	return UPDATE_CONTINUE;
}



update_status ModuleReferee::Update() {
	int positiontobe;
	Animation *current_animation=&idle;
	if ((App->player->flip == true || App->player2->flip == false) && flip == false)flip = true;
	else if ((App->player2->flip == true || App->player->flip == false) && flip == true)flip = false;
	if (flip == false) positiontobe = ((App->player2->position.x - App->player->position.x) / 2) + App->player->position.x;
	else positiontobe= ((App->player->position.x - App->player2->position.x) / 2) + App->player2->position.x;
	if (App->player->hitted_timer == 1) {
		current_animation = &hitp1;
	}
	else if (App->player2->hitted_timer == 1) {
		current_animation = &hitp2;
	}

	
	else if (positiontobe > position.x + 10) {
		position.x ++;
		current_animation = &walkright;
		//current_animation.GetCurrentFrame() = hitp2.GetCurrentFrame();
	}
	else if (positiontobe < position.x - 10) {
		position.x --;
		current_animation = &walkleft;
	}
	
/*
	else if (contexit %1 == 0) {
		if (App->player2->flip == true) {
			if (positiontobe > positionbefore) {
				current_animation = walkright;
			}
			else if (positiontobe < positionbefore) {
				current_animation = walkleft;
			}
			else if (positiontobe == positionbefore) {
				current_animation = idle;
			}
		}
		else if (App->player2->flip == true) {
			if (positiontobe > positionbefore) {
				current_animation = walkright;
			}
			else if (positiontobe < positionbefore) {
				current_animation = walkleft;
			}
			else if (positiontobe == positionbefore) {
				current_animation = idle;
			}
		}
		contexit++;
	}
	*/
	/*
	if(flip==false)App->render->Blit(graphics, position.x, position.y, &(current_animation->GetCurrentFrame()), 1.0F, true, false, App->render->zoom);
	else App->render->Blit(graphics, position.x, position.y, &(current_animation->GetCurrentFrame()), 1.0F, true, true, App->render->zoom);
	*/

	if(flip==false)App->render->Blit(graphics, positiontobe, position.y, &(current_animation->GetCurrentFrame()), 1.0F, true, false, App->render->zoom);
	else App->render->Blit(graphics, positiontobe, position.y, &(current_animation->GetCurrentFrame()), 1.0F, true, true, App->render->zoom);
	return UPDATE_CONTINUE;
}

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

ModuleReferee::ModuleReferee(){



// Idle animation

// Walk backwards animation
	walkleft.pushback({22 , 542 , 59 , 71});
	walkleft.pushback({91 , 542 , 56 , 71});
	walkleft.pushback({159 , 542 , 59 , 71});
	walkleft.pushback({223 , 542 , 67 , 70});
	walkleft.speed=0.2 
		// Walk backwards animation
		walkright.pushback({});
//BegginingCombat animation
		startcombat.pushback({});
//ending animation
		endingcombat.pushback({});
//hitted player 1 animation
		//hitp1.pushback({84 , 33 , 59 , 94}); //player in the left hits player in the right
		hitp1.pushback({183 , 33 , 59 , 94 });
		hitp1.pushback({271 , 33 , 59 , 94 });
		hitp1.pushback({355 , 33 , 59 , 94 });
		hitp1.pushback({432 , 33 , 82 , 95});
		hitp1.pushback({518 , 33 , 76 , 93});
		hitp1.pushback({600 , 33 , 71 , 95});
		hitp1.pushback({});
		hitp1.speed = 0.2;    


//hitted player 2 animation
		//hitp1.pushback({84 , 33 , 59 , 94});//player in the right hits player in the left
		hitp2.pushback({84 , 166 , 59 , 94 });
		hitp2.pushback({176 , 166 , 59 , 94 });
		hitp2.pushback({247 , 166 , 59 , 94 });
		hitp2.pushback({306 , 166 , 59 , 94 });
		hitp2.pushback({413 , 166 , 59 , 94 });
		hitp2.pushback({505 , 166 , 59 , 94 });
		hitp2.pushback({596 , 166 , 59 , 94 });
		hitp2.pushback({});
		hitp2.speed = 0.2f;

}
ModuleReferee::~ModuleReferee()
{}
// Load assets
bool ModuleReferee::Start()
{
	LOG("Loading referee textures");
	bool ret = true;
	graphics = App->textures->Load("Sprites/SpritesReferee.png");
	position.x = (App->player2->position.x - App->player->position.x) / 2;
	position.y = 210;
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
	if ((App->player->flip == true || App->player2->flip == false) && flip == false)flip = true;
	else if ((App->player2->flip == true || App->player->flip == false) && flip == true)flip = false;
	if (App->player->hitted_timer == 1);//animation  player hitted
	else if (App->player2->hitted_timer == 1);//animation  player2 hitted
	else if (flip == true) {
		if (App->player->position.x - App->player2->position.x > position.x+10) {
			position.x += 5;//+animation move right + problably change value of movement
		}
		else if(App->player->position.x - App->player2->position.x < position.x-10) {
			position.x -= 5;//+animation move right + problably change value of movement
		}
	}
	else {
		if (App->player2->position.x - App->player->position.x > position.x + 10) {
			position.x += 5;//+animation move right + problably change value of movement
		}
		else if (App->player2->position.x - App->player->position.x < position.x - 10) {
			position.x -= 5;//+animation move right + problably change value of movement
		}
	}
	if(flip==false)App->render->Blit(graphics, position.x, position.y, &rect/*HERE WILL GO THE ANIMATION RECTANGLE*/, 1.0F, true, false, App->render->zoom);
	else App->render->Blit(graphics, position.x, position.y, &rect/*HERE WILL GO THE ANIMATION RECTANGLE*/, 1.0F, true, true, App->render->zoom);
	return UPDATE_CONTINUE;

}

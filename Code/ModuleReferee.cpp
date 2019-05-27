/*#include "Globals.h"
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

position.x = 50;
position.y = 210;

// Idle animation

// Walk backwards animation

// Walk backwards animation

//BegginingCombat animation

//ending animation

//hitted player 1 animation

//hitted player 2 animation


}
ModuleReferee::~ModuleReferee()
{}
// Load assets
bool ModuleReferee::Start()
{
	LOG("Loading referee textures");
	bool ret = true;
	graphics = App->textures->Load("Sprites/SpritesReferee.png");
	
	position.x = 125;
	position.y = 210;
	
	
	


	
	App->render->camera.x = App->render->camera.y = 0;
	position.x = App->render->zooming;
	

	return ret;
}

//Clean Up
bool ModulePlayer::CleanUp() {
	App->textures->Unload(graphics);

	return true;
}

update_status ModulePlayer::PreUpdate() {
	
	
}
*/
#include "Globals.h"
#include "Application.h"
#include "Modulebackground.h"
#include "ModuleAudio.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "Animation.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleFadeToBlack.h"
#include"ModuleSceneEarthquake.h"
#include"ModuleCollision.h"
#include"ModuleParticles.h"
#include "ModuleUI.h"
#include "ModuleSceneCongrats.h"
#include "SDL/include/SDL.h"

ModuleBackground::ModuleBackground():Module(){
	// Water1 animation
	back.PushBack({ 0, 0, 640, 416 });
	back.PushBack({ 640, 0, 640, 416 });
	back.PushBack({ 1280, 0, 640, 416 });
	back.PushBack({ 1920, 0, 640, 416 });
	back.PushBack({ 0, 416, 640, 416 });
	back.PushBack({ 640, 416, 640, 416 });
	back.PushBack({ 1280, 416, 640, 416 });
	back.PushBack({ 1920, 416, 640, 416 });
	back.speed = 0.08f;

}

ModuleBackground::~ModuleBackground(){}

bool ModuleBackground::Start() {
	scrollleft = 0;
	scrollright = 0;
	App->audio->LoadMusic("Music/BackgroundUkyo.ogg");
	App->audio->PlayMusic(App->audio->musics[0]);
	Ukyo =App->audio->LoadChunk("Audio_FX/Ukyo.wav");
	App->audio->PlayChunk(Ukyo);
	graphics=App->textures->Load("Sprites/UkyoBackground.png");
	cameraleftcol = App->collision->AddCollider({ App->render->camera.x,App->render->camera.y,1,SCREEN_HEIGHT }, COLLIDER_WALL_LEFT, App->background);
	camerarightcol = App->collision->AddCollider({ App->render->camera.x,App->render->camera.y,1,SCREEN_HEIGHT }, COLLIDER_WALL_RIGHT, App->background);
	App->player->Enable();
	App->player2->Enable();
	App->particles->Enable();
	App->collision->Enable();
	App->UI->Enable();
	return true;
}
update_status ModuleBackground::Update() {
	App->render->Blit(graphics, 0, -170, &(back.GetCurrentFrame()), 0.9f, true);  //Background
	if (App->input->space == true&&App->fade->finished == true) {
		App->audio->StopMusic();
		App->fade->FadeToBlack(App->background, App->scenecongrats, 2);
	}
	cameraleft.x = (-App->render->camera.x) / SCREEN_SIZE;
	cameraleft.y = 0;
	cameraright.x = ((-App->render->camera.x) / SCREEN_SIZE) + (App->render->camera.w / SCREEN_SIZE) - 1;
	cameraright.y = 0;
	cameraleftcol->SetPos(cameraleft.x, cameraleft.y);
	camerarightcol->SetPos(cameraright.x, cameraright.y);
	return UPDATE_CONTINUE;
}
bool ModuleBackground::CleanUp()
{
	App->audio->StopChunk();
	App->audio->UnLoadChunk(Ukyo);
	App->audio->UnLoadMusic(App->audio->musics[0]);
	App->player->Disable();
	App->player2->Disable();
	App->particles->Disable();
	App->collision->Disable();
	App->UI->Disable();
	App->textures->Unload(graphics);
	return true;
}
void ModuleBackground::OnCollision(Collider* wall, Collider* enemy) {
	/*if (actual != HITTED) {

	}
	actual = HITTED;*/
	//LOG("ENEMY HITTED\n\n");
}
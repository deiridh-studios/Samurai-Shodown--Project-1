#include "Globals.h"
#include "Application.h"
#include "ModuleSceneEarthquake.h"
#include "ModuleAudio.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "Animation.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleFadeToBlack.h"
#include "ModuleSceneCongrats.h"
#include"ModuleCollision.h"
#include"ModuleParticles.h"
#include "ModuleUI.h"
#include "SDL/include/SDL.h"

ModuleSceneEarthquake::ModuleSceneEarthquake():Module()
{
	// Background animation
	backearthquake.PushBack({ 0, 0, 640, 416 });
	backearthquake.PushBack({ 640, 0, 640, 416 });
	backearthquake.PushBack({ 1280, 0, 640, 416 });
	backearthquake.PushBack({ 1920, 0, 640, 416 });
	backearthquake.PushBack({ 2560, 0, 640, 416 });
	backearthquake.PushBack({ 0, 416, 640, 416 });
	backearthquake.PushBack({ 640, 416, 640, 416 });
	backearthquake.PushBack({ 1280, 416, 640, 416 });
	backearthquake.PushBack({ 1920, 416, 640, 416 });
	backearthquake.PushBack({ 2560, 416, 640, 416 });
	backearthquake.PushBack({ 0, 832, 640, 416 });
	backearthquake.PushBack({ 640, 832, 640, 416 });
	backearthquake.PushBack({ 1280, 832, 640, 416 });
	backearthquake.PushBack({ 1920, 832, 640, 416 });
	backearthquake.PushBack({ 2560, 832, 640, 416 });
	backearthquake.PushBack({ 0, 1248, 640, 416 });
	backearthquake.PushBack({ 640, 1248, 640, 416 });
	backearthquake.PushBack({ 1280, 1248, 640, 416 });
	backearthquake.PushBack({ 1920, 1248, 640, 416 });
	backearthquake.PushBack({ 2560, 1248, 640, 416 });
	backearthquake.PushBack({ 0, 1664, 640, 416 });
	backearthquake.PushBack({ 640, 1664, 640, 416 });
	backearthquake.PushBack({ 1280, 1664, 640, 416 });
	backearthquake.speed = 0.08f;


}
ModuleSceneEarthquake::~ModuleSceneEarthquake() {}
bool  ModuleSceneEarthquake::Start() {
	rectbackground.x = 0;
	rectbackground.y = -200;
	rectbackground.w = (SCREEN_WIDTH)*2;
	rectbackground.h = (SCREEN_HEIGHT);
	scrollleft = 0;
	scrollright = 0;
	App->audio->LoadMusic("Music/stage2.ogg");
	App->audio->PlayMusic(App->audio->musics[0]);
	earthquake = App->audio->LoadChunk("Audio_FX/Earthquake.wav");
	App->audio->PlayChunk(earthquake);
	graphics = App->textures->Load("Sprites/BackEarthquake.png");
	App->player->Enable();
	App->player2->Enable();
	App->particles->Enable();
	App->collision->Enable();
	App->UI->Enable();
	return true;
}
update_status  ModuleSceneEarthquake::Update() {
	App->render->Blit(graphics, 0, -120, &(backearthquake.GetCurrentFrame()), 0.9f);  //Background
	if (App->input->space == true&&App->fade->finished == true)  {
		App->audio->StopMusic();
		App->fade->FadeToBlack(App->sceneearthquake, App->scenecongrats, 2);
	}
	return UPDATE_CONTINUE;
}
bool  ModuleSceneEarthquake::CleanUp()
{
	App->audio->StopChunk();
	App->audio->UnLoadChunk(earthquake);
	App->audio->UnLoadMusic(App->audio->musics[0]);
	App->player->Disable();
	App->player2->Disable();
	App->particles->Disable();
	App->collision->Disable();
	App->UI->Disable();
	App->textures->Unload(graphics);
	return true;
}
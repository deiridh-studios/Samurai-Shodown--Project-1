#include "Globals.h"
#include "Application.h"
#include "ModuleSceneEarthquake.h"
#include "ModuleAudio.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "Animation.h"
#include "ModulePlayer.h"
#include "ModuleFadeToBlack.h"
#include "ModuleSceneCongrats.h"
#include "SDL/include/SDL.h"

ModuleSceneEarthquake::ModuleSceneEarthquake() :Module() {}
ModuleSceneEarthquake::~ModuleSceneEarthquake() {}
bool  ModuleSceneEarthquake::Start() {
	rectbackground.x = 0;
	rectbackground.y = 0;
	rectbackground.w = (SCREEN_WIDTH)*SCREEN_SIZE;
	rectbackground.h = (SCREEN_HEIGHT)*SCREEN_SIZE;
	scrollleft = 0;
	scrollright = 0;
	App->audio->LoadMusic("Music/stage2.ogg");
	App->audio->PlayMusic(App->audio->musics[0]);
	earthquake = App->audio->LoadChunk("Audio_FX/Earthquake.wav");
	App->audio->PlayChunk(earthquake);
	graphics = App->textures->Load("Sprites/StageEarthquake.png");
	App->player->Enable();
	return true;
}
update_status  ModuleSceneEarthquake::Update() {
	App->render->Blit(graphics, 0, -170, &rectbackground, 0.8f);  //Background
	if (App->input->keyboardstate[SDL_SCANCODE_SPACE] == App->input->KEY_PUSHED&&App->fade->finished == true)  {
		App->audio->StopMusic();
		App->fade->FadeToBlack(App->sceneearthquake, App->scenecongrats, 5);
	}
	return UPDATE_CONTINUE;
}
bool  ModuleSceneEarthquake::CleanUp()
{
	App->audio->StopChunk();
	App->audio->UnLoadChunk(earthquake);
	App->audio->UnLoadMusic(App->audio->musics[0]);
	App->player->Disable();
	App->textures->Unload(graphics);
	return true;
}
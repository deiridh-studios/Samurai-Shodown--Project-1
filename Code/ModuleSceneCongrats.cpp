#include "Globals.h"
#include "Application.h"
#include "ModuleSceneCongrats.h"
#include "ModuleAudio.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "Animation.h"
#include "ModulePlayer.h"
#include "ModuleFadeToBlack.h"
#include "ModuleSceneWelcome.h"
#include "SDL/include/SDL.h"

ModuleSceneCongrats::ModuleSceneCongrats() :Module() {}
ModuleSceneCongrats::~ModuleSceneCongrats() {}
bool  ModuleSceneCongrats::Start() {
	rectbackground.x = 0;
	rectbackground.y = 0;
	rectbackground.w = SCREEN_WIDTH;
	rectbackground.h = SCREEN_HEIGHT;
	App->audio->LoadMusic("Music/end.ogg");
	App->audio->PlayMusic(App->audio->musics[0]);
	graphics = App->textures->Load("Sprites/congrats.png");
	return true;
}
update_status  ModuleSceneCongrats::Update() {
	App->render->Blit(graphics, 0, 0, &rectbackground, 0.0f);  //Background
	if (App->input->keyboardstate[SDL_SCANCODE_SPACE] == App->input->KEY_PUSHED&&App->fade->finished == true) {
		App->audio->StopMusic();
		App->fade->FadeToBlack(App->scenecongrats, App->scenewelcome, 2);
	}
	return UPDATE_CONTINUE;
}
bool  ModuleSceneCongrats::CleanUp()
{
	App->audio->UnLoadMusic(App->audio->musics[0]);
	App->textures->Unload(graphics);
	return true;
}
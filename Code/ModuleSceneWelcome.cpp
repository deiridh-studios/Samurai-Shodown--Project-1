#include "Globals.h"
#include "Application.h"
#include "Modulebackground.h"
#include "ModuleAudio.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "Animation.h"
#include "ModulePlayer.h"
#include "ModuleFadeToBlack.h"
#include "ModuleSceneWelcome.h"
#include "SDL/include/SDL.h"

ModuleSceneWelcome::ModuleSceneWelcome() :Module() {}
ModuleSceneWelcome::~ModuleSceneWelcome() {}
bool  ModuleSceneWelcome::Start() {
	rectbackground.x = 0;
	rectbackground.y = 0;
	rectbackground.w = SCREEN_WIDTH;
	rectbackground.h = SCREEN_HEIGHT;
	App->audio->LoadMusic("Music/start.ogg");
	App->audio->PlayMusic(App->audio->musics[0]);
	graphics = App->textures->Load("Sprites/intro.png");
	return true;
}
update_status  ModuleSceneWelcome::Update() {
	SDL_Rect rect{ 0,0,rectbackground.w*SCREEN_SIZE, rectbackground.h*SCREEN_SIZE };
	App->render->Blit(graphics, 0, 0, &rectbackground, 0.0f);  //Background
	if (App->input->keyboardstate[SDL_SCANCODE_SPACE] == App->input->KEY_PUSHED&&App->fade->finished == true) {
		App->audio->StopMusic();
		App->fade->FadeToBlack(App->scenewelcome, App->background, 2);
	}
	return UPDATE_CONTINUE;
}
bool  ModuleSceneWelcome::CleanUp()
{
	App->audio->UnLoadMusic(App->audio->musics[0]);
	App->textures->Unload(graphics);
	return true;
}
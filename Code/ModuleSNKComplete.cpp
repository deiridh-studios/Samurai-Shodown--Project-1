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
#include "ModuleSceneWelcome.h"
#include "ModuleSNKMenu.h"
#include "ModuleSNKComplete.h"
#include "ModuleCharacterSelection.h"
#include "SDL/include/SDL.h"

ModuleSNKComplete::ModuleSNKComplete() :Module()
{
	//Title
	Background.PushBack({ 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT });
	Background.PushBack({ SCREEN_WIDTH, 0, SCREEN_WIDTH, SCREEN_HEIGHT });
	Background.speed = 0.02;



}

ModuleSNKComplete::~ModuleSNKComplete() {}

bool  ModuleSNKComplete::Start() {
	App->audio->LoadMusic("Music/start.ogg");
	App->audio->PlayMusic(App->audio->musics[0]);
	graphics = App->textures->Load("Sprites/SNKComplete.png");
	Background.current_frame = 0;
	return true;
}

update_status  ModuleSNKComplete::Update() {

	App->render->Blit(graphics, 0, 0, &(Background.GetCurrentFrame()), 0.0f);


	if (App->input->keyboardstate[SDL_SCANCODE_SPACE] == KEY_PUSHED) {
		App->audio->StopMusic();
		App->fade->FadeToBlack(App->SNKComplete, App->scenewelcome, 2);
	}
	return UPDATE_CONTINUE;
}

bool  ModuleSNKComplete::CleanUp()
{
	App->audio->UnLoadMusic(App->audio->musics[0]);
	App->textures->Unload(graphics);
	return true;
}
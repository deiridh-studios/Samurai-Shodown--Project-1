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
#include "ModuleCharacterSelection.h"
#include "SDL/include/SDL.h"

ModuleCharacterSelection::ModuleCharacterSelection() :Module()
{
	//Title
	CharacterSelection.PushBack({ 0, 0, 253, 200 });

}

ModuleCharacterSelection::~ModuleCharacterSelection() {}

bool  ModuleCharacterSelection::Start() {
	App->audio->LoadMusic("Music/start.ogg");
	App->audio->PlayMusic(App->audio->musics[0]);
	graphics = App->textures->Load("Sprites/Neo Geo Intro.png");
	CharacterSelection.current_frame = 0;
	return true;
}

update_status  ModuleCharacterSelection::Update() {
	if (App->fade->finished == true && SDL_GetTicks() > 3500) {
		App->render->Blit(graphics, 30, 15, &(CharacterSelection.GetCurrentFrame()), 0.0f);
	}

	if (CharacterSelection.current_frame > 67) {
		App->input->keyboardstate[SDL_SCANCODE_SPACE] = KEY_PUSHED;
	}

	if (App->input->keyboardstate[SDL_SCANCODE_SPACE] == KEY_PUSHED && App->fade->finished == true && CharacterSelection.current_frame > 67) {
		App->audio->StopMusic();
		App->fade->FadeToBlack(App->characterselection, App->background, 2);
	}
	return UPDATE_CONTINUE;
}

bool  ModuleCharacterSelection::CleanUp()
{
	App->audio->UnLoadMusic(App->audio->musics[0]);
	App->textures->Unload(graphics);
	return true;
}
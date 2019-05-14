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
#include "ModuleSNKComplete.h"
#include "SDL/include/SDL.h"

ModuleCharacterSelection::ModuleCharacterSelection() :Module()
{
	//Title
	UkyoIdle.PushBack({ 0, 112, 75, 137 });
	UkyoIdle.PushBack({ 75, 112, 75, 137 });
	UkyoIdle.speed = 0.02;

	//Selection Animation
	SelectionAnimation.PushBack({ 177, 91, 37, 45 });
	SelectionAnimation.PushBack({ 216, 91, 37, 45 });
	SelectionAnimation.speed = 0.07;


}

ModuleCharacterSelection::~ModuleCharacterSelection() {}

bool  ModuleCharacterSelection::Start() {
	App->audio->LoadMusic("Music/start.ogg");
	App->audio->PlayMusic(App->audio->musics[0]);
	graphics = App->textures->Load("Sprites/CharactersSelection.png");
	UkyoIdle.current_frame = 0;
	background.x = 495;
	background.y = 0;
	background.w = SCREEN_WIDTH;
	background.h = SCREEN_HEIGHT;
	ukyoletters.x = 190;
	ukyoletters.y = 151;
	ukyoletters.w = 63;
	ukyoletters.h = 49;
	charactersrect.x = 0;
	charactersrect.y = 0;
	charactersrect.w = 217;
	charactersrect.h = 85;
	return true;
}

update_status  ModuleCharacterSelection::Update() {

	App->render->Blit(graphics, 0, 0, &background, 0.0f);
	App->render->Blit(graphics, 123, 110, &(UkyoIdle.GetCurrentFrame()), 0.0f);
	App->render->Blit(graphics, 130, 160, &ukyoletters, 0.0f);
	App->render->Blit(graphics, 45, 17, &charactersrect, 0.0f);
	App->render->Blit(graphics, 153, 15, &(SelectionAnimation.GetCurrentFrame()), 0.0f);

	if (App->input->keyboardstate[SDL_SCANCODE_SPACE] == KEY_PUSHED) {
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
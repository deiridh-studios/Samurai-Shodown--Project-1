#include "Globals.h"
#include "Application.h"
#include "ModuleSceneCongrats.h"
#include "ModuleAudio.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "Animation.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleFadeToBlack.h"
#include "ModuleSceneWelcome.h"
#include "ModuleFonts.h"
#include "SDL/include/SDL.h"
#include<stdio.h>

ModuleSceneCongrats::ModuleSceneCongrats() :Module() {
	
	//Ukyo2PlayerBackground
	backgroundUkyo1.PushBack({ 0, 758, 304, 128 });
	backgroundUkyo1.PushBack({ 304, 758, 304, 128 });
	backgroundUkyo1.PushBack({ 608, 758, 304, 128 });
	backgroundUkyo1.PushBack({ 0, 886, 304, 128 });
	backgroundUkyo1.PushBack({ 304, 886, 304, 128 });
	backgroundUkyo1.PushBack({ 608, 886, 304, 128 });
	backgroundUkyo1.PushBack({ 0, 1014, 304, 128 });
	backgroundUkyo1.PushBack({ 304, 1014, 304, 128 });
	backgroundUkyo1.speed = 0.1;

	//Ukyo1PlayerBackground
	backgroundUkyo2.PushBack({ 0, 374, 304, 128 });
	backgroundUkyo2.PushBack({ 304, 374, 304, 128 });
	backgroundUkyo2.PushBack({ 608, 374, 304, 128 });
	backgroundUkyo2.PushBack({ 0, 502, 304, 128 });
	backgroundUkyo2.PushBack({ 304, 502, 304, 128 });
	backgroundUkyo2.PushBack({ 608, 502, 304, 128 });
	backgroundUkyo2.PushBack({ 0, 630, 304, 128 });
	backgroundUkyo2.PushBack({ 304, 630, 304, 128 });
	backgroundUkyo2.speed = 0.1;

	//Ukyo1PlayerBackground
	letters.PushBack({ 648, 665, 216, 31 });
	letters.PushBack({ 648, 665, 216, 31 });
	letters.PushBack({ 648, 665, 216, 31 });
	letters.PushBack({ 648, 665, 216, 31 });
	letters.PushBack({ 648, 665, 216, 31 });
	letters.PushBack({ 648, 665, 216, 31 });
	letters.PushBack({ 648, 665, 216, 31 });
	letters.PushBack({ 648, 665, 216, 31 });
	letters.PushBack({ 648, 665, 216, 31 });
	letters.PushBack({ 648, 665, 216, 31 });
	letters.PushBack({ 648, 665, 216, 31 });
	letters.PushBack({ 648, 665, 216, 31 });
	letters.PushBack({ 648, 665, 216, 31 });
	letters.PushBack({ 648, 665, 216, 31 });
	letters.PushBack({ 648, 665, 216, 31 });
	letters.PushBack({ 648, 665, 216, 31 });
	letters.PushBack({ 648, 665, 216, 31 });
	letters.PushBack({ 648, 665, 216, 31 });
	letters.PushBack({ 648, 665, 216, 31 });
	letters.PushBack({ 648, 665, 216, 31 });
	letters.PushBack({ 0, 126, 216, 31 });
	letters.PushBack({ 216, 126, 216, 31 });
	letters.PushBack({ 432, 126, 216, 31 });
	letters.PushBack({ 648, 126, 216, 31 });
	letters.PushBack({ 864, 126, 216, 31 });
	letters.PushBack({ 0, 157, 216, 31 });
	letters.PushBack({ 216, 157, 216, 31 });
	letters.PushBack({ 432, 157, 216, 31 });
	letters.PushBack({ 648, 157, 216, 31 });
	letters.PushBack({ 864, 157, 216, 31 });
	letters.PushBack({ 0, 188, 216, 31 });
	letters.PushBack({ 216, 188, 216, 31 });
	letters.PushBack({ 432, 188, 216, 31 });
	letters.PushBack({ 648, 188, 216, 31 });
	letters.PushBack({ 864, 188, 216, 31 });
	letters.PushBack({ 0, 219, 216, 31 });
	letters.PushBack({ 216, 219, 216, 31 });
	letters.PushBack({ 432, 219, 216, 31 });
	letters.PushBack({ 648, 219, 216, 31 });
	letters.PushBack({ 864, 219, 216, 31 });
	letters.PushBack({ 0, 250, 216, 31 });
	letters.PushBack({ 216, 250, 216, 31 });
	letters.PushBack({ 432, 250, 216, 31 });
	letters.PushBack({ 648, 250, 216, 31 });
	letters.PushBack({ 864, 250, 216, 31 });
	letters.PushBack({ 0, 281, 216, 31 });
	letters.PushBack({ 216, 281, 216, 31 });
	letters.PushBack({ 432, 281, 216, 31 });
	letters.PushBack({ 648, 281, 216, 31 });
	letters.PushBack({ 864, 281, 216, 31 });
	letters.PushBack({ 0, 312, 216, 31 });
	letters.PushBack({ 216, 312, 216, 31 });
	letters.PushBack({ 432, 312, 216, 31 });
	letters.PushBack({ 648, 312, 216, 31 });
	letters.PushBack({ 864, 312, 216, 31 });
	letters.PushBack({ 0, 343, 216, 31 });
	letters.PushBack({ 216, 343, 216, 31 });
	letters.PushBack({ 432, 343, 216, 31 });
	letters.PushBack({ 648, 343, 216, 31 });
	letters.PushBack({ 864, 343, 216, 31 });
	letters.speed = 0.2;

}

ModuleSceneCongrats::~ModuleSceneCongrats() {}

bool  ModuleSceneCongrats::Start() {
	//WIN
	UkyoPlayer2WIN.x = 0;
	UkyoPlayer2WIN.y = 0;
	UkyoPlayer2WIN.w = 123;
	UkyoPlayer2WIN.h = 126;
	UkyoPlayer1WIN.x = 216;
	UkyoPlayer1WIN.y = 0;
	UkyoPlayer1WIN.w = 123;
	UkyoPlayer1WIN.h = 126;
	//LOSE
	UkyoPlayer1LOSE.x = 432;
	UkyoPlayer1LOSE.y = 46;
	UkyoPlayer1LOSE.w = 82;
	UkyoPlayer1LOSE.h = 80;
	UkyoPlayer2LOSE.x = 514;
	UkyoPlayer2LOSE.y = 46;
	UkyoPlayer2LOSE.w = 82;
	UkyoPlayer2LOSE.h = 80;
	//Letters
	lettersfinished.x = 648;
	lettersfinished.y = 630;
	lettersfinished.w = 216;
	lettersfinished.h = 31;

	letters.current_frame = 0;
	App->audio->LoadMusic("Music/end.ogg");
	App->audio->PlayMusic(App->audio->musics[0]);
	graphics = App->textures->Load("Sprites/FinalWin.png");
	font_victory = App->fonts->Load("Sprites/DEFINITIVE_FONT.png", "abcdefghijklmnopqrstuwyz123", 1);
	return true;
}

int xplayer1 = 347, xplayer2 = -80, xplayer11 = -100, xplayer22 = 400, multiplicador = 1, multiplicador2 = -1, multiplicador3 = 1, multiplicador4 = -1;

update_status  ModuleSceneCongrats::Update() {

	if (xplayer1 >= -24) {
		if (multiplicador2 == -1) {
			xplayer1 += 6 * multiplicador2;
		}
		if (xplayer1 <= -24) {
			multiplicador2 = 1;
			xplayer1 = -24;
		}
		if ((multiplicador2 == 1) && (xplayer1 <= 31)) {
			xplayer1 += 6 * multiplicador2;
		}
	}

	if (xplayer2 <= 190) {
		if (multiplicador == 1) {
			xplayer2 += 6 * multiplicador;
		}
		if (xplayer2 >= 190) {
			multiplicador = -1;
			xplayer2 = 190;
		}
		if ((multiplicador == -1) && (xplayer2 >= 150)) {
			xplayer2 += 6 * multiplicador;
		}
	}

	if (xplayer11 <= 80) {
		if (multiplicador3 == 1) {
			xplayer11 += 4 * multiplicador3;
		}
		if (xplayer11 >= 80) {
			multiplicador3 = -1;
			xplayer11 = 80;
		}
		if ((multiplicador3 == -1) && (xplayer11 >= 50)) {
			xplayer11 += 4 * multiplicador3;
		}
	}

	if (xplayer22 >= 160) {
		if (multiplicador4 == -1) {
			xplayer22 += 4 * multiplicador4;
		}
		if (xplayer22 <= 160) {
			multiplicador4 = 1;
			xplayer22 = 160;
		}
		if ((multiplicador4 == 1) && (xplayer22 <= 190)) {
			xplayer22 += 4 * multiplicador4;
		}
	}

	if (App->player->victory == true) {
		App->render->Blit(graphics, 0, 48, &(backgroundUkyo1.GetCurrentFrame()), 0.0f);
		if (letters.current_frame <= 59) {
			App->render->Blit(graphics, 44, 184, &(letters.GetCurrentFrame()), 0.0f);
		}
		else{
			App->render->Blit(graphics, 44, 184, &lettersfinished, 0.0f);
		}
		App->render->Blit(graphics, xplayer22, 80, &UkyoPlayer2LOSE, 0.0f);
		App->render->Blit(graphics, xplayer1, 50, &UkyoPlayer1WIN, 0.0f);
	}

	else if (App->player2->victory == true) {
		App->render->Blit(graphics, 0, 48, &(backgroundUkyo2.GetCurrentFrame()), 0.0f);
		if (letters.current_frame <= 59) {
			App->render->Blit(graphics, 44, 184, &(letters.GetCurrentFrame()), 0.0f);
		}
		else {
			App->render->Blit(graphics, 44, 184, &lettersfinished, 0.0f);
		}
		App->render->Blit(graphics, xplayer11, 80, &UkyoPlayer1LOSE, 0.0f);
		App->render->Blit(graphics, xplayer2, 50, &UkyoPlayer2WIN, 0.0f);
	}

	App->fonts->BlitText(145, 170, font_victory, victory_text);

	if ((App->input->keyboardstate[SDL_SCANCODE_SPACE] == KEY_PUSHED) && (App->fade->finished == true) && (letters.current_frame > 59)) {
		App->audio->StopMusic();
		App->fade->FadeToBlack(App->scenecongrats, App->scenewelcome, 2);
	}
	return UPDATE_CONTINUE;
}

bool  ModuleSceneCongrats::CleanUp()
{
	App->audio->UnLoadMusic(App->audio->musics[0]);
	App->textures->Unload(graphics);
	App->fonts->UnLoad(font_victory);
	return true;
}
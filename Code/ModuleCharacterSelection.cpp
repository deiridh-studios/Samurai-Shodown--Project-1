#include "Globals.h"
#include "Application.h"
#include "Modulebackground.h"
#include "ModuleAudio.h"
#include "ModuleController.h"
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
	//GenAnP1
	GenAnP1.PushBack({ 0, 210, 95, 140 });
	GenAnP1.PushBack({ 95, 210, 95, 140 });
	GenAnP1.PushBack({ 190, 210, 96, 140 });
	GenAnP1.PushBack({ 95, 210, 95, 140 });
	GenAnP1.PushBack({ 0, 210, 95, 140 });
	GenAnP1.speed = 0.15;

	//GenAnP2
	GenAnP2.PushBack({ 908, 210, 100, 140 });
	GenAnP2.PushBack({ 1008, 210, 100, 140 });
	GenAnP2.PushBack({ 1108, 210, 100, 140 });
	GenAnP2.PushBack({ 1008, 210, 100, 140 });
	GenAnP2.PushBack({ 908, 210, 100, 140 });
	GenAnP2.speed = 0.15;

	//GalfordP1
	GalfordP1.PushBack({ 0, 360, 111, 140 });
	GalfordP1.PushBack({ 111, 360, 111, 140 });
	GalfordP1.PushBack({ 222, 360, 111, 140 });
	GalfordP1.PushBack({ 333, 360, 111, 140 });
	GalfordP1.PushBack({ 222, 360, 111, 140 });
	GalfordP1.PushBack({ 111, 360, 111, 140 });
	GalfordP1.PushBack({ 0, 360, 111, 140 });
	GalfordP1.speed = 0.15;
	   
	//GalfordP2
	GalfordP2.PushBack({ 828, 360, 111, 140 });
	GalfordP2.PushBack({ 940, 360, 111, 140 });
	GalfordP2.PushBack({ 1051, 360, 112, 140 });
	GalfordP2.PushBack({ 940, 360, 111, 140 });
	GalfordP2.PushBack({ 828, 360, 111, 140 });
	GalfordP2.speed = 0.15;

	//UkyoP1
	UkyoP1.PushBack({ 0, 510, 75, 140 });
	UkyoP1.PushBack({ 75, 510, 75, 140 });
	UkyoP1.speed = 0.02;

	//UkyoP2
	UkyoP2.PushBack({ 1166, 510, 75, 140 });
	UkyoP2.PushBack({ 1241, 510, 75, 140 });
	UkyoP2.speed = 0.02;

	//HaohmaruP1
	HaohmaruP1.PushBack({ 167, 510, 127, 140 });
	HaohmaruP1.PushBack({ 294, 510, 127, 140 });
	HaohmaruP1.PushBack({ 421, 510, 127, 140 });
	HaohmaruP1.PushBack({ 294, 510, 127, 140 });
	HaohmaruP1.PushBack({ 167, 510, 127, 140 });
	HaohmaruP1.speed = 0.15;

	//HaohmaruP2
	HaohmaruP2.PushBack({ 739, 510, 127, 140 });
	HaohmaruP2.PushBack({ 866, 510, 127, 140 });
	HaohmaruP2.PushBack({ 993, 510, 127, 140 });
	HaohmaruP2.PushBack({ 866, 510, 127, 140 });
	HaohmaruP2.PushBack({ 739, 510, 127, 140 });
	HaohmaruP2.speed = 0.1;

	//CharlotteP1
	CharlotteP1.PushBack({ 0, 660, 143, 140 });
	CharlotteP1.PushBack({ 143, 660, 143, 140 });
	CharlotteP1.PushBack({ 286, 660, 143, 140 });
	CharlotteP1.PushBack({ 429, 660, 143, 140 });
	CharlotteP1.PushBack({ 286, 660, 143, 140 });
	CharlotteP1.PushBack({ 143, 660, 143, 140 });
	CharlotteP1.PushBack({ 0, 660, 143, 140 });
	CharlotteP1.speed = 0.15;

	//CharlotteP2
	CharlotteP2.PushBack({ 774, 660, 143, 140 });
	CharlotteP2.PushBack({ 917, 660, 143, 140 });
	CharlotteP2.PushBack({ 1060, 660, 143, 140 });
	CharlotteP2.PushBack({ 1203, 660, 143, 140 });
	CharlotteP2.PushBack({ 1060, 660, 143, 140 });
	CharlotteP2.PushBack({ 917, 660, 143, 140 });
	CharlotteP2.PushBack({ 774, 660, 143, 140 });
	CharlotteP2.speed = 0.15;

	//TamTamP1
	TamTamP1.PushBack({ 0, 810, 95, 140 });
	TamTamP1.PushBack({ 95, 810, 98, 140 });
	TamTamP1.PushBack({ 193, 810, 101, 140 });
	TamTamP1.PushBack({ 95, 810, 98, 140 });
	TamTamP1.PushBack({ 0, 810, 95, 140 });
	TamTamP1.speed = 0.15;

	//TamTamP2
	TamTamP2.PushBack({ 1115, 960, 100, 140 });
	TamTamP2.PushBack({ 1215, 960, 100, 140 });
	TamTamP2.PushBack({ 1315, 960, 100, 140 });
	TamTamP2.PushBack({ 1215, 960, 100, 140 });
	TamTamP2.PushBack({ 1115, 960, 100, 140 });
	TamTamP2.speed = 0.15;

	//EarthquakeP1
	EarthquakeP1.PushBack({ 308, 210, 144, 140 });
	EarthquakeP1.speed = 0.15;

	//EarthquakeP2
	EarthquakeP2.PushBack({ 1225, 210, 144, 140 });
	EarthquakeP2.speed = 0.15;

	//NakoruruP1
	NakoruruP1.PushBack({ 0, 960, 135, 140 });
	NakoruruP1.PushBack({ 135, 960, 135, 140 });
	NakoruruP1.PushBack({ 270, 960, 135, 140 });
	NakoruruP1.PushBack({ 405, 960, 135, 140 });
	NakoruruP1.PushBack({ 540, 960, 135, 140 });
	NakoruruP1.PushBack({ 675, 960, 135, 140 });
	NakoruruP1.PushBack({ 810, 960, 135, 140 });
	NakoruruP1.PushBack({ 945, 960, 135, 140 });
	NakoruruP1.speed = 0.15;

	//NakoruruP2
	NakoruruP2.PushBack({ 338, 810, 135, 140 });
	NakoruruP2.PushBack({ 473, 810, 135, 140 });
	NakoruruP2.PushBack({ 609, 810, 135, 140 });
	NakoruruP2.PushBack({ 745, 810, 135, 140 });
	NakoruruP2.PushBack({ 881, 810, 135, 140 });
	NakoruruP2.PushBack({ 1017, 810, 135, 140 });
	NakoruruP2.speed = 0.15;

	//WanFuP1
	WanFuP1.PushBack({ 0, 1110, 116, 140 });
	WanFuP1.PushBack({ 116, 1110, 118, 140 });
	WanFuP1.PushBack({ 236, 1110, 119, 140 });
	WanFuP1.PushBack({ 116, 1110, 118, 140 });
	WanFuP1.PushBack({ 0, 1110, 116, 140 });
	WanFuP1.speed = 0.15;

	//WanFuP2
	WanFuP2.PushBack({ 402, 1110, 116, 140 });
	WanFuP2.PushBack({ 524, 1110, 118, 140 });
	WanFuP2.PushBack({ 644, 1110, 119, 140 });
	WanFuP2.PushBack({ 524, 1110, 118, 140 });
	WanFuP2.PushBack({ 402, 1110, 116, 140 });
	WanFuP2.speed = 0.15;

	//JubeiP1
	JubeiP1.PushBack({ 0, 1260, 101, 140 });
	JubeiP1.PushBack({ 101, 1260, 104, 140 });
	JubeiP1.PushBack({ 205, 1260, 103, 140 });
	JubeiP1.PushBack({ 308, 1260, 100, 140 });
	JubeiP1.PushBack({ 205, 1260, 103, 140 });
	JubeiP1.PushBack({ 101, 1260, 104, 140 });
	JubeiP1.PushBack({ 0, 1260, 101, 140 });
	JubeiP1.speed = 0.15;

	//JubeiP2
	JubeiP2.PushBack({ 437, 1260, 96, 140 });
	JubeiP2.PushBack({ 533, 1260, 98, 140 });
	JubeiP2.PushBack({ 631, 1260, 104, 140 });
	JubeiP2.PushBack({ 735, 1260, 103, 140 });
	JubeiP2.PushBack({ 631, 1260, 104, 140 });
	JubeiP2.PushBack({ 533, 1260, 98, 140 });
	JubeiP2.PushBack({ 437, 1260, 96, 140 });
	JubeiP2.speed = 0.15;

	//HanzoP1
	HanzoP1.PushBack({ 0, 1410, 88, 140 });
	HanzoP1.PushBack({ 88, 1410, 88, 140 });
	HanzoP1.PushBack({ 176, 1410, 88, 140 });
	HanzoP1.PushBack({ 264, 1410, 88, 140 });
	HanzoP1.PushBack({ 352, 1410, 88, 140 });
	HanzoP1.PushBack({ 440, 1410, 88, 140 });
	HanzoP1.speed = 0.15;

	//HanzoP2
	HanzoP2.PushBack({ 900, 1110, 87, 140 });
	HanzoP2.PushBack({ 987, 1110, 87, 140 });
	HanzoP2.PushBack({ 1074, 1110, 87, 140 });
	HanzoP2.PushBack({ 1161, 1110, 87, 140 });
	HanzoP2.PushBack({ 1248, 1110, 87, 140 });
	HanzoP2.PushBack({ 1335, 1110, 87, 140 });
	HanzoP2.speed = 0.15;

	//KyoshiroP1
	KyoshiroP1.PushBack({ 0, 1560, 144, 140 });
	KyoshiroP1.PushBack({ 144, 1560, 144, 140 });
	KyoshiroP1.PushBack({ 288, 1560, 144, 140 });
	KyoshiroP1.PushBack({ 434, 1560, 144, 140 });
	KyoshiroP1.PushBack({ 578, 1560, 144, 140 });
	KyoshiroP1.PushBack({ 434, 1560, 144, 140 });
	KyoshiroP1.PushBack({ 288, 1560, 144, 140 });
	KyoshiroP1.PushBack({ 144, 1560, 144, 140 });
	KyoshiroP1.PushBack({ 0, 1560, 144, 140 });
	KyoshiroP1.speed = 0.15;

	//KyoshiroP2
	KyoshiroP2.PushBack({ 669, 1410, 145, 140 });
	KyoshiroP2.PushBack({ 814, 1410, 145, 140 });
	KyoshiroP2.PushBack({ 959, 1410, 145, 140 });
	KyoshiroP2.PushBack({ 1104, 1410, 145, 140 });
	KyoshiroP2.PushBack({ 1249, 1410, 145, 140 });
	KyoshiroP2.PushBack({ 1104, 1410, 145, 140 });
	KyoshiroP2.PushBack({ 959, 1410, 145, 140 });
	KyoshiroP2.PushBack({ 814, 1410, 145, 140 });
	KyoshiroP2.PushBack({ 669, 1410, 145, 140 });
	KyoshiroP2.speed = 0.15;

	//Selection Animation
	SelectionAnimation.PushBack({ 177, 91, 37, 45 });
	SelectionAnimation.PushBack({ 216, 91, 37, 45 });
	SelectionAnimation.speed = 0.07;

	//Selection AnimationP1
	SelectionAnimationP1.PushBack({ 264, 91, 37, 45 });
	SelectionAnimationP1.PushBack({ 301, 91, 37, 45 });
	SelectionAnimationP1.speed = 0.07;

	//Selection AnimationP2
	SelectionAnimationP2.PushBack({ 352, 91, 37, 45 });
	SelectionAnimationP2.PushBack({ 389, 91, 37, 45 });
	SelectionAnimationP2.speed = 0.07;
}

ModuleCharacterSelection::~ModuleCharacterSelection() {}

bool  ModuleCharacterSelection::Start() {

	App->audio->LoadMusic("Music/start.ogg");
	App->audio->PlayMusic(App->audio->musics[0]);
	graphics = App->textures->Load("Sprites/CharactersSelection.png");
	background.x = 495;
	background.y = 0;
	background.w = SCREEN_WIDTH;
	background.h = SCREEN_HEIGHT;
	charactersrect.x = 0;
	charactersrect.y = 0;
	charactersrect.w = 217;
	charactersrect.h = 85;
	return true;
}

int positionxp1 = 153, positionyp1 = 15, positionxp2 = 153, positionyp2 = 15, posanx1 = 0, posanx2 = 160;
Animation CurrentAn, CurrentAn2;

update_status  ModuleCharacterSelection::Update() {
	//w= 36  /  h= 43

	//Input P1
	if (App->input->keyboardstate[SDL_SCANCODE_A] == KEY_PUSHED) {
		if (positionxp1 > 45) {
			positionxp1 -= 36;
		}
		else {
			positionxp1 = 225;
		}
	}
	if (App->input->keyboardstate[SDL_SCANCODE_D] == KEY_PUSHED) {
		if (positionxp1 < 225) {
			positionxp1 += 36;
		}
		else {
			positionxp1 = 45;
		}
	}
	if (App->input->keyboardstate[SDL_SCANCODE_S] == KEY_PUSHED) {
		if (positionyp1 < 58) {
			positionyp1 += 43;
		}
		else {
			positionyp1 = 15;
		}
	}
	if (App->input->keyboardstate[SDL_SCANCODE_W] == KEY_PUSHED) {
		if (positionyp1 > 15) {
			positionyp1 -= 43;
		}
		else {
			positionyp1 = 58;
		}
	}

	//Input P2
	if (App->input->keyboardstate[SDL_SCANCODE_LEFT] == KEY_PUSHED) {
		if (positionxp2 > 45) {
			positionxp2 -= 36;
		}
		else {
			positionxp2 = 225;
		}
	}
	if (App->input->keyboardstate[SDL_SCANCODE_RIGHT] == KEY_PUSHED) {
		if (positionxp2 < 225) {
			positionxp2 += 36;
		}
		else {
			positionxp2 = 45;
		}
	}
	if (App->input->keyboardstate[SDL_SCANCODE_DOWN] == KEY_PUSHED) {
		if (positionyp2 < 58) {
			positionyp2 += 43;
		}
		else {
			positionyp2 = 15;
		}
	}
	if (App->input->keyboardstate[SDL_SCANCODE_UP] == KEY_PUSHED) {
		if (positionyp2 > 15) {
			positionyp2 -= 43;
		}
		else {
			positionyp2 = 58;
		}
	}

	//Animations P1
	if (positionxp1 == 225 && positionyp1 == 15) {
		CurrentAn.GetCurrentFrame() = TamTamP1.GetCurrentFrame();
		posanx1 = 25;
	}
	else if (positionxp1 == 189 && positionyp1 == 15) {
		CurrentAn.GetCurrentFrame() = CharlotteP1.GetCurrentFrame();
		posanx1 = 2;
	}
	else if (positionxp1 == 153 && positionyp1 == 15) {
		CurrentAn.GetCurrentFrame() = UkyoP1.GetCurrentFrame();
		posanx1 = 30;
	}
	else if (positionxp1 == 117 && positionyp1 == 15) {
		CurrentAn.GetCurrentFrame() = HaohmaruP1.GetCurrentFrame();
		posanx1 = 5;
	}
	else if (positionxp1 == 81 && positionyp1 == 15) {
		CurrentAn.GetCurrentFrame() = GalfordP1.GetCurrentFrame();
		posanx1 = 15;
	}
	else if (positionxp1 == 45 && positionyp1 == 15) {
		CurrentAn.GetCurrentFrame() = GenAnP1.GetCurrentFrame();
		posanx1 = 25;
	}
	else if (positionxp1 == 225 && positionyp1 == 58) {
		CurrentAn.GetCurrentFrame() = KyoshiroP1.GetCurrentFrame();
		posanx1 = 5;
	}
	else if (positionxp1 == 189 && positionyp1 == 58) {
		CurrentAn.GetCurrentFrame() = HanzoP1.GetCurrentFrame();
		posanx1 = 29;
	}
	else if (positionxp1 == 153 && positionyp1 == 58) {
		CurrentAn.GetCurrentFrame() = JubeiP1.GetCurrentFrame();
		posanx1 = 22;
	}
	else if (positionxp1 == 117 && positionyp1 == 58) {
		CurrentAn.GetCurrentFrame() = WanFuP1.GetCurrentFrame();
		posanx1 = 5;
	}
	else if (positionxp1 == 81 && positionyp1 == 58) {
		CurrentAn.GetCurrentFrame() = NakoruruP1.GetCurrentFrame();
		posanx1 = 0;
	}
	else if (positionxp1 == 45 && positionyp1 == 58) {
		CurrentAn.GetCurrentFrame() = EarthquakeP1.GetCurrentFrame();
		posanx1 = 0;
	}

	//Animations P2
	if (positionxp2 == 225 && positionyp2 == 15) {
		CurrentAn2.GetCurrentFrame() = TamTamP2.GetCurrentFrame();

	}
	else if (positionxp2 == 189 && positionyp2 == 15) {
		CurrentAn2.GetCurrentFrame() = CharlotteP2.GetCurrentFrame();
	}
	else if (positionxp2 == 153 && positionyp2 == 15) {
		CurrentAn2.GetCurrentFrame() = UkyoP2.GetCurrentFrame();
	}
	else if (positionxp2 == 117 && positionyp2 == 15) {
		CurrentAn2.GetCurrentFrame() = HaohmaruP2.GetCurrentFrame();
	}
	else if (positionxp2 == 81 && positionyp2 == 15) {
		CurrentAn2.GetCurrentFrame() = GalfordP2.GetCurrentFrame();
	}
	else if (positionxp2 == 45 && positionyp2 == 15) {
		CurrentAn2.GetCurrentFrame() = GenAnP2.GetCurrentFrame();
	}
	else if (positionxp2 == 225 && positionyp2 == 58) {
		CurrentAn2.GetCurrentFrame() = KyoshiroP2.GetCurrentFrame();
	}
	else if (positionxp2 == 189 && positionyp2 == 58) {
		CurrentAn2.GetCurrentFrame() = HanzoP2.GetCurrentFrame();
	}
	else if (positionxp2 == 153 && positionyp2 == 58) {
		CurrentAn2.GetCurrentFrame() = JubeiP2.GetCurrentFrame();
	}
	else if (positionxp2 == 117 && positionyp2 == 58) {
		CurrentAn2.GetCurrentFrame() = WanFuP2.GetCurrentFrame();
	}
	else if (positionxp2 == 81 && positionyp2 == 58) {
		CurrentAn2.GetCurrentFrame() = NakoruruP2.GetCurrentFrame();
	}
	else if (positionxp2 == 45 && positionyp2 == 58) {
		CurrentAn2.GetCurrentFrame() = EarthquakeP2.GetCurrentFrame();
	}

	App->render->Blit(graphics, 0, 0, &background, 0.0f);
	App->render->Blit(graphics, 45, 17, &charactersrect, 0.0f);
	if (positionxp1 == positionxp2 && positionyp1 == positionyp2) {
		App->render->Blit(graphics, positionxp1, positionyp1, &(SelectionAnimation.GetCurrentFrame()), 0.0f);
	}
	else{
		App->render->Blit(graphics, positionxp1, positionyp1, &(SelectionAnimationP1.GetCurrentFrame()), 0.0f);
		App->render->Blit(graphics, positionxp2, positionyp2, &(SelectionAnimationP2.GetCurrentFrame()), 0.0f);
	}
	App->render->Blit(graphics, posanx1, 80, &(CurrentAn.GetCurrentFrame()), 0.0f);
	App->render->Blit(graphics, posanx2, 80, &(CurrentAn2.GetCurrentFrame()), 0.0f); //144

	if ((App->input->keyboardstate[SDL_SCANCODE_SPACE] == KEY_PUSHED) && (positionxp1 == 153 && positionyp1 == 15) && (positionxp2 == 153 && positionyp2 == 15)) {
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
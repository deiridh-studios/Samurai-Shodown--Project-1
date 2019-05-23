#include "Globals.h"
#include "Application.h"
#include "ModuleUI.h"
#include "ModuleFonts.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleController.h"
#include "ModuleFadeToBlack.h"
#include "Modulebackground.h"
#include "ModuleSNKMenu.h"
#include "SDL/include/SDL_timer.h"
#include<stdio.h>


ModuleUI::ModuleUI(){}
ModuleUI::~ModuleUI() {}

bool ModuleUI::Init() {
	font_score = App->fonts->Load("Sprites/Numbers FONT.png", "0123456789-.,defghij", 2);
	font_score_white = App->fonts->Load("Sprites/WhiteNumbersFONT.png", "0123456789", 1);
	font_points = App->fonts->Load("Sprites/NumbersUIPlayers.png", "0123456789P=", 1);
	font_credits = App->fonts->Load("Sprites/NumbersCreditsFONT.png", "0123456789", 1);
	textlife = App->textures->Load("Sprites/Sprite_Sheet_UI_1.png");
	level4 = App->textures->Load("Sprites/CreditsandLevel4.png");
	doinitialtime = false;
	lifebarplayer1.x = 273;
	lifebarplayer1red.x = lifebarplayer1white.x = 277;
	lifebarplayer1.y = 421;
	lifebarplayer1red.y = 324;
	lifebarplayer1white.y = 389;
	lifebarplayer1.w = lifebarplayer1red.w = lifebarplayer1white.w = 134;
	lifebarplayer1.h = lifebarplayer1red.h = lifebarplayer1white.h = 15;
	lifebarplayer2.x = lifebarplayer2red.x = lifebarplayer2white.x = 273;
	lifebarplayer2.y = 405;
	lifebarplayer2red.y = 341;
	lifebarplayer2white.y = 373;
	lifebarplayer2.w = 134;
	lifebarplayer2red.w = lifebarplayer2white.w = 132;
	lifebarplayer2.h = lifebarplayer2red.h = lifebarplayer2white.h = 15;
	lifeplayer1.x = 273;
	lifeplayer1.y = 308;
	lifeplayer1.w = 128;
	lifeplayer1.h = 15;
	lifeplayer2.x = 273;
	lifeplayer2.y = 308;
	lifeplayer2.w = 128;
	lifeplayer2.h = 15;
	player1life = 32;
	player2life = 32;
	komessage.x = komessagewhite.x = endmessage.x = endmessagewhite.x = 484;
	komessage.y = 393;
	komessage.w = komessagewhite.w = endmessage.w = endmessagewhite.w = 28;
	komessage.h = komessagewhite.h = endmessage.h = endmessagewhite.h = 23;
	komessagewhite.y = 416;
	endmessage.y = 441;
	endmessagewhite.y = 465;
	victorymarker.x = 488;
	victorymarker.y = 377;
	victorymarker.w = 24;
	victorymarker.h = 15;
	nameplayer.x = 404;
	nameplayer.y = 489;
	nameplayer.w = 32;
	nameplayer.h = 8;
	level4rect.x = level4rect.y = creditrect.y = creditsrect.y = 0;
	level4rect.w = 53;
	level4rect.h = creditrect.h = creditsrect.h = 8;
	creditrect.x = 53;
	creditrect.w = 39;
	creditsrect.x = 92;
	creditsrect.w = 45;
	play = false;
	roundsp1 = roundsp2 = 0;
	credits = 0;
	koblink = lifeblink = 0;
	timeblink = 0;
	pointsp1 = pointsp2 = 0;
	rounds = 0;
	//App->input->space = false;
	return true;
}
bool ModuleUI::CleanUp() {
	App->fonts->UnLoad(font_score);
	App->fonts->UnLoad(font_score_white);
	App->fonts->UnLoad(font_points);
	App->fonts->UnLoad(font_credits);
	App->textures->Unload(textlife);
	App->textures->Unload(level4);
	return true;
}
update_status ModuleUI::Update() {
	if (play == true && App->fade->finished == true) {
		///////TIMER/////////
		if (doinitialtime == true) {
			initialtime = SDL_GetTicks();
			doinitialtime = false;
		}
		time = (100000) - (SDL_GetTicks() - initialtime);
		sprintf_s(time_text, 10, "%7d", (time / 1000));
		if (time / 1000 <= 15) {
			timeblink++;
			if (timeblink > 10)timeblink = 0;
			if(timeblink<5) App->fonts->BlitText(65, 50, font_score_white, time_text);
			else  App->fonts->BlitText(65, 50, font_score, time_text);
		}
		else App->fonts->BlitText(65, 50, font_score, time_text);
		if (time / 1000 == 0) {
			rounds++;
			if (player1life > player2life) {
				roundsp1++;
			}
			else if (player2life > player1life) {
				roundsp2++;
			}
			else if (rounds == 4) {
				App->background->fade = true;
				roundsp1 = roundsp2 = 0;
				pointsp1 = pointsp2 = 0;
			}
			if (rounds != 4 && roundsp1 < 2 && roundsp2 < 2)(App->fade->FadeToBlack(App->background, App->background));
			if (App->background->fade==true)rounds = 0;
			play = false;
		}



		/////////LIFE UPDATE/////////
		lifeplayer1.w = player1life * 4;
		lifeplayer2.w = player2life * 4;
		App->render->Blit(textlife, 5, 20, &lifebarplayer1, 0.0f, false);
		App->render->Blit(textlife, 180, 20, &lifebarplayer2, 0.0f, false);
		if(lifeplayer1.w> 58)App->render->Blit(textlife, (137 - (player1life * 4)), 20, &lifeplayer1, 0.0f, false);
		if(lifeplayer2.w> 58)App->render->Blit(textlife, 182, 20, &lifeplayer2, 0.0f, false);



		////////NAME PLAYER///////
		App->render->Blit(textlife, 17, 35, &nameplayer, 0.0f, false);
		App->render->Blit(textlife, 270, 35, &nameplayer, 0.0f, false);


		////////POINTS////////
		App->fonts->BlitText(17, 10, font_points, "P1=");
		App->fonts->BlitText(220, 10, font_points, "P2=");
		sprintf_s(points1, 10, "%7d", pointsp1);
		sprintf_s(points2, 10, "%7d", pointsp2);
		App->fonts->BlitText(41, 10, font_points, points1);
		App->fonts->BlitText(245, 10, font_points, points2);


		///////VICTORY MARKERS//////////
		if(roundsp1>0)App->render->Blit(textlife, 9, 45, &victorymarker, 0.0f, false);
		if(roundsp1>1)App->render->Blit(textlife, 41, 45, &victorymarker, 0.0f, false);
		if (roundsp2 > 0)App->render->Blit(textlife, 286, 45, &victorymarker, 0.0f, false);
		if (roundsp2 > 1)App->render->Blit(textlife, 254, 45, &victorymarker, 0.0f, false);



		////////KO AND KO BLINK//////
		if (lifeplayer1.w <= 58 || lifeplayer2.w <= 58) {
			koblink++;
			lifeblink++;
			if (koblink > 20)koblink = 0;
			if (lifeblink > 10)lifeblink = 0;
			lifebarplayer1red.w = lifebarplayer1white.w = lifeplayer1.w;
			lifebarplayer2red.w = lifebarplayer2white.w = lifeplayer2.w;
			if ((roundsp1 > 0 && lifeplayer2.w <= 58) || (roundsp2 > 0 && lifeplayer2.w <= 58)||rounds==3) {
				if(koblink<10)App->render->Blit(textlife, 145, 10, &endmessagewhite, 0.0f, false);
				else App->render->Blit(textlife, 145, 10, &endmessage, 0.0f, false);
			}
			else if (koblink < 10) App->render->Blit(textlife, 145, 10, &komessagewhite, 0.0f, false);
			else App->render->Blit(textlife, 145, 10, &komessage, 0.0f, false);
			if (lifeblink > 5) {
				if (lifeplayer1.w <= 58)App->render->Blit(textlife, (137 - (player1life * 4)), 20, &lifebarplayer1red, 0.0f, false);
				if (lifeplayer2.w <= 58) App->render->Blit(textlife, 180, 20, &lifebarplayer2red, 0.0f, false);
			}
			else {
				if (lifeplayer1.w <= 58)App->render->Blit(textlife, (137 - (player1life * 4)), 20, &lifebarplayer1white, 0.0f, false);
				if (lifeplayer2.w <= 58)App->render->Blit(textlife, 180, 20, &lifebarplayer2white, 0.0f, false);
			}
		}
		else if(rounds==3||(roundsp1==1&&roundsp2==1))App->render->Blit(textlife, 145, 10, &endmessage, 0.0f, false);
		else App->render->Blit(textlife, 145, 10, &komessage, 0.0f, false);



		///////////ONE PLAYER DEFEATED//////
		if (lifeplayer1.w <= 0||roundsp2==2||rounds==4) {
			if(roundsp2<2)roundsp2++;
			rounds++;
			if (roundsp2 == 2 || rounds == 4) {
				App->background->fade = true;
				App->player2->victory = true;
				roundsp1=roundsp2 = 0;
				pointsp1 = 0;
				rounds = 0;
			}
			else(App->fade->FadeToBlack(App->background, App->background));
			play = false;
		}
		if (lifeplayer2.w <= 0||roundsp1==2||rounds==4) {
			if(roundsp1<2)roundsp1++;
			rounds++;
			if (roundsp1 == 2 || rounds == 4) {
				App->background->fade = true;
				App->player->victory = true;
				roundsp1=roundsp2 = 0;
				pointsp2 = 0;
				rounds = 0;
			}
			else(App->fade->FadeToBlack(App->background, App->background));
			play = false;
		}
	}

	/////////BETWEEN ROUNDS OR BETWEEN FIGHTS////////
	else {
		koblink = 0;
		timeblink = 0;
		lifeblink = 0;
		lifeplayer1.w = 128;
		lifeplayer2.w = 128;
		lifebarplayer1red.w = lifebarplayer1white.w = lifebarplayer2red.w = lifebarplayer2white.w = 134;
		player1life = player2life = 32;
		doinitialtime = true;
		if (roundsp1 > 0 || roundsp2 > 0)play = true;
		
	}

	///////CREDITS AND LEVEL-4////////
	if (App->SNKMenu->IsEnabled() == false) {
		App->render->Blit(level4, 140, 216, &level4rect, 0.0f, false);
		if(credits<2)App->render->Blit(level4, 230, 216, &creditrect, 0.0f, false);
		else App->render->Blit(level4, 230, 216, &creditsrect, 0.0f, false);
		sprintf_s(creditsc, 10, "%02d", credits);
		App->fonts->BlitText(277, 216, font_credits, creditsc);
	}

	return UPDATE_CONTINUE;
}

void ModuleUI::DamageTaken(int numplayer, int damage) {
	if (numplayer == 1) {
		player1life -= damage;
		if (player1life < 0)player1life = 0;
		pointsp2 += 50;
	}
	else if (numplayer == 2) {
		player2life -= damage;
		if (player2life < 0)player2life = 0;
		pointsp1 += 50;
	}
}
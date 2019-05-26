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
#include "ModuleInput.h"
#include "ModuleAudio.h"
#include "SDL/include/SDL_timer.h"
#include<stdio.h>


ModuleUI::ModuleUI(){}
ModuleUI::~ModuleUI() {}
bool ModuleUI::Init() {
	font_score = App->fonts->Load("Sprites/Numbers FONT.png", "0123456789-.,defghij", 2);
	font_score_white = App->fonts->Load("Sprites/WhiteNumbersFONT.png", "0123456789", 1);
	font_points = App->fonts->Load("Sprites/NumbersUIPlayers.png", "0123456789P=", 1);
	font_credits = App->fonts->Load("Sprites/NumbersCreditsFONT.png", "0123456789", 1);
	font_finalpoints = App->fonts->Load("Sprites/YellowNumbersAndPercent.png", "0123456789%", 1);
	textlife = App->textures->Load("Sprites/Sprite_Sheet_UI_1.png");
	level4 = App->textures->Load("Sprites/CreditsandLevel4.png");
	sumpoints = App->audio->LoadChunk("Audio_FX/End_Combat_Points.wav");
	sumpoints2 = App->audio->LoadChunk("Audio_FX/Enter_in_Menu.wav");
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
	hitrect.x = 349;
	hitrect.y = 93;
	hitrect.h = 27;
	hitrect.w = 68;
	totalrect.x = 419;
	totalrect.y = 95;
	totalrect.h = timerect.h = liferect.h = 21;
	totalrect.w = 67;
	timerect.x = 395;
	timerect.y = 124;
	timerect.w = 64;
	liferect.x = 440;
	liferect.y = 145;
	liferect.w = 63;
	play = false;
	roundsp1 = roundsp2 = 0;
	credits = 0;
	koblink = lifeblink = 0;
	timeblink = 0;
	pointsp1 = 0;
	pointsp2 = 0;
	victory = 0;
	rounds = 0;
	counter = 0;
	startplay = false;
	totalscore = lifescore = timescore = hitsscore = 0;
	finished = false;
	return true;
}
bool ModuleUI::CleanUp() {
	App->audio->StopChunk();
	App->audio->UnLoadChunk(sumpoints);
	App->audio->UnLoadChunk(sumpoints2);
	App->fonts->UnLoad(font_finalpoints);
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
		if (finished == false)startplay = true;
		else startplay = false;
		if (doinitialtime == true) {
			initialtime = SDL_GetTicks();
			doinitialtime = false;
		}
		if(finished==false)time = (100000) - (SDL_GetTicks() - initialtime);
		sprintf_s(time_text, 10, "%7d", (time / 1000));
		if (time / 1000 <= 15) {
			if(finished==false)timeblink++;
			if (timeblink > 10)timeblink = 0;
			if(timeblink<5) App->fonts->BlitText(62, 45, font_score_white, time_text);
			else  App->fonts->BlitText(62, 45, font_score, time_text);
		}
		else App->fonts->BlitText(62, 45, font_score, time_text);
		if (time / 1000 == 0&&finished==false) {
			rounds++;
			if (player1life > player2life) {
				victory = 1;
			}
			else if (player2life > player1life) {
				victory = 2;
			}
			else if (rounds == 4) {
				pointsp1 = pointsp2 = 0;
			}
			finished = true;
		}



		/////////LIFE UPDATE/////////
		lifeplayer1.w = player1life * 4;
		lifeplayer2.w = player2life * 4;
		App->render->Blit(textlife, 10, 20, &lifebarplayer1, 0.0f, false);
		App->render->Blit(textlife, 160, 20, &lifebarplayer2, 0.0f, false);
		if(lifeplayer1.w> 58)App->render->Blit(textlife, (138 - (player1life * 4)), 20, &lifeplayer1, 0.0f, false);
		if(lifeplayer2.w> 58)App->render->Blit(textlife, 166, 20, &lifeplayer2, 0.0f, false);



		////////NAME PLAYER///////
		App->render->Blit(textlife, 17, 35, &nameplayer, 0.0f, false);
		App->render->Blit(textlife, 253, 35, &nameplayer, 0.0f, false);


		////////POINTS////////
		App->fonts->BlitText(17, 10, font_points, "P1=");
		App->fonts->BlitText(207, 10, font_points, "P2=");
		sprintf_s(points1, 10, "%7d", pointsp1);
		App->fonts->BlitText(41, 10, font_points, points1);
		sprintf_s(points2, 10, "%7d", pointsp2);
		App->fonts->BlitText(232, 10, font_points, points2);


		///////VICTORY MARKERS//////////
		if(roundsp1>0)App->render->Blit(textlife, 10, 45, &victorymarker, 0.0f, false);
		if(roundsp1>1)App->render->Blit(textlife, 42, 45, &victorymarker, 0.0f, false);
		if (roundsp2 > 0)App->render->Blit(textlife, 270, 45, &victorymarker, 0.0f, false);
		if (roundsp2 > 1)App->render->Blit(textlife, 238, 45, &victorymarker, 0.0f, false);



		////////KO AND KO BLINK//////
		if ((lifeplayer1.w <= 58 || lifeplayer2.w <= 58)) {
			koblink++;
			lifeblink++;
			if (koblink > 20)koblink = 0;
			else if (koblink > 10 && (lifeplayer1.w <= 18 || lifeplayer2.w <= 18))koblink = 0;
			if (lifeblink > 10)lifeblink = 0;
			lifebarplayer1red.w = lifebarplayer1white.w = lifeplayer1.w;
			lifebarplayer2red.w = lifebarplayer2white.w = lifeplayer2.w;
			if (finished == false) {
				if ((roundsp1 > 0 && lifeplayer2.w <= 58) || (roundsp2 > 0 && lifeplayer2.w <= 58) || rounds == 3) {
					if (koblink < 10 && lifeplayer1.w > 18 && lifeplayer2.w > 18)App->render->Blit(textlife, 138, 12, &endmessagewhite, 0.0f, false);
					else if (koblink < 5 && (lifeplayer1.w <= 18 || lifeplayer2.w <= 18))App->render->Blit(textlife, 138, 12, &endmessagewhite, 0.0f, false);
					else App->render->Blit(textlife, 138, 12, &endmessage, 0.0f, false);
				}
				else if (koblink < 10 && lifeplayer1.w > 18 && lifeplayer2.w > 18) App->render->Blit(textlife, 138, 12, &komessagewhite, 0.0f, false);
				else if (koblink < 5 && (lifeplayer1.w <= 18 || lifeplayer2.w <= 18))App->render->Blit(textlife, 138, 12, &komessagewhite, 0.0f, false);
				else App->render->Blit(textlife, 138, 12, &komessage, 0.0f, false);
			}
			else if (rounds == 4 || roundsp1 == 2 || roundsp2 == 2 || (roundsp1 == 1 && roundsp2 == 1))App->render->Blit(textlife, 138, 12, &endmessage, 0.0f, false);
			else App->render->Blit(textlife, 138, 12, &komessage, 0.0f, false);
			if (lifeblink > 5) {
				if (lifeplayer1.w <= 58)App->render->Blit(textlife, (138 - (player1life * 4)), 20, &lifebarplayer1red, 0.0f, false);
				if (lifeplayer2.w <= 58) App->render->Blit(textlife, 166, 20, &lifebarplayer2red, 0.0f, false);
			}
			else {
				if (lifeplayer1.w <= 58)App->render->Blit(textlife, (138 - (player1life * 4)), 20, &lifebarplayer1white, 0.0f, false);
				if (lifeplayer2.w <= 58)App->render->Blit(textlife, 166, 20, &lifebarplayer2white, 0.0f, false);
			}
		}
		else if(rounds==3||(roundsp1==1&&roundsp2==1))App->render->Blit(textlife, 138, 12, &endmessage, 0.0f, false);
		else App->render->Blit(textlife, 138, 12, &komessage, 0.0f, false);



		///////////ONE PLAYER DEFEATED//////
		if ((lifeplayer1.w <= 0|victory==2||rounds==4)&&finished==false) {
			roundsp2++;
			victory = 2;
			rounds++;
			if (roundsp2 == 2 || rounds == 4) {
				App->player2->victory = true;
				pointsp1 = 0;
			}
			finished = true;
		}
		if ((lifeplayer2.w <= 0||victory==1||rounds==4)&&finished==false) {
			roundsp1++;
			victory = 1;
			rounds++;
			if (roundsp1 == 2 || rounds == 4) {
				App->player->victory = true;
				pointsp2 = 0;
			}
			finished = true;
		}




		/////////////////////SCORES AT THE FINISH////////////////////////////
		if (finished == true) {
			if (totalscore == 0 && hitsscore == 0 && lifescore == 0 && timescore == 0) {
				initialtime = SDL_GetTicks();
				App->render->zoom = false;
				timescore = time / 1000;
				timescore *= 100;
				if (lifeplayer1.w > 0 && lifeplayer2.w == 0) {
					lifescore = player1life * 200;
					if (App->player->nattacks > 0)hitsscore = ((float)App->player->nattackss / (float)App->player->nattacks)*100;
				}
				else if (lifeplayer1.w == 0 && lifeplayer2.w > 0) {
					lifescore = player2life * 200;
					if(App->player2->nattacks>0)hitsscore = ((float)App->player2->nattackss / (float)App->player2->nattacks) * 100;
				}
			}
			if (SDL_GetTicks() - initialtime >= 2000) {
				if (victory!=0) {
					App->render->Blit(textlife, 60, 70, &liferect, 0.0f, false);
					if(counter>2)App->render->Blit(textlife, 60, 100, &timerect, 0.0f, false);
					if (counter > 4)App->render->Blit(textlife, 60, 130, &hitrect, 0.0f, false);
					if (counter > 8)App->render->Blit(textlife, 60, 166, &totalrect, 0.0f, false);
					sprintf_s(score, 10, "%7d", lifescore);
					if (counter > 10)App->fonts->BlitText(125, 70, font_finalpoints, score);
					sprintf_s(score, 10, "%7d", timescore);
					if (counter > 12)App->fonts->BlitText(125, 100, font_finalpoints, score);
					sprintf_s(score, 10, "%7d", hitsscore);
					if (counter > 14)App->fonts->BlitText(125, 130, font_finalpoints, score);
					sprintf_s(score, 10, "%c",'%');
					if (counter > 16&&counter<22)App->fonts->BlitText(235, 130, font_finalpoints, score);
					sprintf_s(score, 10, "%7d", totalscore);
					if (counter > 18)App->fonts->BlitText(125, 166, font_finalpoints, score);
					if (counter >= 20) {
						if (App->input->keyboardstate[SDL_SCANCODE_SPACE]) {
							App->audio->PlayChunk(sumpoints, -1);
							if(counter<22)hitsscore= ((float)hitsscore / (float)100) * 20000;
							if(victory==1)pointsp1+=lifescore+timescore+ hitsscore;
							else pointsp2+= lifescore + timescore + hitsscore;
							totalscore+= lifescore + timescore + hitsscore;
							App->audio->PlayChunk(sumpoints2);
							lifescore = hitsscore = timescore = 0;
							counter = 55;
						}
						for (int i = 0; i < 3; i++) {
							if (lifescore > 0) {
								if(counter==20)App->audio->PlayChunk(sumpoints, -1);
								counter = 21;
								lifescore -= 10;
								totalscore += 10;
								if (victory == 1)pointsp1 += 10;
								else pointsp2 += 10;
							}
							else if(timescore > 0) {
								timescore -= 10;
								totalscore += 10;
								if (victory == 1)pointsp1 += 10;
								else pointsp2 += 10;
							}
							else if (counter < 22) {
								App->audio->StopChunk();
								App->audio->PlayChunk(sumpoints2);
								hitsscore = ((float)hitsscore / (float)100) * 20000;
								counter++;
							}
							else if (counter < 56)counter++;
							else if (hitsscore > 0) {
								if(counter==56)App->audio->PlayChunk(sumpoints, -1);
								counter = 57;
								hitsscore -= 10;
								totalscore += 10;
								if (victory == 1)pointsp1 += 10;
								else pointsp2 += 10;
							}
						}
					}
					if (counter < 20)counter++;
				}
				if (hitsscore == 0 && lifescore == 0 && timescore == 0) {
					if (counter>78) {
						play = false;
						victory = 0;
						if (rounds != 4 && roundsp1 < 2 && roundsp2 < 2)(App->fade->FadeToBlack(App->background, App->background));
						else {
							App->background->fade = true;
							rounds = 0;
							roundsp1 = roundsp2 = 0;
						}
					}
					if (counter <= 78) {
						
						if (counter == 57) {
							App->audio->StopChunk();
							App->audio->PlayChunk(sumpoints2);
						}
						counter++;
					}
				}
			}
		}
	}

	/////////BETWEEN ROUNDS OR BETWEEN FIGHTS////////
	else {
		koblink = 0;
		counter = 0;
		timeblink = 0;
		lifeblink = 0;
		lifeplayer1.w = 128;
		lifeplayer2.w = 128;
		lifebarplayer1red.w = lifebarplayer1white.w = lifebarplayer2red.w = lifebarplayer2white.w = 134;
		player1life = player2life = 32;
		doinitialtime = true;
		finished = false;
		totalscore = lifescore = timescore = hitsscore = 0;
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
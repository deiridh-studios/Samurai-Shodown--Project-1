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
	powbarempty.x = powbarempty2.x = 380;
	powbarempty.y = 287;
	powbarempty2.y = 297;
	powbarempty.h = powbarempty2.h = powbargreen.h = powbargreen2.h = powbaryellow.h = powbaryellow2.h = powbarorange.h = powbarorange2.h = powbarred.h = powbarred2.h = powbarwhite.h = powbarwhite2.h = 9;
	powbarempty.w = powbarempty2.w = powbargreen.w = powbargreen2.w = powbaryellow.w = powbaryellow2.w = powbarorange.w = powbarorange2.w = powbarred.w = powbarred2.w = powbarwhite.w = powbarwhite2.w = 64;
	powbargreen.x = powbargreen2.x = powbaryellow.x = powbaryellow2.x = powbarorange.x = powbarorange2.x = powbarred.x = powbarred2.x = powbarwhite.x = powbarwhite2.x = 445;
	powbargreen.y = 247;
	powbargreen2.y = 257;
	powbaryellow.y = 167;
	powbaryellow2.y = 177;
	powbarorange.y = 187;
	powbarorange2.y = 197;
	powbarred.y = 207;
	powbarred2.y = 217;
	powbarwhite.y = 227;
	powbarwhite2.y = 237;
	pow1.x = 463;
	pow1.y = 337;
	pow1.w = 16;
	pow1.h = 11;
	pow2.x = 457;
	pow2.y = 352;
	pow2.w = 22;
	pow2.h = 15;
	pow3.x = 484;
	pow3.y = 325;
	pow3.w = 24;
	pow3.h = 20;
	pow4.x = 482;
	pow4.y = 349;
	pow4.w = 28;
	pow4.h = 24;
	fullpow1.x = 433;
	fullpow1.y = 370;
	fullpow1.w = fullpow3.w = 48;
	fullpow1.h = fullpow3.h = 39;
	fullpow2.x = 435;
	fullpow2.y = 411;
	fullpow2.w = 47;
	fullpow2.h = 35;
	fullpow3.x = 434;
	fullpow3.y = 447;
	counterpow1 = counterpow2 =timepow1=timepow2= 0;
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
	npow1 = npow2 = 0;
	startplay = false;
	finishpow1 = finishpow2 = false;
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
		App->render->Blit(textlife, 4, 20, &lifebarplayer1, 0.0f, false);
		App->render->Blit(textlife, 166, 20, &lifebarplayer2, 0.0f, false);
		if(lifeplayer1.w> 58)App->render->Blit(textlife, (136 - (player1life * 4)), 20, &lifeplayer1, 0.0f, false);
		if(lifeplayer2.w> 58)App->render->Blit(textlife, 168, 20, &lifeplayer2, 0.0f, false);



		////////NAME PLAYER///////
		App->render->Blit(textlife, 17, 35, &nameplayer, 0.0f, false);
		App->render->Blit(textlife, 253, 35, &nameplayer, 0.0f, false);


		////////POINTS////////
		App->fonts->BlitText(17, 10, font_points, "P1=");
		App->fonts->BlitText(202, 10, font_points, "P2=");
		sprintf_s(points1, 10, "%7d", pointsp1);
		App->fonts->BlitText(41, 10, font_points, points1);
		sprintf_s(points2, 10, "%7d", pointsp2);
		App->fonts->BlitText(227, 10, font_points, points2);


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
				if ((roundsp1 > 0 && lifeplayer2.w <= 58) || (roundsp2 > 0 && lifeplayer1.w <= 58) || rounds == 3) {
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
				if (lifeplayer1.w <= 58)App->render->Blit(textlife, (136 - ((int)player1life * 4)), 20, &lifebarplayer1red, 0.0f, false);
				if (lifeplayer2.w <= 58) App->render->Blit(textlife, 166, 20, &lifebarplayer2red, 0.0f, false);
			}
			else {
				if (lifeplayer1.w <= 58)App->render->Blit(textlife, (136 - ((int)player1life * 4)), 20, &lifebarplayer1white, 0.0f, false);
				if (lifeplayer2.w <= 58)App->render->Blit(textlife, 166, 20, &lifebarplayer2white, 0.0f, false);
			}
		}
		else if(rounds==3||(roundsp1==1&&roundsp2==1))App->render->Blit(textlife, 138, 12, &endmessage, 0.0f, false);
		else App->render->Blit(textlife, 138, 12, &komessage, 0.0f, false);



		//////////////POW/////////////////////
		if(npow1<11)powbargreen.w = (int)npow1*2;
		else if(npow1 < 13)	powbaryellow.w = ((int)npow1 - 10) * 2;
		else if(npow1<19){
			powbaryellow.w = ((int)npow1 - 5) * 2;
			powbargreen.w = 5 * 2;
		}
		else if(npow1 < 25){
			powbarorange.w = ((int)npow1 - 16) * 2;
			powbaryellow.w = 13 * 2;
			powbargreen.w = 3 * 2;
		}
		else if(npow1<32){
			powbarred.w = ((int)npow1 - 24)*2;
			powbarorange.w = 18 * 2;
			powbaryellow.w = 6 * 2;
			powbargreen.w = 0;
		}
		else {
			if (timepow1 == 0)timepow1 = SDL_GetTicks();
			if (SDL_GetTicks() - timepow1 >= 12000)finishpow1 = true;
			if (finishpow1 == false) {
				if (counterpow1 < 9)counterpow1++;
				else counterpow1 = 0;
				powbaryellow.w = 0;
				powbarred.w = powbarorange.w = 64;
			}
			else {
				if (counterpow1 <= 9)counterpow1 = 10;
				else counterpow1++;
				powbarred.w -= 2;
			}
		}
		if (npow2 < 11)powbargreen2.w = (int)npow2*2;
		else if (npow2 < 13) powbaryellow2.w = ((int)npow2 - 10) * 2;
		else if (npow2 < 19) {
			powbaryellow2.w = ((int)npow2 - 5) * 2;
			powbargreen2.w = 5 * 2;
		}
		else if(npow2 < 25){
			powbarorange2.w = ((int)npow2 - 16) * 2;
			powbaryellow2.w = 13 * 2;
			powbargreen2.w = 3 * 2;
		}
		else if(npow2<32){
			powbarred2.w = ((int)npow2 - 24)*2;
			powbarorange2.w = 18 * 2;
			powbaryellow2.w = 6 * 2;
			powbargreen2.w = 0;
		}
		else {
			if (timepow2 == 0)timepow2 = SDL_GetTicks();
			if (SDL_GetTicks() - timepow2 >= 12000)finishpow2 = true;
			if (finishpow2 == false) {
				if (counterpow2 < 9)counterpow2++;
				else counterpow2 = 0;
				powbaryellow2.w = 0;
				powbarred2.w = powbarorange2.w = 64;
			}
			else {
				if (counterpow2 <= 9)counterpow2 = 10;
				else counterpow2++;
				powbarred2.w -= 2;
			}
		}
		App->render->Blit(textlife, 41, 207, &powbarempty, 0.0f, false);
		App->render->Blit(textlife, 197, 207, &powbarempty2, 0.0f, false);
		App->render->Blit(textlife, (41+(64-powbargreen.w)), 207, &powbargreen, 0.0f, false);
		App->render->Blit(textlife, 197, 207, &powbargreen2, 0.0f, false);	
		if(npow1>=11)App->render->Blit(textlife, (41 + (64  -powbargreen.w- powbaryellow.w)), 207, &powbaryellow, 0.0f, false);
		if (npow2>=11)App->render->Blit(textlife, (197+powbargreen2.w), 207, &powbaryellow2, 0.0f, false);
		if (npow1 >= 19 && npow1 < 32)App->render->Blit(textlife, (41 + (64 - powbargreen.w - powbaryellow.w - powbarorange.w)), 207, &powbarorange, 0.0f, false);
		if (npow2 >= 19 && npow2 < 32)App->render->Blit(textlife, (197 + powbargreen2.w+powbaryellow2.w), 207, &powbarorange2, 0.0f, false);
		if (npow1 >= 25 && npow1 < 32)App->render->Blit(textlife, (41 + (64 - powbargreen.w - powbaryellow.w - powbarorange.w-powbarred.w)), 207, &powbarred, 0.0f, false);
		if (npow2 >= 25 && npow2 < 32)App->render->Blit(textlife, (197 + powbargreen2.w + powbaryellow2.w + powbarorange2.w), 207, &powbarred2, 0.0f, false);
		if (npow1 >= 32&&finishpow1==false) {
			if (counterpow1 < 3) App->render->Blit(textlife, 41 + (64 - powbarred.w), 207, &powbarred, 0.0f, false);
			else if (counterpow1 < 6) App->render->Blit(textlife, 41 + (64 - powbarwhite.w), 207, &powbarwhite, 0.0f, false);
			else if (counterpow1 < 9) App->render->Blit(textlife, 41 + (64 - powbarorange.w), 207, &powbarorange, 0.0f, false);
		}
		else if (npow1 >= 32 && finishpow1 == true) App->render->Blit(textlife, 41 + (64 - powbarred.w), 207, &powbarred, 0.0f, false);
		if (npow2 >= 32&&finishpow2==false) {
			if (counterpow2 < 3) App->render->Blit(textlife, 197, 207, &powbarred2, 0.0f, false);
			else if (counterpow2 < 6) App->render->Blit(textlife, 197, 207, &powbarwhite2, 0.0f, false);
			else if (counterpow2 < 9) App->render->Blit(textlife, 197, 207, &powbarorange2, 0.0f, false);
		}
		else if (npow2 >= 32 && finishpow2 == true)	App->render->Blit(textlife, 197, 207, &powbarred2, 0.0f, false);
		if (npow1 < 8)App->render->Blit(textlife, 25, 205, &pow1, 0.0f, false);
		else if (npow1 < 16) App->render->Blit(textlife, 19, 201, &pow2, 0.0f, false);
		else if (npow1 < 24)App->render->Blit(textlife, 17, 196, &pow3, 0.0f, false);
		else if (npow1 < 32)App->render->Blit(textlife, 13, 192, &pow4, 0.0f, false);
		else if (npow1 >= 32&&finishpow1==false) {
			if (counterpow1 < 3) App->render->Blit(textlife, 1, 177, &fullpow1, 0.0f, false);
			else if (counterpow1 < 6) App->render->Blit(textlife, 1, 181, &fullpow2, 0.0f, false);
			else if (counterpow1 < 9) App->render->Blit(textlife, 1, 177, &fullpow3, 0.0f, false);
		}
		else if (npow1 >= 32 && finishpow1 == true){
			if(counterpow1<20)App->render->Blit(textlife, 13, 192, &pow4, 0.0f, false);
			else if (counterpow1<30)App->render->Blit(textlife, 17, 196, &pow3, 0.0f, false);
			else if(counterpow1<40)App->render->Blit(textlife, 19, 201, &pow2, 0.0f, false);
			else App->render->Blit(textlife, 25, 205, &pow1, 0.0f, false);
			if (powbarred.w == 0) {
				npow1 = 0;
				finishpow1 = false;
				counterpow1 = 0;
				timepow1 = 0;
			}
		}
		if (npow2 < 8)App->render->Blit(textlife, 261, 205, &pow1, 0.0f, false);
		else if (npow2 < 16)App->render->Blit(textlife, 261, 201, &pow2, 0.0f, false);
		else if (npow2 < 24)App->render->Blit(textlife, 261, 196, &pow3, 0.0f, false);
		else if (npow2 < 32)App->render->Blit(textlife, 261, 192, &pow4, 0.0f, false);
		else if (npow2 >= 32&&finishpow2==false) {
			if (counterpow2 < 3) App->render->Blit(textlife, 253, 177, &fullpow1, 0.0f, false);
			else if (counterpow2 < 6) App->render->Blit(textlife, 253, 181, &fullpow2, 0.0f, false);
			else if (counterpow2 < 9) App->render->Blit(textlife, 253, 177, &fullpow3, 0.0f, false);
		}
		else if (npow2 >= 32 && finishpow2 == true) {
			if (counterpow2 < 20)App->render->Blit(textlife, 261, 192, &pow4, 0.0f, false);
			else if (counterpow2 < 30)App->render->Blit(textlife, 261, 196, &pow3, 0.0f, false);
			else if (counterpow2 < 40)App->render->Blit(textlife, 261, 201, &pow2, 0.0f, false);
			else App->render->Blit(textlife, 261, 205, &pow1, 0.0f, false);
			if (powbarred2.w == 0) {
				npow2 = 0;
				finishpow2 = false;
				counterpow2 = 0;
				timepow2 = 0;
			}
		}



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
					lifescore /= 10;
					lifescore *= 10;
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
					if (counter >= 20&&counter<58) {
						if (App->input->keyboardstate[SDL_SCANCODE_SPACE]) {
							App->audio->PlayChunk(sumpoints, -1);
							if(counter<22)hitsscore= ((float)hitsscore / (float)100) * 20000;
							if(victory==1)pointsp1+=lifescore+timescore+ hitsscore;
							else pointsp2+= lifescore + timescore + hitsscore;
							totalscore+= lifescore + timescore + hitsscore;
							App->audio->PlayChunk(sumpoints2);
							lifescore = hitsscore = timescore = 0;
							counter = 58;
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
					if (counter>79) {
						play = false;
						victory = 0;
						if (rounds != 4 && roundsp1 < 2 && roundsp2 < 2)(App->fade->FadeToBlack(App->background, App->background));
						else {
							App->background->fade = true;
							rounds = 0;
							npow1 = npow2 = 0;
							roundsp1 = roundsp2 = 0;
							counterpow1 = counterpow2 = timepow1 = timepow2 = 0;
							finishpow1 = finishpow2 = false;
						}
					}
					if (counter <= 79) {
						
						if (counter == 57 || counter == 58) {
							App->audio->StopChunk();
							App->audio->PlayChunk(sumpoints2);
							counter = 58;
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
	if (App->SNKMenu->IsEnabled() == false||credits>0) {
		App->render->Blit(level4, 131, 216, &level4rect, 0.0f, false);
		if(credits<2)App->render->Blit(level4, 221, 216, &creditrect, 0.0f, false);
		else App->render->Blit(level4, 221, 216, &creditsrect, 0.0f, false);
		sprintf_s(creditsc, 10, "%02d", credits);
		App->fonts->BlitText(268, 216, font_credits, creditsc);
	}

	return UPDATE_CONTINUE;
}

void ModuleUI::DamageTaken(int numplayer, float damage, float pow) {
	if (numplayer == 1) {
		player1life -= damage;
		if (player1life < 0)player1life = 0;
		pointsp2 += 50;
		if(npow1<32)npow1+=pow;
	}
	else if (numplayer == 2) {
		player2life -= damage;
		if (player2life < 0)player2life = 0;
		pointsp1 += 50;
		if(npow2<32)npow2+=pow;
	}
}
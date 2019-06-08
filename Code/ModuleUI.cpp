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


ModuleUI::ModuleUI(){
	////engarde
	engarde.PushBack({0, 302'5, 175, 4'5});
	engarde.PushBack({0, 296'5, 175, 6'5});
	engarde.PushBack({0, 288'5, 175, 7});
	engarde.PushBack({0, 278, 175, 10'5});
	engarde.PushBack({0, 265, 175, 12'5});
	engarde.PushBack({0, 251, 175, 14'5});
	engarde.PushBack({0, 235, 175, 16'5});
	engarde.PushBack({0, 217, 175, 18});
	engarde.PushBack({0, 197, 175, 19});
	engarde.PushBack({0, 173'5, 175, 23'5});
	engarde.PushBack({0, 149, 175, 24'5});
	engarde.PushBack({0, 123, 175, 26'5});
	engarde.PushBack({0, 94'5, 175, 29'5});
	engarde.PushBack({0, 64, 175, 30});
	engarde.PushBack({0, 31'5, 175, 32});
	engarde.PushBack({0, 0, 175, 32'5});
	

	////begin
	begin.PushBack({177'5, 326, 20'5, 10});
	begin.PushBack({177'5, 338, 32, 16});
	begin.PushBack({177'5, 353'5, 46'5, 24'5});
	begin.PushBack({ 101, 317, 60, 28});
	begin.PushBack({ 101, 346, 72, 35});
	begin.PushBack({0, 321, 84, 41});
	begin.PushBack({0, 363, 97, 47});
	begin.PushBack({0, 412, 104, 49});
	begin.PushBack({0, 462, 104, 50});

	////duel
	duel.PushBack({ 243, 112, 165, 5});
	duel.PushBack({ 243, 116, 165, 6'5});
	duel.PushBack({ 243, 122, 165, 8'5});
	duel.PushBack({ 243, 130, 165, 11});
	duel.PushBack({ 243, 141'5, 165, 10});
	duel.PushBack({ 243, 152, 165, 13'5});
	duel.PushBack({ 243, 165, 165, 16'5});
	duel.PushBack({ 243, 181, 165, 18});
	duel.PushBack({ 243, 199'5, 165, 20});
	duel.PushBack({ 243, 219, 165, 22'5});
	duel.PushBack({ 243, 241'5, 165, 23'5});
	duel.PushBack({ 243, 265, 165, 25});
	duel.PushBack({ 243, 290, 165, 29});
	duel.PushBack({ 243, 318, 165, 29'5});
	duel.PushBack({ 243, 348, 165, 33});
	duel.PushBack({ 384, 109, 61, 32});
	duel.PushBack({ 384, 139'5, 57, 29'5});
	duel.PushBack({ 384, 168, 54, 27});
	duel.PushBack({ 384, 194'5, 49, 26'5});
	duel.PushBack({ 384, 223, 45, 23'5});
	duel.PushBack({ 384, 247, 42, 21});
	duel.PushBack({ 384, 269, 38, 19});
	duel.PushBack({ 384, 288'5, 34, 17'5});
	duel.PushBack({ 384, 309'5, 30, 15'5});
	duel.PushBack({ 384, 325'5, 26, 13'5});
	duel.PushBack({ 384, 341, 22, 11});
	duel.PushBack({ 384, 353'5, 18, 9'5});
	duel.PushBack({ 384, 364, 14, 7});
	duel.PushBack({ 384, 372, 10, 5});

	////perfect
	perfect.PushBack({ 424, 499, 16'5, 15});
	perfect.PushBack({ 423, 488, 23, 23});
	perfect.PushBack({ 390, 484, 30'5, 30});
	perfect.PushBack({ 351, 484, 36, 36});
	perfect.PushBack({ 302, 483, 43'5, 43});
	perfect.PushBack({ 245'5, 483, 50'5, 51'5});
	perfect.PushBack({ 183, 483, 57, 57});
	perfect.PushBack({ 113, 483, 65, 64});
	perfect.PushBack({ 374'5, 438, 70'5, 71});
	perfect.PushBack({ 294, 438, 77, 77});
	perfect.PushBack({ 207, 438, 84'5, 84});
	perfect.PushBack({ 113, 438, 92, 92});
	perfect.PushBack({ 335, 384, 97, 98});
	perfect.PushBack({ 228, 384, 104, 105});
	perfect.PushBack({ 113, 384, 112, 112});

	////welldone
	welldone.PushBack({ 465, 101, 20, 5});
	welldone.PushBack({ 465, 93, 29, 7});
	welldone.PushBack({ 465, 81, 46, 11});
	welldone.PushBack({ 405, 94'5, 56, 14'5});
	welldone.PushBack({ 340, 93, 65, 17});
	welldone.PushBack({ 266, 92, 74, 18});
	welldone.PushBack({ 183, 91'5, 83, 19'5});
	welldone.PushBack({ 333, 75, 92, 20});
	welldone.PushBack({ 333, 52'5, 100, 21'5});
	welldone.PushBack({ 333, 28, 108, 24'5});
	welldone.PushBack({ 333, 0, 117, 27'5});
	welldone.PushBack({ 183, 63, 127, 30});
	welldone.PushBack({ 183, 136, 136, 30'5});
	welldone.PushBack({ 183, 0, 145, 32});
}
ModuleUI::~ModuleUI() {}
bool ModuleUI::Init() {
	font_score = App->fonts->Load("Sprites/Numbers FONT.png", "0123456789-.,defghij", 2);
	font_score_white = App->fonts->Load("Sprites/WhiteNumbersFONT.png", "0123456789", 1);
	font_points = App->fonts->Load("Sprites/NumbersUIPlayers.png", "0123456789P=", 1);
	font_credits = App->fonts->Load("Sprites/NumbersCreditsFONT.png", "0123456789", 1);
	font_finalpoints = App->fonts->Load("Sprites/YellowNumbersAndPercent.png", "0123456789%", 1);
	textlife = App->textures->Load("Sprites/Sprite_Sheet_UI_1.png");
	textletters = App->textures->Load("Sprites/Sprite_Sheet_UI_2.png");
	level4 = App->textures->Load("Sprites/CreditsandLevel4.png");
	sumpoints = App->audio->LoadChunk("Audio_FX/End_Combat_Points.wav");
	sumpoints2 = App->audio->LoadChunk("Audio_FX/Enter_in_Menu.wav");
	creditsound = App->audio->LoadChunk("Audio_FX/Credits.wav");
	lastsecssound = App->audio->LoadChunk("Audio_FX/TimeOUT.wav");
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
	startletters = finishletters = true;
	totalscore = lifescore = timescore = hitsscore = 0;
	finished = false;
	toperfect = false;
	return true;
}
bool ModuleUI::CleanUp() {
	App->audio->StopChunk();
	App->audio->UnLoadChunk(lastsecssound);
	App->audio->UnLoadChunk(creditsound);
	App->audio->UnLoadChunk(sumpoints);
	App->audio->UnLoadChunk(sumpoints2);
	App->fonts->UnLoad(font_finalpoints);
	App->fonts->UnLoad(font_score);
	App->fonts->UnLoad(font_score_white);
	App->fonts->UnLoad(font_points);
	App->fonts->UnLoad(font_credits);
	App->textures->Unload(textletters);
	App->textures->Unload(textlife);
	App->textures->Unload(level4);
	return true;
}
update_status ModuleUI::Update() {
	////////////////EN GARDE AND BEGIN//////////////////
	if (App->background->IsEnabled() == true && App->fade->finished == true&&startletters==true) {
		Animation* current_animation=&engarde;
		if (engarde.finished == true)current_animation = &duel;
		if (duel.finished == true)current_animation = &begin;
		App->render->Blit(textletters, 100, 100, &(current_animation->GetCurrentFrame()), 1.0f, false);
		if(begin.finished==true)startletters = false;
	}
	if (play == true && App->fade->finished == true&&startletters==false) {
		///////TIMER/////////
		int oldtime=0;
		if (finished == false)startplay = true;
		else startplay = false;
		if (doinitialtime == true) {
			initialtime = SDL_GetTicks();
			doinitialtime = false;
		}
		if (finished == false) {
			if (time / 1000 <= 15) oldtime = time;
			time = (100000) - (SDL_GetTicks() - initialtime);
		}
		sprintf_s(time_text, 10, "%7d", (time / 1000));
		if (time / 1000 <= 15) {
			if (oldtime / 1000 != time / 1000)App->audio->PlayChunk(lastsecssound, 0, -1);
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
		if (finishpow1 == true)npow1--;
		if (finishpow2 == true)npow2--;
		if (npow1 == 0) { finishpow1 = false; timepow1 = 0; counterpow1 = 0; }
		if (npow2 == 0) { finishpow2 = false; timepow2 = 0; counterpow2 = 0; }
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
			npow1 = 32;
			if (timepow1 == 0)timepow1 = SDL_GetTicks();
			if (SDL_GetTicks() - timepow1 >= 12000)finishpow1 = true;
			if (finishpow1 == false) {
				if (counterpow1 < 9)counterpow1++;
				else counterpow1 = 0;
				powbaryellow.w = 0;
				powbarred.w = powbarorange.w = 64;
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
			npow2 = 32;
			if (timepow2 == 0)timepow2 = SDL_GetTicks();
			if (SDL_GetTicks() - timepow2 >= 12000)finishpow2 = true;
			if (finishpow2 == false) {
				if (counterpow2 < 9)counterpow2++;
				else counterpow2 = 0;
				powbaryellow2.w = 0;
				powbarred2.w = powbarorange2.w = 64;
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
		else if (npow1 >= 32 && finishpow1 == true)App->render->Blit(textlife, 13, 192, &pow4, 0.0f, false);
		if (npow2 < 8)App->render->Blit(textlife, 261, 205, &pow1, 0.0f, false);
		else if (npow2 < 16)App->render->Blit(textlife, 261, 201, &pow2, 0.0f, false);
		else if (npow2 < 24)App->render->Blit(textlife, 261, 196, &pow3, 0.0f, false);
		else if (npow2 < 32)App->render->Blit(textlife, 261, 192, &pow4, 0.0f, false);
		else if (npow2 >= 32&&finishpow2==false) {
			if (counterpow2 < 3) App->render->Blit(textlife, 253, 177, &fullpow1, 0.0f, false);
			else if (counterpow2 < 6) App->render->Blit(textlife, 253, 181, &fullpow2, 0.0f, false);
			else if (counterpow2 < 9) App->render->Blit(textlife, 253, 177, &fullpow3, 0.0f, false);
		}
		else if (npow2 >= 32 && finishpow2 == true) App->render->Blit(textlife, 261, 192, &pow4, 0.0f, false);



		///////////ONE PLAYER DEFEATED//////
		if ((lifeplayer1.w <= 0||victory==2||rounds==4)&&finished==false) {
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
			if (finishletters == true) {
				Animation* current_animation;
				if (victory != 0 && (roundsp1 == 2 || roundsp2 == 2 || rounds == 4));//victory
				else if (victory != 0);//ippon
				else;//timeup
				//if victory/ippon finished and if (roundsp1 == 2 || roundsp2 == 2 || rounds == 4) well done && ukyo
				//else if victory/ippon finished ukyo
				//else draw
				//if ukyo finished && (player1life==32||player2life==32)perfect
				//else if ukyo finished perfect.Finished()
				//if draw finished && rounds==4 duel finished
				//else if draw finished duelfinished.Finished()
				//}
				//Blit
				/*if ukyo/duelfinished finished*/finishletters = false;
			}
			if (totalscore == 0 && hitsscore == 0 && lifescore == 0 && timescore == 0&&finishletters==false) {
				initialtime = SDL_GetTicks();
				App->render->zoom = false;
				if (victory != 0) {
					timescore = time / 1000;
					timescore *= 100;
					if (victory == 1) {
						lifescore = player1life * 200;
						lifescore /= 10;
						lifescore *= 10;
						if (App->player->nattacks > 0)hitsscore = ((float)App->player->nattackss / (float)App->player->nattacks) * 100;
					}
					else if (victory == 2) {
						lifescore = player2life * 200;
						lifescore /= 10;
						lifescore *= 10;
						if (App->player2->nattacks > 0)hitsscore = ((float)App->player2->nattackss / (float)App->player2->nattacks) * 100;
					}
				}
				else totalscore++;
			}
			if ((SDL_GetTicks() - initialtime >= 2000||victory==0)&&finishletters==false) {
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
				else counter = 80;
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
	else if(startletters==false){
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
		startletters = true;
		finishletters = true;
		totalscore = lifescore = timescore = hitsscore = 0;
		engarde.Reset();
		duel.Reset();
		begin.Reset();
		welldone.Reset();
		perfect.Reset();
		//RESET ALL NEW ANIMATIONS
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
		if (npow1 < 32 || finishpow1 == false)npow1 += pow;
	}
	else if (numplayer == 2) {
		player2life -= damage;
		if (player2life < 0)player2life = 0;
		pointsp1 += 50;
		if (npow2 < 32 || finishpow2 == false)npow2 += pow;
	}
}

void ModuleUI::newcredit() {
	App->audio->PlayChunk(creditsound, 0, -1);
}
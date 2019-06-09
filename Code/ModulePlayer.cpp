#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModulePlayer.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleUI.h"
#include "ModulePlayer2.h"
#include "Modulebackground.h"
#include "StateMachine.h"
#include "ModuleUI.h"
#include "ModuleSlowdown.h"
#include "SDL/include/SDL_timer.h"


ModulePlayer::ModulePlayer()
{
	position.x = 50;
	position.y = 210;

	// Idle animation
	idle.PushBack({ 0, 0, 75, 137 });
	idle.PushBack({ 75, 0, 75, 137 });
	idle.speed = 0.02f;


	// Walk forward animation
	forward.PushBack({ 185, 0, 75, 137 });
	forward.PushBack({ 260, 0, 72, 137 });
	forward.PushBack({ 332, 0, 81, 137 });
	forward.PushBack({ 413, 0, 87, 137 });
	forward.PushBack({ 500, 0, 81, 137 });
	forward.PushBack({ 581, 0, 72, 137 });
	forward.PushBack({ 653, 0, 75, 137 });
	forward.speed = 0.2f;


	// Walk backwards animation
	backward.PushBack({ 653, 0, 75, 137 });
	backward.PushBack({ 581, 0, 72, 137 });
	backward.PushBack({ 500, 0, 81, 137 });
	backward.PushBack({ 413, 0, 87, 137 });
	backward.PushBack({ 332, 0, 81, 137 });
	backward.PushBack({ 260, 0, 72, 137 });
	backward.PushBack({ 185, 0, 75, 137 });
	backward.speed = 0.2f;


	// Stronger Kick animation
	strongerkick.PushBack({  15, 190, 70, 86 });
	strongerkick.PushBack({ 114, 190, 66, 86 });
	strongerkick.PushBack({ 202, 190, 67, 86 });
	strongerkick.PushBack({ 302, 190, 82, 86 });
	strongerkick.PushBack({ 402, 190, 100, 86 });
	strongerkick.speed = 0.2f;

	// Kick animation
	kick.PushBack({ 0, 411, 97, 137 });
	kick.PushBack({ 97, 411, 97, 137 });
	kick.PushBack({ 194, 411, 97, 137 });
	kick.PushBack({ 97, 411, 97, 137 });
	kick.PushBack({ 0, 411, 97, 137 });
	kick.speed = 0.2f;



	//crouch
	crouch.PushBack({ 1243 , 274 , 75 , 137 });
	crouch.PushBack({ 1318 , 274 , 68 , 137 });
	crouch.PushBack({ 1386 , 274 , 67 , 137 });
	crouch.speed = 0.2f;
	

	//crouchfinished
	crouchfinished.PushBack({ 1386 , 274 , 67 , 137 });
	crouchfinished.speed = 0.2f;


	// Punch animation (TO IMPROVE)
	punch.PushBack({ 0, 274, 117, 137 });
	punch.PushBack({ 117, 274, 117, 137 });
	punch.PushBack({ 234, 274, 117, 137 });
	punch.PushBack({ 351, 274, 117, 137 });
	punch.PushBack({ 468, 274, 117, 137 });
	punch.PushBack({ 351, 274, 117, 137 });
	punch.PushBack({ 234, 274, 117, 137 });
	punch.PushBack({ 117, 274, 117, 137 });
	punch.PushBack({ 0, 274, 117, 137 });
	punch.speed = 0.4f;

	// Jump
	jump.PushBack({ 761, 0, 75, 137 });
	jump.PushBack({ 836, 0, 68, 137 });
	jump.PushBack({ 904, 0, 75, 137 });
	jump.PushBack({ 979, 0, 61, 137 });
	jump.PushBack({ 1040, 0, 66, 137 });
	jump.PushBack({ 1106, 0, 63, 137 });
	jump.PushBack({ 1106, 0, 63, 137 });
	jump.PushBack({ 1040, 0, 66, 137 });
	jump.PushBack({ 979, 0, 61, 137 });
	jump.PushBack({ 904, 0, 75, 137 });
	jump.PushBack({ 836, 0, 68, 137 });
	jump.PushBack({ 761, 0, 75, 137 });
	jump.speed = 0.1f;


	// Jump Forward
	jumpforward.PushBack({ 761, 0, 75, 137 });
	jumpforward.PushBack({ 836, 0, 68, 137 });
	jumpforward.PushBack({ 904, 0, 75, 137 });
	jumpforward.PushBack({ 979, 0, 61, 137 });
	jumpforward.PushBack({ 1040, 0, 66, 137 });
	jumpforward.PushBack({ 1106, 0, 63, 137 });
	jumpforward.PushBack({ 1169, 0, 61, 137 });
	jumpforward.PushBack({ 1106, 0, 63, 137 });
	jumpforward.PushBack({ 1040, 0, 66, 137 });
	jumpforward.PushBack({ 979, 0, 61, 137 });
	jumpforward.PushBack({ 904, 0, 75, 137 });
	jumpforward.PushBack({ 836, 0, 68, 137 });
	jumpforward.PushBack({ 761, 0, 75, 137 });
	jumpforward.speed = 0.1f;


	// Jump backwards
	jumpbackward.PushBack({ 761, 0, 75, 137 });
	jumpbackward.PushBack({ 836, 0, 68, 137 });
	jumpbackward.PushBack({ 904, 0, 75, 137 });
	jumpbackward.PushBack({ 979, 0, 61, 137 });
	jumpbackward.PushBack({ 1040, 0, 66, 137 });
	jumpbackward.PushBack({ 1106, 0, 63, 137 });
	jumpbackward.PushBack({ 1169, 0, 61, 137 });
	jumpbackward.PushBack({ 1106, 0, 63, 137 });
	jumpbackward.PushBack({ 1040, 0, 66, 137 });
	jumpbackward.PushBack({ 979, 0, 61, 137 });
	jumpbackward.PushBack({ 904, 0, 75, 137 });
	jumpbackward.PushBack({ 836, 0, 68, 137 });
	jumpbackward.PushBack({ 761, 0, 75, 137 });
	jumpbackward.speed = 0.1f;



	//AppleAttack
	appleattack.PushBack({ 0, 959, 200, 157 });
	appleattack.PushBack({ 200, 959, 200, 157 });
	appleattack.PushBack({ 400, 959, 200, 157 });
	appleattack.PushBack({ 600, 959, 200, 157 });
	appleattack.PushBack({ 800, 959, 200, 157 });
	appleattack.PushBack({ 1000, 959, 200, 157 });
	appleattack.PushBack({ 1200, 959, 200, 157 });
	appleattack.PushBack({ 1400, 959, 200, 157 });
	appleattack.PushBack({ 1600, 959, 200, 157 });
	appleattack.PushBack({ 1800, 959, 200, 157 });
	appleattack.PushBack({ 0, 1115, 200, 157 });
	appleattack.PushBack({ 200, 1115, 200, 157 });
	appleattack.PushBack({ 400, 1115, 200, 157 });
	appleattack.PushBack({ 600, 1115, 200, 157 });
	appleattack.PushBack({ 800, 1115, 200, 157 });
	appleattack.PushBack({ 1000, 1115, 200, 157 });
	appleattack.PushBack({ 1200, 1115, 200, 157 });
	appleattack.PushBack({ 1400, 1115, 200, 157 });
	appleattack.PushBack({ 1600, 1115, 200, 157 });
	appleattack.PushBack({ 1800, 1115, 200, 157 });
	appleattack.PushBack({ 0, 1271, 200, 157 });
	appleattack.PushBack({ 200, 1271, 200, 157 });
	appleattack.PushBack({ 400, 1271, 200, 157 });
	appleattack.PushBack({ 600, 1271, 200, 157 });
	appleattack.PushBack({ 800, 1271, 200, 157 });
	appleattack.PushBack({ 1000, 1271, 200, 157 });
	appleattack.PushBack({ 1200, 1271, 200, 157 });
	appleattack.PushBack({ 1400, 1271, 200, 157 });
	appleattack.PushBack({ 1600, 1271, 200, 157 });
	appleattack.PushBack({ 1800, 1271, 200, 157 });
	appleattack.PushBack({ 0, 1426, 200, 157 });
	appleattack.PushBack({ 200, 1426, 200, 157 });
	appleattack.PushBack({ 400, 1426, 200, 157 });
	appleattack.PushBack({ 600, 1426, 200, 157 });
	appleattack.PushBack({ 800, 1426, 200, 157 });
	appleattack.PushBack({ 1000, 1426, 200, 157 });
	appleattack.PushBack({ 1200, 1426, 200, 157 });
	appleattack.PushBack({ 1400, 1426, 200, 157 });
	appleattack.PushBack({ 1600, 1426, 200, 157 });
	appleattack.PushBack({ 1800, 1426, 200, 157 });
	appleattack.PushBack({ 0, 1582, 200, 157 });
	appleattack.PushBack({ 200, 1582, 200, 157 });
	appleattack.PushBack({ 400, 1582, 200, 157 });
	appleattack.PushBack({ 600, 1582, 200, 157 });
	appleattack.PushBack({ 800, 1582, 200, 157 });
	appleattack.PushBack({ 1000, 1582, 200, 157 });
	appleattack.PushBack({ 1200, 1582, 200, 157 });
	appleattack.PushBack({ 1400, 1582, 200, 157 });
	appleattack.PushBack({ 1600, 1582, 200, 157 });
	appleattack.PushBack({ 1800, 1582, 200, 157 });
	appleattack.PushBack({ 0, 1739, 200, 157 });
	appleattack.PushBack({ 200, 1739, 200, 157 });
	appleattack.PushBack({ 400, 1739, 200, 157 });
	appleattack.PushBack({ 600, 1739, 200, 157 });
	appleattack.PushBack({ 800, 1739, 200, 157 });
	appleattack.PushBack({ 1000, 1739, 200, 157 });
	appleattack.PushBack({ 1200, 1739, 200, 157 });
	appleattack.PushBack({ 1400, 1739, 200, 157 });
	appleattack.PushBack({ 1600, 1739, 200, 157 });
	appleattack.PushBack({ 1800, 1739, 200, 157 });
	appleattack.speed = 0.2f;

	//Animation hitted;
	hittedan.PushBack({ 1920, 0, 67, 137 });
	hittedan.PushBack({ 1987, 0, 75, 137 });
	hittedan.speed = 0.1f;

	//Punch jumping;
	punchair.PushBack({ 1168 , 137 , 76 , 137 });
	punchair.PushBack({ 1244 , 137 , 69 ,  137 });
	punchair.PushBack({ 1313 , 137 , 89 , 137 });
	punchair.PushBack({ 1402 , 137 , 143 , 137 });
	punchair.PushBack({ 1545 , 137 , 147 , 137 });
	punchair.PushBack({ 1692 , 137 , 149 ,  137 });
	punchair.PushBack({ 1313 , 137 , 89 , 137 });
	punchair.PushBack({ 1244 , 137 , 69 ,  137 });
	punchair.PushBack({ 1168 , 137 , 76 , 137 });
	punchair.speed = 0.25f;

	//Punch crouch;
	punchcrouch.PushBack({ 570 , 411 , 169 , 137 });
	punchcrouch.PushBack({ 739 , 411 , 169 , 137 });
	punchcrouch.PushBack({ 908 , 411 , 169 , 137 });
	punchcrouch.PushBack({ 1077 , 411 , 169 , 137 });
	punchcrouch.PushBack({ 1246 , 411 , 169 , 137 });
	punchcrouch.PushBack({ 1415 , 411 , 169 , 137 });
	punchcrouch.PushBack({ 1584 , 411 , 169 , 137 });
	punchcrouch.PushBack({ 1415 , 411 , 169 , 137 });
	punchcrouch.PushBack({ 1246 , 411 , 169 , 137 });
	punchcrouch.PushBack({ 1077 , 411 , 169 , 137 });
	punchcrouch.PushBack({ 908 , 411 , 169 , 137 });
	punchcrouch.PushBack({ 739 , 411 , 169 , 137 });
	punchcrouch.PushBack({ 570 , 411 , 169 , 137 });
	punchcrouch.speed = 0.3f;

	////////////Kick jumping;
	kickair.PushBack({ 511 , 137 , 61 , 137 });
	kickair.PushBack({ 572 , 137 , 83 , 137 });
	kickair.PushBack({ 655 , 137 , 111 , 137 });
	kickair.PushBack({ 766 , 137 , 96 , 137 });
	kickair.speed = 0.3f;

	///////////Kick crouch;
	kickcrouch.PushBack({ 1665, 334, 69, 80});
	kickcrouch.PushBack({ 1734, 334, 67, 80});
	kickcrouch.PushBack({ 1801, 334, 81, 80});
	kickcrouch.PushBack({ 1882, 334, 100,80});
	kickcrouch.PushBack({ 1982, 334, 68, 80});
	kickcrouch.speed = 0.3f;

	///////////Lost weapon;
	lostweapon.PushBack({ 1778, 477, 40, 72 });
	lostweapon.PushBack({ 1818, 477, 42, 72 });
	lostweapon.speed = 0.2f;

	///////////Clash swords;
	clashswords.PushBack({ 915, 1920, 65, 113 });
	clashswords.PushBack({ 980, 1920, 71'5, 113 });
	clashswords.PushBack({ 1051'5, 1920, 97'5, 113 });


	//Shadow animation
	shadow.PushBack({ 2005, 411, 70, 14 });
	shadow.PushBack({ 2005, 425, 70, 14 });
	shadow.speed = 0.4f;

	///////////Pre  battle animation;
	prebattle.PushBack({ 19, 1937 , 67 , 96 });
	prebattle.PushBack({ 93 , 1937 , 66 , 96 });
	prebattle.PushBack({ 173 , 1937 , 69 , 96 });
	prebattle.PushBack({ 242, 1937 , 76 , 96 });
	prebattle.PushBack({ 318, 1937 , 76 , 96 });
	prebattle.PushBack({ 394, 1937 , 79 , 96 });
	prebattle.PushBack({ 473, 1937 , 78 , 96 });
	prebattle.PushBack({ 553, 1937 , 75 , 96 });
	prebattle.PushBack({ 644, 1937 , 65 , 96 });
	prebattle.PushBack({ 727, 1937 , 65 , 96 });
	prebattle.PushBack({ 811 , 1937 , 65 , 96 });


	///////////Winner animation;
	win.PushBack({ 0,  2031'5 , 62'5 , 138'5 });
	win.PushBack({ 62'5 , 2031'5 , 69 , 138'5 });
	win.PushBack({ 131'5, 2031'5 , 79 , 138'5 });
	win.PushBack({ 210'5, 2031'5 , 105 , 138'5 });
	win.PushBack({ 315'5, 2031'5 , 111 , 138'5 });
	win.PushBack({ 426'5, 2031'5 , 98'5 , 138'5 });
	win.PushBack({ 525, 2031'5 , 102'5 , 138'5 });
	win.PushBack({ 627'5, 2031'5 , 104'5 , 138'5 });
	win.PushBack({ 732, 2031'5 , 96'5 , 138'5 });
	win.PushBack({ 828'5, 2031'5 , 129 , 138'5 });
	win.PushBack({ 957'5, 2031'5 , 124 , 138'5 });
	win.PushBack({ 1081'5, 2031'5 , 79 , 138'5 });
	win.PushBack({ 1160'5, 2031'5 , 69'5 , 138'5 });
	win.PushBack({ 1230, 2031'5 , 64'5 , 138'5 });
	win.PushBack({ 1294'5, 2031'5 , 65 , 138'5 });
	win.PushBack({ 1359'5, 2031'5 , 65'5 , 138'5 });
	win.PushBack({ 1425, 2031'5 , 65 , 138'5 });

	///////////Fire eagle;
	firebird.PushBack({ 0, 550, 67, 137});
	firebird.PushBack({ 67, 550, 67, 137 });
	firebird.PushBack({ 134, 550, 79, 137 });
	firebird.PushBack({ 213, 550, 89, 137 });
	firebird.PushBack({ 314, 550, 189, 137 });
	firebird.PushBack({ 503, 550, 186, 137 });
	firebird.PushBack({ 689, 550, 120, 137 });
	firebird.PushBack({ 809, 550, 69, 137 });
	firebird.PushBack({ 878, 550, 70, 137 });
	firebird.PushBack({ 948, 550, 86, 137 });
	firebird.PushBack({ 1034, 550, 57, 137 });
	firebird.PushBack({ 1091, 550, 75, 137 });
	firebird.speed = 0.2f;
	
	///////////Roll attack;
	rollattack.PushBack({ 0, 756, 71,  825 });
	rollattack.PushBack({ 190, 756, 74, 825 });
	rollattack.PushBack({ 406, 756, 86, 825 });
	rollattack.PushBack({ 600, 756, 96, 825 });
	rollattack.PushBack({ 794, 756, 112, 825 });
	rollattack.PushBack({ 985, 756, 178, 825 });
	rollattack.PushBack({ 1180, 756, 174,  825 });
	rollattack.PushBack({ 1370, 756, 178, 825});
	rollattack.PushBack({ 1564, 756, 177, 825 });
	rollattack.PushBack({ 1758, 756, 174, 825 });
	rollattack.PushBack({ 22, 756, 172, 97 });
	rollattack.PushBack({ 214, 756, 139, 97 });
	rollattack.PushBack({ 400, 756, 78, 97 });
	rollattack.PushBack({ 580, 756, 92, 97 });
	rollattack.PushBack({ 768, 756, 93, 97 });
	rollattack.PushBack({ 976, 756, 78, 97 });
	//rollattack.speed=0.2f;


	///////////Air hitted;
	airhitted.PushBack({ 1215,  1941, 82, 96 });
	airhitted.PushBack({ 1297, 1941, 97, 96 });
	airhitted.PushBack({ 1394, 1941, 126'3, 96 });
	airhitted.PushBack({ 1520'3, 1941, 125'9, 96 });
	airhitted.PushBack({ 1646'2, 1941, 125'8, 96 });
	airhitted.PushBack({ 1772, 1941, 96, 96 });
	airhitted.PushBack({ 1868, 1941, 70'6, 96 });
	airhitted.PushBack({ 1938'6, 1941, 43'4, 96 });
	airhitted.PushBack({ 1982, 1941, 76'5,96 });
	//airhitted.speed=0.2f;

	///////////Strong slash;
	strongerslash.PushBack({43,   2488'5, 75, 91'5});
	strongerslash.PushBack({ 202, 2488'5, 83, 91'5});
	strongerslash.PushBack({ 352, 2488'5, 86, 91'5});
	strongerslash.PushBack({ 513, 2488'5, 84, 91'5});
	strongerslash.PushBack({ 663, 2488'5, 97, 91'5});
	strongerslash.PushBack({ 834, 2488'5, 145, 91'5 });
	//strongerslash.speed = 0.2f;
	
	/////////////////////////////////////////////
	///////animations ukyo no weapon////////////
	///////////////////////////////////////////

	/////punchair no weapon
	punchair_noweapon.PushBack({ 1299 , 2497 , 56 , 83 });
	punchair_noweapon.PushBack({ 1378 , 2497 , 80 , 76 });
	punchair_noweapon.PushBack({ 1465 , 2497 , 84 , 77 });
	punchair_noweapon.PushBack({ 1465 , 2497 , 84 , 77 });
	punchair_noweapon.PushBack({ 1378 , 2497 , 80 , 76 });
	punchair_noweapon.PushBack({ 1299 , 2497 , 56 , 83 });
	punchair_noweapon.speed = 0.2f;


	/////strogpunch no weapon
	strongpunch_noweapon.PushBack({20 , 2771 , 56 , 83 });
	strongpunch_noweapon.PushBack({77 , 2771 , 79 , 83});
	strongpunch_noweapon.PushBack({});
	strongpunch_noweapon.speed=0.2f;



	////punchcrouch no weapon
	punchcrouch_noweapon.PushBack({1299 , 2497 , 56 , 83});
	punchcrouch_noweapon.PushBack({1378 , 2497 , 80 , 76});
	punchcrouch_noweapon.PushBack({1465 , 2497 , 84 , 77});
	punchcrouch_noweapon.PushBack({1465 , 2497 , 84 , 77});
	punchcrouch_noweapon.PushBack({1378 , 2497 , 80 , 76});
	punchcrouch_noweapon.PushBack({1299 , 2497 , 56 , 83});
	punchcrouch_noweapon.speed=0.2f;

	/////kick no weapon
	kick_noweapon.PushBack({998 , 2493 , 77 , 87});
	kick_noweapon.PushBack({1086 , 2493 , 89 , 88});
	kick_noweapon.PushBack({1174 , 2493 , 97 , 88});
	kick_noweapon.PushBack({1174 , 2493 , 97 , 88});
	kick_noweapon.PushBack({1086 , 2493 , 89 , 88});
	kick_noweapon.PushBack({998 , 2493 , 77 , 87});
	kick_noweapon.speed=0.2f;


	//// kickair no weapon
	kickair_noweapon.PushBack({0, 2634 , 63 , 84});
	kickair_noweapon.PushBack({60 , 2634 , 85 , 84});
	kickair_noweapon.PushBack({144 , 2631 , 111 , 84});
	kickair_noweapon.PushBack({ 144 , 2631 , 111 , 84 });
	kickair_noweapon.PushBack({ 60 , 2634 , 85 , 84 });
	kickair_noweapon.PushBack({ 0, 2634 , 63 , 84 });
	kickair_noweapon.speed=0.2f;

	//// kickcrouch no weapon
	kickcrouch_noweapon.PushBack({302 , 2787 , 69 , 67});
	kickcrouch_noweapon.PushBack({402 , 2787 , 64 , 67});
	kickcrouch_noweapon.PushBack({484 , 2787 , 72 , 67});
	kickcrouch_noweapon.PushBack({684 , 2787 , 104 , 67});
	kickcrouch_noweapon.PushBack({684 , 2787 , 104 , 67});
	kickcrouch_noweapon.PushBack({484 , 2787 , 72 , 67});
	kickcrouch_noweapon.PushBack({402 , 2787 , 64 , 67});
	kickcrouch_noweapon.PushBack({302 , 2787 , 69 , 67});
	kickcrouch_noweapon.speed = 0.2f;

	////agarre
	agarre_noweapon.PushBack({992 , 2621 , 73 , 96});
	agarre_noweapon.PushBack({1065 , 2621 , 68 , 96});
	agarre_noweapon.PushBack({1132 , 2621 , 66 , 96});
	agarre_noweapon.PushBack({1196 , 2621 , 58 , 96});
	agarre_noweapon.speed=0.2f;

	/////slash
	slash_noweapon.PushBack({1610 , 2640 , 72 , 76});
	slash_noweapon.PushBack({1681 ,2640 , 72 , 76});
	slash_noweapon.PushBack({1748 , 2640 , 72 , 76});
	slash_noweapon.speed = 0.2f;

	

	//// Special crouch attack
	specialcrouchattack.PushBack({56, 2305'1 , 115, 139});
	specialcrouchattack.PushBack({242, 2305'1 , 360, 139});
	specialcrouchattack.PushBack({433, 2305'1 , 572, 139});
	specialcrouchattack.PushBack({622, 2305'1 , 762, 139});
	specialcrouchattack.PushBack({812, 2305'1 , 951, 139});
	specialcrouchattack.PushBack({1003, 2305'1 , 1141, 139});
	specialcrouchattack.PushBack({1190 , 2305'1 , 1329, 139});
	specialcrouchattack.PushBack({1381, 2305'1 , 1521, 139});
	specialcrouchattack.PushBack({1571, 2305'1 , 1710, 139});
	specialcrouchattack.PushBack({1765, 2305'1 , 1826, 139});
	specialcrouchattack.speed = 0.2f;

	//// run with weapon
	runweapon.PushBack({1275 , 2640 , 101 , 78});
	runweapon.PushBack({1376 , 2640 , 98, 78});
	runweapon.PushBack({1474 , 2640 , 100 , 78});
	runweapon.speed = 0.2f;

	//// run without weapon
	runnoweapon.PushBack({1609 , 2640 , 73 , 78});
	runnoweapon.PushBack({1681 , 2640 , 67 , 78});
	runnoweapon.PushBack({1749 , 2640 , 70 , 78});
	runnoweapon.speed = 0.2f;

	//// powerful slash
	powerfulslash.PushBack({821 , 2747 , 73 , 155});
	powerfulslash.PushBack({978 , 2747 , 82 , 155});
	powerfulslash.PushBack({1130 , 2747 , 155 , 155});
	powerfulslash.PushBack({1286 , 2747 , 157, 155});
	powerfulslash.PushBack({1442 , 2747 , 159, 155});
	powerfulslash.PushBack({1602 , 2747 , 145, 155});
	powerfulslash.speed = 0.2f;

	//// agarre amb weapon
	gripwithweapon.PushBack({659 , 2604 , 76 , 114});
	gripwithweapon.PushBack({733 , 2604 , 68 , 114});
	gripwithweapon.PushBack({801 , 2604 , 63 , 114});
	gripwithweapon.PushBack({865 , 2604 , 57 , 114});
	gripwithweapon.speed = 0.2f;

	//// dash
	dash.PushBack({ 1860, 2616, 71, 101 });

	////dash no weapon
	dashnoweapon.PushBack({93, 2624, 71, 93});

	////protect
	protect.PushBack({1919, 48, 68, 90});
	protect.PushBack({1987, 48, 75'5, 90});

}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player textures");
	bool ret = true;
	graphics = App->textures->Load("Sprites/UkyoPlayer1SpriteSheet.png");
	punchsound = App->audio->LoadChunk("Audio_FX/Punch.wav");
	kicksound = App->audio->LoadChunk("Audio_FX/Kick.wav");
	jumpsound = App->audio->LoadChunk("Audio_FX/Jump.wav");
	hittedsound = App->audio->LoadChunk("Audio_FX/Hitted.wav");
	tornadosound = App->audio->LoadChunk("Audio_FX/Tornado.wav");
	position.x = 40;
	position.y = 210;
	body = App->collision->AddCollider({ position.x,(position.y - 100),35,20 }, COLLIDER_PLAYER, this);
	body2 = App->collision->AddCollider({ position.x,(position.y - 50),25,15 }, COLLIDER_PLAYER, this);
	body3 = App->collision->AddCollider({ position.x,(position.y - 20),45,35 }, COLLIDER_PLAYER, this);
	sword = true;
	actual = A_IDLE;
	for (int i = 0; i < 60; i++) inputstate[i] = S_NONE;
	for (int i = 0; i < 6; i++)inputstateout[i] = SO_NONE;
	jump_timer = 0;
	punch_timer = 0;
	kick_timer = 0;
	specialattack_timer = 0;
	inputsouts = 0;
	victory = false;
	flip = false;
	for(int i=0;i<60;i++)inair[i] = false;
	stopleft = stopright = false;
	notfinished = false;
	App->render->camera.x = App->render->camera.y = 0;
	posx = App->render->zooming;
	positionx2 = position.x;
	nattacks = nattackss = 0;
	hitted_timer = punch_timer = kick_timer = punch_timer = 0;
	inattack = false;
	return ret;
}

//Clean Up
bool ModulePlayer::CleanUp() {
	App->textures->Unload(graphics);
	App->audio->StopChunk();
	App->audio->UnLoadChunk(punchsound);
	App->audio->UnLoadChunk(kicksound);
	App->audio->UnLoadChunk(jumpsound);
	App->audio->UnLoadChunk(hittedsound);
	App->audio->UnLoadChunk(tornadosound);
	return true;
}

update_status ModulePlayer::PreUpdate() {
	if (App->UI->npow1 == 32)pow = true;
	else pow = false;
	if (position.x > App->player2->position.x&&position.y == 210)flip = true;
	else if (position.x < App->player2->position.x&&position.y == 210)flip = false;
	for (int i = 59; i > 0; i--)inputstate[i] = inputstate[i - 1];
	inputstate[0] = S_NONE;
	for (int i = 0; i < INPUTSOUTS; i++) inputstateout[i] = SO_NONE;
	inputsouts = 0;
	if (App->UI->startplay == true)Preupdate(jump_timer, punch_timer, kick_timer, specialattack_timer, hitted_timer, inputsouts, position, flip, actual, inputstate, inputstateout, App->player);
	else {
		actual = A_IDLE;
		position.y = 210;
	}
	for (int i = 0; i < 59; i++)inair[i+1] = inair[i];
	if(position.y==210)inair[0] = false;
	else if (position.y < 210)inair[0] = true;
	CheckSpecialAttacks(inputstate, inair);
	return UPDATE_CONTINUE;
}


// Update: draw background
update_status ModulePlayer::Update()
{
	//Animation* current_animation = &idle;
	int speed = 2;
	CheckState(notfinished,jump_timer, punch_timer, kick_timer, specialattack_timer, inputsouts, actual, inputstate, inputstateout);


	////////////////////GODMODE/////////////////////////

	if (App->input->keyboardstate[SDL_SCANCODE_F5] == KEY_PUSHED) {
		if (body->to_delete != false) {
			body = App->collision->AddCollider({ position.x,(position.y - 100),35,20 }, COLLIDER_PLAYER, this);
			body2 = App->collision->AddCollider({ position.x,(position.y - 50),25,15 }, COLLIDER_PLAYER, this);
			body3 = App->collision->AddCollider({ position.x,(position.y - 20),45,35 }, COLLIDER_PLAYER, this);
		}
		else {
			body->to_delete = true;
			body2->to_delete = true;
			body3->to_delete = true;
		}

	}


	////////////////////LOSE AUTOMATICALLY/////////////////////////
	if (App->input->keyboardstate[SDL_SCANCODE_F4] == KEY_PUSHED)App->UI->DamageTaken(1, 100, 0);

		// Draw everything --------------------------------------
	int checkposition = ((170+positionx2) * posx)-170;
	if (checkposition != position.x) positionx2 -= checkposition - position.x;
	position.x = positionx2;
	position.x =((170+position.x)*App->render->zooming)-170;
	posx = App->render->zooming;
	if (attack!=nullptr&&attack->to_delete == false)inattack = true;
	SDL_Rect r = ExecuteState(sword,pow, notfinished,jump_timer, punch_timer, kick_timer, specialattack_timer, hitted_timer, actual, flip, speed, mult, stopright, stopleft, *body, *body2, *body3, &attack, position, App->player)->GetCurrentFrame();
	if (inattack == false && attack!=nullptr&&attack->to_delete == false) nattacks++;
	notfinished = false;
	inattack = false;
	if (flip == false) {
		App->render->Blit(graphics, App->player->position.x + 6, 202, &(shadow.GetCurrentFrame()), 1.0f, true, false, App->render->zoom);
	}
	if (flip == true) {
		App->render->Blit(graphics, App->player->position.x, 202, &(shadow.GetCurrentFrame()), 1.0f, true, false, App->render->zoom);
	}
	
	if (flip == false)	App->render->Blit(graphics, position.x, position.y - r.h, &r, 1.0F, true, false, App->render->zoom);
	else App->render->Blit(graphics, position.x, position.y - r.h, &r, 1.0F, true, true, App->render->zoom);



	return UPDATE_CONTINUE;
}

update_status ModulePlayer::PostUpdate() {
	stopright = false;
	stopleft = false;
	return UPDATE_CONTINUE;
}


void ModulePlayer::OnCollision(Collider* player, Collider* other) {
	if (player->type == COLLIDER_PLAYER) {
		if (other->type == COLLIDER_ENEMY_SHOT) {
			if(position.y==210)actual = A_HITTED;
			else actual = A_HITTED_JUMP;
			if (hitted_timer == 0) {
				hitted_timer = 1;
				App->slowdown->StartSlowdown(100, 60);
			}
		}
		if (other->type == COLLIDER_WALL_LEFT) {
			stopleft = true;
		}
		if (other->type == COLLIDER_WALL_RIGHT) {
			stopright = true;
		}
		if (other->type == COLLIDER_ENEMY) {
			if (flip == false && App->player2->stopright == true) {
				stopright = true;
				if (position.y > 200 && position.y < 210 && mult == -2)position.x-=5;
			}
			else if (flip == true && App->player2->stopleft == true) {
				stopleft = true;
				if (position.y > 200 && position.y < 210 && mult == -2)position.x+=5;
			}
			else if (actual == A_WALK_FORWARD) {
				if (flip == false) App->player2->position.x++;
				else App->player2->position.x--;
			}
			else if (actual == A_JUMP_FORWARD && App->player2->position.y < 210) {
				if (App->player2->actual3 == A_JUMP_FORWARD) {
					if (flip == false)stopright = true;
					else stopleft = true;
				}
				else {
					if (flip == false)App->player2->position.x++;
					else App->player2->position.x--;
				}
			}
			else if (position.y > 200 && position.y < 210 && mult == -2 && App->player2->position.y == 210) {
				if (flip == false) {
					App->player2->position.x++;
					position.x--;
				}
				else{
					App->player2->position.x--;
					position.x++;
				}
			}
		}
	}
	else {
		if (other->type == COLLIDER_ENEMY) {
			if(player->to_delete==false)nattackss++;
			player->to_delete = true;
		}
	}
}
#include "Globals.h"
#include "Application.h"
#include "ModuleSceneEarthquake.h"
#include "ModuleAudio.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "Animation.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleFadeToBlack.h"
#include "ModuleSceneCongrats.h"
#include "ModuleCharacterSelection.h"
#include"ModuleCollision.h"
#include"ModuleParticles.h"
#include "ModuleUI.h"
#include "SDL/include/SDL.h"

ModuleSceneEarthquake::ModuleSceneEarthquake():Module()
{
	// Background animation
	back.PushBack({ 0, 0, 640, 416 });
	back.PushBack({ 640, 0, 640, 416 });
	back.PushBack({ 1280, 0, 640, 416 });
	back.PushBack({ 1920, 0, 640, 416 });
	back.PushBack({ 0, 416, 640, 416 });
	back.PushBack({ 640, 416, 640, 416 });
	back.PushBack({ 1280, 416, 640, 416 });
	back.PushBack({ 1920, 416, 640, 416 });
	back.PushBack({ 0, 832, 640, 416 });
	back.PushBack({ 640, 832, 640, 416 });
	back.PushBack({ 1280, 832, 640, 416 });
	back.PushBack({ 1920, 832, 640, 416 });
	back.PushBack({ 0, 1248, 640, 416 });
	back.PushBack({ 640, 1248, 640, 416 });
	back.PushBack({ 1280, 1248, 640, 416 });
	back.PushBack({ 1920, 1248, 640, 416 });
	back.speed = 0.08f;

	//AWithWeapon
	AWithWeapon.PushBack({ 0, 1344, 272, 64 });
	AWithWeapon.PushBack({ 272, 1344, 272, 64 });
	AWithWeapon.PushBack({ 544, 1344, 272, 64 });
	AWithWeapon.PushBack({ 816, 1344, 272, 64 });
	AWithWeapon.PushBack({ 1088, 1344, 272, 64 });
	AWithWeapon.PushBack({ 1360, 1344, 272, 64 });
	AWithWeapon.PushBack({ 1632, 1344, 272, 64 });
	AWithWeapon.PushBack({ 1904, 1344, 272, 64 });
	AWithWeapon.PushBack({ 2176, 1344, 272, 64 });
	AWithWeapon.PushBack({ 2448, 1344, 272, 64 });
	AWithWeapon.PushBack({ 2720, 1344, 272, 64 });
	AWithWeapon.PushBack({ 0, 1408, 272, 64 });
	AWithWeapon.PushBack({ 272, 1408, 272, 64 });
	AWithWeapon.PushBack({ 544, 1408, 272, 64 });
	AWithWeapon.PushBack({ 816, 1408, 272, 64 });
	AWithWeapon.PushBack({ 1088, 1408, 272, 64 });
	AWithWeapon.PushBack({ 1360, 1408, 272, 64 });
	AWithWeapon.PushBack({ 1632, 1408, 272, 64 });
	AWithWeapon.PushBack({ 1904, 1408, 272, 64 });
	AWithWeapon.PushBack({ 2176, 1408, 272, 64 });
	AWithWeapon.PushBack({ 2448, 1408, 272, 64 });
	AWithWeapon.PushBack({ 2720, 1408, 272, 64 });
	AWithWeapon.PushBack({ 0, 1472, 272, 64 });
	AWithWeapon.PushBack({ 272, 1472, 272, 64 });
	AWithWeapon.PushBack({ 544, 1472, 272, 64 });
	AWithWeapon.PushBack({ 816, 1472, 272, 64 });
	AWithWeapon.PushBack({ 1088, 1472, 272, 64 });
	AWithWeapon.PushBack({ 1360, 1472, 272, 64 });
	AWithWeapon.PushBack({ 1632, 1472, 272, 64 });
	AWithWeapon.PushBack({ 1904, 1472, 272, 64 });
	AWithWeapon.PushBack({ 2176, 1472, 272, 64 });
	AWithWeapon.PushBack({ 2448, 1472, 272, 64 });
	AWithWeapon.PushBack({ 2720, 1472, 272, 64 });
	AWithWeapon.speed = 0.1f;


	//BWithWeapon
	BWithWeapon.PushBack({ 0, 0, 272, 64 });
	BWithWeapon.PushBack({ 272, 0, 272, 64 });
	BWithWeapon.PushBack({ 544, 0, 272, 64 });
	BWithWeapon.PushBack({ 816, 0, 272, 64 });
	BWithWeapon.PushBack({ 1088, 0, 272, 64 });
	BWithWeapon.PushBack({ 1360, 0, 272, 64 });
	BWithWeapon.PushBack({ 1632, 0, 272, 64 });
	BWithWeapon.PushBack({ 1904, 0, 272, 64 });
	BWithWeapon.PushBack({ 2176, 0, 272, 64 });
	BWithWeapon.PushBack({ 2448, 0, 272, 64 });
	BWithWeapon.PushBack({ 2720, 0, 272, 64 });
	BWithWeapon.PushBack({ 0, 64, 272, 64 });
	BWithWeapon.PushBack({ 272, 64, 272, 64 });
	BWithWeapon.PushBack({ 544, 64, 272, 64 });
	BWithWeapon.PushBack({ 816, 64, 272, 64 });
	BWithWeapon.PushBack({ 1088, 64, 272, 64 });
	BWithWeapon.PushBack({ 1360, 64, 272, 64 });
	BWithWeapon.PushBack({ 1632, 64, 272, 64 });
	BWithWeapon.PushBack({ 1904, 64, 272, 64 });
	BWithWeapon.PushBack({ 2176, 64, 272, 64 });
	BWithWeapon.PushBack({ 2448, 64, 272, 64 });
	BWithWeapon.PushBack({ 2720, 64, 272, 64 });
	BWithWeapon.PushBack({ 0, 128, 272, 64 });
	BWithWeapon.PushBack({ 272, 128, 272, 64 });
	BWithWeapon.PushBack({ 544, 128, 272, 64 });
	BWithWeapon.PushBack({ 816, 128, 272, 64 });
	BWithWeapon.PushBack({ 1088, 128, 272, 64 });
	BWithWeapon.PushBack({ 1360, 128, 272, 64 });
	BWithWeapon.PushBack({ 1632, 128, 272, 64 });
	BWithWeapon.PushBack({ 1904, 128, 272, 64 });
	BWithWeapon.speed = 0.1f;


	//ABWithWeapon
	ABWithWeapon.PushBack({ 2176, 128, 272, 64 });
	ABWithWeapon.PushBack({ 2448, 128, 272, 64 });
	ABWithWeapon.PushBack({ 2720, 128, 272, 64 });
	ABWithWeapon.PushBack({ 0, 192, 272, 64 });
	ABWithWeapon.PushBack({ 272, 192, 272, 64 });
	ABWithWeapon.PushBack({ 544, 192, 272, 64 });
	ABWithWeapon.PushBack({ 816, 192, 272, 64 });
	ABWithWeapon.PushBack({ 1088, 192, 272, 64 });
	ABWithWeapon.PushBack({ 1360, 192, 272, 64 });
	ABWithWeapon.PushBack({ 1632, 192, 272, 64 });
	ABWithWeapon.PushBack({ 1904, 192, 272, 64 });
	ABWithWeapon.PushBack({ 2176, 192, 272, 64 });
	ABWithWeapon.PushBack({ 2448, 192, 272, 64 });
	ABWithWeapon.PushBack({ 2720, 192, 272, 64 });
	ABWithWeapon.PushBack({ 0, 256, 272, 64 });
	ABWithWeapon.PushBack({ 272, 256, 272, 64 });
	ABWithWeapon.PushBack({ 544, 256, 272, 64 });
	ABWithWeapon.PushBack({ 816, 256, 272, 64 });
	ABWithWeapon.PushBack({ 1088, 256, 272, 64 });
	ABWithWeapon.PushBack({ 1360, 256, 272, 64 });
	ABWithWeapon.PushBack({ 1632, 256, 272, 64 });
	ABWithWeapon.PushBack({ 1904, 256, 272, 64 });
	ABWithWeapon.PushBack({ 2176, 256, 272, 64 });
	ABWithWeapon.PushBack({ 2448, 256, 272, 64 });
	ABWithWeapon.PushBack({ 2720, 256, 272, 64 });
	ABWithWeapon.PushBack({ 0, 320, 272, 64 });
	ABWithWeapon.PushBack({ 272, 320, 272, 64 });
	ABWithWeapon.PushBack({ 544, 320, 272, 64 });
	ABWithWeapon.PushBack({ 816, 320, 272, 64 });
	ABWithWeapon.PushBack({ 1088, 320, 272, 64 });
	ABWithWeapon.PushBack({ 1360, 320, 272, 64 });
	ABWithWeapon.speed = 0.1f;


	//AWithoutWeapon
	AWithoutWeapon.PushBack({ 1632, 320, 272, 64 });
	AWithoutWeapon.PushBack({ 1904, 320, 272, 64 });
	AWithoutWeapon.PushBack({ 2176, 320, 272, 64 });
	AWithoutWeapon.PushBack({ 2448, 320, 272, 64 });
	AWithoutWeapon.PushBack({ 2720, 320, 272, 64 });
	AWithoutWeapon.PushBack({ 0, 384, 272, 64 });
	AWithoutWeapon.PushBack({ 272, 384, 272, 64 });
	AWithoutWeapon.PushBack({ 544, 384, 272, 64 });
	AWithoutWeapon.PushBack({ 816, 384, 272, 64 });
	AWithoutWeapon.PushBack({ 1088, 384, 272, 64 });
	AWithoutWeapon.PushBack({ 1360, 384, 272, 64 });
	AWithoutWeapon.PushBack({ 1632, 384, 272, 64 });
	AWithoutWeapon.PushBack({ 1904, 384, 272, 64 });
	AWithoutWeapon.PushBack({ 2176, 384, 272, 64 });
	AWithoutWeapon.PushBack({ 2448, 384, 272, 64 });
	AWithoutWeapon.PushBack({ 2448, 448, 272, 64 });
	AWithoutWeapon.PushBack({ 2720, 448, 272, 64 });
	AWithoutWeapon.PushBack({ 0, 512, 272, 64 });
	AWithoutWeapon.PushBack({ 272, 512, 272, 64 });
	AWithoutWeapon.PushBack({ 544, 512, 272, 64 });
	AWithoutWeapon.PushBack({ 816, 512, 272, 64 });
	AWithoutWeapon.PushBack({ 1088, 512, 272, 64 });
	AWithoutWeapon.PushBack({ 1360, 512, 272, 64 });
	AWithoutWeapon.PushBack({ 1632, 512, 272, 64 });
	AWithoutWeapon.PushBack({ 1904, 512, 272, 64 });
	AWithoutWeapon.PushBack({ 2176, 512, 272, 64 });
	AWithoutWeapon.PushBack({ 2448, 512, 272, 64 });
	AWithoutWeapon.speed = 0.1f;


	//BWithoutWeapon
	BWithoutWeapon.PushBack({ 2720, 512, 272, 64 });
	BWithoutWeapon.PushBack({ 0, 576, 272, 64 });
	BWithoutWeapon.PushBack({ 272, 576, 272, 64 });
	BWithoutWeapon.PushBack({ 544, 576, 272, 64 });
	BWithoutWeapon.PushBack({ 816, 576, 272, 64 });
	BWithoutWeapon.PushBack({ 1088, 576, 272, 64 });
	BWithoutWeapon.PushBack({ 1360, 576, 272, 64 });
	BWithoutWeapon.PushBack({ 1632, 576, 272, 64 });
	BWithoutWeapon.PushBack({ 1904, 576, 272, 64 });
	BWithoutWeapon.PushBack({ 2176, 576, 272, 64 });
	BWithoutWeapon.PushBack({ 2448, 576, 272, 64 });
	BWithoutWeapon.PushBack({ 2720, 576, 272, 64 });
	BWithoutWeapon.PushBack({ 0, 640, 272, 64 });
	BWithoutWeapon.PushBack({ 272, 640, 272, 64 });
	BWithoutWeapon.PushBack({ 544, 640, 272, 64 });
	BWithoutWeapon.PushBack({ 816, 640, 272, 64 });
	BWithoutWeapon.PushBack({ 1088, 640, 272, 64 });
	BWithoutWeapon.PushBack({ 1360, 640, 272, 64 });
	BWithoutWeapon.PushBack({ 1632, 640, 272, 64 });
	BWithoutWeapon.PushBack({ 1904, 640, 272, 64 });
	BWithoutWeapon.PushBack({ 2176, 640, 272, 64 });
	BWithoutWeapon.PushBack({ 2448, 640, 272, 64 });
	BWithoutWeapon.PushBack({ 2720, 640, 272, 64 });
	BWithoutWeapon.PushBack({ 0, 704, 272, 64 });
	BWithoutWeapon.PushBack({ 272, 704, 272, 64 });
	BWithoutWeapon.PushBack({ 544, 704, 272, 64 });
	BWithoutWeapon.PushBack({ 816, 704, 272, 64 });
	BWithoutWeapon.PushBack({ 1088, 704, 272, 64 });
	BWithoutWeapon.PushBack({ 1360, 704, 272, 64 });
	BWithoutWeapon.PushBack({ 1632, 704, 272, 64 });
	BWithoutWeapon.PushBack({ 1904, 704, 272, 64 });
	BWithoutWeapon.PushBack({ 2176, 704, 272, 64 });
	BWithoutWeapon.PushBack({ 2448, 704, 272, 64 });
	BWithoutWeapon.PushBack({ 2720, 704, 272, 64 });
	BWithoutWeapon.PushBack({ 0, 768, 272, 64 });
	BWithoutWeapon.PushBack({ 272, 768, 272, 64 });
	BWithoutWeapon.PushBack({ 544, 768, 272, 64 });
	BWithoutWeapon.PushBack({ 816, 768, 272, 64 });
	BWithoutWeapon.speed = 0.1f;


	//ABWithoutWeapon
	ABWithoutWeapon.PushBack({ 1088, 768, 272, 64 });
	ABWithoutWeapon.PushBack({ 1360, 768, 272, 64 });
	ABWithoutWeapon.PushBack({ 1632, 768, 272, 64 });
	ABWithoutWeapon.PushBack({ 1904, 768, 272, 64 });
	ABWithoutWeapon.PushBack({ 2176, 768, 272, 64 });
	ABWithoutWeapon.PushBack({ 2448, 768, 272, 64 });
	ABWithoutWeapon.PushBack({ 2720, 768, 272, 64 });
	ABWithoutWeapon.PushBack({ 0, 832, 272, 64 });
	ABWithoutWeapon.PushBack({ 272, 832, 272, 64 });
	ABWithoutWeapon.PushBack({ 544, 832, 272, 64 });
	ABWithoutWeapon.PushBack({ 816, 832, 272, 64 });
	ABWithoutWeapon.PushBack({ 1088, 832, 272, 64 });
	ABWithoutWeapon.PushBack({ 1360, 832, 272, 64 });
	ABWithoutWeapon.PushBack({ 1632, 832, 272, 64 });
	ABWithoutWeapon.PushBack({ 1904, 832, 272, 64 });
	ABWithoutWeapon.PushBack({ 2176, 832, 272, 64 });
	ABWithoutWeapon.PushBack({ 2448, 832, 272, 64 });
	ABWithoutWeapon.PushBack({ 2720, 832, 272, 64 });
	ABWithoutWeapon.PushBack({ 0, 896, 272, 64 });
	ABWithoutWeapon.PushBack({ 272, 896, 272, 64 });
	ABWithoutWeapon.PushBack({ 544, 896, 272, 64 });
	ABWithoutWeapon.PushBack({ 816, 896, 272, 64 });
	ABWithoutWeapon.PushBack({ 1088, 896, 272, 64 });
	ABWithoutWeapon.PushBack({ 1360, 896, 272, 64 });
	ABWithoutWeapon.PushBack({ 1632, 896, 272, 64 });
	ABWithoutWeapon.PushBack({ 1904, 896, 272, 64 });
	ABWithoutWeapon.PushBack({ 2176, 896, 272, 64 });
	ABWithoutWeapon.PushBack({ 2448, 896, 272, 64 });
	ABWithoutWeapon.PushBack({ 2720, 896, 272, 64 });
	ABWithoutWeapon.PushBack({ 0, 960, 272, 64 });
	ABWithoutWeapon.PushBack({ 272, 960, 272, 64 });
	ABWithoutWeapon.PushBack({ 544, 960, 272, 64 });
	ABWithoutWeapon.PushBack({ 816, 960, 272, 64 });
	ABWithoutWeapon.PushBack({ 1088, 960, 272, 64 });
	ABWithoutWeapon.PushBack({ 1360, 960, 272, 64 });
	ABWithoutWeapon.PushBack({ 1632, 960, 272, 64 });
	ABWithoutWeapon.speed = 0.1f;


	//CWithoutWeapon
	CWithoutWeapon.PushBack({ 1904, 960, 272, 64 });
	CWithoutWeapon.PushBack({ 2176, 960, 272, 64 });
	CWithoutWeapon.PushBack({ 2448, 960, 272, 64 });
	CWithoutWeapon.PushBack({ 2720, 960, 272, 64 });
	CWithoutWeapon.PushBack({ 0, 1024, 272, 64 });
	CWithoutWeapon.PushBack({ 272, 1024, 272, 64 });
	CWithoutWeapon.PushBack({ 544, 1024, 272, 64 });
	CWithoutWeapon.PushBack({ 816, 1024, 272, 64 });
	CWithoutWeapon.PushBack({ 1088, 1024, 272, 64 });
	CWithoutWeapon.PushBack({ 1360, 1024, 272, 64 });
	CWithoutWeapon.PushBack({ 1632, 1024, 272, 64 });
	CWithoutWeapon.PushBack({ 1904, 1024, 272, 64 });
	CWithoutWeapon.PushBack({ 2176, 1024, 272, 64 });
	CWithoutWeapon.PushBack({ 2448, 1024, 272, 64 });
	CWithoutWeapon.PushBack({ 2720, 1024, 272, 64 });
	CWithoutWeapon.PushBack({ 0, 1088, 272, 64 });
	CWithoutWeapon.PushBack({ 272, 1088, 272, 64 });
	CWithoutWeapon.speed = 0.1f;


	//DWithoutWeapon
	DWithoutWeapon.PushBack({ 544, 1088, 272, 64 });
	DWithoutWeapon.PushBack({ 816, 1088, 272, 64 });
	DWithoutWeapon.PushBack({ 1088, 1088, 272, 64 });
	DWithoutWeapon.PushBack({ 1360, 1088, 272, 64 });
	DWithoutWeapon.PushBack({ 1632, 1088, 272, 64 });
	DWithoutWeapon.PushBack({ 1904, 1088, 272, 64 });
	DWithoutWeapon.PushBack({ 2176, 1088, 272, 64 });
	DWithoutWeapon.PushBack({ 2448, 1088, 272, 64 });
	DWithoutWeapon.PushBack({ 2720, 1088, 272, 64 });
	DWithoutWeapon.PushBack({ 0, 1152, 272, 64 });
	DWithoutWeapon.PushBack({ 272, 1152, 272, 64 });
	DWithoutWeapon.PushBack({ 544, 1152, 272, 64 });
	DWithoutWeapon.PushBack({ 816, 1152, 272, 64 });
	DWithoutWeapon.PushBack({ 1088, 1152, 272, 64 });
	DWithoutWeapon.PushBack({ 1360, 1152, 272, 64 });
	DWithoutWeapon.PushBack({ 1632, 1152, 272, 64 });
	DWithoutWeapon.PushBack({ 1904, 1152, 272, 64 });
	DWithoutWeapon.PushBack({ 2176, 1152, 272, 64 });
	DWithoutWeapon.PushBack({ 2448, 1152, 272, 64 });
	DWithoutWeapon.PushBack({ 2720, 1152, 272, 64 });
	DWithoutWeapon.PushBack({ 0, 1216, 272, 64 });
	DWithoutWeapon.speed = 0.1f;


	//CDWithoutWeapon
	CDWithoutWeapon.PushBack({ 272, 1216, 272, 64 });
	CDWithoutWeapon.PushBack({ 544, 1216, 272, 64 });
	CDWithoutWeapon.PushBack({ 816, 1216, 272, 64 });
	CDWithoutWeapon.PushBack({ 1088, 1216, 272, 64 });
	CDWithoutWeapon.PushBack({ 1360, 1216, 272, 64 });
	CDWithoutWeapon.PushBack({ 1632, 1216, 272, 64 });
	CDWithoutWeapon.PushBack({ 1904, 1216, 272, 64 });
	CDWithoutWeapon.PushBack({ 2176, 1216, 272, 64 });
	CDWithoutWeapon.PushBack({ 2448, 1216, 272, 64 });
	CDWithoutWeapon.PushBack({ 2720, 1216, 272, 64 });
	CDWithoutWeapon.PushBack({ 0, 1280, 272, 64 });
	CDWithoutWeapon.PushBack({ 272, 1280, 272, 64 });
	CDWithoutWeapon.PushBack({ 544, 1280, 272, 64 });
	CDWithoutWeapon.PushBack({ 816, 1280, 272, 64 });
	CDWithoutWeapon.PushBack({ 1088, 1280, 272, 64 });
	CDWithoutWeapon.PushBack({ 1360, 1280, 272, 64 });
	CDWithoutWeapon.PushBack({ 1632, 1280, 272, 64 });
	CDWithoutWeapon.PushBack({ 1904, 1280, 272, 64 });
	CDWithoutWeapon.PushBack({ 2176, 1280, 272, 64 });
	CDWithoutWeapon.PushBack({ 2448, 1280, 272, 64 });
	CDWithoutWeapon.PushBack({ 2720, 1280, 272, 64 });
	CDWithoutWeapon.speed = 0.1f;
	
	//rectangletext
	rectangletextA.PushBack({ 2720, 1472, 272, 64 });
	rectangletextB.PushBack({ 1904, 128, 272, 64 });
	rectangletextAB.PushBack({ 1360, 320, 272, 64 });
	rectangletextA2.PushBack({ 2448, 512, 272, 64 });
	rectangletextB2.PushBack({ 816, 768, 272, 64 });
	rectangletextAB2.PushBack({ 1632, 960, 272, 64 });
	rectangletextC2.PushBack({ 272, 1088, 272, 64 });
	rectangletextD2.PushBack({ 0, 1216, 272, 64 });
	rectangletextCD2.PushBack({ 2720, 1280, 272, 64 });
	rectangletextempty.PushBack({ 544, 1088, 272, 64 });
	rectangletextempty.PushBack({ 544, 1088, 272, 64 });
	rectangletextempty.PushBack({ 544, 1088, 272, 64 });
	rectangletextempty.PushBack({ 544, 1088, 272, 64 });
	rectangletextempty.PushBack({ 544, 1088, 272, 64 });
	rectangletextempty.PushBack({ 544, 1088, 272, 64 });
	rectangletextempty.PushBack({ 544, 1088, 272, 64 });
	rectangletextempty.PushBack({ 544, 1088, 272, 64 });
	rectangletextempty.PushBack({ 544, 1088, 272, 64 });
	rectangletextempty.PushBack({ 544, 1088, 272, 64 });
	rectangletextempty.PushBack({ 544, 1088, 272, 64 });
	rectangletextempty.PushBack({ 544, 1088, 272, 64 });
	rectangletextempty.PushBack({ 544, 1088, 272, 64 });
	rectangletextempty.PushBack({ 544, 1088, 272, 64 });
	rectangletextempty.PushBack({ 544, 1088, 272, 64 });
	rectangletextempty.PushBack({ 544, 1088, 272, 64 });
	rectangletextempty.PushBack({ 544, 1088, 272, 64 });
	rectangletextempty.PushBack({ 544, 1088, 272, 64 });
	rectangletextempty.PushBack({ 544, 1088, 272, 64 });
	rectangletextempty.PushBack({ 544, 1088, 272, 64 });
	rectangletextempty.PushBack({ 544, 1088, 272, 64 });
	rectangletextempty.PushBack({ 544, 1088, 272, 64 });
	rectangletextempty.PushBack({ 544, 1088, 272, 64 });
	rectangletextempty.PushBack({ 544, 1088, 272, 64 });
	rectangletextempty.speed = 0.1f;

	//APushing
	APushing.PushBack({ 0, 1536, 48, 38 });
	APushing.PushBack({ 0, 1574, 48, 38 });
	APushing.PushBack({ 0, 1536, 48, 38 });
	APushing.PushBack({ 0, 1574, 48, 38 });
	APushing.PushBack({ 0, 1536, 48, 38 });
	APushing.PushBack({ 0, 1574, 48, 38 });
	APushing.PushBack({ 0, 1536, 48, 38 });
	APushing.PushBack({ 0, 1574, 48, 38 });
	APushing.PushBack({ 0, 1536, 48, 38 });
	APushing.PushBack({ 0, 1574, 48, 38 });
	APushing.PushBack({ 0, 1536, 48, 38 });
	APushing.PushBack({ 0, 1574, 48, 38 });
	APushing.PushBack({ 0, 1536, 48, 38 });
	APushing.PushBack({ 0, 1574, 48, 38 });
	APushing.PushBack({ 0, 1536, 48, 38 });
	APushing.PushBack({ 0, 1574, 48, 38 });
	APushing.PushBack({ 0, 1536, 48, 38 });
	APushing.PushBack({ 0, 1574, 48, 38 });
	APushing.PushBack({ 0, 1536, 48, 38 });
	APushing.PushBack({ 0, 1574, 48, 38 });
	APushing.PushBack({ 0, 1536, 48, 38 });
	APushing.PushBack({ 0, 1574, 48, 38 });
	APushing.PushBack({ 0, 1536, 48, 38 });
	APushing.PushBack({ 0, 1574, 48, 38 });
	APushing.speed = 0.1f;

	ANormal.PushBack({ 0, 1536, 48, 38 });

	//BPushing
	BPushing.PushBack({ 48, 1536, 48, 38 });
	BPushing.PushBack({ 48, 1574, 48, 38 });
	BPushing.PushBack({ 48, 1536, 48, 38 });
	BPushing.PushBack({ 48, 1574, 48, 38 });
	BPushing.PushBack({ 48, 1536, 48, 38 });
	BPushing.PushBack({ 48, 1574, 48, 38 });
	BPushing.PushBack({ 48, 1536, 48, 38 });
	BPushing.PushBack({ 48, 1574, 48, 38 });
	BPushing.PushBack({ 48, 1536, 48, 38 });
	BPushing.PushBack({ 48, 1574, 48, 38 });
	BPushing.PushBack({ 48, 1536, 48, 38 });
	BPushing.PushBack({ 48, 1574, 48, 38 });
	BPushing.PushBack({ 48, 1536, 48, 38 });
	BPushing.PushBack({ 48, 1574, 48, 38 });
	BPushing.PushBack({ 48, 1536, 48, 38 });
	BPushing.PushBack({ 48, 1574, 48, 38 });
	BPushing.PushBack({ 48, 1536, 48, 38 });
	BPushing.PushBack({ 48, 1574, 48, 38 });
	BPushing.PushBack({ 48, 1536, 48, 38 });
	BPushing.PushBack({ 48, 1574, 48, 38 });
	BPushing.PushBack({ 48, 1536, 48, 38 });
	BPushing.PushBack({ 48, 1574, 48, 38 });
	BPushing.PushBack({ 48, 1536, 48, 38 });
	BPushing.PushBack({ 48, 1574, 48, 38 });
	BPushing.speed = 0.1f;

	BNormal.PushBack({ 48, 1536, 48, 38 });

	//CPushing
	CPushing.PushBack({ 96, 1536, 48, 38 });
	CPushing.PushBack({ 96, 1574, 48, 38 });
	CPushing.PushBack({ 96, 1536, 48, 38 });
	CPushing.PushBack({ 96, 1574, 48, 38 });
	CPushing.PushBack({ 96, 1536, 48, 38 });
	CPushing.PushBack({ 96, 1574, 48, 38 });
	CPushing.PushBack({ 96, 1536, 48, 38 });
	CPushing.PushBack({ 96, 1574, 48, 38 });
	CPushing.PushBack({ 96, 1536, 48, 38 });
	CPushing.PushBack({ 96, 1574, 48, 38 });
	CPushing.PushBack({ 96, 1536, 48, 38 });
	CPushing.PushBack({ 96, 1574, 48, 38 });
	CPushing.PushBack({ 96, 1536, 48, 38 });
	CPushing.PushBack({ 96, 1574, 48, 38 });
	CPushing.PushBack({ 96, 1536, 48, 38 });
	CPushing.PushBack({ 96, 1574, 48, 38 });
	CPushing.PushBack({ 96, 1536, 48, 38 });
	CPushing.PushBack({ 96, 1574, 48, 38 });
	CPushing.PushBack({ 96, 1536, 48, 38 });
	CPushing.PushBack({ 96, 1574, 48, 38 });
	CPushing.PushBack({ 96, 1536, 48, 38 });
	CPushing.PushBack({ 96, 1574, 48, 38 });
	CPushing.PushBack({ 96, 1536, 48, 38 });
	CPushing.PushBack({ 96, 1574, 48, 38 });
	CPushing.speed = 0.1f;

	CNormal.PushBack({ 96, 1536, 48, 38 });

	//DPushing
	DPushing.PushBack({ 144, 1536, 48, 38 });
	DPushing.PushBack({ 144, 1574, 48, 38 });
	DPushing.PushBack({ 144, 1536, 48, 38 });
	DPushing.PushBack({ 144, 1574, 48, 38 });
	DPushing.PushBack({ 144, 1536, 48, 38 });
	DPushing.PushBack({ 144, 1574, 48, 38 });
	DPushing.PushBack({ 144, 1536, 48, 38 });
	DPushing.PushBack({ 144, 1574, 48, 38 });
	DPushing.PushBack({ 144, 1536, 48, 38 });
	DPushing.PushBack({ 144, 1574, 48, 38 });
	DPushing.PushBack({ 144, 1536, 48, 38 });
	DPushing.PushBack({ 144, 1574, 48, 38 });
	DPushing.PushBack({ 144, 1536, 48, 38 });
	DPushing.PushBack({ 144, 1574, 48, 38 });
	DPushing.PushBack({ 144, 1536, 48, 38 });
	DPushing.PushBack({ 144, 1574, 48, 38 });
	DPushing.PushBack({ 144, 1536, 48, 38 });
	DPushing.PushBack({ 144, 1574, 48, 38 });
	DPushing.PushBack({ 144, 1536, 48, 38 });
	DPushing.PushBack({ 144, 1574, 48, 38 });
	DPushing.PushBack({ 144, 1536, 48, 38 });
	DPushing.PushBack({ 144, 1574, 48, 38 });
	DPushing.PushBack({ 144, 1536, 48, 38 });
	DPushing.PushBack({ 144, 1574, 48, 38 });
	DPushing.speed = 0.1f;

	DNormal.PushBack({ 144, 1536, 48, 38 });


	//////Ukyo 1st PLAYER////////////
	//Idle
	IdleUkyo1.PushBack({ 0, 0, 75, 137 });
	IdleUkyo1.PushBack({ 75, 0, 75, 137 });
	IdleUkyo1.speed = 0.02f;

	// Stronger Kick animation
	strongerkickUkyo1.PushBack({ 15, 190, 70, 86 });
	strongerkickUkyo1.PushBack({ 114, 190, 66, 86 });
	strongerkickUkyo1.PushBack({ 202, 190, 67, 86 });
	strongerkickUkyo1.PushBack({ 302, 190, 82, 86 });
	strongerkickUkyo1.PushBack({ 402, 190, 100, 86 });
	strongerkickUkyo1.speed = 0.2f;

	// Kick animation
	kickUkyo1.PushBack({ 0, 411, 97, 137 });
	kickUkyo1.PushBack({ 97, 411, 97, 137 });
	kickUkyo1.PushBack({ 194, 411, 97, 137 });
	kickUkyo1.PushBack({ 97, 411, 97, 137 });
	kickUkyo1.PushBack({ 0, 411, 97, 137 });
	kickUkyo1.speed = 0.2f;

	// Punch animation (TO IMPROVE)
	punchUkyo1.PushBack({ 0, 274, 117, 137 });
	punchUkyo1.PushBack({ 117, 274, 117, 137 });
	punchUkyo1.PushBack({ 234, 274, 117, 137 });
	punchUkyo1.PushBack({ 351, 274, 117, 137 });
	punchUkyo1.PushBack({ 468, 274, 117, 137 });
	punchUkyo1.PushBack({ 351, 274, 117, 137 });
	punchUkyo1.PushBack({ 234, 274, 117, 137 });
	punchUkyo1.PushBack({ 117, 274, 117, 137 });
	punchUkyo1.PushBack({ 0, 274, 117, 137 });
	punchUkyo1.speed = 0.4f;

	//EmpateEspadas
	clashswordsUkyo1.PushBack({ 915, 1920, 65, 113 });
	clashswordsUkyo1.PushBack({ 980, 1920, 71'5, 113 });
	clashswordsUkyo1.PushBack({ 1051'5, 1920, 97'5, 113 });
	clashswordsUkyo1.speed = 0.5f;

	///////////Strong slash;
	strongerslashUkyo1.PushBack({ 43,   2488'5, 75, 91'5 });
	strongerslashUkyo1.PushBack({ 202, 2488'5, 83, 91'5 });
	strongerslashUkyo1.PushBack({ 352, 2488'5, 86, 91'5 });
	strongerslashUkyo1.PushBack({ 513, 2488'5, 84, 91'5 });
	strongerslashUkyo1.PushBack({ 663, 2488'5, 97, 91'5 });
	strongerslashUkyo1.PushBack({ 834, 2488'5, 145, 91'5 });
	strongerslashUkyo1.speed = 0.5f;


	//////Ukyo 2n PLAYER////////////
	//Idle
	IdleUkyo2.PushBack({ 0, 0, 75, 137 });
	IdleUkyo2.PushBack({ 75, 0, 75, 137 });
	IdleUkyo2.speed = 0.02f;

	//EmpateEspadas
	clashswordsUkyo2.PushBack({ 915, 1920, 65, 113 });
	clashswordsUkyo2.PushBack({ 980, 1920, 71'5, 113 });
	clashswordsUkyo2.PushBack({ 1051'5, 1920, 97'5, 113 });
	clashswordsUkyo2.speed = 0.5f;

}

ModuleSceneEarthquake::~ModuleSceneEarthquake() {}

bool  ModuleSceneEarthquake::Start() {
	rectbackground.x = 0;
	rectbackground.y = -200;
	rectbackground.w = (SCREEN_WIDTH)*2;
	rectbackground.h = (SCREEN_HEIGHT);
	scrollleft = 0;
	scrollright = 0;
	App->audio->LoadMusic("Music/stage2.ogg");
	App->audio->PlayMusic(App->audio->musics[0]);
	earthquake = App->audio->LoadChunk("Audio_FX/Earthquake.wav");
	App->audio->PlayChunk(earthquake);
	graphics = App->textures->Load("Sprites/Back.png");
	graphics2 = App->textures->Load("Sprites/UITutorial.png");
	graphics3 = App->textures->Load("Sprites/UkyoPlayer1SpriteSheet.png");
	App->UI->Enable();
	rectangletextempty.current_frame = 0;
	return true;
}

Animation Current, CurrentA, CurrentB, CurrentC, CurrentD, CurrentP1, CurrentP2;
int cont = 0, countpunch1=0, countkick1=0, countstrongslash1=0;
bool final=false;

update_status  ModuleSceneEarthquake::Update() {
	App->render->Blit(graphics, 0, -175, &(back.GetCurrentFrame()), 0.9f);
	if (cont == 0) {
		Current.GetCurrentFrame() = AWithWeapon.GetCurrentFrame();
		CurrentA.GetCurrentFrame() = ANormal.GetCurrentFrame();
		CurrentB.GetCurrentFrame() = BNormal.GetCurrentFrame();
		CurrentC.GetCurrentFrame() = CNormal.GetCurrentFrame();
		CurrentD.GetCurrentFrame() = DNormal.GetCurrentFrame();
		CurrentP1.GetCurrentFrame() = IdleUkyo1.GetCurrentFrame();
		CurrentP2.GetCurrentFrame() = IdleUkyo2.GetCurrentFrame();
	}
	if (cont == 1) {
		Current.GetCurrentFrame() = rectangletextA.GetCurrentFrame();
		CurrentA.GetCurrentFrame() = APushing.GetCurrentFrame();
		CurrentB.GetCurrentFrame() = BNormal.GetCurrentFrame();
		CurrentC.GetCurrentFrame() = CNormal.GetCurrentFrame();
		CurrentD.GetCurrentFrame() = DNormal.GetCurrentFrame();
		if (countpunch1 == 0) {
			CurrentP1.GetCurrentFrame() = punchUkyo1.GetCurrentFrame();
		}
		if (punchUkyo1.finished = 1) {
			countpunch1 = 1;
		}
	}
	if (cont == 2) {
		Current.GetCurrentFrame() = BWithWeapon.GetCurrentFrame();
		CurrentA.GetCurrentFrame() = ANormal.GetCurrentFrame();
		CurrentB.GetCurrentFrame() = BNormal.GetCurrentFrame();
		CurrentC.GetCurrentFrame() = CNormal.GetCurrentFrame();
		CurrentD.GetCurrentFrame() = DNormal.GetCurrentFrame();
		CurrentP1.GetCurrentFrame() = IdleUkyo1.GetCurrentFrame();
		CurrentP2.GetCurrentFrame() = IdleUkyo2.GetCurrentFrame();
	}
	if (cont == 3) {
		Current.GetCurrentFrame() = rectangletextB.GetCurrentFrame();
		CurrentA.GetCurrentFrame() = ANormal.GetCurrentFrame();
		CurrentB.GetCurrentFrame() = BPushing.GetCurrentFrame();
		CurrentC.GetCurrentFrame() = CNormal.GetCurrentFrame();
		CurrentD.GetCurrentFrame() = DNormal.GetCurrentFrame();
		if (countkick1 == 0) {
			CurrentP1.GetCurrentFrame() = kickUkyo1.GetCurrentFrame();
		}
		if (kickUkyo1.finished = 1) {
			countkick1 = 1;
		}
	}
	if (cont == 4) {
		Current.GetCurrentFrame() = ABWithWeapon.GetCurrentFrame();
		CurrentA.GetCurrentFrame() = ANormal.GetCurrentFrame();
		CurrentB.GetCurrentFrame() = BNormal.GetCurrentFrame();
		CurrentC.GetCurrentFrame() = CNormal.GetCurrentFrame();
		CurrentD.GetCurrentFrame() = DNormal.GetCurrentFrame();
		CurrentP1.GetCurrentFrame() = IdleUkyo1.GetCurrentFrame();
		CurrentP2.GetCurrentFrame() = IdleUkyo2.GetCurrentFrame();
	}
	if (cont == 5) {
		Current.GetCurrentFrame() = rectangletextAB.GetCurrentFrame();
		CurrentA.GetCurrentFrame() = APushing.GetCurrentFrame();
		CurrentB.GetCurrentFrame() = BPushing.GetCurrentFrame();
		CurrentC.GetCurrentFrame() = CNormal.GetCurrentFrame();
		CurrentD.GetCurrentFrame() = DNormal.GetCurrentFrame();
		if (countstrongslash1 == 0) {
			CurrentP1.GetCurrentFrame() = strongerslashUkyo1.GetCurrentFrame();
		}
		if (strongerslashUkyo1.finished = 1) {
			countstrongslash1 = 1;
		}
	}
	if (cont == 6) {
		Current.GetCurrentFrame() = rectangletextempty.GetCurrentFrame();
		CurrentA.GetCurrentFrame() = ANormal.GetCurrentFrame();
		CurrentB.GetCurrentFrame() = BNormal.GetCurrentFrame();
		CurrentC.GetCurrentFrame() = CNormal.GetCurrentFrame();
		CurrentD.GetCurrentFrame() = DNormal.GetCurrentFrame();
	}
	if (cont == 7) {
		Current.GetCurrentFrame() = AWithoutWeapon.GetCurrentFrame();
		CurrentA.GetCurrentFrame() = ANormal.GetCurrentFrame();
		CurrentB.GetCurrentFrame() = BNormal.GetCurrentFrame();
		CurrentC.GetCurrentFrame() = CNormal.GetCurrentFrame();
		CurrentD.GetCurrentFrame() = DNormal.GetCurrentFrame();
	}
	if (cont == 8) {
		Current.GetCurrentFrame() = rectangletextA2.GetCurrentFrame();
		CurrentA.GetCurrentFrame() = APushing.GetCurrentFrame();
		CurrentB.GetCurrentFrame() = BNormal.GetCurrentFrame();
		CurrentC.GetCurrentFrame() = CNormal.GetCurrentFrame();
		CurrentD.GetCurrentFrame() = DNormal.GetCurrentFrame();
	}
	if (cont == 9) {
		Current.GetCurrentFrame() = BWithoutWeapon.GetCurrentFrame();
		CurrentA.GetCurrentFrame() = ANormal.GetCurrentFrame();
		CurrentB.GetCurrentFrame() = BNormal.GetCurrentFrame();
		CurrentC.GetCurrentFrame() = CNormal.GetCurrentFrame();
		CurrentD.GetCurrentFrame() = DNormal.GetCurrentFrame();
	}
	if (cont == 10) {
		Current.GetCurrentFrame() = rectangletextB2.GetCurrentFrame();
		CurrentA.GetCurrentFrame() = ANormal.GetCurrentFrame();
		CurrentB.GetCurrentFrame() = BPushing.GetCurrentFrame();
		CurrentC.GetCurrentFrame() = CNormal.GetCurrentFrame();
		CurrentD.GetCurrentFrame() = DNormal.GetCurrentFrame();
	}
	if (cont == 11) {
		Current.GetCurrentFrame() = ABWithoutWeapon.GetCurrentFrame();
		CurrentA.GetCurrentFrame() = ANormal.GetCurrentFrame();
		CurrentB.GetCurrentFrame() = BNormal.GetCurrentFrame();
		CurrentC.GetCurrentFrame() = CNormal.GetCurrentFrame();
		CurrentD.GetCurrentFrame() = DNormal.GetCurrentFrame();
	}
	if (cont == 12) {
		Current.GetCurrentFrame() = rectangletextAB2.GetCurrentFrame();
		CurrentA.GetCurrentFrame() = APushing.GetCurrentFrame();
		CurrentB.GetCurrentFrame() = BPushing.GetCurrentFrame();
		CurrentC.GetCurrentFrame() = CNormal.GetCurrentFrame();
		CurrentD.GetCurrentFrame() = DNormal.GetCurrentFrame();
	}
	if (cont == 13) {
		Current.GetCurrentFrame() = CWithoutWeapon.GetCurrentFrame();
		CurrentA.GetCurrentFrame() = ANormal.GetCurrentFrame();
		CurrentB.GetCurrentFrame() = BNormal.GetCurrentFrame();
		CurrentC.GetCurrentFrame() = CNormal.GetCurrentFrame();
		CurrentD.GetCurrentFrame() = DNormal.GetCurrentFrame();
	}
	if (cont == 14) {
		Current.GetCurrentFrame() = rectangletextC2.GetCurrentFrame();
		CurrentA.GetCurrentFrame() = ANormal.GetCurrentFrame();
		CurrentB.GetCurrentFrame() = BNormal.GetCurrentFrame();
		CurrentC.GetCurrentFrame() = CPushing.GetCurrentFrame();
		CurrentD.GetCurrentFrame() = DNormal.GetCurrentFrame();
	}
	if (cont == 15) {
		Current.GetCurrentFrame() = DWithoutWeapon.GetCurrentFrame();
		CurrentA.GetCurrentFrame() = ANormal.GetCurrentFrame();
		CurrentB.GetCurrentFrame() = BNormal.GetCurrentFrame();
		CurrentC.GetCurrentFrame() = CNormal.GetCurrentFrame();
		CurrentD.GetCurrentFrame() = DNormal.GetCurrentFrame();
	}
	if (cont == 16) {
		Current.GetCurrentFrame() = rectangletextD2.GetCurrentFrame();
		CurrentA.GetCurrentFrame() = ANormal.GetCurrentFrame();
		CurrentB.GetCurrentFrame() = BNormal.GetCurrentFrame();
		CurrentC.GetCurrentFrame() = CNormal.GetCurrentFrame();
		CurrentD.GetCurrentFrame() = DPushing.GetCurrentFrame();
	}
	if (cont == 17) {
		Current.GetCurrentFrame() = CDWithoutWeapon.GetCurrentFrame();
		CurrentA.GetCurrentFrame() = ANormal.GetCurrentFrame();
		CurrentB.GetCurrentFrame() = BNormal.GetCurrentFrame();
		CurrentC.GetCurrentFrame() = CNormal.GetCurrentFrame();
		CurrentD.GetCurrentFrame() = DNormal.GetCurrentFrame();
	}
	if (cont == 18) {
		Current.GetCurrentFrame() = rectangletextCD2.GetCurrentFrame();
		CurrentA.GetCurrentFrame() = ANormal.GetCurrentFrame();
		CurrentB.GetCurrentFrame() = BNormal.GetCurrentFrame();
		CurrentC.GetCurrentFrame() = CPushing.GetCurrentFrame();
		CurrentD.GetCurrentFrame() = DPushing.GetCurrentFrame();
	}

	if ((AWithWeapon.finished== 1) && (cont == 0)) {
		if (Current.current_frame == AWithWeapon.current_frame) {
			cont= 1;
		}
	}

	if ((APushing.finished == 1) && (cont == 1)) {
		if (CurrentA.current_frame == APushing.current_frame) {
			cont = 2;
			APushing.Reset();
			BPushing.Reset();
		}
	}

	if ((BWithWeapon.finished == 1) && (cont == 2)) {
		if (Current.current_frame == BWithWeapon.current_frame) {
			cont = 3;
			APushing.Reset();
			BPushing.Reset();
		}
	}

	if ((BPushing.finished == 1) && (cont == 3)) {
		if (CurrentB.current_frame == BPushing.current_frame) {
			cont = 4;
			APushing.Reset();
			BPushing.Reset();
		}
	}

	if ((ABWithWeapon.finished == 1) && (cont == 4)) {
		if (Current.current_frame == ABWithWeapon.current_frame) {
			cont = 5;
			APushing.Reset();
			BPushing.Reset();
			rectangletextempty.Reset();
		}
	}

	if ((BPushing.finished == 1) && (cont == 5)) {
		if ((CurrentB.current_frame == BPushing.current_frame) && (CurrentA.current_frame == APushing.current_frame)) {
			cont = 6;
			APushing.Reset();
			BPushing.Reset();
			rectangletextempty.Reset();
		}
	}

	if ((rectangletextempty.finished == 1) && (cont == 6)) {
		cont = 7;
	}

	if ((AWithoutWeapon.finished == 1) && (cont == 7)) {
		if (Current.current_frame == AWithoutWeapon.current_frame) {
			cont = 8;
			APushing.Reset();
			BPushing.Reset();
			rectangletextempty.Reset();
		}
	}

	if ((APushing.finished == 1) && (cont == 8)) {
		if (CurrentA.current_frame == APushing.current_frame) {
			cont = 9;
			APushing.Reset();
			BPushing.Reset();
			rectangletextempty.Reset();
		}
	}

	if ((BWithoutWeapon.finished == 1) && (cont == 9)) {
		if (Current.current_frame == BWithoutWeapon.current_frame) {
			cont = 10;
			APushing.Reset();
			BPushing.Reset();
			rectangletextempty.Reset();
		}
	}

	if ((BPushing.finished == 1) && (cont == 10)) {
		if (CurrentB.current_frame == BPushing.current_frame) {
			cont = 11;
			APushing.Reset();
			BPushing.Reset();
			rectangletextempty.Reset();
		}
	}

	if ((ABWithoutWeapon.finished == 1) && (cont == 11)) {
		if (Current.current_frame == ABWithoutWeapon.current_frame) {
			cont = 12;
			APushing.Reset();
			BPushing.Reset();
			rectangletextempty.Reset();
		}
	}

	if ((BPushing.finished == 1) && (cont == 12)) {
		if (CurrentB.current_frame == BPushing.current_frame) {
			cont = 13;
			APushing.Reset();
			BPushing.Reset();
			rectangletextempty.Reset();
		}
	}
	
	if ((CWithoutWeapon.finished == 1) && (cont == 13)) {
		if (Current.current_frame == CWithoutWeapon.current_frame) {
			cont = 14;
			APushing.Reset();
			BPushing.Reset();
			rectangletextempty.Reset();
		}
	}

	if ((CPushing.finished == 1) && (cont == 14)) {
		if (CurrentB.current_frame == CPushing.current_frame) {
			cont = 15;
			APushing.Reset();
			BPushing.Reset();
			CPushing.Reset();
			rectangletextempty.Reset();
		}
	}

	if ((DWithoutWeapon.finished == 1) && (cont == 15)) {
		if (Current.current_frame == DWithoutWeapon.current_frame) {
			cont = 16;
			APushing.Reset();
			BPushing.Reset();
			CPushing.Reset();
			DPushing.Reset();
			rectangletextempty.Reset();
		}
	}

	if ((DPushing.finished == 1) && (cont == 16)) {
		if (CurrentB.current_frame == DPushing.current_frame) {
			cont = 17;
			APushing.Reset();
			BPushing.Reset();
			CPushing.Reset();
			DPushing.Reset();
			rectangletextempty.Reset();
		}
	}

	if ((CDWithoutWeapon.finished == 1) && (cont == 17)) {
		if (Current.current_frame == CDWithoutWeapon.current_frame) {
			cont = 18;
			APushing.Reset();
			BPushing.Reset();
			CPushing.Reset();
			DPushing.Reset();
			rectangletextempty.Reset();
		}
	}

	if ((DPushing.finished == 1) && (cont == 18)) {
		if (CurrentB.current_frame == DPushing.current_frame) {
			APushing.Reset();
			BPushing.Reset();
			CPushing.Reset();
			DPushing.Reset();
			rectangletextempty.Reset();
			final = true;
		}
	}

	App->render->Blit(graphics2, 16, 20, &(Current.GetCurrentFrame()), 1);
	App->render->Blit(graphics3, 70, 55, &(CurrentP1.GetCurrentFrame()), 1);
	App->render->Blit(graphics3, 130, 55, &(CurrentP2.GetCurrentFrame()), 1); // Player 2
	App->render->Blit(graphics2, 56, 175, &(CurrentA.GetCurrentFrame()), 1);
	App->render->Blit(graphics2, 104, 175, &(CurrentB.GetCurrentFrame()), 1);
	App->render->Blit(graphics2, 152, 175, &(CurrentC.GetCurrentFrame()), 1);
	App->render->Blit(graphics2, 200, 175, &(CurrentD.GetCurrentFrame()), 1);



	if ((App->input->space == true&&App->fade->finished == true) || (final == true))  {
		App->audio->StopMusic();
		App->fade->FadeToBlack(App->sceneearthquake, App->characterselection, 0.5F);
	}
	return UPDATE_CONTINUE;
}
bool  ModuleSceneEarthquake::CleanUp()
{
	App->audio->StopChunk();
	App->audio->UnLoadChunk(earthquake);
	App->audio->UnLoadMusic(App->audio->musics[0]);
	//App->UI->Disable();
	App->textures->Unload(graphics);
	App->textures->Unload(graphics2);
	App->textures->Unload(graphics3);
	return true;
}
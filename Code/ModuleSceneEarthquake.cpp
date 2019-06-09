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
	rectangletextempty.speed = 0.05f;

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

	//IdleWithoutSword
	Idle2Ukyo1.PushBack({ 765, 0, 68, 137 });
	Idle2Ukyo1.PushBack({ 833, 0, 68, 137 });
	Idle2Ukyo1.speed = 0.02f;

	// AWithWeaponUkyo1
	AWithWeaponUkyo1.PushBack({ 0, 274, 117, 137 });
	AWithWeaponUkyo1.PushBack({ 117, 274, 117, 137 });
	AWithWeaponUkyo1.PushBack({ 234, 274, 117, 137 });
	AWithWeaponUkyo1.PushBack({ 351, 274, 117, 137 });
	AWithWeaponUkyo1.PushBack({ 468, 274, 117, 137 });
	AWithWeaponUkyo1.PushBack({ 351, 274, 117, 137 });
	AWithWeaponUkyo1.PushBack({ 234, 274, 117, 137 });
	AWithWeaponUkyo1.PushBack({ 117, 274, 117, 137 });
	AWithWeaponUkyo1.PushBack({ 0, 274, 117, 137 });
	AWithWeaponUkyo1.speed = 0.3f;

	// BWithWeaponUkyo1
	BWithWeaponUkyo1.PushBack({ 0, 685, 117, 137 });
	BWithWeaponUkyo1.PushBack({ 155, 685, 117, 137 });
	BWithWeaponUkyo1.PushBack({ 310, 685, 117, 137 });
	BWithWeaponUkyo1.PushBack({ 465, 685, 117, 137 });
	BWithWeaponUkyo1.PushBack({ 620, 685, 117, 137 });
	BWithWeaponUkyo1.PushBack({ 620, 685, 117, 137 });
	BWithWeaponUkyo1.PushBack({ 620, 685, 117, 137 });
	BWithWeaponUkyo1.PushBack({ 465, 685, 117, 137 });
	BWithWeaponUkyo1.PushBack({ 310, 685, 117, 137 });
	BWithWeaponUkyo1.PushBack({ 155, 685, 117, 137 });
	BWithWeaponUkyo1.PushBack({ 0, 685, 117, 137 });
	BWithWeaponUkyo1.speed = 0.2f;

	// ABWithWeaponUkyo1
	ABWithWeaponUkyo1.PushBack({ 0, 822, 158, 154 });
	ABWithWeaponUkyo1.PushBack({ 158, 822, 158, 154 });
	ABWithWeaponUkyo1.PushBack({ 316, 822, 158, 154 });
	ABWithWeaponUkyo1.PushBack({ 474, 822, 158, 154 });
	ABWithWeaponUkyo1.PushBack({ 632, 822, 158, 154 });
	ABWithWeaponUkyo1.PushBack({ 790, 822, 158, 154 });
	ABWithWeaponUkyo1.PushBack({ 158, 822, 158, 154 });
	ABWithWeaponUkyo1.PushBack({ 0, 822, 158, 154 });
	ABWithWeaponUkyo1.speed = 0.2f;


	//ClashSwordsUkyo1
	clashswordsUkyo1.PushBack({ 579, 548, 70, 137 });
	clashswordsUkyo1.PushBack({ 712, 548, 99, 137 });
	clashswordsUkyo1.PushBack({ 649, 548, 63, 137 });
	clashswordsUkyo1.PushBack({ 712, 548, 99, 137 });
	clashswordsUkyo1.PushBack({ 579, 548, 70, 137 });
	clashswordsUkyo1.PushBack({ 712, 548, 99, 137 });
	clashswordsUkyo1.PushBack({ 649, 548, 63, 137 });
	clashswordsUkyo1.PushBack({ 712, 548, 99, 137 });
	clashswordsUkyo1.PushBack({ 579, 548, 70, 137 });
	clashswordsUkyo1.speed = 0.1f;

	// AWithoutWeaponUkyo1
	AWithoutWeaponUkyo1.PushBack({ 0, 548, 67, 137 });
	AWithoutWeaponUkyo1.PushBack({ 67, 548, 67, 137 });
	AWithoutWeaponUkyo1.PushBack({ 134, 548, 78, 137 });
	AWithoutWeaponUkyo1.PushBack({ 212, 548, 87, 137 });
	AWithoutWeaponUkyo1.PushBack({ 134, 548, 78, 137 });
	AWithoutWeaponUkyo1.PushBack({ 67, 548, 67, 137 });
	AWithoutWeaponUkyo1.PushBack({ 0, 548, 67, 137 });
	AWithoutWeaponUkyo1.speed = 0.15f;

	// ABWithoutWeaponUkyo1
	ABWithoutWeaponUkyo1.PushBack({ 330, 548, 55, 137 });
	ABWithoutWeaponUkyo1.PushBack({ 385, 548, 80, 137 });
	ABWithoutWeaponUkyo1.PushBack({ 465, 548, 98, 137 });
	ABWithoutWeaponUkyo1.PushBack({ 465, 548, 98, 137 });
	ABWithoutWeaponUkyo1.PushBack({ 465, 548, 98, 137 });
	ABWithoutWeaponUkyo1.PushBack({ 385, 548, 80, 137 });
	ABWithoutWeaponUkyo1.PushBack({ 385, 548, 80, 137 });
	ABWithoutWeaponUkyo1.PushBack({ 330, 548, 55, 137 });
	ABWithoutWeaponUkyo1.speed = 0.15f;

	// CWithoutWeaponUkyo1
	CWithoutWeaponUkyo1.PushBack({ 0, 411, 97, 137 });
	CWithoutWeaponUkyo1.PushBack({ 97, 411, 97, 137 });
	CWithoutWeaponUkyo1.PushBack({ 194, 411, 97, 137 });
	CWithoutWeaponUkyo1.PushBack({ 97, 411, 97, 137 });
	CWithoutWeaponUkyo1.PushBack({ 0, 411, 97, 137 });
	CWithoutWeaponUkyo1.speed = 0.15f;

	// CDWithoutWeaponUkyo1
	CDWithoutWeaponUkyo1.PushBack({ 0, 137, 100, 137 });
	CDWithoutWeaponUkyo1.PushBack({ 100, 137, 100, 137 });
	CDWithoutWeaponUkyo1.PushBack({ 200, 137, 100, 137 });
	CDWithoutWeaponUkyo1.PushBack({ 300, 137, 100, 137 });
	CDWithoutWeaponUkyo1.PushBack({ 400, 137, 100, 137 });
	CDWithoutWeaponUkyo1.PushBack({ 300, 137, 100, 137 });
	CDWithoutWeaponUkyo1.PushBack({ 200, 137, 100, 137 });
	CDWithoutWeaponUkyo1.PushBack({ 100, 137, 100, 137 });
	CDWithoutWeaponUkyo1.PushBack({ 0, 137, 100, 137 });
	CDWithoutWeaponUkyo1.speed = 0.1f;

	//////Ukyo 2n PLAYER////////////
	//Idle
	IdleUkyo2.PushBack({ 817, 411, 74, 137 });
	IdleUkyo2.PushBack({ 891, 411, 75, 137 });
	IdleUkyo2.speed = 0.02f;

	//Hitted Ukyo2
	HittedUkyo2.PushBack({ 835, 548, 67, 137 });

	//Walking Ukyo2
	WalkingUkyo2.PushBack({ 0, 976, 76, 137 });
	WalkingUkyo2.PushBack({ 76, 976, 72, 137 });
	WalkingUkyo2.PushBack({ 148, 976, 81, 137 });
	WalkingUkyo2.PushBack({ 229, 976, 87, 137 });
	WalkingUkyo2.PushBack({ 316, 976, 81, 137 });
	WalkingUkyo2.PushBack({ 397, 976, 72, 137 });
	WalkingUkyo2.PushBack({ 469, 976, 75, 137 });
	WalkingUkyo2.speed = 0.2f;

	//EmpateEspadas
	clashswordsUkyo2.PushBack({ 785, 685, 63, 137 });
	clashswordsUkyo2.PushBack({ 848, 685, 71, 137 });
	clashswordsUkyo2.PushBack({ 919, 685, 98, 137 });
	clashswordsUkyo2.PushBack({ 848, 685, 71, 137 });
	clashswordsUkyo2.PushBack({ 785, 685, 63, 137 });
	clashswordsUkyo2.PushBack({ 848, 685, 71, 137 });
	clashswordsUkyo2.PushBack({ 919, 685, 98, 137 });
	clashswordsUkyo2.PushBack({ 848, 685, 71, 137 });
	clashswordsUkyo2.PushBack({ 785, 685, 63, 137 });
	clashswordsUkyo2.speed = 0.1f;

}

ModuleSceneEarthquake::~ModuleSceneEarthquake() {}

bool  ModuleSceneEarthquake::Start() {
	rectbackground.x = 0;
	rectbackground.y = -200;
	rectbackground.w = (SCREEN_WIDTH)*2;
	rectbackground.h = (SCREEN_HEIGHT);
	scrollleft = 0;
	scrollright = 0;
	graphics = App->textures->Load("Sprites/Back.png");
	graphics2 = App->textures->Load("Sprites/UITutorial.png");
	graphics3 = App->textures->Load("Sprites/TutorialPlayers.png");
	App->UI->Enable();
	rectangletextempty.current_frame = 0;
	return true;
}

Animation Current, CurrentA, CurrentB, CurrentC, CurrentD, CurrentP1, CurrentP2;
int cont = 0, count = 0, positionyU1 = 55, positionxU1 = 77, positionxU2 = 155;
int mult = 0;
bool final=false, walk=false;

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
		if ((count == 0) && (APushing.current_frame >= 8)) {
			CurrentP1.GetCurrentFrame() = AWithWeaponUkyo1.GetCurrentFrame();
		}
		if (AWithWeaponUkyo1.current_frame >= 5) {
			CurrentP1.GetCurrentFrame() = IdleUkyo1.GetCurrentFrame();
			if (positionxU2 <= 200) {
				positionxU2 = positionxU2 + 2;
				CurrentP2.GetCurrentFrame() = HittedUkyo2.GetCurrentFrame();
			}
			else {
				CurrentP2.GetCurrentFrame() = IdleUkyo2.GetCurrentFrame();
			}
			count = 1;
		}
	}
	if (cont == 2) {
		count = 0;
		Current.GetCurrentFrame() = BWithWeapon.GetCurrentFrame();
		CurrentA.GetCurrentFrame() = ANormal.GetCurrentFrame();
		CurrentB.GetCurrentFrame() = BNormal.GetCurrentFrame();
		CurrentC.GetCurrentFrame() = CNormal.GetCurrentFrame();
		CurrentD.GetCurrentFrame() = DNormal.GetCurrentFrame();
		CurrentP1.GetCurrentFrame() = IdleUkyo1.GetCurrentFrame();
		CurrentP2.GetCurrentFrame() = IdleUkyo2.GetCurrentFrame();
		if (positionxU2 >= 155) {
			positionxU2 = positionxU2 -1;
			CurrentP2.GetCurrentFrame() = WalkingUkyo2.GetCurrentFrame();
		}
	}
	if (cont == 3) {
		Current.GetCurrentFrame() = rectangletextB.GetCurrentFrame();
		CurrentA.GetCurrentFrame() = ANormal.GetCurrentFrame();
		CurrentB.GetCurrentFrame() = BPushing.GetCurrentFrame();
		CurrentC.GetCurrentFrame() = CNormal.GetCurrentFrame();
		CurrentD.GetCurrentFrame() = DNormal.GetCurrentFrame();
		if ((count == 0) && (BPushing.current_frame >= 8)) {
			CurrentP1.GetCurrentFrame() = BWithWeaponUkyo1.GetCurrentFrame();
		}
		if (BWithWeaponUkyo1.current_frame >= 5) {
			CurrentP1.GetCurrentFrame() = IdleUkyo1.GetCurrentFrame();
			if (positionxU2 <= 200) {
				positionxU2 = positionxU2 + 2;
				CurrentP2.GetCurrentFrame() = HittedUkyo2.GetCurrentFrame();
			}
			else {
				CurrentP2.GetCurrentFrame() = IdleUkyo2.GetCurrentFrame();
			}
			count = 1;
		}
	}
	if (cont == 4) {
		count = 0;
		Current.GetCurrentFrame() = ABWithWeapon.GetCurrentFrame();
		CurrentA.GetCurrentFrame() = ANormal.GetCurrentFrame();
		CurrentB.GetCurrentFrame() = BNormal.GetCurrentFrame();
		CurrentC.GetCurrentFrame() = CNormal.GetCurrentFrame();
		CurrentD.GetCurrentFrame() = DNormal.GetCurrentFrame();
		CurrentP1.GetCurrentFrame() = IdleUkyo1.GetCurrentFrame();
		CurrentP2.GetCurrentFrame() = IdleUkyo2.GetCurrentFrame();
		if (positionxU2 >= 155) {
			positionxU2 = positionxU2 - 1;
			CurrentP2.GetCurrentFrame() = WalkingUkyo2.GetCurrentFrame();
		}
	}
	if (cont == 5) {
		Current.GetCurrentFrame() = rectangletextAB.GetCurrentFrame();
		CurrentA.GetCurrentFrame() = APushing.GetCurrentFrame();
		CurrentB.GetCurrentFrame() = BPushing.GetCurrentFrame();
		CurrentC.GetCurrentFrame() = CNormal.GetCurrentFrame();
		CurrentD.GetCurrentFrame() = DNormal.GetCurrentFrame();
		CurrentP1.GetCurrentFrame() = IdleUkyo1.GetCurrentFrame();
		CurrentP2.GetCurrentFrame() = IdleUkyo2.GetCurrentFrame();
		if ((count == 0) && (APushing.current_frame >= 8)) {
			positionyU1 = 38;
			CurrentP1.GetCurrentFrame() = ABWithWeaponUkyo1.GetCurrentFrame();
		}
		if (ABWithWeaponUkyo1.current_frame >= 6) {
			positionyU1 = 55;
			CurrentP1.GetCurrentFrame() = IdleUkyo1.GetCurrentFrame();
			if (positionxU2 <= 200) {
				positionxU2 = positionxU2 + 2;
				CurrentP2.GetCurrentFrame() = HittedUkyo2.GetCurrentFrame();
			}
			else {
				CurrentP2.GetCurrentFrame() = IdleUkyo2.GetCurrentFrame();
			}
			count = 1;
		}
	}
	if (cont == 6) {
		count = 0;
		Current.GetCurrentFrame() = rectangletextempty.GetCurrentFrame();
		CurrentA.GetCurrentFrame() = ANormal.GetCurrentFrame();
		CurrentB.GetCurrentFrame() = BNormal.GetCurrentFrame();
		CurrentC.GetCurrentFrame() = CNormal.GetCurrentFrame();
		CurrentD.GetCurrentFrame() = DNormal.GetCurrentFrame();
		CurrentP1.GetCurrentFrame() = IdleUkyo1.GetCurrentFrame();
		CurrentP2.GetCurrentFrame() = IdleUkyo2.GetCurrentFrame();
		if (positionxU2 >= 140) {
			positionxU2 = positionxU2 - 1;
			CurrentP2.GetCurrentFrame() = WalkingUkyo2.GetCurrentFrame();
		}
		if (positionxU1 <= 90) {
			positionxU1 = positionxU1 + 1;
			//CurrentP2.GetCurrentFrame() = WalkingUkyo1.GetCurrentFrame();
		}
		if ((positionxU2 <= 140)&& (positionxU1 >= 90)) {
			CurrentP2.GetCurrentFrame() = clashswordsUkyo2.GetCurrentFrame();
			CurrentP1.GetCurrentFrame() = clashswordsUkyo1.GetCurrentFrame();
		}
		if (clashswordsUkyo1.finished == 1) {

			CurrentP2.GetCurrentFrame() = IdleUkyo2.GetCurrentFrame();
			//CurrentP1.GetCurrentFrame() = fallingUkyo1.GetCurrentFrame();
			
			if (positionyU1 >= 55) {
				mult = 1;
			}
			if (positionyU1 <= -20) {
				mult = -1;
			}
			positionyU1 -= 2 * mult;

			if (positionxU1 >= -20) {
				positionxU1 = positionxU1 - 1;
			}
		}
	}
	if (cont == 7) {
		positionyU1 = 55;
		count = 0;
		Current.GetCurrentFrame() = AWithoutWeapon.GetCurrentFrame();
		CurrentA.GetCurrentFrame() = ANormal.GetCurrentFrame();
		CurrentB.GetCurrentFrame() = BNormal.GetCurrentFrame();
		CurrentC.GetCurrentFrame() = CNormal.GetCurrentFrame();
		CurrentD.GetCurrentFrame() = DNormal.GetCurrentFrame();
		CurrentP1.GetCurrentFrame() = Idle2Ukyo1.GetCurrentFrame();
		CurrentP2.GetCurrentFrame() = IdleUkyo2.GetCurrentFrame();
		if (positionxU1 <= 77) {
			positionxU1 = positionxU1 + 2;
		}
	}
	if (cont == 8) {
		positionxU1 = 77;
		positionyU1 = 55;
		Current.GetCurrentFrame() = rectangletextA2.GetCurrentFrame();
		CurrentA.GetCurrentFrame() = APushing.GetCurrentFrame();
		CurrentB.GetCurrentFrame() = BNormal.GetCurrentFrame();
		CurrentC.GetCurrentFrame() = CNormal.GetCurrentFrame();
		CurrentD.GetCurrentFrame() = DNormal.GetCurrentFrame();
		CurrentP1.GetCurrentFrame() = Idle2Ukyo1.GetCurrentFrame();
		CurrentP2.GetCurrentFrame() = IdleUkyo2.GetCurrentFrame();
		if ((count == 0) && (APushing.current_frame >= 8)) {
			CurrentP1.GetCurrentFrame() = AWithoutWeaponUkyo1.GetCurrentFrame();
		}
		if (AWithoutWeaponUkyo1.current_frame >= 4) {
			CurrentP1.GetCurrentFrame() = Idle2Ukyo1.GetCurrentFrame();
			if (positionxU2 <= 200) {
				positionxU2 = positionxU2 + 2;
				CurrentP2.GetCurrentFrame() = HittedUkyo2.GetCurrentFrame();
			}
			else {
				CurrentP2.GetCurrentFrame() = IdleUkyo2.GetCurrentFrame();
			}
			count = 1;
		}
	}
	if (cont == 9) {
		count = 0;
		Current.GetCurrentFrame() = BWithoutWeapon.GetCurrentFrame();
		CurrentA.GetCurrentFrame() = ANormal.GetCurrentFrame();
		CurrentB.GetCurrentFrame() = BNormal.GetCurrentFrame();
		CurrentC.GetCurrentFrame() = CNormal.GetCurrentFrame();
		CurrentD.GetCurrentFrame() = DNormal.GetCurrentFrame();
		CurrentP1.GetCurrentFrame() = Idle2Ukyo1.GetCurrentFrame();
		CurrentP2.GetCurrentFrame() = IdleUkyo2.GetCurrentFrame();
		if (positionxU2 >= 155) {
			positionxU2 = positionxU2 - 1;
			CurrentP2.GetCurrentFrame() = WalkingUkyo2.GetCurrentFrame();
		}
	}
	if (cont == 10) {
		Current.GetCurrentFrame() = rectangletextB2.GetCurrentFrame();
		CurrentA.GetCurrentFrame() = ANormal.GetCurrentFrame();
		CurrentB.GetCurrentFrame() = BPushing.GetCurrentFrame();
		CurrentC.GetCurrentFrame() = CNormal.GetCurrentFrame();
		CurrentD.GetCurrentFrame() = DNormal.GetCurrentFrame();
		CurrentP1.GetCurrentFrame() = Idle2Ukyo1.GetCurrentFrame();
		CurrentP2.GetCurrentFrame() = IdleUkyo2.GetCurrentFrame();
		if ((count == 0) && (BPushing.current_frame >= 8)) {
			CurrentP1.GetCurrentFrame() = AWithoutWeaponUkyo1.GetCurrentFrame();
		}
		if (AWithoutWeaponUkyo1.current_frame >= 6) {
			CurrentP1.GetCurrentFrame() = Idle2Ukyo1.GetCurrentFrame();
			if (positionxU2 <= 200) {
				positionxU2 = positionxU2 + 2;
				CurrentP2.GetCurrentFrame() = HittedUkyo2.GetCurrentFrame();
			}
			else {
				CurrentP2.GetCurrentFrame() = IdleUkyo2.GetCurrentFrame();
			}
			count = 1;
		}
	}
	if (cont == 11) {
		count = 0;
		Current.GetCurrentFrame() = ABWithoutWeapon.GetCurrentFrame();
		CurrentA.GetCurrentFrame() = ANormal.GetCurrentFrame();
		CurrentB.GetCurrentFrame() = BNormal.GetCurrentFrame();
		CurrentC.GetCurrentFrame() = CNormal.GetCurrentFrame();
		CurrentD.GetCurrentFrame() = DNormal.GetCurrentFrame();
		CurrentP1.GetCurrentFrame() = Idle2Ukyo1.GetCurrentFrame();
		CurrentP2.GetCurrentFrame() = IdleUkyo2.GetCurrentFrame();
		if (positionxU2 >= 155) {
			positionxU2 = positionxU2 - 1;
			CurrentP2.GetCurrentFrame() = WalkingUkyo2.GetCurrentFrame();
		}
	}
	if (cont == 12) {
		Current.GetCurrentFrame() = rectangletextAB2.GetCurrentFrame();
		CurrentA.GetCurrentFrame() = APushing.GetCurrentFrame();
		CurrentB.GetCurrentFrame() = BPushing.GetCurrentFrame();
		CurrentC.GetCurrentFrame() = CNormal.GetCurrentFrame();
		CurrentD.GetCurrentFrame() = DNormal.GetCurrentFrame();
		CurrentP1.GetCurrentFrame() = Idle2Ukyo1.GetCurrentFrame();
		CurrentP2.GetCurrentFrame() = IdleUkyo2.GetCurrentFrame();
		if ((count == 0) && (BPushing.current_frame >= 8)) {
			CurrentP1.GetCurrentFrame() = ABWithoutWeaponUkyo1.GetCurrentFrame();
		}
		if (ABWithoutWeaponUkyo1.current_frame >= 5) {
			CurrentP1.GetCurrentFrame() = Idle2Ukyo1.GetCurrentFrame();
			if (positionxU2 <= 200) {
				positionxU2 = positionxU2 + 2;
				CurrentP2.GetCurrentFrame() = HittedUkyo2.GetCurrentFrame();
			}
			else {
				CurrentP2.GetCurrentFrame() = IdleUkyo2.GetCurrentFrame();
			}
			count = 1;
		}
	}
	if (cont == 13) {
		count = 0;
		Current.GetCurrentFrame() = CWithoutWeapon.GetCurrentFrame();
		CurrentA.GetCurrentFrame() = ANormal.GetCurrentFrame();
		CurrentB.GetCurrentFrame() = BNormal.GetCurrentFrame();
		CurrentC.GetCurrentFrame() = CNormal.GetCurrentFrame();
		CurrentD.GetCurrentFrame() = DNormal.GetCurrentFrame();
		CurrentP1.GetCurrentFrame() = Idle2Ukyo1.GetCurrentFrame();
		CurrentP2.GetCurrentFrame() = IdleUkyo2.GetCurrentFrame();
		if (positionxU2 >= 155) {
			positionxU2 = positionxU2 - 1;
			CurrentP2.GetCurrentFrame() = WalkingUkyo2.GetCurrentFrame();
		}
	}
	if (cont == 14) {
		Current.GetCurrentFrame() = rectangletextC2.GetCurrentFrame();
		CurrentA.GetCurrentFrame() = ANormal.GetCurrentFrame();
		CurrentB.GetCurrentFrame() = BNormal.GetCurrentFrame();
		CurrentC.GetCurrentFrame() = CPushing.GetCurrentFrame();
		CurrentD.GetCurrentFrame() = DNormal.GetCurrentFrame();
		CurrentP1.GetCurrentFrame() = Idle2Ukyo1.GetCurrentFrame();
		CurrentP2.GetCurrentFrame() = IdleUkyo2.GetCurrentFrame();
		if ((count == 0) && (CPushing.current_frame >= 8)) {
			CurrentP1.GetCurrentFrame() = CWithoutWeaponUkyo1.GetCurrentFrame();
		}
		if (CWithoutWeaponUkyo1.current_frame >= 3) {
			CurrentP1.GetCurrentFrame() = Idle2Ukyo1.GetCurrentFrame();
			if (positionxU2 <= 200) {
				positionxU2 = positionxU2 + 2;
				CurrentP2.GetCurrentFrame() = HittedUkyo2.GetCurrentFrame();
			}
			else {
				CurrentP2.GetCurrentFrame() = IdleUkyo2.GetCurrentFrame();
			}
			count = 1;
		}
	}
	if (cont == 15) {
		count = 0;
		CWithoutWeaponUkyo1.Reset();
		Current.GetCurrentFrame() = DWithoutWeapon.GetCurrentFrame();
		CurrentA.GetCurrentFrame() = ANormal.GetCurrentFrame();
		CurrentB.GetCurrentFrame() = BNormal.GetCurrentFrame();
		CurrentC.GetCurrentFrame() = CNormal.GetCurrentFrame();
		CurrentD.GetCurrentFrame() = DNormal.GetCurrentFrame();
		CurrentP1.GetCurrentFrame() = Idle2Ukyo1.GetCurrentFrame();
		CurrentP2.GetCurrentFrame() = IdleUkyo2.GetCurrentFrame();
		if (positionxU2 >= 155) {
			positionxU2 = positionxU2 - 1;
			CurrentP2.GetCurrentFrame() = WalkingUkyo2.GetCurrentFrame();
		}
	}
	if (cont == 16) {
		Current.GetCurrentFrame() = rectangletextD2.GetCurrentFrame();
		CurrentA.GetCurrentFrame() = ANormal.GetCurrentFrame();
		CurrentB.GetCurrentFrame() = BNormal.GetCurrentFrame();
		CurrentC.GetCurrentFrame() = CNormal.GetCurrentFrame();
		CurrentD.GetCurrentFrame() = DPushing.GetCurrentFrame();
		CurrentP1.GetCurrentFrame() = Idle2Ukyo1.GetCurrentFrame();
		CurrentP2.GetCurrentFrame() = IdleUkyo2.GetCurrentFrame();
		if ((count == 0) && (DPushing.current_frame >= 8)) {
			CurrentP1.GetCurrentFrame() = CWithoutWeaponUkyo1.GetCurrentFrame();
		}
		if (CWithoutWeaponUkyo1.current_frame >= 3) {
			CurrentP1.GetCurrentFrame() = Idle2Ukyo1.GetCurrentFrame();
			if (positionxU2 <= 200) {
				positionxU2 = positionxU2 + 2;
				CurrentP2.GetCurrentFrame() = HittedUkyo2.GetCurrentFrame();
			}
			else {
				CurrentP2.GetCurrentFrame() = IdleUkyo2.GetCurrentFrame();
			}
			count = 1;
		}
	}
	if (cont == 17) {
		count = 0;
		Current.GetCurrentFrame() = CDWithoutWeapon.GetCurrentFrame();
		CurrentA.GetCurrentFrame() = ANormal.GetCurrentFrame();
		CurrentB.GetCurrentFrame() = BNormal.GetCurrentFrame();
		CurrentC.GetCurrentFrame() = CNormal.GetCurrentFrame();
		CurrentD.GetCurrentFrame() = DNormal.GetCurrentFrame();
		CurrentP1.GetCurrentFrame() = Idle2Ukyo1.GetCurrentFrame();
		CurrentP2.GetCurrentFrame() = IdleUkyo2.GetCurrentFrame();
		if (positionxU2 >= 155) {
			positionxU2 = positionxU2 - 1;
			CurrentP2.GetCurrentFrame() = WalkingUkyo2.GetCurrentFrame();
		}
	}
	if (cont == 18) {
		Current.GetCurrentFrame() = rectangletextCD2.GetCurrentFrame();
		CurrentA.GetCurrentFrame() = ANormal.GetCurrentFrame();
		CurrentB.GetCurrentFrame() = BNormal.GetCurrentFrame();
		CurrentC.GetCurrentFrame() = CPushing.GetCurrentFrame();
		CurrentD.GetCurrentFrame() = DPushing.GetCurrentFrame();
		CurrentP1.GetCurrentFrame() = Idle2Ukyo1.GetCurrentFrame();
		CurrentP2.GetCurrentFrame() = IdleUkyo2.GetCurrentFrame();

		if ((count == 0) && (CPushing.current_frame >= 8)) {
			CurrentP1.GetCurrentFrame() = CDWithoutWeaponUkyo1.GetCurrentFrame();
		}
		if (CDWithoutWeaponUkyo1.current_frame >= 6) {
			CurrentP1.GetCurrentFrame() = Idle2Ukyo1.GetCurrentFrame();
			if (positionxU2 <= 200) {
				positionxU2 = positionxU2 + 2;
				CurrentP2.GetCurrentFrame() = HittedUkyo2.GetCurrentFrame();
			}
			else {
				CurrentP2.GetCurrentFrame() = IdleUkyo2.GetCurrentFrame();
			}
			count = 1;
		}
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
	App->render->Blit(graphics3, positionxU1, positionyU1, &(CurrentP1.GetCurrentFrame()), 1);
	App->render->Blit(graphics3, positionxU2, 55, &(CurrentP2.GetCurrentFrame()), 1); // Player 2
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
	//App->UI->Disable();
	App->textures->Unload(graphics);
	App->textures->Unload(graphics2);
	App->textures->Unload(graphics3);
	return true;
}
/*#ifndef __ModuleReferee_H__
#define __ModuleReferee_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"

struct SDL_Texture;
class ModuleReferee : public Module;
enum state {
	A_NONE = 0,
	A_IDLE,
	A_FORWARD,
	A_BACKWARD,
	A_START,
	A_END,

};

	class ModuleReferee : public Module
	{
	public:
		ModuleReferee();
		~ModuleReferee();

		ModuleReferee();

		bool Start();
		update_status PreUpdate();
		update_status Update();
		update_status PostUpdate();
		bool CleanUp();
		

	public:

		
		SDL_Texture* graphics = nullptr;

		SDL_Rect shadowrect;


		iPoint position;
		int mult;
		state actual;
	
	};

#endif*/
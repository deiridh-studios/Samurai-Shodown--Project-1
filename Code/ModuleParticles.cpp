#include <math.h>
#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModulePlayer.h"

#include "SDL/include/SDL_timer.h"

ModuleParticles::ModuleParticles()
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
		active[i] = nullptr;
}

ModuleParticles::~ModuleParticles()
{}

// Load assets
bool ModuleParticles::Start()
{
	LOG("Loading particles");
	graphics = App->textures->Load("sprites/spritesHaohmaruFIXED.png");

	// Tornado particle

	////////Tornado animation

	tornado.anim.PushBack({ 1182, 861, 106, 70 });
	tornado.anim.PushBack({ 1288, 861, 106, 70 });
	tornado.anim.PushBack({ 1394, 861, 123, 70 });
	tornado.anim.PushBack({ 1517, 861, 120'2, 70 });
	tornado.anim.PushBack({ 1637'2, 861, 142'8, 70 });
	tornado.anim.speed = 0.2f;
	tornado.speed.x = 5;
	tornado.life = 2300;

	tornado2.anim.PushBack({ 584, 2756, 71, 220});
	tornado2.anim.PushBack({ 730, 2756, 71, 220});
	tornado2.anim.PushBack({ 874, 2756, 71, 220});
	tornado2.anim.PushBack({ 1028, 2756, 71, 220 });
	tornado2.anim.PushBack({ 1168, 2756, 71, 220 });
	tornado2.anim.PushBack({ 1310, 2756, 71, 220 });
	tornado2.anim.PushBack({ 1454, 2756, 71, 220 });
	tornado2.anim.PushBack({ 1590, 2756, 46, 220});
	tornado2.anim.PushBack({ 18, 2970, 46, 216 });
	tornado2.anim.PushBack({ 164, 2970, 46, 216 });
	tornado2.anim.PushBack({ 300, 2970, 46, 216 });
	tornado2.anim.PushBack({ 436, 2970, 46, 216 });
	tornado2.anim.PushBack({ 532, 2970, 46, 216 });
	tornado2.anim.PushBack({ 674, 2970, 46, 216 });
	tornado2.anim.speed = 0.2f;
	tornado2.speed.x = 0;
	tornado2.life = 2300;

	// sword particle
	sword.anim.PushBack({ ,2065, 8,76});
	sword.anim.PushBack({ ,2065, 55,76});
	sword.anim.PushBack({ ,2065, 77,76});
	sword.anim.PushBack({ ,2065, 55,76});
	sword.anim.PushBack({ ,2065, 8,76});
	sword.anim.PushBack({ ,2065, 55,76});
	sword.anim.PushBack({ ,2065, 77,76});
	// eagle particle

	return true;
}

// Unload assets
bool ModuleParticles::CleanUp()
{
	LOG("Unloading particles");
	App->textures->Unload(graphics);

	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		if (active[i] != nullptr)
		{
			delete active[i];
			active[i] = nullptr;
		}
	}

	return true;
}

// Update: draw background
update_status ModuleParticles::Update()
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		Particle* p = active[i];

		if (p == nullptr)
			continue;
		if (p->speed.x==0&&p->anim.GetFinished() == 1) {
			delete p;
			active[i] = nullptr;
		}
		else if (p->Update() == false)
		{
			delete p;
			active[i] = nullptr;
		}
		else if ((int)SDL_GetTicks() >= p->born)
		{
			App->render->Blit(graphics, p->position.x, p->position.y, &(p->anim.GetCurrentFrame()));
			if (p->fx_played == false)
			{
				p->fx_played = true;
			}
		}
	}

	return UPDATE_CONTINUE;
}

void ModuleParticles::AddParticle(const Particle& particle, int x, int y, COLLIDER_TYPE collider_type, Uint32 delay)
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		if (active[i] == nullptr)
		{
			Particle* p = new Particle(particle);
			p->born = (int)SDL_GetTicks() + delay;
			p->position.x = x;
			p->position.y = y;
			if (collider_type == COLLIDER_PLAYER_SHOT) {
				if (App->player->flip == true)p->speed.x = 0 - p->speed.x;
			}
			else if (collider_type == COLLIDER_ENEMY_SHOT) {
				if (App->player2->flip == true)p->speed.x = 0 - p->speed.x;
			}
			if (collider_type != COLLIDER_NONE)
				p->collider = App->collision->AddCollider(p->anim.GetCurrentFrame(), collider_type, this);
			active[i] = p;
			break;
		}
	}
}

void ModuleParticles::OnCollision(Collider* c1, Collider* c2)
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		if (c2->type == COLLIDER_ENEMY) {
			if (active[i] != nullptr && active[i]->collider == c1)
			{
				delete active[i];
				active[i] = nullptr;
				AddParticle(tornado2, App->player2->position.x + 10, 0, COLLIDER_NONE, 0);
				break;
			}
		}
		else if (c2->type == COLLIDER_PLAYER){
			if (active[i] != nullptr && active[i]->collider == c1)
			{
				delete active[i];
				active[i] = nullptr;
				AddParticle(tornado2, App->player->position.x + 10, 0, COLLIDER_NONE, 0);
				//active[i]->speed.x = 0;
				break;
			}
			}
	}
}

// -------------------------------------------------------------
// -------------------------------------------------------------

Particle::Particle()
{
	position.SetToZero();
	speed.SetToZero();
}

Particle::Particle(const Particle& p) :
	anim(p.anim), position(p.position), speed(p.speed),
	fx(p.fx), born(p.born), life(p.life)
{}

Particle::~Particle()
{
	if (collider != nullptr)
		collider->to_delete = true;
}

bool Particle::Update()
{
	bool ret = true;

	if (life > 0)
	{
		if (((int)SDL_GetTicks() - born) > life)
			ret = false;
	}
	else
		if (anim.GetFinished()==0)
			ret = false;

	position.x += speed.x;
	position.y += speed.y;

	if (collider != nullptr)
		collider->SetPos(position.x, position.y);

	return ret;
}


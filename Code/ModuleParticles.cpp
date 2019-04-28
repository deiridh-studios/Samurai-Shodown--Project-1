#include <math.h>
#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"

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

	tornado.anim.PushBack({ 172, 2660, 28, 100 });
	tornado.anim.PushBack({ 316, 2660, 34, 100 });
	tornado.anim.PushBack({ 458, 2660, 44, 100 });
	tornado.anim.PushBack({ 602, 2660, 34, 100 });
	tornado.anim.PushBack({ 738, 2660, 48, 100 });
	tornado.anim.PushBack({ 864, 2660, 80, 100 });
	tornado.anim.PushBack({ 1008, 2660, 98, 100 });
	tornado.anim.PushBack({ 1154, 2660, 102, 100 });
	tornado.anim.PushBack({ 1296, 2660, 94, 100 });
	tornado.anim.PushBack({ 1436, 2660, 98, 100 });
	tornado.anim.PushBack({ 1580, 2660, 92, 100 });
	tornado.anim.PushBack({ 1730, 2660, 86, 100 });
	tornado.anim.PushBack({ 1872, 874, 82, 100 });
	tornado.anim.PushBack({ 16, 2756, 71, 220 });
	tornado.anim.PushBack({ 154, 2756, 71, 220 });
	tornado.anim.PushBack({ 308, 2756, 71, 220});
	tornado.anim.PushBack({ 452, 2756, 71, 220});
	tornado.anim.PushBack({ 584, 2756, 71, 220});
	tornado.anim.PushBack({ 730, 2756, 71, 220});
	tornado.anim.PushBack({ 874, 2756, 71, 220});
	tornado.anim.PushBack({ 1028, 2756, 71, 220 });
	tornado.anim.PushBack({ 1168, 2756, 71, 220 });
	tornado.anim.PushBack({ 1310, 2756, 71, 220 });
	tornado.anim.PushBack({ 1454, 2756, 71, 220 });
	tornado.anim.PushBack({ 1590, 2756, 46, 220});
	tornado.anim.PushBack({ 18, 2970, 46, 216 });
	tornado.anim.PushBack({ 164, 2970, 46, 216 });
	tornado.anim.PushBack({ 300, 2970, 46, 216 });
	tornado.anim.PushBack({ 436, 2970, 46, 216 });
	tornado.anim.PushBack({ 532, 2970, 46, 216 });
	tornado.anim.PushBack({ 674, 2970, 46, 216 });
	tornado.anim.speed = 0.2f;
	tornado.speed.x = 5;
	tornado.life = 3000;

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

		if (p->Update() == false)
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
			if (collider_type != COLLIDER_NONE)
				p->collider = App->collision->AddCollider(p->anim.GetCurrentFrame(), collider_type, this);
			active[i] = p;
			break;
		}
	}
}

void ModuleParticles::OnCollision(Collider* c1, Collider* c2, int x)
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		
		if (active[i] != nullptr && active[i]->collider == c1)
		{
			tornado.speed.x = 0;
			/*delete active[i];
			active[i] = nullptr;*/
			break;
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


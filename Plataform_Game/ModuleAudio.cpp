#include "Globals.h"
#include "Application.h"
#include "ModuleAudio.h"

#include"SDL_Mixer/include/SDL_mixer.h"
#pragma comment(lib, "SDL_Mixer/libx86/SDL2_mixer.lib")

ModuleAudio::ModuleAudio() {
	for (int i = 0; i < MAX_CHUNK; i++) {
		chunks[i] = nullptr;
	}
	for (int i = 0; i < MAX_MUSIC; i++) {
		musics[i] = nullptr;
	}
}

ModuleAudio::~ModuleAudio() {}

bool ModuleAudio::Init() {
	LOG("Init Mixer library");
	bool ret = true;
	int flags = MIX_INIT_OGG;
	int init = Mix_Init(flags);

	if ((init & flags) != flags)
	{
		LOG("Could not initialize Mixer lib.\n\n Mix_Init: %s", Mix_GetError());
		ret = false;
	}
	if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 4096) == -1) {
		LOG("Could not open audio.\n\n Mix_OpenAudio: %s", Mix_GetError());
		ret = false;
	}
	("Could initilialze\n\n");
	return ret;
}


bool ModuleAudio::CleanUp() {

	LOG("Freeing chunks, music and Mixer library");

	for (int i = MAX_CHUNK - 1; i >= 0; i--) {
		if (chunks[i] != nullptr) {
			Mix_FreeChunk(chunks[i]);
			chunks[i] = nullptr;
		}
	}
	for (int i = MAX_MUSIC - 1; i >= 0; i--) {
		if (musics[i] != nullptr) {
			Mix_FreeMusic(musics[i]);
			musics[i] = nullptr;
		}
	}
	Mix_CloseAudio();
	while (Mix_Init(0)) {
		Mix_Quit();
	}
	return true;
}



Mix_Chunk* const ModuleAudio::LoadChunk(const char* path) {
	Mix_Chunk *chunk;
	chunk = Mix_LoadWAV(path);
	if (chunk == NULL) {
		LOG("Chunk not correct\n\n\n\n\n");
		LOG(Mix_GetError());
		return false;
	}
	LOG("Chunk correct\n\n\n\n\n");
	for (int i = 0; i < MAX_CHUNK; i++) {
		if (chunks[i] == nullptr) {
			chunks[i] = chunk;
			return chunk;
		}
	}
	return nullptr;
}

Mix_Music* const ModuleAudio::LoadMusic(const char* path) {
	Mix_Music *musicload;
	musicload = Mix_LoadMUS(path);
	if (musicload == NULL) {
		LOG("Music not correct\n\n\n\n\n");
		LOG(Mix_GetError());
		return false;
	}
	LOG("Music correct\n\n\n\n\n");
	for (int i = 0; i < MAX_CHUNK; i++) {
		if (musics[i] == nullptr) {
			musics[i] = musicload;
			return musicload;
		}
	}
	return nullptr;
}
bool const ModuleAudio::UnLoadChunk(Mix_Chunk* chunk) {
	if (chunk != nullptr)
	{
		for (int i = 0; i < MAX_CHUNK; ++i)
		{
			if (chunks[i] == chunk)
			{
				chunks[i] = nullptr;
				Mix_FreeChunk(chunk);
				break;
			}
		}
	}
	return true;
}
bool const ModuleAudio::UnLoadMusic(_Mix_Music* music) {
	if (music != nullptr)
	{
		for (int i = 0; i < MAX_MUSIC; ++i)
		{
			if (musics[i] == music)
			{
				musics[i] = nullptr;
				Mix_FreeMusic(music);
				break;
			}
		}
	}
	return true;
}

void ModuleAudio::PlayChunk(Mix_Chunk* chunk, int loops, int channel) {
	Mix_PlayChannel(channel, chunk, loops);
}
void ModuleAudio::StopChunk() {
	Mix_HaltChannel(-1);
}

void ModuleAudio::PlayMusic(_Mix_Music* music) {
	if (Mix_FadeInMusic(music, -1, 1000) != 0) LOG("Music not playing correctly: Mix_FadeInMusic: %s", Mix_GetError());
}

void ModuleAudio::StopMusic() {
	if (Mix_FadeOutMusic(1000) != 1) LOG("Music not stoping correctly: Mix_FadeOutMusic: %s", Mix_GetError());
}
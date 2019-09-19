#ifndef __ModuleAudio_H__
#define __ModuleAudio_H__

#include "Module.h"

#define MAX_CHUNK 10
#define MAX_MUSIC 5

struct Mix_Chunk;
struct _Mix_Music;



class ModuleAudio :public Module {
public:
	ModuleAudio();
	~ModuleAudio();

	bool Init();
	bool CleanUp();

	Mix_Chunk* const LoadChunk(const char* path);
	_Mix_Music* const LoadMusic(const char* path);
	bool const UnLoadChunk(Mix_Chunk* chunk);
	bool const UnLoadMusic(_Mix_Music* music);
	void PlayChunk(Mix_Chunk*, int loops = 0, int channel = -1);
	void StopChunk();
	void PlayMusic(_Mix_Music*);
	void StopMusic();

public:
	Mix_Chunk * chunks[MAX_CHUNK];
	_Mix_Music * musics[MAX_MUSIC];
};
#endif
#ifndef __ModuleAudio_H__
#define __ModuleAudio_H__

#include "Module.h"

#define MAX_CHUNK 50
#define MAX_MUSIC 20

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
	void PlayChunk(Mix_Chunk*);
	void PlayMusic(_Mix_Music*);
	void StopMusic();

public:
	Mix_Chunk * chunks[MAX_CHUNK];
	_Mix_Music * musics[MAX_MUSIC];
};
#endif
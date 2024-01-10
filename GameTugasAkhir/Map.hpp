#pragma once
#include "Game.hpp"


//Definition for the map class
class Map
{
public:

	Map();
	~Map();

	void LoadMap(int arr[20][25]);
	void DrawMap();

	void RandomizeTilesDynamic();

private:

	SDL_Rect src, dest;

	SDL_Texture* putih;
	SDL_Texture* hati;
	SDL_Texture* kriting;
	SDL_Texture* kucing;
	SDL_Texture* topi;
	SDL_Texture* wajik;
	SDL_Texture* waru;

	int map[20][25];

};
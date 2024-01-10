#include "Map.hpp"
#include "TextureManager.hpp"
#include <cstdlib>  // For rand() function
#include <ctime>    // For time() function


//20 rows 25 collums
//set the map here
//0 is water, 1 is grass, 2 is dirt
int lvl1[20][25] = {

	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};

Map::Map()
{
	putih = TextureManager::LoadTexture("assets/putih.png");
	hati = TextureManager::LoadTexture("assets/hati.png");
	kriting = TextureManager::LoadTexture("assets/kriting.png");
	kucing = TextureManager::LoadTexture("assets/kucing.png");
	topi = TextureManager::LoadTexture("assets/topi.png");
	wajik = TextureManager::LoadTexture("assets/wajik.png");
	waru = TextureManager::LoadTexture("assets/waru.png");

	LoadMap(lvl1);

	src.x = src.y = 0; //don't get confused by this, it's the same
	src.w = dest.w = 32;
	src.h = dest.h = 32; 

	dest.x = dest.y = 0;

}

void Map::LoadMap(int arr[20][25])
{
	for (int row = 0; row < 20; row++)
	{
		for (int column = 0; column < 25; column++)
		{
			map[row][column] = arr[row][column];
		}
	}
}

void Map::DrawMap()
{
	int type = 0;

	for (int row = 0; row < 20; row++)
	{
		for (int column = 0; column < 25; column++)
		{
			type = map[row][column];

			dest.x = column * 32;
			dest.y = row * 32;

			switch (type)
			{
			case 0:
				TextureManager::Draw(putih, src, dest);
				break;
			case 1:
				TextureManager::Draw(hati, src, dest);
				break;
			case 2:
				TextureManager::Draw(kriting, src, dest);
				break;
			case 3:
				TextureManager::Draw(kucing, src, dest);
				break;
			case 4:
				TextureManager::Draw(topi, src, dest);
				break;
			case 5:
				TextureManager::Draw(wajik, src, dest);
				break;
			case 6:
				TextureManager::Draw(waru, src, dest);
				break;
			default:
				break;
			}
		}
	}
}


//Randomizer for the map
void Map::RandomizeTilesDynamic()
{
	// Dynamic randomization logic here
	int row = rand() % 20;
	int column = rand() % 25;
	int type = rand() % 7; // Change this to the number of tiles you have

	map[row][column] = type;
}
#include "Game.hpp"
#include "Texturemanager.hpp"
#include "GameObject.hpp"
#include "Map.hpp"

Map* map;

SDL_Renderer* Game::renderer = nullptr;

Game::Game() : isRunning(false), window(nullptr)
{}

Game::~Game()
{}


void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystem Initialized!..." << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
		{
			std::cout << "Window Created!" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer Created!" << std::endl;
		}

		isRunning = true;
	}
	else {
		isRunning = false;
	}

	map = new Map();
	map->RandomizeTilesDynamic(); // Randomize the tiles

	lastActivityTime = SDL_GetTicks();  // Initialize last activity time

}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
		case SDL_QUIT:
			isRunning = false;
			break;

		default:
			break;

	}
}

void Game::update() {
	// Dynamic randomization during the game loop
	SDL_Delay(20); // Delay for 20 milliseconds (adjust as needed)
	map->RandomizeTilesDynamic();
}


void Game::render()
{
	SDL_RenderClear(renderer);
	//this is where you put stuff to render
	//put the order as same as the layer texture
	map->DrawMap();

	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Cleaned!" << std::endl;
}

#include <iostream>
#include <sstream>
#include "SDL.h"
#include "breakout.h"

// Define game Resolution.
#define GAME_X_RESOLUTION 1280
#define GAME_Y_RESOLUTION 720

int main(int argc, char* argv[]) {
	bool programOn = true;

	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow("game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, GAME_X_RESOLUTION, GAME_Y_RESOLUTION, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

	Breakout game(8, 5, GAME_X_RESOLUTION, GAME_Y_RESOLUTION);

	SDL_Event event;
	// Game render loop.
	while (programOn) {
		// Handle key inputs.
		while (SDL_PollEvent(&event) != 0) {
			//printf("SDL_PollEvent(&event) != 0\n");
			if (event.type == SDL_QUIT) {
				programOn = false;
			}
			if (event.type == SDL_KEYDOWN) {
				switch (event.key.keysym.sym)
				{
				case SDLK_LEFT:
					game.movePlank(-(GAME_X_RESOLUTION / 64));
					break;
				case SDLK_RIGHT:
					game.movePlank(GAME_X_RESOLUTION / 64);
					break;
				case SDLK_ESCAPE: {
					programOn = false;
					break;
				}
				default:
					printf("\n[INVALID INPUT]\n");
					break;
				}
			}
		}
		// Update the ball position.
		game.moveBall();
		// Check if Game Over.
		if (game.getGameOver()) {
			programOn = false;
		}
		// Background color.
		SDL_SetRenderDrawColor(renderer, 70, 70, 70, 255);
		// Clear the renderer.
		SDL_RenderClear(renderer);
		// Render game objects.
		game.render(renderer);
		// Render present.
		SDL_RenderPresent(renderer);
	}

	return 0;
}
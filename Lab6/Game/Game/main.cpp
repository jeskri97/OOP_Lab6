
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

	// Amount of bricks per row.
	int bricksPerRow = 8;
	// Amount of rows.
	int numberOfRows = 5;
	// Width and height of bricks.
	int width = GAME_X_RESOLUTION / bricksPerRow, height = (GAME_Y_RESOLUTION / 2) / numberOfRows;
	// Position of the first brick
	Point2D brickPos(width / 2, height / 2);
	// Setup the wall.
	Rectangle brick;
	std::vector<std::vector<Rectangle>> wall;
	for (int i = 0; i < numberOfRows + 1; i++) {
		std::vector<Rectangle> row;
		for (int j = 0; j < bricksPerRow; j++) {
			// Set brick color.
			brick.setColor(0, 0, 0, 255);
			// Set brick position.
			brick.setPos(brickPos);
			// Set brick Width and height.
			brick.setVal(width, height);
			// Add brick to list.
			row.push_back(brick);
			// Update brick position for next brick.
			brickPos = brickPos + Point2D(width, 0);
		}
		// Add row to wall.
		wall.push_back(row);
		// Update brick position for next brick.
		brickPos = Point2D(width / 2, (height / 2) + height * i);
	}

	Breakout game(wall, GAME_X_RESOLUTION, GAME_Y_RESOLUTION);

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
		game.moveBall();
		if (game.getGameOver()) {
			programOn = false;
		}
		// Background color.
		SDL_SetRenderDrawColor(renderer, 70, 70, 70, 255);
		SDL_RenderClear(renderer);
		// Render game objects.
		game.render(renderer);
		// Render present.
		SDL_RenderPresent(renderer);
	}

	return 0;
}
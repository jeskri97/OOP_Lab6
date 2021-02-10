
#include <iostream>
#include <sstream>
#include "SDL.h"

int main(int argc, char* argv[]) {
	bool programOn = true;

	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow("game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);

	SDL_Event event;
	while (programOn) {
		while (SDL_PollEvent(&event) != 0) {
			//printf("SDL_PollEvent(&event) != 0\n");
			if (event.type == SDL_QUIT) {
				programOn = false;
			}
			SDL_RenderPresent(renderer);
			if (event.type == SDL_KEYDOWN) {
				switch (event.key.keysym.sym)
				{
				case SDLK_ESCAPE: {
					programOn = false;
					break;
				}
				//case SDL_MOUSEMOTION: {
				//	int mouseX = event.motion.x;
				//	int mouseY = event.motion.y;
				//
				//	std::stringstream ss;
				//	ss << "X: " << mouseX << " Y: " << mouseY;
				//
				//	SDL_SetWindowTitle(window, ss.str().c_str());
				//	break;
				//}
				default:
					printf("\n[INVALID INPUT]\n");
					break;
				}
			}
		}
	}

	return 0;
}

//// testing that SLD linked correctly.
//int main(int argc, char* argv[]) {
//	SDL_SetMainReady();
//
//	SDL_Init(SDL_INIT_EVERYTHING);
//	SDL_Window* window = SDL_CreateWindow("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN);
//	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
//
//	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
//
//	SDL_RenderClear(renderer);
//
//	SDL_RenderPresent(renderer);
//
//	SDL_Delay(3000);
//
//	return 0;
//}
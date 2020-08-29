#include <stdint.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include "display.h"
#include "vector.h"
#include "player.h"
#include "colours.h"

bool is_running = NULL;

Player player;

void setup(void);

void process_input(void);

void update(void);

void render(void);

int main(void) {
	is_running = init_window();

	setup();

	while (is_running) {
		process_input();
		update();
		render();
	}

	cleanup();

	return 0;
}

void setup(void) {
	// Allocate the required bytes in memory for the colour buffer
	colour_buffer = (uint32_t *) malloc(sizeof(uint32_t) * window_width * window_height);

	colour_buffer_texture = SDL_CreateTexture(
			renderer,
			SDL_PIXELFORMAT_ARGB8888,
			SDL_TEXTUREACCESS_STREAMING,
			window_width,
			window_height
	);

	create_player();
}

void process_input(void) {
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type) {
		case SDL_QUIT:
			is_running = false;
			break;
		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_ESCAPE) {
				is_running = false;
			} else if (event.key.keysym.sym == SDLK_w) {
				player.vel = (Vector) {
						.x = 0,
						.y = -player.speed
				};
			} else if (event.key.keysym.sym == SDLK_s) {
				player.vel = (Vector) {
						.x = 0,
						.y = player.speed
				};
			} else if (event.key.keysym.sym == SDLK_a) {
				player.vel = (Vector) {
						.x = -player.speed,
						.y = 0
				};
			} else if (event.key.keysym.sym == SDLK_d) {
				player.vel = (Vector) {
						.x = player.speed,
						.y = 0
				};
			}
			break;
		default:
			break;
	}
}

void update(void) {
	update_player();
}

void render(void) {
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderClear(renderer);

	draw_grid();
	draw_player();

	render_colour_buffer();
	clear_colour_buffer(BLACK);

	SDL_RenderPresent(renderer);
}

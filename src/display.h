#ifndef SNAKE_DISPLAY_H
#define SNAKE_DISPLAY_H

#include <stdint.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

extern int window_width;
extern int window_height;

extern SDL_Window *window;
extern SDL_Renderer *renderer;
extern SDL_Texture *colour_buffer_texture;
// Declare a pointer to an array of uint32 elements.
extern uint32_t *colour_buffer;

bool init_window(void);

void clear_colour_buffer(uint32_t colour);

void render_colour_buffer(void);

void draw_grid(void);

void draw_fill_rect(int x, int y, int width, int height, uint32_t colour);

void cleanup(void);

#endif //SNAKE_DISPLAY_H

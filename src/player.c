#include "player.h"
#include "display.h"
#include "colours.h"

void create_player(void) {
	player.pos = (Vector) {
			.x = 10,
			.y = 10,
	};
	player.w = 10;
	player.h = 10;
	player.vel = (Vector) {
			.x = 0,
			.y = 0,
	};
	player.colour = PINK;
	player.speed = player.w;
}

void draw_player(void) {
	draw_fill_rect(player.pos.x, player.pos.y, player.w, player.h, player.colour);
}

void update_player(void) {
	player.pos = vector2_add(player.pos, player.vel);
}


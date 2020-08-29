#ifndef SNAKE_PLAYER_H
#define SNAKE_PLAYER_H

#include <stdint.h>
#include "vector.h"

typedef struct player_ {
	Vector pos;
	Vector vel;
	int w;
	int h;
	uint32_t colour;
	int speed;
} Player;
extern Player player;

void create_player(void);

void draw_player(void);

void update_player(void);

#endif //SNAKE_PLAYER_H

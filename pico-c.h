
#ifndef __PICO_C_H
#define __PICO_C_H

#include <stdbool.h>

#define E_NO_DRAW (1)

#define SCREEN_WIDTH (64)
#define SCREEN_HEIGHT (64)

// TYPES

typedef char color_t;
struct point_t { int x, y; };
struct rect_t { struct point_t aa, bb; };

// CONSTANTS

static const struct rect_t screen_rect = {
	{0, 0},
	{SCREEN_WIDTH, SCREEN_HEIGHT}
};

// PUBLIC FUNCTIONS

int cls(color_t col);
int rect(struct rect_t r, color_t col);
int line(struct point_t a, struct point_t b, color_t col);
int swap();

#endif

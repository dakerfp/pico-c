
#ifndef __PICO_C_H
#define __PICO_C_H

#include <stdbool.h>

typedef char color_t;

#define E_NO_DRAW (1)

struct point_t {
	int x, y;
};

struct rect_t {
	struct point_t aa, bb;
};

#define SCREEN_WIDTH (32)
#define SCREEN_HEIGHT (32)
static const struct rect_t screen_rect = {
	{0, 0},
	{SCREEN_WIDTH, SCREEN_HEIGHT}
};

// PUBLIC API

int cls(color_t col);
int rect(struct rect_t r, color_t col);
int swap();

#endif

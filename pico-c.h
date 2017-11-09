
#ifndef __PICO_C_H
#define __PICO_C_H

#include <stdbool.h>

#define E_NO_DRAW (1)

#define SCREEN_WIDTH (64)
#define SCREEN_HEIGHT (64)
#define SPRITE_WIDTH (8)
#define MAX_SPRITES (256)

// TYPES

typedef char color_t;
struct point_t { int x, y; };
struct rect_t { struct point_t aa, bb; };
typedef color_t sprite_t[SPRITE_WIDTH * SPRITE_WIDTH];

// PUBLIC FUNCTIONS

// RAW GRAPHICS
int cls(color_t col);
int pset(struct point_t p, color_t col);
color_t pget(struct point_t p);
int rect(struct rect_t r, color_t col);
int rectfill(struct rect_t r, color_t col);
int line(struct point_t a, struct point_t b, color_t col);

// SPRITE GRAPHICS
int spritesheet(sprite_t sprites[]);
int spr(struct point_t p, int spr);
int swap();

#endif

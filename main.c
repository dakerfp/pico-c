#include "pico-c.h"

#include <ncurses.h>

sprite_t sprs = {
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 1, 1, 2, 2, 1, 1, 0,
	0, 2, 2, 1, 1, 2, 2, 0,
	0, 1, 1, 2, 2, 1, 1, 0,
	0, 2, 2, 1, 1, 2, 2, 0,
	0, 1, 1, 2, 2, 1, 1, 0,
	0, 2, 2, 1, 1, 2, 2, 0,
	0, 0, 0, 0, 0, 0, 0, 0
};

int main()
{
	initscr();
	start_color();
	for (int i = 0; i < 8; ++i)
		init_pair(i + 1, i, i);

	color_t black = 0;
	color_t red = 1;
	color_t green = 2;
	color_t blue = 4;

	// frame 1
	cls(black);
	rectfill((struct rect_t){{3, 3},{SCREEN_WIDTH - 3, SCREEN_HEIGHT - 3}}, red);
	rect((struct rect_t){{6, 6},{SCREEN_WIDTH - 6, SCREEN_HEIGHT - 6}}, green);
	rectfill((struct rect_t){{9, 9},{SCREEN_WIDTH - 9, SCREEN_HEIGHT - 9}}, blue);
	line(
		(struct point_t){9, 9},
		(struct point_t){SCREEN_WIDTH - 9, SCREEN_HEIGHT - 9},
		red
	);
	line(
		(struct point_t){SCREEN_WIDTH - 9, 9},
		(struct point_t){9, SCREEN_HEIGHT - 9},
		red
	);
	swap();

	getch();

	// frame 2
	cls(0);
	spritesheet(&sprs);
	spr((struct point_t){22, 22}, 0);
	spr((struct point_t){23, 32}, 0);
	swap();

	getch();
	endwin();

	return 0;
}

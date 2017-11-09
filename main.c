#include "pico-c.h"

#include <ncurses.h>

int main()
{
	color_t black = 0;
	color_t red = 1;
	color_t green = 2;
	color_t blue = 4;

	cls(black);
	rect((struct rect_t){{3, 3},{SCREEN_WIDTH - 3, SCREEN_HEIGHT - 3}}, red);
	rect((struct rect_t){{6, 6},{SCREEN_WIDTH - 6, SCREEN_HEIGHT - 6}}, green);
	rect((struct rect_t){{9, 9},{SCREEN_WIDTH - 9, SCREEN_HEIGHT - 9}}, blue);
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

	initscr();
	start_color();
	for (int i = 0; i < 8; ++i)
		init_pair(i + 1, i, i);
	clear();
	swap();
	getch();
	endwin();

	return 0;
}

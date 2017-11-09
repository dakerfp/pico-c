#include "pico-c.h"

#include <ncurses.h>

int main()
{
	color_t black = 0;
	color_t red = 1;
	color_t green = 2;
	color_t blue = 4;

	cls(black);
	rect((struct rect_t){{3, 3},{screen_rect.bb.x - 3, screen_rect.bb.y - 3}}, red);
	rect((struct rect_t){{6, 6},{screen_rect.bb.x - 6, screen_rect.bb.y - 6}}, green);
	rect((struct rect_t){{9, 9},{screen_rect.bb.x - 9, screen_rect.bb.y - 9}}, blue);

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

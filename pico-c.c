#include "pico-c.h"

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define ABS(a) (((a) >= 0) ? (a) : (-a))
#define SIGN(a) (((a) > 0) ? 1 : \
	(((a) < 0) ? -1 : 0))

static color_t __pbuff[SCREEN_HEIGHT][SCREEN_WIDTH];

static struct rect_t intersect(struct rect_t a, struct rect_t b)
{
	// XXX: fail on non intersecting rects
	struct rect_t inter = {
		{MAX(a.aa.x, b.aa.x), MAX(a.aa.y, b.aa.y)},
		{MIN(a.bb.x, b.bb.x), MIN(a.bb.y, b.bb.y)},
	};
	return inter;
}

static bool rect_is_valid(struct rect_t r)
{
	return (r.aa.x <= r.bb.x) &&
		(r.aa.y <= r.bb.y);
}

static int put(struct point_t p, color_t col) {
	if (p.x < 0) return E_NO_DRAW;
	if (p.y < 0) return E_NO_DRAW;
	if (p.x >= screen_rect.bb.x) return E_NO_DRAW;
	if (p.y >= screen_rect.bb.y) return E_NO_DRAW;
	__pbuff[p.y][p.x] = col;
	return 0;
}

static color_t __pbuff[SCREEN_HEIGHT][SCREEN_WIDTH];

// PUBLIC API

int cls(color_t col)
{
	int i, j;
	for (i = screen_rect.aa.y; i < screen_rect.bb.y; ++i) {
		for (j = screen_rect.aa.x; j < screen_rect.bb.x; ++j) {
			__pbuff[i][j] = col;
		}
	}
	return 0;
}

int rect(struct rect_t r, color_t col)
{
	int i, j;
	r = intersect(screen_rect, r);
	if (!rect_is_valid(r)) {
		return E_NO_DRAW;
	}
	for (i = r.aa.y; i <= r.bb.y; ++i) {
		for (j = r.aa.x; j <= r.bb.x; ++j) {
			__pbuff[i][j] = col;
		}
	}
	return 0;
}

int line(struct point_t a, struct point_t b, color_t col)
{
	if (a.x > b.x) {
		// swap
		struct point_t temp = a;
		a = b;
		b = temp;
	}

	// Bresenham's line drawing algorithm
	float deltax = b.x - a.x;
    float deltay = b.y - a.y;
    float deltaerr = ABS(deltay / deltax);
    float error = 0;
    int signy = SIGN(deltay);

    struct point_t p;
    p.y = a.y;
    for (p.x = a.x; p.x <= b.x; ++p.x) {
		put(p, col);
		error += deltaerr;
		while (error >= 0.5) {
			p.y += signy;
			error -= 1;
		}
    }

	return 0;
}

#include <ncurses.h>
int swap() {
	int i, j;
	for (i = screen_rect.aa.y; i < screen_rect.bb.y; ++i) {
		for (j = screen_rect.aa.x; j < screen_rect.bb.x; ++j) {
			attron(COLOR_PAIR(__pbuff[i][j] + 1));
			mvaddch(i, j, '#');
		}
	}
	return 0;
}


#include <cdk.h>
#include <ncurses.h>
#ifndef UI_H
#define UI_H

extern WINDOW *screen;
extern CDKSCREEN *cdkscreen;
extern CDKSCROLL *cdkscroll;


void display_ui(const char *path);
void draw_borders_after_refresh();
#endif

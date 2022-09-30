#ifndef TUI_H
#define TUI_H

/*
    * This file is part of the Proyecto project.
    Management of the user interface of the program.
*/

// move the cursor to the specified position
void gotoxy(int x, int y);
// create a new screen
#define NEW_SCREEN() printf("\e[?1049h")
// delete the current screen
#define CLOSE_SCREEN() printf("\e[?1049l")

// prints the status bar at the bottom of the screen
void print_status_bar();

// Text styles
#define NORMAL "\e[0m"
#define BOLD "\e[1m"
#define DIM "\e[2m"
#define ITALIC "\e[3m"
#define INVERSE "\e[7m"

// Colors
#define STR(X) #X
#define BRGB(R,G,B) "\e[48;2;" STR(R) STR(;) STR(G) STR(;) STR(B) STR(m)
#define FRGB(R,G,B) "\e[38;2;" STR(R) STR(;) STR(G) STR(;) STR(B) STR(m)

// MISC
#define HIDE_CURSOR "\e[?25l"
#define SHOW_CURSOR "\e[?25h"

// Cursor echo
void noEcho();
void echo();

// Get window size
void get_window_size(int *rows, int *cols);

#endif
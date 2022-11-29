#include "curses.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	initscr();
	int yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);

	WINDOW* menuwin = newwin(6, xMax - 12, yMax - 8, 5);
	box(menuwin, 0, 0);
	refresh();
	wrefresh(menuwin);

	keypad(menuwin, true);
	
	string choices[3] = { "walk","jog","running" };
	int choice, highlight = 0;

	while (1) {
		for (int i = 0; i < 3; i++) {
			if (i == highlight)
				wattron(menuwin, A_REVERSE);
			mvwprintw(menuwin, i + 1, 1, choices[i].c_str());
			wattroff(menuwin, A_REVERSE);
		}
		choice = wgetch(menuwin);
		switch (choice)
		{
		case KEY_UP:
			highlight--;
			if (highlight < 0) {
				highlight = 2;
			}
			break;
		case KEY_DOWN:
			highlight++;
			if (highlight == 3) {
				highlight = 0;
			}
			break;
		default:
			break;
		}
		if (choice == 10) {
			break;
		}
	}
	printw("%s", choices[highlight].c_str());
	getch();
	endwin();
}
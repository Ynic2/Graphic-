#include <iostream>
#include "include/curses.h"
#include <string>
#include <vector>
#include "Functions.h"
#include "Struct.h"

using namespace std;

int main() {
	initscr();
	int xMax;
	func* numbers = new func;
	int size=0;
	xMax = getmaxx(stdscr);
	WINDOW* menu = newwin(9, 13, 1, 1);
	WINDOW* ans = newwin(7, 48, 2, 16);
	WINDOW* ansbox = newwin(9, 50, 1, 15);
	mvwprintw(ans, 3, 19, "Dialog box");
	box(menu, 0, 0);
	box(ansbox, 0, 0);
	wrefresh(ansbox);
	wrefresh(ans);
	keypad(menu, true);
	vector<string> choices(7);
	choices = { "1. Create", "2. Print","3. Delete",
		"4. Resize","5. Read","6. Max","7. Sort" };
	int choice, highlight = 0;
	while (1) {
		while (1) {
			for (int i = 0; i < 7; i++) {
				if (i == highlight)
					wattron(menu, A_REVERSE);
				mvwprintw(menu, i + 1, 1, choices[i].c_str());
				wattroff(menu, A_REVERSE);
			}
			choice = wgetch(menu);
			switch (choice)
			{
			case KEY_UP:
				highlight --;
				if (highlight == -1) {
					highlight = 6;
				}
				wrefresh(menu);
				wrefresh(ansbox);
				break;
			case KEY_DOWN:
				highlight++;
				if (highlight == 7) {
					highlight = 0;
					wrefresh(menu);
					wrefresh(ansbox);
				}
				break;
			default:
				break;
			}
			if (choice == 10) {
				wrefresh(menu);
				wrefresh(ansbox);
				break;
			}
		}
		if (highlight == 0) {
			int count = 1,random;
			create(numbers, random,size,count,ans,menu);
		}
		else if (highlight == 1) {
			print(numbers, size, ans, menu);
		}
		else if (highlight == 2) {
			int delindex = 0;
			Delete(numbers, size,delindex,ans, menu);
		}
		else if (highlight == 3) {
			int newsize=-1;
			resize(numbers, size, ans, newsize, menu);
		}
		else if (highlight == 4) {
			int newindex = -1, newvalue;
			read(numbers, size, newvalue, newindex, ans, menu);
		}
		else if (highlight == 5) {
			int m = -100000000000;
			Maxi(numbers, size, m, ans, menu);
		}
		else if (highlight == 6) {
			int count = 0;
			sort(numbers, count, size);
		}
	}
}
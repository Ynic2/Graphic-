#include <iostream>
#include "include/curses.h"
#include <string>
#include <vector>
#include "Functions.h"
#include "Struct.h"

using namespace std;

int main() {
	initscr();
	bool end = 1;
	func* numbers = new func;
	int size=0;
	WINDOW* menu = newwin(10, 13, 1, 1);
	WINDOW* ans = newwin(8, 48, 2, 16);
	WINDOW* ansbox = newwin(10, 50, 1, 15);
	mvwprintw(ans, 3, 19, "Dialog box");
	box(menu, 0, 0);
	box(ansbox, 0, 0);
	wrefresh(ansbox);
	wrefresh(ans);
	keypad(menu, true);
	vector<string> choices(7);
	choices = { "1. Create", "2. Print","3. Delete",
		"4. Resize","5. Read","6. Max","7. Sort", "8. Exit"};
	int choice, highlight = 0;
	while (end) {
		while (end) {
			for (int i = 0; i < 8; i++) {
				if (i == highlight)
					wattron(menu, A_REVERSE);
				mvwprintw(menu, i + 1, 1, choices[i].c_str());
				wattroff(menu, A_REVERSE);
			}
			choice = wgetch(menu);
			switch (choice)
			{
			case KEY_UP:
				highlight--;
				if (highlight == -1) {
					highlight = 7;
				}
				wrefresh(menu);
				wrefresh(ansbox);
				break;
			case KEY_DOWN:
				highlight++;
				if (highlight == 8) {
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
			int count = 1, random;
			wclear(ans);
			mvwprintw(ans, 1, 1, "Enter the maximum count numbers ");
			box(menu, 0, 0);
			wrefresh(menu);
			wrefresh(ans);
			wscanw(ans, "%d", &size);
			wclear(ans);
			mvwprintw(ans, 1, 1, "Enter the largest number ");
			wrefresh(ans);
			wscanw(ans, "%d", &random);
			wclear(ans);
			mvwprintw(ans, 1, 1, "The array was created successfully");
			wrefresh(ans);
			create(numbers, random, size, count);
		}
		else if (highlight == 1) {
			wclear(ans);
			box(menu, 0, 0);
			wrefresh(menu);
			wrefresh(ans);
			string answer = "";
			print(numbers, size, answer);
			wprintw(ans, "%s", answer.c_str());
			wrefresh(ans);
		}
		else if (highlight == 2) {
			int delindex = 0;
			wclear(ans);
			mvwprintw(ans, 1, 1, "Which element should I delete? ");
			box(menu, 0, 0);
			wrefresh(menu);
			wrefresh(ans);
			wscanw(ans, "%d", &delindex);
			string str = "";
			Delete(numbers, size, delindex, str);
			wclear(ans);
			mvwprintw(ans, 1, 1, "%s", str.c_str());
			wrefresh(ans);
		}
		else if (highlight == 3) {
			int newsize;
			wclear(ans);
			mvwprintw(ans, 1, 1, "Enter new size ");
			box(menu, 0, 0);
			wrefresh(menu);
			wrefresh(ans);
			wscanw(ans, "%d", &newsize);
			wclear(ans);
			mvwprintw(ans, 1, 1, "Dialog box");
			wrefresh(ans);
			resize(numbers, size, newsize);
		}
		else if (highlight == 4) {
			int newindex, newvalue;
			string str;
			wclear(ans);
			mvwprintw(ans, 1, 1, "Enter index should reinput ");
			box(menu, 0, 0);
			wrefresh(menu);
			wrefresh(ans);
			wscanw(ans, "%d", &newindex);
			wclear(ans);
			mvwprintw(ans, 1, 1, "New value ");
			box(menu, 0, 0);
			wrefresh(menu);
			wrefresh(ans);
			wscanw(ans, "%d", &newvalue);
			read(numbers, size, newvalue, newindex, str);
			wclear(ans);
			mvwprintw(ans, 1, 1, "%s", str.c_str());
			wrefresh(ans);
		}
		else if (highlight == 5) {
			int m = -100000000000;
			Maxi(numbers, size, m);
			wclear(ans);
			mvwprintw(ans, 1, 1, "Max value is %d", m);
			box(menu, 0, 0);
			wrefresh(menu);
			wrefresh(ans);
		}
		else if (highlight == 6) {
			int count = 0;
			sort(numbers, count, size);
			wclear(ans);
			mvwprintw(ans, 1, 1, "Sorting was successful");
			wrefresh(ans);
			box(menu, 0, 0);
			wrefresh(menu);
		}
		else if (highlight == 7) {
			vector<string> shure;
			shure = { "Yes", "No" };
			bool stop = 1;
			int highlight1 = 0, input;
			keypad(ans, true);
			wclear(ans);
			mvwprintw(ans, 4, 15, "Are you sure?");
			while (stop) {
				while (stop) {
					for (int i = 0; i < 2; i++) {
						if (highlight1 == i) {
							wattron(ans, A_REVERSE);
						}
						mvwprintw(ans, 5, i * 11 + 15, shure[i].c_str());
						wattroff(ans, A_REVERSE);
					}
					input = wgetch(ans);
					switch (input) {
					case(KEY_LEFT):
						highlight1--;
						if (highlight1 == -1) {
							highlight1 = 1;
						}
						wrefresh(ans);
						break;
					case(KEY_RIGHT):
						highlight1++;
						if (highlight1 == 2) {
							highlight1 = 0;
						}
						wrefresh(ans);
						break;
					default:
						break;
					}
					if (input == 10) {
						wrefresh(ans);
						break;
					}
				}
				if (highlight1 == 0) {
					end = 0;
					stop = 0;
					clear();
					refresh();
				}
				else {
					wclear(ans);
					mvwprintw(ans, 1, 1, "Dialog window");
					wrefresh(ans);
					stop = 0;
				}
			}
		}
	}
}
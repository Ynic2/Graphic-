#include "Functions.h"
#include <string>

void create(func* game, int& random, int& size, int& count, WINDOW* ans, WINDOW* menu)
{
	if (size != 0) {
		game->num = rand() % (random + 1);
		game->index = count;
		if (count + 1 <= size) {
			func* back1 = new func;
			back1 = game;
			func* next1 = new func;
			game->next = next1;
			game->next->back = back1;
		}
		if (count + 1 <= size) {
			count++;
			create(game->next, random, size, count,ans, menu);
		}
	}
	else {
		wclear(ans);
		mvwprintw(ans, 3, 9, "Enter the maximum count numbers");
		box(menu, 0, 0);
		wrefresh(menu);
		wrefresh(ans);
		mvwscanw(ans,5,3,"%d",&size);
		wclear(ans);
		mvwprintw(ans, 3, 13, "Enter the maxmum number");
		wrefresh(ans);
		mvwscanw(ans, 5,3, "%d", &random);
		wclear(ans);
		mvwprintw(ans, 3, 19, "Dialog box");
		wrefresh(ans);
		create(game, random, size, count, ans, menu);
	}
}

void print(func* game, int size,WINDOW* ans, WINDOW* menu)
{
	if (size != 0 && game->index<=size) {
		if (game->index == 1) {
			wclear(ans);
			box(menu, 0, 0);
			wrefresh(menu);
			wrefresh(ans);
		}
			wprintw(ans, "%d", game->num);
		if (game->index < size) {
			wprintw(ans, ",");
		}
		wrefresh(ans);
		if (game->index < size) {
			print(game->next, size, ans, menu);
		}
	}
	else if(size==0) {
		wclear(ans);
		wrefresh(ans);
		mvwprintw(ans, 3, 10, "The array is empty");
		box(menu, 0, 0);
		wrefresh(menu);
		wrefresh(ans);
	}
}

void Delete(func* game, int& size, int& delindex, WINDOW* ans, WINDOW* menu)
{
	if (delindex == 0) {
		wclear(ans);
		mvwprintw(ans, 1, 1, "Which element should I delete?");
		box(menu, 0, 0);
		wrefresh(menu);
		wrefresh(ans);
		mvwscanw(ans, 4, 2, "%d", &delindex);
		wclear(ans);
		mvwprintw(ans, 3, 19, "Dialog box");
		wrefresh(ans);
		Delete(game, size, delindex, ans,menu);
	}
	else {
		if (size < delindex) {
			wclear(ans);
			mvwprintw(ans, 1, 1, "There is no such element");
			box(menu, 0, 0);
			wrefresh(menu);
			wrefresh(ans);
		}
		else if (game->index != delindex) {
			Delete(game->next, size, delindex, ans, menu);
		}
		else if (game->index == delindex) {
			if (game->next != nullptr) {
				game->num = game->next->num;
				game->index = game->next->index;
				game->next = game->next->next;
				wclear(ans);
				mvwprintw(ans, 1, 1, "SUCCEFULL!");
				box(menu, 0, 0);
				wrefresh(menu);
				wrefresh(ans);
			}
			else {
				game = nullptr;
			}
		}
	}
}

void resize(func* game, int& size, WINDOW* ans, int& newsize, WINDOW* menu)
{
	if (newsize<0) {
		wclear(ans);
		mvwprintw(ans, 1, 1, "Enter new size");
		box(menu, 0, 0);
		wrefresh(menu);
		wrefresh(ans);
		mvwscanw(ans, 4, 2, "%d", &newsize);
		wclear(ans);
		mvwprintw(ans, 3, 19, "Dialog box");
		wrefresh(ans);
		resize(game, size, ans, newsize, menu);
	}
	else {
		if (newsize < size) {
			if (game->index < newsize) {
				resize(game->next, size, ans, newsize, menu);
			}
			else {
				game->next = nullptr;
				size = newsize;
			}
		}
		else {
			if (game->next != nullptr) {
				resize(game->next, size, ans, newsize, menu);
			}
			else {
				if (size < newsize) {
					size++;
					func* next1 = new func;
					next1->index = size;
					next1->back = game;
					game->next = next1;
					resize(game->next, size, ans, newsize, menu);
				}
			}
		}
	}
}

void read(func* game, int& size, int& newvalue,int& newindex, WINDOW* ans, WINDOW* menu)
{
	if (newindex==-1){
		wclear(ans);
		mvwprintw(ans, 1, 1, "Enter index should reinput");
		box(menu, 0, 0);
		wrefresh(menu);
		wrefresh(ans);
		mvwscanw(ans, 4, 2, "%d", &newindex);
		wclear(ans);
		mvwprintw(ans, 1, 1, "New value");
		box(menu, 0, 0);
		wrefresh(menu);
		wrefresh(ans);
		mvwscanw(ans, 4, 2, "%d", &newvalue);
		wclear(ans);
		mvwprintw(ans, 3, 19, "Dialog box");
		wrefresh(ans);
		read(game, size, newvalue, newindex, ans, menu);
	}
	else {
		if (newindex > size) {
			wclear(ans);
			mvwprintw(ans, 1, 1, "ERROR: BIG INDEX");
			box(menu, 0, 0);
			wrefresh(menu);
			wrefresh(ans);
		}
		else {
			if (newindex != game->index) {
				read(game->next, size, newvalue, newindex, ans, menu);
			}
			else {
				game->num = newvalue;
			}
		}
	}
}

void Maxi(func* game, int size, int& m, WINDOW* ans, WINDOW* menu)
{
	if (game->num > m) {
		m = game->num;
	}
	if (game->index<size){
		Maxi(game->next, size, m, ans, menu);
	}
	wclear(ans);
	mvwprintw(ans, 1, 1, "Max value is %d", m);
	box(menu, 0, 0);
	wrefresh(menu);
	wrefresh(ans);
}

void sort(func* game,int& count, int size)
{
	if (count+1 < size) {
		if ((game->num) > (game->next->num)) {
			int a = game->num;
			game->num = game->next->num;
			game->next->num = a;
			if (count != 0) {
				count--;
				sort(game->back, count, size);
			}
		}
	}
	count++;
	if (count < size) {
		sort(game->next, count, size);
	}
}

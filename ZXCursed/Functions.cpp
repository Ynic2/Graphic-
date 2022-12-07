#include "Functions.h"
#include <string>
#include <sstream>
#include <stdlib.h>


void create(func* game, int& random, int& size, int& count)
{
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
			create(game->next, random, size, count);
		}
	
}

void print(func* game, int size, string& str)
{
	if (size == 0) {
		str = "The array is empy";

	}
	if (size != 0 && game->index <= size) {
		char* ss = new char[1000];
		itoa(game->num, ss, 10);
		str += ss;
		if (size!=game->index) {
			str.push_back(',');
			print(game->next, size, str);
		}
	}
}

void Delete(func* game, int& size, int& delindex, string& ans)
{
		if (size < delindex) {
			ans = "There is no such element";
		}
		else if (game->index != delindex) {
			Delete(game->next, size, delindex, ans);
		}
		else if (game->index == delindex) {
			if (game->next != nullptr) {
				game->num = game->next->num;
				game->next = game->next->next;
				size -= 1;
				ans = "The deletion was successful";
			}
			else {
				game = nullptr;
				size -= 1;
			}
		}
}

void resize(func* game, int& size, int& newsize)
{
		if (newsize < size) {
			if (game->index < newsize) {
				resize(game->next, size, newsize);
			}
			else {
				game->next = nullptr;
				size = newsize;
			}
		}
		else {
			if (game->next != nullptr) {
				resize(game->next, size, newsize);
			}
			else {
				if (size < newsize) {
					size++;
					func* next1 = new func;
					next1->index = size;
					next1->back = game;
					game->next = next1;
					resize(game->next, size, newsize);
				}
			}
		}
}

void read(func* game, int& size, int& newvalue,int& newindex, string& ans)
{
		if (newindex > size) {
			ans = "ERROR: There is no such position";
		}
		else {
			if (newindex != game->index) {
				read(game->next, size, newvalue, newindex, ans);
			}
			else {
				game->num = newvalue;
			}
		}
}

void Maxi(func* game, int size, int& m)
{
	if (game->num > m) {
		m = game->num;
	}
	if (game->index < size) {
		Maxi(game->next, size, m);
	}

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

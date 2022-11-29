#pragma once
#include <iostream>
#include "Struct.h"
#include "include/curses.h"
#include <string>

using namespace std;

void create(func* game, int& random, int& size, int& count, WINDOW* ans, WINDOW* menu);

void print(func* game, int size, WINDOW* ans,WINDOW* menu);

void Delete(func* game, int& size, int& delindex, WINDOW* ans, WINDOW* menu);

void resize(func* game, int& size, WINDOW* ans, int& newsize, WINDOW* menu);

void read(func* game, int& size,int& newvalue, int& newindex, WINDOW* ans, WINDOW* menu);

void Maxi(func* game, int size, int& m, WINDOW* ans, WINDOW* menu);

void sort(func* game,int& count, int size);
#pragma once
#include <iostream>
#include "Struct.h"
#include "include/curses.h"
#include <string>

using namespace std;

void create(func* game, int& random, int& size, int& count);

void print(func* game, int size, string& str);

void Delete(func* game, int& size, int& delindex, string& ans);

void resize(func* game, int& size, int& newsize);

void read(func* game, int& size,int& newvalue, int& newindex, string& ans);

void Maxi(func* game, int size, int& m);

void sort(func* game,int& count, int size);
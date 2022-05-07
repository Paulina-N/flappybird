#pragma once
#include <iostream>
#include <Windows.h>

using namespace std;

class Background {
private:
	COORD coordinates = {};
public:
	void position(short x, short y);
	void drawBorders();
	void drawObstacle(int x, int move, int r);
	void removeObstacle(int x, int move, int r);
	int hit(int y, int r);
	void instructions(int x, int y);
};
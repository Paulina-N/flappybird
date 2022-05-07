#pragma once
#include <iostream>
#include "bird.h"
#include "background.h"

using namespace std;

class Game : Background {
private:
	Bird bird;
	int attempts = 1, score = 0, high_score = 0;
	int random = 1, r1 = 1, r2 = 1, r3 = 1, i = 24, first = 2, second = 2, third = 2;
public:
	Game(string name);
	int generateNumber();
	void countScore();
	void countScore(int prevscore);
	void gameOver();
};
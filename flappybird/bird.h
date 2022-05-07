#pragma once
#include "background.h"

using namespace std;

class Bird : Background {
private:
	char bird_body = 'O';
public:
	void drawBird(int x, int y);
	void removeBird(int x, int y);
};

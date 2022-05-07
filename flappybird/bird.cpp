#include <iostream>
#include "bird.h"

using namespace std;

void Bird::drawBird(int x, int y) {
	bird_body = 'O';
	position(x, y);
	cout << bird_body;
}

void Bird::removeBird(int x, int y) {
	bird_body = ' ';
	position(x, y);
	cout << bird_body;
}
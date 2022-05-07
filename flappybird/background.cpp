#include <iostream>
#include "background.h"
#include <ctime>

#define SCREEN_WIDTH 112
#define SCREEN_HEIGTH 25
#define WINDOW_START 2
#define GAP 6
#define OBSTACLE 108

using namespace std;

void Background::position(short x, short y) {
	coordinates = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

void Background::drawBorders() {
	for (int i = WINDOW_START; i < SCREEN_WIDTH; i++) {
		position(i, WINDOW_START);
		cout << "-";
		position(i, SCREEN_HEIGTH - 1);
		cout << "-";
	}
	for (int i = WINDOW_START; i < SCREEN_HEIGTH; i++) {
		position(0, i);
		cout << "|";
		position(SCREEN_WIDTH, i);
		cout << "|";
	}
}

void Background::drawObstacle(int x, int move, int r) {
	for (int i = WINDOW_START + 1; i < r + WINDOW_START; i++) {
		position(OBSTACLE + x - move, i);
		cout << "##";
	}

	for (int i = WINDOW_START + r + GAP; i < SCREEN_HEIGTH - 1; i++) {
		position(OBSTACLE + x - move, i);
		cout << "##";
	}
}

void Background::removeObstacle(int x, int move, int r) {
	for (int i = WINDOW_START + 1; i < r + WINDOW_START; i++) {
		position(OBSTACLE + x - move, i);
		cout << "  ";
	}

	for (int i = WINDOW_START + r + GAP; i < SCREEN_HEIGTH - 1; i++) {
		position(OBSTACLE + x - move, i);
		cout << "  ";
	}
}

int Background::hit(int y, int r) {
	if ((y < WINDOW_START + r) || (y > WINDOW_START + r + GAP))
		return 1;
	return 0;
}

void Background::instructions(int x, int y) {
	position(x, y);
	cout << "INSTRUCTIONS:" << endl;
	cout << "Press SPACE BAR to make the bird fly." << endl;
	cout << "Press ESC to exit the game.";
}
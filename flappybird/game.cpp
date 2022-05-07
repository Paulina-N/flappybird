#include <iostream>
#include <conio.h>
#include "game.h"

#define BIRD_POS_X 26
#define BIRD_POS_Y 12
#define GROUND_Y 24
#define CEILING_Y 2

using namespace std;

Game::Game(string name) {
	i = GROUND_Y;
	while (true) {
		if ((i == GROUND_Y) || (i == CEILING_Y)) {
			system("cls");
			instructions(0, 25);
			position(55, 0);
			cout << name;
			position(40, 1);
			countScore(score);
			score = 0;
			cout << "Attempts: " << attempts << "  Score: " << score << "  High Score: " << high_score;
			drawBorders();
			bird.drawBird(BIRD_POS_X, 12);
			r1 = generateNumber();
			r2 = generateNumber();
			r3 = generateNumber();
			first = 2;
			second = 2;
			third = 2;
			i = BIRD_POS_Y;
			attempts++;
		}

		Sleep(160);
		if (first < 108) {
			drawObstacle(0, first, r1);
			removeObstacle(0, first - 2, r1);
			if (first == 82) {
				if (hit(i, r1) == 1) {
					i = GROUND_Y;
					continue;
				}
				else countScore();
			}
		}
		else {
			removeObstacle(0, 106, r1);
			first = 0;
			r1 = generateNumber();
		}
		if ((second > 36) && (second < 144)) {
			drawObstacle(36, second, r2);
			removeObstacle(36, second - 2, r2);
			if (second == 118) {
				if (hit(i, r2) == 1) {
					i = GROUND_Y;
					continue;
				}
				else countScore();
			}
		}
		else if (second >= 143) {
			removeObstacle(0, 106, r2);
			second = 36;
			r2 = generateNumber();
		}
		if ((third > 72) && (third < 180)) {
			drawObstacle(72, third, r3);
			removeObstacle(72, third - 2, r3);
			if (third == 154) {
				if (hit(i, r3) == 1) {
					i = GROUND_Y;
					continue;
				}
				else countScore();
			}
		}
		else if (third >= 180) {
			removeObstacle(0, 106, r3);
			third = 72;
			r3 = generateNumber();
		}
		first += 2;
		second += 2;
		third += 2;

		bird.removeBird(BIRD_POS_X, i);
		i++;
		bird.drawBird(BIRD_POS_X, i);
			
		if (_kbhit()) {
			char ch = _getch();
			if (ch == 32) {
				bird.removeBird(BIRD_POS_X, i);
				i -= 2;
				bird.drawBird(BIRD_POS_X, i);
			}
			else if (ch == 27) {
				gameOver();
				break;
			}
		}
	}
}

int Game::generateNumber() {
	random = (rand() % 10) + 1;
	return random;
}

void Game::countScore() {
	score++;
	position(60, 1);
	cout << score;
}

void Game::countScore(int prevscore) {
	if (prevscore > high_score) high_score = prevscore;
}

void Game::gameOver() {
	system("cls");
	position(50, 0);
	cout << "GAME OVER";
	position(45, 1);
	countScore(score);
	cout << "Your high score is " << high_score;
}
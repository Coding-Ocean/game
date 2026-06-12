#pragma once
#include"circle.h"
struct DATA {
	int TITLE = 0, PLAY = 1, OVER = 2, state = TITLE;
	struct CIRCLE enemy;
	struct CIRCLE player;
};
void title(struct DATA* d);
void play(struct DATA* d);
void over(struct DATA* d);
int collision(struct DATA* c);
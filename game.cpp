#include"libOne.h"
#include"game.h"
void init(struct DATA* d) {
	d->enemy.px = width / 2;
	d->enemy.py = 100;
	d->enemy.vx = 5;
	d->enemy.vy = 5;
	d->enemy.radius = 200;
	d->player.px = 0;
	d->player.py = 0;
	d->player.radius = 200;
	d->enemy.maxSize = 450;
}
void title(struct DATA* d) {
	//画像切り替え
		init(d);
	if (isTrigger(MOUSE_LBUTTON)) {
		d->state = d->PLAY;
	}
}

void play(struct DATA* d) {
	background(255, 200, 255);
	d->player.px = mouseX;
	d->player.py = mouseY;
	d->enemy.px += d->enemy.vx;
	d->enemy.py += d->enemy.vy;
	if (d->enemy.px > width - d->enemy.radius / 2) {
		d->enemy.px = width - d->enemy.radius / 2;
		d->enemy.vx *= -1;
	}
	if (d->enemy.px < 0 + d->enemy.radius / 2) {
		d->enemy.px = 0 + d->enemy.radius / 2;
		d->enemy.vx *= -1;
	}
	if (d->enemy.py > height - d->enemy.radius / 2) {
		d->enemy.py = height - d->enemy.radius / 2;
		d->enemy.vy *= -1;
	}
	if (d->enemy.py < 0 + d->enemy.radius / 2) {
		d->enemy.py = 0 + d->enemy.radius / 2;
		d->enemy.vy *= -1;
	}
	if (d->enemy.radius <= d->enemy.maxSize) {
		d->enemy.radius += 0.05f;
	}
	else {
		if (d->enemy.vx < 0) {
			d->enemy.vx -= 0.001f;
		}
		if (d->enemy.vx > 0) {
			d->enemy.vx += 0.001f;
		}
		if (d->enemy.vy < 0) {
			d->enemy.vy -= 0.001f;
		}
		if (d->enemy.vy > 0) {
			d->enemy.vy += 0.001f;
		}
	}
	if (collision(d)) {
		d->state = d->OVER;
	}

}
void over(struct DATA* d) {
	if (isTrigger(MOUSE_LBUTTON)) {
		d->state = d->TITLE;
	}
}
int collision(struct DATA* c) {
	float x, y, sqz;
	float e, sqd;
	x = c->player.px - c->enemy.px;
	y = c->enemy.py - c->player.py;
	sqz = x * x + y * y;
	e = c->enemy.radius / 2 + c->player.radius / 2;
	sqd = e * e;
	if (sqz <= sqd) {
		return 1;
	}
	else {
		return 0;
	}
}
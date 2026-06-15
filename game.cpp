#include"libOne.h"
#include"game.h"
#include <cmath>
void init(struct DATA* d) {
	d->enemy.px = 0;
	d->enemy.py = height/2;
	d->enemy.vx = 8;
	d->enemy.vy = 8;
	d->enemy.radius = 200;
	//発射角度
	float angle = random(360);
	d->enemy.vx = cos(angle) * 8;
	d->enemy.vy = sin(angle) * 8;
	//ENEMYの最大の大きさ
	d->enemy.maxSize = 500;


	d->player.px = 0;
	d->player.py = 0;
	d->player.radius = 300;

	//生き残った時間
	d->time = 0;
}
void title(struct DATA* d) {
	//画像切り替え
	if (isTrigger(MOUSE_LBUTTON)) {
		init(d);
		d->state = d->PLAY;
	}
}

void play(struct DATA* d) {
	background(255, 200, 255);
	//時間の測定
	d->time += delta;
	//プレイヤーの動作
	d->player.px = mouseX;
	d->player.py = mouseY;
	//ENEMYの動作
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

	//サイズの変化
	if (d->enemy.radius < d->enemy.maxSize) { d->enemy.radius += 0.1f; }

	//速度の変化
	if (d->enemy.vx > 0) { d->enemy.vx += 0.005f; }
	else                 { d->enemy.vx -= 0.005f; }
	if (d->enemy.vy > 0) { d->enemy.vy += 0.005f; }
	else                 { d->enemy.vy -= 0.005f; }
	
	
	if (collision(d)) { d->state = d->OVER; }

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
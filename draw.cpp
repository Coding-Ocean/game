#include"libOne.h"
#include"game.h"
void draw(struct DATA* d) {
	background(255, 200, 255);
	if (d->state == d->TITLE) {
		print("title");
		circle(d->enemy.px, d->enemy.py, d->enemy.radius);
	}
	else if (d->state == d->PLAY) {
		print("play");
		fill(255, 200, 0);
		circle(d->enemy.px, d->enemy.py, d->enemy.radius);
		circle(d->player.px, d->player.py, d->player.radius);
	}
	else {
		print("game over");
		fill(255, 0, 0);
		circle(d->enemy.px, d->enemy.py, d->enemy.radius);
		circle(d->player.px, d->player.py, d->player.radius);
	}
	fill(0, 200, 255);
	print((let)"w:" + width + " h:" + height);
	print((let)"x:" + (int)mouseX + " y:" + (int)mouseY);
	print((let)"delta:" + delta);
}

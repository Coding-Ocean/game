#include"libOne.h"
#include"game.h"
void draw(struct DATA* d) {
	background(255, 200, 255);
	if (d->state == d->TITLE) {
		fill(255, 200, 0);
		print("TITLE");
	}
	else if (d->state == d->PLAY) {
		fill(255, 200, 0);
		print("PLAY");

		circle(d->enemy.px, d->enemy.py, d->enemy.radius);
		circle(d->player.px, d->player.py, d->player.radius);
	}
	else {
		fill(255, 0, 0);
		print("GAME OVER");
		print((let)"¶‚«c‚Á‚½ŠÔ" + d->time);
		circle(d->enemy.px, d->enemy.py, d->enemy.radius);
		circle(d->player.px, d->player.py, d->player.radius);
	}
}

#include"libOne.h"
#include"game.h"
#include"draw.h"
void gmain()
{
	window(1920, 1080, full);
	struct DATA d;
	repeat()
	{
		if (d.state == d.TITLE) { title(&d); }
		else if (d.state == d.PLAY) { play(&d); }
		else { over(&d); }
		draw(&d);
	}
}
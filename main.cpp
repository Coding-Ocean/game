#include"libOne.h"
void gmain()
{
	window(432, 768);
	int img = loadImage("assets\\unkoWhite.png");
	int snd = loadSound("assets\\pa.wav");
	float px = width / 2 - 50;
	float py = -500;
	float vy = 10;
	while (notQuit)
	{
		py += vy;
		if(py > height) {
			py = -100;
			playSound(snd);
		}

		clear(60, 120, 240);
		imageColor(120, 60, 0);
		image(img, px, py);
	}
}
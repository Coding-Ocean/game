#include"libOne.h"

void gmain()
{
	window(1920, 1080, full);
	
	repeat()
	{
		background(0, 0, 0);

		//info
		print((let)"width:" + width + " height:" + height);
		print((let)"mouseX:" + (int)mouseX + " mouseY:" + (int)mouseY);
		print((let)"delta:" + delta);
	}
}
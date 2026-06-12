#include"libOne.h"

void gmain()
{
	//windowをつくる
	window(1920, 1080, full);
	//ゲームループ
	repeat()
	{
		//背景描画
		background(0, 0, 0);
		//情報描画
		print_f("width:%.f height:%.f", width, height);
		print_f("mouseX:%.f mouseY:%.f", mouseX, mouseY);
		print_f("delta:%.3f", delta);
	}
}
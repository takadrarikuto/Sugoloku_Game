#include "DxLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	ChangeWindowMode(TRUE);
	DxLib_Init();
	SetGraphMode(800, 600, 32); //window�T�C�Y800*600 32bit
	SetDrawScreen(DX_SCREEN_BACK);


	int back_img1 = LoadGraph("image\\�w�i�e�X�g�p.png");
	DrawGraph(0, 0, back_img1, TRUE);


	ScreenFlip();

	WaitKey();

	DxLib_End();
	return 0;
}
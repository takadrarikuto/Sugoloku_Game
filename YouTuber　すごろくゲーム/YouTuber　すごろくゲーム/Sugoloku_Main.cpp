#pragma once
#include "DxLib.h"
#include "Header.h"

int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	//ポート用変数
	int Sendport, RecvPort; //send送る Recv受ける

	//送受信データ処理用
	char StrBuf[256] = { "NULL" };

	//windowの設定
	ChangeWindowMode(TRUE); //windowモード
	SetGraphMode(800, 600, 32); //windowサイズ640*480 32bit
	SetAlwaysRunFlag(TRUE); //バックグラウンドでも実行出来るようにする
	SetDoubleStartValidFlag(TRUE); //多重起動の許可

	//初期化
	if (DxLib_Init() == -1)return -1; //エラーが出たら終了

	//バックバッファを使う設定
	SetDrawScreen(DX_SCREEN_BACK);

	//画像読み込み
	int image = LoadGraph("image\\Frisk.png");

	//画像の位置情報
	float x, y;
	//画像の移動距離情報
	float vx, vy;
	//初期化 
	x = 0.0f;
	y = 536.0f;
	vx = 0.0f;
	vy = 0.0f;
	//向きフラグ
	bool LR_flg = 0;
	//前進フラグ
	bool Forward_flg = false;

	//アニメーション用カウント
	int anim_cnt = 0;
	//切り取り位置
	int rect_x = 0;

	while (CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		//Enterで前進フラグをtrue、移動距離を設定
		if (CheckHitKey(KEY_INPUT_RETURN) && Forward_flg == false)
		{
			Forward_flg = true;
			vx = x + 64;
			/*vx = -64;*/
		}
		
		//設定した移動距離までに移動
		if (vx != x)
		{
			x += 2.0f;
		}
		/*if (vx < 0)
		{
			x += 2.0f;
			vx += 2.0f;
		}*/
		//設定した移動距離に到着すると停止(Enterを押しっぱなしによる連続移動を止める処理付き)
		else if (vx == x && CheckHitKey(KEY_INPUT_RETURN) == false)
		{
			Forward_flg = false;
		}
		//右
		if (CheckHitKey(KEY_INPUT_RIGHT)) {
			x += 2.0f;
			if (x > 800 - 64) x = 800 - 64; //画面端の判定
			LR_flg = 1;
		}
		//左
		else if (CheckHitKey(KEY_INPUT_LEFT)) {
			x -= 2.0f;
			if (x < 0)x = 0;  //画面端の判定
			LR_flg = 0;
		}
		//上
		else if (CheckHitKey(KEY_INPUT_UP)) {
			y -= 2.0f;
			if (y < 0)y = 0;  //画面端の判定
		}
		//下
		else if (CheckHitKey(KEY_INPUT_DOWN)) {
			y += 2.0f;
			if (y > 600 - 64)y = 600 - 64;  //画面端の判定
		}
		else {
			anim_cnt = 0;
			rect_x = 0;
		}
		

		ClearDrawScreen(); //画像クリア
		//描画処理
		DrawRectGraphF(
			x, y,  //描画位置
			rect_x, 0, //切り取り開始位置
			64, 64, //切り取るサイズ
			image,  //切り取る元画像
			TRUE, //透過処理フラグ
			LR_flg //反転処理フラグ
		);

		ScreenFlip(); //バックバッファと切り替え

		//例外が発生したらプログラム終了
		if (ProcessMessage() == -1) break;
	}

	DxLib_End(); //dxライブラリ終了処理


	return 0;
}
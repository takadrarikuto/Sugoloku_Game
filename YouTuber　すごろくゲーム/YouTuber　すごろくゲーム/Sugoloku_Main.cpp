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
	//画像の移動ベクトル最大値
	float vx_max, vy_max;
	//初期化 
	x = 0.0f;
	y = 536.0f;
	vx = 0.0f;
	vy = 0.0f;
	vx_max = 0.0f;
	vy_max = 0.0f;
	//左右向きフラグ
	bool LR_flg = 1;
	//上下向きフラグ
	bool UD_flg = 0;
	//進行方向管理変数
	int Direction_of_Travel_num = 0; //0:右 1:左 2:上 3:下
	//前進フラグ
	bool Forward_flg = false;

	//アニメーション用カウント
	int anim_cnt = 0;
	//切り取り位置
	int rect_x = 0;

	while (CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		//方向設定
		//右
		if (CheckHitKey(KEY_INPUT_RIGHT)) {
			LR_flg = 1;
			Direction_of_Travel_num = 0;
		}
		//左
		else if (CheckHitKey(KEY_INPUT_LEFT)) {
			LR_flg = 0;
			Direction_of_Travel_num = 1;
		}
		//上
		else if (CheckHitKey(KEY_INPUT_UP)) {
			UD_flg = 1;
			Direction_of_Travel_num = 2;
		}
		//下
		else if (CheckHitKey(KEY_INPUT_DOWN)) {
			UD_flg = 0;
			Direction_of_Travel_num = 3;
		}

		//Enterで前進フラグをtrue、1P移動距離を設定
		if (CheckHitKey(KEY_INPUT_RETURN) && Forward_flg == false)
		{
			if (Direction_of_Travel_num == 0)
			{
				vx = x + 64; //右
				vx_max = 2.0f;
			}
			else if (Direction_of_Travel_num == 1)
			{
				vx = x - 64;//左
				vx_max = -2.0f;
			}
			else if (Direction_of_Travel_num == 2)
			{
				vy = y - 64;//上
				vy_max = -2.0f;
			}
			else if (Direction_of_Travel_num == 3)
			{
				vy = y + 64;//下
				vy_max = 2.0f;
			}
			Forward_flg = true;
		}
		
		//設定した移動距離までに移動
		//左右
		if (vx != x)
		{
			x += vx_max;
		}
		//上下
		else if (vy != y)
		{
			y += vy_max;
		}	
		//設定した移動距離に到着すると停止(Enterを押しっぱなしによる連続移動を止める処理付き)
		if (CheckHitKey(KEY_INPUT_RETURN) == false)
		{
			//初期化 
			if (vx == x)
			{
				vx_max = 0.0f;
			}
			else if (vy == y)
			{
				vy_max = 0.0f;
			}
			Forward_flg = false;
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
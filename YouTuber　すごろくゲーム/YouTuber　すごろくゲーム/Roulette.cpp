#pragma once
#include "DxLib.h"
#include "Header.h"
#define RECR_MAX 200

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
	int Rou_image = LoadGraph("image\\スロット.png");

	//画像の位置情報
	float Rou_x, Rou_y;
	//初期化 
	Rou_x = 300.0f;
	Rou_y = 200.0f;
	//左右向きフラグ
	bool Rou_LR_flg = 0;
	//ボタン確認(ルーレット用)
	bool Roulette_Enter_Bottan = false;
	//ルーレット回転
	bool Roulette_Rotation = false;
	//ルーレット進展
	int Roulette = 0;

	//切り取り位置
	int Rou_rect_x = 0;
	int Rou_rect_y = 0;

	while (CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		//ルーレット処理
		//Enterでルーレット回転スタート
		if (CheckHitKey(KEY_INPUT_RETURN) == true && Roulette_Enter_Bottan == false)
		{			
			if (Roulette == 0)
			{			
				//ルーレット回転開始
				Roulette_Rotation = true;				
				Roulette = 1;
			}
			else if (Roulette == 1)
			{				
				//初期化
				Roulette_Rotation = false;
				Roulette = 0;				
			}				
			Roulette_Enter_Bottan = true;
		}
		else if (CheckHitKey(KEY_INPUT_RETURN) == false)
		{
			Roulette_Enter_Bottan = false;
		}

		//ルーレット回転処理
		if (Roulette_Rotation == true)
		{			
			if (Rou_rect_x < 400) {
				Rou_rect_x += 200;
			}
			else {
				Rou_rect_x = 0; //初期化
				if (Rou_rect_y < 200) {
					Rou_rect_y = 200;
				}
				else {
					Rou_rect_y = 0; //初期化
				}
			}
		}

		ClearDrawScreen(); //画像クリア
		//描画処理
		DrawRectGraphF(
			Rou_x, Rou_y,  //描画位置
			Rou_rect_x, Rou_rect_y, //切り取り開始位置
			RECR_MAX, RECR_MAX, //切り取るサイズ
			Rou_image,  //切り取る元画像
			TRUE, //透過処理フラグ
			Rou_LR_flg //反転処理フラグ
		);

		ScreenFlip(); //バックバッファと切り替え

		//例外が発生したらプログラム終了
		if (ProcessMessage() == -1) break;
	}

	DxLib_End(); //dxライブラリ終了処理


	return 0;
}
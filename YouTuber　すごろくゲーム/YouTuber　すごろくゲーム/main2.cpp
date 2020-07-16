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
	SetOutApplicationLogValidFlag(FALSE); //Log.txtを生成しないように設定
	SetAlwaysRunFlag(TRUE); //バックグラウンドでも実行出来るようにする
	SetDoubleStartValidFlag(TRUE); //多重起動の許可
	
	//初期化
	if (DxLib_Init() == -1)return -1; //エラーが出たら終了

	//バックバッファを使う設定
	SetDrawScreen(DX_SCREEN_BACK);

	//画像読み込み
	int image = LoadGraph("image\\pic.png");

	//画像の位置情報
	float x, y;
	//初期化 
	x = 0.0f;
	y = 536.0f;
	//向きフラグ
	bool LR_flg = 0;
	//ジャンプフラグ
	bool Ja_flg = 0;

	//アニメーション用カウント
	int anim_cnt = 0;
	//切り取り位置
	int rect_x = 0;	

	while (CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		
		//右
		if (CheckHitKey(KEY_INPUT_RIGHT)) {
			x += 2.0f;
			if (x > 800 - 64) x = 800 - 64; //画面端の判定
			anim_cnt += 8;
			if (anim_cnt % 64 == 0)rect_x = 192 + anim_cnt;
			if (anim_cnt == 128)anim_cnt = 0;
			LR_flg = 0;
		}
		//左
		else if (CheckHitKey(KEY_INPUT_LEFT)) {
			x -= 2.0f;
			if (x < 0)x = 0;  //画面端の判定
			if (anim_cnt % 64 == 0)rect_x = 192 + anim_cnt;
			anim_cnt += 8;
			if (anim_cnt == 128)anim_cnt = 0;
			LR_flg = 1;
		}
		else {
			anim_cnt = 0;
			rect_x = 0;
			Ja_flg = 0;
		}
		//ジャンプ
		if (CheckHitKey(KEY_INPUT_UP)) {						
			if (Ja_flg == 0)y -= 4.0f;	
			if (y < 0)y = 0;
			Ja_flg = 1;
			rect_x = 390;
		}
			
		//自由落下処理
		if (y < 600 - 64 && Ja_flg == 0){
			y += 4.0f;
			rect_x = 390;		
		}

		ClearDrawScreen(); //画像クリア
		//描画処理
		DrawRectGraphF(
			x, y,  //描画位置
			rect_x,0, //切り取り開始位置
			64,64, //切り取るサイズ
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
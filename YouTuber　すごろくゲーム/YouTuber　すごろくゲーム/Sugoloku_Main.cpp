#pragma once
#include "DxLib.h"
#include "Header.h"

#include <time.h>

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
	SetGraphMode(800, 600, 32); //windowサイズ800*600 32bit
	SetAlwaysRunFlag(TRUE); //バックグラウンドでも実行出来るようにする
	SetDoubleStartValidFlag(TRUE); //多重起動の許可

	//初期化
	if (DxLib_Init() == -1)return -1; //エラーが出たら終了

	//SetBackgroundColor(0, 255, 255);
	if (DxLib_Init() < 0) return -1;

	//バックバッファを使う設定
	SetDrawScreen(DX_SCREEN_BACK);

	//LoadGraphScreen(0, 0, "背景テスト用.png", TRUE);

	//画像読み込み
	int image = LoadGraph("image\\Frisk.png");
	int back_img1 = LoadGraph("image\\背景テスト用.png");
	int Rou_image = LoadGraph("image\\スロット.png");
	DrawGraph(0, 0, back_img1, TRUE);

	//プレイヤー
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

		//アニメーション用カウント
		int anim_cnt = 0;
		//切り取り位置
		int rect_x = 0;
		int rect_y = 0;

	//ルーレット
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
		//ルーレット回転・停止
		int Roulette = 0;		

		//切り取り位置
		int Rou_rect_x = 0;
		int Rou_rect_y = 0;

	//共有
		//主人公移動開始フラグ
		bool PlayerMove_Flg = false;
		//主人公移動回数
		int PlayerMove_num = 0;

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
				PlayerMove_num = 0; //初期化
				Roulette = 1;
			}
			else if (Roulette == 1)
			{				
				//ルーレット停止
				PlayerMove_Flg = true; //主人公移動開始
				Roulette_Rotation = false; //初期化
				Roulette = 0; //初期化
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
			//画像切り取り位置変更処理
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

		//移動距離調整処理
		if (Rou_rect_y < 200)
		{
			if (Rou_rect_x == 0){
				PlayerMove_num = 1;
			}
			else if (Rou_rect_x == 200){
				PlayerMove_num = 2;
			}
			else if (Rou_rect_x == 400){
				PlayerMove_num = 3;
			}
		}
		else if (Rou_rect_y == 200)
		{
			if (Rou_rect_x == 0) {
				PlayerMove_num = 4;
			}
			else if (Rou_rect_x == 200){
				PlayerMove_num = 5;
			}
			else if (Rou_rect_x == 400){
				PlayerMove_num = 6;
			}
		}

		//移動方向設定
		//右
		if (Direction_of_Travel_num == 0) {
			LR_flg = 1;			
		}
		//左
		else if (Direction_of_Travel_num == 1) {
			LR_flg = 0;			
		}
		//上
		else if (Direction_of_Travel_num == 2) {
			UD_flg = 1;			
		}
		//下
		else if (Direction_of_Travel_num == 3) {
			UD_flg = 0;			
		}

		//Enterで前進フラグをtrue、1P移動距離を設定
		if (PlayerMove_Flg == true)
		{
			if (Direction_of_Travel_num == 0)
			{
				vx = x + (64 * PlayerMove_num); //右
				vx_max = 2.0f;
			}
			else if (Direction_of_Travel_num == 1)
			{
				vx = x - (64 * PlayerMove_num);//左
				vx_max = -2.0f;
			}
			else if (Direction_of_Travel_num == 2)
			{
				vy = y - (64 * PlayerMove_num);//上
				vy_max = -2.0f;
			}
			else if (Direction_of_Travel_num == 3)
			{
				vy = y + (64 * PlayerMove_num);//下
				vy_max = 2.0f;
			}
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
		if (PlayerMove_Flg == true)
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
			PlayerMove_Flg = false;
			Direction_of_Travel_num = 0;
		}
		
		ClearDrawScreen(); //画像クリア
		//プレイヤー描画処理
		DrawRectGraphF(
			x, y,  //描画位置
			rect_x, rect_y, //切り取り開始位置
			64, 64, //切り取るサイズ
			image,  //切り取る元画像
			TRUE, //透過処理フラグ
			LR_flg //反転処理フラグ
		);

		//ルーレット描画処理
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
#pragma once
#include "DxLib.h"
#include "Header.h"

#define MAP_SIZE	50 //マップチップ一つのドットサイズ
#define MAP_WIDTH	16 //マップの幅
#define MAP_HEIGHT	12 //マップの縦長さ

// マップのデータ(16マス×12マス)(0 = 描画マス、1 = 壁)
int MapData[MAP_HEIGHT][MAP_WIDTH] =
{
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 } ,
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 } ,
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1 } ,
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1 } ,
	{ 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1 } ,
	{ 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1 } ,
	{ 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1 } ,
	{ 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1 } ,
	{ 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1 } ,
	{ 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1 } ,
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 } ,
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 } ,
};

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
	if (DxLib_Init() == -1)return -1; //エラーが出たら終

	SetBackgroundColor(0, 100, 0);
	if (DxLib_Init() < 0) return -1;

	//バックバッファを使う設定
	SetDrawScreen(DX_SCREEN_BACK);

	//画像読み込み
	int image = LoadGraph("image\\Frisk.png");
	int back_img1 = LoadGraph("image\\背景テスト用.png");
	int squares_img1 = LoadGraph("image\\マス.png");

	int i, j;

	//画像の位置情報
	float x, y;
	//画像の移動距離情報
	float vx, vy;
	//画像の移動ベクトル最大値
	float vx_max, vy_max;
	//初期化 
	x = 50.0f;
	y = 5.0f;
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
	int rect_y = 0;

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
				vx = x + 50; //右
				vx_max = 2.0f;
			}
			else if (Direction_of_Travel_num == 1)
			{
				vx = x - 50;//左
				vx_max = -2.0f;
			}
			else if (Direction_of_Travel_num == 2)
			{
				vy = y - 50;//上
				vy_max = -2.0f;
			}
			else if (Direction_of_Travel_num == 3)
			{
				vy = y + 50;//下
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

		//マップを描く
		for (i = 0; i < MAP_HEIGHT; i++)
		{
			for (j = 0; j < MAP_WIDTH; j++)
			{
				if (MapData[i][j] == 0)
				{
					DrawRectGraphF(
						j * MAP_SIZE, i * MAP_SIZE,  //描画位置
						0, 0, //切り取り開始位置
						50, 50, //切り取るサイズ
						squares_img1,  //切り取る元画像
						FALSE //透過処理フラグ
					);
					/*DrawBox(j * MAP_SIZE, i * MAP_SIZE,
						j * MAP_SIZE + MAP_SIZE, i * MAP_SIZE + MAP_SIZE,
						GetColor(255, 255, 255), TRUE);*/
				}
			}
		}

		//unsigned int Cr;
		//Cr = GetColor(255, 255, 255);//色の値を取得
		//DrawBox(150, 20, 200, 70, Cr, TRUE);//四角形を描画
		//DrawBox(205, 20, 255, 70, Cr, TRUE);
		//DrawBox(260, 20, 310, 70, Cr, TRUE);

		//描画処理(ここで画像の表示を行う)
		//背景
		//DrawRectGraphF(
		//	0, 0,  //描画位置
		//	0, 0, //切り取り開始位置
		//	800, 600, //切り取るサイズ
		//	back_img1,  //切り取る元画像
		//	TRUE //透過処理フラグ
		//	//LR_flg //反転処理フラグ
		//);
		//プレイヤー
		DrawRectGraphF(
			x, y,  //描画位置
			rect_x, rect_y, //切り取り開始位置
			64, 64, //切り取るサイズ
			image,  //切り取る元画像
			TRUE, //透過処理フラグ
			LR_flg //反転処理フラグ
		);

		//UI部分背景
		DrawBox(0, 0, 800, 50, GetColor(0, 0, 0), TRUE);//四角形を描画
		//文字を描画する
		//登録者数
		DrawFormatString(7, 7, GetColor(255, 255, 255), "1Pチャンネル登録者数：1000人(仮)");
		DrawFormatString(7, 29, GetColor(255, 255, 255), "2Pチャンネル登録者数：1000人(仮)");
		//ゴールまでの歩数
		DrawFormatString(300, 20, GetColor(255, 255, 255), "ゴールまで");
		DrawFormatString(395, 7, GetColor(255, 255, 255), "1P：あと30歩");
		DrawFormatString(395, 29, GetColor(255, 255, 255), "2P：あと30歩");
		//現在順位
		DrawFormatString(550, 20, GetColor(255, 255, 255), "現在順位");
		DrawFormatString(625, 7, GetColor(255, 0, 0), "1位：1P");
		DrawFormatString(625, 29, GetColor(255, 255, 255), "2位：2P");

		int x_c1 = 55, y_c1 = 0;
		//文字を描画する
		//DrawFormatString(x_c1, y_c1, GetColor(255, 255, 0), "START");
		int x_c2 = 505, y_c2 = 300;
		//文字を描画する
		DrawFormatString(x_c2, y_c2, GetColor(255, 0, 0), "GOAL！");

		//x_c = x_c; // x座標を2加算
		//y_c = y_c; // y座標を1加算


		ScreenFlip(); //バックバッファと切り替え

		//例外が発生したらプログラム終了
		if (ProcessMessage() == -1) break;
	}

	DxLib_End(); //dxライブラリ終了処理

	return 0;
}
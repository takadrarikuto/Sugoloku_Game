#pragma once
#include "DxLib.h"
#include "Header.h"

#define MAP_SIZE	50 //マップチップ一つのドットサイズ
#define MAP_WIDTH	20 //マップの幅
#define MAP_HEIGHT	20 //マップの縦長さ

#define MOVE_FRAME	32 //移動にかけるフレーム数

// マップのデータ(16マス×12マス)(0 = 描画マス、1 = 壁)
int MapData[MAP_HEIGHT][MAP_WIDTH] =
{
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 } ,
	{ 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 } ,
	{ 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1 } ,
	{ 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1 } ,
	{ 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1 } ,
	{ 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1 } ,
	{ 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1 } ,
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1 } ,
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1 } ,
	{ 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1 } ,
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1 } ,
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1 } ,
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1 } ,
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1 } ,
	{ 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1 } ,
	{ 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1 } ,
	{ 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1 } ,
	{ 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1 } ,
	{ 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1 } ,
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 } ,
};

//移動しているかどうかのフラグ( 0:停止中  1:移動中 )
int Move;
//各方向に移動する量
int MoveX, MoveY;
//移動し始めてから何フレーム経過したかを保持する変数
int MoveCounter;

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
	int Rou_image = LoadGraph("image\\スロット.png");
	DrawGraph(0, 0, back_img1, TRUE);
	int squares_img1 = LoadGraph("image\\マス.png");

	int i, j;
	int Key;
	int ScrollX, ScrollY;

	//画像の位置情報
	float x, y;
	//画像の移動距離情報
	float vx, vy;
	//画像の移動ベクトル最大値
	float vx_max, vy_max;
	//初期化 
	x = 350.0f;
	y = 275.0f;
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

	//最初は停止中(0)にしておく
	Move = 0;

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

			// 移動中ではない場合キー入力を受け付ける
			if (Move == 0)
			{

			//Enterで前進フラグをtrue、1P移動距離を設定
			if (CheckHitKey(KEY_INPUT_RETURN) && Forward_flg == false)
			{
				if (Direction_of_Travel_num == 0)
				{
					//vx = x + 50; //右
					//vx_max = 2.0f;
					Move = 1;
					MoveX = 1;
					MoveY = 0;
				}
				else if (Direction_of_Travel_num == 1)
				{
					//vx = x - 50;//左
					//vx_max = -2.0f;
					Move = 1;
					MoveX = -1;
					MoveY = 0;
				}
				else if (Direction_of_Travel_num == 2)
				{
					//vy = y - 50;//上
					//vy_max = -2.0f;
					Move = 1;
					MoveX = 0;
					MoveY = -1;
				}
				else if (Direction_of_Travel_num == 3)
				{
					//vy = y + 50;//下
					//vy_max = 2.0f;
					Move = 1;
					MoveX = 0;
					MoveY = 1;
				}
				Forward_flg = true;
			}

			//停止中は画面のスクロールは行わない
			ScrollX = 0;
			ScrollY = 0;
		}

		// 移動中の場合は移動処理を行う
		if (Move == 1)
		{
			MoveCounter++;
			//設定した移動距離までに移動
			//左右
			//if (vx != x)
			//{
			//	x += vx_max;
			//}
			//上下
			//else if (vy != y)
			//{
			//	y += vy_max;
			//}
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

			// 移動処理が終了したら停止中にする
			if (MoveCounter == MOVE_FRAME)
			{
				// プレイヤーの位置を変更する
				x += MoveX;
				y += MoveY;

				// 停止中は画面のスクロールは行わない
				//ScrollX = 0;
				//ScrollY = 0;

				Move = 0;
			}
			else
			{
				// 経過時間からスクロール量を算出する
				ScrollX = -(MoveX * MAP_SIZE * MoveCounter / MOVE_FRAME);
				ScrollY = -(MoveY * MAP_SIZE * MoveCounter / MOVE_FRAME);
			}
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

		//マップを描く
		for (i = 0; i < MAP_HEIGHT; i++)
		{
			for (j = 0; j < MAP_WIDTH; j++)
			{
				if (MapData[i][j] == 0)
				{
					DrawRectGraphF(
						j * MAP_SIZE + ScrollX, i * MAP_SIZE + ScrollY,  //描画位置
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
		DrawFormatString(7, 7, GetColor(255, 255, 255), "1Pチャンネル登録者数：1000人");
		DrawFormatString(7, 29, GetColor(255, 255, 255), "2Pチャンネル登録者数：1000人");
		//ゴールまでの歩数
		DrawFormatString(300, 20, GetColor(255, 255, 255), "ゴールまで");
		DrawFormatString(395, 7, GetColor(255, 255, 255), "1P：あと30歩");
		DrawFormatString(395, 29, GetColor(255, 255, 255), "2P：あと30歩");
		//現在順位
		DrawFormatString(550, 20, GetColor(255, 255, 255), "現在順位");
		DrawFormatString(625, 7, GetColor(255, 0, 0), "1位：1P");
		DrawFormatString(625, 29, GetColor(255, 255, 255), "2位：2P");

		int x_c1 = 355, y_c1 = 350;
		//文字を描画する
		DrawFormatString(x_c1 + ScrollX, y_c1 + ScrollY, GetColor(255, 255, 0), "START");
		int x_c2 = 453, y_c2 = 185;
		//文字を描画する
		DrawFormatString(x_c2 + ScrollX, y_c2 + ScrollY, GetColor(255, 0, 0), "GOAL！");

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
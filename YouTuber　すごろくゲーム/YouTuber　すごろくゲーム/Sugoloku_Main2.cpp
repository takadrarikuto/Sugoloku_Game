#pragma once
#include "DxLib.h"
#include "Header.h"

#define MAP_SIZE	50 //マップチップ一つのドットサイズ
#define MAP_WIDTH	20 //マップの幅
#define MAP_HEIGHT	20 //マップの縦長さ
#define MOVE_FRAME	50 //移動にかけるフレーム数

#define RECR_MAX 200 //ルーレット切り取り数

//マップのデータ(16マス×12マス)(0 = 壁、1 = 描画マス、2 = スタート、3 = ゴール)
int MapData[MAP_HEIGHT][MAP_WIDTH] =
{
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } ,
	{ 0, 2, 0, 1, 1, 1, 1, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 } ,
	{ 0, 1, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 } ,
	{ 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0 } ,
	{ 0, 1, 0, 0, 0, 0, 1, 0, 0, 3, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0 } ,
	{ 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0 } ,
	{ 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0 } ,
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0 } ,
	{ 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0 } ,
	{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 } ,
	{ 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0 } ,
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0 } ,
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0 } ,
	{ 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0 } ,
	{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 } ,
	{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 } ,
	{ 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0 } ,
	{ 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 1, 1, 0 } ,
	{ 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0 } ,
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } ,
};

//プレイヤーの位置
int PlayerX, PlayerY;
//移動しているかどうかのフラグ( 0:停止中  1:移動中 )
int Move;
//各方向に移動する量
int MoveX, MoveY;
//移動し始めてから何フレーム経過したかを保持する変数
int MoveCounter;

//マップとプレイヤーの描画関数
void GraphDraw(int ScrollX, int ScrollY)
{
	int j, i;
	int MapDrawPointX, MapDrawPointY;		//描画するマップ座標値
	int DrawMapChipNumX, DrawMapChipNumY;	//描画するマップチップの数

	//描画するマップチップの数をセット
	DrawMapChipNumX = 800 / MAP_SIZE + 2;
	DrawMapChipNumY = 600 / MAP_SIZE + 2;

	//画面左上に描画するマップ座標をセット
	MapDrawPointX = PlayerX - (DrawMapChipNumX / 2 - 1);
	MapDrawPointY = PlayerY - (DrawMapChipNumY / 2 - 1);

	//画像読み込み(「static int」でないと、メモリが増加し続けるので注意)
	static int image = LoadGraph("image\\Frisk3.png");
	static int back_img1 = LoadGraph("image\\背景テスト用.png");
	static int squares_start = LoadGraph("image\\STARTマス.png");
	static int squares_goal = LoadGraph("image\\GOALマス.png");
	static int squares_img1 = LoadGraph("image\\マス.png");
	static int squares_img2 = LoadGraph("image\\青マス.png");
	static int squares_img3 = LoadGraph("image\\緑マス.png");
	static int Branch = LoadGraph("image\\分岐.png");

	//マップを描く
	for (i = -1; i < DrawMapChipNumY; i++){
		for (j = -1; j < DrawMapChipNumX; j++){
			//画面からはみ出た位置なら描画しない
			if (j + MapDrawPointX < 0 || i + MapDrawPointY < 0 ||
				j + MapDrawPointX >= MAP_WIDTH || i + MapDrawPointY >= MAP_HEIGHT) continue;

			//マップデータが0だったら壁を描画する(デバッグ用)
			/*if (MapData[i + MapDrawPointY][j + MapDrawPointX] == 0)
			{
				DrawBox(j * MAP_SIZE + ScrollX, i * MAP_SIZE + ScrollY,
					j * MAP_SIZE + MAP_SIZE + ScrollX, i * MAP_SIZE + MAP_SIZE + ScrollY,
					GetColor(0, 0, 255), TRUE);
			}*/
			//マップに1があれば「通常マス」描画
			if (MapData[i + MapDrawPointY][j + MapDrawPointX] == 1){
				DrawRectGraphF(
					j * MAP_SIZE + ScrollX, i * MAP_SIZE + ScrollY,  //描画位置
					0, 0, //切り取り開始位置
					50, 50, //切り取るサイズ
					squares_img1,  //切り取る元画像
					FALSE //透過処理フラグ
				);
			}
			//マップに2があれば「STARTマス」描画
			if (MapData[i + MapDrawPointY][j + MapDrawPointX] == 2){
				DrawRectGraphF(
					j * MAP_SIZE + ScrollX, i * MAP_SIZE + ScrollY,  //描画位置
					0, 0, //切り取り開始位置
					50, 50, //切り取るサイズ
					squares_start,  //切り取る元画像
					FALSE //透過処理フラグ
				);
			}
			//マップに3があれば「GOALマス」描画
			if (MapData[i + MapDrawPointY][j + MapDrawPointX] == 3){
				DrawRectGraphF(
					j * MAP_SIZE + ScrollX, i * MAP_SIZE + ScrollY,  //描画位置
					0, 0, //切り取り開始位置
					50, 50, //切り取るサイズ
					squares_goal,  //切り取る元画像
					FALSE //透過処理フラグ
				);
			}
			//マップに4があれば「青マス」描画
			if (MapData[i + MapDrawPointY][j + MapDrawPointX] == 4){
				DrawRectGraphF(
					j * MAP_SIZE + ScrollX, i * MAP_SIZE + ScrollY,  //描画位置
					0, 0, //切り取り開始位置
					50, 50, //切り取るサイズ
					squares_img2,  //切り取る元画像
					FALSE //透過処理フラグ
				);
			}
			//マップに5があれば「緑マス」描画
			if (MapData[i + MapDrawPointY][j + MapDrawPointX] == 5){
				DrawRectGraphF(
					j * MAP_SIZE + ScrollX, i * MAP_SIZE + ScrollY,  //描画位置
					0, 0, //切り取り開始位置
					50, 50, //切り取るサイズ
					squares_img3,  //切り取る元画像
					FALSE //透過処理フラグ
				);
			}
			//マップに6があれば「分岐」描画
			if (MapData[i + MapDrawPointY][j + MapDrawPointX] == 6){
				DrawRectGraphF(
					j * MAP_SIZE + ScrollX, i * MAP_SIZE + ScrollY,  //描画位置
					0, 0, //切り取り開始位置
					60, 60, //切り取るサイズ
					Branch,  //切り取る元画像
					FALSE //透過処理フラグ
				);
			}
		}
	}
	//プレイヤーの描画
	DrawRectGraphF(
		400, 300 ,  //描画位置
		0, 0, //切り取り開始位置
		MAP_SIZE, MAP_SIZE, //切り取るサイズ
		image,  //切り取る元画像
		TRUE //透過処理フラグ
	);

	/*DrawBox((PlayerX - MapDrawPointX) * MAP_SIZE, (PlayerY - MapDrawPointY) * MAP_SIZE,
		(PlayerX - MapDrawPointX + 1) * MAP_SIZE, (PlayerY - MapDrawPointY + 1) * MAP_SIZE,
		GetColor(255, 255, 255), TRUE);*/

	//-----------------------------------------------------------------------
	//UI部分背景
	DrawBox(0, 0, 800, 50, GetColor(0, 0, 0), TRUE);//四角形を描画
	//文字を描画する-------------------------------------------------------------------
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
	//---------------------------------------------------------------------------------
}

//メイン
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	//ポート用変数
	int Sendport, RecvPort; //send送る Recv受ける

	//送受信データ処理用
	char StrBuf[256] = { "NULL" };

	ChangeWindowMode(TRUE); //windowモード
	SetGraphMode(800, 600, 16); //windowサイズ800*600 32bit
	SetAlwaysRunFlag(TRUE); //バックグラウンドでも実行出来るようにする
	SetDoubleStartValidFlag(TRUE); //多重起動の許可
	SetBackgroundColor(0, 100, 0); //背景色

	int Key,i;
	int ScrollX, ScrollY;
	int time;

	//初期化
	if (DxLib_Init() == -1)	{ //DXライブラリ初期化処理
		return -1;				//エラーが起きたら直ちに終了
	}
	if (DxLib_Init() < 0){
		return -1;
	}

	//描画先画面を裏画面にする
	SetDrawScreen(DX_SCREEN_BACK);

	//ルーレット画像(「static int」でないと、メモリが増加し続けるので注意)
	static int Rou_image = LoadGraph("image\\スロット.png");

	//プレイヤーの初期位置をセット
	PlayerX = 1;
	PlayerY = 1;

	//最初は停止中(0)にしておく
	Move = 0;

	//プレイヤー----------------------------------
	//画像の移動距離情報
	float P1_x, P1_y, /*1Pプレイヤー*/P2_x, P2_y/*2Pプレイヤー*/;
	//初期化 
	P1_x = 350.0f; P1_y = 268.0f; //1Pプレイヤー
	P2_x = 400.0f; P2_y = 268.0f; //2Pプレイヤー
	//左右向きフラグ
	bool P1_LR_flg = 1/*1Pプレイヤー*/, P2_LR_flg = 1/*2Pプレイヤー*/;
	//上下向きフラグ
	bool P1_UD_flg = 0/*1Pプレイヤー*/, P2_UD_flg = 0/*2Pプレイヤー*/;
	//進行方向管理変数
	int P1_Direction_of_Travel_num = 0/*1Pプレイヤー*/,
		P2_Direction_of_Travel_num = 0/*2Pプレイヤー*/; //0:右 1:左 2:上 3:下
	//アニメーション用カウント
	int P1_anim_cnt = 0/*1Pプレイヤー*/, P2_anim_cnt = 0/*2Pプレイヤー*/;
	//切り取り位置
	int P1_rect_x = 0/*1Pプレイヤー*/, P2_rect_x = 0/*2Pプレイヤー*/;
	int P1_rect_y = 0/*1Pプレイヤー*/, P2_rect_y = 0/*2Pプレイヤー*/;
	//--------------------------------------------
	//ルーレット----------------------------------
	//画像の位置情報
	float Rou_x, Rou_y;
	//初期化 
	Rou_x = 295.0f;
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

	//ルーレット画像表示停止フラグ
	bool RouDraw_flg = false;
	//ルーレット画像表示停止タイム
	int RouDraw_time = 0;

	//共有
	//主人公移動開始フラグ
	bool P1_PlayerMove_Flg = false/*1Pプレイヤー*/, P2_PlayerMove_Flg = false/*2Pプレイヤー*/;
	//主人公移動回数
	int P1_PlayerMove_num = 0/*1Pプレイヤー*/, P2_PlayerMove_num = 0/*2Pプレイヤー*/;
	//--------------------------------------------

	//ループ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0){
		//画面を初期化
		ClearDrawScreen();

		//方向設定
		//右
		if (CheckHitKey(KEY_INPUT_RIGHT)) {
			P1_LR_flg = 1;
			P1_Direction_of_Travel_num = 0;
			time = 0;
			time++;
			DrawFormatString(0, 50, GetColor(255, 255, 0), "選択方向：右");
		}
		//左
		else if (CheckHitKey(KEY_INPUT_LEFT)) {
			P1_LR_flg = 0;
			P1_Direction_of_Travel_num = 1;
			DrawFormatString(0, 50, GetColor(255, 255, 0), "選択方向：左");
		}
		//上
		else if (CheckHitKey(KEY_INPUT_UP)) {
			P1_UD_flg = 1;
			P1_Direction_of_Travel_num = 2;
			DrawFormatString(0, 50, GetColor(255, 255, 0), "選択方向：上");
		}
		//下
		else if (CheckHitKey(KEY_INPUT_DOWN)) {
			P1_UD_flg = 0;
			P1_Direction_of_Travel_num = 3;
			DrawFormatString(0, 50, GetColor(255, 255, 0), "選択方向：下");
		}

		//移動中ではない場合キー入力を受け付ける
		if (Move == 0){
			//ルーレット処理--------------------------------------------------------------------
			//Enterでルーレット回転スタート
			if (CheckHitKey(KEY_INPUT_RETURN) == true && Roulette_Enter_Bottan == false) {
				if (Roulette == 0) {
					//初期化	
					P1_PlayerMove_num = 0;					
					RouDraw_flg = false;
					Roulette = 1; //Roulette 1へ移動
				}
				else if (Roulette == 1) {					
					Roulette_Rotation = true; //ルーレット回転開始
					Roulette = 2; //Roulette 2へ移動
				}
				else if (Roulette == 2) {
					//ルーレット停止	
					Roulette_Rotation = false; //初期化					
					Roulette = 3; //Roulette 3へ移動
				}
				else if (Roulette == 3)
				{
					P1_PlayerMove_Flg = true; //主人公移動開始
					RouDraw_flg = true; //ルーレット画像表示停止
					//初期化					
					Roulette = 0; //Roulette 0へ移動
				}
				Roulette_Enter_Bottan = true;
			}
			else if (CheckHitKey(KEY_INPUT_RETURN) == false)
				Roulette_Enter_Bottan = false;

			//ルーレット回転処理
			if (Roulette_Rotation == true){
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
			//主人公移動距離調整処理
			if (Rou_rect_y < 200) { //ルーレット切り取りy位置200以下の時
				if (Rou_rect_x == 0) {
					P1_PlayerMove_num = 1; //1マス移動
				}
				else if (Rou_rect_x == 200) {
					P1_PlayerMove_num = 2; //2マス移動
				}
				else if (Rou_rect_x == 400) {
					P1_PlayerMove_num = 3; //3マス移動
				}
			}
			else if (Rou_rect_y == 200) { //ルーレット切り取りy位置200の時
				if (Rou_rect_x == 0) {
					P1_PlayerMove_num = 4; //4マス移動
				}
				else if (Rou_rect_x == 200) {
					P1_PlayerMove_num = 5; //5マス移動
				}
				else if (Rou_rect_x == 400) {
					P1_PlayerMove_num = 6; //6マス移動
				}
			}
			//----------------------------------------------------------------------------------

			//キー入力を得る
			//Key = GetJoypadInputState(DX_INPUT_KEY_PAD1);

			//キー入力に応じてプレイヤーの座標を移動
			/*if (Key & PAD_INPUT_LEFT)
			{
				Move = 1;
				MoveX = -1;
				MoveY = 0;
			}
			if (Key & PAD_INPUT_RIGHT)
			{
				Move = 1;
				MoveX = 1;
				MoveY = 0;
			}
			if (Key & PAD_INPUT_UP)
			{
				Move = 1;
				MoveX = 0;
				MoveY = -1;
			}
			if (Key & PAD_INPUT_DOWN)
			{
				Move = 1;
				MoveX = 0;
				MoveY = 1;
			}*/
			//プレイヤー前進フラグをtrue、1P移動距離を設定
			if (P1_PlayerMove_Flg == true){
				for (i = 0; i < P1_PlayerMove_num; i++){
					if (P1_Direction_of_Travel_num == 0){//右移動						
						Move = 1;
						MoveX = 1.0f;
						MoveY = 0.0f;
					}
					else if (P1_Direction_of_Travel_num == 1){//左移動						
						Move = 1;
						MoveX = -1.0f;
						MoveY = 0.0f;
					}
					else if (P1_Direction_of_Travel_num == 2){//上移動						
						Move = 1;
						MoveX = 0.0f;
						MoveY = -1.0f;
					}
					else if (P1_Direction_of_Travel_num == 3){//下移動						
						Move = 1;
						MoveX = 0.0f;
						MoveY = 1.0f;
					}

					if (Move == 1){
						MoveCounter = 0;
					}
				}
			}

			//進入不可能なマップだった場合は移動できない
			if (Move == 1){
				if (MapData[PlayerY + MoveY][PlayerX + MoveX] == 0){
					Move = 0;
				}
				else{
					MoveCounter = 0;
				}
			}

			//停止中は画面のスクロールは行わない
			ScrollX = 0;
			ScrollY = 0;
		}

		//移動中の場合は移動処理を行う
		if (Move == 1){
			MoveCounter++;
			if (P1_PlayerMove_Flg == true){
				//初期化
				P1_PlayerMove_Flg = false;
				P1_Direction_of_Travel_num = 0;
			}
			//移動処理が終了したら停止中にする
			if (MoveCounter == MOVE_FRAME){
				Move = 0;

				//プレイヤーの位置を変更する
				PlayerX += MoveX;
				PlayerY += MoveY;

				//停止中は画面のスクロールは行わない
				ScrollX = 0;
				ScrollY = 0;
			}
			else{
				//経過時間からスクロール量を算出する
				ScrollX = -(MoveX * MAP_SIZE * MoveCounter / MOVE_FRAME);
				ScrollY = -(MoveY * MAP_SIZE * MoveCounter / MOVE_FRAME);
			}
		}

		//ClearDrawScreen(); //画像クリア

		if (RouDraw_flg == false){
			//ルーレット描画処理
			DrawRectGraphF(
				Rou_x, Rou_y,  //描画位置
				Rou_rect_x, Rou_rect_y, //切り取り開始位置
				RECR_MAX, RECR_MAX, //切り取るサイズ
				Rou_image,  //切り取る元画像
				FALSE, //透過処理フラグ
				Rou_LR_flg //反転処理フラグ
			);
		}

		//マップとプレイヤーを描画
		GraphDraw(ScrollX, ScrollY);

		ScreenFlip(); //バックバッファと切り替え

		//例外が発生したらプログラム終了
		if (ProcessMessage() == -1) break;
	}

	DxLib_End(); //dxライブラリ終了処理

	return 0;
}
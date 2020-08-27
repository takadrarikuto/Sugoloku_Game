#pragma once
#include "DxLib.h"
#include "Header.h"

#define MAP_SIZE	50 //マップチップ一つのドットサイズ
#define MAP_WIDTH	20 //マップの幅
#define MAP_HEIGHT	20 //マップの縦長さ
#define MOVE_FRAME	50 //移動にかけるフレーム数

#define RECR_MAX 200 //ルーレット切り取り数

/*マップのデータ(20マス×20マス)(0 = 壁、1 = 描画マス、2 = スタート、3 = ゴール
4 = 登録者増加、 5 = 登録者減少、6 = 分岐点、7 = 2倍マス、)(150マス)*/
int MapData[MAP_HEIGHT][MAP_WIDTH] =
{
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,2,0,1,1,4,1,1,1,5,1,1,4,1,1,4,1,1,5,0},
	{0,1,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
	{0,1,0,1,1,1,5,0,0,0,0,0,4,1,5,1,0,0,1,0},
	{0,4,0,0,0,0,1,0,3,1,9,9,9,0,0,8,0,0,1,0},
	{0,5,0,0,0,0,4,0,0,0,0,0,0,0,0,1,0,0,5,0},
	{0,1,1,1,1,7,5,0,4,1,1,4,5,5,4,5,0,0,1,0},
	{0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,1,0},
	{0,1,5,1,1,7,1,1,5,0,1,8,1,0,1,7,1,0,4,0},
	{0,4,0,0,0,0,0,0,0,0,1,0,5,5,5,0,4,0,1,0},
	{0,1,5,1,1,8,1,4,1,1,4,0,0,0,0,0,1,0,1,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0},
	{0,1,5,1,0,5,1,4,0,0,0,0,4,4,4,0,5,0,7,0},
	{0,4,0,1,0,1,0,1,0,5,1,1,1,0,1,8,1,0,1,0},
	{0,1,0,4,1,8,0,7,1,4,0,0,0,0,0,0,0,0,8,0},
	{0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
	{0,1,0,1,4,4,4,4,5,1,4,1,4,4,1,5,1,0,1,0},
	{0,8,1,1,0,0,0,0,0,0,0,0,0,0,0,0,6,4,5,0},
	{0,0,0,1,5,5,5,5,4,1,5,1,5,5,1,4,1,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},

	/*{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } ,
	{ 0, 2, 0, 1, 1, 4, 1, 1, 1, 1,    5, 1, 1, 1, 1, 4, 1, 1, 5, 0 } ,
	{ 0, 1, 0, 8, 0, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0, 0, 0, 1, 0 } ,
	{ 0, 1, 0, 1, 1, 1, 1, 0, 0, 0,    0, 0, 1, 4, 1, 0, 0, 0, 1, 0 } ,
	{ 0, 4, 0, 0, 0, 0, 1, 0, 0, 3,    9, 9, 9, 0, 8, 0, 0, 0, 1, 0 } ,
	{ 0, 5, 0, 0, 0, 0, 5, 0, 0, 0,    0, 0, 0, 0, 1, 0, 0, 0, 1, 0 } ,
	{ 0, 1, 1, 1, 1, 7, 4, 0, 0, 0,    0, 0, 1, 4, 1, 0, 0, 0, 5, 0 } ,
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    0, 0, 1, 0, 0, 0, 0, 0, 1, 0 } ,
	{ 0, 1, 5, 1, 1, 7, 1, 1, 5, 7,    4, 1, 1, 0, 0, 0, 0, 0, 4, 0 } ,
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0, 0, 0, 1, 0 } ,

	{ 0, 1, 1, 1, 5, 8, 1, 1, 1, 1,    4, 1, 1, 1, 0, 0, 0, 0, 1, 0 } ,
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    0, 0, 0, 1, 0, 0, 0, 0, 1, 0 } ,
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    0, 0, 0, 1, 0, 0, 0, 0, 7, 0 } ,
	{ 0, 1, 1, 5, 1, 1, 1, 8, 1, 4,    1, 1, 5, 5, 0, 0, 0, 0, 1, 0 } ,
	{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0, 0, 0, 8, 0 } ,
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0, 0, 0, 1, 0 } ,
	{ 0, 1, 0, 1, 1, 1, 4, 1, 5, 1,    4, 1, 4, 4, 1, 5, 7, 0, 1, 0 } ,
	{ 0, 8, 1, 1, 0, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0, 6, 4, 1, 0 } ,
	{ 0, 0, 0, 1, 1, 1, 5, 1, 4, 5,    1, 1, 5, 5, 1, 4, 1, 0, 0, 0 } ,
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } ,*/
};
/*主人公用のマップのデータ(20マス×20マス)(0 = 壁、1 = 描画マス、2 = 主人公、3 = 通過後マス
4 = 登録者増加、 5 = 登録者減少、 6 = 分岐点 8 = 分岐点終点(予定))(125マス)*/
4 = 登録者増加、 5 = 登録者減少、 6 = 分岐点、7 = 2倍マス、9 = ゴールマス　 = 分岐点終点(7以外予定))(150マス)*/
int MapData_P[MAP_HEIGHT][MAP_WIDTH] =
{
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,2,0,1,1,4,1,1,1,5,1,1,4,1,1,4,1,1,5,0},
	{0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
	{0,1,0,1,1,1,5,0,0,0,0,0,4,1,5,1,0,0,1,0},
	{0,4,0,0,0,0,1,0,9,1,1,1,1,0,0,1,0,0,1,0},
	{0,5,0,0,0,0,4,0,0,0,0,0,0,0,0,1,0,0,5,0},
	{0,1,1,1,1,7,5,0,4,1,1,4,5,5,4,5,0,0,1,0},
	{0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,1,0},
	{0,1,5,1,1,7,1,1,5,0,1,1,1,0,1,7,1,0,4,0},
	{0,4,0,0,0,0,0,0,0,0,1,0,5,5,5,0,4,0,1,0},
	{0,1,5,1,1,1,1,4,1,1,4,0,0,0,0,0,1,0,1,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0},
	{0,1,5,1,0,5,1,4,0,0,0,0,4,4,4,0,5,0,7,0},
	{0,4,0,1,0,1,0,1,0,5,1,1,1,0,1,1,1,0,1,0},
	{0,1,0,4,1,1,0,7,1,4,0,0,0,0,0,0,0,0,1,0},
	{0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
	{0,1,0,1,4,4,4,4,5,1,4,1,4,4,1,5,1,0,1,0},
	{0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,6,4,5,0},
	{0,0,0,1,5,5,5,5,4,1,5,1,5,5,1,4,1,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	/*{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } ,
	{ 0, 2, 0, 1, 1, 4, 1, 1, 1, 1,    5, 1, 1, 1, 1, 4, 1, 1, 5, 0 } ,
	{ 0, 1, 0, 1, 0, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0, 0, 0, 1, 0 } ,
	{ 0, 1, 0, 1, 1, 1, 1, 0, 0, 0,    0, 0, 1, 4, 1, 0, 0, 0, 1, 0 } ,
	{ 0, 4, 0, 0, 0, 0, 1, 0, 0, 9,    1, 1, 1, 0, 8, 0, 0, 0, 1, 0 } ,
	{ 0, 5, 0, 0, 0, 0, 5, 0, 0, 0,    0, 0, 0, 0, 1, 0, 0, 0, 1, 0 } ,
	{ 0, 1, 1, 1, 1, 1, 4, 0, 0, 0,    0, 0, 1, 4, 1, 0, 0, 0, 5, 0 } ,
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    0, 0, 1, 0, 0, 0, 0, 0, 1, 0 } ,
	{ 0, 1, 5, 1, 1, 7, 1, 1, 5, 7,    4, 1, 1, 0, 0, 0, 0, 0, 4, 0 } ,
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0, 0, 0, 1, 0 } ,

	{ 0, 1, 1, 1, 5, 8, 1, 1, 1, 1,    4, 1, 1, 1, 0, 0, 0, 0, 1, 0 } ,
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    0, 0, 0, 1, 0, 0, 0, 0, 1, 0 } ,
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    0, 0, 0, 1, 0, 0, 0, 0, 7, 0 } ,
	{ 0, 1, 1, 5, 1, 1, 1, 8, 1, 4,    1, 1, 5, 5, 0, 0, 0, 0, 1, 0 } ,
	{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0, 0, 0, 8, 0 } ,
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0, 0, 0, 1, 0 } ,
	{ 0, 1, 0, 1, 1, 1, 4, 1, 5, 1,    4, 1, 4, 4, 1, 5, 7, 0, 1, 0 } ,
	{ 0, 8, 1, 1, 0, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0, 6, 4, 1, 0 } ,
	{ 0, 0, 0, 1, 1, 1, 5, 1, 4, 5,    1, 1, 5, 5, 1, 4, 1, 0, 0, 0 } ,
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } ,*/
};

//プレイヤーの位置
int PlayerX, PlayerY;
//移動しているかどうかのフラグ( 0:停止中  1:移動中 )
int Move;
//各方向に移動する量
int MoveX, MoveY;
//移動し始めてから何フレーム経過したかを保持する変数
int MoveCounter;

//チャンネル登録者数用変数(初期値：1000人)
int P1_subscriber = 1000;
int P2_subscriber = 1000;

//マス目カウント用(試作)
int squares_cnt1 = 150;
int squares_cnt2 = 150;

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
	static int image = LoadGraph("image\\プレイヤー1.png");
	static int back_img1 = LoadGraph("image\\背景テスト用.png");
	static int squares_start = LoadGraph("image\\STARTマス.png");//「2」
	static int squares_goal = LoadGraph("image\\GOALマス.png");//「3」
	static int squares_img1 = LoadGraph("image\\マス.png");//「1」
	static int subscriber_up = LoadGraph("image\\登録者数増加マス.png");//「4」
	static int subscriber_down = LoadGraph("image\\登録者数減少マス.png");//「5」
	static int Branch = LoadGraph("image\\分岐.png");//「6」
	static int Double = LoadGraph("image\\２倍マス.png");//「7」
	static int event = LoadGraph("image\\イベントマス.png");//「8」
	static int Reversal = LoadGraph("image\\逆転マス.png");//「9」

	//マップを描く
	for (i = -1; i < DrawMapChipNumY; i++) {
		for (j = -1; j < DrawMapChipNumX; j++) {
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
			if (MapData[i + MapDrawPointY][j + MapDrawPointX] == 1) {
				DrawRectGraphF(
					j * MAP_SIZE + ScrollX, i * MAP_SIZE + ScrollY,  //描画位置
					0, 0, //切り取り開始位置
					50, 50, //切り取るサイズ
					squares_img1,  //切り取る元画像
					FALSE //透過処理フラグ
				);
			}
			//マップに2があれば「STARTマス」描画
			if (MapData[i + MapDrawPointY][j + MapDrawPointX] == 2) {
				DrawRectGraphF(
					j * MAP_SIZE + ScrollX, i * MAP_SIZE + ScrollY,  //描画位置
					0, 0, //切り取り開始位置
					50, 50, //切り取るサイズ
					squares_start,  //切り取る元画像
					FALSE //透過処理フラグ
				);
			}
			//マップに3があれば「GOALマス」描画
			if (MapData[i + MapDrawPointY][j + MapDrawPointX] == 3) {
				DrawRectGraphF(
					j * MAP_SIZE + ScrollX, i * MAP_SIZE + ScrollY,  //描画位置
					0, 0, //切り取り開始位置
					50, 50, //切り取るサイズ
					squares_goal,  //切り取る元画像
					FALSE //透過処理フラグ
				);
			}
			//マップに4があれば「チャンネル登録者数増加マス」描画
			if (MapData[i + MapDrawPointY][j + MapDrawPointX] == 4) {
				DrawRectGraphF(
					j * MAP_SIZE + ScrollX, i * MAP_SIZE + ScrollY,  //描画位置
					0, 0, //切り取り開始位置
					50, 50, //切り取るサイズ
					subscriber_up,  //切り取る元画像
					FALSE //透過処理フラグ
				);
			}
			//マップに5があれば「チャンネル登録者数減少マス」描画
			if (MapData[i + MapDrawPointY][j + MapDrawPointX] == 5) {
				DrawRectGraphF(
					j * MAP_SIZE + ScrollX, i * MAP_SIZE + ScrollY,  //描画位置
					0, 0, //切り取り開始位置
					50, 50, //切り取るサイズ
					subscriber_down,  //切り取る元画像
					FALSE //透過処理フラグ
				);
			}
			//マップに6があれば「分岐」描画
			if (MapData[i + MapDrawPointY][j + MapDrawPointX] == 6) {
				DrawRectGraphF(
					j * MAP_SIZE + ScrollX, i * MAP_SIZE + ScrollY,  //描画位置
					0, 0, //切り取り開始位置
					50, 50, //切り取るサイズ
					Branch,  //切り取る元画像
					FALSE //透過処理フラグ
				);
			}
			//マップに7があれば「サイコロ２倍マス」描画
			if (MapData[i + MapDrawPointY][j + MapDrawPointX] == 7)
			{
				DrawRectGraphF(
					j * MAP_SIZE + ScrollX, i * MAP_SIZE + ScrollY,  //描画位置
					0, 0, //切り取り開始位置
					50, 50, //切り取るサイズ
					Double,  //切り取る元画像
					FALSE //透過処理フラグ
				);
			}
			//マップに8があれば「イベントマス」描画
			if (MapData[i + MapDrawPointY][j + MapDrawPointX] == 8)
			{
				DrawRectGraphF(
					j * MAP_SIZE + ScrollX, i * MAP_SIZE + ScrollY,  //描画位置
					0, 0, //切り取り開始位置
					50, 50, //切り取るサイズ
					event,  //切り取る元画像
					FALSE //透過処理フラグ
				);
			}
			//マップに9があれば「逆転マス」描画
			if (MapData[i + MapDrawPointY][j + MapDrawPointX] == 9)
			{
				DrawRectGraphF(
					j * MAP_SIZE + ScrollX, i * MAP_SIZE + ScrollY,  //描画位置
					0, 0, //切り取り開始位置
					50, 50, //切り取るサイズ
					Reversal,  //切り取る元画像
					FALSE //透過処理フラグ
				);
			}
			//主人公用マップに2があれば「主人公」描画
			if (MapData_P[i + MapDrawPointY][j + MapDrawPointX] == 2)
			{
				DrawRectGraphF(
					j * MAP_SIZE + ScrollX, i * MAP_SIZE + ScrollY,  //描画位置
					0, 0, //切り取り開始位置
					MAP_SIZE, MAP_SIZE, //切り取るサイズ
					image,  //切り取る元画像
					TRUE //透過処理フラグ
				);
			}
		}
	}
	//プレイヤーの描画
	/*DrawRectGraphF(
		400, 300 ,  //描画位置
		0, 0, //切り取り開始位置
		MAP_SIZE, MAP_SIZE, //切り取るサイズ
		image,  //切り取る元画像
		TRUE //透過処理フラグ
	);*/

	/*DrawBox((PlayerX - MapDrawPointX) * MAP_SIZE, (PlayerY - MapDrawPointY) * MAP_SIZE,
		(PlayerX - MapDrawPointX + 1) * MAP_SIZE, (PlayerY - MapDrawPointY + 1) * MAP_SIZE,
		GetColor(255, 255, 255), TRUE);*/

	//---------------------------------------------------------------------------------
	//UI部分背景
	DrawBox(0, 0, 800, 50, GetColor(0, 0, 0), TRUE);//描画
	//文字を描画する-------------------------------------------------------------------
	//登録者数
	DrawFormatString(7, 7, GetColor(255, 255, 255), "1Pチャンネル登録者数：%d人", P1_subscriber);
	DrawFormatString(7, 29, GetColor(255, 255, 255), "2Pチャンネル登録者数：%d人", P2_subscriber);
	//ゴールまでの歩数
	DrawFormatString(270, 18, GetColor(255, 255, 255), "ゴールまで");
	DrawFormatString(365, 7, GetColor(255, 255, 255), "1P：あと%d歩", squares_cnt1);
	DrawFormatString(365, 29, GetColor(255, 255, 255), "2P：あと%d歩", squares_cnt2);
	//現在順位
	DrawFormatString(500, 18, GetColor(255, 255, 255), "現在順位");
	if (P1_subscriber > P2_subscriber)
	{
		DrawFormatString(575, 7, GetColor(255, 0, 0), "1位：1P");
		DrawFormatString(575, 29, GetColor(255, 255, 255), "2位：2P");
	}
	else if (P2_subscriber > P1_subscriber)
	{
		DrawFormatString(575, 7, GetColor(255, 0, 0), "1位：2P");
		DrawFormatString(575, 29, GetColor(255, 255, 255), "2位：1P");
	}
	else
	{
		DrawFormatString(575, 18, GetColor(255, 255, 255), "同位：");
		DrawFormatString(628, 7, GetColor(255, 255, 255), "1P");
		DrawFormatString(628, 29, GetColor(255, 255, 255), "2P");
	}
	//順番
	DrawFormatString(665, 18, GetColor(255, 255, 255), "ターン");
	DrawFormatString(750, 7, GetColor(255, 255, 255), "1P");
	DrawFormatString(750, 29, GetColor(255, 255, 255), "2P");
	DrawFormatString(725, 7, GetColor(255, 255, 255), "◆");
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

	SetOutApplicationLogValidFlag(FALSE); //Log.txtを生成しないように設定
	ChangeWindowMode(TRUE); //windowモード
	SetGraphMode(800, 600, 32); //windowサイズ800*600 32bit
	SetAlwaysRunFlag(TRUE); //バックグラウンドでも実行出来るようにする
	SetDoubleStartValidFlag(TRUE); //多重起動の許可
	SetBackgroundColor(0, 100, 0); //背景色

	int Key, i;
	int ScrollX, ScrollY;
	int MapDrawPointX, MapDrawPointY;		//描画するマップ座標値
	int DrawMapChipNumX, DrawMapChipNumY;	//描画するマップチップの数
	int subscriber_up_time = 0;
	int subscriber_down_time = 0;
	int two_times_messagetime = 0;
	int goal_time = 0;
	bool Roulette_Flg = false; //ルーレットテキスト用フラグ
	bool Roulette_stop_Flg = false; //ルーレットテキスト用フラグ
	bool square_go_Flg = false; //ルーレットテキスト用フラグ
	bool square_rest_Flg = true; //ルーレットテキスト用フラグ

	//初期化
	if (DxLib_Init() == -1) { //DXライブラリ初期化処理
		return -1;				//エラーが起きたら直ちに終了
	}
	if (DxLib_Init() < 0) {
		return -1;
	}

	//描画先画面を裏画面にする
	SetDrawScreen(DX_SCREEN_BACK);

	//画像読み込み(「static int」でないと、メモリが増加し続けるので注意)
	static int Rou_image = LoadGraph("image\\スロット.png");//ルーレット
	static int message_window_img = LoadGraph("image\\メッセージウィンドウ.png");//「9」

	//BGM再生
	PlaySoundFile("music\\メインBGM.mp3", DX_PLAYTYPE_LOOP);

	int move_sound = 0;
	int roulette_sound = 0;
	int roulette_dec_sound = 0;
	int subscriber_up_sound = 0;
	int subscriber_down_sound = 0;
	int goal_sound = 0;
	int goal_cheers_sound = 0;

	move_sound = LoadSoundMem("music\\コマ移動.mp3");
	roulette_sound = LoadSoundMem("music\\ルーレット.mp3");
	roulette_dec_sound = LoadSoundMem("music\\ルーレット決定.mp3");
	subscriber_up_sound = LoadSoundMem("music\\登録者数増加音.mp3");
	subscriber_down_sound = LoadSoundMem("music\\登録者数減少音.mp3");
	goal_sound = LoadSoundMem("music\\ゴール音.mp3");
	goal_cheers_sound = LoadSoundMem("music\\ゴール歓声.mp3");

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

	//2倍マス用フラグ
	bool two_times = false;

	//共有
	//主人公移動開始フラグ
	bool P1_PlayerMove_Flg = false/*1Pプレイヤー*/, P2_PlayerMove_Flg = false/*2Pプレイヤー*/;
	//イベントスロットフラグ
	bool EventRou_flg = false;
	//分岐設定フラグ
	bool Branch_flg = false;
	//スロット変数
	int Rou_num = 0;
	//イベントスロット変数
	int P1_EventRou_num = 0/*1Pプレイヤー*/, P2_EventRou_num = 0/*2Pプレイヤー*/;
	//分岐設定変数 1 = →,2 = ←,3 = ↑,4 = ↓
	int Branch_num = 0;
	//主人公移動回数
	int P1_PlayerMove_num = 0/*1Pプレイヤー*/, P2_PlayerMove_num = 0/*2Pプレイヤー*/;
	//--------------------------------------------
	//1P2P切り替えフラグ
	bool P_Switching_flg = false;

	//タイトル
	//タイトル位置情報
	float Title_x = 0.0f, Title_y = 0.0f;
	//タイトル切り替えフラグ
	bool Title_flg = false;
	//タイトル画像
	//static int Title_image = LoadGraph("image\\スロット.png");

	//ループ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
		//画面を初期化
		ClearDrawScreen();

		//向き文字表示
		if (P1_LR_flg == 1)
		{
			DrawFormatString(0, 50, GetColor(255, 255, 0), "選択方向選択：右");
		}
		else if (P1_LR_flg == 0)
		{
			DrawFormatString(0, 50, GetColor(255, 255, 0), "選択方向選択：左");
		}
		else if (P1_UD_flg == 1)
		{
			DrawFormatString(0, 50, GetColor(255, 255, 0), "選択方向選択：上");
		}
		else if (P1_UD_flg == 0)
		{
			DrawFormatString(0, 50, GetColor(255, 255, 0), "選択方向選択：下");
		}

		//移動中ではない場合キー入力を受け付ける
		if (Move == 0) {
			//ルーレット処理--------------------------------------------------------------------
			//Enterでルーレット回転スタート
			if (CheckHitKey(KEY_INPUT_RETURN) == true && Roulette_Enter_Bottan == false) {
				if (Roulette == 0) { //ルーレット回転スタート
					RouDraw_flg = false; //画像表示再開
					Roulette_Rotation = true; //ルーレット回転開始
					Roulette_stop_Flg = true; //ルーレット回転中テキストオン
					square_rest_Flg = false;
					Roulette = 1; //Roulette 1へ移動
					PlaySoundMem(roulette_sound, DX_PLAYTYPE_LOOP, TRUE);//効果音再生
				}
				else if (Roulette == 1) { //ルーレット停止
					Roulette_Rotation = false; //初期化
					Roulette_stop_Flg = false; //ルーレット回転中テキストオフ
					square_go_Flg = true; //コマ進めるテキストオン
					Roulette = 2; //Roulette 2へ移動
					StopSoundMem(roulette_sound);
					PlaySoundMem(roulette_dec_sound, DX_PLAYTYPE_BACK, TRUE);//効果音再生
				}
				else if (Roulette == 2) { //移動開始
					//イベントスロットフラグ and 分岐設定フラグがfalseの時 and 分岐設定変数が0の時
					P1_PlayerMove_Flg = true; //主人公移動開始	
					RouDraw_flg = true; //ルーレット画像表示停止
					square_go_Flg = false; //コマ進めるテキストオフ
					square_rest_Flg = true;
					Roulette = 0; //Roulette 0へ移動
				}
				Roulette_Enter_Bottan = true;
			}
			else if (CheckHitKey(KEY_INPUT_RETURN) == false)
				Roulette_Enter_Bottan = false;
				Roulette_Flg = true; //ルーレットスタートテキストオン
				//two_times = false;

			//ルーレット回転処理
			if (Roulette_Rotation == true) {
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
					Rou_num = 1; //1スロット
				}
				else if (Rou_rect_x == 200) {
					Rou_num = 2; //2スロット
				}
				else if (Rou_rect_x == 400) {
					Rou_num = 3; //3スロット
				}
				//2倍マスフラグがONなら2倍にする
				if (two_times == true)
				{
					P1_PlayerMove_num *= 2;
				}
			}
			else if (Rou_rect_y == 200) { //ルーレット切り取りy位置200の時
				if (Rou_rect_x == 0) {
					Rou_num = 4; //4スロット
				}
				else if (Rou_rect_x == 200) {
					Rou_num = 5; //5スロット
				}
				else if (Rou_rect_x == 400) {
					Rou_num = 6; //6スロット
				}
			}

			//分岐設定フラグ
			if (Branch_flg == true && Roulette == 2) {
				//分岐処理
				if (Rou_num > 3) {
					Branch_num = 3; //分岐設定 3 = ↑
				}
				else {
					Branch_num = 4; //分岐設定 4 = ↓
				}
			}
			//イベントスロット判定処理
			else if (EventRou_flg == true && Roulette == 2) {
				P1_EventRou_num = Rou_num; //イベントスロット
				EventRou_flg = false; //イベントスロットフラグ初期化
			}
			//マス移動処理
			else if(Branch_flg == false && EventRou_flg == false && Roulette == 0){
				P1_PlayerMove_num = 6; //マス移動
			}

				//2倍マスフラグがONなら2倍にする
				if (two_times == true)
				{
					P1_PlayerMove_num *= 2;
				}
			}
			//----------------------------------------------------------------------------------

			//キー入力を得る
			Key = GetJoypadInputState(DX_INPUT_KEY_PAD1);


			//停止中は画面のスクロールは行わない
			ScrollX = 0;
			ScrollY = 0;
		}
		
		//移動処理
		//進入不可能なマップだった場合は移動できない
		if (P1_PlayerMove_Flg == true)
		{
			//0 = 壁には移動できない
			if (MapData_P[PlayerY + MoveY][PlayerX + MoveX] == 0)
			{

				//0には何もしない
			}
			else {
				//主人公の周りにある道を確認して移動する
				if (MapData_P[PlayerY][PlayerX] == 2 && (MapData_P[PlayerY][PlayerX + 1] == 1 || MapData_P[PlayerY][PlayerX + 1] >= 4)) {//右移動
					//移動回数が1の時
					if (P1_PlayerMove_num == 1) {
						//進んだ方向に「4」があれば、登録者数増加
						if (MapData_P[PlayerY][PlayerX + 1] == 4) {
							PlaySoundMem(subscriber_up_sound, DX_PLAYTYPE_BACK, TRUE);//増加音再生
							P1_subscriber += 100;
							subscriber_up_time = 200;
						}
						//進んだ方向に「5」があれば、登録者数減少
						if (MapData_P[PlayerY][PlayerX + 1] == 5) {
							PlaySoundMem(subscriber_down_sound, DX_PLAYTYPE_BACK, TRUE);//減少音再生
							P1_subscriber -= 100;
							subscriber_down_time = 200;
						}
						//進んだ方向に「7」があれば、次回ルーレット数2倍
						if (MapData_P[PlayerY][PlayerX + 1] == 7) {
							PlaySoundMem(subscriber_up_sound, DX_PLAYTYPE_BACK, TRUE);//増加音再生
							two_times = true;
							two_times_messagetime = 200;
						}
						//進んだ方向が「7以外」なら、2倍マスフラグをOFFにする
						if (MapData_P[PlayerY][PlayerX + 1] != 7 && two_times == true)
						{
							two_times = false;
						}
					}
					//(主人公マップの)進んだ方向に「9」があれば、ゴール処理
					if (MapData_P[PlayerY][PlayerX + 1] == 9) {
						PlaySoundMem(goal_sound, DX_PLAYTYPE_BACK, TRUE);//効果音再生
						PlaySoundMem(goal_cheers_sound, DX_PLAYTYPE_BACK, TRUE);//効果音再生
						goal_time = 200;
						//順位によって順位ボーナス加算
						if (P1_subscriber > P2_subscriber) {
							P1_subscriber += 10000; //1位 +10000人
						}
						else if (P2_subscriber > P1_subscriber) {
							P1_subscriber += 5000; //2位 +5000人
						}
					}
					MapData_P[PlayerY][PlayerX] = 3; //主人公が通った所は通れなくする
					MapData_P[PlayerY][PlayerX + 1] = 2; //通路に主人公を通す
					MoveX = 1.0f; //X軸方向にスクロール
					P1_LR_flg = 1; //向き切り替え 右
				}
				else if (MapData_P[PlayerY][PlayerX] == 2 && (MapData_P[PlayerY][PlayerX - 1] == 1|| MapData_P[PlayerY][PlayerX - 1] >= 4)) {//左移動
					//移動回数が1の時
					if (P1_PlayerMove_num == 1) {
						//進んだ方向に「4」があれば、登録者数増加
						if (MapData_P[PlayerY][PlayerX - 1] == 4) {
							PlaySoundMem(subscriber_up_sound, DX_PLAYTYPE_BACK, TRUE);//増加音再生
							P1_subscriber += 100;
							subscriber_up_time = 200;
						}
						//進んだ方向に「5」があれば、登録者数減少
						if (MapData_P[PlayerY][PlayerX - 1] == 5) {
							PlaySoundMem(subscriber_down_sound, DX_PLAYTYPE_BACK, TRUE);//減少音再生
							P1_subscriber -= 100;
							subscriber_down_time = 200;
						}
						//進んだ方向に「7」があれば、次回ルーレット数2倍
						if (MapData_P[PlayerY][PlayerX - 1] == 7) {
							PlaySoundMem(subscriber_up_sound, DX_PLAYTYPE_BACK, TRUE);//増加音再生
							two_times = true;
							two_times_messagetime = 200;
						}
						//進んだ方向が「7以外」なら、2倍マスフラグをOFFにする
						if (MapData_P[PlayerY][PlayerX - 1] != 7 && two_times == true)
						{
							two_times = false;
						}
					}
					//(主人公マップの)進んだ方向に「9」があれば、ゴール処理
					if (MapData_P[PlayerY][PlayerX - 1] == 9) {
						PlaySoundMem(goal_sound, DX_PLAYTYPE_BACK, TRUE);//効果音再生
						PlaySoundMem(goal_cheers_sound, DX_PLAYTYPE_BACK, TRUE);//効果音再生
						goal_time = 200;
						//順位によって順位ボーナス加算
						if (P1_subscriber > P2_subscriber) {
							P1_subscriber += 10000;
						}
						else if (P2_subscriber > P1_subscriber) {
							P1_subscriber += 5000;
						}
					}
					MapData_P[PlayerY][PlayerX] = 3; //主人公が通った所は通れなくする
					MapData_P[PlayerY][PlayerX - 1] = 2; //通路に主人公を通す
					MoveX = -1.0f; //-X軸方向にスクロール
					P1_LR_flg = 0; //向き切り替え 左
				}
				else if (MapData_P[PlayerY][PlayerX] == 2 && (MapData_P[PlayerY - 1][PlayerX] == 1|| MapData_P[PlayerY - 1][PlayerX] >= 4)) {//上移動
					//移動回数が1の時
					if (P1_PlayerMove_num == 1) {
						//進んだ方向に「4」があれば、登録者数増加
						if (MapData_P[PlayerY - 1][PlayerX] == 4) {
							PlaySoundMem(subscriber_up_sound, DX_PLAYTYPE_BACK, TRUE);//増加音再生
							P1_subscriber += 100;
							subscriber_up_time = 200;
						}
						//進んだ方向に「5」があれば、登録者数減少
						if (MapData_P[PlayerY - 1][PlayerX] == 5) {
							PlaySoundMem(subscriber_down_sound, DX_PLAYTYPE_BACK, TRUE);//減少音再生
							P1_subscriber -= 100;
							subscriber_down_time = 200;
						}
						//進んだ方向に「7」があれば、次回ルーレット数2倍
						if (MapData_P[PlayerY - 1][PlayerX] == 7) {
							PlaySoundMem(subscriber_up_sound, DX_PLAYTYPE_BACK, TRUE);//増加音再生
							two_times = true;
							two_times_messagetime = 200;
						}
						//進んだ方向が「7以外」なら、2倍マスフラグをOFFにする
						if (MapData_P[PlayerY - 1][PlayerX] != 7 && two_times == true)
						{
							two_times = false;
						}
					}
					//(主人公マップの)進んだ方向に「9」があれば、ゴール処理
					if (MapData_P[PlayerY - 1][PlayerX] == 9) {
						PlaySoundMem(goal_sound, DX_PLAYTYPE_BACK, TRUE);//効果音再生
						PlaySoundMem(goal_cheers_sound, DX_PLAYTYPE_BACK, TRUE);//効果音再生
						goal_time = 200;
						//順位によって順位ボーナス加算
						if (P1_subscriber > P2_subscriber) {
							P1_subscriber += 10000;
						}
						else if (P2_subscriber > P1_subscriber) {
							P1_subscriber += 5000;
						}
					}
					MapData_P[PlayerY][PlayerX] = 3; //主人公が通った所は通れなくする
					MapData_P[PlayerY - 1][PlayerX] = 2; //通路に主人公を通す
					MoveY = -1.0f; //-Y軸方向にスクロール
					P1_UD_flg = 1; //向き切り替え 上
				}
				else if (MapData_P[PlayerY][PlayerX] == 2 && (MapData_P[PlayerY + 1][PlayerX] == 1 || MapData_P[PlayerY + 1][PlayerX] >= 4 )) {//下移動
					//移動回数が1の時
					if (P1_PlayerMove_num == 1) {
						//進んだ方向に「4」があれば、登録者数増加
						if (MapData_P[PlayerY + 1][PlayerX] == 4) {
							PlaySoundMem(subscriber_up_sound, DX_PLAYTYPE_BACK, TRUE);//増加音再生
							P1_subscriber += 100;
							subscriber_up_time = 200;
						}
						//進んだ方向に「5」があれば、登録者数減少
						if (MapData_P[PlayerY + 1][PlayerX] == 5) {
							PlaySoundMem(subscriber_down_sound, DX_PLAYTYPE_BACK, TRUE);//減少音再生
							P1_subscriber -= 100;
							subscriber_down_time = 200;
						}
						//進んだ方向に「7」があれば、次回ルーレット数2倍
						if (MapData_P[PlayerY + 1][PlayerX] == 7) {
							PlaySoundMem(subscriber_up_sound, DX_PLAYTYPE_BACK, TRUE);//増加音再生
							two_times = true;
							two_times_messagetime = 200;
						}
						//進んだ方向が「7以外」なら、2倍マスフラグをOFFにする
						if (MapData_P[PlayerY + 1][PlayerX] != 7 && two_times == true)
						{
							two_times = false;
						}
					}
					//(主人公マップの)進んだ方向に「9」があれば、ゴール処理
					if (MapData_P[PlayerY + 1][PlayerX] == 9) {
						PlaySoundMem(goal_sound, DX_PLAYTYPE_BACK, TRUE);//効果音再生
						PlaySoundMem(goal_cheers_sound, DX_PLAYTYPE_BACK, TRUE);//効果音再生
						goal_time = 200;
						//順位によって順位ボーナス加算
						if (P1_subscriber > P2_subscriber) {
							P1_subscriber += 10000;
						}
						else if (P2_subscriber > P1_subscriber) {
							P1_subscriber += 5000;
						}
					}
					MapData_P[PlayerY][PlayerX] = 3; //主人公が通った所は通れなくする
					MapData_P[PlayerY + 1][PlayerX] = 2; //通路に主人公を通す
					MoveY = 1.0f; //Y軸方向にスクロール
					P1_UD_flg = 0; //向き切り替え 下
				}
				Move = 1; //スクロール開始
				PlaySoundMem(move_sound, DX_PLAYTYPE_BACK, TRUE);//移動音再生
			}
			
			
			MoveCounter = 0;
		}
		

		//移動中の場合は移動処理を行う
		if (Move == 1) {			
			MoveCounter++;
			if (P1_PlayerMove_Flg == true) {
				//初期化
				P1_PlayerMove_Flg = false;
				squares_cnt1 -= 1;
			}
			//移動処理が終了したら停止中にする
			if (MoveCounter == MOVE_FRAME) {
				if (Branch_flg == true) {
					//初期化
					Move = 0;
					MoveCounter = 0;
					P1_PlayerMove_num--; //移動回数減少
					RouDraw_flg = false; //画像表示再開
				}
				else {
					//分岐設定開始処理
					if (P1_PlayerMove_num > 1) { //移動回数が0以上の時
						P1_PlayerMove_Flg = true; //もう一度移動させる
						MoveCounter = 0;
						P1_PlayerMove_num--; //移動回数減少
					}
					else if (P1_PlayerMove_num == 1) { //移動回数が1の時
						//初期化
						Move = 0;
						P1_PlayerMove_num = 0;
						Roulette = 0; //Roulette 0へ移動
						RouDraw_flg = false; //画像表示再開
					}
				}

				//プレイヤーの位置を変更する
				PlayerX += MoveX;
				PlayerY += MoveY;

				//停止中は画面のスクロールは行わない
				ScrollX = 0;
				ScrollY = 0;

				//移動量初期化
				MoveX = 0.0f;
				MoveY = 0.0f;
			}
			else {
				//経過時間からスクロール量を算出する
				ScrollX = -(MoveX * MAP_SIZE * MoveCounter / MOVE_FRAME);
				ScrollY = -(MoveY * MAP_SIZE * MoveCounter / MOVE_FRAME);
			}
		}

		//ClearDrawScreen(); //画像クリア

		if (RouDraw_flg == false) {
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

		//メッセージウィンドウ画像読み込み
		DrawRectGraphF(
			15, 420,  //描画位置
			0, 0, //切り取り開始位置
			769, 187, //切り取るサイズ
			message_window_img,  //切り取る元画像
			TRUE //透過処理フラグ
		);

		//チャンネル登録者数増加テキスト
		subscriber_up_time--;
		if (subscriber_up_time > 0) {
			DrawFormatString(40, 470, GetColor(50, 255, 255), "チャンネル登録者数増加マス");
			DrawFormatString(40, 500, GetColor(255, 255, 255), "チャンネル登録者数が100人増えた！");
		}
		else{
			subscriber_up_time = 0;
		}

		//チャンネル登録者数減少テキスト
		subscriber_down_time--;
		if (subscriber_down_time > 0) {
			DrawFormatString(40, 470, GetColor(255, 50, 255), "チャンネル登録者数減少マス");
			DrawFormatString(40, 500, GetColor(255, 0, 0), "チャンネル登録者数が100人減った…");
		}
		else {
			subscriber_down_time = 0;
		}

		//2倍マステキスト
		two_times_messagetime--;
		if (two_times_messagetime > 0) {
			DrawFormatString(40, 470, GetColor(50, 255, 255), "2倍マス！");
			DrawFormatString(40, 500, GetColor(255, 255, 255), "次回のルーレットの数が2倍になります");
		}
		else {
			two_times_messagetime = 0;
		}

		//ルーレットスタート指示テキスト
		if (Roulette_Flg == true && Roulette_stop_Flg == false && square_go_Flg == false
			&& square_rest_Flg == true && RouDraw_flg == false && goal_time == 0
			&& subscriber_up_time == 0 && subscriber_down_time == 0 && two_times_messagetime == 0) {
			DrawFormatString(40, 470, GetColor(255, 255, 255), "Enterキーでルーレットスタート");
			if (two_times == true)
			{
				DrawFormatString(40, 505, GetColor(50, 255, 255), "2倍チャンス！");
				DrawFormatString(40, 525, GetColor(255, 255, 255), "ルーレットの出た目×2になります");
			}
		}
		else {
			Roulette_Flg == false;
		}

		//ルーレットストップ指示テキスト
		if (Roulette_stop_Flg == true && subscriber_up_time == 0 && subscriber_down_time == 0
			&& two_times_messagetime == 0) {
			DrawFormatString(40, 470, GetColor(255, 255, 255), "Enterキーでルーレットストップ");
			if (two_times == true)
			{
				DrawFormatString(40, 505, GetColor(50, 255, 255), "2倍チャンス！");
				DrawFormatString(40, 525, GetColor(255, 255, 255), "ルーレットの出た目×2になります");
			}
		}
		else {
			Roulette_stop_Flg == false;
		}

		//コマ進める指示テキスト
		if (square_go_Flg == true && subscriber_up_time == 0 && subscriber_down_time == 0
			&& two_times_messagetime == 0) {
			DrawFormatString(40, 470, GetColor(255, 255, 255), "Enterキーでコマを進める");
			if (two_times == true)
			{
				DrawFormatString(40, 505, GetColor(50, 255, 255), "2倍チャンス！");
				DrawFormatString(40, 525, GetColor(255, 255, 255), "ルーレットの出た目×2になります");
			}
		}
		else {
			square_go_Flg == false;
		}

		//あと何マス テキスト
		if (square_rest_Flg == true && RouDraw_flg == true && goal_time == 0
			&& subscriber_up_time == 0 && subscriber_down_time == 0 && two_times_messagetime == 0) {

			if (P1_PlayerMove_num == 1){
				DrawFormatString(40, 470, GetColor(255, 255, 255), "あと：1マス");
			}
			else if (P1_PlayerMove_num == 2) {
				DrawFormatString(40, 470, GetColor(255, 255, 255), "あと：2マス");
			}
			else if (P1_PlayerMove_num == 3) {
				DrawFormatString(40, 470, GetColor(255, 255, 255), "あと：3マス");
			}
			else if (P1_PlayerMove_num == 4) {
				DrawFormatString(40, 470, GetColor(255, 255, 255), "あと：4マス");
			}
			else if (P1_PlayerMove_num == 5) {
				DrawFormatString(40, 470, GetColor(255, 255, 255), "あと：5マス");
			}
			else if (P1_PlayerMove_num == 6) {
				DrawFormatString(40, 470, GetColor(255, 255, 255), "あと：6マス");
			}
			else if (P1_PlayerMove_num == 7) {
				DrawFormatString(40, 470, GetColor(255, 255, 255), "あと：7マス");
			}
			else if (P1_PlayerMove_num == 8) {
				DrawFormatString(40, 470, GetColor(255, 255, 255), "あと：8マス");
			}
			else if (P1_PlayerMove_num == 9) {
				DrawFormatString(40, 470, GetColor(255, 255, 255), "あと：9マス");
			}
			else if (P1_PlayerMove_num == 10) {
				DrawFormatString(40, 470, GetColor(255, 255, 255), "あと：10マス");
			}
			else if (P1_PlayerMove_num == 11) {
				DrawFormatString(40, 470, GetColor(255, 255, 255), "あと：11マス");
			}
			else if (P1_PlayerMove_num == 12) {
				DrawFormatString(40, 470, GetColor(255, 255, 255), "あと：12マス");
			}
		}
		else {
			square_rest_Flg == false;
		}

		//ゴールテキスト
		goal_time--;
		if (goal_time > 0 && subscriber_up_time == 0 && subscriber_down_time == 0
			&& two_times_messagetime == 0) {
			DrawFormatString(40, 470, GetColor(255, 0, 0), "ゴール！");

			//1位でゴールした場合
			if(P1_subscriber > P2_subscriber){
				DrawFormatString(40, 500, GetColor(255, 255, 0), "順位ボーナス 1位：チャンネル登録者数＋10000人！");
			}
			else if (P2_subscriber > P1_subscriber) {
				DrawFormatString(40, 500, GetColor(255, 255, 0), "順位ボーナス 2位：チャンネル登録者数＋5000人！");
			}
		}
		else {
			goal_time = 0;
		}

		ScreenFlip(); //バックバッファと切り替え

		//例外が発生したらプログラム終了
		if (ProcessMessage() == -1) break;
	}

	DxLib_End(); //dxライブラリ終了処理

	return 0;
}
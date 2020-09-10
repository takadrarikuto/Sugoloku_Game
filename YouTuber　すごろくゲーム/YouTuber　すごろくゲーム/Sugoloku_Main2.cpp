#pragma once
#include "DxLib.h"
#include "Header.h"

#define MAP_SIZE	50 //マップチップ一つのドットサイズ
#define MAP_WIDTH	20 //マップの幅
#define MAP_HEIGHT	20 //マップの縦長さ
#define MOVE_FRAME	50 //移動にかけるフレーム数

#define RECR_MAX 200 //ルーレット切り取り数

bool Player1_DrawFlg = false;
bool Player2_DrawFlg = false;

//モードセレクト
int SelectMode() {
	int mode;

	while (1) {
		ClearDrawScreen();


		DrawString(0, 0, "プレイヤー選択　0:1P　1:2P", GetColor(255, 255, 255));
		mode = KeyInputNumber(0, 16, 1, 0, FALSE);
		if (mode == 0) {
			DrawString(0, 32, "プレイヤーは、1P", GetColor(255, 255, 255));
			Player1_DrawFlg = true;
		}
		else {
			DrawString(0, 32, "プレイヤーは、2P", GetColor(255, 255, 255));
			Player2_DrawFlg = true;
		}
		DrawString(0, 64, "これで良いですか？", GetColor(255, 255, 255));
		DrawString(0, 80, "0...いいえ 1...はい", GetColor(255, 255, 255));
		if (KeyInputNumber(0, 96, 1, 0, FALSE))break;
	}
	return mode;
}

//IP入力
IPDATA IP_set() {
	IPDATA ip;

	while (1)
	{
		ClearDrawScreen();

		DrawString(0, 0, "IP入力(172.17.157.81)", GetColor(255, 255, 255));
		ip.d1 = KeyInputNumber(0, 16, 255, 0, FALSE);
		ip.d2 = KeyInputNumber(0, 16, 255, 0, FALSE);
		ip.d3 = KeyInputNumber(0, 16, 255, 0, FALSE);
		ip.d4 = KeyInputNumber(0, 16, 255, 0, FALSE);
		DrawFormatString(0, 16, GetColor(255, 0, 0),
			"IP:%d:%d:%d:%d",
			ip.d1,
			ip.d2,
			ip.d3,
			ip.d4
		);

		DrawString(0, 32, "これで良いですか？", GetColor(255, 255, 255));
		DrawString(0, 48, "0...いいえ 1...はい", GetColor(255, 255, 255));
		if (KeyInputNumber(0, 64, 1, 0, FALSE))break;
	}
	return ip;
}

/*マップのデータ(20マス×20マス)(0 = 壁、1 = 描画マス、2 = スタート、3 = ゴール
4 = 登録者増加、 5 = 登録者減少、6 = 分岐点、7 = 2倍マス、8 = イベントマス
9 = 逆転マス)(150マス)*/
int MapData[MAP_HEIGHT][MAP_WIDTH] =
{
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 2, 0, 1, 1, 4, 1, 1, 1, 5, 1, 1, 4, 1, 1, 4, 1, 1, 5, 0 },
	{ 0, 1, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
	{ 0, 1, 0, 1, 1, 1, 5, 0, 0, 0, 0, 0, 4, 1, 5, 1, 0, 0, 1, 0 },
	{ 0, 4, 0, 0, 0, 0, 1, 0, 3, 1, 9, 9, 9, 0, 0, 8, 0, 0, 1, 0 },
	{ 0, 5, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 5, 0 },
	{ 0, 1, 1, 1, 1, 7, 5, 0, 4, 1, 1, 4, 5, 5, 4, 5, 0, 0, 1, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
	{ 0, 1, 5, 1, 1, 7, 1, 1, 5, 0, 1, 8, 1, 0, 1, 7, 1, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 5, 5, 5, 0, 4, 0, 1, 0 },
	{ 0, 1, 5, 1, 1, 8, 1, 4, 1, 1, 4, 0, 0, 0, 0, 0, 1, 0, 1, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0 },
	{ 0, 1, 5, 1, 0, 5, 1, 4, 0, 0, 0, 0, 4, 4, 4, 0, 5, 0, 7, 0 },
	{ 0, 4, 0, 1, 0, 1, 0, 1, 0, 5, 1, 1, 1, 0, 1, 8, 1, 0, 1, 0 },
	{ 0, 1, 0, 4, 1, 8, 0, 7, 1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
	{ 0, 1, 0, 1, 4, 4, 4, 4, 5, 1, 4, 1, 4, 4, 1, 5, 1, 0, 1, 0 },
	{ 0, 8, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 4, 5, 0 },
	{ 0, 0, 0, 1, 5, 5, 5, 5, 4, 1, 5, 1, 5, 5, 1, 4, 1, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },

};
/*主人公用のマップのデータ(20マス×20マス)(0 = 壁、1 = 描画マス、2 = 主人公、3 = 通過後マス
4 = 登録者増加、 5 = 登録者減少、 6 = 分岐点 7 = 2倍マス、8 = 分岐点終点(予定)
9 = ゴールマス、10 = イベントマス、11 = 逆転マス 12 = 一方通行マス(左)) (150マス)*/
int MapData_P[MAP_HEIGHT][MAP_WIDTH] =
{
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 2, 0, 1, 1, 4, 1, 1, 1, 5, 1, 1, 4, 1, 1, 4, 1, 1, 5, 0 },
	{ 0, 1, 0,10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
	{ 0, 1, 0, 1, 1, 1, 5, 0, 0, 0, 0, 0, 4, 1, 5, 1, 0, 0, 1, 0 },
	{ 0, 4, 0, 0, 0, 0, 1, 0, 9, 1,11,11,11, 0, 0,10, 0, 0, 1, 0 },
	{ 0, 5, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 5, 0 },
	{ 0, 1, 1, 1, 1, 7, 5, 0, 4, 1, 1, 4, 5, 5, 4, 5, 0, 0, 1, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
	{ 0, 1, 5, 1, 1, 7, 1, 1, 5, 0, 1,10, 1, 0, 1, 7, 1, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 5, 5, 5, 0, 4, 0, 1, 0 },
	{ 0, 1, 5, 1, 1,10, 1, 4, 1, 1, 4, 0, 0, 0, 0, 0, 1, 0, 1, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0 },
	{ 0, 1, 5, 1, 0, 5, 1, 4, 0, 0, 0, 0, 4, 4, 4, 0, 5, 0, 7, 0 },
	{ 0, 4, 0, 1, 0, 1, 0, 1, 0, 5, 1, 1, 1, 0, 1,10, 1, 0, 1, 0 },
	{ 0, 1, 0, 4, 1,10, 0, 7, 1, 4, 0, 0, 0, 0, 0, 0, 0, 0,10, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
	{ 0, 1, 0, 1, 4, 4, 4, 4, 5, 1, 4, 1, 4, 4, 1, 5, 1, 0, 1, 0 },
	{ 0,10,12, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 4, 5, 0 },
	{ 0, 0, 0, 1, 5, 5, 5, 5, 4, 1, 5, 1, 5, 5, 1, 4, 1, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
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
int P1_subscriber = 1000; //1P
int P2_subscriber = 1000; //2P
int P_subscriber = 0; //計算用
int Get_P1_subscriber() { return P1_subscriber; }
int Get_P2_subscriber() { return P2_subscriber; }


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
	static int image2 = LoadGraph("image\\プレイヤー2.png");
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
				if (Player1_DrawFlg == true) { //1Pプレイヤー
					DrawRectGraphF(
						j * MAP_SIZE + ScrollX, i * MAP_SIZE + ScrollY,  //描画位置
						0, 0, //切り取り開始位置
						MAP_SIZE, MAP_SIZE, //切り取るサイズ
						image,  //切り取る元画像
						TRUE //透過処理フラグ
					);
				}
				if (Player2_DrawFlg == true) { //2Pプレイヤー
					DrawRectGraphF(
						j * MAP_SIZE + ScrollX, i * MAP_SIZE + ScrollY,  //描画位置
						0, 0, //切り取り開始位置
						MAP_SIZE, MAP_SIZE, //切り取るサイズ
						image2,  //切り取る元画像
						TRUE //透過処理フラグ
					);
				}
			}
		}
	}

	//チャンネル登録者数個別計算
	if (Player1_DrawFlg == true && P_subscriber != 0) {
		P1_subscriber += P_subscriber;
		P_subscriber = 0;
		//0以下にならない処理
		if (P1_subscriber <= 0) {
			P1_subscriber = 0;
		}
	}
	if (Player2_DrawFlg == true && P_subscriber != 0) {
		P2_subscriber += P_subscriber;
		P_subscriber = 0;
		//0以下にならない処理
		if (P2_subscriber <= 0) {
			P2_subscriber = 0;
		}
	}

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
	int SendPort, RecvPort; //send送る Recv受ける

	//送受信データ処理用
	char StrBuf[256] = { "NULL" };

	SetOutApplicationLogValidFlag(FALSE); //Log.txtを生成しないように設定
	ChangeWindowMode(TRUE); //windowモード
	SetGraphMode(800, 600, 32); //windowサイズ800*600 32bit
	SetAlwaysRunFlag(TRUE); //バックグラウンドでも実行出来るようにする
	SetDoubleStartValidFlag(TRUE); //多重起動の許可
	//SetBackgroundColor(0, 100, 0); //背景色

	int Key, i;
	int ScrollX, ScrollY;
	int MapDrawPointX, MapDrawPointY;		//描画するマップ座標値
	int DrawMapChipNumX, DrawMapChipNumY;	//描画するマップチップの数
	int subscriber_up_time = 0;
	int subscriber_down_time = 0;
	int two_times_messagetime = 0;
	int event_messagetime = 0;
	int goal_time = 0;
	bool Roulette_Flg = false; //ルーレットテキスト用フラグ
	bool Roulette_stop_Flg = false; //ルーレットテキスト用フラグ
	bool square_go_Flg = false; //ルーレットテキスト用フラグ
	bool square_rest_Flg = true; //ルーレットテキスト用フラグ
	bool Event_messagetime_Flg = false; //イベントテキスト用フラグ
	bool Branch_destination_Flg = false; //分岐イベント用フラグ
	bool Goal_sound_Flg1 = false; //ゴール後移動音制御用フラグ

	//初期化
	if (DxLib_Init() == -1) { //DXライブラリ初期化処理
		return -1;				//エラーが起きたら直ちに終了
	}
	if (DxLib_Init() < 0) {
		return -1;
	}

	//モードのセレクト
	int mode = SelectMode();

	//windowの名前
	if (mode == 0) {
		SetWindowText("1P");
		SendPort = 41; //41
		RecvPort = 40; //40
	}
	else {
		SetWindowText("2P");
		SendPort = 40; //40
		RecvPort = 41; //41
	}

	//描画先画面を裏画面にする
	SetDrawScreen(DX_SCREEN_BACK);

	//画像読み込み(「static int」でないと、メモリが増加し続けるので注意)
	static int Rou_image = LoadGraph("image\\スロット枠付き.png");//ルーレット
	static int message_window_img = LoadGraph("image\\メッセージウィンドウ.png");//「9」
	static int back_img1 = LoadGraph("image\\背景（仮）.jpg");

	//BGM再生
	PlaySoundFile("music\\メインBGM.mp3", DX_PLAYTYPE_LOOP);

	int move_sound = 0;
	int roulette_sound = 0;
	int roulette_dec_sound = 0;
	int subscriber_up_sound = 0;
	int subscriber_down_sound = 0;
	int two_times_sound = 0;
	int event_sound = 0;
	int goal_sound = 0;
	int goal_cheers_sound = 0;

	move_sound = LoadSoundMem("music\\コマ移動.mp3");
	roulette_sound = LoadSoundMem("music\\ルーレット.mp3");
	roulette_dec_sound = LoadSoundMem("music\\ルーレット決定.mp3");
	subscriber_up_sound = LoadSoundMem("music\\登録者数増加音.mp3");
	subscriber_down_sound = LoadSoundMem("music\\登録者数減少音.mp3");
	two_times_sound = LoadSoundMem("music\\2倍マス音.mp3");
	event_sound = LoadSoundMem("music\\イベントマス音.mp3");
	goal_sound = LoadSoundMem("music\\ゴール音.mp3");
	goal_cheers_sound = LoadSoundMem("music\\ゴール歓声.mp3");

	//プレイヤーの初期位置をセット
	PlayerX = 1;
	PlayerY = 1;

	//最初は停止中(0)にしておく
	Move = 0;

	//プレイヤー----------------------------------
	//左右向きフラグ
	bool P1_LR_flg = 1/*1Pプレイヤー*/, P2_LR_flg = 1/*2Pプレイヤー*/;
	//上下向きフラグ
	bool P1_UD_flg = 0/*1Pプレイヤー*/, P2_UD_flg = 0/*2Pプレイヤー*/;
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
	bool EventRou_flg2 = false;
	bool EventRou_flg3 = false;
	//分岐設定フラグ
	bool Branch_flg = false;
	//主人公分岐先設定フラグ
	bool P1_PlayerMove_Branch_destination_Up_flg = false; //↑
	bool P1_PlayerMove_Branch_destination_Down_flg = false; //↓
	//スロット変数
	int Rou_num = 0;
	//イベントスロット変数
	int P1_EventRou_num = 0/*1Pプレイヤー*/, P2_EventRou_num = 0/*2Pプレイヤー*/;
	//分岐設定変数 1 = ↑,2 = ↓ 
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
	/*Player1_DrawFlg = false;
	Player2_DrawFlg = false;*/
	//送受信用データ
	char name[15] = "name";
	//Data* data = new Data(x, y, name);

	//IPの設定
	IPDATA IP = IP_set();

	//通信用ソケットハンドル
	int NetUDPHandle = MakeUDPSocket(SendPort);

	//ループ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
		//画面を初期化
		ClearDrawScreen();

		//背景画像読み込み
		DrawRectGraphF(
			0, 50,  //描画位置
			0, 0, //切り取り開始位置
			800, 550, //切り取るサイズ
			back_img1,  //切り取る元画像
			FALSE //透過処理フラグ
		);

		//移動中ではない場合キー入力を受け付ける
		if (Move == 0) {
			//ルーレット処理--------------------------------------------------------------------
			//Enterでルーレット回転スタート(event_messagetimeが0以外の時はキー入力を受け付けない)
			if (CheckHitKey(KEY_INPUT_RETURN) == true && Roulette_Enter_Bottan == false && event_messagetime == 0) {
				if (Roulette == 0) { //ルーレット回転スタート
					Rou_num = 0; //スロット変数初期化
					RouDraw_flg = false; //画像表示再開
					Roulette_Rotation = true; //ルーレット回転開始
					Roulette_stop_Flg = true; //ルーレット回転中テキストオン
					square_rest_Flg = false;
					Event_messagetime_Flg = false;
					Roulette = 1; //Roulette 1へ移動
					PlaySoundMem(roulette_sound, DX_PLAYTYPE_LOOP, TRUE);//効果音再生
					//イベント終了処理
					if (EventRou_flg3 == true) {
						EventRou_flg = false;
						EventRou_flg3 = false;
					}
				}
				else if (Roulette == 1) { //ルーレット停止
					Roulette_Rotation = false; //初期化
					Roulette_stop_Flg = false; //ルーレット回転中テキストオフ
					square_go_Flg = true; //コマ進めるテキストオン
					Roulette = 2; //Roulette 2へ移動
					StopSoundMem(roulette_sound);
					PlaySoundMem(roulette_dec_sound, DX_PLAYTYPE_BACK, TRUE);//効果音再生
				}
				else if (Roulette == 2) { //ルーレット表示停止、移動開始
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
			if (Branch_flg == true && Roulette == 2 && Branch_num == 0) {
				//分岐処理
				if (Rou_num > 3) {
					Branch_num = 1; //分岐設定 1 = ↑
				}
				else if (Rou_num > 0 && Rou_num <= 3) {
					Branch_num = 2; //分岐設定 2 = ↓
				}
			}
			//イベントスロット判定処理
			else if (EventRou_flg == true && Roulette == 2) {
				P1_EventRou_num = Rou_num; //イベントスロット
				//EventRou_flg = false; //イベントスロットフラグ初期化
			}
			//マス移動処理
			else if (Branch_flg == false && EventRou_flg == false && Roulette == 0) {
				P1_PlayerMove_num = Rou_num; //マス移動 デバック3固定
				//2倍マスフラグがONなら2倍にする
				if (two_times == true) {
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
		//進入不可能なマップ・イベント発生中・逆転マス発生中の場合は移動できない
		if (P1_PlayerMove_Flg == true && EventRou_flg == false) {

			//分岐判定処理
			if (Branch_num > 0) {
				if (P1_PlayerMove_num > 0) { //分岐マスを通過する時
					if (Branch_num == 1) { //上
						P1_PlayerMove_Branch_destination_Down_flg = true; //主人公分岐先設定フラグTrue ↓
					}
					else if (Branch_num == 2) { //下
						P1_PlayerMove_Branch_destination_Up_flg = true; //主人公分岐先設定フラグTrue ↑
					}
					Branch_num = 0; //初期化
					Branch_flg = false; //分岐設定初期化
					Branch_destination_Flg = false; //初期化
				}
				else { //分岐マスで停止した時
					Branch_flg = false; //分岐設定初期化
					P1_PlayerMove_Flg = false;
					Branch_destination_Flg = false; //初期化
				}
			}

			if (P1_PlayerMove_num > 0) {
				//0 = 壁には移動できない
				if (MapData_P[PlayerY + MoveY][PlayerX + MoveX] == 0)
				{

					//0には何もしない
				}
				else {
					//主人公の周りにある道を確認して移動する
					if (MapData_P[PlayerY][PlayerX] == 2 && (MapData_P[PlayerY][PlayerX + 1] == 1 ||
						MapData_P[PlayerY][PlayerX + 1] >= 4 && MapData_P[PlayerY][PlayerX + 1] != 12)) {//右移動
						//移動回数が1の時
						if (P1_PlayerMove_num == 1) {
							//進んだ方向に「4」があれば、登録者数増加
							if (MapData_P[PlayerY][PlayerX + 1] == 4) {
								PlaySoundMem(subscriber_up_sound, DX_PLAYTYPE_BACK, TRUE);//増加音再生
								P_subscriber += 100;
								subscriber_up_time = 200;
							}
							//進んだ方向に「5」があれば、登録者数減少
							if (MapData_P[PlayerY][PlayerX + 1] == 5) {
								PlaySoundMem(subscriber_down_sound, DX_PLAYTYPE_BACK, TRUE);//減少音再生
								P_subscriber -= 100;
								subscriber_down_time = 200;
							}
							//進んだ方向に「7」があれば、次回ルーレット数2倍
							if (MapData_P[PlayerY][PlayerX + 1] == 7) {
								PlaySoundMem(two_times_sound, DX_PLAYTYPE_BACK, TRUE);//2倍マス音再生
								two_times = true;
								two_times_messagetime = 200;
							}
							//進んだ方向が「7以外」なら、2倍マスフラグをOFFにする
							if (MapData_P[PlayerY][PlayerX + 1] != 7 && two_times == true)
							{
								two_times = false;
							}
							//進んだ方向に「10」があれば、イベント発生
							if (MapData_P[PlayerY][PlayerX + 1] == 10) {
								PlaySoundMem(event_sound, DX_PLAYTYPE_BACK, TRUE);//マス音再生
								Event_messagetime_Flg = true;
								EventRou_flg = true;
								EventRou_flg2 = true;
							}
							//進んだ方向に「11」があれば、逆転マス発生（仮）
							if (MapData_P[PlayerY][PlayerX + 1] == 11) {
								PlaySoundMem(subscriber_up_sound, DX_PLAYTYPE_BACK, TRUE);//音再生(確認用)
							}
						}
						//進んだ方向に「6」があれば、分岐処理
						if (MapData_P[PlayerY][PlayerX + 1] == 6) {
							Branch_flg = true;  //分岐イベント発生
							Branch_destination_Flg = true; //分岐イベントテキスト表示
						}
						//(主人公マップの)進んだ方向に「9」があれば、ゴール処理
						if (MapData_P[PlayerY][PlayerX + 1] == 9) {
							PlaySoundMem(goal_sound, DX_PLAYTYPE_BACK, TRUE);//効果音再生
							PlaySoundMem(goal_cheers_sound, DX_PLAYTYPE_BACK, TRUE);//効果音再生
							goal_time = 200;
							Goal_sound_Flg1 = true;
							//順位によって順位ボーナス加算
							if (P1_subscriber > P2_subscriber) {
								P_subscriber += 10000; //1位 +10000人
							}
							else if (P2_subscriber > P1_subscriber) {
								P_subscriber += 5000; //2位 +5000人
							}
						}
						MapData_P[PlayerY][PlayerX] = 3; //主人公が通った所は通れなくする
						MapData_P[PlayerY][PlayerX + 1] = 2; //通路に主人公を通す
						MoveX = 1.0f; //X軸方向にスクロール
						P1_LR_flg = 1; //向き切り替え 右
					}
					else if (MapData_P[PlayerY][PlayerX] == 2 && (MapData_P[PlayerY][PlayerX - 1] == 1 || MapData_P[PlayerY][PlayerX - 1] >= 4)) {//左移動
						//移動回数が1の時
						if (P1_PlayerMove_num == 1) {
							//進んだ方向に「4」があれば、登録者数増加
							if (MapData_P[PlayerY][PlayerX - 1] == 4) {
								PlaySoundMem(subscriber_up_sound, DX_PLAYTYPE_BACK, TRUE);//増加音再生
								P_subscriber += 100;
								subscriber_up_time = 200;
							}
							//進んだ方向に「5」があれば、登録者数減少
							if (MapData_P[PlayerY][PlayerX - 1] == 5) {
								PlaySoundMem(subscriber_down_sound, DX_PLAYTYPE_BACK, TRUE);//減少音再生
								P_subscriber -= 100;
								subscriber_down_time = 200;
							}
							//進んだ方向に「7」があれば、次回ルーレット数2倍
							if (MapData_P[PlayerY][PlayerX - 1] == 7) {
								PlaySoundMem(two_times_sound, DX_PLAYTYPE_BACK, TRUE);//2倍マス音再生
								two_times = true;
								two_times_messagetime = 200;
							}
							//進んだ方向が「7以外」なら、2倍マスフラグをOFFにする
							if (MapData_P[PlayerY][PlayerX - 1] != 7 && two_times == true)
							{
								two_times = false;
							}
							//進んだ方向に「10」があれば、イベント発生
							if (MapData_P[PlayerY][PlayerX - 1] == 10) {
								PlaySoundMem(event_sound, DX_PLAYTYPE_BACK, TRUE);//マス音再生
								Event_messagetime_Flg = true;
								EventRou_flg = true;
								EventRou_flg2 = true;
							}
							//進んだ方向に「11」があれば、逆転マス発生（仮）
							if (MapData_P[PlayerY][PlayerX - 1] == 11) {
								PlaySoundMem(subscriber_up_sound, DX_PLAYTYPE_BACK, TRUE);//音再生(確認用)
							}
						}
						//進んだ方向に「6」があれば、分岐処理
						if (MapData_P[PlayerY][PlayerX - 1] == 6) {
							Branch_flg = true;  //分岐イベント発生
							Branch_destination_Flg = true; //分岐イベントテキスト表示
						}
						//(主人公マップの)進んだ方向に「9」があれば、ゴール処理
						if (MapData_P[PlayerY][PlayerX - 1] == 9) {
							PlaySoundMem(goal_sound, DX_PLAYTYPE_BACK, TRUE);//効果音再生
							PlaySoundMem(goal_cheers_sound, DX_PLAYTYPE_BACK, TRUE);//効果音再生
							goal_time = 200;
							Goal_sound_Flg1 = true;
							//順位によって順位ボーナス加算
							if (P1_subscriber > P2_subscriber) {
								P_subscriber += 10000;
							}
							else if (P2_subscriber > P1_subscriber) {
								P_subscriber += 5000;
							}
						}
						MapData_P[PlayerY][PlayerX] = 3; //主人公が通った所は通れなくする
						MapData_P[PlayerY][PlayerX - 1] = 2; //通路に主人公を通す
						MoveX = -1.0f; //-X軸方向にスクロール
						P1_LR_flg = 0; //向き切り替え 左
					}
					else if (MapData_P[PlayerY][PlayerX] == 2 && P1_PlayerMove_Branch_destination_Up_flg == false && 
							(MapData_P[PlayerY - 1][PlayerX] == 1 ||  MapData_P[PlayerY - 1][PlayerX] >= 4 &&
							 MapData_P[PlayerY - 1][PlayerX] != 12)) {//上移動
						//移動回数が1の時
						if (P1_PlayerMove_num == 1) {
							//進んだ方向に「4」があれば、登録者数増加
							if (MapData_P[PlayerY - 1][PlayerX] == 4) {
								PlaySoundMem(subscriber_up_sound, DX_PLAYTYPE_BACK, TRUE);//増加音再生
								P_subscriber += 100;
								subscriber_up_time = 200;
							}
							//進んだ方向に「5」があれば、登録者数減少
							if (MapData_P[PlayerY - 1][PlayerX] == 5) {
								PlaySoundMem(subscriber_down_sound, DX_PLAYTYPE_BACK, TRUE);//減少音再生
								P_subscriber -= 100;
								subscriber_down_time = 200;
							}
							//進んだ方向に「7」があれば、次回ルーレット数2倍
							if (MapData_P[PlayerY - 1][PlayerX] == 7) {
								PlaySoundMem(two_times_sound, DX_PLAYTYPE_BACK, TRUE);//2倍マス音再生
								two_times = true;
								two_times_messagetime = 200;
							}
							//進んだ方向が「7以外」なら、2倍マスフラグをOFFにする
							if (MapData_P[PlayerY - 1][PlayerX] != 7 && two_times == true)
							{
								two_times = false;
							}
							//進んだ方向に「10」があれば、イベント発生
							if (MapData_P[PlayerY - 1][PlayerX] == 10) {
								PlaySoundMem(event_sound, DX_PLAYTYPE_BACK, TRUE);//マス音再生
								Event_messagetime_Flg = true;
								EventRou_flg = true;
								EventRou_flg2 = true;
							}
							//進んだ方向に「11」があれば、逆転マス発生（仮）
							if (MapData_P[PlayerY - 1][PlayerX] == 11) {
								PlaySoundMem(subscriber_up_sound, DX_PLAYTYPE_BACK, TRUE);//音再生(確認用)
							}
						}
						//進んだ方向に「6」があれば、分岐処理
						if (MapData_P[PlayerY - 1][PlayerX] == 6) {
							Branch_flg = true;  //分岐イベント発生
							Branch_destination_Flg = true; //分岐イベントテキスト表示
						}
						//(主人公マップの)進んだ方向に「9」があれば、ゴール処理
						if (MapData_P[PlayerY - 1][PlayerX] == 9) {
							PlaySoundMem(goal_sound, DX_PLAYTYPE_BACK, TRUE);//効果音再生
							PlaySoundMem(goal_cheers_sound, DX_PLAYTYPE_BACK, TRUE);//効果音再生
							goal_time = 200;
							Goal_sound_Flg1 = true;
							//順位によって順位ボーナス加算
							if (P1_subscriber > P2_subscriber) {
								P_subscriber += 10000;
							}
							else if (P2_subscriber > P1_subscriber) {
								P_subscriber += 5000;
							}
						}
						MapData_P[PlayerY][PlayerX] = 3; //主人公が通った所は通れなくする
						MapData_P[PlayerY - 1][PlayerX] = 2; //通路に主人公を通す
						MoveY = -1.0f; //-Y軸方向にスクロール
						P1_UD_flg = 1; //向き切り替え 上
					}
					else if (MapData_P[PlayerY][PlayerX] == 2 && P1_PlayerMove_Branch_destination_Down_flg == false && 
							(MapData_P[PlayerY + 1][PlayerX] == 1 ||  MapData_P[PlayerY + 1][PlayerX] >= 4 &&
							 MapData_P[PlayerY + 1][PlayerX] != 12)) {//下移動
						//移動回数が1の時
						if (P1_PlayerMove_num == 1) {
							//進んだ方向に「4」があれば、登録者数増加
							if (MapData_P[PlayerY + 1][PlayerX] == 4) {
								PlaySoundMem(subscriber_up_sound, DX_PLAYTYPE_BACK, TRUE);//増加音再生
								P_subscriber += 100;
								subscriber_up_time = 200;
							}
							//進んだ方向に「5」があれば、登録者数減少
							if (MapData_P[PlayerY + 1][PlayerX] == 5) {
								PlaySoundMem(subscriber_down_sound, DX_PLAYTYPE_BACK, TRUE);//減少音再生
								P_subscriber -= 100;
								subscriber_down_time = 200;
							}
							
							//進んだ方向に「7」があれば、次回ルーレット数2倍
							if (MapData_P[PlayerY + 1][PlayerX] == 7) {
								PlaySoundMem(two_times_sound, DX_PLAYTYPE_BACK, TRUE);//2倍マス音再生
								two_times = true;
								two_times_messagetime = 200;
							}
							//進んだ方向が「7以外」なら、2倍マスフラグをOFFにする
							if (MapData_P[PlayerY + 1][PlayerX] != 7 && two_times == true){
								two_times = false;
							}
							//進んだ方向に「10」があれば、イベント発生
							if (MapData_P[PlayerY + 1][PlayerX] == 10) {
								PlaySoundMem(event_sound, DX_PLAYTYPE_BACK, TRUE);//マス音再生
								Event_messagetime_Flg = true;
								EventRou_flg = true;
								EventRou_flg2 = true;
							}
							//進んだ方向に「11」があれば、逆転マス発生（仮）
							if (MapData_P[PlayerY + 1][PlayerX] == 11) {
								PlaySoundMem(subscriber_up_sound, DX_PLAYTYPE_BACK, TRUE);//音再生(確認用)
							}
						}
						//進んだ方向に「6」があれば、分岐処理
						if (MapData_P[PlayerY + 1][PlayerX] == 6) {
							Branch_flg = true;  //分岐イベント発生
							Branch_destination_Flg = true; //分岐イベントテキスト表示
						}
						//(主人公マップの)進んだ方向に「9」があれば、ゴール処理
						if (MapData_P[PlayerY + 1][PlayerX] == 9) {
							PlaySoundMem(goal_sound, DX_PLAYTYPE_BACK, TRUE);//効果音再生
							PlaySoundMem(goal_cheers_sound, DX_PLAYTYPE_BACK, TRUE);//効果音再生
							goal_time = 200;
							Goal_sound_Flg1 = true;
							//順位によって順位ボーナス加算
							if (P1_subscriber > P2_subscriber) {
								P_subscriber += 10000;
							}
							else if (P2_subscriber > P1_subscriber) {
								P_subscriber += 5000;
							}
						}
						MapData_P[PlayerY][PlayerX] = 3; //主人公が通った所は通れなくする
						MapData_P[PlayerY + 1][PlayerX] = 2; //通路に主人公を通す
						MoveY = 1.0f; //Y軸方向にスクロール
						P1_UD_flg = 0; //向き切り替え 下
					}
					Move = 1; //スクロール開始
					if (Goal_sound_Flg1 == false) {
						PlaySoundMem(move_sound, DX_PLAYTYPE_BACK, TRUE);//移動音再生
					}
				}
			}
			
			MoveCounter = 0;
		}

				//移動中の場合は移動処理を行う
				if (Move == 1) {
					MoveCounter++;
					if (P1_PlayerMove_Flg == true) {
						//初期化
						P1_PlayerMove_Flg = false;
						//マスカウント(あと何マス)が0以上の時のみマスカウントを減らす
						if (squares_cnt1 > 0) {
							squares_cnt1 -= 1;
						}
					}
					//移動処理が終了したら停止中にする
					if (MoveCounter == MOVE_FRAME) {
						//分岐設定開始処理
						if (Branch_flg == true) {
							//初期化
							Move = 0;
							MoveCounter = 0;
							P1_PlayerMove_num--; //移動回数減少
							RouDraw_flg = false; //画像表示再開
						}
						else {
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

						//主人公分岐先設定フラグ初期化
						if (P1_PlayerMove_Branch_destination_Up_flg == true) {
							P1_PlayerMove_Branch_destination_Up_flg = false; //主人公分岐先設定フラグTrue ↑
						}
						else if (P1_PlayerMove_Branch_destination_Down_flg == true) {
							P1_PlayerMove_Branch_destination_Down_flg = false; //主人公分岐先設定フラグTrue ↓
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

				//マップとプレイヤーを描画
				GraphDraw(ScrollX, ScrollY);

				//ルーレット表示停止処理
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
				else {
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
				//イベントマステキスト
				if (Event_messagetime_Flg == true) {
					DrawFormatString(40, 470, GetColor(50, 255, 255), "イベントマス！");
					DrawFormatString(40, 500, GetColor(255, 255, 255), "ルーレットの目が、1～3ならチャンネル登録者数増加、4～6ならチャンネル登録者数減少");
					DrawFormatString(40, 530, GetColor(255, 255, 255), "Enterキーでルーレットスタート");
				}
				else {
					Event_messagetime_Flg = false;
				}

				//分岐イベントテキスト表示
				if (Branch_destination_Flg == true) {
					if (Roulette == 0) {
						DrawFormatString(40, 470, GetColor(255, 255, 255), "Enterキーでルーレットスタート");
						DrawFormatString(40, 505, GetColor(50, 255, 255), "分岐イベント発生");
						DrawFormatString(40, 525, GetColor(255, 255, 255), "移動先を決めよう");
					}
					else if (Roulette == 2) {
						//分岐先表示描画
						if (Branch_num == 1) { //上
							DrawFormatString(40, 500, GetColor(50, 255, 255), "移動先 : 上");
						}
						else if (Branch_num == 2) { //下
							DrawFormatString(40, 500, GetColor(50, 255, 255), "移動先 : 下");
						}
					}
				}

				//ルーレットスタート指示テキスト
				if (Roulette_Flg == true && Roulette_stop_Flg == false && square_go_Flg == false
					&& square_rest_Flg == true && RouDraw_flg == false && goal_time == 0
					&& subscriber_up_time == 0 && subscriber_down_time == 0 && two_times_messagetime == 0
					&& Event_messagetime_Flg == false && Branch_flg == false) {
					DrawFormatString(40, 470, GetColor(255, 255, 255), "Enterキーでルーレットスタート");
					if (two_times == true) {
						DrawFormatString(40, 505, GetColor(50, 255, 255), "2倍チャンス！");
						DrawFormatString(40, 525, GetColor(255, 255, 255), "ルーレットの出た目×2になります");
					}
				}
				else {
					Roulette_Flg == false;
				}

				//ルーレットストップ指示テキスト
				if (Roulette_stop_Flg == true && subscriber_up_time == 0 && subscriber_down_time == 0
					&& two_times_messagetime == 0 && Event_messagetime_Flg == false) {
					DrawFormatString(40, 470, GetColor(255, 255, 255), "Enterキーでルーレットストップ");
					if (two_times == true) {
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
					if (EventRou_flg == false && event_messagetime == 0) {
						DrawFormatString(40, 470, GetColor(255, 255, 255), "Enterキーでコマを進める");
					}
					else if (event_messagetime == 0) {
						DrawFormatString(40, 470, GetColor(255, 255, 255), "Enterキーを押してください");
						EventRou_flg3 = true;
					}

			if (two_times == true){
				DrawFormatString(40, 505, GetColor(50, 255, 255), "2倍チャンス！");
				DrawFormatString(40, 525, GetColor(255, 255, 255), "ルーレットの出た目×2になります");
			}
			//イベント発生中でルーレットの目が1～3の場合、チャンネル登録者数増加
			if (EventRou_flg2 == true && P1_EventRou_num <= 3){
				PlaySoundMem(subscriber_up_sound, DX_PLAYTYPE_BACK, TRUE);//増加音再生
				P_subscriber += 500;//+500人
				event_messagetime = 200;
				EventRou_flg2 = false;
			}
			//イベント発生中でルーレットの目が4～6の場合、チャンネル登録者数増減少
			else if (EventRou_flg2 == true && P1_EventRou_num >= 4){
				PlaySoundMem(subscriber_down_sound, DX_PLAYTYPE_BACK, TRUE);//減少音再生
				P_subscriber -= 500; //-500人
				event_messagetime = 200;
				EventRou_flg2 = false;
			}
			//イベント用チャンネル登録者数増減テキスト
			event_messagetime --;
			if (P1_EventRou_num <= 3 && event_messagetime > 0) {
				DrawFormatString(40, 470, GetColor(50, 255, 255), "チャンネル登録者数増加！");
				DrawFormatString(40, 500, GetColor(255, 255, 255), "チャンネル登録者数が500人増えた！");
			}
			else if (P1_EventRou_num >= 4 && event_messagetime > 0) {
				DrawFormatString(40, 470, GetColor(255, 50, 255), "チャンネル登録者数減少…");
				DrawFormatString(40, 500, GetColor(255, 0, 0), "チャンネル登録者数が500人減った…");
			}
			else {
				event_messagetime = 0;
			}
		}
		else {
			square_go_Flg = false;
		}

				//あと何マス テキスト
				if (square_rest_Flg == true && RouDraw_flg == true && goal_time == 0
					&& subscriber_up_time == 0 && subscriber_down_time == 0 && two_times_messagetime == 0
					&& Event_messagetime_Flg == false && Branch_destination_Flg == false) {

					if (P1_PlayerMove_num == 1) {
						DrawFormatString(40, 470, GetColor(255, 255, 255), "マス到着");
					}
					else if (P1_PlayerMove_num >= 2) {
						DrawFormatString(40, 470, GetColor(255, 255, 255), "あと：%dマス", P1_PlayerMove_num - 1);
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
					if (P1_subscriber > P2_subscriber) {
						DrawFormatString(40, 500, GetColor(255, 255, 0), "順位ボーナス 1位：チャンネル登録者数＋10000人！");
					}
					else if (P2_subscriber > P1_subscriber) {
						DrawFormatString(40, 500, GetColor(255, 255, 0), "順位ボーナス 2位：チャンネル登録者数＋5000人！");
					}
				}
				else {
					goal_time = 0;
				}

				//デバッグ用ルーレット数字確認
				DrawFormatString(0, 50, GetColor(0, 150, 0), "【デバッグ用】ルーレット数字：%d", Rou_num);
				//デバッグ用イベントルーレット数字確認
				DrawFormatString(0, 70, GetColor(0, 150, 0), "【デバッグ用】イベントルーレット数字：%d", P1_EventRou_num);
				//デバッグ用進むマス数確認
				DrawFormatString(0, 90, GetColor(0, 150, 0), "【デバッグ用】進むマス数：%d", P1_PlayerMove_num);

		ScreenFlip(); //バックバッファと切り替え

		//例外が発生したらプログラム終了
		if (ProcessMessage() == -1) break;
	}

	DxLib_End(); //dxライブラリ終了処理

	return 0;
}
		
	
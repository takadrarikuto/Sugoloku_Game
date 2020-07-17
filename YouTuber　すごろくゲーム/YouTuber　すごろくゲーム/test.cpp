// マップスクロール基本
#include "DxLib.h"

#define MAP_SIZE	64			// マップチップ一つのドットサイズ
#define MAP_WIDTH	20			// マップの幅
#define MAP_HEIGHT	16			// マップの縦長さ
#define MOVE_FRAME	32			// 移動にかけるフレーム数

// マップのデータ
int MapData[MAP_HEIGHT][MAP_WIDTH] =
{
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } ,
	{ 0, 1, 1, 0, 0, 0, 0, 0, 0, 0 ,  1, 1, 1, 1, 1, 1, 1, 1, 1, 0 } ,
	{ 0, 0, 1, 1, 1, 0, 0, 0, 0, 0 ,  1, 0, 0, 0, 0, 0, 0, 0, 1, 0 } ,
	{ 0, 0, 1, 0, 1, 0, 0, 0, 0, 0 ,  1, 1, 1, 1, 1, 1, 0, 0, 1, 0 } ,
	{ 0, 1, 1, 0, 1, 0, 0, 1, 1, 0 ,  0, 0, 0, 0, 0, 1, 0, 0, 1, 0 } ,
	{ 0, 1, 0, 0, 1, 0, 0, 1, 1, 0 ,  0, 0, 1, 1, 1, 1, 1, 0, 1, 0 } ,
	{ 0, 1, 0, 0, 1, 0, 0, 1, 1, 0 ,  0, 0, 1, 0, 0, 1, 1, 0, 1, 0 } ,
	{ 0, 1, 0, 0, 1, 0, 0, 1, 1, 0 ,  0, 0, 1, 0, 0, 1, 1, 0, 1, 0 } ,

	{ 0, 1, 1, 1, 1, 1, 1, 1, 1, 0 ,  0, 1, 1, 0, 0, 1, 1, 0, 1, 0 } ,
	{ 0, 0, 0, 0, 1, 0, 0, 1, 0, 0 ,  0, 1, 1, 0, 0, 1, 1, 0, 1, 0 } ,
	{ 0, 0, 0, 0, 1, 0, 0, 1, 0, 0 ,  0, 1, 1, 0, 0, 1, 1, 0, 1, 0 } ,
	{ 0, 0, 0, 1, 1, 0, 0, 1, 0, 0 ,  0, 1, 1, 0, 0, 1, 1, 0, 1, 0 } ,
	{ 0, 1, 1, 1, 1, 0, 0, 1, 1, 1 ,  1, 1, 1, 0, 0, 1, 1, 0, 1, 0 } ,
	{ 0, 1, 1, 1, 1, 0, 0, 0, 0, 0 ,  0, 0, 0, 0, 0, 0, 0, 0, 1, 0 } ,
	{ 0, 1, 1, 1, 1, 0, 0, 0, 0, 0 ,  0, 0, 0, 0, 0, 0, 0, 0, 1, 0 } ,
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } ,
};

// プレイヤーの位置
int PlayerX, PlayerY;
// 移動しているかどうかのフラグ( 0:停止中  1:移動中 )
int Move;
// 各方向に移動する量
int MoveX, MoveY;
// 移動し始めてから何フレーム経過したかを保持する変数
int MoveCounter;

// マップとプレイヤーの描画関数
void GraphDraw(int ScrollX, int ScrollY)
{
	int j, i;
	int MapDrawPointX, MapDrawPointY;		// 描画するマップ座標値
	int DrawMapChipNumX, DrawMapChipNumY;	// 描画するマップチップの数

	// 描画するマップチップの数をセット
	DrawMapChipNumX = 640 / MAP_SIZE + 2;
	DrawMapChipNumY = 480 / MAP_SIZE + 2;

	// 画面左上に描画するマップ座標をセット
	MapDrawPointX = PlayerX - (DrawMapChipNumX / 2 - 1);
	MapDrawPointY = PlayerY - (DrawMapChipNumY / 2 - 1);

	// マップを描く
	for (i = -1; i < DrawMapChipNumY; i++)
	{
		for (j = -1; j < DrawMapChipNumX; j++)
		{
			// 画面からはみ出た位置なら描画しない
			if (j + MapDrawPointX < 0 || i + MapDrawPointY < 0 ||
				j + MapDrawPointX >= MAP_WIDTH || i + MapDrawPointY >= MAP_HEIGHT) continue;

			// マップデータが０だったら四角を描画する
			if (MapData[i + MapDrawPointY][j + MapDrawPointX] == 0)
			{
				DrawBox(j * MAP_SIZE + ScrollX, i * MAP_SIZE + ScrollY,
					j * MAP_SIZE + MAP_SIZE + ScrollX, i * MAP_SIZE + MAP_SIZE + ScrollY,
					GetColor(255, 0, 0), TRUE);
			}
		}
	}

	// プレイヤーの描画
	DrawBox((PlayerX - MapDrawPointX) * MAP_SIZE, (PlayerY - MapDrawPointY) * MAP_SIZE,
		(PlayerX - MapDrawPointX + 1) * MAP_SIZE, (PlayerY - MapDrawPointY + 1) * MAP_SIZE,
		GetColor(255, 255, 255), TRUE);
}

// ＷｉｎＭａｉｎ関数
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	int Key;
	int ScrollX, ScrollY;

	ChangeWindowMode(TRUE); //windowモード
	SetGraphMode(640, 480, 32);
	if (DxLib_Init() == -1)	// ＤＸライブラリ初期化処理
	{
		return -1;				// エラーが起きたら直ちに終了
	}

	// 描画先画面を裏画面にする
	SetDrawScreen(DX_SCREEN_BACK);

	// プレイヤーの初期位置をセット
	PlayerX = 2;
	PlayerY = 2;

	// 最初は停止中(0)にしておく
	Move = 0;

	// ループ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		// 画面を初期化
		ClearDrawScreen();

		// 移動中ではない場合キー入力を受け付ける
		if (Move == 0)
		{
			// キー入力を得る
			Key = GetJoypadInputState(DX_INPUT_KEY_PAD1);

			// キー入力に応じてプレイヤーの座標を移動
			if (Key & PAD_INPUT_LEFT)
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
			}

			// 進入不可能なマップだった場合は移動できない
			if (Move == 1)
			{
				if (MapData[PlayerY + MoveY][PlayerX + MoveX] == 0)
				{
					Move = 0;
				}
				else
				{
					MoveCounter = 0;
				}
			}

			// 停止中は画面のスクロールは行わない
			ScrollX = 0;
			ScrollY = 0;
		}

		// 移動中の場合は移動処理を行う
		if (Move == 1)
		{
			MoveCounter++;

			// 移動処理が終了したら停止中にする
			if (MoveCounter == MOVE_FRAME)
			{
				Move = 0;

				// プレイヤーの位置を変更する
				PlayerX += MoveX;
				PlayerY += MoveY;

				// 停止中は画面のスクロールは行わない
				ScrollX = 0;
				ScrollY = 0;
			}
			else
			{
				// 経過時間からスクロール量を算出する
				ScrollX = -(MoveX * MAP_SIZE * MoveCounter / MOVE_FRAME);
				ScrollY = -(MoveY * MAP_SIZE * MoveCounter / MOVE_FRAME);
			}
		}

		// マップとプレイヤーを描画
		GraphDraw(ScrollX, ScrollY);

		// 裏画面の内容を表画面に映す
		ScreenFlip();
	}

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;					// ソフトの終了
}
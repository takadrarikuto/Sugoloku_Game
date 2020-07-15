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
	SetGraphMode(640, 480, 32); //windowサイズ640*480 32bit
	SetOutApplicationLogValidFlag(FALSE); //Log.txtを生成しないように設定
	SetAlwaysRunFlag(TRUE); //バックグラウンドでも実行出来るようにする
	SetDoubleStartValidFlag(TRUE); //多重起動の許可

	//初期化
	if (DxLib_Init() == -1)return -1; //エラーが出たら終了
	//モードのセレクト
	int mode = SelectMode();

	//windowの名前
	if (mode == 0) {
		SetWindowText("スタート側"); //ウィンドウ名
		Sendport = 41;
		RecvPort = 40;
	}
	else
	{
		SetWindowText("待ち受け側"); //ウィンドウ名
		Sendport = 40;
		RecvPort = 41;
	}

	SetDrawScreen(DX_SCREEN_BACK);

	//画像読み込み
	int image = LoadGraph("image\\Frisk.png");
	//画像の位置情報
	float x, y;
	//初期化 
	x = 0.0f;
	y = 0.0f;

	//送受信用データ
	char name[15] = "name";
	Data* data = new Data(x, y, name);

	//IPの設定
	IPDATA IP = IP_set();

	//通信用ソケットハンドル
	int NetUDPHandle = MakeUDPSocket(Sendport);

	while (CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		if (ProcessMessage() == -1) break;

		if (mode == 0)
		{
			//移動処理
			if (CheckHitKey(KEY_INPUT_UP)) y -= 4.0f;
			if (CheckHitKey(KEY_INPUT_DOWN)) y += 4.0f;
			if (CheckHitKey(KEY_INPUT_RIGHT)) x += 4.0f;
			if (CheckHitKey(KEY_INPUT_LEFT)) x -= 4.0f;

			//データ変換
			//sprintf_s(StrBuf, "%f", x); //文字列に変換

			//送受信データの更新
			data->pos.x = x;
			data->pos.y = y;

			//データの送信
			NetWorkSendUDP(NetUDPHandle, IP, RecvPort, data, 256);
		}

		if (mode == 1) {
			//データの受信
			if (CheckNetWorkRecvUDP(NetUDPHandle) == TRUE) {
				NetWorkRecvUDP(NetUDPHandle, NULL, NULL, StrBuf, 256, FALSE);
				//受信データ変換
				memcpy_s(data, sizeof(Data), StrBuf, sizeof(Data));
				x = data->pos.x;
				y = data->pos.y;

				//x = atof(StrBuf); //付け取ったデータをfloatに変換
				//DrawFormatString(0, 16, GetColor(255, 0, 0),"%s", StrBuf);
			}
		}
		ClearDrawScreen(); //画像クリア
		//描画処理
		DrawGraphF(x, y, image, TRUE);
		ScreenFlip(); //バックバッファと切り替え
	}
	delete data; //送受信データの削除

	WaitKey();

	DeleteUDPSocket(NetUDPHandle); //ハンドルの削除
	DxLib_End(); //dxライブラリ終了処理


	return 0;
}
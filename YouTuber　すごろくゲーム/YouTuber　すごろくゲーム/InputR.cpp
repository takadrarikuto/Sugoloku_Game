#include "Header.h"

//モードセレクト
int SelectMode() {
	int mode;

	while (1) {
		ClearDrawScreen();

		DrawString(0, 0, "すごろくゲーム", GetColor(255, 255, 255));
		DrawString(0, 16, "プレイヤー選択　０:1P　１:2P", GetColor(255, 255, 255));
		mode = KeyInputNumber(0, 32, 1, 0, FALSE);
		if (mode == 0) {
			DrawString(0, 48, "プレイヤーは、1P", GetColor(255, 255, 255));
		}
		else  {
			DrawString(0, 48, "プレイヤーは、2P", GetColor(255, 255, 255));
		}
		DrawString(0, 80, "これで良いですか？", GetColor(255, 255, 255));
		DrawString(0, 96, "0...いいえ 1...はい", GetColor(255, 255, 255));
		if (KeyInputNumber(0, 112, 1, 0, FALSE))break;
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
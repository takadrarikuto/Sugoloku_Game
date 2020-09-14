#pragma once
#include "DxLib.h"
#include <string.h>
#include <string>
#include <sstream>

IPDATA IP_set(); //IP入力

int SelectMode(); //モードセレクト

//座標
struct Pos
{
	float x, y;
};

//データクラスの定義
class Data {
private:

public:

	char name[16];
	Pos pos;

	//コンストラクタ
	Data(float _x, float _y, char* _name);
};

struct Sub
{
	int sub_1P, sub_2P;
};

//チャンネル登録者数用変数(初期値：1000人)
class Subscriber {
public:
	Sub sub;

	//コンストラクタ
	Subscriber(int sub_1p, int sub_2p);
};

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

struct Squ
{
	int squ_1P, squ_2P;
};

class Squares {
public:
	Squ squ;

	//コンストラクタ
	Squares(int squ_1p, int squ_2p);
};

struct Play
{
	bool Player1, Player2;
};

class Player {
public:
	Play play;

	//コンストラクタ
	Player(bool P1, bool P2);
};

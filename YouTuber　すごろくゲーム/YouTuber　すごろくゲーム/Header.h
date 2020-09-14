#pragma once
#include "DxLib.h"
#include <string.h>
#include <string>
#include <sstream>

IPDATA IP_set(); //IP����

int SelectMode(); //���[�h�Z���N�g

//���W
struct Pos
{
	float x, y;
};

//�f�[�^�N���X�̒�`
class Data {
private:

public:

	char name[16];
	Pos pos;

	//�R���X�g���N�^
	Data(float _x, float _y, char* _name);
};

struct Sub
{
	int sub_1P, sub_2P;
};

//�`�����l���o�^�Ґ��p�ϐ�(�����l�F1000�l)
class Subscriber {
public:
	Sub sub;

	//�R���X�g���N�^
	Subscriber(int sub_1p, int sub_2p);
};

struct Squ
{
	int squ_1P, squ_2P;
};

class Squares {
public:
	Squ squ;

	//�R���X�g���N�^
	Squares(int squ_1p, int squ_2p);
};

struct Play
{
	bool Player1, Player2;
};

class Player {
public:
	Play play;

	//�R���X�g���N�^
	Player(bool P1, bool P2);
};

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

#include "Header.h"
//�f�[�^�N���X

//�R���X�g���N�^
Data::Data(float _x, float _y, char* _name) {
	pos.x = _x;
	pos.y = _y;

	strcpy_s(name, _name);
}
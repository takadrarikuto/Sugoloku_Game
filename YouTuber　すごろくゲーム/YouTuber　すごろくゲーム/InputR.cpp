#include "Header.h"

//���[�h�Z���N�g
int SelectMode() {
	int mode;

	while (1) {
		ClearDrawScreen();

		DrawString(0, 0, "���[�h�I�� 0:�X�^�[�g��1:�҂��󂯑�", GetColor(255, 255, 255));
		mode = KeyInputNumber(0, 16, 1, 0, FALSE);
		if (mode == 0) {
			DrawString(0, 32, "���[�h�́A�X�^�[�g��", GetColor(255, 0, 0));
		}
		else {
			DrawString(0, 48, "���[�h�́A�҂��󂯑�", GetColor(255, 255, 255));
		}
		DrawString(0, 64, "����ŗǂ��ł����H", GetColor(255, 255, 255));
		DrawString(0, 80, "0...������ 1...�͂�", GetColor(255, 255, 255));
		if (KeyInputNumber(0, 96, 1, 0, FALSE))break;
	}
	return mode;
}

//IP����
IPDATA IP_set() {
	IPDATA ip;

	while (1)
	{
		ClearDrawScreen();

		DrawString(0, 0, "IP����(192.168.0.9)", GetColor(255, 255, 255));
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

		DrawString(0, 32, "����ŗǂ��ł����H", GetColor(255, 255, 255));
		DrawString(0, 48, "0...������ 1...�͂�", GetColor(255, 255, 255));
		if (KeyInputNumber(0, 64, 1, 0, FALSE))break;
	}
	return ip;
}
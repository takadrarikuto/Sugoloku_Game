#pragma once
#include "DxLib.h"
#include "Header.h"

int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	//�|�[�g�p�ϐ�
	int Sendport, RecvPort; //send���� Recv�󂯂�

	//����M�f�[�^�����p
	char StrBuf[256] = { "NULL" };

	//window�̐ݒ�
	ChangeWindowMode(TRUE); //window���[�h
	SetGraphMode(640, 480, 32); //window�T�C�Y640*480 32bit
	SetOutApplicationLogValidFlag(FALSE); //Log.txt�𐶐����Ȃ��悤�ɐݒ�
	SetAlwaysRunFlag(TRUE); //�o�b�N�O���E���h�ł����s�o����悤�ɂ���
	SetDoubleStartValidFlag(TRUE); //���d�N���̋���

	//������
	if (DxLib_Init() == -1)return -1; //�G���[���o����I��
	//���[�h�̃Z���N�g
	int mode = SelectMode();

	//window�̖��O
	if (mode == 0) {
		SetWindowText("�X�^�[�g��"); //�E�B���h�E��
		Sendport = 41;
		RecvPort = 40;
	}
	else
	{
		SetWindowText("�҂��󂯑�"); //�E�B���h�E��
		Sendport = 40;
		RecvPort = 41;
	}

	SetDrawScreen(DX_SCREEN_BACK);

	//�摜�ǂݍ���
	int image = LoadGraph("image\\Frisk.png");
	//�摜�̈ʒu���
	float x, y;
	//������ 
	x = 0.0f;
	y = 0.0f;

	//����M�p�f�[�^
	char name[15] = "name";
	Data* data = new Data(x, y, name);

	//IP�̐ݒ�
	IPDATA IP = IP_set();

	//�ʐM�p�\�P�b�g�n���h��
	int NetUDPHandle = MakeUDPSocket(Sendport);

	while (CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		if (ProcessMessage() == -1) break;

		if (mode == 0)
		{
			//�ړ�����
			if (CheckHitKey(KEY_INPUT_UP)) y -= 4.0f;
			if (CheckHitKey(KEY_INPUT_DOWN)) y += 4.0f;
			if (CheckHitKey(KEY_INPUT_RIGHT)) x += 4.0f;
			if (CheckHitKey(KEY_INPUT_LEFT)) x -= 4.0f;

			//�f�[�^�ϊ�
			//sprintf_s(StrBuf, "%f", x); //������ɕϊ�

			//����M�f�[�^�̍X�V
			data->pos.x = x;
			data->pos.y = y;

			//�f�[�^�̑��M
			NetWorkSendUDP(NetUDPHandle, IP, RecvPort, data, 256);
		}

		if (mode == 1) {
			//�f�[�^�̎�M
			if (CheckNetWorkRecvUDP(NetUDPHandle) == TRUE) {
				NetWorkRecvUDP(NetUDPHandle, NULL, NULL, StrBuf, 256, FALSE);
				//��M�f�[�^�ϊ�
				memcpy_s(data, sizeof(Data), StrBuf, sizeof(Data));
				x = data->pos.x;
				y = data->pos.y;

				//x = atof(StrBuf); //�t��������f�[�^��float�ɕϊ�
				//DrawFormatString(0, 16, GetColor(255, 0, 0),"%s", StrBuf);
			}
		}
		ClearDrawScreen(); //�摜�N���A
		//�`�揈��
		DrawGraphF(x, y, image, TRUE);
		ScreenFlip(); //�o�b�N�o�b�t�@�Ɛ؂�ւ�
	}
	delete data; //����M�f�[�^�̍폜

	WaitKey();

	DeleteUDPSocket(NetUDPHandle); //�n���h���̍폜
	DxLib_End(); //dx���C�u�����I������


	return 0;
}
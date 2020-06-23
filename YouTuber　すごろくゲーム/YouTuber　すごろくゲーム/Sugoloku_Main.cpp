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
	SetGraphMode(800, 600, 32); //window�T�C�Y640*480 32bit
	SetAlwaysRunFlag(TRUE); //�o�b�N�O���E���h�ł����s�o����悤�ɂ���
	SetDoubleStartValidFlag(TRUE); //���d�N���̋���

	//������
	if (DxLib_Init() == -1)return -1; //�G���[���o����I��

	//�o�b�N�o�b�t�@���g���ݒ�
	SetDrawScreen(DX_SCREEN_BACK);

	//�摜�ǂݍ���
	int image = LoadGraph("image\\Frisk.png");

	//�摜�̈ʒu���
	float x, y;
	//�摜�̈ړ��������
	float vx, vy;
	//�摜�̈ړ��x�N�g���ő�l
	float vx_max, vy_max;
	//������ 
	x = 0.0f;
	y = 536.0f;
	vx = 0.0f;
	vy = 0.0f;
	vx_max = 0.0f;
	vy_max = 0.0f;
	//���E�����t���O
	bool LR_flg = 1;
	//�㉺�����t���O
	bool UD_flg = 0;
	//�i�s�����Ǘ��ϐ�
	int Direction_of_Travel_num = 0; //0:�E 1:�� 2:�� 3:��
	//�O�i�t���O
	bool Forward_flg = false;

	//�A�j���[�V�����p�J�E���g
	int anim_cnt = 0;
	//�؂���ʒu
	int rect_x = 0;

	while (CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		//�����ݒ�
		//�E
		if (CheckHitKey(KEY_INPUT_RIGHT)) {
			LR_flg = 1;
			Direction_of_Travel_num = 0;
		}
		//��
		else if (CheckHitKey(KEY_INPUT_LEFT)) {
			LR_flg = 0;
			Direction_of_Travel_num = 1;
		}
		//��
		else if (CheckHitKey(KEY_INPUT_UP)) {
			UD_flg = 1;
			Direction_of_Travel_num = 2;
		}
		//��
		else if (CheckHitKey(KEY_INPUT_DOWN)) {
			UD_flg = 0;
			Direction_of_Travel_num = 3;
		}

		//Enter�őO�i�t���O��true�A1P�ړ�������ݒ�
		if (CheckHitKey(KEY_INPUT_RETURN) && Forward_flg == false)
		{
			if (Direction_of_Travel_num == 0)
			{
				vx = x + 64; //�E
				vx_max = 2.0f;
			}
			else if (Direction_of_Travel_num == 1)
			{
				vx = x - 64;//��
				vx_max = -2.0f;
			}
			else if (Direction_of_Travel_num == 2)
			{
				vy = y - 64;//��
				vy_max = -2.0f;
			}
			else if (Direction_of_Travel_num == 3)
			{
				vy = y + 64;//��
				vy_max = 2.0f;
			}
			Forward_flg = true;
		}
		
		//�ݒ肵���ړ������܂łɈړ�
		//���E
		if (vx != x)
		{
			x += vx_max;
		}
		//�㉺
		else if (vy != y)
		{
			y += vy_max;
		}	
		//�ݒ肵���ړ������ɓ�������ƒ�~(Enter���������ςȂ��ɂ��A���ړ����~�߂鏈���t��)
		if (CheckHitKey(KEY_INPUT_RETURN) == false)
		{
			//������ 
			if (vx == x)
			{
				vx_max = 0.0f;
			}
			else if (vy == y)
			{
				vy_max = 0.0f;
			}
			Forward_flg = false;
		}
		
		ClearDrawScreen(); //�摜�N���A
		//�`�揈��
		DrawRectGraphF(
			x, y,  //�`��ʒu
			rect_x, 0, //�؂���J�n�ʒu
			64, 64, //�؂���T�C�Y
			image,  //�؂��錳�摜
			TRUE, //���ߏ����t���O
			LR_flg //���]�����t���O
		);

		ScreenFlip(); //�o�b�N�o�b�t�@�Ɛ؂�ւ�

		//��O������������v���O�����I��
		if (ProcessMessage() == -1) break;
	}

	DxLib_End(); //dx���C�u�����I������


	return 0;
}
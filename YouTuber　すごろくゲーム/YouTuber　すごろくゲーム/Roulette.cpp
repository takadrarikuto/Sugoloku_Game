#pragma once
#include "DxLib.h"
#include "Header.h"
#define RECR_MAX 200

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
	int image = LoadGraph("image\\�X���b�g.png");

	//�摜�̈ʒu���
	float x, y;
	//�؂���ʒu�ύX
	int vx, vy;
	//������ 
	x = 300.0f;
	y = 200.0f;
	vx = 0;
	vy = 0;
	//���E�����t���O
	bool LR_flg = 0;
	//�{�^���m�F
	bool Enter_Bottan = false;
	//���[���b�g��]
	bool Roulette_Rotation = false;
	//���[���b�g�i�W
	int Roulette = 0;

	//�A�j���[�V�����p�J�E���g
	int anim_cnt = 0;
	//�؂���ʒu
	int rect_x = 0;
	int rect_y = 0;

	while (CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		//���[���b�g����
		//Enter�Ń��[���b�g��]�X�^�[�g
		if (CheckHitKey(KEY_INPUT_RETURN) == true && Enter_Bottan == false)
		{			
			if (Roulette == 0)
			{			
				//���[���b�g��]�J�n
				Roulette_Rotation = true;				
				Roulette = 1;
			}
			else if (Roulette == 1)
			{				
				//������
				Roulette_Rotation = false;
				Roulette = 0;				
			}				
			Enter_Bottan = true;
		}
		else if (CheckHitKey(KEY_INPUT_RETURN) == false)
		{
			Enter_Bottan = false;
		}

		//���[���b�g��]����
		if (Roulette_Rotation == true)
		{			
			if (rect_x < 400) {
				rect_x += 200;
			}
			else {
				rect_x = 0; //������
				if (rect_y < 200) {
					rect_y = 200;
				}
				else {
					rect_y = 0; //������
				}
			}
		}

		ClearDrawScreen(); //�摜�N���A
		//�`�揈��
		DrawRectGraphF(
			x, y,  //�`��ʒu
			rect_x, rect_y, //�؂���J�n�ʒu
			RECR_MAX, RECR_MAX, //�؂���T�C�Y
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
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
	int Rou_image = LoadGraph("image\\�X���b�g.png");

	//�摜�̈ʒu���
	float Rou_x, Rou_y;
	//������ 
	Rou_x = 300.0f;
	Rou_y = 200.0f;
	//���E�����t���O
	bool Rou_LR_flg = 0;
	//�{�^���m�F(���[���b�g�p)
	bool Roulette_Enter_Bottan = false;
	//���[���b�g��]
	bool Roulette_Rotation = false;
	//���[���b�g�i�W
	int Roulette = 0;

	//�؂���ʒu
	int Rou_rect_x = 0;
	int Rou_rect_y = 0;

	while (CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		//���[���b�g����
		//Enter�Ń��[���b�g��]�X�^�[�g
		if (CheckHitKey(KEY_INPUT_RETURN) == true && Roulette_Enter_Bottan == false)
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
			Roulette_Enter_Bottan = true;
		}
		else if (CheckHitKey(KEY_INPUT_RETURN) == false)
		{
			Roulette_Enter_Bottan = false;
		}

		//���[���b�g��]����
		if (Roulette_Rotation == true)
		{			
			if (Rou_rect_x < 400) {
				Rou_rect_x += 200;
			}
			else {
				Rou_rect_x = 0; //������
				if (Rou_rect_y < 200) {
					Rou_rect_y = 200;
				}
				else {
					Rou_rect_y = 0; //������
				}
			}
		}

		ClearDrawScreen(); //�摜�N���A
		//�`�揈��
		DrawRectGraphF(
			Rou_x, Rou_y,  //�`��ʒu
			Rou_rect_x, Rou_rect_y, //�؂���J�n�ʒu
			RECR_MAX, RECR_MAX, //�؂���T�C�Y
			Rou_image,  //�؂��錳�摜
			TRUE, //���ߏ����t���O
			Rou_LR_flg //���]�����t���O
		);

		ScreenFlip(); //�o�b�N�o�b�t�@�Ɛ؂�ւ�

		//��O������������v���O�����I��
		if (ProcessMessage() == -1) break;
	}

	DxLib_End(); //dx���C�u�����I������


	return 0;
}
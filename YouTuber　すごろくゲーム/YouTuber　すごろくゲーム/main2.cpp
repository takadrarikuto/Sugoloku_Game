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
	SetOutApplicationLogValidFlag(FALSE); //Log.txt�𐶐����Ȃ��悤�ɐݒ�
	SetAlwaysRunFlag(TRUE); //�o�b�N�O���E���h�ł����s�o����悤�ɂ���
	SetDoubleStartValidFlag(TRUE); //���d�N���̋���
	
	//������
	if (DxLib_Init() == -1)return -1; //�G���[���o����I��

	//�o�b�N�o�b�t�@���g���ݒ�
	SetDrawScreen(DX_SCREEN_BACK);

	//�摜�ǂݍ���
	int image = LoadGraph("image\\pic.png");

	//�摜�̈ʒu���
	float x, y;
	//������ 
	x = 0.0f;
	y = 536.0f;
	//�����t���O
	bool LR_flg = 0;
	//�W�����v�t���O
	bool Ja_flg = 0;

	//�A�j���[�V�����p�J�E���g
	int anim_cnt = 0;
	//�؂���ʒu
	int rect_x = 0;	

	while (CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		
		//�E
		if (CheckHitKey(KEY_INPUT_RIGHT)) {
			x += 2.0f;
			if (x > 800 - 64) x = 800 - 64; //��ʒ[�̔���
			anim_cnt += 8;
			if (anim_cnt % 64 == 0)rect_x = 192 + anim_cnt;
			if (anim_cnt == 128)anim_cnt = 0;
			LR_flg = 0;
		}
		//��
		else if (CheckHitKey(KEY_INPUT_LEFT)) {
			x -= 2.0f;
			if (x < 0)x = 0;  //��ʒ[�̔���
			if (anim_cnt % 64 == 0)rect_x = 192 + anim_cnt;
			anim_cnt += 8;
			if (anim_cnt == 128)anim_cnt = 0;
			LR_flg = 1;
		}
		else {
			anim_cnt = 0;
			rect_x = 0;
			Ja_flg = 0;
		}
		//�W�����v
		if (CheckHitKey(KEY_INPUT_UP)) {						
			if (Ja_flg == 0)y -= 4.0f;	
			if (y < 0)y = 0;
			Ja_flg = 1;
			rect_x = 390;
		}
			
		//���R��������
		if (y < 600 - 64 && Ja_flg == 0){
			y += 4.0f;
			rect_x = 390;		
		}

		ClearDrawScreen(); //�摜�N���A
		//�`�揈��
		DrawRectGraphF(
			x, y,  //�`��ʒu
			rect_x,0, //�؂���J�n�ʒu
			64,64, //�؂���T�C�Y
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
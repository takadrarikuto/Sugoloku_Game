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
	//������ 
	x = 0.0f;
	y = 536.0f;
	vx = 0.0f;
	vy = 0.0f;
	//�����t���O
	bool LR_flg = 0;
	//�O�i�t���O
	bool Forward_flg = false;

	//�A�j���[�V�����p�J�E���g
	int anim_cnt = 0;
	//�؂���ʒu
	int rect_x = 0;

	while (CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		//Enter�őO�i�t���O��true�A�ړ�������ݒ�
		if (CheckHitKey(KEY_INPUT_RETURN) && Forward_flg == false)
		{
			Forward_flg = true;
			vx = x + 64;
			/*vx = -64;*/
		}
		
		//�ݒ肵���ړ������܂łɈړ�
		if (vx != x)
		{
			x += 2.0f;
		}
		/*if (vx < 0)
		{
			x += 2.0f;
			vx += 2.0f;
		}*/
		//�ݒ肵���ړ������ɓ�������ƒ�~(Enter���������ςȂ��ɂ��A���ړ����~�߂鏈���t��)
		else if (vx == x && CheckHitKey(KEY_INPUT_RETURN) == false)
		{
			Forward_flg = false;
		}
		//�E
		if (CheckHitKey(KEY_INPUT_RIGHT)) {
			x += 2.0f;
			if (x > 800 - 64) x = 800 - 64; //��ʒ[�̔���
			LR_flg = 1;
		}
		//��
		else if (CheckHitKey(KEY_INPUT_LEFT)) {
			x -= 2.0f;
			if (x < 0)x = 0;  //��ʒ[�̔���
			LR_flg = 0;
		}
		//��
		else if (CheckHitKey(KEY_INPUT_UP)) {
			y -= 2.0f;
			if (y < 0)y = 0;  //��ʒ[�̔���
		}
		//��
		else if (CheckHitKey(KEY_INPUT_DOWN)) {
			y += 2.0f;
			if (y > 600 - 64)y = 600 - 64;  //��ʒ[�̔���
		}
		else {
			anim_cnt = 0;
			rect_x = 0;
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
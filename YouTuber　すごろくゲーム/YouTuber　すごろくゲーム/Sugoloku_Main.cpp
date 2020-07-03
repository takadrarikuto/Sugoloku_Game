#pragma once
#include "DxLib.h"
#include "Header.h"

#include <time.h>

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
	SetGraphMode(800, 600, 32); //window�T�C�Y800*600 32bit
	SetAlwaysRunFlag(TRUE); //�o�b�N�O���E���h�ł����s�o����悤�ɂ���
	SetDoubleStartValidFlag(TRUE); //���d�N���̋���

	//������
	if (DxLib_Init() == -1)return -1; //�G���[���o����I��

	//SetBackgroundColor(0, 255, 255);
	if (DxLib_Init() < 0) return -1;

	//�o�b�N�o�b�t�@���g���ݒ�
	SetDrawScreen(DX_SCREEN_BACK);

	//LoadGraphScreen(0, 0, "�w�i�e�X�g�p.png", TRUE);

	//�摜�ǂݍ���
	int image = LoadGraph("image\\Frisk.png");
	int back_img1 = LoadGraph("image\\�w�i�e�X�g�p.png");
	int Rou_image = LoadGraph("image\\�X���b�g.png");
	DrawGraph(0, 0, back_img1, TRUE);

	//�v���C���[
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

		//�A�j���[�V�����p�J�E���g
		int anim_cnt = 0;
		//�؂���ʒu
		int rect_x = 0;
		int rect_y = 0;

	//���[���b�g
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
		//���[���b�g��]�E��~
		int Roulette = 0;		

		//�؂���ʒu
		int Rou_rect_x = 0;
		int Rou_rect_y = 0;

	//���L
		//��l���ړ��J�n�t���O
		bool PlayerMove_Flg = false;
		//��l���ړ���
		int PlayerMove_num = 0;

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
				PlayerMove_num = 0; //������
				Roulette = 1;
			}
			else if (Roulette == 1)
			{				
				//���[���b�g��~
				PlayerMove_Flg = true; //��l���ړ��J�n
				Roulette_Rotation = false; //������
				Roulette = 0; //������
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
			//�摜�؂���ʒu�ύX����
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

		//�ړ�������������
		if (Rou_rect_y < 200)
		{
			if (Rou_rect_x == 0){
				PlayerMove_num = 1;
			}
			else if (Rou_rect_x == 200){
				PlayerMove_num = 2;
			}
			else if (Rou_rect_x == 400){
				PlayerMove_num = 3;
			}
		}
		else if (Rou_rect_y == 200)
		{
			if (Rou_rect_x == 0) {
				PlayerMove_num = 4;
			}
			else if (Rou_rect_x == 200){
				PlayerMove_num = 5;
			}
			else if (Rou_rect_x == 400){
				PlayerMove_num = 6;
			}
		}

		//�ړ������ݒ�
		//�E
		if (Direction_of_Travel_num == 0) {
			LR_flg = 1;			
		}
		//��
		else if (Direction_of_Travel_num == 1) {
			LR_flg = 0;			
		}
		//��
		else if (Direction_of_Travel_num == 2) {
			UD_flg = 1;			
		}
		//��
		else if (Direction_of_Travel_num == 3) {
			UD_flg = 0;			
		}

		//Enter�őO�i�t���O��true�A1P�ړ�������ݒ�
		if (PlayerMove_Flg == true)
		{
			if (Direction_of_Travel_num == 0)
			{
				vx = x + (64 * PlayerMove_num); //�E
				vx_max = 2.0f;
			}
			else if (Direction_of_Travel_num == 1)
			{
				vx = x - (64 * PlayerMove_num);//��
				vx_max = -2.0f;
			}
			else if (Direction_of_Travel_num == 2)
			{
				vy = y - (64 * PlayerMove_num);//��
				vy_max = -2.0f;
			}
			else if (Direction_of_Travel_num == 3)
			{
				vy = y + (64 * PlayerMove_num);//��
				vy_max = 2.0f;
			}
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
		if (PlayerMove_Flg == true)
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
			PlayerMove_Flg = false;
			Direction_of_Travel_num = 0;
		}
		
		ClearDrawScreen(); //�摜�N���A
		//�v���C���[�`�揈��
		DrawRectGraphF(
			x, y,  //�`��ʒu
			rect_x, rect_y, //�؂���J�n�ʒu
			64, 64, //�؂���T�C�Y
			image,  //�؂��錳�摜
			TRUE, //���ߏ����t���O
			LR_flg //���]�����t���O
		);

		//���[���b�g�`�揈��
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
#pragma once
#include "DxLib.h"
#include "Header.h"

#define MAP_SIZE	50 //�}�b�v�`�b�v��̃h�b�g�T�C�Y
#define MAP_WIDTH	20 //�}�b�v�̕�
#define MAP_HEIGHT	20 //�}�b�v�̏c����

#define MOVE_FRAME	32 //�ړ��ɂ�����t���[����

// �}�b�v�̃f�[�^(16�}�X�~12�}�X)(0 = �`��}�X�A1 = ��)
int MapData[MAP_HEIGHT][MAP_WIDTH] =
{
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 } ,
	{ 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 } ,
	{ 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1 } ,
	{ 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1 } ,
	{ 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1 } ,
	{ 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1 } ,
	{ 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1 } ,
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1 } ,
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1 } ,
	{ 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1 } ,
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1 } ,
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1 } ,
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1 } ,
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1 } ,
	{ 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1 } ,
	{ 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1 } ,
	{ 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1 } ,
	{ 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1 } ,
	{ 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1 } ,
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 } ,
};

//�ړ����Ă��邩�ǂ����̃t���O( 0:��~��  1:�ړ��� )
int Move;
//�e�����Ɉړ������
int MoveX, MoveY;
//�ړ����n�߂Ă��牽�t���[���o�߂�������ێ�����ϐ�
int MoveCounter;

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
	if (DxLib_Init() == -1)return -1; //�G���[���o����I

	SetBackgroundColor(0, 100, 0);
	if (DxLib_Init() < 0) return -1;

	//�o�b�N�o�b�t�@���g���ݒ�
	SetDrawScreen(DX_SCREEN_BACK);

	//�摜�ǂݍ���
	int image = LoadGraph("image\\Frisk.png");
	int back_img1 = LoadGraph("image\\�w�i�e�X�g�p.png");
	int Rou_image = LoadGraph("image\\�X���b�g.png");
	DrawGraph(0, 0, back_img1, TRUE);
	int squares_img1 = LoadGraph("image\\�}�X.png");

	int i, j;
	int Key;
	int ScrollX, ScrollY;

	//�摜�̈ʒu���
	float x, y;
	//�摜�̈ړ��������
	float vx, vy;
	//�摜�̈ړ��x�N�g���ő�l
	float vx_max, vy_max;
	//������ 
	x = 350.0f;
	y = 275.0f;
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

	//�ŏ��͒�~��(0)�ɂ��Ă���
	Move = 0;

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

			// �ړ����ł͂Ȃ��ꍇ�L�[���͂��󂯕t����
			if (Move == 0)
			{

			//Enter�őO�i�t���O��true�A1P�ړ�������ݒ�
			if (CheckHitKey(KEY_INPUT_RETURN) && Forward_flg == false)
			{
				if (Direction_of_Travel_num == 0)
				{
					//vx = x + 50; //�E
					//vx_max = 2.0f;
					Move = 1;
					MoveX = 1;
					MoveY = 0;
				}
				else if (Direction_of_Travel_num == 1)
				{
					//vx = x - 50;//��
					//vx_max = -2.0f;
					Move = 1;
					MoveX = -1;
					MoveY = 0;
				}
				else if (Direction_of_Travel_num == 2)
				{
					//vy = y - 50;//��
					//vy_max = -2.0f;
					Move = 1;
					MoveX = 0;
					MoveY = -1;
				}
				else if (Direction_of_Travel_num == 3)
				{
					//vy = y + 50;//��
					//vy_max = 2.0f;
					Move = 1;
					MoveX = 0;
					MoveY = 1;
				}
				Forward_flg = true;
			}

			//��~���͉�ʂ̃X�N���[���͍s��Ȃ�
			ScrollX = 0;
			ScrollY = 0;
		}

		// �ړ����̏ꍇ�͈ړ��������s��
		if (Move == 1)
		{
			MoveCounter++;
			//�ݒ肵���ړ������܂łɈړ�
			//���E
			//if (vx != x)
			//{
			//	x += vx_max;
			//}
			//�㉺
			//else if (vy != y)
			//{
			//	y += vy_max;
			//}
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

			// �ړ��������I���������~���ɂ���
			if (MoveCounter == MOVE_FRAME)
			{
				// �v���C���[�̈ʒu��ύX����
				x += MoveX;
				y += MoveY;

				// ��~���͉�ʂ̃X�N���[���͍s��Ȃ�
				//ScrollX = 0;
				//ScrollY = 0;

				Move = 0;
			}
			else
			{
				// �o�ߎ��Ԃ���X�N���[���ʂ��Z�o����
				ScrollX = -(MoveX * MAP_SIZE * MoveCounter / MOVE_FRAME);
				ScrollY = -(MoveY * MAP_SIZE * MoveCounter / MOVE_FRAME);
			}
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

		//�}�b�v��`��
		for (i = 0; i < MAP_HEIGHT; i++)
		{
			for (j = 0; j < MAP_WIDTH; j++)
			{
				if (MapData[i][j] == 0)
				{
					DrawRectGraphF(
						j * MAP_SIZE + ScrollX, i * MAP_SIZE + ScrollY,  //�`��ʒu
						0, 0, //�؂���J�n�ʒu
						50, 50, //�؂���T�C�Y
						squares_img1,  //�؂��錳�摜
						FALSE //���ߏ����t���O
					);
					/*DrawBox(j * MAP_SIZE, i * MAP_SIZE,
						j * MAP_SIZE + MAP_SIZE, i * MAP_SIZE + MAP_SIZE,
						GetColor(255, 255, 255), TRUE);*/
				}
			}
		}

		//unsigned int Cr;
		//Cr = GetColor(255, 255, 255);//�F�̒l���擾
		//DrawBox(150, 20, 200, 70, Cr, TRUE);//�l�p�`��`��
		//DrawBox(205, 20, 255, 70, Cr, TRUE);
		//DrawBox(260, 20, 310, 70, Cr, TRUE);

		//�`�揈��(�����ŉ摜�̕\�����s��)
		//�w�i
		//DrawRectGraphF(
		//	0, 0,  //�`��ʒu
		//	0, 0, //�؂���J�n�ʒu
		//	800, 600, //�؂���T�C�Y
		//	back_img1,  //�؂��錳�摜
		//	TRUE //���ߏ����t���O
		//	//LR_flg //���]�����t���O
		//);
		//�v���C���[
		DrawRectGraphF(
			x, y,  //�`��ʒu
			rect_x, rect_y, //�؂���J�n�ʒu
			64, 64, //�؂���T�C�Y
			image,  //�؂��錳�摜
			TRUE, //���ߏ����t���O
			LR_flg //���]�����t���O
		);

		//UI�����w�i
		DrawBox(0, 0, 800, 50, GetColor(0, 0, 0), TRUE);//�l�p�`��`��
		//������`�悷��
		//�o�^�Ґ�
		DrawFormatString(7, 7, GetColor(255, 255, 255), "1P�`�����l���o�^�Ґ��F1000�l");
		DrawFormatString(7, 29, GetColor(255, 255, 255), "2P�`�����l���o�^�Ґ��F1000�l");
		//�S�[���܂ł̕���
		DrawFormatString(300, 20, GetColor(255, 255, 255), "�S�[���܂�");
		DrawFormatString(395, 7, GetColor(255, 255, 255), "1P�F����30��");
		DrawFormatString(395, 29, GetColor(255, 255, 255), "2P�F����30��");
		//���ݏ���
		DrawFormatString(550, 20, GetColor(255, 255, 255), "���ݏ���");
		DrawFormatString(625, 7, GetColor(255, 0, 0), "1�ʁF1P");
		DrawFormatString(625, 29, GetColor(255, 255, 255), "2�ʁF2P");

		int x_c1 = 355, y_c1 = 350;
		//������`�悷��
		DrawFormatString(x_c1 + ScrollX, y_c1 + ScrollY, GetColor(255, 255, 0), "START");
		int x_c2 = 453, y_c2 = 185;
		//������`�悷��
		DrawFormatString(x_c2 + ScrollX, y_c2 + ScrollY, GetColor(255, 0, 0), "GOAL�I");

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
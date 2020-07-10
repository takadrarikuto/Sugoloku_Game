#pragma once
#include "DxLib.h"
#include "Header.h"

#define MAP_SIZE	50 //�}�b�v�`�b�v��̃h�b�g�T�C�Y
#define MAP_WIDTH	20 //�}�b�v�̕�
#define MAP_HEIGHT	20 //�}�b�v�̏c����
#define MOVE_FRAME	50 //�ړ��ɂ�����t���[����

//�}�b�v�̃f�[�^(16�}�X�~12�}�X)(0 = �ǁA1 = �`��}�X�A2 = �X�^�[�g�A3 = �S�[��)
int MapData[MAP_HEIGHT][MAP_WIDTH] =
{
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } ,
	{ 0, 2, 0, 1, 1, 1, 1, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 } ,
	{ 0, 1, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 } ,
	{ 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0 } ,
	{ 0, 1, 0, 0, 0, 0, 1, 0, 0, 3, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0 } ,
	{ 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0 } ,
	{ 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0 } ,
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0 } ,
	{ 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0 } ,
	{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 } ,
	{ 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0 } ,
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0 } ,
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0 } ,
	{ 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0 } ,
	{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 } ,
	{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 } ,
	{ 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0 } ,
	{ 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 1, 1, 0 } ,
	{ 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0 } ,
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } ,
};

//�v���C���[�̈ʒu
int PlayerX, PlayerY;
//�ړ����Ă��邩�ǂ����̃t���O( 0:��~��  1:�ړ��� )
int Move;
//�e�����Ɉړ������
int MoveX, MoveY;
//�ړ����n�߂Ă��牽�t���[���o�߂�������ێ�����ϐ�
int MoveCounter;

//�}�b�v�ƃv���C���[�̕`��֐�
void GraphDraw(int ScrollX, int ScrollY)
{
	int j, i;
	int MapDrawPointX, MapDrawPointY;		//�`�悷��}�b�v���W�l
	int DrawMapChipNumX, DrawMapChipNumY;	//�`�悷��}�b�v�`�b�v�̐�

	//�摜�ǂݍ���
	int image = LoadGraph("image\\Frisk3.png");
	int back_img1 = LoadGraph("image\\�w�i�e�X�g�p.png");
	int Rou_image = LoadGraph("image\\�X���b�g.png");
	int squares_start = LoadGraph("image\\START�}�X.png");
	int squares_goal = LoadGraph("image\\GOAL�}�X.png");
	int squares_img1 = LoadGraph("image\\�}�X.png");
	int squares_img2 = LoadGraph("image\\�}�X.png");
	int squares_img3 = LoadGraph("image\\�΃}�X.png");
	int Branch = LoadGraph("image\\����.png");

	//�`�悷��}�b�v�`�b�v�̐����Z�b�g
	DrawMapChipNumX = 800 / MAP_SIZE + 2;
	DrawMapChipNumY = 600 / MAP_SIZE + 2;

	//��ʍ���ɕ`�悷��}�b�v���W���Z�b�g
	MapDrawPointX = PlayerX - (DrawMapChipNumX / 2 - 1);
	MapDrawPointY = PlayerY - (DrawMapChipNumY / 2 - 1);

	//�}�b�v��`��
	for (i = -1; i < DrawMapChipNumY; i++)
	{
		for (j = -1; j < DrawMapChipNumX; j++)
		{
			//��ʂ���͂ݏo���ʒu�Ȃ�`�悵�Ȃ�
			if (j + MapDrawPointX < 0 || i + MapDrawPointY < 0 ||
				j + MapDrawPointX >= MAP_WIDTH || i + MapDrawPointY >= MAP_HEIGHT) continue;

			//�}�b�v�f�[�^��0��������ǂ�`�悷��(�f�o�b�O�p)
			/*if (MapData[i + MapDrawPointY][j + MapDrawPointX] == 0)
			{
				DrawBox(j * MAP_SIZE + ScrollX, i * MAP_SIZE + ScrollY,
					j * MAP_SIZE + MAP_SIZE + ScrollX, i * MAP_SIZE + MAP_SIZE + ScrollY,
					GetColor(0, 255, 255), TRUE);
			}*/
			//�}�b�v��1������΁u�ʏ�}�X�v�`��
			if (MapData[i + MapDrawPointY][j + MapDrawPointX] == 1)
			{
				DrawRectGraphF(
					j * MAP_SIZE + ScrollX, i * MAP_SIZE + ScrollY,  //�`��ʒu
					0, 0, //�؂���J�n�ʒu
					50, 50, //�؂���T�C�Y
					squares_img1,  //�؂��錳�摜
					FALSE //���ߏ����t���O
				);
			}
			//�}�b�v��2������΁uSTART�}�X�v�`��
			if (MapData[i + MapDrawPointY][j + MapDrawPointX] == 2)
			{
				DrawRectGraphF(
					j * MAP_SIZE + ScrollX, i * MAP_SIZE + ScrollY,  //�`��ʒu
					0, 0, //�؂���J�n�ʒu
					50, 50, //�؂���T�C�Y
					squares_start,  //�؂��錳�摜
					FALSE //���ߏ����t���O
				);
			}
			//�}�b�v��3������΁uGOAL�}�X�v�`��
			if (MapData[i + MapDrawPointY][j + MapDrawPointX] == 3)
			{
				DrawRectGraphF(
					j * MAP_SIZE + ScrollX, i * MAP_SIZE + ScrollY,  //�`��ʒu
					0, 0, //�؂���J�n�ʒu
					50, 50, //�؂���T�C�Y
					squares_goal,  //�؂��錳�摜
					FALSE //���ߏ����t���O
				);
			}
			//�}�b�v��4������΁u�}�X�v�`��
			if (MapData[i + MapDrawPointY][j + MapDrawPointX] == 4)
			{
				DrawRectGraphF(
					j * MAP_SIZE + ScrollX, i * MAP_SIZE + ScrollY,  //�`��ʒu
					0, 0, //�؂���J�n�ʒu
					50, 50, //�؂���T�C�Y
					squares_img2,  //�؂��錳�摜
					FALSE //���ߏ����t���O
				);
			}
			//�}�b�v��5������΁u�΃}�X�v�`��
			if (MapData[i + MapDrawPointY][j + MapDrawPointX] == 5)
			{
				DrawRectGraphF(
					j * MAP_SIZE + ScrollX, i * MAP_SIZE + ScrollY,  //�`��ʒu
					0, 0, //�؂���J�n�ʒu
					50, 50, //�؂���T�C�Y
					squares_img3,  //�؂��錳�摜
					FALSE //���ߏ����t���O
				);
			}
			//�}�b�v��6������΁u����v�`��
			if (MapData[i + MapDrawPointY][j + MapDrawPointX] == 6)
			{
				DrawRectGraphF(
					j * MAP_SIZE + ScrollX, i * MAP_SIZE + ScrollY,  //�`��ʒu
					0, 0, //�؂���J�n�ʒu
					60, 60, //�؂���T�C�Y
					Branch,  //�؂��錳�摜
					FALSE //���ߏ����t���O
				);
			}
		}
	}

	//�v���C���[�̕`��
	DrawRectGraphF(
		400, 300 ,  //�`��ʒu
		0, 0, //�؂���J�n�ʒu
		MAP_SIZE, MAP_SIZE, //�؂���T�C�Y
		image,  //�؂��錳�摜
		TRUE //���ߏ����t���O
	);

	/*DrawBox((PlayerX - MapDrawPointX) * MAP_SIZE, (PlayerY - MapDrawPointY) * MAP_SIZE,
		(PlayerX - MapDrawPointX + 1) * MAP_SIZE, (PlayerY - MapDrawPointY + 1) * MAP_SIZE,
		GetColor(255, 255, 255), TRUE);*/

	//-----------------------------------------------------------------------
	//UI�����w�i
	DrawBox(0, 0, 800, 50, GetColor(0, 0, 0), TRUE);//�l�p�`��`��
	//������`�悷��-------------------------------------------------------------------
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
	//---------------------------------------------------------------------------------
}

//���C��
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	//�|�[�g�p�ϐ�
	int Sendport, RecvPort; //send���� Recv�󂯂�

	//����M�f�[�^�����p
	char StrBuf[256] = { "NULL" };

	int Key;
	int ScrollX, ScrollY;

	ChangeWindowMode(TRUE); //window���[�h
	SetGraphMode(800, 600, 16);
	SetGraphMode(800, 600, 32); //window�T�C�Y800*600 32bit
	SetAlwaysRunFlag(TRUE); //�o�b�N�O���E���h�ł����s�o����悤�ɂ���
	SetDoubleStartValidFlag(TRUE); //���d�N���̋���

	//������
	if (DxLib_Init() == -1)return -1; //�G���[���o����I

	SetBackgroundColor(0, 100, 0);
	if (DxLib_Init() < 0) return -1;

	//�`����ʂ𗠉�ʂɂ���
	SetDrawScreen(DX_SCREEN_BACK);

	//�v���C���[�̏����ʒu���Z�b�g
	PlayerX = 1;
	PlayerY = 1;

	//�ŏ��͒�~��(0)�ɂ��Ă���
	Move = 0;

	//���[�v
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		//��ʂ�������
		ClearDrawScreen();

		//�ړ����ł͂Ȃ��ꍇ�L�[���͂��󂯕t����
		if (Move == 0)
		{
			//�L�[���͂𓾂�
			Key = GetJoypadInputState(DX_INPUT_KEY_PAD1);

			//�L�[���͂ɉ����ăv���C���[�̍��W���ړ�
			if (Key & PAD_INPUT_LEFT)
			{
				Move = 1;
				MoveX = -1;
				MoveY = 0;
			}
			if (Key & PAD_INPUT_RIGHT)
			{
				Move = 1;
				MoveX = 1;
				MoveY = 0;
			}
			if (Key & PAD_INPUT_UP)
			{
				Move = 1;
				MoveX = 0;
				MoveY = -1;
			}
			if (Key & PAD_INPUT_DOWN)
			{
				Move = 1;
				MoveX = 0;
				MoveY = 1;
			}

			//�i���s�\�ȃ}�b�v�������ꍇ�͈ړ��ł��Ȃ�
			if (Move == 1)
			{
				if (MapData[PlayerY + MoveY][PlayerX + MoveX] == 0)
				{
					Move = 0;
				}
				else
				{
					MoveCounter = 0;
				}
			}

			//��~���͉�ʂ̃X�N���[���͍s��Ȃ�
			ScrollX = 0;
			ScrollY = 0;
		}

		//�ړ����̏ꍇ�͈ړ��������s��
		if (Move == 1)
		{
			MoveCounter++;

			//�ړ��������I���������~���ɂ���
			if (MoveCounter == MOVE_FRAME)
			{
				Move = 0;

				//�v���C���[�̈ʒu��ύX����
				PlayerX += MoveX;
				PlayerY += MoveY;

				//��~���͉�ʂ̃X�N���[���͍s��Ȃ�
				ScrollX = 0;
				ScrollY = 0;
			}
			else
			{
				//�o�ߎ��Ԃ���X�N���[���ʂ��Z�o����
				ScrollX = -(MoveX * MAP_SIZE * MoveCounter / MOVE_FRAME);
				ScrollY = -(MoveY * MAP_SIZE * MoveCounter / MOVE_FRAME);
			}
		}

		//�}�b�v�ƃv���C���[��`��
		GraphDraw(ScrollX, ScrollY);

		ScreenFlip(); //�o�b�N�o�b�t�@�Ɛ؂�ւ�

		//��O������������v���O�����I��
		if (ProcessMessage() == -1) break;

		//����ʂ̓��e��\��ʂɉf��
		//ScreenFlip();
	}

	DxLib_End(); //dx���C�u�����I������

	return 0;
}
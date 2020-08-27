#pragma once
#include "DxLib.h"
#include "Header.h"

#define MAP_SIZE	50 //�}�b�v�`�b�v��̃h�b�g�T�C�Y
#define MAP_WIDTH	20 //�}�b�v�̕�
#define MAP_HEIGHT	20 //�}�b�v�̏c����
#define MOVE_FRAME	50 //�ړ��ɂ�����t���[����

#define RECR_MAX 200 //���[���b�g�؂��萔

/*�}�b�v�̃f�[�^(20�}�X�~20�}�X)(0 = �ǁA1 = �`��}�X�A2 = �X�^�[�g�A3 = �S�[��
4 = �o�^�ґ����A 5 = �o�^�Ҍ����A6 = ����_�A7 = 2�{�}�X�A)(150�}�X)*/
int MapData[MAP_HEIGHT][MAP_WIDTH] =
{
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,2,0,1,1,4,1,1,1,5,1,1,4,1,1,4,1,1,5,0},
	{0,1,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
	{0,1,0,1,1,1,5,0,0,0,0,0,4,1,5,1,0,0,1,0},
	{0,4,0,0,0,0,1,0,3,1,9,9,9,0,0,8,0,0,1,0},
	{0,5,0,0,0,0,4,0,0,0,0,0,0,0,0,1,0,0,5,0},
	{0,1,1,1,1,7,5,0,4,1,1,4,5,5,4,5,0,0,1,0},
	{0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,1,0},
	{0,1,5,1,1,7,1,1,5,0,1,8,1,0,1,7,1,0,4,0},
	{0,4,0,0,0,0,0,0,0,0,1,0,5,5,5,0,4,0,1,0},
	{0,1,5,1,1,8,1,4,1,1,4,0,0,0,0,0,1,0,1,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0},
	{0,1,5,1,0,5,1,4,0,0,0,0,4,4,4,0,5,0,7,0},
	{0,4,0,1,0,1,0,1,0,5,1,1,1,0,1,8,1,0,1,0},
	{0,1,0,4,1,8,0,7,1,4,0,0,0,0,0,0,0,0,8,0},
	{0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
	{0,1,0,1,4,4,4,4,5,1,4,1,4,4,1,5,1,0,1,0},
	{0,8,1,1,0,0,0,0,0,0,0,0,0,0,0,0,6,4,5,0},
	{0,0,0,1,5,5,5,5,4,1,5,1,5,5,1,4,1,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},

	/*{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } ,
	{ 0, 2, 0, 1, 1, 4, 1, 1, 1, 1,    5, 1, 1, 1, 1, 4, 1, 1, 5, 0 } ,
	{ 0, 1, 0, 8, 0, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0, 0, 0, 1, 0 } ,
	{ 0, 1, 0, 1, 1, 1, 1, 0, 0, 0,    0, 0, 1, 4, 1, 0, 0, 0, 1, 0 } ,
	{ 0, 4, 0, 0, 0, 0, 1, 0, 0, 3,    9, 9, 9, 0, 8, 0, 0, 0, 1, 0 } ,
	{ 0, 5, 0, 0, 0, 0, 5, 0, 0, 0,    0, 0, 0, 0, 1, 0, 0, 0, 1, 0 } ,
	{ 0, 1, 1, 1, 1, 7, 4, 0, 0, 0,    0, 0, 1, 4, 1, 0, 0, 0, 5, 0 } ,
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    0, 0, 1, 0, 0, 0, 0, 0, 1, 0 } ,
	{ 0, 1, 5, 1, 1, 7, 1, 1, 5, 7,    4, 1, 1, 0, 0, 0, 0, 0, 4, 0 } ,
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0, 0, 0, 1, 0 } ,

	{ 0, 1, 1, 1, 5, 8, 1, 1, 1, 1,    4, 1, 1, 1, 0, 0, 0, 0, 1, 0 } ,
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    0, 0, 0, 1, 0, 0, 0, 0, 1, 0 } ,
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    0, 0, 0, 1, 0, 0, 0, 0, 7, 0 } ,
	{ 0, 1, 1, 5, 1, 1, 1, 8, 1, 4,    1, 1, 5, 5, 0, 0, 0, 0, 1, 0 } ,
	{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0, 0, 0, 8, 0 } ,
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0, 0, 0, 1, 0 } ,
	{ 0, 1, 0, 1, 1, 1, 4, 1, 5, 1,    4, 1, 4, 4, 1, 5, 7, 0, 1, 0 } ,
	{ 0, 8, 1, 1, 0, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0, 6, 4, 1, 0 } ,
	{ 0, 0, 0, 1, 1, 1, 5, 1, 4, 5,    1, 1, 5, 5, 1, 4, 1, 0, 0, 0 } ,
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } ,*/
};
/*��l���p�̃}�b�v�̃f�[�^(20�}�X�~20�}�X)(0 = �ǁA1 = �`��}�X�A2 = ��l���A3 = �ʉߌ�}�X
4 = �o�^�ґ����A 5 = �o�^�Ҍ����A 6 = ����_ 8 = ����_�I�_(�\��))(125�}�X)*/
4 = �o�^�ґ����A 5 = �o�^�Ҍ����A 6 = ����_�A7 = 2�{�}�X�A9 = �S�[���}�X�@ = ����_�I�_(7�ȊO�\��))(150�}�X)*/
int MapData_P[MAP_HEIGHT][MAP_WIDTH] =
{
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,2,0,1,1,4,1,1,1,5,1,1,4,1,1,4,1,1,5,0},
	{0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
	{0,1,0,1,1,1,5,0,0,0,0,0,4,1,5,1,0,0,1,0},
	{0,4,0,0,0,0,1,0,9,1,1,1,1,0,0,1,0,0,1,0},
	{0,5,0,0,0,0,4,0,0,0,0,0,0,0,0,1,0,0,5,0},
	{0,1,1,1,1,7,5,0,4,1,1,4,5,5,4,5,0,0,1,0},
	{0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,1,0},
	{0,1,5,1,1,7,1,1,5,0,1,1,1,0,1,7,1,0,4,0},
	{0,4,0,0,0,0,0,0,0,0,1,0,5,5,5,0,4,0,1,0},
	{0,1,5,1,1,1,1,4,1,1,4,0,0,0,0,0,1,0,1,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0},
	{0,1,5,1,0,5,1,4,0,0,0,0,4,4,4,0,5,0,7,0},
	{0,4,0,1,0,1,0,1,0,5,1,1,1,0,1,1,1,0,1,0},
	{0,1,0,4,1,1,0,7,1,4,0,0,0,0,0,0,0,0,1,0},
	{0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
	{0,1,0,1,4,4,4,4,5,1,4,1,4,4,1,5,1,0,1,0},
	{0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,6,4,5,0},
	{0,0,0,1,5,5,5,5,4,1,5,1,5,5,1,4,1,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	/*{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } ,
	{ 0, 2, 0, 1, 1, 4, 1, 1, 1, 1,    5, 1, 1, 1, 1, 4, 1, 1, 5, 0 } ,
	{ 0, 1, 0, 1, 0, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0, 0, 0, 1, 0 } ,
	{ 0, 1, 0, 1, 1, 1, 1, 0, 0, 0,    0, 0, 1, 4, 1, 0, 0, 0, 1, 0 } ,
	{ 0, 4, 0, 0, 0, 0, 1, 0, 0, 9,    1, 1, 1, 0, 8, 0, 0, 0, 1, 0 } ,
	{ 0, 5, 0, 0, 0, 0, 5, 0, 0, 0,    0, 0, 0, 0, 1, 0, 0, 0, 1, 0 } ,
	{ 0, 1, 1, 1, 1, 1, 4, 0, 0, 0,    0, 0, 1, 4, 1, 0, 0, 0, 5, 0 } ,
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    0, 0, 1, 0, 0, 0, 0, 0, 1, 0 } ,
	{ 0, 1, 5, 1, 1, 7, 1, 1, 5, 7,    4, 1, 1, 0, 0, 0, 0, 0, 4, 0 } ,
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0, 0, 0, 1, 0 } ,

	{ 0, 1, 1, 1, 5, 8, 1, 1, 1, 1,    4, 1, 1, 1, 0, 0, 0, 0, 1, 0 } ,
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    0, 0, 0, 1, 0, 0, 0, 0, 1, 0 } ,
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    0, 0, 0, 1, 0, 0, 0, 0, 7, 0 } ,
	{ 0, 1, 1, 5, 1, 1, 1, 8, 1, 4,    1, 1, 5, 5, 0, 0, 0, 0, 1, 0 } ,
	{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0, 0, 0, 8, 0 } ,
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0, 0, 0, 1, 0 } ,
	{ 0, 1, 0, 1, 1, 1, 4, 1, 5, 1,    4, 1, 4, 4, 1, 5, 7, 0, 1, 0 } ,
	{ 0, 8, 1, 1, 0, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0, 6, 4, 1, 0 } ,
	{ 0, 0, 0, 1, 1, 1, 5, 1, 4, 5,    1, 1, 5, 5, 1, 4, 1, 0, 0, 0 } ,
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } ,*/
};

//�v���C���[�̈ʒu
int PlayerX, PlayerY;
//�ړ����Ă��邩�ǂ����̃t���O( 0:��~��  1:�ړ��� )
int Move;
//�e�����Ɉړ������
int MoveX, MoveY;
//�ړ����n�߂Ă��牽�t���[���o�߂�������ێ�����ϐ�
int MoveCounter;

//�`�����l���o�^�Ґ��p�ϐ�(�����l�F1000�l)
int P1_subscriber = 1000;
int P2_subscriber = 1000;

//�}�X�ڃJ�E���g�p(����)
int squares_cnt1 = 150;
int squares_cnt2 = 150;

//�}�b�v�ƃv���C���[�̕`��֐�
void GraphDraw(int ScrollX, int ScrollY)
{
	int j, i;
	int MapDrawPointX, MapDrawPointY;		//�`�悷��}�b�v���W�l
	int DrawMapChipNumX, DrawMapChipNumY;	//�`�悷��}�b�v�`�b�v�̐�

	//�`�悷��}�b�v�`�b�v�̐����Z�b�g
	DrawMapChipNumX = 800 / MAP_SIZE + 2;
	DrawMapChipNumY = 600 / MAP_SIZE + 2;

	//��ʍ���ɕ`�悷��}�b�v���W���Z�b�g
	MapDrawPointX = PlayerX - (DrawMapChipNumX / 2 - 1);
	MapDrawPointY = PlayerY - (DrawMapChipNumY / 2 - 1);

	//�摜�ǂݍ���(�ustatic int�v�łȂ��ƁA��������������������̂Œ���)
	static int image = LoadGraph("image\\�v���C���[1.png");
	static int back_img1 = LoadGraph("image\\�w�i�e�X�g�p.png");
	static int squares_start = LoadGraph("image\\START�}�X.png");//�u2�v
	static int squares_goal = LoadGraph("image\\GOAL�}�X.png");//�u3�v
	static int squares_img1 = LoadGraph("image\\�}�X.png");//�u1�v
	static int subscriber_up = LoadGraph("image\\�o�^�Ґ������}�X.png");//�u4�v
	static int subscriber_down = LoadGraph("image\\�o�^�Ґ������}�X.png");//�u5�v
	static int Branch = LoadGraph("image\\����.png");//�u6�v
	static int Double = LoadGraph("image\\�Q�{�}�X.png");//�u7�v
	static int event = LoadGraph("image\\�C�x���g�}�X.png");//�u8�v
	static int Reversal = LoadGraph("image\\�t�]�}�X.png");//�u9�v

	//�}�b�v��`��
	for (i = -1; i < DrawMapChipNumY; i++) {
		for (j = -1; j < DrawMapChipNumX; j++) {
			//��ʂ���͂ݏo���ʒu�Ȃ�`�悵�Ȃ�
			if (j + MapDrawPointX < 0 || i + MapDrawPointY < 0 ||
				j + MapDrawPointX >= MAP_WIDTH || i + MapDrawPointY >= MAP_HEIGHT) continue;

			//�}�b�v�f�[�^��0��������ǂ�`�悷��(�f�o�b�O�p)
			/*if (MapData[i + MapDrawPointY][j + MapDrawPointX] == 0)
			{
				DrawBox(j * MAP_SIZE + ScrollX, i * MAP_SIZE + ScrollY,
					j * MAP_SIZE + MAP_SIZE + ScrollX, i * MAP_SIZE + MAP_SIZE + ScrollY,
					GetColor(0, 0, 255), TRUE);
			}*/
			//�}�b�v��1������΁u�ʏ�}�X�v�`��
			if (MapData[i + MapDrawPointY][j + MapDrawPointX] == 1) {
				DrawRectGraphF(
					j * MAP_SIZE + ScrollX, i * MAP_SIZE + ScrollY,  //�`��ʒu
					0, 0, //�؂���J�n�ʒu
					50, 50, //�؂���T�C�Y
					squares_img1,  //�؂��錳�摜
					FALSE //���ߏ����t���O
				);
			}
			//�}�b�v��2������΁uSTART�}�X�v�`��
			if (MapData[i + MapDrawPointY][j + MapDrawPointX] == 2) {
				DrawRectGraphF(
					j * MAP_SIZE + ScrollX, i * MAP_SIZE + ScrollY,  //�`��ʒu
					0, 0, //�؂���J�n�ʒu
					50, 50, //�؂���T�C�Y
					squares_start,  //�؂��錳�摜
					FALSE //���ߏ����t���O
				);
			}
			//�}�b�v��3������΁uGOAL�}�X�v�`��
			if (MapData[i + MapDrawPointY][j + MapDrawPointX] == 3) {
				DrawRectGraphF(
					j * MAP_SIZE + ScrollX, i * MAP_SIZE + ScrollY,  //�`��ʒu
					0, 0, //�؂���J�n�ʒu
					50, 50, //�؂���T�C�Y
					squares_goal,  //�؂��錳�摜
					FALSE //���ߏ����t���O
				);
			}
			//�}�b�v��4������΁u�`�����l���o�^�Ґ������}�X�v�`��
			if (MapData[i + MapDrawPointY][j + MapDrawPointX] == 4) {
				DrawRectGraphF(
					j * MAP_SIZE + ScrollX, i * MAP_SIZE + ScrollY,  //�`��ʒu
					0, 0, //�؂���J�n�ʒu
					50, 50, //�؂���T�C�Y
					subscriber_up,  //�؂��錳�摜
					FALSE //���ߏ����t���O
				);
			}
			//�}�b�v��5������΁u�`�����l���o�^�Ґ������}�X�v�`��
			if (MapData[i + MapDrawPointY][j + MapDrawPointX] == 5) {
				DrawRectGraphF(
					j * MAP_SIZE + ScrollX, i * MAP_SIZE + ScrollY,  //�`��ʒu
					0, 0, //�؂���J�n�ʒu
					50, 50, //�؂���T�C�Y
					subscriber_down,  //�؂��錳�摜
					FALSE //���ߏ����t���O
				);
			}
			//�}�b�v��6������΁u����v�`��
			if (MapData[i + MapDrawPointY][j + MapDrawPointX] == 6) {
				DrawRectGraphF(
					j * MAP_SIZE + ScrollX, i * MAP_SIZE + ScrollY,  //�`��ʒu
					0, 0, //�؂���J�n�ʒu
					50, 50, //�؂���T�C�Y
					Branch,  //�؂��錳�摜
					FALSE //���ߏ����t���O
				);
			}
			//�}�b�v��7������΁u�T�C�R���Q�{�}�X�v�`��
			if (MapData[i + MapDrawPointY][j + MapDrawPointX] == 7)
			{
				DrawRectGraphF(
					j * MAP_SIZE + ScrollX, i * MAP_SIZE + ScrollY,  //�`��ʒu
					0, 0, //�؂���J�n�ʒu
					50, 50, //�؂���T�C�Y
					Double,  //�؂��錳�摜
					FALSE //���ߏ����t���O
				);
			}
			//�}�b�v��8������΁u�C�x���g�}�X�v�`��
			if (MapData[i + MapDrawPointY][j + MapDrawPointX] == 8)
			{
				DrawRectGraphF(
					j * MAP_SIZE + ScrollX, i * MAP_SIZE + ScrollY,  //�`��ʒu
					0, 0, //�؂���J�n�ʒu
					50, 50, //�؂���T�C�Y
					event,  //�؂��錳�摜
					FALSE //���ߏ����t���O
				);
			}
			//�}�b�v��9������΁u�t�]�}�X�v�`��
			if (MapData[i + MapDrawPointY][j + MapDrawPointX] == 9)
			{
				DrawRectGraphF(
					j * MAP_SIZE + ScrollX, i * MAP_SIZE + ScrollY,  //�`��ʒu
					0, 0, //�؂���J�n�ʒu
					50, 50, //�؂���T�C�Y
					Reversal,  //�؂��錳�摜
					FALSE //���ߏ����t���O
				);
			}
			//��l���p�}�b�v��2������΁u��l���v�`��
			if (MapData_P[i + MapDrawPointY][j + MapDrawPointX] == 2)
			{
				DrawRectGraphF(
					j * MAP_SIZE + ScrollX, i * MAP_SIZE + ScrollY,  //�`��ʒu
					0, 0, //�؂���J�n�ʒu
					MAP_SIZE, MAP_SIZE, //�؂���T�C�Y
					image,  //�؂��錳�摜
					TRUE //���ߏ����t���O
				);
			}
		}
	}
	//�v���C���[�̕`��
	/*DrawRectGraphF(
		400, 300 ,  //�`��ʒu
		0, 0, //�؂���J�n�ʒu
		MAP_SIZE, MAP_SIZE, //�؂���T�C�Y
		image,  //�؂��錳�摜
		TRUE //���ߏ����t���O
	);*/

	/*DrawBox((PlayerX - MapDrawPointX) * MAP_SIZE, (PlayerY - MapDrawPointY) * MAP_SIZE,
		(PlayerX - MapDrawPointX + 1) * MAP_SIZE, (PlayerY - MapDrawPointY + 1) * MAP_SIZE,
		GetColor(255, 255, 255), TRUE);*/

	//---------------------------------------------------------------------------------
	//UI�����w�i
	DrawBox(0, 0, 800, 50, GetColor(0, 0, 0), TRUE);//�`��
	//������`�悷��-------------------------------------------------------------------
	//�o�^�Ґ�
	DrawFormatString(7, 7, GetColor(255, 255, 255), "1P�`�����l���o�^�Ґ��F%d�l", P1_subscriber);
	DrawFormatString(7, 29, GetColor(255, 255, 255), "2P�`�����l���o�^�Ґ��F%d�l", P2_subscriber);
	//�S�[���܂ł̕���
	DrawFormatString(270, 18, GetColor(255, 255, 255), "�S�[���܂�");
	DrawFormatString(365, 7, GetColor(255, 255, 255), "1P�F����%d��", squares_cnt1);
	DrawFormatString(365, 29, GetColor(255, 255, 255), "2P�F����%d��", squares_cnt2);
	//���ݏ���
	DrawFormatString(500, 18, GetColor(255, 255, 255), "���ݏ���");
	if (P1_subscriber > P2_subscriber)
	{
		DrawFormatString(575, 7, GetColor(255, 0, 0), "1�ʁF1P");
		DrawFormatString(575, 29, GetColor(255, 255, 255), "2�ʁF2P");
	}
	else if (P2_subscriber > P1_subscriber)
	{
		DrawFormatString(575, 7, GetColor(255, 0, 0), "1�ʁF2P");
		DrawFormatString(575, 29, GetColor(255, 255, 255), "2�ʁF1P");
	}
	else
	{
		DrawFormatString(575, 18, GetColor(255, 255, 255), "���ʁF");
		DrawFormatString(628, 7, GetColor(255, 255, 255), "1P");
		DrawFormatString(628, 29, GetColor(255, 255, 255), "2P");
	}
	//����
	DrawFormatString(665, 18, GetColor(255, 255, 255), "�^�[��");
	DrawFormatString(750, 7, GetColor(255, 255, 255), "1P");
	DrawFormatString(750, 29, GetColor(255, 255, 255), "2P");
	DrawFormatString(725, 7, GetColor(255, 255, 255), "��");
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

	SetOutApplicationLogValidFlag(FALSE); //Log.txt�𐶐����Ȃ��悤�ɐݒ�
	ChangeWindowMode(TRUE); //window���[�h
	SetGraphMode(800, 600, 32); //window�T�C�Y800*600 32bit
	SetAlwaysRunFlag(TRUE); //�o�b�N�O���E���h�ł����s�o����悤�ɂ���
	SetDoubleStartValidFlag(TRUE); //���d�N���̋���
	SetBackgroundColor(0, 100, 0); //�w�i�F

	int Key, i;
	int ScrollX, ScrollY;
	int MapDrawPointX, MapDrawPointY;		//�`�悷��}�b�v���W�l
	int DrawMapChipNumX, DrawMapChipNumY;	//�`�悷��}�b�v�`�b�v�̐�
	int subscriber_up_time = 0;
	int subscriber_down_time = 0;
	int two_times_messagetime = 0;
	int goal_time = 0;
	bool Roulette_Flg = false; //���[���b�g�e�L�X�g�p�t���O
	bool Roulette_stop_Flg = false; //���[���b�g�e�L�X�g�p�t���O
	bool square_go_Flg = false; //���[���b�g�e�L�X�g�p�t���O
	bool square_rest_Flg = true; //���[���b�g�e�L�X�g�p�t���O

	//������
	if (DxLib_Init() == -1) { //DX���C�u��������������
		return -1;				//�G���[���N�����璼���ɏI��
	}
	if (DxLib_Init() < 0) {
		return -1;
	}

	//�`����ʂ𗠉�ʂɂ���
	SetDrawScreen(DX_SCREEN_BACK);

	//�摜�ǂݍ���(�ustatic int�v�łȂ��ƁA��������������������̂Œ���)
	static int Rou_image = LoadGraph("image\\�X���b�g.png");//���[���b�g
	static int message_window_img = LoadGraph("image\\���b�Z�[�W�E�B���h�E.png");//�u9�v

	//BGM�Đ�
	PlaySoundFile("music\\���C��BGM.mp3", DX_PLAYTYPE_LOOP);

	int move_sound = 0;
	int roulette_sound = 0;
	int roulette_dec_sound = 0;
	int subscriber_up_sound = 0;
	int subscriber_down_sound = 0;
	int goal_sound = 0;
	int goal_cheers_sound = 0;

	move_sound = LoadSoundMem("music\\�R�}�ړ�.mp3");
	roulette_sound = LoadSoundMem("music\\���[���b�g.mp3");
	roulette_dec_sound = LoadSoundMem("music\\���[���b�g����.mp3");
	subscriber_up_sound = LoadSoundMem("music\\�o�^�Ґ�������.mp3");
	subscriber_down_sound = LoadSoundMem("music\\�o�^�Ґ�������.mp3");
	goal_sound = LoadSoundMem("music\\�S�[����.mp3");
	goal_cheers_sound = LoadSoundMem("music\\�S�[������.mp3");

	//�v���C���[�̏����ʒu���Z�b�g
	PlayerX = 1;
	PlayerY = 1;

	//�ŏ��͒�~��(0)�ɂ��Ă���
	Move = 0;

	//�v���C���[----------------------------------
	//�摜�̈ړ��������
	float P1_x, P1_y, /*1P�v���C���[*/P2_x, P2_y/*2P�v���C���[*/;
	//������ 
	P1_x = 350.0f; P1_y = 268.0f; //1P�v���C���[
	P2_x = 400.0f; P2_y = 268.0f; //2P�v���C���[
	//���E�����t���O
	bool P1_LR_flg = 1/*1P�v���C���[*/, P2_LR_flg = 1/*2P�v���C���[*/;
	//�㉺�����t���O
	bool P1_UD_flg = 0/*1P�v���C���[*/, P2_UD_flg = 0/*2P�v���C���[*/;
	//�A�j���[�V�����p�J�E���g
	int P1_anim_cnt = 0/*1P�v���C���[*/, P2_anim_cnt = 0/*2P�v���C���[*/;
	//�؂���ʒu
	int P1_rect_x = 0/*1P�v���C���[*/, P2_rect_x = 0/*2P�v���C���[*/;
	int P1_rect_y = 0/*1P�v���C���[*/, P2_rect_y = 0/*2P�v���C���[*/;
	//--------------------------------------------
	//���[���b�g----------------------------------
	//�摜�̈ʒu���
	float Rou_x, Rou_y;
	//������ 
	Rou_x = 295.0f;
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

	//���[���b�g�摜�\����~�t���O
	bool RouDraw_flg = false;
	//���[���b�g�摜�\����~�^�C��
	int RouDraw_time = 0;	

	//2�{�}�X�p�t���O
	bool two_times = false;

	//���L
	//��l���ړ��J�n�t���O
	bool P1_PlayerMove_Flg = false/*1P�v���C���[*/, P2_PlayerMove_Flg = false/*2P�v���C���[*/;
	//�C�x���g�X���b�g�t���O
	bool EventRou_flg = false;
	//����ݒ�t���O
	bool Branch_flg = false;
	//�X���b�g�ϐ�
	int Rou_num = 0;
	//�C�x���g�X���b�g�ϐ�
	int P1_EventRou_num = 0/*1P�v���C���[*/, P2_EventRou_num = 0/*2P�v���C���[*/;
	//����ݒ�ϐ� 1 = ��,2 = ��,3 = ��,4 = ��
	int Branch_num = 0;
	//��l���ړ���
	int P1_PlayerMove_num = 0/*1P�v���C���[*/, P2_PlayerMove_num = 0/*2P�v���C���[*/;
	//--------------------------------------------
	//1P2P�؂�ւ��t���O
	bool P_Switching_flg = false;

	//�^�C�g��
	//�^�C�g���ʒu���
	float Title_x = 0.0f, Title_y = 0.0f;
	//�^�C�g���؂�ւ��t���O
	bool Title_flg = false;
	//�^�C�g���摜
	//static int Title_image = LoadGraph("image\\�X���b�g.png");

	//���[�v
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
		//��ʂ�������
		ClearDrawScreen();

		//���������\��
		if (P1_LR_flg == 1)
		{
			DrawFormatString(0, 50, GetColor(255, 255, 0), "�I������I���F�E");
		}
		else if (P1_LR_flg == 0)
		{
			DrawFormatString(0, 50, GetColor(255, 255, 0), "�I������I���F��");
		}
		else if (P1_UD_flg == 1)
		{
			DrawFormatString(0, 50, GetColor(255, 255, 0), "�I������I���F��");
		}
		else if (P1_UD_flg == 0)
		{
			DrawFormatString(0, 50, GetColor(255, 255, 0), "�I������I���F��");
		}

		//�ړ����ł͂Ȃ��ꍇ�L�[���͂��󂯕t����
		if (Move == 0) {
			//���[���b�g����--------------------------------------------------------------------
			//Enter�Ń��[���b�g��]�X�^�[�g
			if (CheckHitKey(KEY_INPUT_RETURN) == true && Roulette_Enter_Bottan == false) {
				if (Roulette == 0) { //���[���b�g��]�X�^�[�g
					RouDraw_flg = false; //�摜�\���ĊJ
					Roulette_Rotation = true; //���[���b�g��]�J�n
					Roulette_stop_Flg = true; //���[���b�g��]���e�L�X�g�I��
					square_rest_Flg = false;
					Roulette = 1; //Roulette 1�ֈړ�
					PlaySoundMem(roulette_sound, DX_PLAYTYPE_LOOP, TRUE);//���ʉ��Đ�
				}
				else if (Roulette == 1) { //���[���b�g��~
					Roulette_Rotation = false; //������
					Roulette_stop_Flg = false; //���[���b�g��]���e�L�X�g�I�t
					square_go_Flg = true; //�R�}�i�߂�e�L�X�g�I��
					Roulette = 2; //Roulette 2�ֈړ�
					StopSoundMem(roulette_sound);
					PlaySoundMem(roulette_dec_sound, DX_PLAYTYPE_BACK, TRUE);//���ʉ��Đ�
				}
				else if (Roulette == 2) { //�ړ��J�n
					//�C�x���g�X���b�g�t���O and ����ݒ�t���O��false�̎� and ����ݒ�ϐ���0�̎�
					P1_PlayerMove_Flg = true; //��l���ړ��J�n	
					RouDraw_flg = true; //���[���b�g�摜�\����~
					square_go_Flg = false; //�R�}�i�߂�e�L�X�g�I�t
					square_rest_Flg = true;
					Roulette = 0; //Roulette 0�ֈړ�
				}
				Roulette_Enter_Bottan = true;
			}
			else if (CheckHitKey(KEY_INPUT_RETURN) == false)
				Roulette_Enter_Bottan = false;
				Roulette_Flg = true; //���[���b�g�X�^�[�g�e�L�X�g�I��
				//two_times = false;

			//���[���b�g��]����
			if (Roulette_Rotation == true) {
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

			//��l���ړ�������������
			if (Rou_rect_y < 200) { //���[���b�g�؂���y�ʒu200�ȉ��̎�
				if (Rou_rect_x == 0) {
					Rou_num = 1; //1�X���b�g
				}
				else if (Rou_rect_x == 200) {
					Rou_num = 2; //2�X���b�g
				}
				else if (Rou_rect_x == 400) {
					Rou_num = 3; //3�X���b�g
				}
				//2�{�}�X�t���O��ON�Ȃ�2�{�ɂ���
				if (two_times == true)
				{
					P1_PlayerMove_num *= 2;
				}
			}
			else if (Rou_rect_y == 200) { //���[���b�g�؂���y�ʒu200�̎�
				if (Rou_rect_x == 0) {
					Rou_num = 4; //4�X���b�g
				}
				else if (Rou_rect_x == 200) {
					Rou_num = 5; //5�X���b�g
				}
				else if (Rou_rect_x == 400) {
					Rou_num = 6; //6�X���b�g
				}
			}

			//����ݒ�t���O
			if (Branch_flg == true && Roulette == 2) {
				//���򏈗�
				if (Rou_num > 3) {
					Branch_num = 3; //����ݒ� 3 = ��
				}
				else {
					Branch_num = 4; //����ݒ� 4 = ��
				}
			}
			//�C�x���g�X���b�g���菈��
			else if (EventRou_flg == true && Roulette == 2) {
				P1_EventRou_num = Rou_num; //�C�x���g�X���b�g
				EventRou_flg = false; //�C�x���g�X���b�g�t���O������
			}
			//�}�X�ړ�����
			else if(Branch_flg == false && EventRou_flg == false && Roulette == 0){
				P1_PlayerMove_num = 6; //�}�X�ړ�
			}

				//2�{�}�X�t���O��ON�Ȃ�2�{�ɂ���
				if (two_times == true)
				{
					P1_PlayerMove_num *= 2;
				}
			}
			//----------------------------------------------------------------------------------

			//�L�[���͂𓾂�
			Key = GetJoypadInputState(DX_INPUT_KEY_PAD1);


			//��~���͉�ʂ̃X�N���[���͍s��Ȃ�
			ScrollX = 0;
			ScrollY = 0;
		}
		
		//�ړ�����
		//�i���s�\�ȃ}�b�v�������ꍇ�͈ړ��ł��Ȃ�
		if (P1_PlayerMove_Flg == true)
		{
			//0 = �ǂɂ͈ړ��ł��Ȃ�
			if (MapData_P[PlayerY + MoveY][PlayerX + MoveX] == 0)
			{

				//0�ɂ͉������Ȃ�
			}
			else {
				//��l���̎���ɂ��铹���m�F���Ĉړ�����
				if (MapData_P[PlayerY][PlayerX] == 2 && (MapData_P[PlayerY][PlayerX + 1] == 1 || MapData_P[PlayerY][PlayerX + 1] >= 4)) {//�E�ړ�
					//�ړ��񐔂�1�̎�
					if (P1_PlayerMove_num == 1) {
						//�i�񂾕����Ɂu4�v������΁A�o�^�Ґ�����
						if (MapData_P[PlayerY][PlayerX + 1] == 4) {
							PlaySoundMem(subscriber_up_sound, DX_PLAYTYPE_BACK, TRUE);//�������Đ�
							P1_subscriber += 100;
							subscriber_up_time = 200;
						}
						//�i�񂾕����Ɂu5�v������΁A�o�^�Ґ�����
						if (MapData_P[PlayerY][PlayerX + 1] == 5) {
							PlaySoundMem(subscriber_down_sound, DX_PLAYTYPE_BACK, TRUE);//�������Đ�
							P1_subscriber -= 100;
							subscriber_down_time = 200;
						}
						//�i�񂾕����Ɂu7�v������΁A���񃋁[���b�g��2�{
						if (MapData_P[PlayerY][PlayerX + 1] == 7) {
							PlaySoundMem(subscriber_up_sound, DX_PLAYTYPE_BACK, TRUE);//�������Đ�
							two_times = true;
							two_times_messagetime = 200;
						}
						//�i�񂾕������u7�ȊO�v�Ȃ�A2�{�}�X�t���O��OFF�ɂ���
						if (MapData_P[PlayerY][PlayerX + 1] != 7 && two_times == true)
						{
							two_times = false;
						}
					}
					//(��l���}�b�v��)�i�񂾕����Ɂu9�v������΁A�S�[������
					if (MapData_P[PlayerY][PlayerX + 1] == 9) {
						PlaySoundMem(goal_sound, DX_PLAYTYPE_BACK, TRUE);//���ʉ��Đ�
						PlaySoundMem(goal_cheers_sound, DX_PLAYTYPE_BACK, TRUE);//���ʉ��Đ�
						goal_time = 200;
						//���ʂɂ���ď��ʃ{�[�i�X���Z
						if (P1_subscriber > P2_subscriber) {
							P1_subscriber += 10000; //1�� +10000�l
						}
						else if (P2_subscriber > P1_subscriber) {
							P1_subscriber += 5000; //2�� +5000�l
						}
					}
					MapData_P[PlayerY][PlayerX] = 3; //��l�����ʂ������͒ʂ�Ȃ�����
					MapData_P[PlayerY][PlayerX + 1] = 2; //�ʘH�Ɏ�l����ʂ�
					MoveX = 1.0f; //X�������ɃX�N���[��
					P1_LR_flg = 1; //�����؂�ւ� �E
				}
				else if (MapData_P[PlayerY][PlayerX] == 2 && (MapData_P[PlayerY][PlayerX - 1] == 1|| MapData_P[PlayerY][PlayerX - 1] >= 4)) {//���ړ�
					//�ړ��񐔂�1�̎�
					if (P1_PlayerMove_num == 1) {
						//�i�񂾕����Ɂu4�v������΁A�o�^�Ґ�����
						if (MapData_P[PlayerY][PlayerX - 1] == 4) {
							PlaySoundMem(subscriber_up_sound, DX_PLAYTYPE_BACK, TRUE);//�������Đ�
							P1_subscriber += 100;
							subscriber_up_time = 200;
						}
						//�i�񂾕����Ɂu5�v������΁A�o�^�Ґ�����
						if (MapData_P[PlayerY][PlayerX - 1] == 5) {
							PlaySoundMem(subscriber_down_sound, DX_PLAYTYPE_BACK, TRUE);//�������Đ�
							P1_subscriber -= 100;
							subscriber_down_time = 200;
						}
						//�i�񂾕����Ɂu7�v������΁A���񃋁[���b�g��2�{
						if (MapData_P[PlayerY][PlayerX - 1] == 7) {
							PlaySoundMem(subscriber_up_sound, DX_PLAYTYPE_BACK, TRUE);//�������Đ�
							two_times = true;
							two_times_messagetime = 200;
						}
						//�i�񂾕������u7�ȊO�v�Ȃ�A2�{�}�X�t���O��OFF�ɂ���
						if (MapData_P[PlayerY][PlayerX - 1] != 7 && two_times == true)
						{
							two_times = false;
						}
					}
					//(��l���}�b�v��)�i�񂾕����Ɂu9�v������΁A�S�[������
					if (MapData_P[PlayerY][PlayerX - 1] == 9) {
						PlaySoundMem(goal_sound, DX_PLAYTYPE_BACK, TRUE);//���ʉ��Đ�
						PlaySoundMem(goal_cheers_sound, DX_PLAYTYPE_BACK, TRUE);//���ʉ��Đ�
						goal_time = 200;
						//���ʂɂ���ď��ʃ{�[�i�X���Z
						if (P1_subscriber > P2_subscriber) {
							P1_subscriber += 10000;
						}
						else if (P2_subscriber > P1_subscriber) {
							P1_subscriber += 5000;
						}
					}
					MapData_P[PlayerY][PlayerX] = 3; //��l�����ʂ������͒ʂ�Ȃ�����
					MapData_P[PlayerY][PlayerX - 1] = 2; //�ʘH�Ɏ�l����ʂ�
					MoveX = -1.0f; //-X�������ɃX�N���[��
					P1_LR_flg = 0; //�����؂�ւ� ��
				}
				else if (MapData_P[PlayerY][PlayerX] == 2 && (MapData_P[PlayerY - 1][PlayerX] == 1|| MapData_P[PlayerY - 1][PlayerX] >= 4)) {//��ړ�
					//�ړ��񐔂�1�̎�
					if (P1_PlayerMove_num == 1) {
						//�i�񂾕����Ɂu4�v������΁A�o�^�Ґ�����
						if (MapData_P[PlayerY - 1][PlayerX] == 4) {
							PlaySoundMem(subscriber_up_sound, DX_PLAYTYPE_BACK, TRUE);//�������Đ�
							P1_subscriber += 100;
							subscriber_up_time = 200;
						}
						//�i�񂾕����Ɂu5�v������΁A�o�^�Ґ�����
						if (MapData_P[PlayerY - 1][PlayerX] == 5) {
							PlaySoundMem(subscriber_down_sound, DX_PLAYTYPE_BACK, TRUE);//�������Đ�
							P1_subscriber -= 100;
							subscriber_down_time = 200;
						}
						//�i�񂾕����Ɂu7�v������΁A���񃋁[���b�g��2�{
						if (MapData_P[PlayerY - 1][PlayerX] == 7) {
							PlaySoundMem(subscriber_up_sound, DX_PLAYTYPE_BACK, TRUE);//�������Đ�
							two_times = true;
							two_times_messagetime = 200;
						}
						//�i�񂾕������u7�ȊO�v�Ȃ�A2�{�}�X�t���O��OFF�ɂ���
						if (MapData_P[PlayerY - 1][PlayerX] != 7 && two_times == true)
						{
							two_times = false;
						}
					}
					//(��l���}�b�v��)�i�񂾕����Ɂu9�v������΁A�S�[������
					if (MapData_P[PlayerY - 1][PlayerX] == 9) {
						PlaySoundMem(goal_sound, DX_PLAYTYPE_BACK, TRUE);//���ʉ��Đ�
						PlaySoundMem(goal_cheers_sound, DX_PLAYTYPE_BACK, TRUE);//���ʉ��Đ�
						goal_time = 200;
						//���ʂɂ���ď��ʃ{�[�i�X���Z
						if (P1_subscriber > P2_subscriber) {
							P1_subscriber += 10000;
						}
						else if (P2_subscriber > P1_subscriber) {
							P1_subscriber += 5000;
						}
					}
					MapData_P[PlayerY][PlayerX] = 3; //��l�����ʂ������͒ʂ�Ȃ�����
					MapData_P[PlayerY - 1][PlayerX] = 2; //�ʘH�Ɏ�l����ʂ�
					MoveY = -1.0f; //-Y�������ɃX�N���[��
					P1_UD_flg = 1; //�����؂�ւ� ��
				}
				else if (MapData_P[PlayerY][PlayerX] == 2 && (MapData_P[PlayerY + 1][PlayerX] == 1 || MapData_P[PlayerY + 1][PlayerX] >= 4 )) {//���ړ�
					//�ړ��񐔂�1�̎�
					if (P1_PlayerMove_num == 1) {
						//�i�񂾕����Ɂu4�v������΁A�o�^�Ґ�����
						if (MapData_P[PlayerY + 1][PlayerX] == 4) {
							PlaySoundMem(subscriber_up_sound, DX_PLAYTYPE_BACK, TRUE);//�������Đ�
							P1_subscriber += 100;
							subscriber_up_time = 200;
						}
						//�i�񂾕����Ɂu5�v������΁A�o�^�Ґ�����
						if (MapData_P[PlayerY + 1][PlayerX] == 5) {
							PlaySoundMem(subscriber_down_sound, DX_PLAYTYPE_BACK, TRUE);//�������Đ�
							P1_subscriber -= 100;
							subscriber_down_time = 200;
						}
						//�i�񂾕����Ɂu7�v������΁A���񃋁[���b�g��2�{
						if (MapData_P[PlayerY + 1][PlayerX] == 7) {
							PlaySoundMem(subscriber_up_sound, DX_PLAYTYPE_BACK, TRUE);//�������Đ�
							two_times = true;
							two_times_messagetime = 200;
						}
						//�i�񂾕������u7�ȊO�v�Ȃ�A2�{�}�X�t���O��OFF�ɂ���
						if (MapData_P[PlayerY + 1][PlayerX] != 7 && two_times == true)
						{
							two_times = false;
						}
					}
					//(��l���}�b�v��)�i�񂾕����Ɂu9�v������΁A�S�[������
					if (MapData_P[PlayerY + 1][PlayerX] == 9) {
						PlaySoundMem(goal_sound, DX_PLAYTYPE_BACK, TRUE);//���ʉ��Đ�
						PlaySoundMem(goal_cheers_sound, DX_PLAYTYPE_BACK, TRUE);//���ʉ��Đ�
						goal_time = 200;
						//���ʂɂ���ď��ʃ{�[�i�X���Z
						if (P1_subscriber > P2_subscriber) {
							P1_subscriber += 10000;
						}
						else if (P2_subscriber > P1_subscriber) {
							P1_subscriber += 5000;
						}
					}
					MapData_P[PlayerY][PlayerX] = 3; //��l�����ʂ������͒ʂ�Ȃ�����
					MapData_P[PlayerY + 1][PlayerX] = 2; //�ʘH�Ɏ�l����ʂ�
					MoveY = 1.0f; //Y�������ɃX�N���[��
					P1_UD_flg = 0; //�����؂�ւ� ��
				}
				Move = 1; //�X�N���[���J�n
				PlaySoundMem(move_sound, DX_PLAYTYPE_BACK, TRUE);//�ړ����Đ�
			}
			
			
			MoveCounter = 0;
		}
		

		//�ړ����̏ꍇ�͈ړ��������s��
		if (Move == 1) {			
			MoveCounter++;
			if (P1_PlayerMove_Flg == true) {
				//������
				P1_PlayerMove_Flg = false;
				squares_cnt1 -= 1;
			}
			//�ړ��������I���������~���ɂ���
			if (MoveCounter == MOVE_FRAME) {
				if (Branch_flg == true) {
					//������
					Move = 0;
					MoveCounter = 0;
					P1_PlayerMove_num--; //�ړ��񐔌���
					RouDraw_flg = false; //�摜�\���ĊJ
				}
				else {
					//����ݒ�J�n����
					if (P1_PlayerMove_num > 1) { //�ړ��񐔂�0�ȏ�̎�
						P1_PlayerMove_Flg = true; //������x�ړ�������
						MoveCounter = 0;
						P1_PlayerMove_num--; //�ړ��񐔌���
					}
					else if (P1_PlayerMove_num == 1) { //�ړ��񐔂�1�̎�
						//������
						Move = 0;
						P1_PlayerMove_num = 0;
						Roulette = 0; //Roulette 0�ֈړ�
						RouDraw_flg = false; //�摜�\���ĊJ
					}
				}

				//�v���C���[�̈ʒu��ύX����
				PlayerX += MoveX;
				PlayerY += MoveY;

				//��~���͉�ʂ̃X�N���[���͍s��Ȃ�
				ScrollX = 0;
				ScrollY = 0;

				//�ړ��ʏ�����
				MoveX = 0.0f;
				MoveY = 0.0f;
			}
			else {
				//�o�ߎ��Ԃ���X�N���[���ʂ��Z�o����
				ScrollX = -(MoveX * MAP_SIZE * MoveCounter / MOVE_FRAME);
				ScrollY = -(MoveY * MAP_SIZE * MoveCounter / MOVE_FRAME);
			}
		}

		//ClearDrawScreen(); //�摜�N���A

		if (RouDraw_flg == false) {
			//���[���b�g�`�揈��
			DrawRectGraphF(
				Rou_x, Rou_y,  //�`��ʒu
				Rou_rect_x, Rou_rect_y, //�؂���J�n�ʒu
				RECR_MAX, RECR_MAX, //�؂���T�C�Y
				Rou_image,  //�؂��錳�摜
				FALSE, //���ߏ����t���O
				Rou_LR_flg //���]�����t���O
			);
		}

		//�}�b�v�ƃv���C���[��`��
		GraphDraw(ScrollX, ScrollY);

		//���b�Z�[�W�E�B���h�E�摜�ǂݍ���
		DrawRectGraphF(
			15, 420,  //�`��ʒu
			0, 0, //�؂���J�n�ʒu
			769, 187, //�؂���T�C�Y
			message_window_img,  //�؂��錳�摜
			TRUE //���ߏ����t���O
		);

		//�`�����l���o�^�Ґ������e�L�X�g
		subscriber_up_time--;
		if (subscriber_up_time > 0) {
			DrawFormatString(40, 470, GetColor(50, 255, 255), "�`�����l���o�^�Ґ������}�X");
			DrawFormatString(40, 500, GetColor(255, 255, 255), "�`�����l���o�^�Ґ���100�l�������I");
		}
		else{
			subscriber_up_time = 0;
		}

		//�`�����l���o�^�Ґ������e�L�X�g
		subscriber_down_time--;
		if (subscriber_down_time > 0) {
			DrawFormatString(40, 470, GetColor(255, 50, 255), "�`�����l���o�^�Ґ������}�X");
			DrawFormatString(40, 500, GetColor(255, 0, 0), "�`�����l���o�^�Ґ���100�l�������c");
		}
		else {
			subscriber_down_time = 0;
		}

		//2�{�}�X�e�L�X�g
		two_times_messagetime--;
		if (two_times_messagetime > 0) {
			DrawFormatString(40, 470, GetColor(50, 255, 255), "2�{�}�X�I");
			DrawFormatString(40, 500, GetColor(255, 255, 255), "����̃��[���b�g�̐���2�{�ɂȂ�܂�");
		}
		else {
			two_times_messagetime = 0;
		}

		//���[���b�g�X�^�[�g�w���e�L�X�g
		if (Roulette_Flg == true && Roulette_stop_Flg == false && square_go_Flg == false
			&& square_rest_Flg == true && RouDraw_flg == false && goal_time == 0
			&& subscriber_up_time == 0 && subscriber_down_time == 0 && two_times_messagetime == 0) {
			DrawFormatString(40, 470, GetColor(255, 255, 255), "Enter�L�[�Ń��[���b�g�X�^�[�g");
			if (two_times == true)
			{
				DrawFormatString(40, 505, GetColor(50, 255, 255), "2�{�`�����X�I");
				DrawFormatString(40, 525, GetColor(255, 255, 255), "���[���b�g�̏o���ځ~2�ɂȂ�܂�");
			}
		}
		else {
			Roulette_Flg == false;
		}

		//���[���b�g�X�g�b�v�w���e�L�X�g
		if (Roulette_stop_Flg == true && subscriber_up_time == 0 && subscriber_down_time == 0
			&& two_times_messagetime == 0) {
			DrawFormatString(40, 470, GetColor(255, 255, 255), "Enter�L�[�Ń��[���b�g�X�g�b�v");
			if (two_times == true)
			{
				DrawFormatString(40, 505, GetColor(50, 255, 255), "2�{�`�����X�I");
				DrawFormatString(40, 525, GetColor(255, 255, 255), "���[���b�g�̏o���ځ~2�ɂȂ�܂�");
			}
		}
		else {
			Roulette_stop_Flg == false;
		}

		//�R�}�i�߂�w���e�L�X�g
		if (square_go_Flg == true && subscriber_up_time == 0 && subscriber_down_time == 0
			&& two_times_messagetime == 0) {
			DrawFormatString(40, 470, GetColor(255, 255, 255), "Enter�L�[�ŃR�}��i�߂�");
			if (two_times == true)
			{
				DrawFormatString(40, 505, GetColor(50, 255, 255), "2�{�`�����X�I");
				DrawFormatString(40, 525, GetColor(255, 255, 255), "���[���b�g�̏o���ځ~2�ɂȂ�܂�");
			}
		}
		else {
			square_go_Flg == false;
		}

		//���Ɖ��}�X �e�L�X�g
		if (square_rest_Flg == true && RouDraw_flg == true && goal_time == 0
			&& subscriber_up_time == 0 && subscriber_down_time == 0 && two_times_messagetime == 0) {

			if (P1_PlayerMove_num == 1){
				DrawFormatString(40, 470, GetColor(255, 255, 255), "���ƁF1�}�X");
			}
			else if (P1_PlayerMove_num == 2) {
				DrawFormatString(40, 470, GetColor(255, 255, 255), "���ƁF2�}�X");
			}
			else if (P1_PlayerMove_num == 3) {
				DrawFormatString(40, 470, GetColor(255, 255, 255), "���ƁF3�}�X");
			}
			else if (P1_PlayerMove_num == 4) {
				DrawFormatString(40, 470, GetColor(255, 255, 255), "���ƁF4�}�X");
			}
			else if (P1_PlayerMove_num == 5) {
				DrawFormatString(40, 470, GetColor(255, 255, 255), "���ƁF5�}�X");
			}
			else if (P1_PlayerMove_num == 6) {
				DrawFormatString(40, 470, GetColor(255, 255, 255), "���ƁF6�}�X");
			}
			else if (P1_PlayerMove_num == 7) {
				DrawFormatString(40, 470, GetColor(255, 255, 255), "���ƁF7�}�X");
			}
			else if (P1_PlayerMove_num == 8) {
				DrawFormatString(40, 470, GetColor(255, 255, 255), "���ƁF8�}�X");
			}
			else if (P1_PlayerMove_num == 9) {
				DrawFormatString(40, 470, GetColor(255, 255, 255), "���ƁF9�}�X");
			}
			else if (P1_PlayerMove_num == 10) {
				DrawFormatString(40, 470, GetColor(255, 255, 255), "���ƁF10�}�X");
			}
			else if (P1_PlayerMove_num == 11) {
				DrawFormatString(40, 470, GetColor(255, 255, 255), "���ƁF11�}�X");
			}
			else if (P1_PlayerMove_num == 12) {
				DrawFormatString(40, 470, GetColor(255, 255, 255), "���ƁF12�}�X");
			}
		}
		else {
			square_rest_Flg == false;
		}

		//�S�[���e�L�X�g
		goal_time--;
		if (goal_time > 0 && subscriber_up_time == 0 && subscriber_down_time == 0
			&& two_times_messagetime == 0) {
			DrawFormatString(40, 470, GetColor(255, 0, 0), "�S�[���I");

			//1�ʂŃS�[�������ꍇ
			if(P1_subscriber > P2_subscriber){
				DrawFormatString(40, 500, GetColor(255, 255, 0), "���ʃ{�[�i�X 1�ʁF�`�����l���o�^�Ґ��{10000�l�I");
			}
			else if (P2_subscriber > P1_subscriber) {
				DrawFormatString(40, 500, GetColor(255, 255, 0), "���ʃ{�[�i�X 2�ʁF�`�����l���o�^�Ґ��{5000�l�I");
			}
		}
		else {
			goal_time = 0;
		}

		ScreenFlip(); //�o�b�N�o�b�t�@�Ɛ؂�ւ�

		//��O������������v���O�����I��
		if (ProcessMessage() == -1) break;
	}

	DxLib_End(); //dx���C�u�����I������

	return 0;
}
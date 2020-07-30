#pragma once
#include "DxLib.h"
#include "Header.h"

#define MAP_SIZE	50 //�}�b�v�`�b�v��̃h�b�g�T�C�Y
#define MAP_WIDTH	20 //�}�b�v�̕�
#define MAP_HEIGHT	20 //�}�b�v�̏c����
#define MOVE_FRAME	50 //�ړ��ɂ�����t���[����

#define RECR_MAX 200 //���[���b�g�؂��萔

//�}�b�v�̃f�[�^(20�}�X�~20�}�X)(0 = �ǁA1 = �`��}�X�A2 = �X�^�[�g�A3 = �S�[��)(125�}�X)
int MapData[MAP_HEIGHT][MAP_WIDTH] =
{
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } ,
	{ 0, 2, 0, 1, 1, 4, 1, 1, 1, 1,    5, 1, 1, 1, 1, 4, 1, 1, 5, 0 } ,
	{ 0, 1, 0, 8, 0, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0, 0, 0, 1, 0 } ,
	{ 0, 1, 0, 1, 1, 1, 1, 0, 0, 0,    0, 0, 1, 4, 1, 0, 0, 0, 1, 0 } ,
	{ 0, 4, 0, 0, 0, 0, 1, 0, 0, 3,    9, 9, 9, 0, 1, 0, 0, 0, 1, 0 } ,
	{ 0, 5, 0, 0, 0, 0, 5, 0, 0, 0,    0, 0, 0, 0, 1, 0, 0, 0, 1, 0 } ,
	{ 0, 1, 1, 1, 1, 7, 4, 0, 0, 0,    0, 0, 1, 1, 1, 0, 0, 0, 1, 0 } ,
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    0, 0, 1, 0, 0, 0, 0, 0, 1, 0 } ,
	{ 0, 1, 1, 1, 1, 1, 1, 1, 1, 1,    4, 1, 1, 0, 0, 0, 0, 0, 4, 0 } ,
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0, 0, 0, 1, 0 } ,

	{ 0, 1, 1, 1, 1, 1, 1, 1, 1, 1,    4, 1, 1, 1, 0, 0, 0, 0, 1, 0 } ,
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    0, 0, 0, 1, 0, 0, 0, 0, 1, 0 } ,
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    0, 0, 0, 1, 0, 0, 0, 0, 1, 0 } ,
	{ 0, 1, 1, 1, 1, 1, 1, 1, 1, 4,    1, 1, 1, 1, 0, 0, 0, 0, 1, 0 } ,
	{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0, 0, 0, 1, 0 } ,
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0, 0, 0, 1, 0 } ,
	{ 0, 1, 0, 0, 0, 1, 1, 1, 4, 1,    1, 1, 1, 1, 1, 1, 1, 0, 1, 0 } ,
	{ 0, 1, 1, 1, 1, 1, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0, 6, 4, 1, 0 } ,
	{ 0, 0, 0, 0, 0, 1, 1, 1, 4, 1,    1, 1, 1, 1, 1, 1, 1, 0, 0, 0 } ,
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } ,
};
//��l���p�̃}�b�v�̃f�[�^(20�}�X�~20�}�X)(0 = �ǁA1 = �`��}�X�A2 = ��l���A3 = �ʉߌ�}�X)(125�}�X)
int MapData_P[MAP_HEIGHT][MAP_WIDTH] =
{
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } ,
	{ 0, 2, 0, 1, 1, 4, 1, 1, 1, 1,    5, 1, 1, 1, 1, 1, 1, 1, 5, 0 } ,
	{ 0, 1, 0, 1, 0, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0, 0, 0, 1, 0 } ,
	{ 0, 1, 0, 1, 1, 1, 1, 0, 0, 0,    0, 0, 1, 1, 1, 0, 0, 0, 1, 0 } ,
	{ 0, 4, 0, 0, 0, 0, 1, 0, 0, 9,    1, 1, 1, 0, 1, 0, 0, 0, 1, 0 } ,
	{ 0, 5, 0, 0, 0, 0, 5, 0, 0, 0,    0, 0, 0, 0, 1, 0, 0, 0, 1, 0 } ,
	{ 0, 1, 1, 1, 1, 1, 4, 0, 0, 0,    0, 0, 1, 1, 1, 0, 0, 0, 1, 0 } ,
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    0, 0, 1, 0, 0, 0, 0, 0, 1, 0 } ,
	{ 0, 1, 1, 1, 1, 1, 1, 1, 1, 1,    1, 1, 1, 0, 0, 0, 0, 0, 1, 0 } ,
	{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0, 0, 0, 1, 0 } ,

	{ 0, 1, 1, 1, 1, 1, 1, 1, 1, 1,    1, 1, 1, 1, 0, 0, 0, 0, 1, 0 } ,
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    0, 0, 0, 1, 0, 0, 0, 0, 1, 0 } ,
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    0, 0, 0, 1, 0, 0, 0, 0, 1, 0 } ,
	{ 0, 1, 1, 1, 1, 1, 1, 1, 1, 1,    1, 1, 1, 1, 0, 0, 0, 0, 1, 0 } ,
	{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0, 0, 0, 1, 0 } ,
	{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0, 0, 0, 1, 0 } ,
	{ 0, 1, 0, 0, 0, 1, 1, 1, 1, 1,    1, 1, 1, 1, 1, 1, 1, 0, 1, 0 } ,
	{ 0, 1, 1, 1, 1, 1, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0, 1, 1, 1, 0 } ,
	{ 0, 0, 0, 0, 0, 1, 1, 1, 1, 1,    1, 1, 1, 1, 1, 1, 1, 0, 0, 0 } ,
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } ,
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
int squares_cnt1 = 125;

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
	static int Double = LoadGraph("image\\�T�C�R���Q�{�}�X.png");//�u7�v
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

		//-----------------------------------------------------------------------
		//UI�����w�i
	DrawBox(0, 0, 800, 50, GetColor(0, 0, 0), TRUE);//�`��
	//������`�悷��-------------------------------------------------------------------
	//�o�^�Ґ�
	DrawFormatString(7, 7, GetColor(255, 255, 255), "1P�`�����l���o�^�Ґ��F%d�l", P1_subscriber);
	DrawFormatString(7, 29, GetColor(255, 255, 255), "2P�`�����l���o�^�Ґ��F%d�l", P2_subscriber);
	//�S�[���܂ł̕���
	DrawFormatString(270, 18, GetColor(255, 255, 255), "�S�[���܂�");
	DrawFormatString(365, 7, GetColor(255, 255, 255), "1P�F����%d��", squares_cnt1);
	DrawFormatString(365, 29, GetColor(255, 255, 255), "2P�F����30��");
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
	int goal_time = 0;

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

	move_sound = LoadSoundMem("music\\�R�}�ړ�.mp3");
	roulette_sound = LoadSoundMem("music\\���[���b�g.mp3");
	roulette_dec_sound = LoadSoundMem("music\\���[���b�g����.mp3");
	subscriber_up_sound = LoadSoundMem("music\\�o�^�Ґ�������.mp3");
	subscriber_down_sound = LoadSoundMem("music\\�o�^�Ґ�������.mp3");

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

	//���L
	//��l���ړ��J�n�t���O
	bool P1_PlayerMove_Flg = false/*1P�v���C���[*/, P2_PlayerMove_Flg = false/*2P�v���C���[*/;
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
				if (Roulette == 0) {
					//������		
					Roulette_Rotation = true; //���[���b�g��]�J�n
					Roulette = 1; //Roulette 1�ֈړ�
					PlaySoundMem(roulette_sound, DX_PLAYTYPE_LOOP, TRUE);//���ʉ��Đ�
				}
				else if (Roulette == 1) {
					//���[���b�g��~	
					Roulette_Rotation = false; //������
					Roulette = 2; //Roulette 2�ֈړ�
					StopSoundMem(roulette_sound);
					PlaySoundMem(roulette_dec_sound, DX_PLAYTYPE_BACK, TRUE);//���ʉ��Đ�
				}
				else if (Roulette == 2) {
					P1_PlayerMove_Flg = true; //��l���ړ��J�n	
					RouDraw_flg = true; //���[���b�g�摜�\����~
					Roulette = 0; //Roulette 0�ֈړ�
				}
				Roulette_Enter_Bottan = true;
			}
			else if (CheckHitKey(KEY_INPUT_RETURN) == false)
				Roulette_Enter_Bottan = false;

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
					P1_PlayerMove_num = 1; //1�}�X�ړ�
				}
				else if (Rou_rect_x == 200) {
					P1_PlayerMove_num = 2; //2�}�X�ړ�
				}
				else if (Rou_rect_x == 400) {
					P1_PlayerMove_num = 3; //3�}�X�ړ�
				}
			}
			else if (Rou_rect_y == 200) { //���[���b�g�؂���y�ʒu200�̎�
				if (Rou_rect_x == 0) {
					P1_PlayerMove_num = 4; //4�}�X�ړ�
				}
				else if (Rou_rect_x == 200) {
					P1_PlayerMove_num = 5; //5�}�X�ړ�
				}
				else if (Rou_rect_x == 400) {
					P1_PlayerMove_num = 6; //6�}�X�ړ�
				}
			}
			//----------------------------------------------------------------------------------

			//�L�[���͂𓾂�
			Key = GetJoypadInputState(DX_INPUT_KEY_PAD1);

			//�i���s�\�ȃ}�b�v�������ꍇ�͈ړ��ł��Ȃ�
			if (P1_PlayerMove_Flg == true)
			{
				//0 = �ǂɂ͈ړ��ł��Ȃ�
				if (MapData_P[PlayerY + MoveY][PlayerX + MoveX] == 0)
				{
					//0�ɂ͉������Ȃ�
				}
				else {
					//���[���b�g�ɕ\�����ꂽ�������ړ�������
					for (; 0 < P1_PlayerMove_num; P1_PlayerMove_num--)
					{
						//�}�b�v�ǂݎ��
						for (int m_y = 0; m_y < MAP_HEIGHT; m_y++) {
							for (int m_x = 0; m_x < MAP_WIDTH; m_x++) {
								//��l���̎���ɂ��铹���m�F���Ĉړ�����
								if (MapData_P[m_y][m_x] == 2 && (MapData_P[PlayerY][PlayerX + 1] == 1
									|| MapData_P[PlayerY][PlayerX + 1] == 4
									|| MapData_P[PlayerY][PlayerX + 1] == 5)) {//�E�ړ�
									//�i�񂾕�����4������΁A�o�^�Ґ�����
									if (MapData_P[PlayerY][PlayerX + 1] == 4){
										PlaySoundMem(subscriber_up_sound, DX_PLAYTYPE_BACK, TRUE);//�������Đ�
										P1_subscriber += 100;
										subscriber_up_time = 200;
									}
									//�i�񂾕�����5������΁A�o�^�Ґ�����
									if (MapData_P[PlayerY][PlayerX + 1] == 5){
										PlaySoundMem(subscriber_down_sound, DX_PLAYTYPE_BACK, TRUE);//�������Đ�
										P1_subscriber -= 100;
										subscriber_down_time = 200;
									}
									//�i�񂾕�����9������΁A�S�[������
									if (MapData_P[PlayerY][PlayerX + 1] == 9) {
										goal_time = 200;
									}
									PlaySoundMem(move_sound, DX_PLAYTYPE_BACK, TRUE);//�ړ����Đ�
									MapData_P[m_y][m_x] = 3; //��l�����ʂ������͒ʂ�Ȃ�����
									MapData_P[m_y][m_x + 1] = 2; //�ʘH�Ɏ�l����ʂ�
									Move = 1; //�X�N���[���J�n
									MoveX = 1.0f; //X�������ɃX�N���[��
									P1_LR_flg = 1; //�����؂�ւ� �E
								}
								else if (MapData_P[m_y][m_x] == 2 && (MapData_P[PlayerY][PlayerX - 1] == 1
									|| MapData_P[PlayerY][PlayerX - 1] == 4
									|| MapData_P[PlayerY][PlayerX - 1] == 5)) {//���ړ�
									//�i�񂾕�����4������΁A�o�^�Ґ�����
									if (MapData_P[PlayerY][PlayerX - 1] == 4){
										PlaySoundMem(subscriber_up_sound, DX_PLAYTYPE_BACK, TRUE);//�������Đ�
										P1_subscriber += 100;
										subscriber_up_time = 200;
									}
									//�i�񂾕�����5������΁A�o�^�Ґ�����
									if (MapData_P[PlayerY][PlayerX - 1] == 5){
										PlaySoundMem(subscriber_down_sound, DX_PLAYTYPE_BACK, TRUE);//�������Đ�
										P1_subscriber -= 100;
										subscriber_down_time = 200;
									}
									//�i�񂾕�����9������΁A�S�[������
									if (MapData_P[PlayerY][PlayerX - 1] == 9) {
										goal_time = 200;
									}
									PlaySoundMem(move_sound, DX_PLAYTYPE_BACK, TRUE);//�ړ����Đ�
									MapData_P[m_y][m_x] = 3; //��l�����ʂ������͒ʂ�Ȃ�����
									MapData_P[m_y][m_x - 1] = 2; //�ʘH�Ɏ�l����ʂ�
									Move = 1; //�X�N���[���J�n
									MoveX = -1.0f; //-X�������ɃX�N���[��
									P1_LR_flg = 0; //�����؂�ւ� ��
								}
								else if (MapData_P[m_y][m_x] == 2 && (MapData_P[PlayerY - 1][PlayerX] == 1
									|| MapData_P[PlayerY - 1][PlayerX] == 4
									|| MapData_P[PlayerY - 1][PlayerX] == 5)) {//��ړ�
									//�i�񂾕�����4������΁A�o�^�Ґ�����
									if (MapData_P[PlayerY - 1][PlayerX] == 4){
										PlaySoundMem(subscriber_up_sound, DX_PLAYTYPE_BACK, TRUE);//�������Đ�
										P1_subscriber += 100;
										subscriber_up_time = 200;
									}
									//�i�񂾕�����5������΁A�o�^�Ґ�����
									if (MapData_P[PlayerY - 1][PlayerX] == 5){
										PlaySoundMem(subscriber_down_sound, DX_PLAYTYPE_BACK, TRUE);//�������Đ�
										P1_subscriber -= 100;
										subscriber_down_time = 200;
									}
									//�i�񂾕�����9������΁A�S�[������
									if (MapData_P[PlayerY - 1][PlayerX] == 9) {
										goal_time = 200;
									}
									PlaySoundMem(move_sound, DX_PLAYTYPE_BACK, TRUE);//�ړ����Đ�
									MapData_P[m_y][m_x] = 3; //��l�����ʂ������͒ʂ�Ȃ�����
									MapData_P[m_y - 1][m_x] = 2; //�ʘH�Ɏ�l����ʂ�
									Move = 1; //�X�N���[���J�n
									MoveY = -1.0f; //-Y�������ɃX�N���[��
									P1_UD_flg = 1; //�����؂�ւ� ��
								}
								else if (MapData_P[m_y][m_x] == 2 && (MapData_P[PlayerY + 1][PlayerX] == 1
									|| MapData_P[PlayerY + 1][PlayerX] == 4
									|| MapData_P[PlayerY + 1][PlayerX] == 5)) {//���ړ�
									//�i�񂾕�����4������΁A�o�^�Ґ�����
									if (MapData_P[PlayerY + 1][PlayerX] == 4){
										PlaySoundMem(subscriber_up_sound, DX_PLAYTYPE_BACK, TRUE);//�������Đ�
										P1_subscriber += 100;
										subscriber_up_time = 200;
									}
									//�i�񂾕�����5������΁A�o�^�Ґ�����
									if (MapData_P[PlayerY + 1][PlayerX] == 5){
										PlaySoundMem(subscriber_down_sound, DX_PLAYTYPE_BACK, TRUE);//�������Đ�
										P1_subscriber -= 100;
										subscriber_down_time = 200;
									}
									//�i�񂾕�����9������΁A�S�[������
									if (MapData_P[PlayerY + 1][PlayerX] == 9) {
										goal_time = 200;
									}
									PlaySoundMem(move_sound, DX_PLAYTYPE_BACK, TRUE);//�ړ����Đ�
									MapData_P[m_y][m_x] = 3; //��l�����ʂ������͒ʂ�Ȃ�����
									MapData_P[m_y + 1][m_x] = 2; //�ʘH�Ɏ�l����ʂ�
									Move = 1; //�X�N���[���J�n
									MoveY = 1.0f; //Y�������ɃX�N���[��
									P1_UD_flg = 0; //�����؂�ւ� ��
								}
							}
						}
					}

					MoveCounter = 0;
				}				
			}

			//��~���͉�ʂ̃X�N���[���͍s��Ȃ�
			ScrollX = 0;
			ScrollY = 0;
		}

		//�ړ����̏ꍇ�͈ړ��������s��
		if (Move == 1) {
			MoveCounter++;
			if (P1_PlayerMove_Flg == true) {
				//������
				P1_PlayerMove_Flg = false;
			}
			//�ړ��������I���������~���ɂ���
			if (MoveCounter == MOVE_FRAME) {
				//������
				Move = 0;
				RouDraw_flg = false;
				Roulette = 0; //Roulette 0�ֈړ�

				//�v���C���[�̈ʒu��ύX����
				PlayerX += MoveX;
				PlayerY += MoveY;

				//��~���͉�ʂ̃X�N���[���͍s��Ȃ�
				ScrollX = 0;
				ScrollY = 0;
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

		subscriber_up_time--;
		if (subscriber_up_time > 0) {
			//�w�i�摜�ǂݍ���
			DrawRectGraphF(
				15, 420,  //�`��ʒu
				0, 0, //�؂���J�n�ʒu
				769, 187, //�؂���T�C�Y
				message_window_img,  //�؂��錳�摜
				TRUE //���ߏ����t���O
			);
			DrawFormatString(40, 470, GetColor(50, 255, 255), "�`�����l���o�^�Ґ������}�X");
			DrawFormatString(40, 500, GetColor(255, 255, 255), "�`�����l���o�^�Ґ���100�l�������I");
		}
		else{
			subscriber_up_time = 0;
		}

		subscriber_down_time--;
		if (subscriber_down_time > 0) {
			//�w�i�摜�ǂݍ���
			DrawRectGraphF(
				15, 420,  //�`��ʒu
				0, 0, //�؂���J�n�ʒu
				769, 187, //�؂���T�C�Y
				message_window_img,  //�؂��錳�摜
				TRUE //���ߏ����t���O
			);
			DrawFormatString(40, 470, GetColor(255, 50, 255), "�`�����l���o�^�Ґ������}�X");
			DrawFormatString(40, 500, GetColor(255, 0, 0), "�`�����l���o�^�Ґ���100�l�������c");
		}
		else {
			subscriber_down_time = 0;
		}

		goal_time--;
		if (goal_time > 0) {
			DrawRectGraphF(
				15, 420,  //�`��ʒu
				0, 0, //�؂���J�n�ʒu
				769, 187, //�؂���T�C�Y
				message_window_img,  //�؂��錳�摜
				TRUE //���ߏ����t���O
			);
			DrawFormatString(40, 470, GetColor(255, 0, 0), "�S�[���I");
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
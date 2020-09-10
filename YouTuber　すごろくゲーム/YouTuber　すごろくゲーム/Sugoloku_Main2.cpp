#pragma once
#include "DxLib.h"
#include "Header.h"

#define MAP_SIZE	50 //�}�b�v�`�b�v��̃h�b�g�T�C�Y
#define MAP_WIDTH	20 //�}�b�v�̕�
#define MAP_HEIGHT	20 //�}�b�v�̏c����
#define MOVE_FRAME	50 //�ړ��ɂ�����t���[����

#define RECR_MAX 200 //���[���b�g�؂��萔

bool Player1_DrawFlg = false;
bool Player2_DrawFlg = false;

//���[�h�Z���N�g
int SelectMode() {
	int mode;

	while (1) {
		ClearDrawScreen();


		DrawString(0, 0, "�v���C���[�I���@0:1P�@1:2P", GetColor(255, 255, 255));
		mode = KeyInputNumber(0, 16, 1, 0, FALSE);
		if (mode == 0) {
			DrawString(0, 32, "�v���C���[�́A1P", GetColor(255, 255, 255));
			Player1_DrawFlg = true;
		}
		else {
			DrawString(0, 32, "�v���C���[�́A2P", GetColor(255, 255, 255));
			Player2_DrawFlg = true;
		}
		DrawString(0, 64, "����ŗǂ��ł����H", GetColor(255, 255, 255));
		DrawString(0, 80, "0...������ 1...�͂�", GetColor(255, 255, 255));
		if (KeyInputNumber(0, 96, 1, 0, FALSE))break;
	}
	return mode;
}

//IP����
IPDATA IP_set() {
	IPDATA ip;

	while (1)
	{
		ClearDrawScreen();

		DrawString(0, 0, "IP����(172.17.157.81)", GetColor(255, 255, 255));
		ip.d1 = KeyInputNumber(0, 16, 255, 0, FALSE);
		ip.d2 = KeyInputNumber(0, 16, 255, 0, FALSE);
		ip.d3 = KeyInputNumber(0, 16, 255, 0, FALSE);
		ip.d4 = KeyInputNumber(0, 16, 255, 0, FALSE);
		DrawFormatString(0, 16, GetColor(255, 0, 0),
			"IP:%d:%d:%d:%d",
			ip.d1,
			ip.d2,
			ip.d3,
			ip.d4
		);

		DrawString(0, 32, "����ŗǂ��ł����H", GetColor(255, 255, 255));
		DrawString(0, 48, "0...������ 1...�͂�", GetColor(255, 255, 255));
		if (KeyInputNumber(0, 64, 1, 0, FALSE))break;
	}
	return ip;
}

/*�}�b�v�̃f�[�^(20�}�X�~20�}�X)(0 = �ǁA1 = �`��}�X�A2 = �X�^�[�g�A3 = �S�[��
4 = �o�^�ґ����A 5 = �o�^�Ҍ����A6 = ����_�A7 = 2�{�}�X�A8 = �C�x���g�}�X
9 = �t�]�}�X)(150�}�X)*/
int MapData[MAP_HEIGHT][MAP_WIDTH] =
{
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 2, 0, 1, 1, 4, 1, 1, 1, 5, 1, 1, 4, 1, 1, 4, 1, 1, 5, 0 },
	{ 0, 1, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
	{ 0, 1, 0, 1, 1, 1, 5, 0, 0, 0, 0, 0, 4, 1, 5, 1, 0, 0, 1, 0 },
	{ 0, 4, 0, 0, 0, 0, 1, 0, 3, 1, 9, 9, 9, 0, 0, 8, 0, 0, 1, 0 },
	{ 0, 5, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 5, 0 },
	{ 0, 1, 1, 1, 1, 7, 5, 0, 4, 1, 1, 4, 5, 5, 4, 5, 0, 0, 1, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
	{ 0, 1, 5, 1, 1, 7, 1, 1, 5, 0, 1, 8, 1, 0, 1, 7, 1, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 5, 5, 5, 0, 4, 0, 1, 0 },
	{ 0, 1, 5, 1, 1, 8, 1, 4, 1, 1, 4, 0, 0, 0, 0, 0, 1, 0, 1, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0 },
	{ 0, 1, 5, 1, 0, 5, 1, 4, 0, 0, 0, 0, 4, 4, 4, 0, 5, 0, 7, 0 },
	{ 0, 4, 0, 1, 0, 1, 0, 1, 0, 5, 1, 1, 1, 0, 1, 8, 1, 0, 1, 0 },
	{ 0, 1, 0, 4, 1, 8, 0, 7, 1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
	{ 0, 1, 0, 1, 4, 4, 4, 4, 5, 1, 4, 1, 4, 4, 1, 5, 1, 0, 1, 0 },
	{ 0, 8, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 4, 5, 0 },
	{ 0, 0, 0, 1, 5, 5, 5, 5, 4, 1, 5, 1, 5, 5, 1, 4, 1, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },

};
/*��l���p�̃}�b�v�̃f�[�^(20�}�X�~20�}�X)(0 = �ǁA1 = �`��}�X�A2 = ��l���A3 = �ʉߌ�}�X
4 = �o�^�ґ����A 5 = �o�^�Ҍ����A 6 = ����_ 7 = 2�{�}�X�A8 = ����_�I�_(�\��)
9 = �S�[���}�X�A10 = �C�x���g�}�X�A11 = �t�]�}�X 12 = ����ʍs�}�X(��)) (150�}�X)*/
int MapData_P[MAP_HEIGHT][MAP_WIDTH] =
{
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 2, 0, 1, 1, 4, 1, 1, 1, 5, 1, 1, 4, 1, 1, 4, 1, 1, 5, 0 },
	{ 0, 1, 0,10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
	{ 0, 1, 0, 1, 1, 1, 5, 0, 0, 0, 0, 0, 4, 1, 5, 1, 0, 0, 1, 0 },
	{ 0, 4, 0, 0, 0, 0, 1, 0, 9, 1,11,11,11, 0, 0,10, 0, 0, 1, 0 },
	{ 0, 5, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 5, 0 },
	{ 0, 1, 1, 1, 1, 7, 5, 0, 4, 1, 1, 4, 5, 5, 4, 5, 0, 0, 1, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
	{ 0, 1, 5, 1, 1, 7, 1, 1, 5, 0, 1,10, 1, 0, 1, 7, 1, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 5, 5, 5, 0, 4, 0, 1, 0 },
	{ 0, 1, 5, 1, 1,10, 1, 4, 1, 1, 4, 0, 0, 0, 0, 0, 1, 0, 1, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0 },
	{ 0, 1, 5, 1, 0, 5, 1, 4, 0, 0, 0, 0, 4, 4, 4, 0, 5, 0, 7, 0 },
	{ 0, 4, 0, 1, 0, 1, 0, 1, 0, 5, 1, 1, 1, 0, 1,10, 1, 0, 1, 0 },
	{ 0, 1, 0, 4, 1,10, 0, 7, 1, 4, 0, 0, 0, 0, 0, 0, 0, 0,10, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
	{ 0, 1, 0, 1, 4, 4, 4, 4, 5, 1, 4, 1, 4, 4, 1, 5, 1, 0, 1, 0 },
	{ 0,10,12, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 4, 5, 0 },
	{ 0, 0, 0, 1, 5, 5, 5, 5, 4, 1, 5, 1, 5, 5, 1, 4, 1, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
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
int P1_subscriber = 1000; //1P
int P2_subscriber = 1000; //2P
int P_subscriber = 0; //�v�Z�p
int Get_P1_subscriber() { return P1_subscriber; }
int Get_P2_subscriber() { return P2_subscriber; }


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
	static int image2 = LoadGraph("image\\�v���C���[2.png");
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
				if (Player1_DrawFlg == true) { //1P�v���C���[
					DrawRectGraphF(
						j * MAP_SIZE + ScrollX, i * MAP_SIZE + ScrollY,  //�`��ʒu
						0, 0, //�؂���J�n�ʒu
						MAP_SIZE, MAP_SIZE, //�؂���T�C�Y
						image,  //�؂��錳�摜
						TRUE //���ߏ����t���O
					);
				}
				if (Player2_DrawFlg == true) { //2P�v���C���[
					DrawRectGraphF(
						j * MAP_SIZE + ScrollX, i * MAP_SIZE + ScrollY,  //�`��ʒu
						0, 0, //�؂���J�n�ʒu
						MAP_SIZE, MAP_SIZE, //�؂���T�C�Y
						image2,  //�؂��錳�摜
						TRUE //���ߏ����t���O
					);
				}
			}
		}
	}

	//�`�����l���o�^�Ґ��ʌv�Z
	if (Player1_DrawFlg == true && P_subscriber != 0) {
		P1_subscriber += P_subscriber;
		P_subscriber = 0;
		//0�ȉ��ɂȂ�Ȃ�����
		if (P1_subscriber <= 0) {
			P1_subscriber = 0;
		}
	}
	if (Player2_DrawFlg == true && P_subscriber != 0) {
		P2_subscriber += P_subscriber;
		P_subscriber = 0;
		//0�ȉ��ɂȂ�Ȃ�����
		if (P2_subscriber <= 0) {
			P2_subscriber = 0;
		}
	}

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
	int SendPort, RecvPort; //send���� Recv�󂯂�

	//����M�f�[�^�����p
	char StrBuf[256] = { "NULL" };

	SetOutApplicationLogValidFlag(FALSE); //Log.txt�𐶐����Ȃ��悤�ɐݒ�
	ChangeWindowMode(TRUE); //window���[�h
	SetGraphMode(800, 600, 32); //window�T�C�Y800*600 32bit
	SetAlwaysRunFlag(TRUE); //�o�b�N�O���E���h�ł����s�o����悤�ɂ���
	SetDoubleStartValidFlag(TRUE); //���d�N���̋���
	//SetBackgroundColor(0, 100, 0); //�w�i�F

	int Key, i;
	int ScrollX, ScrollY;
	int MapDrawPointX, MapDrawPointY;		//�`�悷��}�b�v���W�l
	int DrawMapChipNumX, DrawMapChipNumY;	//�`�悷��}�b�v�`�b�v�̐�
	int subscriber_up_time = 0;
	int subscriber_down_time = 0;
	int two_times_messagetime = 0;
	int event_messagetime = 0;
	int goal_time = 0;
	bool Roulette_Flg = false; //���[���b�g�e�L�X�g�p�t���O
	bool Roulette_stop_Flg = false; //���[���b�g�e�L�X�g�p�t���O
	bool square_go_Flg = false; //���[���b�g�e�L�X�g�p�t���O
	bool square_rest_Flg = true; //���[���b�g�e�L�X�g�p�t���O
	bool Event_messagetime_Flg = false; //�C�x���g�e�L�X�g�p�t���O
	bool Branch_destination_Flg = false; //����C�x���g�p�t���O
	bool Goal_sound_Flg1 = false; //�S�[����ړ�������p�t���O

	//������
	if (DxLib_Init() == -1) { //DX���C�u��������������
		return -1;				//�G���[���N�����璼���ɏI��
	}
	if (DxLib_Init() < 0) {
		return -1;
	}

	//���[�h�̃Z���N�g
	int mode = SelectMode();

	//window�̖��O
	if (mode == 0) {
		SetWindowText("1P");
		SendPort = 41; //41
		RecvPort = 40; //40
	}
	else {
		SetWindowText("2P");
		SendPort = 40; //40
		RecvPort = 41; //41
	}

	//�`����ʂ𗠉�ʂɂ���
	SetDrawScreen(DX_SCREEN_BACK);

	//�摜�ǂݍ���(�ustatic int�v�łȂ��ƁA��������������������̂Œ���)
	static int Rou_image = LoadGraph("image\\�X���b�g�g�t��.png");//���[���b�g
	static int message_window_img = LoadGraph("image\\���b�Z�[�W�E�B���h�E.png");//�u9�v
	static int back_img1 = LoadGraph("image\\�w�i�i���j.jpg");

	//BGM�Đ�
	PlaySoundFile("music\\���C��BGM.mp3", DX_PLAYTYPE_LOOP);

	int move_sound = 0;
	int roulette_sound = 0;
	int roulette_dec_sound = 0;
	int subscriber_up_sound = 0;
	int subscriber_down_sound = 0;
	int two_times_sound = 0;
	int event_sound = 0;
	int goal_sound = 0;
	int goal_cheers_sound = 0;

	move_sound = LoadSoundMem("music\\�R�}�ړ�.mp3");
	roulette_sound = LoadSoundMem("music\\���[���b�g.mp3");
	roulette_dec_sound = LoadSoundMem("music\\���[���b�g����.mp3");
	subscriber_up_sound = LoadSoundMem("music\\�o�^�Ґ�������.mp3");
	subscriber_down_sound = LoadSoundMem("music\\�o�^�Ґ�������.mp3");
	two_times_sound = LoadSoundMem("music\\2�{�}�X��.mp3");
	event_sound = LoadSoundMem("music\\�C�x���g�}�X��.mp3");
	goal_sound = LoadSoundMem("music\\�S�[����.mp3");
	goal_cheers_sound = LoadSoundMem("music\\�S�[������.mp3");

	//�v���C���[�̏����ʒu���Z�b�g
	PlayerX = 1;
	PlayerY = 1;

	//�ŏ��͒�~��(0)�ɂ��Ă���
	Move = 0;

	//�v���C���[----------------------------------
	//���E�����t���O
	bool P1_LR_flg = 1/*1P�v���C���[*/, P2_LR_flg = 1/*2P�v���C���[*/;
	//�㉺�����t���O
	bool P1_UD_flg = 0/*1P�v���C���[*/, P2_UD_flg = 0/*2P�v���C���[*/;
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
	bool EventRou_flg2 = false;
	bool EventRou_flg3 = false;
	//����ݒ�t���O
	bool Branch_flg = false;
	//��l�������ݒ�t���O
	bool P1_PlayerMove_Branch_destination_Up_flg = false; //��
	bool P1_PlayerMove_Branch_destination_Down_flg = false; //��
	//�X���b�g�ϐ�
	int Rou_num = 0;
	//�C�x���g�X���b�g�ϐ�
	int P1_EventRou_num = 0/*1P�v���C���[*/, P2_EventRou_num = 0/*2P�v���C���[*/;
	//����ݒ�ϐ� 1 = ��,2 = �� 
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
	/*Player1_DrawFlg = false;
	Player2_DrawFlg = false;*/
	//����M�p�f�[�^
	char name[15] = "name";
	//Data* data = new Data(x, y, name);

	//IP�̐ݒ�
	IPDATA IP = IP_set();

	//�ʐM�p�\�P�b�g�n���h��
	int NetUDPHandle = MakeUDPSocket(SendPort);

	//���[�v
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
		//��ʂ�������
		ClearDrawScreen();

		//�w�i�摜�ǂݍ���
		DrawRectGraphF(
			0, 50,  //�`��ʒu
			0, 0, //�؂���J�n�ʒu
			800, 550, //�؂���T�C�Y
			back_img1,  //�؂��錳�摜
			FALSE //���ߏ����t���O
		);

		//�ړ����ł͂Ȃ��ꍇ�L�[���͂��󂯕t����
		if (Move == 0) {
			//���[���b�g����--------------------------------------------------------------------
			//Enter�Ń��[���b�g��]�X�^�[�g(event_messagetime��0�ȊO�̎��̓L�[���͂��󂯕t���Ȃ�)
			if (CheckHitKey(KEY_INPUT_RETURN) == true && Roulette_Enter_Bottan == false && event_messagetime == 0) {
				if (Roulette == 0) { //���[���b�g��]�X�^�[�g
					Rou_num = 0; //�X���b�g�ϐ�������
					RouDraw_flg = false; //�摜�\���ĊJ
					Roulette_Rotation = true; //���[���b�g��]�J�n
					Roulette_stop_Flg = true; //���[���b�g��]���e�L�X�g�I��
					square_rest_Flg = false;
					Event_messagetime_Flg = false;
					Roulette = 1; //Roulette 1�ֈړ�
					PlaySoundMem(roulette_sound, DX_PLAYTYPE_LOOP, TRUE);//���ʉ��Đ�
					//�C�x���g�I������
					if (EventRou_flg3 == true) {
						EventRou_flg = false;
						EventRou_flg3 = false;
					}
				}
				else if (Roulette == 1) { //���[���b�g��~
					Roulette_Rotation = false; //������
					Roulette_stop_Flg = false; //���[���b�g��]���e�L�X�g�I�t
					square_go_Flg = true; //�R�}�i�߂�e�L�X�g�I��
					Roulette = 2; //Roulette 2�ֈړ�
					StopSoundMem(roulette_sound);
					PlaySoundMem(roulette_dec_sound, DX_PLAYTYPE_BACK, TRUE);//���ʉ��Đ�
				}
				else if (Roulette == 2) { //���[���b�g�\����~�A�ړ��J�n
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
			if (Branch_flg == true && Roulette == 2 && Branch_num == 0) {
				//���򏈗�
				if (Rou_num > 3) {
					Branch_num = 1; //����ݒ� 1 = ��
				}
				else if (Rou_num > 0 && Rou_num <= 3) {
					Branch_num = 2; //����ݒ� 2 = ��
				}
			}
			//�C�x���g�X���b�g���菈��
			else if (EventRou_flg == true && Roulette == 2) {
				P1_EventRou_num = Rou_num; //�C�x���g�X���b�g
				//EventRou_flg = false; //�C�x���g�X���b�g�t���O������
			}
			//�}�X�ړ�����
			else if (Branch_flg == false && EventRou_flg == false && Roulette == 0) {
				P1_PlayerMove_num = Rou_num; //�}�X�ړ� �f�o�b�N3�Œ�
				//2�{�}�X�t���O��ON�Ȃ�2�{�ɂ���
				if (two_times == true) {
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
		//�i���s�\�ȃ}�b�v�E�C�x���g�������E�t�]�}�X�������̏ꍇ�͈ړ��ł��Ȃ�
		if (P1_PlayerMove_Flg == true && EventRou_flg == false) {

			//���򔻒菈��
			if (Branch_num > 0) {
				if (P1_PlayerMove_num > 0) { //����}�X��ʉ߂��鎞
					if (Branch_num == 1) { //��
						P1_PlayerMove_Branch_destination_Down_flg = true; //��l�������ݒ�t���OTrue ��
					}
					else if (Branch_num == 2) { //��
						P1_PlayerMove_Branch_destination_Up_flg = true; //��l�������ݒ�t���OTrue ��
					}
					Branch_num = 0; //������
					Branch_flg = false; //����ݒ菉����
					Branch_destination_Flg = false; //������
				}
				else { //����}�X�Œ�~������
					Branch_flg = false; //����ݒ菉����
					P1_PlayerMove_Flg = false;
					Branch_destination_Flg = false; //������
				}
			}

			if (P1_PlayerMove_num > 0) {
				//0 = �ǂɂ͈ړ��ł��Ȃ�
				if (MapData_P[PlayerY + MoveY][PlayerX + MoveX] == 0)
				{

					//0�ɂ͉������Ȃ�
				}
				else {
					//��l���̎���ɂ��铹���m�F���Ĉړ�����
					if (MapData_P[PlayerY][PlayerX] == 2 && (MapData_P[PlayerY][PlayerX + 1] == 1 ||
						MapData_P[PlayerY][PlayerX + 1] >= 4 && MapData_P[PlayerY][PlayerX + 1] != 12)) {//�E�ړ�
						//�ړ��񐔂�1�̎�
						if (P1_PlayerMove_num == 1) {
							//�i�񂾕����Ɂu4�v������΁A�o�^�Ґ�����
							if (MapData_P[PlayerY][PlayerX + 1] == 4) {
								PlaySoundMem(subscriber_up_sound, DX_PLAYTYPE_BACK, TRUE);//�������Đ�
								P_subscriber += 100;
								subscriber_up_time = 200;
							}
							//�i�񂾕����Ɂu5�v������΁A�o�^�Ґ�����
							if (MapData_P[PlayerY][PlayerX + 1] == 5) {
								PlaySoundMem(subscriber_down_sound, DX_PLAYTYPE_BACK, TRUE);//�������Đ�
								P_subscriber -= 100;
								subscriber_down_time = 200;
							}
							//�i�񂾕����Ɂu7�v������΁A���񃋁[���b�g��2�{
							if (MapData_P[PlayerY][PlayerX + 1] == 7) {
								PlaySoundMem(two_times_sound, DX_PLAYTYPE_BACK, TRUE);//2�{�}�X���Đ�
								two_times = true;
								two_times_messagetime = 200;
							}
							//�i�񂾕������u7�ȊO�v�Ȃ�A2�{�}�X�t���O��OFF�ɂ���
							if (MapData_P[PlayerY][PlayerX + 1] != 7 && two_times == true)
							{
								two_times = false;
							}
							//�i�񂾕����Ɂu10�v������΁A�C�x���g����
							if (MapData_P[PlayerY][PlayerX + 1] == 10) {
								PlaySoundMem(event_sound, DX_PLAYTYPE_BACK, TRUE);//�}�X���Đ�
								Event_messagetime_Flg = true;
								EventRou_flg = true;
								EventRou_flg2 = true;
							}
							//�i�񂾕����Ɂu11�v������΁A�t�]�}�X�����i���j
							if (MapData_P[PlayerY][PlayerX + 1] == 11) {
								PlaySoundMem(subscriber_up_sound, DX_PLAYTYPE_BACK, TRUE);//���Đ�(�m�F�p)
							}
						}
						//�i�񂾕����Ɂu6�v������΁A���򏈗�
						if (MapData_P[PlayerY][PlayerX + 1] == 6) {
							Branch_flg = true;  //����C�x���g����
							Branch_destination_Flg = true; //����C�x���g�e�L�X�g�\��
						}
						//(��l���}�b�v��)�i�񂾕����Ɂu9�v������΁A�S�[������
						if (MapData_P[PlayerY][PlayerX + 1] == 9) {
							PlaySoundMem(goal_sound, DX_PLAYTYPE_BACK, TRUE);//���ʉ��Đ�
							PlaySoundMem(goal_cheers_sound, DX_PLAYTYPE_BACK, TRUE);//���ʉ��Đ�
							goal_time = 200;
							Goal_sound_Flg1 = true;
							//���ʂɂ���ď��ʃ{�[�i�X���Z
							if (P1_subscriber > P2_subscriber) {
								P_subscriber += 10000; //1�� +10000�l
							}
							else if (P2_subscriber > P1_subscriber) {
								P_subscriber += 5000; //2�� +5000�l
							}
						}
						MapData_P[PlayerY][PlayerX] = 3; //��l�����ʂ������͒ʂ�Ȃ�����
						MapData_P[PlayerY][PlayerX + 1] = 2; //�ʘH�Ɏ�l����ʂ�
						MoveX = 1.0f; //X�������ɃX�N���[��
						P1_LR_flg = 1; //�����؂�ւ� �E
					}
					else if (MapData_P[PlayerY][PlayerX] == 2 && (MapData_P[PlayerY][PlayerX - 1] == 1 || MapData_P[PlayerY][PlayerX - 1] >= 4)) {//���ړ�
						//�ړ��񐔂�1�̎�
						if (P1_PlayerMove_num == 1) {
							//�i�񂾕����Ɂu4�v������΁A�o�^�Ґ�����
							if (MapData_P[PlayerY][PlayerX - 1] == 4) {
								PlaySoundMem(subscriber_up_sound, DX_PLAYTYPE_BACK, TRUE);//�������Đ�
								P_subscriber += 100;
								subscriber_up_time = 200;
							}
							//�i�񂾕����Ɂu5�v������΁A�o�^�Ґ�����
							if (MapData_P[PlayerY][PlayerX - 1] == 5) {
								PlaySoundMem(subscriber_down_sound, DX_PLAYTYPE_BACK, TRUE);//�������Đ�
								P_subscriber -= 100;
								subscriber_down_time = 200;
							}
							//�i�񂾕����Ɂu7�v������΁A���񃋁[���b�g��2�{
							if (MapData_P[PlayerY][PlayerX - 1] == 7) {
								PlaySoundMem(two_times_sound, DX_PLAYTYPE_BACK, TRUE);//2�{�}�X���Đ�
								two_times = true;
								two_times_messagetime = 200;
							}
							//�i�񂾕������u7�ȊO�v�Ȃ�A2�{�}�X�t���O��OFF�ɂ���
							if (MapData_P[PlayerY][PlayerX - 1] != 7 && two_times == true)
							{
								two_times = false;
							}
							//�i�񂾕����Ɂu10�v������΁A�C�x���g����
							if (MapData_P[PlayerY][PlayerX - 1] == 10) {
								PlaySoundMem(event_sound, DX_PLAYTYPE_BACK, TRUE);//�}�X���Đ�
								Event_messagetime_Flg = true;
								EventRou_flg = true;
								EventRou_flg2 = true;
							}
							//�i�񂾕����Ɂu11�v������΁A�t�]�}�X�����i���j
							if (MapData_P[PlayerY][PlayerX - 1] == 11) {
								PlaySoundMem(subscriber_up_sound, DX_PLAYTYPE_BACK, TRUE);//���Đ�(�m�F�p)
							}
						}
						//�i�񂾕����Ɂu6�v������΁A���򏈗�
						if (MapData_P[PlayerY][PlayerX - 1] == 6) {
							Branch_flg = true;  //����C�x���g����
							Branch_destination_Flg = true; //����C�x���g�e�L�X�g�\��
						}
						//(��l���}�b�v��)�i�񂾕����Ɂu9�v������΁A�S�[������
						if (MapData_P[PlayerY][PlayerX - 1] == 9) {
							PlaySoundMem(goal_sound, DX_PLAYTYPE_BACK, TRUE);//���ʉ��Đ�
							PlaySoundMem(goal_cheers_sound, DX_PLAYTYPE_BACK, TRUE);//���ʉ��Đ�
							goal_time = 200;
							Goal_sound_Flg1 = true;
							//���ʂɂ���ď��ʃ{�[�i�X���Z
							if (P1_subscriber > P2_subscriber) {
								P_subscriber += 10000;
							}
							else if (P2_subscriber > P1_subscriber) {
								P_subscriber += 5000;
							}
						}
						MapData_P[PlayerY][PlayerX] = 3; //��l�����ʂ������͒ʂ�Ȃ�����
						MapData_P[PlayerY][PlayerX - 1] = 2; //�ʘH�Ɏ�l����ʂ�
						MoveX = -1.0f; //-X�������ɃX�N���[��
						P1_LR_flg = 0; //�����؂�ւ� ��
					}
					else if (MapData_P[PlayerY][PlayerX] == 2 && P1_PlayerMove_Branch_destination_Up_flg == false && 
							(MapData_P[PlayerY - 1][PlayerX] == 1 ||  MapData_P[PlayerY - 1][PlayerX] >= 4 &&
							 MapData_P[PlayerY - 1][PlayerX] != 12)) {//��ړ�
						//�ړ��񐔂�1�̎�
						if (P1_PlayerMove_num == 1) {
							//�i�񂾕����Ɂu4�v������΁A�o�^�Ґ�����
							if (MapData_P[PlayerY - 1][PlayerX] == 4) {
								PlaySoundMem(subscriber_up_sound, DX_PLAYTYPE_BACK, TRUE);//�������Đ�
								P_subscriber += 100;
								subscriber_up_time = 200;
							}
							//�i�񂾕����Ɂu5�v������΁A�o�^�Ґ�����
							if (MapData_P[PlayerY - 1][PlayerX] == 5) {
								PlaySoundMem(subscriber_down_sound, DX_PLAYTYPE_BACK, TRUE);//�������Đ�
								P_subscriber -= 100;
								subscriber_down_time = 200;
							}
							//�i�񂾕����Ɂu7�v������΁A���񃋁[���b�g��2�{
							if (MapData_P[PlayerY - 1][PlayerX] == 7) {
								PlaySoundMem(two_times_sound, DX_PLAYTYPE_BACK, TRUE);//2�{�}�X���Đ�
								two_times = true;
								two_times_messagetime = 200;
							}
							//�i�񂾕������u7�ȊO�v�Ȃ�A2�{�}�X�t���O��OFF�ɂ���
							if (MapData_P[PlayerY - 1][PlayerX] != 7 && two_times == true)
							{
								two_times = false;
							}
							//�i�񂾕����Ɂu10�v������΁A�C�x���g����
							if (MapData_P[PlayerY - 1][PlayerX] == 10) {
								PlaySoundMem(event_sound, DX_PLAYTYPE_BACK, TRUE);//�}�X���Đ�
								Event_messagetime_Flg = true;
								EventRou_flg = true;
								EventRou_flg2 = true;
							}
							//�i�񂾕����Ɂu11�v������΁A�t�]�}�X�����i���j
							if (MapData_P[PlayerY - 1][PlayerX] == 11) {
								PlaySoundMem(subscriber_up_sound, DX_PLAYTYPE_BACK, TRUE);//���Đ�(�m�F�p)
							}
						}
						//�i�񂾕����Ɂu6�v������΁A���򏈗�
						if (MapData_P[PlayerY - 1][PlayerX] == 6) {
							Branch_flg = true;  //����C�x���g����
							Branch_destination_Flg = true; //����C�x���g�e�L�X�g�\��
						}
						//(��l���}�b�v��)�i�񂾕����Ɂu9�v������΁A�S�[������
						if (MapData_P[PlayerY - 1][PlayerX] == 9) {
							PlaySoundMem(goal_sound, DX_PLAYTYPE_BACK, TRUE);//���ʉ��Đ�
							PlaySoundMem(goal_cheers_sound, DX_PLAYTYPE_BACK, TRUE);//���ʉ��Đ�
							goal_time = 200;
							Goal_sound_Flg1 = true;
							//���ʂɂ���ď��ʃ{�[�i�X���Z
							if (P1_subscriber > P2_subscriber) {
								P_subscriber += 10000;
							}
							else if (P2_subscriber > P1_subscriber) {
								P_subscriber += 5000;
							}
						}
						MapData_P[PlayerY][PlayerX] = 3; //��l�����ʂ������͒ʂ�Ȃ�����
						MapData_P[PlayerY - 1][PlayerX] = 2; //�ʘH�Ɏ�l����ʂ�
						MoveY = -1.0f; //-Y�������ɃX�N���[��
						P1_UD_flg = 1; //�����؂�ւ� ��
					}
					else if (MapData_P[PlayerY][PlayerX] == 2 && P1_PlayerMove_Branch_destination_Down_flg == false && 
							(MapData_P[PlayerY + 1][PlayerX] == 1 ||  MapData_P[PlayerY + 1][PlayerX] >= 4 &&
							 MapData_P[PlayerY + 1][PlayerX] != 12)) {//���ړ�
						//�ړ��񐔂�1�̎�
						if (P1_PlayerMove_num == 1) {
							//�i�񂾕����Ɂu4�v������΁A�o�^�Ґ�����
							if (MapData_P[PlayerY + 1][PlayerX] == 4) {
								PlaySoundMem(subscriber_up_sound, DX_PLAYTYPE_BACK, TRUE);//�������Đ�
								P_subscriber += 100;
								subscriber_up_time = 200;
							}
							//�i�񂾕����Ɂu5�v������΁A�o�^�Ґ�����
							if (MapData_P[PlayerY + 1][PlayerX] == 5) {
								PlaySoundMem(subscriber_down_sound, DX_PLAYTYPE_BACK, TRUE);//�������Đ�
								P_subscriber -= 100;
								subscriber_down_time = 200;
							}
							
							//�i�񂾕����Ɂu7�v������΁A���񃋁[���b�g��2�{
							if (MapData_P[PlayerY + 1][PlayerX] == 7) {
								PlaySoundMem(two_times_sound, DX_PLAYTYPE_BACK, TRUE);//2�{�}�X���Đ�
								two_times = true;
								two_times_messagetime = 200;
							}
							//�i�񂾕������u7�ȊO�v�Ȃ�A2�{�}�X�t���O��OFF�ɂ���
							if (MapData_P[PlayerY + 1][PlayerX] != 7 && two_times == true){
								two_times = false;
							}
							//�i�񂾕����Ɂu10�v������΁A�C�x���g����
							if (MapData_P[PlayerY + 1][PlayerX] == 10) {
								PlaySoundMem(event_sound, DX_PLAYTYPE_BACK, TRUE);//�}�X���Đ�
								Event_messagetime_Flg = true;
								EventRou_flg = true;
								EventRou_flg2 = true;
							}
							//�i�񂾕����Ɂu11�v������΁A�t�]�}�X�����i���j
							if (MapData_P[PlayerY + 1][PlayerX] == 11) {
								PlaySoundMem(subscriber_up_sound, DX_PLAYTYPE_BACK, TRUE);//���Đ�(�m�F�p)
							}
						}
						//�i�񂾕����Ɂu6�v������΁A���򏈗�
						if (MapData_P[PlayerY + 1][PlayerX] == 6) {
							Branch_flg = true;  //����C�x���g����
							Branch_destination_Flg = true; //����C�x���g�e�L�X�g�\��
						}
						//(��l���}�b�v��)�i�񂾕����Ɂu9�v������΁A�S�[������
						if (MapData_P[PlayerY + 1][PlayerX] == 9) {
							PlaySoundMem(goal_sound, DX_PLAYTYPE_BACK, TRUE);//���ʉ��Đ�
							PlaySoundMem(goal_cheers_sound, DX_PLAYTYPE_BACK, TRUE);//���ʉ��Đ�
							goal_time = 200;
							Goal_sound_Flg1 = true;
							//���ʂɂ���ď��ʃ{�[�i�X���Z
							if (P1_subscriber > P2_subscriber) {
								P_subscriber += 10000;
							}
							else if (P2_subscriber > P1_subscriber) {
								P_subscriber += 5000;
							}
						}
						MapData_P[PlayerY][PlayerX] = 3; //��l�����ʂ������͒ʂ�Ȃ�����
						MapData_P[PlayerY + 1][PlayerX] = 2; //�ʘH�Ɏ�l����ʂ�
						MoveY = 1.0f; //Y�������ɃX�N���[��
						P1_UD_flg = 0; //�����؂�ւ� ��
					}
					Move = 1; //�X�N���[���J�n
					if (Goal_sound_Flg1 == false) {
						PlaySoundMem(move_sound, DX_PLAYTYPE_BACK, TRUE);//�ړ����Đ�
					}
				}
			}
			
			MoveCounter = 0;
		}

				//�ړ����̏ꍇ�͈ړ��������s��
				if (Move == 1) {
					MoveCounter++;
					if (P1_PlayerMove_Flg == true) {
						//������
						P1_PlayerMove_Flg = false;
						//�}�X�J�E���g(���Ɖ��}�X)��0�ȏ�̎��̂݃}�X�J�E���g�����炷
						if (squares_cnt1 > 0) {
							squares_cnt1 -= 1;
						}
					}
					//�ړ��������I���������~���ɂ���
					if (MoveCounter == MOVE_FRAME) {
						//����ݒ�J�n����
						if (Branch_flg == true) {
							//������
							Move = 0;
							MoveCounter = 0;
							P1_PlayerMove_num--; //�ړ��񐔌���
							RouDraw_flg = false; //�摜�\���ĊJ
						}
						else {
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

						//��l�������ݒ�t���O������
						if (P1_PlayerMove_Branch_destination_Up_flg == true) {
							P1_PlayerMove_Branch_destination_Up_flg = false; //��l�������ݒ�t���OTrue ��
						}
						else if (P1_PlayerMove_Branch_destination_Down_flg == true) {
							P1_PlayerMove_Branch_destination_Down_flg = false; //��l�������ݒ�t���OTrue ��
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

				//�}�b�v�ƃv���C���[��`��
				GraphDraw(ScrollX, ScrollY);

				//���[���b�g�\����~����
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
				else {
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
				//�C�x���g�}�X�e�L�X�g
				if (Event_messagetime_Flg == true) {
					DrawFormatString(40, 470, GetColor(50, 255, 255), "�C�x���g�}�X�I");
					DrawFormatString(40, 500, GetColor(255, 255, 255), "���[���b�g�̖ڂ��A1�`3�Ȃ�`�����l���o�^�Ґ������A4�`6�Ȃ�`�����l���o�^�Ґ�����");
					DrawFormatString(40, 530, GetColor(255, 255, 255), "Enter�L�[�Ń��[���b�g�X�^�[�g");
				}
				else {
					Event_messagetime_Flg = false;
				}

				//����C�x���g�e�L�X�g�\��
				if (Branch_destination_Flg == true) {
					if (Roulette == 0) {
						DrawFormatString(40, 470, GetColor(255, 255, 255), "Enter�L�[�Ń��[���b�g�X�^�[�g");
						DrawFormatString(40, 505, GetColor(50, 255, 255), "����C�x���g����");
						DrawFormatString(40, 525, GetColor(255, 255, 255), "�ړ�������߂悤");
					}
					else if (Roulette == 2) {
						//�����\���`��
						if (Branch_num == 1) { //��
							DrawFormatString(40, 500, GetColor(50, 255, 255), "�ړ��� : ��");
						}
						else if (Branch_num == 2) { //��
							DrawFormatString(40, 500, GetColor(50, 255, 255), "�ړ��� : ��");
						}
					}
				}

				//���[���b�g�X�^�[�g�w���e�L�X�g
				if (Roulette_Flg == true && Roulette_stop_Flg == false && square_go_Flg == false
					&& square_rest_Flg == true && RouDraw_flg == false && goal_time == 0
					&& subscriber_up_time == 0 && subscriber_down_time == 0 && two_times_messagetime == 0
					&& Event_messagetime_Flg == false && Branch_flg == false) {
					DrawFormatString(40, 470, GetColor(255, 255, 255), "Enter�L�[�Ń��[���b�g�X�^�[�g");
					if (two_times == true) {
						DrawFormatString(40, 505, GetColor(50, 255, 255), "2�{�`�����X�I");
						DrawFormatString(40, 525, GetColor(255, 255, 255), "���[���b�g�̏o���ځ~2�ɂȂ�܂�");
					}
				}
				else {
					Roulette_Flg == false;
				}

				//���[���b�g�X�g�b�v�w���e�L�X�g
				if (Roulette_stop_Flg == true && subscriber_up_time == 0 && subscriber_down_time == 0
					&& two_times_messagetime == 0 && Event_messagetime_Flg == false) {
					DrawFormatString(40, 470, GetColor(255, 255, 255), "Enter�L�[�Ń��[���b�g�X�g�b�v");
					if (two_times == true) {
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
					if (EventRou_flg == false && event_messagetime == 0) {
						DrawFormatString(40, 470, GetColor(255, 255, 255), "Enter�L�[�ŃR�}��i�߂�");
					}
					else if (event_messagetime == 0) {
						DrawFormatString(40, 470, GetColor(255, 255, 255), "Enter�L�[�������Ă�������");
						EventRou_flg3 = true;
					}

			if (two_times == true){
				DrawFormatString(40, 505, GetColor(50, 255, 255), "2�{�`�����X�I");
				DrawFormatString(40, 525, GetColor(255, 255, 255), "���[���b�g�̏o���ځ~2�ɂȂ�܂�");
			}
			//�C�x���g�������Ń��[���b�g�̖ڂ�1�`3�̏ꍇ�A�`�����l���o�^�Ґ�����
			if (EventRou_flg2 == true && P1_EventRou_num <= 3){
				PlaySoundMem(subscriber_up_sound, DX_PLAYTYPE_BACK, TRUE);//�������Đ�
				P_subscriber += 500;//+500�l
				event_messagetime = 200;
				EventRou_flg2 = false;
			}
			//�C�x���g�������Ń��[���b�g�̖ڂ�4�`6�̏ꍇ�A�`�����l���o�^�Ґ�������
			else if (EventRou_flg2 == true && P1_EventRou_num >= 4){
				PlaySoundMem(subscriber_down_sound, DX_PLAYTYPE_BACK, TRUE);//�������Đ�
				P_subscriber -= 500; //-500�l
				event_messagetime = 200;
				EventRou_flg2 = false;
			}
			//�C�x���g�p�`�����l���o�^�Ґ������e�L�X�g
			event_messagetime --;
			if (P1_EventRou_num <= 3 && event_messagetime > 0) {
				DrawFormatString(40, 470, GetColor(50, 255, 255), "�`�����l���o�^�Ґ������I");
				DrawFormatString(40, 500, GetColor(255, 255, 255), "�`�����l���o�^�Ґ���500�l�������I");
			}
			else if (P1_EventRou_num >= 4 && event_messagetime > 0) {
				DrawFormatString(40, 470, GetColor(255, 50, 255), "�`�����l���o�^�Ґ������c");
				DrawFormatString(40, 500, GetColor(255, 0, 0), "�`�����l���o�^�Ґ���500�l�������c");
			}
			else {
				event_messagetime = 0;
			}
		}
		else {
			square_go_Flg = false;
		}

				//���Ɖ��}�X �e�L�X�g
				if (square_rest_Flg == true && RouDraw_flg == true && goal_time == 0
					&& subscriber_up_time == 0 && subscriber_down_time == 0 && two_times_messagetime == 0
					&& Event_messagetime_Flg == false && Branch_destination_Flg == false) {

					if (P1_PlayerMove_num == 1) {
						DrawFormatString(40, 470, GetColor(255, 255, 255), "�}�X����");
					}
					else if (P1_PlayerMove_num >= 2) {
						DrawFormatString(40, 470, GetColor(255, 255, 255), "���ƁF%d�}�X", P1_PlayerMove_num - 1);
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
					if (P1_subscriber > P2_subscriber) {
						DrawFormatString(40, 500, GetColor(255, 255, 0), "���ʃ{�[�i�X 1�ʁF�`�����l���o�^�Ґ��{10000�l�I");
					}
					else if (P2_subscriber > P1_subscriber) {
						DrawFormatString(40, 500, GetColor(255, 255, 0), "���ʃ{�[�i�X 2�ʁF�`�����l���o�^�Ґ��{5000�l�I");
					}
				}
				else {
					goal_time = 0;
				}

				//�f�o�b�O�p���[���b�g�����m�F
				DrawFormatString(0, 50, GetColor(0, 150, 0), "�y�f�o�b�O�p�z���[���b�g�����F%d", Rou_num);
				//�f�o�b�O�p�C�x���g���[���b�g�����m�F
				DrawFormatString(0, 70, GetColor(0, 150, 0), "�y�f�o�b�O�p�z�C�x���g���[���b�g�����F%d", P1_EventRou_num);
				//�f�o�b�O�p�i�ރ}�X���m�F
				DrawFormatString(0, 90, GetColor(0, 150, 0), "�y�f�o�b�O�p�z�i�ރ}�X���F%d", P1_PlayerMove_num);

		ScreenFlip(); //�o�b�N�o�b�t�@�Ɛ؂�ւ�

		//��O������������v���O�����I��
		if (ProcessMessage() == -1) break;
	}

	DxLib_End(); //dx���C�u�����I������

	return 0;
}
		
	
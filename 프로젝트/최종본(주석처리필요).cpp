#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<conio.h>
#include<time.h>
#define LEFT 75 //�·� �̵�    //Ű���尪�� 
#define ENTER 13 //��� �̵� 
#define ESC 27
#define UP 119 //���� �̵�
#define DOWN 115 //�Ʒ��� �̵�
#define FASTSPEED 150 //���� �ӵ�
#define SLOWSPEED 300 // ���� �ӵ�
#pragma warning(disable : 4996)
int cnt = 1;
bool left1 = false;
bool right1 = false;
bool up1 = false;
bool down1 = false;
bool atk1 = false;
bool left2 = false;
bool right2 = false;
bool up2 = false;
bool down2 = false;
bool atk2 = false;
bool left3 = false;
bool right3 = false;
bool up3 = false;
bool down3 = false;
bool atk3 = false;
void DrawTurret1();
void DrawTurret2();
void ExtraLife();
int cnt1;
int cnt2;
int life = 1;
int invisiblecnt = 5000;

typedef struct
{
	int health;
	int x;
	int y;

	bool ifAlive;
} Player; // ĳ���� ���� ����ü

typedef struct
{
	int x;
	int y;
} Life; // �߰�ü�� ��ġ ����ü

Player enemyPlayer1 = { 100,10,10,true };
Player enemyPlayer2 = { 100,10,10,true };
Player myPlayer = { 100,30,20,true };
Life life_loc = { 0,0 };
void gotoxy(int x, int y) //gotoxy �Լ� ����
{
	COORD CursorPosition = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);
}

typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;
const int refreshRate = 50;



void setcursortype(CURSOR_TYPE c)
{
	CONSOLE_CURSOR_INFO CurInfo;
	switch (c)
	{
	case NOCURSOR:
		CurInfo.dwSize = 1;
		CurInfo.bVisible = FALSE;
		break;
	case SOLIDCURSOR:
		CurInfo.dwSize = 100;
		CurInfo.bVisible = TRUE;
		break;
	case NORMALCURSOR:
		CurInfo.dwSize = 20;
		CurInfo.bVisible = TRUE;
		break;
	} SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
}

void map(int x, int y)  //map ���
{

	gotoxy(x, y); printf("����������������������������������������������������������������������������������������");
	gotoxy(x, y + 1); printf("��                                          ��");
	gotoxy(x, y + 2); printf("��                                          ��");
	gotoxy(x, y + 3); printf("��                                          ��");
	gotoxy(x, y + 4); printf("��                                          ��");
	gotoxy(x, y + 5); printf("��                                          ��");
	gotoxy(x, y + 6); printf("��                                          ��");
	gotoxy(x, y + 7); printf("��                                          ��");
	gotoxy(x, y + 8); printf("��                                          ��");
	gotoxy(x, y + 9); printf("��                                          ��");
	gotoxy(x, y + 10); printf("��                                          ��");
	gotoxy(x, y + 11); printf("��                                          ��");
	gotoxy(x, y + 12); printf("��                                          ��");
	gotoxy(x, y + 13); printf("��                                          ��");
	gotoxy(x, y + 14); printf("��                                          ��");
	gotoxy(x, y + 15); printf("��                                          ��");
	gotoxy(x, y + 16); printf("��                                          ��");
	gotoxy(x, y + 17); printf("��                                          ��");
	gotoxy(x, y + 18); printf("��                                          ��");
	gotoxy(x, y + 19); printf("��                                          ��");
	gotoxy(x, y + 20); printf("��                                          ��");
	gotoxy(x, y + 21); printf("��                                          ��");
	gotoxy(x, y + 22); printf("����������������������������������������������������������������������������������������");
}

int gamestart()  //Ÿ��Ʋ ȭ��
{
	int x = 22; //Ÿ��Ʋȭ���� ǥ�õǴ� x��ǥ 
	int y = 4; //Ÿ��Ʋȭ���� ǥ�õǴ� y��ǥ 
	int check = 1;
	int ch;
	map(12, 3);
	gotoxy(x + 8, y + 2); printf("A");               Sleep(150);
	gotoxy(x + 8, y + 2); printf("A V");             Sleep(150);
	gotoxy(x + 8, y + 2); printf("A V O");           Sleep(150);
	gotoxy(x + 8, y + 2); printf("A V O I");         Sleep(150);
	gotoxy(x + 8, y + 2); printf("A V O I D");       Sleep(150);
	gotoxy(x + 5, y + 3); printf("O");               Sleep(150);
	gotoxy(x + 5, y + 3); printf("O B");             Sleep(150);
	gotoxy(x + 5, y + 3); printf("O B S");           Sleep(150);
	gotoxy(x + 5, y + 3); printf("O B S T");         Sleep(150);
	gotoxy(x + 5, y + 3); printf("O B S T A");       Sleep(150);
	gotoxy(x + 5, y + 3); printf("O B S T A C");     Sleep(150);
	gotoxy(x + 5, y + 3); printf("O B S T A C L");   Sleep(150);
	gotoxy(x + 5, y + 3); printf("O B S T A C L E"); Sleep(150);

	gotoxy(x - 2, y + 10); printf("SELECT = ENTER, MOVE = W,A,S,D"); //����Ű ����
	y = 10;
	x = 27;
	while (true)
	{

		gotoxy(32, 10); printf("START"); // ���� ���
		gotoxy(32, 11); printf("EXIT"); // ������ ���
		ch = getch(); // ����or������ �Է¹ޱ�

		if (ch == ENTER)
		{
			return check;
		}
		else if (ch == DOWN && check < 2)
		{
			check++;
			y += 1;
			gotoxy(x + 2, y - 1); printf("      ");
			gotoxy(x + 10, y - 1); printf("      ");
			gotoxy(x + 2, y); printf(">>  ");
			gotoxy(x + 10, y); printf("<<");
		}
		else if (ch == UP && check > 1)
		{
			check--;
			y -= 1;
			gotoxy(x + 2, y + 1); printf("     ");
			gotoxy(x + 10, y + 1); printf("      ");
			gotoxy(x + 2, y); printf(">>  ");
			gotoxy(x + 10, y); printf(" <<");
		}

	}
}

void DrawTurret1() { // ���� 1��°
	static int atkspd;
	if (atk1 == false)
	{
		switch (rand() % 4) // �����¿� ���� ���� ���ϱ�
		{
		case 0: // ������ ����
			Sleep(10);
			enemyPlayer1.x = 10;
			enemyPlayer1.y = rand() % 20 + 10;
			right1 = true;
			atk1 = true;
			break;
		case 1: // ���� ����
			Sleep(10);
			enemyPlayer1.x = 49;
			enemyPlayer1.y = rand() % 20 + 10;
			left1 = true;
			atk1 = true;
			break;
		case 2: // ���� ����
			Sleep(10);
			enemyPlayer1.x = rand() % 40 + 10;
			enemyPlayer1.y = 30;
			up1 = true;
			atk1 = true;
			break;
		default: // �Ʒ��� ����
			Sleep(10);
			enemyPlayer1.x = rand() % 40 + 10;
			enemyPlayer1.y = 10;
			down1 = true;
			atk1 = true;
		}
	}


	if (right1 == true) // ������ ����
	{
		if (enemyPlayer1.x < 48)
		{
			if (cnt1 % (FASTSPEED - (cnt / 10000)) == 0) {
				enemyPlayer1.x++;
				gotoxy(enemyPlayer1.x, enemyPlayer1.y);
				printf("��");
				gotoxy(enemyPlayer1.x - 1, enemyPlayer1.y);
				printf("  ");
			}
		}
		if (enemyPlayer1.x == 48) // �ε����� �����
		{
			gotoxy(enemyPlayer1.x, enemyPlayer1.y);
			Sleep(20);
			printf("  ");
			right1 = false;
			atk1 = false;
		}
	}



	if (left1 == true) // ���� ����
	{
		if (enemyPlayer1.x > 10)
		{
			if (cnt1 % (FASTSPEED - (cnt / 10000)) == 0)
			{
				enemyPlayer1.x--;
				gotoxy(enemyPlayer1.x, enemyPlayer1.y);
				printf("�� ");
			}
		}
		if (enemyPlayer1.x == 10)
		{
			gotoxy(enemyPlayer1.x, enemyPlayer1.y);
			Sleep(20);
			printf("  ");
			left1 = false;
			atk1 = false;
		}
	}


	if (up1 == true) // ���� ����
	{
		if (enemyPlayer1.y > 10)
		{
			if (cnt1 % (SLOWSPEED - (cnt / 20000)) == 0)
			{
				enemyPlayer1.y--;
				gotoxy(enemyPlayer1.x, enemyPlayer1.y);
				printf("��");
				gotoxy(enemyPlayer1.x, enemyPlayer1.y + 1);
				printf("  ");
			}
		}
		if (enemyPlayer1.y == 10)
		{
			gotoxy(enemyPlayer1.x, enemyPlayer1.y);
			Sleep(20);
			printf("  ");
			up1 = false;
			atk1 = false;
		}
	}


	if (down1 == true) // �Ʒ��� ����
	{
		if (enemyPlayer1.y < 30)
		{
			if (cnt1 % (SLOWSPEED - (cnt / 20000)) == 0)
			{
				enemyPlayer1.y++;
				gotoxy(enemyPlayer1.x, enemyPlayer1.y);
				printf("��");
				gotoxy(enemyPlayer1.x, enemyPlayer1.y - 1);
				printf("  ");
			}
		}

		if (enemyPlayer1.y == 30)
		{
			gotoxy(enemyPlayer1.x, enemyPlayer1.y);
			Sleep(20);
			printf("  ");
			down1 = false;
			atk1 = false;
		}
	}
	if (atk1 == false)
	{
		atkspd--;
		//Sleep(1000 - atkspd);
	}
	cnt1++;
}

void DrawTurret2() { // ���� 2��° �����Ͱ� �ڵ� �Ȱ���
	static int atkspd;
	if (atk2 == false)
	{
		switch (rand() % 4)
		{
		case 0:
			Sleep(10);
			enemyPlayer2.x = 10;
			enemyPlayer2.y = rand() % 20 + 10;
			right2 = true;
			atk2 = true;
			break;
		case 1:
			Sleep(10);
			enemyPlayer2.x = 49;
			enemyPlayer2.y = rand() % 20 + 10;
			left2 = true;
			atk2 = true;
			break;
		case 2:
			Sleep(10);
			enemyPlayer2.x = rand() % 40 + 10;
			enemyPlayer2.y = 30;
			up2 = true;
			atk2 = true;
			break;
		default:
			Sleep(10);
			enemyPlayer2.x = rand() % 40 + 10;
			enemyPlayer2.y = 10;
			down2 = true;
			atk2 = true;
		}
	}


	if (right2 == true)
	{
		if (enemyPlayer2.x < 48)
		{
			if (cnt2 % (FASTSPEED - (cnt / 10000)) == 0)
			{
				enemyPlayer2.x++;
				gotoxy(enemyPlayer2.x, enemyPlayer2.y);
				printf("��");
				gotoxy(enemyPlayer2.x - 1, enemyPlayer2.y);
				printf("  ");
			}
		}
		if (enemyPlayer2.x == 48)
		{
			gotoxy(enemyPlayer2.x, enemyPlayer2.y);
			Sleep(20);
			printf("  ");
			right2 = false;
			atk2 = false;
		}
	}



	if (left2 == true)
	{
		if (enemyPlayer2.x > 10)
		{
			if (cnt2 % (FASTSPEED - (cnt / 10000)) == 0)
			{
				enemyPlayer2.x--;
				gotoxy(enemyPlayer2.x, enemyPlayer2.y);
				printf("�� ");
			}
		}
		if (enemyPlayer2.x == 10)
		{
			gotoxy(enemyPlayer2.x, enemyPlayer2.y);

			Sleep(20);
			printf("  ");
			left2 = false;
			atk2 = false;
		}
	}


	if (up2 == true)
	{
		if (enemyPlayer2.y > 10)
		{
			if (cnt2 % (SLOWSPEED - (cnt / 20000)) == 0)
			{
				enemyPlayer2.y--;
				gotoxy(enemyPlayer2.x, enemyPlayer2.y);
				printf("��");
				gotoxy(enemyPlayer2.x, enemyPlayer2.y + 1);
				printf("  ");
			}
		}
		if (enemyPlayer2.y == 10)
		{
			gotoxy(enemyPlayer2.x, enemyPlayer2.y);
			Sleep(20);
			printf("  ");
			up2 = false;
			atk2 = false;
		}
	}


	if (down2 == true)
	{
		if (enemyPlayer2.y < 30)
		{
			if (cnt2 % (SLOWSPEED - (cnt / 20000)) == 0)
			{
				enemyPlayer2.y++;
				gotoxy(enemyPlayer2.x, enemyPlayer2.y);
				printf("��");
				gotoxy(enemyPlayer2.x, enemyPlayer2.y - 1);
				printf("  ");
			}
		}

		if (enemyPlayer2.y == 30)
		{
			gotoxy(enemyPlayer2.x, enemyPlayer2.y);
			Sleep(20);
			printf("  ");
			down2 = false;
			atk2 = false;
		}
	}
	if (atk2 == false)
	{
		//Sleep(100 - atkspd);
	}
	cnt2++;
}

void Drawcharacter() // ĳ���Ͱ� ���� �� ĳ���� ��� ���
{
	gotoxy(25, 12); printf("������������");
	gotoxy(25, 13); printf("��������������");
	gotoxy(25, 14); printf("��  ��  ��");
	gotoxy(25, 15); printf("��  ��  ��");
	gotoxy(25, 16); printf("�� ������ ��");
	gotoxy(25, 17); printf("��������������");
	gotoxy(25, 18); printf(" ���� ���� ");
	Sleep(100);
	gotoxy(25, 12); printf("     ");
	Sleep(60);
	gotoxy(28, 12); printf("   ");
	Sleep(60);
	gotoxy(31, 12); printf("   ");
	Sleep(60);

	gotoxy(25, 13); printf("   ");
	Sleep(60);
	gotoxy(28, 13); printf("   ");
	Sleep(60);
	gotoxy(31, 13); printf("   ");
	Sleep(60);

	gotoxy(25, 14); printf("   ");
	Sleep(60);
	gotoxy(28, 14); printf("   ");
	Sleep(60);
	gotoxy(31, 14); printf("   ");
	Sleep(60);

	gotoxy(25, 15); printf("   ");
	Sleep(60);
	gotoxy(28, 15); printf("   ");
	Sleep(60);
	gotoxy(31, 15); printf("   ");
	Sleep(60);

	gotoxy(25, 16); printf("   ");
	Sleep(60);
	gotoxy(28, 16); printf("   ");
	Sleep(60);
	gotoxy(31, 16); printf("   ");
	Sleep(60);

	gotoxy(25, 17); printf("   ");
	Sleep(60);
	gotoxy(28, 17); printf("   ");
	Sleep(60);
	gotoxy(31, 17); printf("   ");
	Sleep(60);

	gotoxy(25, 18); printf("   "); Sleep(60);
	gotoxy(28, 18); printf("   "); Sleep(60);
	gotoxy(31, 18); printf("   "); Sleep(60);
	Sleep(250);
}


int main(void)
{
	srand(time(NULL));
	setcursortype(NOCURSOR);
	system("mode CON COLS=70 LINES=70");
	int a;
	int turn = 0;
			bool lifeminus=false;
			bool lifeplus = false;
	cnt = 1;
	while (1) {
		system("cls"); // ���� �� ȭ�� �ʱ�ȭ

		a = gamestart(); // ������ �����ϴ��� ���ϴ��� �Ǵ�
		if (a == 1) { // ���� �ϴ� ���
		gg: 
			myPlayer.x = 30;
			myPlayer.y = 20;
			DrawTurret1();
			DrawTurret2();
			cnt = 1;
			int life = 1;
			system("cls");
			gotoxy(28, 6);  printf("S T A R T");
			Sleep(1000);
			system("cls");
			map(8, 9);
			int x = 0, y = 0;
			char ch;

			gotoxy(15, 15);
			while (true)
			{
				gotoxy(myPlayer.x, myPlayer.y);
				printf(" ");

				ch = '\0';
				if (kbhit()) ch = getch(); // ĳ���� �̵� �Է� �ޱ�

				switch (ch) // �Է� �޾� ĳ���� �̵�
				{
				case 'w':
					if (myPlayer.y > 10) myPlayer.y--;
					break;
				case 's':
					if (myPlayer.y < 30) myPlayer.y++;
					break;
				case 'a':
					if (myPlayer.x > 10) myPlayer.x--;
					break;
				case 'd':
					if (myPlayer.x < 50) myPlayer.x++;
				}

				gotoxy(myPlayer.x, myPlayer.y);
				printf("@");
				if(!lifeplus)
					if (myPlayer.x != life_loc.x && myPlayer.y != life_loc.y)
					{
						lifeplus = false;
					}
				if (myPlayer.x == life_loc.x && myPlayer.y == life_loc.y)
				{
					lifeplus = true;
					life++;
					life_loc.x = 0;
					life_loc.y = 0;
				}




				DrawTurret1(); // ����1 ���
				DrawTurret2(); // ����2 ���
				ExtraLife();

				//DrawTurret3();

				//Sleep(100 / refreshRate);
				gotoxy(8, 8); printf("Score : %d                             Life : %d", cnt / 1000,life);
				cnt++;
				invisiblecnt--;
				if(!invisiblecnt)
					if (myPlayer.x != enemyPlayer1.x && myPlayer.y != enemyPlayer1.y || myPlayer.x != enemyPlayer2.x && myPlayer.y != enemyPlayer2.y)
					{
					lifeminus = false;
					invisiblecnt = 5000;
				}
				if(!lifeminus)
				if (myPlayer.x == enemyPlayer1.x && myPlayer.y == enemyPlayer1.y || myPlayer.x == enemyPlayer2.x && myPlayer.y == enemyPlayer2.y) // ���ݿ� �¾Ҵ��� �Ǵ�
				{
					lifeminus = true;
					life--;

					if (life ==0) {
						int restart;
						system("cls");
						Drawcharacter();
					rr:
						gotoxy(28, 6); printf("YOU DIED");
						gotoxy(28, 7); printf("RESTART?");
						gotoxy(20, 8); printf("ENTER : ����, ESC : ������");
						gotoxy(20, 9); printf("SCORE : %d", cnt / 1000);
						Sleep(250);
						restart = getch(); // ����� �ϴ��� �Է¹���
						Sleep(250);
						if (restart == ENTER) // ����� �� ��
						{
							Sleep(250);
							cnt = 0;
							life=1;
							goto gg;
						}
						else if (restart == ESC) // ����� ���� ���� ��
						{
							goto bb;
						}
						else
						{
							gotoxy(23, 10); printf("�ٽ� �Է��� �ּ���."); Sleep(200);
							gotoxy(23, 10); printf("                   ");
							goto rr;
						}
						break;
					}
				}
			}
		}
		else {
		bb:
			system("cls");
			break;
		}
	}
}

void ExtraLife() // �߰� ü�� �Լ�
{
	if (cnt%100000==0) // ������ 100���� �Ǹ� ���� ��ġ�� �߰� ü�� ��ġ
	{
		life_loc.x = (rand() % 40 + 10);
		life_loc.y = (rand() % 20 + 10);
		gotoxy(life_loc.x,life_loc.y);
		printf("��");
	}	
}
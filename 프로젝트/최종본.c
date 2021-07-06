#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<conio.h>
#include<time.h>
#define LEFT 75 //좌로 이동    //키보드값들 
#define ENTER 13 //우로 이동 
#define ESC 27
#define UP 119 //위로 이동
#define DOWN 115 //아래로 이동
#define FASTSPEED 150 //가로 속도
#define SLOWSPEED 300 // 세로 속도
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
} Player; // 캐릭터 정보 구조체

typedef struct
{
	int x;
	int y;
} Life; // 추가체력 위치 구조체

Player enemyPlayer1 = { 100,10,10,true };
Player enemyPlayer2 = { 100,10,10,true };
Player myPlayer = { 100,30,20,true };
Life life_loc = { 0,0 };
void gotoxy(int x, int y) //gotoxy 함수 선언
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

void map(int x, int y)  //map 출력
{

	gotoxy(x, y); printf("┌──────────────────────────────────────────┐");
	gotoxy(x, y + 1); printf("│                                          │");
	gotoxy(x, y + 2); printf("│                                          │");
	gotoxy(x, y + 3); printf("│                                          │");
	gotoxy(x, y + 4); printf("│                                          │");
	gotoxy(x, y + 5); printf("│                                          │");
	gotoxy(x, y + 6); printf("│                                          │");
	gotoxy(x, y + 7); printf("│                                          │");
	gotoxy(x, y + 8); printf("│                                          │");
	gotoxy(x, y + 9); printf("│                                          │");
	gotoxy(x, y + 10); printf("│                                          │");
	gotoxy(x, y + 11); printf("│                                          │");
	gotoxy(x, y + 12); printf("│                                          │");
	gotoxy(x, y + 13); printf("│                                          │");
	gotoxy(x, y + 14); printf("│                                          │");
	gotoxy(x, y + 15); printf("│                                          │");
	gotoxy(x, y + 16); printf("│                                          │");
	gotoxy(x, y + 17); printf("│                                          │");
	gotoxy(x, y + 18); printf("│                                          │");
	gotoxy(x, y + 19); printf("│                                          │");
	gotoxy(x, y + 20); printf("│                                          │");
	gotoxy(x, y + 21); printf("│                                          │");
	gotoxy(x, y + 22); printf("└──────────────────────────────────────────┘");
}

int gamestart()  //타이틀 화면
{
	int x = 22; //타이틀화면이 표시되는 x좌표 
	int y = 4; //타이틀화면이 표시되는 y좌표 
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

	gotoxy(x - 2, y + 10); printf("SELECT = ENTER, MOVE = W,A,S,D"); //조작키 설명
	y = 10;
	x = 27;
	while (true)
	{

		gotoxy(32, 10); printf("START"); // 시작 출력
		gotoxy(32, 11); printf("EXIT"); // 나가기 출력
		ch = getch(); // 시작or나가기 입력받기

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

void DrawTurret1() { // 공격 1개째
	static int atkspd;
	if (atk1 == false)
	{
		switch (rand() % 4) // 상하좌우 공격 방향 정하기
		{
		case 0: // 오른쪽 공격
			Sleep(10);
			enemyPlayer1.x = 10;
			enemyPlayer1.y = rand() % 20 + 10;
			right1 = true;
			atk1 = true;
			break;
		case 1: // 왼쪽 공격
			Sleep(10);
			enemyPlayer1.x = 49;
			enemyPlayer1.y = rand() % 20 + 10;
			left1 = true;
			atk1 = true;
			break;
		case 2: // 위쪽 공격
			Sleep(10);
			enemyPlayer1.x = rand() % 40 + 10;
			enemyPlayer1.y = 30;
			up1 = true;
			atk1 = true;
			break;
		default: // 아래쪽 공격
			Sleep(10);
			enemyPlayer1.x = rand() % 40 + 10;
			enemyPlayer1.y = 10;
			down1 = true;
			atk1 = true;
		}
	}


	if (right1 == true) // 오른쪽 공격
	{
		if (enemyPlayer1.x < 48)
		{
			if (cnt1 % (FASTSPEED - (cnt / 10000)) == 0) {
				enemyPlayer1.x++;
				gotoxy(enemyPlayer1.x, enemyPlayer1.y);
				printf("▶");
				gotoxy(enemyPlayer1.x - 1, enemyPlayer1.y);
				printf("  ");
			}
		}
		if (enemyPlayer1.x == 48) // 부딪히면 사라짐
		{
			gotoxy(enemyPlayer1.x, enemyPlayer1.y);
			Sleep(20);
			printf("  ");
			right1 = false;
			atk1 = false;
		}
	}



	if (left1 == true) // 왼쪽 공격
	{
		if (enemyPlayer1.x > 10)
		{
			if (cnt1 % (FASTSPEED - (cnt / 10000)) == 0)
			{
				enemyPlayer1.x--;
				gotoxy(enemyPlayer1.x, enemyPlayer1.y);
				printf("◀ ");
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


	if (up1 == true) // 위쪽 공격
	{
		if (enemyPlayer1.y > 10)
		{
			if (cnt1 % (SLOWSPEED - (cnt / 20000)) == 0)
			{
				enemyPlayer1.y--;
				gotoxy(enemyPlayer1.x, enemyPlayer1.y);
				printf("▲");
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


	if (down1 == true) // 아래쪽 공격
	{
		if (enemyPlayer1.y < 30)
		{
			if (cnt1 % (SLOWSPEED - (cnt / 20000)) == 0)
			{
				enemyPlayer1.y++;
				gotoxy(enemyPlayer1.x, enemyPlayer1.y);
				printf("▼");
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

void DrawTurret2() { // 공격 2개째 위에것과 코드 똑같음
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
				printf("▶");
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
				printf("◀ ");
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
				printf("▲");
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
				printf("▼");
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

void Drawcharacter() // 캐릭터가 죽을 시 캐릭터 모습 출력
{
	gotoxy(25, 12); printf("┌──━━┐");
	gotoxy(25, 13); printf("│─────│");
	gotoxy(25, 14); printf("│  │  │");
	gotoxy(25, 15); printf("│  │  │");
	gotoxy(25, 16); printf("│ ┌─┐ │");
	gotoxy(25, 17); printf("└┬┬─┬┬┘");
	gotoxy(25, 18); printf(" ┘┘ └└ ");
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
		system("cls"); // 시작 전 화면 초기화

		a = gamestart(); // 게임을 시작하는지 안하는지 판단
		if (a == 1) { // 시작 하는 경우
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
				if (kbhit()) ch = getch(); // 캐릭터 이동 입력 받기

				switch (ch) // 입력 받아 캐릭터 이동
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




				DrawTurret1(); // 공격1 출력
				DrawTurret2(); // 공격2 출력
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
				if (myPlayer.x == enemyPlayer1.x && myPlayer.y == enemyPlayer1.y || myPlayer.x == enemyPlayer2.x && myPlayer.y == enemyPlayer2.y) // 공격에 맞았는지 판단
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
						gotoxy(20, 8); printf("ENTER : 시작, ESC : 나가기");
						gotoxy(20, 9); printf("SCORE : %d", cnt / 1000);
						Sleep(250);
						restart = getch(); // 재시작 하는지 입력받음
						Sleep(250);
						if (restart == ENTER) // 재시작 할 시
						{
							Sleep(250);
							cnt = 0;
							life=1;
							goto gg;
						}
						else if (restart == ESC) // 재시작 하지 않을 시
						{
							goto bb;
						}
						else
						{
							gotoxy(23, 10); printf("다시 입력해 주세요."); Sleep(200);
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

void ExtraLife() // 추가 체력 함수
{
	if (cnt%100000==0) // 점수가 100점이 되면 랜덤 위치에 추가 체력 배치
	{
		life_loc.x = (rand() % 40 + 10);
		life_loc.y = (rand() % 20 + 10);
		gotoxy(life_loc.x,life_loc.y);
		printf("♥");
	}	
}
#include < stdio.h	>
#include <windows.h>
#include <stdio.h>
#include <sddl.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <iostream>
#include <mmsystem.h>
#include<process.h>
#include<mmsystem.h>
#pragma comment(lib, "winmm.lib")
#include<stdlib.h>
#include<string.h>


#define BLOCK "      ■■■    "
#define BIGBLOCK "     ■■■■■   "
#define VOID "                 "
#define BLOCK2 "      □□□    "
#define BIGBLOCK2 "     □□□□□   "
#define LONG "      ◆◆◆    "

#define Flame "C:\\Users\\1117정은성\\Downloads\\flame.wav"
#define Flamehgih "C:\\Users\\1117정은성\\Downloads\\Flamehigh.wav"

#define FireBird "C:\\Users\\1117정은성\\Downloads\\FireBird.wav"
#define FireBirdhigh "C:\\Users\\1117정은성\\Downloads\\Firebirdhigh.wav"

#define kktu "C:\\Users\\1117정은성\\Downloads\\kktu.wav"

#define File "C:\\Users\\1117정은성\\Desktop\\VisualStudio\\C PROJECT\\C PROJECT\\MaxScore.txt"


/// <summary>
/// 색깔 지정
/// </summary>
/// <param name="text"></param>
/// <param name="back"></param>
void setcolor(unsigned short text, unsigned short back)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text | (back << 4));
}

void how(int* count);
int form(char maxScoreList[][255]);
int pick_m(int* count, int* count2, char maxScoreList[][255]);
void RESULT(int* score, int* cnt, int* maxcombo, int* song, char maxScoreList[][255]);

void Num1(int x, int y);
void Num2(int x, int y);
void Num3(int x, int y);
void Num4(int x, int y);
void Num5(int x, int y);
void Num6(int x, int y);
void Num7(int x, int y);
void Num8(int x, int y);
void Num9(int x, int y);
void Num0(int x, int y);


/// <summary>
/// F,J 노트 생성
/// </summary>
void spawnNote(int* map) {
	map[1] = 1;
	map[2] = 1;
	map[3] = 1;
}


/// <summary>
/// D,K 노트 생성
/// </summary>
void spawnNote2(int* map) {
	map[1] = 2;
	map[2] = 2;
	map[3] = 2;
}



/// <summary>
/// F,J 큰 노트 생성
/// </summary>
void spawnBigNote(int* map) {
	map[1] = 4;
	map[2] = 4;
	map[3] = 4;
}

/// <summary>
/// D,K 큰 노트 생성
/// </summary>
void spawnBigNote2(int* map) {
	map[1] = 5;
	map[2] = 5;
	map[3] = 5;
}

/// <summary>
/// 롱 노트 멈추기
/// </summary>
void spawnLongNotestop(int* Long) {
	*Long = 0;
}



/// <summary>
/// 롱노트 시작
/// </summary>
/// <param name="time">롱노트를 유지 할 시간</param>
void spawnLongNoteStart(int* map, int* Long, int time) {
	*Long = 1;
	map[1] = 3;
	map[2] = 3;
	map[3] = 3;
	Sleep(time);
	spawnLongNotestop(Long);
}


void MaxScoreSetting(char maxScoreList[][255]) {
	FILE* fp;
	int size = 255;
	int originScore = 0;
	char doc[255];
	fopen_s(&fp, File, "r");

	if (fp == NULL) {
		printf("파일을 불러오지못함");

		return;
	}

	int i = 0;
	while (feof(fp) == 0) {
		char doc[255];
		fgets(doc, size, fp);
		strcpy_s(maxScoreList[i], doc);
		i++;
	}




	fclose(fp);

}

void MaxScoreUpdate(int *song,int* score, char maxScoreList[][255]) {
	FILE* fp;
	char currentScore[255];
	int originScore;
	

	sprintf_s(currentScore,sizeof(currentScore), "%d", *score);
	strcat_s(currentScore, "\n");
	originScore = atoi(maxScoreList[*song-1]);
	if (originScore < *score) {
		strcpy_s(maxScoreList[*song-1], currentScore);

	}
	fopen_s(&fp,File, "w+");
	if (fp == NULL) {
		system("cls");
		printf("파일을 찾을 수 없음");

		Sleep(6000);
		return;
	}

	for (int i = 1; i < 3; i++) {
		strcat_s(maxScoreList[0], maxScoreList[i]);
	}

	fseek(fp, 0, SEEK_SET);
	fputs(maxScoreList[0], fp);
	fclose(fp);
}
//커서숨기기
void CursorView()
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1; //커서 굵기 (1 ~ 100)
	cursorInfo.bVisible = FALSE; //커서 Visible TRUE(보임) FALSE(숨김)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

/// <summary>
/// 풀스크린	
/// </summary>
void fullscreen() {
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
}


/// <summary>
/// 커서 이동 함수
/// </summary>
/// <param name="x">x좌표</param>
/// <param name="y">y좌표</param>
void gotoxy(int x, int y) {
	COORD pos = { 2 * x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


int inter_face() {

#pragma region 쿵덕쿵덕


	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
	printf("\n■                                                                                                                                                                                        ■");
	printf("\n■                                                                                                                                                                                        ■");
	printf("\n■                                                                                                                                                                                        ■");
	printf("\n■                                                                                                                                                                                        ■");
	printf("\n■                                                                                                                                                                                        ■");
	printf("■                                                          ######        ######  #     ######        ######   #                                                                          ■\n");
	printf("■                                                              ##        ##     ##         ##        ##      ##                                                                          ■ \n");
	printf("■                                                          ######        ######  #     ######        ######   #                                                                          ■ ");
	printf("■                                                              ##                          ##                                                                                            ■\n");
	printf("■                                                        ###########                #############                                                                                        ■ \n");
	printf("■                                                             ##          #########        ##         ##########                                                                         ■\n");
	printf("■                                                            ####                ##       ####                ##                                                                         ■\n");
	printf("■                                                           #    #               ##      #    #               ##                                                                         ■\n");
	printf("■                                                            ####                         ####                                                                                           ■\n■");
	printf("                                                                                                                                                                                        ■");
	printf("\n■                                                                                                                                                                                        ■");
	printf("\n■                                                                                                                                                                                        ■");
	printf("\n■                                                                                                                                                                                        ■");
	printf("\n■                                                                                                                                                                                        ■");
	printf("\n■                                                                                                                                                                                        ■");
	printf("\n■                                                                                                                                                                                        ■");
	printf("\n■                                                                                                                                                                                        ■");
	printf("\n■                                                                                                                                                                                        ■");
	printf("\n■                                                                                                                                                                                        ■");
	printf("\n■                                                                                                                                                                                        ■");
	printf("■                                                   ----------------------------------------------------------------                                                                     ■\n");
	printf("■                                                                                   곡 선택                                                                                              ■\n");
	printf("■                                                   ----------------------------------------------------------------                                                                     ■\n");
	printf("■                                                                                    설명                                                                                                ■ \n");
	printf("■                                                   ----------------------------------------------------------------                                                                     ■\n");
	printf("■                                                                                   종료하기                                                                                             ■\n");
	printf("■                                                                                                                                                                                        ■ ");
	printf("\n■                                                                                                                                                                                        ■");
	printf("\n■                                                                                                                                                                                        ■");
	printf("\n■                                                                                                                                                                                        ■");
	printf("\n■                                                                                                                                                                                        ■");
	printf("\n■                                                                                                                                                                                        ■");
	printf("\n■                                                                                                                                                                                        ■");
	printf("\n■                                                                                                                                                                                        ■");
	printf("\n■                                                                                                                                                                                        ■");
	printf("\n■                                                                                                                                                                                        ■");
	printf("\n■                                                                                                                                                                                        ■");
	printf("\n■                                                                                                                                                                                        ■");
	printf("\n■                                                                                                                                                                                        ■");
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");

#pragma endregion

#pragma region 조작


	int x = 40;
	int y = 27;
	gotoxy(x, y);
	while (1) {
		gotoxy(x, y);
		printf("  ");

		if (y == 31 && GetAsyncKeyState(0x44)) { //위
			y -= 2;
		}
		else if (y > 27 && y < 31 && GetAsyncKeyState(0x44)) {
			y -= 2;
		}
		else if (y > 27 && y < 31 && GetAsyncKeyState(0x4B)) {
			y += 2;
		}
		if (y == 27 && GetAsyncKeyState(0x4B)) { //아래
			y += 2;
		}
#pragma endregion

		if (GetAsyncKeyState(0x46) || GetAsyncKeyState(0x4A)) {
			if (y == 27) {
				system("cls");
				return 1;
				break;
			}
			if (y == 29) {
				system("cls");
				return 2;
				break;
			}
			if (y == 31) {
				system("cls");
				return 3;
				break;
			}
		}

		
		gotoxy(x, y);
		printf("▶");
		Sleep(200);
	}


}

//설명

void how(int* count) {
	//인게임 함수를 먼저 만들고 나서 예시를 보여주기 위해서 도움말을 가장 마지막에 만들자.
	/*printf("■■■              □□□             ◆◆◆\n");
	printf("■■■     F,J      □□□    D,K      ◆◆◆    아무거나 계속누르기!\n");
	printf("■■■              □□□             ◆◆◆\n");
	printf("\n");
	printf("\n");
	printf(" □□□□□              ■■■■■\n");
	printf(" □□□□□              ■■■■■\n");
	printf(" □□□□□              ■■■■■\n");
	printf("  F,J동시에               D,K 동시에\n");
	printf("\n");
	printf("\n");
	printf("                 D나K를 눌러 뒤로가기");*/
	setcolor(4, 0);
	printf("■■■");
	setcolor(9, 0);
	printf("             □□□");
	setcolor(14, 0);
	printf("	       ◆◆◆\n");
	setcolor(4, 0);
	printf("■■■     ");
	setcolor(7, 0);
	printf("F,J     ");
	setcolor(9, 0);
	printf("□□□    ");
	setcolor(7, 0);
	printf("D, K      ");
	setcolor(14, 0);
	printf("◆◆◆    ");
	setcolor(7, 0);
	printf("아무거나 계속누르기!\n");
	setcolor(4, 0);
	printf("■■■	");
	setcolor(9, 0);
	printf("           □□□             ");
	setcolor(14, 0);
	printf(" ◆◆◆\n");
	printf("\n");
	printf("\n");
	setcolor(9, 0);
	printf(" □□□□□             ");
	setcolor(4, 0);
	printf("■■■■■\n");
	setcolor(9, 0);
	printf(" □□□□□");
	setcolor(4, 0);
	printf("		■■■■■\n");
	setcolor(9, 0);
	printf(" □□□□□");
	setcolor(4, 0);
	printf("		■■■■■\n");
	setcolor(7, 0);
	printf("  F,J동시에");
	printf("		D, K 동시에\n");
	printf("\n");
	printf("\n");
	printf("                 D나K를 눌러 뒤로가기");
	while (1) {
		if (GetAsyncKeyState(0x44) || GetAsyncKeyState(0x4B)) {
			system("cls");
			*count = 1;
			return;

		}
	}
}
	
int form(char maxScoreList[][255]) {
	int count = 0;
	int cont = 0;
	while (1) {
		if (count == 0) {
			PlaySound(TEXT(kktu), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		}
	int pick = inter_face();

		if (pick == 1) {
		    int temp = pick_m(&cont, &count,maxScoreList);
			
			if (cont == 1) {
				return temp;
			}
			
			
		}
		if (pick == 2) {
			how(&count);
			
		}
		if (pick == 3) {
			system("cls");
			printf("강해져서 돌아오쎄요 ~ ^^\n");
			printf("강해져서 돌아오쎄요 ~ ^^\n");
			printf("강해져서 돌아오쎄요 ~ ^^\n");
			printf("강해져서 돌아오쎄요 ~ ^^\n");
			printf("강해져서 돌아오쎄요 ~ ^^\n");
			printf("강해져서 돌아오쎄요 ~ ^^\n");
			printf("강해져서 돌아오쎄요 ~ ^^\n");
			printf("강해져서 돌아오쎄요 ~ ^^\n");
			printf("강해져서 돌아오쎄요 ~ ^^\n");
			printf("강해져서 돌아오쎄요 ~ ^^\n");
			printf("강해져서 돌아오쎄요 ~ ^^\n");
			printf("강해져서 돌아오쎄요 ~ ^^\n");
			printf("강해져서 돌아오쎄요 ~ ^^\n");
			printf("강해져서 돌아오쎄요 ~ ^^\n");
			printf("강해져서 돌아오쎄요 ~ ^^\n");
			printf("강해져서 돌아오쎄요 ~ ^^\n");
			printf("강해져서 돌아오쎄요 ~ ^^\n");
			printf("강해져서 돌아오쎄요 ~ ^^\n");
			printf("강해져서 돌아오쎄요 ~ ^^\n");
			printf("강해져서 돌아오쎄요 ~ ^^\n");
			printf("강해져서 돌아오쎄요 ~ ^^\n");
			printf("강해져서 돌아오쎄요 ~ ^^\n");
			printf("강해져서 돌아오쎄요 ~ ^^\n");
			printf("강해져서 돌아오쎄요 ~ ^^\n");
			printf("강해져서 돌아오쎄요 ~ ^^\n");
			printf("강해져서 돌아오쎄요 ~ ^^\n");
			printf("강해져서 돌아오쎄요 ~ ^^\n");
			printf("강해져서 돌아오쎄요 ~ ^^\n");
			printf("강해져서 돌아오쎄요 ~ ^^\n");
			printf("강해져서 돌아오쎄요 ~ ^^\n");
			printf("강해져서 돌아오쎄요 ~ ^^\n");
			printf("강해져서 돌아오쎄요 ~ ^^\n");
			printf("강해져서 돌아오쎄요 ~ ^^\n");
			printf("강해져서 돌아오쎄요 ~ ^^\n");
			printf("강해져서 돌아오쎄요 ~ ^^\n");
			printf("강해져서 돌아오쎄요 ~ ^^\n");
			printf("강해져서 돌아오쎄요 ~ ^^\n");
			printf("강해져서 돌아오쎄요 ~ ^^\n");
			printf("강해져서 돌아오쎄요 ~ ^^\n");
			printf("강해져서 돌아오쎄요 ~ ^^\n");
			printf("강해져서 돌아오쎄요 ~ ^^\n");
			printf("강해져서 돌아오쎄요 ~ ^^\n");
			printf("강해져서 돌아오쎄요 ~ ^^\n");
			printf("강해져서 돌아오쎄요 ~ ^^\n");
			printf("강해져서 돌아오쎄요 ~ ^^\n");
			printf("강해져서 돌아오쎄요 ~ ^^\n");
			printf("강해져서 돌아오쎄요 ~ ^^\n");
			printf("강해져서 돌아오쎄요 ~ ^^\n");
			printf("강해져서 돌아오쎄요 ~ ^^\n");
			printf("강해져서 돌아오쎄요 ~ ^^\n");
			printf("강해져서 돌아오쎄요 ~ ^^\n");
			printf("강해져서 돌아오쎄요 ~ ^^\n");
			printf("강해져서 돌아오쎄요 ~ ^^\n");
			printf("강해져서 돌아오쎄요 ~ ^^\n");
			printf("강해져서 돌아오쎄요 ~ ^^\n");
			printf("강해져서 돌아오쎄요 ~ ^^\n");
			printf("강해져서 돌아오쎄요 ~ ^^\n");
			printf("강해져서 돌아오쎄요 ~ ^^\n");
			printf("강해져서 돌아오쎄요 ~ ^^\n");
			printf("강해져서 돌아오쎄요 ~ ^^\n");
			printf("강해져서 돌아오쎄요 ~ ^^\n");
			printf("강해져서 돌아오쎄요 ~ ^^\n");
			printf("강해져서 돌아오쎄요 ~ ^^\n");
			printf("강해져서 돌아오쎄요 ~ ^^\n");
			printf("강해져서 돌아오쎄요 ~ ^^\n");
			printf("강해져서 돌아오쎄요 ~ ^^\n");
			printf("강해져서 돌아오쎄요 ~ ^^\n");
			printf("강해져서 돌아오쎄요 ~ ^^\n");
			printf("강해져서 돌아오쎄요 ~ ^^\n");
			printf("강해져서 돌아오쎄요 ~ ^^\n");
			printf("강해져서 돌아오쎄요 ~ ^^\n");
			printf("강해져서 돌아오쎄요 ~ ^^\n");
			printf("강해져서 돌아오쎄요 ~ ^^\n");
			printf("강해져서 돌아오쎄요 ~ ^^\n");

			exit(0);
			
		}
	}

	return 0;
}




int pick_m(int* count, int* count2, char Maxscore[][255]) {
#pragma region 노래


	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
	printf("\n■                                                                                                                                                                                        ■");
	printf("\n■                                                                                                                                                                                        ■");
	printf("\n■                                                                                                                                                                                        ■");
	printf("\n■                                                                                                                                                                                        ■");
	printf("\n■                                                                                                                                                                                        ■");
	printf("■                                                                                                                                                                                        ■\n");
	printf("■                                                                                                                                                                                        ■ \n");
	printf("■                                                                                                                                                                                        ■ ");
	printf("■                                                                                                                                                                                        ■\n");
	printf("■                                                                                                                                                                                        ■ \n");
	printf("■                                                                                                                                                                                        ■\n");
	printf("■                                                                                                                                                                                        ■\n");
	printf("■                                                                                                                                                                                        ■\n");
	printf("■                                                                                                                                                                                        ■\n■");
	printf("                                                                                                                                                                                        ■");
	printf("\n■                                                                                                                                                                                        ■");
	printf("\n■                                                                                                                                                                                        ■");
	printf("\n■                                                                                                                                                                                        ■");
	printf("\n■                                                                                                                                                                                        ■");
	printf("\n■                                                                                                                                                                                        ■");
	printf("\n■                                                                                                                                                                                        ■");
	printf("\n■                                                                                                                                                                                        ■");
	printf("\n■                                                                                                                                                                                        ■");
	printf("\n■                                                                                                                                                                                        ■");
	printf("\n■                                                                                                                                                                                        ■");
	printf("■                                                                                                                                                                                        ■\n");
	printf("■                                                                                   염화                                                                                                 ■\n");
	printf("■                                                   ----------------------------------------------------------------                                                                     ■\n");
	printf("■                                                                                   불새                                                                                                 ■ \n");
	printf("■                                                   ----------------------------------------------------------------                                                                     ■\n");
	printf("■                                                                                추후 업데이트                                                                                           ■\n");
	printf("■                                                                                                                                                                                        ■ ");
	printf("\n■                                                                                                                                                                                        ■");
	printf("\n■                                                                       D와K를 동시에 눌러 뒤로가기                                                                                      ■");
	printf("\n■                                                                                                                                                                                        ■");
	printf("\n■                                                                                                                                                                                        ■");
	printf("\n■                                                                                                                                                                                        ■");
	printf("\n■                                                                                                                                                                                        ■");
	printf("\n■                                                                                                                                                                                        ■");
	printf("\n■                                                                                                                                                                                        ■");
	printf("\n■                                                                                                                                                                                        ■");
	printf("\n■                                                                                                                                                                                        ■");
	printf("\n■                                                                                                                                                                                        ■");
	printf("\n■                                                                                                                                                                                        ■");
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
#pragma endregion
	int x = 40;
	int y = 27;
	int cnt = 0;
	int temp;
	int score2;
	int Result[10] = { 0, };
	int x2 = 12; int y2 = 5;
	gotoxy(x, y);
	while (1) {
		gotoxy(x, y);
		printf("  ");

		if (GetAsyncKeyState(0x4B) && GetAsyncKeyState(0x44)) {
			PlaySound(NULL, 0, 0);
			*count2 = 0;
			system("cls");
			return 0;
		}
		if (y == 31 && GetAsyncKeyState(0x44)) { //위
			y -= 2;
			cnt = 0;
		}
		else if (y > 27 && y < 31 && GetAsyncKeyState(0x44)) {
			y -= 2;
			cnt = 0;
		}
		else if (y > 27 && y < 31 && GetAsyncKeyState(0x4B)) {
			y += 2;
			cnt = 0;
		}
		if (y == 27 && GetAsyncKeyState(0x4B)) { //아래
			y += 2;
			cnt = 0;
		}
		//음악 재생
		if (y == 27 && cnt != 1) {
			gotoxy(3, 5);
			printf("                                                                                                                                                                                 ");
			gotoxy(3, 6);
			printf("                                                                                                                                                                                 ");
			gotoxy(3, 7);
			printf("                                                                                                                                                                                 ");
			gotoxy(3, 8);
			printf("                                                                                                                                                                                 ");
			gotoxy(3, 9);
			printf("                                                                                                                                                                                 ");
			gotoxy(3, 10);
			printf("                                                                                                                                                                                 ");
			gotoxy(3, 11);
			printf("                                                                                                                                                                                 ");
			gotoxy(3, 12);
			printf("                                                                                                                                                                                 ");
			gotoxy(3, 13);
			printf("                                                                                                                                                                                 ");
			gotoxy(3, 14);
			printf("                                                                                                                                                                                 ");

			gotoxy(5, 5);
			printf("최고 점수 :");
			score2 = atoi(Maxscore[0]);

			for (int j = 0; j < 10; ++j) {
				temp = score2 % 10;
				Result[j] = temp;
				score2 = score2 / 10;
			}
			for (int i = 9; i >= 0; i--)
			{
				switch (Result[i])
				{
				case 0:
					Num0(x2, y2);
					x2 += 8;
					break;
				case 1:
					Num1(x2, y2);
					x2 += 8;
					break;
				case 2:
					Num2(x2, y2);
					x2 += 8;
					break;
				case 3:
					Num3(x2, y2);
					x2 += 8;
					break;
				case 4:
					Num4(x2, y2);
					x2 += 8;
					break;
				case 5:
					Num5(x2, y2);
					x2 += 8;
					break;
				case 6:
					Num6(x2, y2);
					x2 += 8;
					break;
				case 7:
					Num7(x2, y2);
					x2 += 8;
					break;
				case 8:
					Num8(x2, y2);
					x2 += 8;
					break;
				case 9:
					Num9(x2, y2);
					x2 += 8;
					break;
				default:
					break;
				}

				PlaySound(TEXT(Flamehgih), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
				cnt = 1;
			}
			x2 = 12;

		}
		if (y == 29 && cnt == 0) {
			score2 = atoi(Maxscore[1]);
			gotoxy(3, 5);
			printf("                                                                                                                                                                                 ");
			gotoxy(3, 6);
			printf("                                                                                                                                                                                 ");
			gotoxy(3, 7);
			printf("                                                                                                                                                                                 ");
			gotoxy(3, 8);
			printf("                                                                                                                                                                                 ");
			gotoxy(3, 9);
			printf("                                                                                                                                                                                 ");
			gotoxy(3, 10);
			printf("                                                                                                                                                                                 ");
			gotoxy(3, 11);
			printf("                                                                                                                                                                                 ");
			gotoxy(3, 12);
			printf("                                                                                                                                                                                 ");
			gotoxy(3, 13);
			printf("                                                                                                                                                                                 ");
			gotoxy(3, 14);
			printf("                                                                                                                                                                                 ");
			gotoxy(5, 5);
			printf("최고 점수 :");
			for (int j = 0; j < 10; ++j) {
				temp = score2 % 10;
				Result[j] = temp;
				score2 = score2 / 10;
			}
			for (int i = 9; i >= 0; i--)
			{
				switch (Result[i])
				{
				case 0:
					Num0(x2, y2);
					x2 += 8;
					break;
				case 1:
					Num1(x2, y2);
					x2 += 8;
					break;
				case 2:
					Num2(x2, y2);
					x2 += 8;
					break;
				case 3:
					Num3(x2, y2);
					x2 += 8;
					break;
				case 4:
					Num4(x2, y2);
					x2 += 8;
					break;
				case 5:
					Num5(x2, y2);
					x2 += 8;
					break;
				case 6:
					Num6(x2, y2);
					x2 += 8;
					break;
				case 7:
					Num7(x2, y2);
					x2 += 8;
					break;
				case 8:
					Num8(x2, y2);
					x2 += 8;
					break;
				case 9:
					Num9(x2, y2);
					x2 += 8;
					break;
				default:
					break;
				}

				PlaySound(TEXT(FireBirdhigh), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
				cnt = 1;
			}
		}

		x2 = 12;

		if (y == 31 && cnt == 0) {
			gotoxy(3, 5);
			printf("                                                                                                                                                                                 ");
			gotoxy(3, 6);
			printf("                                                                                                                                                                                 ");
			gotoxy(3, 7);
			printf("                                                                                                                                                                                 ");
			gotoxy(3, 8);
			printf("                                                                                                                                                                                 ");
			gotoxy(3, 9);
			printf("                                                                                                                                                                                 ");
			gotoxy(3, 10);
			printf("                                                                                                                                                                                 ");
			gotoxy(3, 11);
			printf("                                                                                                                                                                                 ");
			gotoxy(3, 12);
			printf("                                                                                                                                                                                 ");
			gotoxy(3, 13);
			printf("                                                                                                                                                                                 ");
			gotoxy(3, 14);
			printf("                                                                                                                                                                                 ");
			PlaySound(NULL, 0, 0);
		}

		gotoxy(x, y);
		printf("▶");
		Sleep(200);

		if (GetAsyncKeyState(0x46) || GetAsyncKeyState(0x4A)) {
			*count = 1;
			if (y == 27) {
				system("cls");
				return 1;


				break;
			}
			if (y == 29) {
				system("cls");
				return 2;
				break;
			}


		}

	}



}



//픽


/// <summary>
/// 맵 로딩
/// </summary>
void Map() {

	gotoxy(0, 0);
	printf("│                      │\n");
	printf("│                      │\n");
	printf("│                      │\n");
	printf("│                      │\n");
	printf("│                      │\n");
	printf("│                      │\n");
	printf("│                      │\n");
	printf("│                      │\n");
	printf("│                      │\n");
	printf("│                      │\n");
	printf("│                      │\n");
	printf("│                      │\n");
	printf("│                      │\n");
	printf("│                      │\n");
	printf("│                      │\n");
	printf("│                      │\n");
	printf("│                      │\n");
	printf("│                      │\n");
	printf("│                      │\n");
	printf("│                      │\n");
	printf("│                      │\n");
	printf("│                      │\n");
	printf("│                      │\n");
	printf("│                      │\n");
	printf("│                      │\n");
	printf("│                      │\n");
	printf("│                      │\n");
	printf("│                      │\n");
	printf("│                      │\n");
	printf("│                      │\n");
	printf("│                      │\n");
	printf("│                      │\n");
	printf("│                      │\n");
	printf("│                      │\n");
	printf("│                      │\n");
	printf("│                      │\n");
	printf("│                      │\n");
	printf("│                      │\n");
	printf("│                      │\n");
	printf("│                      │  ◀\n");
	printf("│                      │  ◀\n");
	printf("│                      │  ◀\n");
	printf("│                      │\n");
	printf("│                      │\n");
	printf("│                      │\n");
	printf("│                      │\n");
	printf("│                      │\n");
	printf("│                      │\n");
	printf("│                      │\n");
	printf("│                      │\n");
}

/// <summary>
/// 맵그리기
/// </summary>
void MapPrint(int *map) {
	int y = 0;
	for (int i = 0; i < 50; ++i) {
		y = i;


		switch (map[i])
		{
		case 1:
			gotoxy(1, y);
			setcolor(4, 0);
			printf("%s", BLOCK);
			setcolor(7, 0);

			break;
		case 2:
			gotoxy(1, y);
			setcolor(9, 0);

			printf("%s", BLOCK2);
			setcolor(7, 0);

			break;
		case 3:
			
			gotoxy(1, y);
			setcolor(14, 0);

			printf("%s", LONG);
			setcolor(7, 0);

			break;
		case 4:
			gotoxy(1, y);
			setcolor(4, 0);

			printf("%s", BIGBLOCK);
			setcolor(7, 0);
			
			break;
		case 5:
			gotoxy(1, y);
			setcolor(9, 0);

			printf("%s", BIGBLOCK2);
			setcolor(7, 0);

			break;
		default:
			gotoxy(1, y);

			printf("%s", VOID);
			break;
		}

		printf("\n");
	}
}

/// <summary>
/// 한칸씩 아래로 내리기
/// </summary>
void Setting(int* Long, int* combo, int *map) {


	for (int i = 50; i >= 0; i--) {
		if (*Long == 1) {
			map[1] = 3;
		}
		if (i != 50) {
			map[i + 1] = map[i];
			map[i] = 0;



		}
		/*else {
			map[i] = 0;

		}*/

		if (i == 50 && map[50] == 1 || i == 50 && map[50] == 2 || i == 50 && map[50] == 4|| i == 50 && map[50] == 5) {
			gotoxy(19, 25);
			printf("놓쳤소..       ");
			*combo = 0;

		}

	}
}

void Num1(int x, int y)
{
	gotoxy(x, y++);
	printf("  ######     ");
	gotoxy(x, y++);
	printf("###  ###     ");
	gotoxy(x, y++);
	printf("     ###     ");
	gotoxy(x, y++);
	printf("     ###     ");
	gotoxy(x, y++);
	printf("     ###     ");
	gotoxy(x, y++);
	printf("     ###     ");
	gotoxy(x, y++);
	printf("     ###     ");
	gotoxy(x, y++);
	printf("     ###     ");
	gotoxy(x, y++);
	printf("#############");
}

void Num2(int x, int y)
{
	gotoxy(x, y++);
	printf("  ########	 ");
	gotoxy(x, y++);
	printf("###     #### ");
	gotoxy(x, y++);
	printf("         ### ");
	gotoxy(x, y++);
	printf("        ###	 ");
	gotoxy(x, y++);
	printf("       ###	 ");
	gotoxy(x, y++);
	printf("      ###	 ");
	gotoxy(x, y++);
	printf("    ###		 ");
	gotoxy(x, y++);
	printf("  ###		 ");
	gotoxy(x, y++);
	printf("#############");
}

void Num3(int x, int y)
{
	gotoxy(x, y++);
	printf("  ########	 ");
	gotoxy(x, y++);
	printf("####     ### ");
	gotoxy(x, y++);
	printf("##        ###");
	gotoxy(x, y++);
	printf("         ### ");
	gotoxy(x, y++);
	printf("      ####	 ");
	gotoxy(x, y++);
	printf("         ### ");
	gotoxy(x, y++);
	printf("##        ###");
	gotoxy(x, y++);
	printf("####     ### ");
	gotoxy(x, y++);
	printf("  ########	 ");

}

void Num4(int x, int y)
{
	printf("    ######	  ");
	gotoxy(x, y++);
	printf("   ### ###	  ");
	gotoxy(x, y++);
	printf("  ###  ###	  ");
	gotoxy(x, y++);
	printf(" ###   ###	  ");
	gotoxy(x, y++);
	printf("###    ###	  ");
	gotoxy(x, y++);
	printf("###    ###	  ");
	gotoxy(x, y++);
	printf("##############");
	gotoxy(x, y++);
	printf("       ###	  ");
	gotoxy(x, y++);
	printf("       ###	  ");
}

void Num5(int x, int y)
{
	gotoxy(x, y++);
	printf("############# ");
	gotoxy(x, y++);
	printf("###			  ");
	gotoxy(x, y++);
	printf("###			  ");
	gotoxy(x, y++);
	printf("### #######	  ");
	gotoxy(x, y++);
	printf("##        ### ");
	gotoxy(x, y++);
	printf("           ###");
	gotoxy(x, y++);
	printf("           ###");
	gotoxy(x, y++);
	printf("###       ### ");
	gotoxy(x, y++);
	printf("  #########	  ");
}

void Num6(int x, int y)
{
	gotoxy(x, y++);
	printf("   ########	  ");
	gotoxy(x, y++);
	printf(" ###      ### ");
	gotoxy(x, y++);
	printf("###			  ");
	gotoxy(x, y++);
	printf("###			  ");
	gotoxy(x, y++);
	printf("###  ######	  ");
	gotoxy(x, y++);
	printf("####      ### ");
	gotoxy(x, y++);
	printf("###        ###");
	gotoxy(x, y++);
	printf(" ###      ### ");
	gotoxy(x, y++);
	printf("  #########	  ");
}

void Num7(int x, int y)
{
	gotoxy(x, y++);
	printf("##############");
	gotoxy(x, y++);
	printf(" ###       ###");
	gotoxy(x, y++);
	printf(" ###       ###");
	gotoxy(x, y++);
	printf("           ###");
	gotoxy(x, y++);
	printf("          ### ");
	gotoxy(x, y++);
	printf("          ### ");
	gotoxy(x, y++);
	printf("         ###  ");
	gotoxy(x, y++);
	printf("         ###  ");
	gotoxy(x, y++);
	printf("        ###	  ");
}

void Num8(int x, int y)
{
	gotoxy(x, y++);
	printf("   ########	  ");
	gotoxy(x, y++);
	printf(" ###      ### ");
	gotoxy(x, y++);
	printf("###        ###");
	gotoxy(x, y++);
	printf(" ###      ### ");
	gotoxy(x, y++);
	printf("   ########	  ");
	gotoxy(x, y++);
	printf(" ###      ### ");
	gotoxy(x, y++);
	printf("###        ###");
	gotoxy(x, y++);
	printf(" ###      ### ");
	gotoxy(x, y++);
	printf("   ########   ");
}

void Num9(int x, int y)
{
	gotoxy(x, y++);
	printf("   ########	  ");
	gotoxy(x, y++);
	printf(" ###      ### ");
	gotoxy(x, y++);
	printf("###        ###");
	gotoxy(x, y++);
	printf(" ###      ### ");
	gotoxy(x, y++);
	printf("   ########   ");
	gotoxy(x, y++);
	printf("        ###   ");
	gotoxy(x, y++);
	printf("       ###	  ");
	gotoxy(x, y++);
	printf("      ###	  ");
	gotoxy(x, y++);
	printf("     ###	  ");
}

void Num0(int x, int y)
{
	gotoxy(x, y++);
	printf("    ######	  ");
	gotoxy(x, y++);
	printf("  ###    ###  ");
	gotoxy(x, y++);
	printf(" ###      ### ");
	gotoxy(x, y++);
	printf("###        ###");
	gotoxy(x, y++);
	printf("###        ###");
	gotoxy(x, y++);
	printf("###        ###");
	gotoxy(x, y++);
	printf(" ###      ### ");
	gotoxy(x, y++);
	printf("  ###    ###  ");
	gotoxy(x, y++);
	printf("    ######	  ");
}



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
#include "header.h"
#include<string.h>


int Long = 0;
int song = 0;
int combo = 0;

#define Flame "C:\\Users\\1117정은성\\Downloads\\flame.wav"
#define Flamehgih "C:\\Users\\1117정은성\\Downloads\\Flamehigh.wav"
#define FireBird "C:\\Users\\1117정은성\\Downloads\\Firrebird.wav"
#define FireBirdhigh "C:\\Users\\1117정은성\\Downloads\\Firebirdhigh.wav"
#define kktu "C:\\Users\\1117정은성\\Downloads\\kktu.wav"
#define File "C:\\Users\\1117정은성\\Desktop\\VisualStudio\\C PROJECT\\C PROJECT\\MaxScore.txt"
#define dogclear "C:\\Users\\1117정은성\\Downloads\\2.wav"

int isEnd = 1;

char maxScoreList[4][255];


int map[51] = { 0, };
int score = 0;
int cnt[4] = { 0, };


int maxcombo = 0;



/// <summary>
/// 본격적인 게임
/// </summary>
/// <param name="arg"></param>
/// <returns></returns>
unsigned _stdcall Render(void* arg) {

	
	while (1) {
		if (maxcombo <= combo) {
			maxcombo = combo;
		}
		MapPrint(map);
		Setting(&Long, &combo, map);


		gotoxy(20, 3);
		printf("%d점", score);
		if (combo == 0) {
			gotoxy(21, 14);
			printf("                ");

		}
		else {
			gotoxy(21, 14);
			printf("%d번 연계했소!!", combo);
		}
		Sleep(20);
		if (GetAsyncKeyState(0x46)||GetAsyncKeyState(0x4A)) {

			

			if (map[40] == 1 && map[41] == 1 && map[42] == 1) {
				gotoxy(19, 25);
				printf("훌륭하오!!!!      ");
				score += 500;
				combo++;
				cnt[0]++;
				map[40] = 0;
				map[41] = 0;
				map[42] = 0;
			}
			else if (map[40] == 3 && map[41] == 3 && map[42] == 3) {
				gotoxy(19, 25);
				printf("훌륭하오!!        ");
				score += 100;
				combo++;
				cnt[0]++;

			}
			else if (map[40] == 1 && map[41] == 1 && map[42] == 0) {
				gotoxy(19, 25);
				printf("좋소!        ");

				score += 300;
				combo++;
				cnt[1]++;

				map[39] = 0;
				map[40] = 0;
				map[41] = 0;
			}
			else if (map[40] == 0 && map[41] == 1 && map[42] == 1) {
				gotoxy(19, 25);
				printf("좋소!         ");

				score += 300;
				combo++;
				cnt[1]++;

				map[41] = 0;
				map[42] = 0;
				map[43] = 0;
			}
			else if (map[40] == 1 && map[41] == 0 && map[42] == 0) {
				gotoxy(19, 25);
				printf("괜찮소        ");

				score += 150;
				combo++;
				cnt[2]++;

				map[38] = 0;
				map[39] = 0;
				map[40] = 0;
			}
			else if (map[40] == 0 && map[41] == 0 && map[42] == 1) {
				gotoxy(19, 25);
				printf("괜찮소        ");

				score += 150;
				combo++;
				cnt[2]++;


				map[42] = 0;
				map[43] = 0;
				map[44] = 0;
				map[45] = 0;
				map[46] = 0;
			}
			else if (map[40] == 0 && map[41] == 0 && map[42] == 0 && map[39] == 1) {
				gotoxy(19, 25);
				printf("괜찮소        ");

				score += 150;
				combo++;
				cnt[2]++;

				map[37] = 0;
				map[38] = 0;
				map[39] = 0;
			}
			else if (map[40] == 0 && map[41] == 0 && map[42] == 0 && map[39] == 0 && map[38] == 1) {
				gotoxy(19, 25);
				printf("빗나갔소..        ");

				combo = 0;
				cnt[3]++;

				map[36] = 0;
				map[37] = 0;
				map[38] = 0;
			}
		}

		if (GetAsyncKeyState(0x44)  || GetAsyncKeyState(0x4B)) {
			if (map[40] == 2 && map[41] == 2 && map[42] == 2) {
				gotoxy(19, 25);
				printf("훌륭하오!!        ");
				score += 500;
				combo++;
				cnt[0]++;

				map[40] = 0;
				map[41] = 0;
				map[42] = 0;
			}
			else if (map[40] == 3 && map[41] == 3 && map[42] == 3) {
				gotoxy(19, 25);
				printf("훌륭하오!!!!        ");
				score += 100;
				combo++;
				cnt[0]++;


			}
			else if (map[40] == 2 && map[41] == 2 && map[42] == 0) {
				gotoxy(19, 25);
				printf("좋소!        ");

				score += 300;
				combo++;
				cnt[1]++;

				map[39] = 0;
				map[40] = 0;
				map[41] = 0;
			}
			else if (map[40] == 0 && map[41] == 2 && map[42] == 2) {
				gotoxy(19, 25);
				printf("좋소!       ");

				score += 300;
				combo++;
				cnt[1]++;

				map[41] = 0;
				map[42] = 0;
				map[43] = 0;
			}
			else if (map[40] == 2 && map[41] == 0 && map[42] == 0) {
				gotoxy(19, 25);
				printf("괜찮소        ");

				score += 150;
				combo++;
				cnt[2]++;

				map[38] = 0;
				map[39] = 0;
				map[40] = 0;
			}
			else if (map[40] == 0 && map[41] == 0 && map[42] == 2) {
				gotoxy(19, 25);
				printf("괜찮소         ");

				score += 150;
				combo++;
				cnt[2]++;


				map[42] = 0;
				map[43] = 0;
				map[44] = 0;
				map[45] = 0;
				map[46] = 0;
			}
			else if (map[40] == 0 && map[41] == 0 && map[42] == 0 && map[39] == 2) {
				gotoxy(19, 25);
				printf("괜찮소         ");

				score += 150;
				combo++;
				cnt[2]++;

				map[37] = 0;
				map[38] = 0;
				map[39] = 0;
			}
			else if (map[40] == 0 && map[41] == 0 && map[42] == 0 && map[39] == 0 && map[38] == 2) {
				gotoxy(19, 25);
				printf("빗나갔소..         ");

				combo = 0;
				cnt[3]++;

				map[36] = 0;
				map[37] = 0;
				map[38] = 0;
			}
		}

		if (GetAsyncKeyState(0x46) && GetAsyncKeyState(0x4A)) {
			if (map[40] == 4 && map[41] == 4&& map[42] == 4) {
				gotoxy(19, 25);
				printf("훌륭하오!!!!      ");
				score += 500;
				combo++;
				cnt[0]++;

				map[40] = 0;
				map[41] = 0;
				map[42] = 0;
			}
			else if (map[40] == 3 && map[41] == 3 && map[42] == 3) {
				gotoxy(19, 25);
				printf("훌륭하오!!        ");
				score += 100;
				combo++;
				cnt[0]++;

			}
			else if (map[40] == 4 && map[41] == 4 && map[42] == 0) {
				gotoxy(19, 25);
				printf("좋소!        ");

				score += 300;
				combo++;
				cnt[1]++;

				map[39] = 0;
				map[40] = 0;
				map[41] = 0;
			}
			else if (map[40] == 0 && map[41] == 4 && map[42] == 4) {
				gotoxy(19, 25);
				printf("좋소!         ");

				score += 300;
				combo++;

				cnt[1]++;

				map[41] = 0;
				map[42] = 0;
				map[43] = 0;
			}
			else if (map[40] == 4 && map[41] == 0 && map[42] == 0) {
				gotoxy(19, 25);
				printf("괜찮소        ");

				score += 150;
				combo++;
				cnt[2]++;

				map[38] = 0;
				map[39] = 0;
				map[40] = 0;
			}
			else if (map[40] == 0 && map[41] == 0 && map[42] == 4) {
				gotoxy(19, 25);
				printf("괜찮소        ");

				score += 150;
				combo++;
				cnt[2]++;


				map[42] = 0;
				map[43] = 0;
				map[44] = 0;
				map[45] = 0;
				map[46] = 0;
			}
			else if (map[40] == 0 && map[41] == 0 && map[42] == 0 && map[39] == 4) {
				gotoxy(19, 25);
				printf("괜찮소        ");

				score += 150;
				combo++;
				cnt[2]++;

				map[37] = 0;
				map[38] = 0;
				map[39] = 0;
			}
			else if (map[40] == 0 && map[41] == 0 && map[42] == 0 && map[39] == 0 && map[38] == 4) {
				gotoxy(19, 25);
				printf("빗나갔소..        ");

				combo = 0;
				cnt[3]++;

				map[36] = 0;
				map[37] = 0;
				map[38] = 0;
			}
		}

		if (GetAsyncKeyState(0x44) && GetAsyncKeyState(0x4B)) {
			if (map[40] == 5 && map[41] == 5 && map[42] == 5) {
				gotoxy(19, 25);
				printf("훌륭하오!!!!      ");
				score += 500;
				combo++;
				cnt[0]++;

				map[40] = 0;
				map[41] = 0;
				map[42] = 0;
			}
			else if (map[40] == 3 && map[41] == 3 && map[42] == 3) {
				gotoxy(19, 25);
				printf("훌륭하오!!        ");
				score += 100;
				combo++;
				cnt[0]++;

			}
			else if (map[40] == 5 && map[41] == 5 && map[42] == 0) {
				gotoxy(19, 25);
				printf("좋소!        ");

				score += 300;
				combo++;
				cnt[1]++;

				map[39] = 0;
				map[40] = 0;
				map[41] = 0;
			}
			else if (map[40] == 0 && map[41] == 5 && map[42] == 5) {
				gotoxy(19, 25);
				printf("좋소!         ");

				score += 300;
				combo++;
				cnt[1]++;

				map[41] = 0;
				map[42] = 0;
				map[43] = 0;
			}
			else if (map[40] == 5 && map[41] == 0 && map[42] == 0) {
				gotoxy(19, 25);
				printf("괜찮소        ");

				score += 150;
				combo++;
				cnt[2]++;


				map[38] = 0;
				map[39] = 0;
				map[40] = 0;
			}
			else if (map[40] == 0 && map[41] == 0 && map[42] == 5) {
				gotoxy(19, 25);
				printf("괜찮소        ");

				score += 150;
				combo++;
				cnt[2]++;


				map[42] = 0;
				map[43] = 0;
				map[44] = 0;
				map[45] = 0;
				map[46] = 0;
			}
			else if (map[40] == 0 && map[41] == 0 && map[42] == 0 && map[39] == 5) {
				gotoxy(19, 25);
				printf("괜찮소        ");

				score += 150;
				combo++;
				cnt[2]++;

				map[37] = 0;
				map[38] = 0;
				map[39] = 0;
			}
			else if (map[40] == 0 && map[41] == 0 && map[42] == 0 && map[39] == 0 && map[38] == 5) {
				gotoxy(19, 25);
				printf("빗나갔소..        ");

				combo = 0;
				cnt[3]++;

				map[36] = 0;
				map[37] = 0;
			}
		}

		if (isEnd == 0) {
			_endthread();
		}
	}

	

	return 0;
}



//void RESULT(int* score, int* cnt, int* maxcombo, int* song, char maxScoreList[][255]) {
//	int score2;
//	int Result[10] = { 0, };
//	int temp;
//	int Random[10] = { 0, };
//	int cnt2[4] = { 0, };
//	int cntResult[3];
//	score2 = *score;
//	int maxcomboResult[3];
//
//	for (int j = 0; j < 10; ++j) {
//		temp = score2 % 10;
//		Result[j] = temp;
//		score2 = score2 / 10;
//	}
//	double firsttime = 0;
//	double secondtime = 0;
//	int x = 10, y = 3;
//	int current = 0;
//
//	system("cls");
//	
//		for (;;) {
//			x = 10;
//			for (int i = 9; i >= current; i--) {
//				Random[i] = rand() % 10;
//
//				firsttime += 0.01;
//				secondtime += 0.01;
//				if (firsttime >= 3) {
//					if (secondtime >= 3) {
//						if (Random[current] == Result[current]) {
//							current += 1;
//							secondtime = 0;
//						}
//					}
//				}
//				switch (Random[i])
//				{
//				case 0:
//					Num0(x, y);
//					x += 8;
//					break;
//				case 1:
//					Num1(x, y);
//					x += 8;
//					break;
//				case 2:
//					Num2(x, y);
//					x += 8;
//					break;
//				case 3:
//					Num3(x, y);
//					x += 8;
//					break;
//				case 4:
//					Num4(x, y);
//					x += 8;
//					break;
//				case 5:
//					Num5(x, y);
//					x += 8;
//					break;
//				case 6:
//					Num6(x, y);
//					x += 8;
//					break;
//				case 7:
//					Num7(x, y);
//					x += 8;
//					break;
//				case 8:
//					Num8(x, y);
//					x += 8;
//					break;
//				case 9:
//					Num9(x, y);
//					x += 8;
//					break;
//				default:
//					break;
//				}
//			}
//			if (current == 9) break;
//
//
//		}
//		system("cls");
//
//		Sleep(2000);
//	x = 3;
//	gotoxy(x, y);
//	printf("점수 : ");
//	x = 10;
//	for (int i = 9; i >= 0; i--) {
//		switch (Result[i])
//		{
//		case 0:
//			Num0(x, y);
//			x += 8;
//			break;
//		case 1:
//			Num1(x, y);
//			x += 8;
//			break;
//		case 2:
//			Num2(x, y);
//			x += 8;
//			break;
//		case 3:
//			Num3(x, y);
//			x += 8;
//			break;
//		case 4:
//			Num4(x, y);
//			x += 8;
//			break;
//		case 5:
//			Num5(x, y);
//			x += 8;
//			break;
//		case 6:
//			Num6(x, y);
//			x += 8;
//			break;
//		case 7:
//			Num7(x, y);
//			x += 8;
//			break;
//		case 8:
//			Num8(x, y);
//			x += 8;
//			break;
//		case 9:
//			Num9(x, y);
//			x += 8;
//			break;
//		default:
//			break;
//		}
//	}
//
//	x = 3;
//	y = 18;
//	gotoxy(x, y);
//	printf("훌륭하오! :");
//
//	x = 8;
//	y = 16;
//	for (int j = 0; j < 3; ++j) {
//		temp = cnt[0] % 10;
//		cntResult[j] = temp;
//		cnt[0] /= 10;
//	}
//
//
//	for (int i = 2; i >= 0; i--)
//	{
//		switch (cntResult[i])
//		{
//		case 0:
//			Num0(x, y);
//			x += 8;
//			break;
//		case 1:
//			Num1(x, y);
//			x += 8;
//			break;
//		case 2:
//			Num2(x, y);
//			x += 8;
//			break;
//		case 3:
//			Num3(x, y);
//			x += 8;
//			break;
//		case 4:
//			Num4(x, y);
//			x += 8;
//			break;
//		case 5:
//			Num5(x, y);
//			x += 8;
//			break;
//		case 6:
//			Num6(x, y);
//			x += 8;
//			break;
//		case 7:
//			Num7(x, y);
//			x += 8;
//			break;
//		case 8:
//			Num8(x, y);
//			x += 8;
//			break;
//		case 9:
//			Num9(x, y);
//			x += 8;
//			break;
//		default:
//			break;
//		}
//
//	}
//
//
//	for (int j = 0; j < 3; ++j) {
//		temp = cnt[1] % 10;
//		cntResult[j] = temp;
//		cnt[1] /= 10;
//	}
//	x = 3;
//	y = 28;
//	gotoxy(x, y);
//	printf("좋소!  ");
//
//	x = 8;
//	y = 28;
//	gotoxy(x, y);
//
//	for (int i = 2; i >= 0; i--)
//	{
//		switch (cntResult[i])
//		{
//		case 0:
//			Num0(x, y);
//			x += 8;
//			break;
//		case 1:
//			Num1(x, y);
//			x += 8;
//			break;
//		case 2:
//			Num2(x, y);
//			x += 8;
//			break;
//		case 3:
//			Num3(x, y);
//			x += 8;
//			break;
//		case 4:
//			Num4(x, y);
//			x += 8;
//			break;
//		case 5:
//			Num5(x, y);
//			x += 8;
//			break;
//		case 6:
//			Num6(x, y);
//			x += 8;
//			break;
//		case 7:
//			Num7(x, y);
//			x += 8;
//			break;
//		case 8:
//			Num8(x, y);
//			x += 8;
//			break;
//		case 9:
//			Num9(x, y);
//			x += 8;
//			break;
//		default:
//			break;
//		}
//
//	}
//
//	x = 34;
//	y = 18;
//	gotoxy(x, y);
//	printf("괜찮소.  ");
//
//	x = 39;
//	y = 16;
//	gotoxy(x, y);
//
//	for (int j = 0; j < 3; ++j) {
//		temp = cnt[2] % 10;
//		cntResult[j] = temp;
//		cnt[2] /= 10;
//	}
//	for (int i = 2; i >= 0; i--)
//	{
//		switch (cntResult[i])
//		{
//		case 0:
//			Num0(x, y);
//			x += 8;
//			break;
//		case 1:
//			Num1(x, y);
//			x += 8;
//			break;
//		case 2:
//			Num2(x, y);
//			x += 8;
//			break;
//		case 3:
//			Num3(x, y);
//			x += 8;
//			break;
//		case 4:
//			Num4(x, y);
//			x += 8;
//			break;
//		case 5:
//			Num5(x, y);
//			x += 8;
//			break;
//		case 6:
//			Num6(x, y);
//			x += 8;
//			break;
//		case 7:
//			Num7(x, y);
//			x += 8;
//			break;
//		case 8:
//			Num8(x, y);
//			x += 8;
//			break;
//		case 9:
//			Num9(x, y);
//			x += 8;
//			break;
//		default:
//			break;
//		}
//
//	}
//
//
//	x = 34;
//	y = 28;
//	gotoxy(x, y);
//	printf("빗나갔소..");
//
//	x = 39;
//	y = 28;
//	gotoxy(x, y);
//	for (int j = 0; j < 3; ++j) {
//		temp = cnt[3] % 10;
//		cntResult[j] = temp;
//		cnt[3] /= 10;
//	}
//
//	for (int i = 2; i >= 0; i--)
//	{
//		switch (cntResult[i])
//		{
//		case 0:
//			Num0(x, y);
//			x += 8;
//			break;
//		case 1:
//			Num1(x, y);
//			x += 8;
//			break;
//		case 2:
//			Num2(x, y);
//			x += 8;
//			break;
//		case 3:
//			Num3(x, y);
//			x += 8;
//			break;
//		case 4:
//			Num4(x, y);
//			x += 8;
//			break;
//		case 5:
//			Num5(x, y);
//			x += 8;
//			break;
//		case 6:
//			Num6(x, y);
//			x += 8;
//			break;
//		case 7:
//			Num7(x, y);
//			x += 8;
//			break;
//		case 8:
//			Num8(x, y);
//			x += 8;
//			break;
//		case 9:
//			Num9(x, y);
//			x += 8;
//			break;
//		default:
//			break;
//		}
//
//	}
//
//	for (int j = 0; j < 3; ++j) {
//		temp = *maxcombo % 10;
//		maxcomboResult[j] = temp;
//		*maxcombo /= 10;
//	}
//	x = 5;
//	y = 40;
//	gotoxy(x, y);
//	printf("최대 연계!");
//
//	x = 12;
//	y = 40;
//	gotoxy(x, y);
//	for (int i = 2; i >= 0; i--)
//	{
//		switch (maxcomboResult[i])
//		{
//		case 0:
//			Num0(x, y);
//			x += 8;
//			break;
//		case 1:
//			Num1(x, y);
//			x += 8;
//			break;
//		case 2:
//			Num2(x, y);
//			x += 8;
//			break;
//		case 3:
//			Num3(x, y);
//			x += 8;
//			break;
//		case 4:
//			Num4(x, y);
//			x += 8;
//			break;
//		case 5:
//			Num5(x, y);
//			x += 8;
//			break;
//		case 6:
//			Num6(x, y);
//			x += 8;
//			break;
//		case 7:
//			Num7(x, y);
//			x += 8;
//			break;
//		case 8:
//			Num8(x, y);
//			x += 8;
//			break;
//		case 9:
//			Num9(x, y);
//			x += 8;
//			break;
//		default:
//			break;
//		}
//
//	}
//
//
//	x = 80;
//	y = 40;
//	gotoxy(x, y);
//	printf("D나K를 눌러 계속");
//
//	MaxScoreUpdate(song, score, maxScoreList);
//	while (1) {
//		if (GetAsyncKeyState(0x44) || GetAsyncKeyState(0x4B))
//		{
//			break;
//		}
//	}
//}

void PlayMusic() {
	switch (song)
	{
	case 1:
		PlaySound(TEXT(Flame), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		break;
	case 2:
		PlaySound(TEXT(FireBird), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

		break;
	default:
		break;
	}
}
void RESULT() {
	int score2;
	int Result[10] = { 0, };
	int temp;
	int Random[10] = { 0, };
	int cnt2[4] = { 0, };
	int cntResult[3];
	score2 = score;
	int maxcomboResult[3];

	for (int j = 0; j < 10; ++j) {
		temp = score2 % 10;
		Result[j] = temp;
		score2 = score2 / 10;
	}
	double firsttime = 0;
	double secondtime = 0;
	int x = 10, y = 3;
	int current = 0;

	system("cls");

	for (;;) {
		x = 10;
		for (int i = 9; i >= current; i--) {
			Random[i] = rand() % 10;

			firsttime += 0.01;
			secondtime += 0.01;
			if (firsttime >= 3) {
				if (secondtime >= 3) {
					if (Random[current] == Result[current]) {
						current += 1;
						secondtime = 0;
					}
				}
			}
			switch (Random[i])
			{
			case 0:
				Num0(x, y);
				x += 8;
				break;
			case 1:
				Num1(x, y);
				x += 8;
				break;
			case 2:
				Num2(x, y);
				x += 8;
				break;
			case 3:
				Num3(x, y);
				x += 8;
				break;
			case 4:
				Num4(x, y);
				x += 8;
				break;
			case 5:
				Num5(x, y);
				x += 8;
				break;
			case 6:
				Num6(x, y);
				x += 8;
				break;
			case 7:
				Num7(x, y);
				x += 8;
				break;
			case 8:
				Num8(x, y);
				x += 8;
				break;
			case 9:
				Num9(x, y);
				x += 8;
				break;
			default:
				break;
			}
		}
		if (current == 9) break;


	}
	system("cls");

	x = 3;
	gotoxy(x, y);
	printf("점수 : ");
	x = 10;
	for (int i = 9; i >= 0; i--) {
		switch (Result[i])
		{
		case 0:
			Num0(x, y);
			x += 8;
			break;
		case 1:
			Num1(x, y);
			x += 8;
			break;
		case 2:
			Num2(x, y);
			x += 8;
			break;
		case 3:
			Num3(x, y);
			x += 8;
			break;
		case 4:
			Num4(x, y);
			x += 8;
			break;
		case 5:
			Num5(x, y);
			x += 8;
			break;
		case 6:
			Num6(x, y);
			x += 8;
			break;
		case 7:
			Num7(x, y);
			x += 8;
			break;
		case 8:
			Num8(x, y);
			x += 8;
			break;
		case 9:
			Num9(x, y);
			x += 8;
			break;
		default:
			break;
		}
	}

	x = 3;
	y = 18;
	gotoxy(x, y);
	printf("훌륭하오! :");

	x = 8;
	y = 16;
	for (int j = 0; j < 3; ++j) {
		temp = cnt[0] % 10;
		cntResult[j] = temp;
		cnt[0] /= 10;
	}


	for (int i = 2; i >= 0; i--)
	{
		switch (cntResult[i])
		{
		case 0:
			Num0(x, y);
			x += 8;
			break;
		case 1:
			Num1(x, y);
			x += 8;
			break;
		case 2:
			Num2(x, y);
			x += 8;
			break;
		case 3:
			Num3(x, y);
			x += 8;
			break;
		case 4:
			Num4(x, y);
			x += 8;
			break;
		case 5:
			Num5(x, y);
			x += 8;
			break;
		case 6:
			Num6(x, y);
			x += 8;
			break;
		case 7:
			Num7(x, y);
			x += 8;
			break;
		case 8:
			Num8(x, y);
			x += 8;
			break;
		case 9:
			Num9(x, y);
			x += 8;
			break;
		default:
			break;
		}

	}


	for (int j = 0; j < 3; ++j) {
		temp = cnt[1] % 10;
		cntResult[j] = temp;
		cnt[1] /= 10;
	}
	x = 3;
	y = 28;
	gotoxy(x, y);
	printf("좋소!  ");

	x = 8;
	y = 28;
	gotoxy(x, y);

	for (int i = 2; i >= 0; i--)
	{
		switch (cntResult[i])
		{
		case 0:
			Num0(x, y);
			x += 8;
			break;
		case 1:
			Num1(x, y);
			x += 8;
			break;
		case 2:
			Num2(x, y);
			x += 8;
			break;
		case 3:
			Num3(x, y);
			x += 8;
			break;
		case 4:
			Num4(x, y);
			x += 8;
			break;
		case 5:
			Num5(x, y);
			x += 8;
			break;
		case 6:
			Num6(x, y);
			x += 8;
			break;
		case 7:
			Num7(x, y);
			x += 8;
			break;
		case 8:
			Num8(x, y);
			x += 8;
			break;
		case 9:
			Num9(x, y);
			x += 8;
			break;
		default:
			break;
		}

	}

	x = 34;
	y = 18;
	gotoxy(x, y);
	printf("괜찮소.  ");

	x = 39;
	y = 16;
	gotoxy(x, y);

	for (int j = 0; j < 3; ++j) {
		temp = cnt[2] % 10;
		cntResult[j] = temp;
		cnt[2] /= 10;
	}
	for (int i = 2; i >= 0; i--)
	{
		switch (cntResult[i])
		{
		case 0:
			Num0(x, y);
			x += 8;
			break;
		case 1:
			Num1(x, y);
			x += 8;
			break;
		case 2:
			Num2(x, y);
			x += 8;
			break;
		case 3:
			Num3(x, y);
			x += 8;
			break;
		case 4:
			Num4(x, y);
			x += 8;
			break;
		case 5:
			Num5(x, y);
			x += 8;
			break;
		case 6:
			Num6(x, y);
			x += 8;
			break;
		case 7:
			Num7(x, y);
			x += 8;
			break;
		case 8:
			Num8(x, y);
			x += 8;
			break;
		case 9:
			Num9(x, y);
			x += 8;
			break;
		default:
			break;
		}

	}


	x = 34;
	y = 28;
	gotoxy(x, y);
	printf("빗나갔소..");

	x = 39;
	y = 28;
	gotoxy(x, y);
	for (int j = 0; j < 3; ++j) {
		temp = cnt[3] % 10;
		cntResult[j] = temp;
		cnt[3] /= 10;
	}

	for (int i = 2; i >= 0; i--)
	{
		switch (cntResult[i])
		{
		case 0:
			Num0(x, y);
			x += 8;
			break;
		case 1:
			Num1(x, y);
			x += 8;
			break;
		case 2:
			Num2(x, y);
			x += 8;
			break;
		case 3:
			Num3(x, y);
			x += 8;
			break;
		case 4:
			Num4(x, y);
			x += 8;
			break;
		case 5:
			Num5(x, y);
			x += 8;
			break;
		case 6:
			Num6(x, y);
			x += 8;
			break;
		case 7:
			Num7(x, y);
			x += 8;
			break;
		case 8:
			Num8(x, y);
			x += 8;
			break;
		case 9:
			Num9(x, y);
			x += 8;
			break;
		default:
			break;
		}

	}

	for (int j = 0; j < 3; ++j) {
		temp = maxcombo % 10;
		maxcomboResult[j] = temp;
		maxcombo /= 10;
	}
	x = 5;
	y = 40;
	gotoxy(x, y);
	printf("최대 연계!");

	x = 12;
	y = 40;
	gotoxy(x, y);
	for (int i = 2; i >= 0; i--)
	{
		switch (maxcomboResult[i])
		{
		case 0:
			Num0(x, y);
			x += 8;
			break;
		case 1:
			Num1(x, y);
			x += 8;
			break;
		case 2:
			Num2(x, y);
			x += 8;
			break;
		case 3:
			Num3(x, y);
			x += 8;
			break;
		case 4:
			Num4(x, y);
			x += 8;
			break;
		case 5:
			Num5(x, y);
			x += 8;
			break;
		case 6:
			Num6(x, y);
			x += 8;
			break;
		case 7:
			Num7(x, y);
			x += 8;
			break;
		case 8:
			Num8(x, y);
			x += 8;
			break;
		case 9:
			Num9(x, y);
			x += 8;
			break;
		default:
			break;
		}

	}


	x = 80;
	y = 40;
	gotoxy(x, y);
	printf("D나K를 눌러 계속");

	MaxScoreUpdate(&song, &score, maxScoreList);
	while (1) {
		if (GetAsyncKeyState(0x44) || GetAsyncKeyState(0x4B))
		{
			break;
		}
	}
}


void DropNote() {
	switch (song) {
#pragma region 불꽃


	case 1: // 불꽃

		spawnNote(map);
		Sleep(220);
		PlayMusic();
		Sleep(1250);
		spawnNote(map);
		Sleep(1400);
		spawnNote(map);

		Sleep(1090);
		spawnBigNote(map);
		Sleep(2100);
		spawnNote(map);
		Sleep(1497);
		spawnNote(map);
		Sleep(1597);
		spawnNote(map);
		Sleep(1197);
		spawnNote(map);
		Sleep(4600);
		spawnNote(map);//사요나라
		Sleep(600);
		spawnNote(map);
		Sleep(300);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(880);
		spawnNote(map);//아리가또
		Sleep(200);
		spawnNote(map);
		Sleep(350);
		spawnNote(map);
		Sleep(250);
		spawnNote(map);

		Sleep(750);
		spawnNote(map);
		Sleep(220);
		spawnNote(map);
		Sleep(320);
		spawnNote(map);
		Sleep(220);
		spawnNote(map);
		Sleep(320);
		spawnNote(map);
		Sleep(220);
		spawnNote(map);
		Sleep(1400);

		spawnNote(map);
		Sleep(250);
		spawnNote(map);
		Sleep(290);
		spawnNote(map);
		Sleep(250);
		spawnNote(map);
		Sleep(330);
		spawnNote(map);
		Sleep(680);
		spawnNote(map);
		Sleep(300);
		spawnNote(map);
		Sleep(300);
		spawnNote(map);
		Sleep(1000);
		spawnNote(map);
		Sleep(300);
		spawnNote(map);
		Sleep(300);
		spawnNote(map);
		Sleep(300);
		spawnNote(map);
		Sleep(300);
		spawnLongNoteStart(map, &Long, 1200);
		Sleep(500);
		spawnNote(map);
		Sleep(500);
		spawnNote(map);
		Sleep(300);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(880);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(290);
		spawnNote(map);
		Sleep(250);
		spawnNote(map);

		Sleep(750);
		spawnNote(map);
		Sleep(220);
		spawnNote(map);
		Sleep(320);
		spawnNote(map);
		Sleep(220);
		spawnNote(map);
		Sleep(320);
		spawnNote(map);
		Sleep(220);
		spawnLongNoteStart(map, &Long, 1200);

		Sleep(600);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(300);
		spawnNote(map);
		Sleep(250);
		spawnNote(map);
		Sleep(350);
		spawnNote(map);
		Sleep(350);
		spawnNote(map);
		Sleep(350);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);

		Sleep(650);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(400);
		spawnNote(map);
		Sleep(250);
		spawnNote(map);
		Sleep(550);
		spawnNote(map);
		Sleep(550);
		spawnBigNote(map);
		Sleep(380);
		spawnBigNote(map);
		Sleep(380);
		spawnBigNote(map);
		Sleep(380);
		spawnBigNote(map);
		Sleep(380);
		spawnNote(map);// 하이라이트 시작
		Sleep(380);
		spawnNote(map);
		Sleep(370);
		spawnBigNote(map);
		Sleep(370);
		spawnNote(map);
		Sleep(380);
		spawnNote(map);
		Sleep(380);
		spawnNote(map);
		Sleep(380);
		spawnBigNote(map);
		Sleep(380);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(300);
		spawnNote(map);
		Sleep(370);
		spawnNote(map);
		Sleep(370);
		spawnBigNote(map);
		Sleep(370);
		spawnNote(map);
		Sleep(370);
		spawnNote(map);
		Sleep(370);
		spawnNote(map);
		Sleep(370);
		spawnBigNote(map);
		Sleep(370);
		spawnNote(map);
		Sleep(370);
		spawnNote(map);
		Sleep(370);
		spawnNote(map);
		Sleep(370);
		spawnBigNote(map);
		Sleep(370);
		spawnNote(map);
		Sleep(370);
		spawnNote(map);
		Sleep(370);
		spawnNote(map);
		Sleep(370);
		spawnBigNote(map);
		Sleep(370);
		spawnNote(map);
		Sleep(300);
		spawnNote(map);
		Sleep(370);
		spawnNote(map);
		Sleep(390);
		spawnBigNote(map);
		Sleep(400);
		spawnNote(map);
		Sleep(400);
		spawnNote(map);
		Sleep(400);
		spawnNote(map);
		Sleep(400);
		spawnBigNote(map);
		Sleep(400);

		spawnNote(map);
		Sleep(300);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(390);
		spawnNote(map);
		Sleep(320);
		spawnNote(map);
		Sleep(300);
		spawnNote(map);
		Sleep(450);

		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(390);
		spawnNote(map);
		Sleep(420);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(390);
		spawnNote(map);
		Sleep(420);
		spawnNote(map);
		Sleep(300);
		spawnNote(map);
		Sleep(450);

		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(290);
		spawnNote(map);
		Sleep(400);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(300);
		spawnBigNote(map);
		Sleep(390);
		spawnBigNote(map);
		Sleep(390);
		spawnBigNote(map);
		Sleep(400);
		spawnBigNote(map);
		Sleep(400);
		spawnBigNote(map);
		Sleep(400);
		spawnBigNote(map);
		Sleep(400);
		spawnBigNote(map);
		Sleep(400);
		spawnLongNoteStart(map, &Long, 2400);
		Sleep(1100);
		spawnLongNoteStart(map, &Long, 600);//보쿠타치와

		Sleep(250);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);

		spawnLongNoteStart(map, &Long, 600);

		Sleep(150);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnLongNoteStart(map, &Long, 250);

		Sleep(100);
		spawnNote(map);
		Sleep(200);
		spawnLongNoteStart(map, &Long, 250);

		Sleep(100);
		spawnNote(map);
		Sleep(200);
		spawnLongNoteStart(map, &Long, 600);
		Sleep(1250);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);

		Sleep(500);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(400);
		spawnNote(map);
		Sleep(400);
		spawnNote(map);
		Sleep(400);
		spawnNote(map);
		Sleep(400);
		spawnBigNote(map);
		Sleep(370);
		spawnBigNote(map);
		Sleep(600);
		spawnNote(map);
		Sleep(600);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(1000);

		spawnNote(map);
		Sleep(220);
		spawnNote(map);
		Sleep(220);
		spawnNote(map);
		Sleep(220);
		spawnNote(map);
		Sleep(220);
		spawnNote(map);

		Sleep(600);
		spawnNote(map);
		Sleep(220);
		spawnNote(map);
		Sleep(220);
		spawnNote(map);
		Sleep(220);
		spawnNote(map);
		Sleep(220);
		spawnNote(map);
		Sleep(900);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);

		Sleep(650);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(400);
		spawnNote(map);
		Sleep(400);
		spawnBigNote(map);
		Sleep(400);
		spawnBigNote(map);
		Sleep(400);
		spawnBigNote(map);
		Sleep(400);
		spawnBigNote(map);
		Sleep(600);
		spawnNote(map);
		Sleep(400);
		spawnNote(map);
		Sleep(600);
		spawnNote(map);
		Sleep(250);
		spawnNote(map);
		Sleep(250);
		spawnNote(map);
		Sleep(400);
		spawnNote(map);
		Sleep(250);
		spawnNote(map);
		Sleep(350);
		spawnNote(map);
		Sleep(250);
		spawnNote(map);
		Sleep(250);
		spawnNote(map);
		Sleep(500);
		spawnNote(map);
		Sleep(250);
		spawnNote(map);
		Sleep(350);
		spawnNote(map);
		Sleep(250);
		spawnNote(map);
		Sleep(1500);

		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(1000);
		spawnNote(map);
		Sleep(1000);
		spawnNote(map);
		Sleep(1000);
		spawnLongNoteStart(map, &Long, 800);

		Sleep(5400);
		spawnNote(map);
		Sleep(750);
		spawnNote(map);
		Sleep(750);
		spawnNote(map);
		Sleep(750);
		spawnNote(map);
		Sleep(550);
		spawnNote(map);
		Sleep(550);
		spawnNote(map);
		Sleep(350);
		spawnNote(map);
		Sleep(350);
		spawnNote(map);
		Sleep(350);
		spawnLongNoteStart(map, &Long, 2000);
#pragma endregion
		Sleep(3500);
		PlaySound(NULL, 0, 0);
		break;


#pragma region 불새



	case 2: // 불새
	
		PlayMusic();
		Sleep(100);
		spawnNote(map); //소라가
		Sleep(850);
		spawnNote(map); //돈나
		Sleep(500);
		spawnNote(map);
		Sleep(1200);
		spawnNote(map); //다카
		Sleep(400);
		spawnNote(map);
		Sleep(1200);
		spawnNote(map); //쿠테모
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote(map); //하네가
		Sleep(1400);
		spawnNote(map);
		Sleep(1400);
		spawnNote(map); //치기레칫테모
		Sleep(1400);
		spawnNote(map);
		Sleep(400);
		spawnNote(map);
		Sleep(400);
		spawnNote(map);
		Sleep(800);
		spawnNote(map);
		Sleep(400);
		spawnNote(map);
		Sleep(400);
		spawnNote(map);
		Sleep(500);
		spawnNote(map);
		Sleep(1400);
		spawnNote(map); //토비타츠
		Sleep(800);
		spawnNote(map);
		Sleep(800);
		spawnNote(map);
		spawnNote(map); //코토
		Sleep(800);
		spawnNote(map); //오소
		Sleep(800);
		spawnNote(map); //오소
		Sleep(800);
		spawnNote(map); //레즈니
		Sleep(400);
		spawnNote(map);
		Sleep(400);
		spawnBigNote2(map);//코가세
	   //후시나루 키즈나 ~
		Sleep(1200);
		spawnNote(map);
		Sleep(800);
		spawnNote(map);
		Sleep(800);
		spawnNote(map);
		Sleep(800);
		spawnNote(map);
		Sleep(800);
		spawnNote(map);
		Sleep(800);
		spawnNote(map);
		Sleep(800);
		spawnNote(map);
		Sleep(800);
		spawnNote(map);
		Sleep(800);
		spawnNote(map);
		Sleep(800);
		spawnNote(map);
		Sleep(1000); //파이어
		spawnLongNoteStart(map, &Long, 5500); //바드 ~~~~~
		Sleep(4100);// 츠이에누 유메에 모에아가레
		spawnNote(map);
		Sleep(400);
		spawnNote(map);
		Sleep(400);
		spawnNote(map);
		Sleep(200); //파이어
		spawnNote(map);
		Sleep(200); //파이어
		spawnNote(map);
		Sleep(200); //파이어
		spawnNote(map);
		Sleep(200); // 버닝 업 ~
		spawnBigNote(map);
		Sleep(250);
		spawnBigNote(map);
		Sleep(250);
		spawnBigNote(map);
		Sleep(800);
		spawnNote(map);
		Sleep(150);
		spawnNote2(map);
		Sleep(150);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(150);
		spawnNote2(map);
		Sleep(150);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(150);
		spawnNote2(map);
		Sleep(150);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(150);
		spawnNote2(map);
		Sleep(150);
		spawnNote(map);
		Sleep(150);
		spawnBigNote(map);
		Sleep(250);
		spawnBigNote(map);
		Sleep(250);
		spawnBigNote(map);
		Sleep(600);
		spawnNote(map);
		Sleep(150);
		spawnNote2(map);
		Sleep(150);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(150);
		spawnNote2(map);
		Sleep(150);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(150);
		spawnNote2(map);
		Sleep(150);
		spawnNote(map);
		Sleep(200);
		spawnBigNote2(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		
		Sleep(200);
		spawnLongNoteStart(map, &Long, 900);
		spawnBigNote2(map);
		Sleep(400);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(400);
		spawnBigNote2(map);
		Sleep(1600);
		spawnBigNote2(map);
		Sleep(300);
		spawnBigNote2(map);
		Sleep(300);
		spawnBigNote2(map);
		Sleep(1000);
		spawnNote(map);
		Sleep(400);
		spawnNote(map);
		Sleep(400);
		spawnNote2(map);
		Sleep(400);
		spawnNote2(map);
		Sleep(400);
		spawnNote(map);
		Sleep(400);
		spawnNote(map);
		Sleep(400);
		spawnNote(map);
		Sleep(400);
		spawnNote2(map);
		Sleep(400);
		spawnNote2(map);
		Sleep(400);
		spawnNote(map);
		Sleep(400);
		spawnNote(map);
		Sleep(400);
		spawnNote(map);
		Sleep(400);
		spawnNote2(map);
		Sleep(400);
		spawnNote2(map);
		Sleep(400);
		spawnNote(map);
		Sleep(400);
		spawnNote(map);
		Sleep(400);
		spawnNote(map);
		Sleep(400);
		spawnNote2(map);
		Sleep(400);
		spawnNote2(map);
		Sleep(400);
		spawnNote(map);
		Sleep(400);
		spawnNote2(map);
		Sleep(400);
		spawnNote2(map);
		Sleep(400);
		spawnNote(map);
		Sleep(400);
		spawnNote2(map);
		Sleep(400);
		spawnBigNote(map);
		Sleep(1200);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnBigNote(map);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(400);
		spawnBigNote(map);
		Sleep(200);
		spawnBigNote(map);
		Sleep(200);
		spawnBigNote(map);
		Sleep(300);
		spawnBigNote2(map);
		Sleep(200);
		spawnBigNote2(map);
		Sleep(200);
		spawnBigNote2(map);
		Sleep(200);
		spawnLongNoteStart(map, &Long, 1500);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnLongNoteStart(map, &Long, 400);
		Sleep(200);
		spawnLongNoteStart(map, &Long, 500);
		Sleep(600);
		spawnBigNote(map);
		Sleep(300);
		spawnBigNote(map);
		Sleep(300);
		spawnBigNote(map);
		Sleep(300);
		spawnBigNote2(map);
		Sleep(300);
		spawnBigNote2(map);
		Sleep(300);
		spawnBigNote2(map);
		Sleep(800);
		spawnLongNoteStart(map, &Long, 700);
		Sleep(300);
		spawnBigNote(map);
		Sleep(300);
		spawnBigNote(map);
		Sleep(300);
		spawnBigNote(map);
		Sleep(300);
		spawnBigNote2(map);
		Sleep(300);
		spawnBigNote2(map);
		Sleep(300);
		spawnBigNote2(map);
		Sleep(600);
		spawnLongNoteStart(map, &Long, 700);
		Sleep(300);
		spawnBigNote(map);
		Sleep(300);
		spawnBigNote(map);
		Sleep(300);
		spawnBigNote(map);
		Sleep(300);
		spawnBigNote2(map);
		Sleep(300);
		spawnBigNote2(map);
		Sleep(300);
		spawnLongNoteStart(map, &Long, 1000);
		spawnNote(map);
		Sleep(150);
		spawnNote2(map);
		Sleep(150);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(150);
		spawnNote2(map);
		Sleep(150);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(150);
		spawnNote2(map);
		Sleep(150);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(150);
		spawnNote2(map);
		Sleep(150);
		spawnNote(map);
		Sleep(150);
		spawnBigNote(map);
		Sleep(250);
		spawnBigNote(map);
		Sleep(250);
		spawnBigNote(map);
		Sleep(800);
		spawnNote(map);
		Sleep(150);
		spawnNote2(map);
		Sleep(150);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(150);
		spawnNote2(map);
		Sleep(150);
		spawnNote(map);
		Sleep(200);
		spawnBigNote2(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnNote2(map);
		Sleep(200);
		spawnBigNote(map);
		Sleep(200);
		spawnBigNote(map);
		Sleep(200);
		spawnBigNote(map);



		break;

#pragma endregion

	case 3: //에쎕

		break;
	}

	Sleep(3700);
	PlaySound(TEXT(dogclear), NULL, SND_FILENAME | SND_ASYNC);
	system("cls");
	isEnd = 0;
	RESULT();
}




int  main() {
	CursorView();
	fullscreen();

	MaxScoreSetting(maxScoreList);
	while (1)
	{

		system("cls");
		combo = 0;
		score = 0;
		song = form(maxScoreList);

		Map();
		_beginthreadex(NULL, 0, Render, 0, 0, NULL);

		PlaySound(NULL, 0, 0);
		Sleep(4000);
		DropNote();
		isEnd = 1;
	}


	return 0;
}	

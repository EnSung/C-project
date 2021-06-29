#pragma once






/// <summary>
/// 풀스크린	
/// </summary>
void fullscreen();


/// <summary>
/// 커서 이동 함수
/// </summary>
/// <param name="x">x좌표</param>
/// <param name="y">y좌표</param>
void gotoxy(int x, int y);


/// <summary>
/// 맵 로딩
/// </summary>
void Map();

/// <summary>
/// 맵그리기
/// </summary>
void MapPrint(int* map);

/// <summary>
/// 한칸씩 아래로 내리기
/// </summary>
void Setting(int* Long, int* combo, int* map);


/// <summary>
/// 맵그리기
/// </summary>
void MapPrint(int* map);


/// <summary>
/// 최고점수 업뎃
/// </summary>
/// <param name="song"></param>
/// <param name="score"></param>
/// <param name="maxScoreList"></param>
void MaxScoreUpdate(int* song, int* score, char maxScoreList[][255]);



/// <summary>
/// 초반 최고점수 세팅
/// </summary>
/// <param name="maxScoreList"></param>
void MaxScoreSetting(char maxScoreList[][255]);



/// <summary>
/// F,J 노트 생성
/// </summary>
void spawnNote(int* map);


/// <summary>
/// D,K 노트 생성
/// </summary>
void spawnNote2(int* map);


/// <summary>
/// F,J 큰 노트 생성
/// </summary>
void spawnBigNote(int* map);

/// <summary>
/// D,K 큰 노트 생성
/// </summary>
void spawnBigNote2(int* map);

/// <summary>
/// 롱 노트 멈추기
/// </summary>
void spawnLongNotestop(int* Long);


/// <summary>
/// 롱노트 시작
/// </summary>
/// <param name="time">롱노트를 유지 할 시간</param>
void spawnLongNoteStart(int* map, int* Long, int time);

//커서가리기
void CursorView();


void how(int* count);

//픽
int form(char maxScoreList[][255]);

//메인메뉴
int inter_face();
int pick_m(int* count, int* count2, char Maxscore[][255]);

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

//void RESULT(int* score, int* cnt, int* maxcombo, int* song, char maxScoreList[][255]);
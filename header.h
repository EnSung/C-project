#pragma once






/// <summary>
/// Ǯ��ũ��	
/// </summary>
void fullscreen();


/// <summary>
/// Ŀ�� �̵� �Լ�
/// </summary>
/// <param name="x">x��ǥ</param>
/// <param name="y">y��ǥ</param>
void gotoxy(int x, int y);


/// <summary>
/// �� �ε�
/// </summary>
void Map();

/// <summary>
/// �ʱ׸���
/// </summary>
void MapPrint(int* map);

/// <summary>
/// ��ĭ�� �Ʒ��� ������
/// </summary>
void Setting(int* Long, int* combo, int* map);


/// <summary>
/// �ʱ׸���
/// </summary>
void MapPrint(int* map);


/// <summary>
/// �ְ����� ����
/// </summary>
/// <param name="song"></param>
/// <param name="score"></param>
/// <param name="maxScoreList"></param>
void MaxScoreUpdate(int* song, int* score, char maxScoreList[][255]);



/// <summary>
/// �ʹ� �ְ����� ����
/// </summary>
/// <param name="maxScoreList"></param>
void MaxScoreSetting(char maxScoreList[][255]);



/// <summary>
/// F,J ��Ʈ ����
/// </summary>
void spawnNote(int* map);


/// <summary>
/// D,K ��Ʈ ����
/// </summary>
void spawnNote2(int* map);


/// <summary>
/// F,J ū ��Ʈ ����
/// </summary>
void spawnBigNote(int* map);

/// <summary>
/// D,K ū ��Ʈ ����
/// </summary>
void spawnBigNote2(int* map);

/// <summary>
/// �� ��Ʈ ���߱�
/// </summary>
void spawnLongNotestop(int* Long);


/// <summary>
/// �ճ�Ʈ ����
/// </summary>
/// <param name="time">�ճ�Ʈ�� ���� �� �ð�</param>
void spawnLongNoteStart(int* map, int* Long, int time);

//Ŀ��������
void CursorView();


void how(int* count);

//��
int form(char maxScoreList[][255]);

//���θ޴�
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
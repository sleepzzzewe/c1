#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include "main.h"
int read(int* room, int* hp, int* money) {
	int ROOM, HP, MONEY;
	FILE* file;
	file = fopen("save.txt", "r");//�}��save.txt�åu��Ū��
	if (file != NULL) {
		while ((fscanf(file, "%d,%d,%d", &ROOM, &HP, &MONEY) == 3)) { //���\Ū��3���ܼƫ�^��3
			printf("�ж��G%d, HP�G%d, �����G%d\n", ROOM, HP, MONEY);
			*room = ROOM;
			*hp = HP;
			*money = MONEY;
		}
		fclose(file);
	}
	else {
		printf("�ɮ׶}�Ҥ����\");
	}
	Sleep(1000);
	printf("\033[2J\033[H");//�M���e��


	return 0;

}
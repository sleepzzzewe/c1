#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include "main.h"
int save(int* room, int* hp, int* money) {
	printf("�A�{�b�� �ж��G%d, hp�G%d, �����G%d ", *room, *hp, *money);
	FILE* file;
	file = fopen("save.txt", "w");//�}��save.txt�åu��g�J���л\
	if (file != NULL) {
		fprintf(file, "%d,%d,%d\n", *room, *hp, *money);//�g�J�ж��A��q�A����
		fclose(file);
	}
	else {
		printf("�ɮ׶}�Ҥ����\");
	}
	printf("�s�ɦ��\");
	Sleep(1000);
	printf("\033[2J\033[H");//�M���e��


	return 0;

}
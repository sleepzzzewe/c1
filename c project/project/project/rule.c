#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include "main.h"
int rule() {
	char rule;
	int continue1; //�P�_�O�_�~��
	FILE* file;
	file = fopen("rule.txt", "r");//�}��rule.txt�åu��Ū��
	if (file != NULL) {
		while (!feof(file)) { //�̧�Ū���A�����ɮק���
			rule = fgetc(file);
			putchar(rule);
		}
		fclose(file);
	}
	else {
		printf("�ɮ׶}�Ҥ����\");
	}
	printf("\n��J1�~��...");
	scanf("%d", &continue1);
	if (continue1 == 1) { //��J1�~��
		Sleep(1000);
		printf("\033[2J\033[H");//�M���e��
		return 0;
	}

}
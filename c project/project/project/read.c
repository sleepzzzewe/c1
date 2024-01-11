#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include "main.h"
int read(int* room, int* hp, int* money) {
	int ROOM, HP, MONEY;
	FILE* file;
	file = fopen("save.txt", "r");//開啟save.txt並只能讀取
	if (file != NULL) {
		while ((fscanf(file, "%d,%d,%d", &ROOM, &HP, &MONEY) == 3)) { //成功讀取3個變數後回傳3
			printf("房間：%d, HP：%d, 金錢：%d\n", ROOM, HP, MONEY);
			*room = ROOM;
			*hp = HP;
			*money = MONEY;
		}
		fclose(file);
	}
	else {
		printf("檔案開啟不成功");
	}
	Sleep(1000);
	printf("\033[2J\033[H");//清除畫面


	return 0;

}
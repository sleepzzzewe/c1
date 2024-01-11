#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include "main.h"
int rule() {
	char rule;
	int continue1; //判斷是否繼續
	FILE* file;
	file = fopen("rule.txt", "r");//開啟rule.txt並只能讀取
	if (file != NULL) {
		while (!feof(file)) { //依序讀取，直到檔案尾端
			rule = fgetc(file);
			putchar(rule);
		}
		fclose(file);
	}
	else {
		printf("檔案開啟不成功");
	}
	printf("\n輸入1繼續...");
	scanf("%d", &continue1);
	if (continue1 == 1) { //輸入1繼續
		Sleep(1000);
		printf("\033[2J\033[H");//清除畫面
		return 0;
	}

}
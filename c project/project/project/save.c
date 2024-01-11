#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include "main.h"
int save(int* room, int* hp, int* money) {
	printf("你現在的 房間：%d, hp：%d, 金錢：%d ", *room, *hp, *money);
	FILE* file;
	file = fopen("save.txt", "w");//開啟save.txt並只能寫入並覆蓋
	if (file != NULL) {
		fprintf(file, "%d,%d,%d\n", *room, *hp, *money);//寫入房間，血量，金錢
		fclose(file);
	}
	else {
		printf("檔案開啟不成功");
	}
	printf("存檔成功");
	Sleep(1000);
	printf("\033[2J\033[H");//清除畫面


	return 0;

}
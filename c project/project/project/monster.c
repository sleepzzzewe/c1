#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include "main.h"
int monster(int* room, int* hp, int* money) {    //怪物房
    char monsterName[20] = { 0 }, input[20] = { 0 };
    int amountTime;
    double limitTime = 5;
    for (int i = 0; i < 5; i++) //給予怪獸隨機名稱
    {
        monsterName[i] = 'a' + rand() % 26; //a~z的隨機亂數
    }

    printf("房間%d    HP：%d   Money：%d\n", *room, *hp, *money);
    printf("你遇到了一個怪獸，它的名字是%s。\n", monsterName);
    printf("請在5秒內輸入怪獸的名字：");

    time_t startTime, endTime; //宣告起始時間及結束時間
    time(&startTime); //開始的時間
    scanf("%s", &input);
    time(&endTime); //結束的時間

    amountTime = difftime(endTime, startTime); //兩個時間的差值
    int result = strcmp(input, monsterName); //確認字串是否相同

    if (amountTime > limitTime) { //時間超時
        printf("你沒有成功地打敗怪獸，你的生命值減少了10點，並且回到上一層\n");
        *hp -= 20; //hp-20
        Sleep(2000);
        printf("\033[2J\033[H");//清除畫面
    }
    else if (result == 0) { //字串與其名稱相同
        printf("你成功地打敗了怪獸，並前進到下一個房間。\n");
        *room += 1; //房間加1
        int getMoney = rand() % 20 + 1; //給予1~20的隨機金錢
        *money += getMoney; //增加金錢
        printf("你獲得了%d元", getMoney);
        Sleep(2000);
        printf("\033[2J\033[H");//清除畫面

    }
    else { //字串與其名稱不符
        printf("你沒有成功地打敗怪獸，你的生命值減少了20點，並且回到上一層\n");
        *hp -= 20; //hp-20
        Sleep(2000);
        printf("\033[2J\033[H");//清除畫面
    }
}

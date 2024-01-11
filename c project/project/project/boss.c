#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include "main.h"
int Boss(int* room, int* hp, int* money) {  //boss房
    const char* talk = "勇敢的騎士，恭喜你來到最後的關卡";
    for (int i = 0; talk[i] != '\0'; ++i) //每隔0.5秒依序顯示 "勇敢的騎士，恭喜你來到最後的關卡" 
    {
        printf("%c", talk[i]);
        Sleep(50);
    }
    printf("\033[2J\033[H");//清除畫面

    char bossName[20] = { 0 }, input[20] = { 0 };
    int amountTime;
    double limitTime = 5;
    int bossHP = 100;
    while (*hp > 0 && bossHP > 0) { //當hp > 0 及 bossHP > 0 繼續執行 繼續執行其while內容
        for (int i = 0; i < 5; i++) //給予a~z的隨機亂數
        {
            bossName[i] = 'a' + rand() % 26;
        }

        printf("房間%d    HP：%d   Money：%d\n", *room, *hp, *money);
        printf("這位魔王的名字是%s。魔王的血量：%d\n", bossName, bossHP);
        printf("請在5秒內輸入魔王的名字：");

        time_t startTime, endTime; //宣告起始時間即結束時間
        time(&startTime); //開始的時間
        scanf("%s", &input);
        time(&endTime); //結束的時間

        amountTime = difftime(endTime, startTime);//兩個時間的差值
        int result = strcmp(input, bossName);
        if (amountTime > limitTime) { //時間超時
            printf("魔王：就這點能耐嗎？\n 生命值減少了20點");
            *hp -= 20; //hp-20
            Sleep(2000);
            printf("\033[2J\033[H");//清除畫面
        }
        else if (result == 0) { //字串符合
            printf("你成功對魔王造成傷害了，魔王扣了20HP。\n");
            bossHP -= 20; //bossHP-20
            Sleep(2000);
            printf("\033[2J\033[H");//清除畫面

        }
        else { //字串不符合
            printf("魔王：就這點能耐嗎？\n 生命值減少了20點");
            *hp -= 20; //hp-20
            Sleep(2000);
            printf("\033[2J\033[H");//清除畫面
        }

        Sleep(2000);
        printf("\033[2J\033[H");//清除畫面

    }
    if (bossHP == 0) //成功通關
        printf("恭喜你通過了所有的房間，你贏了遊戲！\n");
    else if (*hp == 0) //血量耗盡
        printf("你的生命值已經耗盡，遊戲結束。\n");
}
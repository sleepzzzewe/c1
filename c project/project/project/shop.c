#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include "main.h"
int shop(int* room, int* hp, int* money) {  //商人房
    int input = 0;
    printf(("你遇到了商人地舖!!!"));
    Sleep(2000);
    printf("\033[2J\033[H");//清除畫面

    while (1) {
        printf("房間%d    HP：%d   Money：%d\n", *room, *hp, *money);
        printf("商人：今天想買些甚麼 ?\n");
        printf("| 1：藥水(+20hp) 20元 |\n 你想要購買(輸入0離開)：");
        scanf("%d", &input); //輸入1以購買藥水
        if (input == 0) { //離開房間
            printf("商人：謝謝光臨 ^^");
            Sleep(2000);
            printf("\033[2J\033[H");//清除畫面
            break;
        }
        printf("\033[2J\033[H");//清除畫面
        if (input == 1) { //成功購買
            if (*hp < 100 && *money >= 20) {
                printf("你購買了藥水，hp + 20");
                *hp += 20;
                *money -= 20;
                if (*hp > 100)*hp = 100;
            }
            else if (*money < 20) { //不夠錢
                printf("商人：帶夠錢再來吧，不要打擾我的生意");
            }
            else {  //hp已滿
                printf("你的HP已滿，無法購買");
            }
            Sleep(2000);
            printf("\033[2J\033[H");//清除畫面
        }
        else { //重新輸入
            printf("請重新輸入");
            Sleep(1500);
            printf("\033[2J\033[H");//清除畫面
        }

    }

}
#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include "main.h"
#define MAX_HP 100 //玩家血量
#define MAX_ROOMS 10 //最大房間數
#define limit_time 5 //輸入的限制時間
int main() {
    int hp = MAX_HP; //血量為100 
    int room = 1; //房間計數
    int money = 0; //金錢
    int enterRoom = 0; //進入左右的房間  左(1)右(2)
    while (hp > 0 && room < MAX_ROOMS) { //當hp > 0 及 room < 10 時 繼續執行其while內容
        printf("房間%d    HP：%d   Money：%d\n", room, hp, money);
        printf("請選擇走向左邊或右邊的房間\n 左(1) 右(2) 存檔(3) 讀檔(4) 規則(5) 離開遊戲(6) ：");
        scanf("%d",&enterRoom);
        Sleep(1000);
        printf("\033[2J\033[H");//清除畫面
        if (enterRoom == 1) { //進入一號房
           printf("你進入一號房\n");
           selectRoom(&room, &hp, &money);
        }
        else if (enterRoom == 2){ //進入二號房
           printf("你進入二號房\n");
           selectRoom(&room, &hp, &money);
        }
        else if (enterRoom == 3) { //存檔
            printf("是否確定存檔？確定(1)：");
            scanf("%d", &enterRoom);
            if (enterRoom == 1)
            {
                printf("\033[2J\033[H");//清除畫面
                save(&room, &hp, &money);
            }
            else {
                printf("\033[2J\033[H");//清除畫面
                continue;
            }
        }
        else if (enterRoom == 4) { //讀檔
            read(&room, &hp, &money);
        }
        else if (enterRoom == 5){ //規則
            rule();
        }
        else if (enterRoom == 6) {  //離開遊戲
            printf("離開遊戲中...");
            return 0;
        }
        
        
        else{ //重新輸入
           printf("請重新輸入");
           Sleep(1000);
           printf("\033[2J\033[H");//清除畫面
        }
    }

    if (room == 10) { //當room == 10時，進入boss房     
        Boss(&room, &hp, &money);
    }

    if (hp <= 0) { //血量耗盡
        printf("你的生命值已經耗盡，遊戲結束。\n");
    }

    return 0;
}
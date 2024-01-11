#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include "main.h"
int selectRoom(int* room, int* hp, int* money) {
    srand(time(NULL));
    int random = rand() % 3 + 1; //給予1~3的亂數
    if (random == 1) { //怪物房
        monster(room, hp, money);
    }
    else if (random == 2) { //商人房
        shop(room, hp, money);
    }
    else { //怪物房      
        monster(room, hp, money);
    }
}
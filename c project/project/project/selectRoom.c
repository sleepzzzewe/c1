#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include "main.h"
int selectRoom(int* room, int* hp, int* money) {
    srand(time(NULL));
    int random = rand() % 3 + 1; //����1~3���ü�
    if (random == 1) { //�Ǫ���
        monster(room, hp, money);
    }
    else if (random == 2) { //�ӤH��
        shop(room, hp, money);
    }
    else { //�Ǫ���      
        monster(room, hp, money);
    }
}
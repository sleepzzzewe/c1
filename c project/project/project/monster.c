#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include "main.h"
int monster(int* room, int* hp, int* money) {    //�Ǫ���
    char monsterName[20] = { 0 }, input[20] = { 0 };
    int amountTime;
    double limitTime = 5;
    for (int i = 0; i < 5; i++) //�������~�H���W��
    {
        monsterName[i] = 'a' + rand() % 26; //a~z���H���ü�
    }

    printf("�ж�%d    HP�G%d   Money�G%d\n", *room, *hp, *money);
    printf("�A�J��F�@�ө��~�A�����W�r�O%s�C\n", monsterName);
    printf("�Цb5����J���~���W�r�G");

    time_t startTime, endTime; //�ŧi�_�l�ɶ��ε����ɶ�
    time(&startTime); //�}�l���ɶ�
    scanf("%s", &input);
    time(&endTime); //�������ɶ�

    amountTime = difftime(endTime, startTime); //��Ӯɶ����t��
    int result = strcmp(input, monsterName); //�T�{�r��O�_�ۦP

    if (amountTime > limitTime) { //�ɶ��W��
        printf("�A�S�����\�a���ѩ��~�A�A���ͩR�ȴ�֤F10�I�A�åB�^��W�@�h\n");
        *hp -= 20; //hp-20
        Sleep(2000);
        printf("\033[2J\033[H");//�M���e��
    }
    else if (result == 0) { //�r��P��W�٬ۦP
        printf("�A���\�a���ѤF���~�A�ëe�i��U�@�өж��C\n");
        *room += 1; //�ж��[1
        int getMoney = rand() % 20 + 1; //����1~20���H������
        *money += getMoney; //�W�[����
        printf("�A��o�F%d��", getMoney);
        Sleep(2000);
        printf("\033[2J\033[H");//�M���e��

    }
    else { //�r��P��W�٤���
        printf("�A�S�����\�a���ѩ��~�A�A���ͩR�ȴ�֤F20�I�A�åB�^��W�@�h\n");
        *hp -= 20; //hp-20
        Sleep(2000);
        printf("\033[2J\033[H");//�M���e��
    }
}

#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include "main.h"
int Boss(int* room, int* hp, int* money) {  //boss��
    const char* talk = "�i�����M�h�A���ߧA�Ө�̫᪺���d";
    for (int i = 0; talk[i] != '\0'; ++i) //�C�j0.5��̧���� "�i�����M�h�A���ߧA�Ө�̫᪺���d" 
    {
        printf("%c", talk[i]);
        Sleep(50);
    }
    printf("\033[2J\033[H");//�M���e��

    char bossName[20] = { 0 }, input[20] = { 0 };
    int amountTime;
    double limitTime = 5;
    int bossHP = 100;
    while (*hp > 0 && bossHP > 0) { //��hp > 0 �� bossHP > 0 �~����� �~������while���e
        for (int i = 0; i < 5; i++) //����a~z���H���ü�
        {
            bossName[i] = 'a' + rand() % 26;
        }

        printf("�ж�%d    HP�G%d   Money�G%d\n", *room, *hp, *money);
        printf("�o���]�����W�r�O%s�C�]������q�G%d\n", bossName, bossHP);
        printf("�Цb5����J�]�����W�r�G");

        time_t startTime, endTime; //�ŧi�_�l�ɶ��Y�����ɶ�
        time(&startTime); //�}�l���ɶ�
        scanf("%s", &input);
        time(&endTime); //�������ɶ�

        amountTime = difftime(endTime, startTime);//��Ӯɶ����t��
        int result = strcmp(input, bossName);
        if (amountTime > limitTime) { //�ɶ��W��
            printf("�]���G�N�o�I��@�ܡH\n �ͩR�ȴ�֤F20�I");
            *hp -= 20; //hp-20
            Sleep(2000);
            printf("\033[2J\033[H");//�M���e��
        }
        else if (result == 0) { //�r��ŦX
            printf("�A���\���]���y���ˮ`�F�A�]�����F20HP�C\n");
            bossHP -= 20; //bossHP-20
            Sleep(2000);
            printf("\033[2J\033[H");//�M���e��

        }
        else { //�r�ꤣ�ŦX
            printf("�]���G�N�o�I��@�ܡH\n �ͩR�ȴ�֤F20�I");
            *hp -= 20; //hp-20
            Sleep(2000);
            printf("\033[2J\033[H");//�M���e��
        }

        Sleep(2000);
        printf("\033[2J\033[H");//�M���e��

    }
    if (bossHP == 0) //���\�q��
        printf("���ߧA�q�L�F�Ҧ����ж��A�AĹ�F�C���I\n");
    else if (*hp == 0) //��q�Ӻ�
        printf("�A���ͩR�Ȥw�g�ӺɡA�C�������C\n");
}
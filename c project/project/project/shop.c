#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include "main.h"
int shop(int* room, int* hp, int* money) {  //�ӤH��
    int input = 0;
    printf(("�A�J��F�ӤH�a�E!!!"));
    Sleep(2000);
    printf("\033[2J\033[H");//�M���e��

    while (1) {
        printf("�ж�%d    HP�G%d   Money�G%d\n", *room, *hp, *money);
        printf("�ӤH�G���ѷQ�R�Ǭƻ� ?\n");
        printf("| 1�G�Ĥ�(+20hp) 20�� |\n �A�Q�n�ʶR(��J0���})�G");
        scanf("%d", &input); //��J1�H�ʶR�Ĥ�
        if (input == 0) { //���}�ж�
            printf("�ӤH�G���¥��{ ^^");
            Sleep(2000);
            printf("\033[2J\033[H");//�M���e��
            break;
        }
        printf("\033[2J\033[H");//�M���e��
        if (input == 1) { //���\�ʶR
            if (*hp < 100 && *money >= 20) {
                printf("�A�ʶR�F�Ĥ��Ahp + 20");
                *hp += 20;
                *money -= 20;
                if (*hp > 100)*hp = 100;
            }
            else if (*money < 20) { //������
                printf("�ӤH�G�a�����A�ӧa�A���n���Z�ڪ��ͷN");
            }
            else {  //hp�w��
                printf("�A��HP�w���A�L�k�ʶR");
            }
            Sleep(2000);
            printf("\033[2J\033[H");//�M���e��
        }
        else { //���s��J
            printf("�Э��s��J");
            Sleep(1500);
            printf("\033[2J\033[H");//�M���e��
        }

    }

}
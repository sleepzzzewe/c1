#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include "main.h"
#define MAX_HP 100 //���a��q
#define MAX_ROOMS 10 //�̤j�ж���
#define limit_time 5 //��J������ɶ�
int main() {
    int hp = MAX_HP; //��q��100 
    int room = 1; //�ж��p��
    int money = 0; //����
    int enterRoom = 0; //�i�J���k���ж�  ��(1)�k(2)
    while (hp > 0 && room < MAX_ROOMS) { //��hp > 0 �� room < 10 �� �~������while���e
        printf("�ж�%d    HP�G%d   Money�G%d\n", room, hp, money);
        printf("�п�ܨ��V����Υk�䪺�ж�\n ��(1) �k(2) �s��(3) Ū��(4) �W�h(5) ���}�C��(6) �G");
        scanf("%d",&enterRoom);
        Sleep(1000);
        printf("\033[2J\033[H");//�M���e��
        if (enterRoom == 1) { //�i�J�@����
           printf("�A�i�J�@����\n");
           selectRoom(&room, &hp, &money);
        }
        else if (enterRoom == 2){ //�i�J�G����
           printf("�A�i�J�G����\n");
           selectRoom(&room, &hp, &money);
        }
        else if (enterRoom == 3) { //�s��
            printf("�O�_�T�w�s�ɡH�T�w(1)�G");
            scanf("%d", &enterRoom);
            if (enterRoom == 1)
            {
                printf("\033[2J\033[H");//�M���e��
                save(&room, &hp, &money);
            }
            else {
                printf("\033[2J\033[H");//�M���e��
                continue;
            }
        }
        else if (enterRoom == 4) { //Ū��
            read(&room, &hp, &money);
        }
        else if (enterRoom == 5){ //�W�h
            rule();
        }
        else if (enterRoom == 6) {  //���}�C��
            printf("���}�C����...");
            return 0;
        }
        
        
        else{ //���s��J
           printf("�Э��s��J");
           Sleep(1000);
           printf("\033[2J\033[H");//�M���e��
        }
    }

    if (room == 10) { //��room == 10�ɡA�i�Jboss��     
        Boss(&room, &hp, &money);
    }

    if (hp <= 0) { //��q�Ӻ�
        printf("�A���ͩR�Ȥw�g�ӺɡA�C�������C\n");
    }

    return 0;
}
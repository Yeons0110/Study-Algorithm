#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

long totalday(int y, int m, int d);

int main(){

        int sy, sm, sd, fy, fm, fd, dates;
        printf("ù��° �� ���� �Է� \n");
        printf("���� 1998 8 23  : ");
        scanf("%d %d %d", &fy, &fm, &fd);
        printf("�ι�° �� ���� �Է� \n");
        printf("���� 1998 8 23  : ");
        scanf("%d %d %d", &sy, &sm, &sd);

        dates = totalday(sy, sm, sd) - totalday(fy, fm, fd);

        printf("\n\n%d�� %d�� %d�� �� \n", fy, fm, fd);

        printf("%d�� %d�� %d�� ������ \n", sy, sm, sd);

        printf("�� ��¥ �� : %ld��\n", dates);

        return 0;

}

long totalday(int y, int m, int d){

        int months[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

        int i;

        long total = 0L;
        total = (y - 1) * 365L + (y - 1) / 4 - (y - 1) / 100 + (y - 1) / 400;

        if (!(y % 4) && y % 100 || !(y % 400))
                 months[1]++;
        for (i = 0; i < m - 1; i++)
                 total += months[i];
        total += d;
        return total; //������� ��� +1�� ���ش�.

}
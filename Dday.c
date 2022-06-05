#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

long totalday(int y, int m, int d);

int main(){

        int sy, sm, sd, fy, fm, fd, dates;
        printf("첫번째 년 월일 입력 \n");
        printf("형식 1998 8 23  : ");
        scanf("%d %d %d", &fy, &fm, &fd);
        printf("두번째 년 월일 입력 \n");
        printf("형식 1998 8 23  : ");
        scanf("%d %d %d", &sy, &sm, &sd);

        dates = totalday(sy, sm, sd) - totalday(fy, fm, fd);

        printf("\n\n%d년 %d월 %d일 과 \n", fy, fm, fd);

        printf("%d년 %d월 %d일 사이의 \n", sy, sm, sd);

        printf("총 날짜 수 : %ld일\n", dates);

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
        return total; //기념일일 경우 +1일 해준다.

}
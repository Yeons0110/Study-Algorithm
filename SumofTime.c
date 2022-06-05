// 배열에 대해서 알아보고자 합니다.
// C언어에서는 Java와는 달리 변수를 배열의 길이에 오지 못하게 제한되어 있습니다. 
// 그렇기 때문에 C언어에서는 동적 배열을 생성할때는 malloc함수를 활용하여 동적 메모리를 할당하는 방법을 써야 합니다.

//메모리의 동적 할당이란?
/* "메모리를 동적 할당한다"라는 뜻은 컴퓨터 프로그램이 실행되는 도중인 런타임 도중에 사용할 메모리 공간을 할당하는 것을 말합니다. 동적 할당되는 메모리는 힙 영역에 생성되게 되며 컴파일 타임에 메모리의 크기가 결정되는 데이터 영역이나 스택 영역의 정적 메모리 할당과는 대조적인 개념입니다.*/
// malloc 함수를 사용하기 위해서는 malloc 함수가 포함되어 있는 <stdlib.h> 헤더나 <malloc.h> 헤더를 포함시켜야 합니다.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  int count = 0;
  int A = 0, B = 0;
  //int time[3];
  scanf("%d\n", &count); //왜 숫자를 받지?
  
  int* time = (int*)malloc(sizeof(int) * count); //동적으로 생성하는 법

  for (int j = 0; j < count; j++)
  {
    scanf("%d %d", &A, &B); //AB값은 왜 받지?
    time[j] = (A + B) % 24; //왜 더해서 나누지?
  }

  for (int q = 0; q < count; q++)
  {
    printf("#%d %d\n", q + 1, time[q]);
  }
  return 0;
}
#include <stdio.h>
#include <string.h>

int main()
{
  int num = 3;
  int A[3], B[3];

  for (int i = 0; i < num; i++)
  {
    scanf("%d %d", &A[i], &B[i]);
  }

  for (int i = 0; i < num; i++)
  {
    printf("#%d ", i + 1);

    if (A[i] > B[i])
      printf("A");

    else if (A[i] < B[i])
      printf("B");

    else if (A[i] == B[i])
    {
      printf("Equal");
    }

    printf("\n");
  }

  return 0;
}
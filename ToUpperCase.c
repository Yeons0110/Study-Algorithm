#include <stdio.h>
#include <string.h>

int main()
{
  char str[81];//문자열을 담는 것인가?

  scanf("%s", str); //왜 입력을 받지?

  for (int i = 0; i < strlen(str); i++)//길이동안 반복을 하면서
  {
    if (str[i] >= 'a' && str[i] <= 'z')//아 소문자를 대문자로 바꿔주는 함수이구나.
      str[i] -= 32;
  }

  printf("%s", str);
  return 0;
}
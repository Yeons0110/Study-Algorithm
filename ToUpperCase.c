#include <stdio.h>
#include <string.h>

int main()
{
  char str[81];//���ڿ��� ��� ���ΰ�?

  scanf("%s", str); //�� �Է��� ����?

  for (int i = 0; i < strlen(str); i++)//���̵��� �ݺ��� �ϸ鼭
  {
    if (str[i] >= 'a' && str[i] <= 'z')//�� �ҹ��ڸ� �빮�ڷ� �ٲ��ִ� �Լ��̱���.
      str[i] -= 32;
  }

  printf("%s", str);
  return 0;
}
/***********************************************************************/
/*               HW#1 : 트리를 사용한 정렬 알고리즘 구현                 */
/*  작성자 : 김성연                             날짜 : 2021년 10월 23일  */
/*                                                                     */
/* 문제 정의 : 이진탐색트리를 이용하여 txt의 값들을 삽입하고 찾는 기능 구현*/
/*                - - - - - - -                                        */
/* 기능 : 왼쪽 노드, 오른쪽 노드를 이용하여 트리를 만들고, 탐색노드 구현   */
/*        추가고려 사항은 터미널에 "chcp 65001"을 명령하여 한글이 보이도록 함    */
/*        gcc로 실행함                                                   */
/*                - - - - - - -                                         */
/***********************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int key;
  struct node *left;
  struct node *right;
} Node;

int insert(Node *head, int key) //트리 삽입 함수
{
  Node *insertNode = (Node *)malloc(sizeof(Node));
  insertNode->key = key; //받은 키 값을 대입
  insertNode->left = NULL;
  insertNode->right = NULL;

  if (head->left == NULL) //처음 넣을 때 비어있으니 첫 값 삽입
  {
    head->left = insertNode;
    return 1;
  }

  Node *ptr = head->left;  //left 값을 표현하기 쉽게 함
  Node *parentNode = NULL; //알맞는 트리 삽입을 위하여 부모 노드를 이용함

  while (ptr != NULL) //왼쪽 노드가 비어있지 않다면 반복
  {
    if (ptr->key == key)
      return 1;

    parentNode = ptr; //ptr을 부모노드로 두고

    if (ptr->key < key) //키 값을 비교하여 작으면 왼쪽, 크면 오른쪽으로 뻗어감
      ptr = ptr->right;
    else
      ptr = ptr->left;
  }

  if (parentNode->key > key) //값을 비교하여 왼쪽 또는 오른쪽에 위치함
    parentNode->left = insertNode;
  else
    parentNode->right = insertNode;
  return 1;
}

int findNode(Node *head, int key) //탐색 함수
{

  if (head == NULL) //비어있을 시 반환
  {
    printf("\n 비어있습니다.\n");
    return -1;
  }

  if (head->left == NULL) //비어있을 시 반환
  {
    printf("\n 비어있습니다.\n");
    return -1;
  }

  Node *root = head->left;

  Node *parent = NULL;
  Node *ptr = root;

  while ((ptr != NULL) && (ptr->key != key))
  {
    if (ptr->key != key) //찾는 키값이 나올 때까지 노드를 탐색함
    {
      parent = ptr;

      if (ptr->key > key) //부모 노드와 값을 비교하여 뻗어나감
        ptr = ptr->left;
      else
        ptr = ptr->right;
    }
  }

  if (ptr == NULL) //찾는 값이 없다면
  {
    printf("파일 내 [%d]값이 존재하지 않습니다.\n ", key);
    return -1; //반환
  }
  //찾는 값이 있다면
  printf("파일 내 [%d]값이 존재합니다.\n ", key);
  return 0; //반환
}

int main(void)
{
  int number;
  Node *head = (Node *)malloc(sizeof(Node));
  head->left = NULL;
  head->right = NULL;
  head->key = -9999;

  printf("test.txt 파일을 이진탐색트리로 만들었습니다.\n");

  FILE *pFile = fopen("input.txt", "r"); //read mode
  int intTemp = -1;

  if (pFile == NULL)
  {
    printf("파일이 존재하지 않습니다.");
    return 0;
  }

  // 파일 읽기 성공
  while (fscanf(pFile, "%d", &intTemp) != EOF)
  {
    if (intTemp < 0)
      break;
    // 트리생성
    insert(head, intTemp); //파일 안의 값을 트리에 삽입합니다.
    printf("%d ", intTemp);

    // 생성된 트리에서 키 검색
  }
  printf("\n");

  while (1)
  {
    printf("찾고 싶은 값을 입력해주세요(그만 찾고 싶으시다면 -1을 눌러주세요) : ");
    do //입력받은 수가 정수가 아닐 시에 예외처리
    {
      int num = scanf("%d", &number);

      if (num == 1) //정수를 입력받으면 1이 되는 성질을 이용
      {
        break;
      }
      else
      {
        printf("정수가 아닙니다. 다시 입력하세요 : "); //문자열 입력시 예외처리
        while (getchar() != '\n')
        {
        }
      }

    } while (1);

    if (number == -1)
      break;
    findNode(head, number);
  }
  //파일 형태로 반환

  fclose(pFile); //close file
  return 0;
}
#include <iostream>
#include <string>

using namespace std;

int main()
{
  int dx[4] = {0, 0, -1, 1};
  int dy[4] = {-1, 1, 0, 0};
  char moveTypes[4] = {'L', 'R', 'U', 'D'};
  int size;
  int x = 1, y = 1;
  string input;

  cin >> size;
  cin.ignore();        // 버퍼 비우고
  getline(cin, input); // \n 포함해서 입력 받고

  for (int i = 0; i < input.size(); i++)
  {
    char plan = input[i];
    int nx = 0, ny = 0;
    for (int j = 0; j < 4; j++)
    {
      if (moveTypes[j] == plan)
      {
        nx = x + dx[j];
        ny = y + dy[j];
      }
    }

    if (nx < 1 || ny < 1 || nx > size || ny > size) // map 을 벗어나서 움직이려고 하는 경우
    {
      continue;
    }
    else
    {
      x = nx;
      y = ny;
    }
  }

  cout << x << " " << y;

  return 0;
}
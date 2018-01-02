#include <bits/stdc++.h>
using namespace std;

int m[3][3];

int main()
{
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++)
      m[i][j] = i * j;

  for(int i = 0; i < 3; i++)
  {
    for(int j = 0; j < 3; j++)
    {
      printf(" %d", m[i][j]);
    }
    printf("\n");
  }
  for(int i = 0; i < 3; i++)
    memset(m[i], 0, sizeof(m[i]));

  for(int i = 0; i < 3; i++)
  {
    for(int j = 0; j < 3; j++)
    {
      printf(" %d", m[i][j]);
    }
    printf("\n");
  }
  return 0;
}

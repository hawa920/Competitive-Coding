/*
 *
 *  Nothing but implementation of matrix multiplications,
 *  Fast power -> O(lgN),
 *  use bitwise & to decide whether to time by pow(base, 2^k),
 *
 *  Example:
 *    X^5 = X^(b101) = X * (X^4);
 *
 *
 * */

#include <bits/stdc++.h>
using namespace std;

typedef long long lld;
int n, p, a, b, c, i, j;


int fastmatrix()
{
  int times = n - 3, bit = 1;

  if(times <= 0)
    return 1;

  lld base[3][3] = {{a, b, c}, {1, 0, 0}, {0, 1, 0}}, ret[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}, temp[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

  while(bit > 0)
  {
    if((times & bit) > 0)
    {
      for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
          temp[i][j] = ((ret[i][0] * base[0][j]) % p + (ret[i][1] * base[1][j]) % p + (ret[i][2] * base[2][j]) % p) % p;

      for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
          ret[i][j] = temp[i][j];
    }
    bit <<= 1; // till it overflows
    for(i = 0; i < 3; i++)
      for(j = 0; j < 3; j++)
        temp[i][j] = ((base[i][0] * base[0][j]) % p + (base[i][1] * base[1][j]) % p + (base[i][2] * base[2][j]) % p) % p;

    for(i = 0; i < 3; i++)
      for(j = 0; j < 3; j++)
        base[i][j] = temp[i][j];

  }
  return (int)((ret[0][0] + ret[0][1] + ret[0][2]) % p);
}


int main()
{
  while(scanf("%d%d%d%d%d", &n, &p, &a, &b, &c) != EOF)
  {
    printf("%d\n", fastmatrix());
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
lld n, p, a, b, c;


lld fibonacci()
{

  n -= 3;
  if(n < 1)
    return 1;

  lld base[3][3] = {{a, b, c}, {1, 0, 0}, {0, 1, 0}}, ret[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}, temp[3][3], bit = 1;

  while(bit > 0)
  {
    if(bit & n)
    {
      for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
          temp[i][j] = ret[i][j];

      for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
        {
          ret[i][j] = 0;
          for(int k = 0; k < 3; k++)
            ret[i][j] = (ret[i][j] + temp[i][k] * base[k][j]) % p;
        }
    }

    bit <<= 1;

    for(int i = 0; i < 3; i++)
      for(int j = 0; j < 3; j++)
        temp[i][j] = base[i][j];

    for(int i = 0; i < 3; i++)
      for(int j = 0; j < 3; j++)
      {
        base[i][j] = 0;
        for(int k = 0; k < 3; k++)
          base[i][j] = (base[i][j] + temp[i][k] * temp[k][j]) % p;
      }

  }
  return (ret[0][0] + ret[0][1] + ret[0][2]) % p;
}


int main()
{
  while(scanf("%lld%lld%lld%lld%lld", &n, &p, &a, &b, &c) != EOF)
  {
    printf("%lld\n", fibonacci());
  }
  return 0;
}

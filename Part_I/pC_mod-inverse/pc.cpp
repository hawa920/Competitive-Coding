/*
 *
 *  Modulor Inverse
 *  Formula: X^(p-2) % p, where p is necessary to be a prime
 *
 * */


#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
int p, len, i, j;
char n[1024];
lld ret;

int fastmod(lld x, lld t)
{
  int bit = 1;
  lld ret = 1;
  while(bit > 0)
  {
    if((t & bit) > 0)
      ret = (ret * x) % p;
    bit <<= 1;
    x = (x * x) % p;
  }
  return (int) ret;
}


int main()
{
  while(scanf("%s%d", n, &p) != EOF)
  {
    ret = 0;
    len = (int) strlen(n);
    for(i = 0; i < len; i++)
      ret = (ret * 10 + (n[i] - '0')) % p;
    printf("%d\n", fastmod(ret, p - 2));
  }
  return 0;
}

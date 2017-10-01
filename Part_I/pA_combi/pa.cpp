/*
 *
 *
 *  Fast Power Calculating -> O(lgN),
 *  Using bitwise & to decide whether to time by pow(base, 2^k)
 *
 *  X^5 = X^(b101) = X * (X^4)
 *
 * */


#include <bits/stdc++.h>
using namespace std;
typedef long long lld;

int n, k, p, m, i, j;
lld ret;

int fastmod(lld x, lld t)
{
  lld rvl = 1;
  int bit = 1;
  while(bit > 0) // till it overflows
  {
    if((t & bit) > 0)
      rvl = (rvl * x) % p;
    bit <<= 1;
    x = (x * x) % p;
  }
  return rvl;
}

int main()
{
  while(scanf("%d%d%d", &n, &k, &p) != EOF)
  {
    ret = 1;
    m = n - (k > (n - k) ? k : (n - k));
    k = k > (n - k) ? (n - k) : k;
    for(i = 0; i < m; i++)
      ret = (ret * (n - i)) % p;
    for(i = 2; i <= k; i++)
      ret = (ret * fastmod(i, p-2)) % p;

    printf("%lld\n", ret);
  }
}

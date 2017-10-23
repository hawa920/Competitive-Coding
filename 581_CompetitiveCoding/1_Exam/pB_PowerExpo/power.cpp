#include <bits/stdc++.h>
using namespace std;
typedef long long lld;

lld p;
char x[256], n[256];


lld powerExpo()
{
  lld xlen = (lld) strlen(x), nlen = (lld) strlen(n), xmodp = 0, nmodp = 0;
  for(int i = 0; i < (int) xlen; i++)
  {
    xmodp = (xmodp * 10 + (x[i] - '0')) % p;
  }

  for(int i = 0; i < (int) nlen; i++)
  {
    nmodp = (nmodp * 10 + (n[i] - '0')) % (p - 1);
  }

  // fast-multi
  lld bit = 1, xx = xmodp, nn = nmodp, ret = 1; // ret = xx^nn %p
  while(bit > 0) // till it overflows
  {
    if(bit & nn)
    {
      ret = (ret * xx) % p;
    }

    bit <<= 1;
    xx = (xx * xx) % p;
  }
  return ret;
}



int main()
{
  while(scanf("%s%s%lld", x, n, &p) != EOF)
  {
    printf("%lld\n", powerExpo());
  }
  return 0;
}

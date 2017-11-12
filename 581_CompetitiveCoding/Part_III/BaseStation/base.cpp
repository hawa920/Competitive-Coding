#include <bits/stdc++.h>
using namespace std;


int t, n, k, l, r, i, j, x, sp[50009];


bool valid(int len, int num)
{
  for(i = 0, j = 0; i < n && j < num; j++)
  {
    int bnd = sp[i] + len;
    while(i < n && sp[i] <= bnd)
      i++;
  }
  return i == n ? 1 : 0;
}



int main()
{
  scanf("%d", &t);
  while(t--)
  {
    scanf("%d%d", &n, &k);
    // 初始化
    for(i = 0; i < n; i++)
      scanf("%d", &sp[i]);

    sort(&sp[0], &sp[0] + n);
    l = 0;
    r = ceil((sp[n - 1] - sp[0]) / k);
    while(r > l)
    {
      if(valid((r + l) / 2, k))
        r = (r + l) / 2;
      else
        l = (r + l) / 2 + 1;
    }
    printf("%d\n", l);
  }
  return 0;
}

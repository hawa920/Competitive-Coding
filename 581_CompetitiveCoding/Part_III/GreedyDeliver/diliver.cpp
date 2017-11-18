#include <bits/stdc++.h>
using namespace std;


int main()
{
  int t, n, ppl[1024], ret, temp;
  ppl[0] = 0;
  scanf("%d", &t);
  while(t--)
  {
    ret = temp = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
      scanf("%d", &ppl[i]);
    sort(&ppl[1], &ppl[1] + n);

    for(int i = 0, j = 1; i < n and j <= n; i++, j++)
    {
      temp += ppl[i] + ppl[j];
      ret += temp;
    }
    printf("%d\n", ret);
  }
  return 0;
}

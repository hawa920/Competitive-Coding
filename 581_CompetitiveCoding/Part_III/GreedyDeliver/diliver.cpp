#include <bits/stdc++.h>
using namespace std;


int main()
{
  int t, n, ppl[1024], ret, temp;
  ppl[0] = 0; // 為了方便計算
  scanf("%d", &t);
  while(t--)
  {
    ret = temp = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) // 為了方便計算從1開始
      scanf("%d", &ppl[i]);
    sort(&ppl[1], &ppl[1] + n);

    for(int i = 0, j = 1; i < n and j <= n; i++, j++) //j是第j個人, i是第j個人前面的一個人
    {
      temp += ppl[i] + ppl[j]; //累計時間
      ret += temp; // 累加每個人的時間
    }
    printf("%d\n", ret);
  }
  return 0;
}

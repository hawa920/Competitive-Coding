#include <bits/stdc++.h>
using namespace std;


int t, n, k, l, r, i, j, x, sp[50009];


bool valid(int len, int num)
{
  for(i = 0, j = 0; i < n && j < num; j++)
  {
    int bnd = sp[i] + len; // 第j個基地台的服務範圍
    while(i < n && sp[i] <= bnd) // 在這個範圍內表示可以服務,就繼續往下
      i++;
  }
  return i == n ? 1 : 0; // 如果 i==n 代表每個基地台都包含了
}



int main()
{
  scanf("%d", &t);
  while(t--)
  {
    scanf("%d%d", &n, &k); // n個需要被服務的點, k個基地台, 求最小直徑
    // 初始化
    for(i = 0; i < n; i++)
      scanf("%d", &sp[i]); // sp 紀錄著每個服務點的x座標

    sort(&sp[0], &sp[0] + n); // 將這些服務點按照x座標排序
    l = 0;
    r = ceil((sp[n - 1] - sp[0]) / k); // 保證r目前長度絕對可以包含每個點
    while(r > l) // 二分搜
    {
      if(valid((r + l) / 2, k)) // valid() 判斷在長度為 len 的情況下, 基地台有 num 個能否覆蓋每個基地台
        r = (r + l) / 2; // 如果可以就往內縮
      else
        l = (r + l) / 2 + 1; // 不可以就讓l往外並且+1
    }
    printf("%d\n", l);
  }
  return 0;
}

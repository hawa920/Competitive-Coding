#include <bits/stdc++.h>
using namespace std;

int t, n, u, v, w, i, j, dp[100009], oo = 1e9+7, l, m, r;
vector<pair<int, pair<int,int>>> x;

int main()
{
  scanf("%d", &t);
  while(t--)
  {
    x.clear();
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
      scanf("%d%d%d", &u, &v, &w);
      x.push_back({v, {u, w}}); // 把結束時間放前面
      dp[i] = -oo; // 初始化, dp[i] 考慮選或不選第i個行程所能獲得的最大值
    }
    // 依照結束時間遞增排序
    sort(x.begin(), x.end());
    dp[0] = x.at(0).second.second; // 初始化

    for(i = 1; i < n; i++)
    {
      // 往前找第一個可以接的點
      l = 0; r = i - 1;
      while(r > l)
      {
        m = (r + l) / 2;
        if(x.at(i).second.first >= x.at(m).first)
          l = 1 + m;
        else
          r = m;
      }
      // 上面的二分搜會找到一個大於等於該活動開始時間的最小結束時間, 所以底下要往回找
      for(j = r; j >= 0; j--)
        if(x.at(j).first <= x.at(i).second.first)
          break;

      dp[i] = j == -1 ? max(dp[i - 1], x.at(i).second.second) : max(dp[i - 1], x.at(i).second.second + dp[j]);
    }
    printf("%d\n", dp[n - 1]);
  }
  return 0;
}

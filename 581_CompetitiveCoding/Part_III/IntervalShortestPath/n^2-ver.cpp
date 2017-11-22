/* Version O(n^2) */
#include <bits/stdc++.h>
using namespace std;


vector<pair<int, pair<int,int>>> arr;
int t, n, u, v, w, d[100009], oo = 1e7+9, i;

int main()
{
  scanf("%d", &t);
  while(t--)
  {
    arr.clear();
    for(i = 0; i < 100009; i++)
      d[i] = oo;
    d[0] = 0; // 初始化起點

    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
      scanf("%d%d%d", &u, &v, &w);
      arr.push_back({u, {v, w}});
    }
    sort(arr.begin(), arr.end());
    // d[i] 紀錄著到包含 i 為止所需要的最小weight
    for(const auto &x : arr)
    {
      u = x.first;
      v = x.second.first;
      w = x.second.second;
      for(i = u; i < v; i++)
        d[v] = d[v] > d[i] + w ? d[i] + w : d[v];
    }
    for(i = 100008; i >= 0 && d[i] == oo; i--)
      ;
    printf("%d\n", d[i]);
  }
}

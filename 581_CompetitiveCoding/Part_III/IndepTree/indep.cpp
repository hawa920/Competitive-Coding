#include <bits/stdc++.h>
using namespace std;

struct dt_pt
{
  int w, liss;
};

int t, n, r1, s, r, ret;
struct dt_pt pts[1009];
vector<int> adj[1009];

void dfs(int root)
{
  if(adj[root].size() == 0)
  {
    pts[root].liss = pts[root].w;
    return;
  }

  int idx, inc = 0, exc = 0;
  for(idx = 0; idx < adj[root].size(); idx++)
    dfs(adj[root].at(idx));
  for(const auto &x : adj[root])
    for(const auto &y : adj[x])
      inc += pts[y].liss;
  for(const auto &x : adj[root])
    exc += pts[x].liss;
  pts[root].liss = max(pts[root].w + inc, exc);
}


int main()
{
  scanf("%d", &t);
  while(t--)
  {
    // 初始化
    ret = 0;
    for(int i = 0; i < 1009; i++)
    {
      adj[i].clear();
      pts[i] = {0, 0};
    }

    // 建立階層表
    scanf("%d%d", &n, &r1);
    pts[1] = {r1, 0};
    for(int i = 2; i <= n; i++)
    {
      scanf("%d%d", &s, &r);
      pts[i] = {r, 0};
      adj[s].push_back(i);
    }
    dfs(1);
    for(int i = 1; i <= n; i++)
      ret = max(ret, pts[i].liss);
    printf("%d\n", ret);
  }
  return 0;
}

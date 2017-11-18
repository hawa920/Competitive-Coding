#include <bits/stdc++.h>
using namespace std;


struct zzz
{
  int pt, h1, h2, h, idx;
};


int t, n, ret, pa[100009];
vector<int> adj[100009];
stack<zzz> dfs;


int main()
{
  int u, v, root, reth;
  scanf("%d", &t);
  while(t--)
  {
    ret = 0;
    scanf("%d", &n);
    // 初始化 adjancy list
    for(int i = 0; i < n; i++)
    {
      adj[i].clear();
      pa[i] = i;
    }

    // 建立當前的 adjancy list
    for(int i = 1; i < n; i++)
    {
      scanf("%d%d", &u, &v);
      pa[v] = u;
      adj[u].push_back(v);
    }

    // 找出 root
    for(int i = 0; i < n; i++)
    {
      if(pa[i] == i)
      {
        root = i;
        break;
      }
    }

    dfs.push({root, 0, 0, 0, 0});

    while(not dfs.empty())
    {
      if(dfs.top().idx == adj[dfs.top().pt].size())
      {
        ret = max(ret, dfs.top().h1 + dfs.top().h2);
        reth = dfs.top().h1 + 1;
        dfs.pop();

        if(dfs.empty())
          break;

        if(reth > dfs.top().h1)
        {
          int temp = dfs.top().h1;
          dfs.top().h1 = reth;
          dfs.top().h2 = temp;
        }
        else if(reth > dfs.top().h2)
        {
          dfs.top().h2 = reth;
        }
      }

      else
        dfs.push({adj[dfs.top().pt].at(dfs.top().idx++), 0, 0, 0, 0});
    }
    printf("%d\n", ret);
  }
}

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
    // 初始化 adjancy list以及 parent list
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
      if(dfs.top().idx == adj[dfs.top().pt].size()) // 如果這個點已經traverse完畢, 就代表要準備pop了
      {
        ret = max(ret, dfs.top().h1 + dfs.top().h2); // pop之前看看全域ret 有沒有比h1+h2小, 有的話就更新
        reth = dfs.top().h1 + 1; // reth 是會return當前要pop這個點比較大的那個邊長
        dfs.pop(); // pop掉stack頂

        if(dfs.empty()) // 如果已經空了那就break
          break;

        if(reth > dfs.top().h1) // 比較剛剛reth與現在top的h1, h2的關係
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

      else // 如果還有點沒traverse, 把該點加進stack就繼續, 這裡在模仿系統的stack的方式
        dfs.push({adj[dfs.top().pt].at(dfs.top().idx++), 0, 0, 0, 0});
    }
    printf("%d\n", ret);
  }
}

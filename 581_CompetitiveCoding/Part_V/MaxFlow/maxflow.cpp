#include <bits/stdc++.h>
using namespace std;

typedef long long lld;
int t, nv, ne, u, v, w, p[512];
lld rgraph[512][512], ret;
bool ifvisit[512];


bool bfs(int s, int t)
{
  queue<int> q;
  memset(&p[0], 0, sizeof(p));
  memset(&ifvisit[0], 0, sizeof(ifvisit));
  q.push(s);
  p[s] = s;
  while(not q.empty())
  {
    int temp = q.front();
    q.pop();
    if(ifvisit[temp])
      continue;
    ifvisit[temp] = true;
    for(int i = 0; i < nv; i++)
    {
      // 注意這裡的第二個判對, 不可省略
      if(rgraph[temp][i] > 0 and not ifvisit[i])
      {
        q.push(i);
        p[i] = temp;
        if(i == t)
          break;
      }
    }
  }
  return ifvisit[t];
}

int main()
{
  scanf("%d", &t);
  while(t--)
  {
    ret = 0;
    scanf("%d%d", &nv, &ne);
    for(int i = 0; i < 512; i++)
      memset(rgraph[i], 0, sizeof(rgraph[i]));

    for(int i = 0; i < ne; i++)
    {
      scanf("%d%d%d", &u, &v, &w);
      rgraph[u][v] = w;
    }
    while(bfs(0, nv - 1))
    {
      lld bneck = 1e9 + 7;
      int s = 0, t = nv - 1;
      for(int i = t; i != s; i = p[i])
        bneck = min(bneck, rgraph[p[i]][i]);
      for(int i = t; i != s; i = p[i])
        rgraph[p[i]][i] -= bneck, rgraph[i][p[i]] += bneck;
      ret += bneck;
    }
    printf("%lld\n", ret);
  }
  return 0;
}

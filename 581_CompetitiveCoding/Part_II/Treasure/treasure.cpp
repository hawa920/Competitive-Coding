#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long lld;


lld maxTreasure(int n, int m, int t)
{
  int a, b, w[n], cur;
  lld ret;
  bool ifvisit[n];
  stack<int> pile;
  vector<int> start, adjlist[n];

  for(int i = 0; i < t; i++)
  {
    scanf("%d", &a);
    start.pb(a);
  }

  for(int i = 0; i < n; i++)
  {
    scanf("%d", &w[i]);
    ifvisit[i] = false;
  }

  for(int i = 0; i < m; i++)
  {
    scanf("%d%d", &a, &b);
    adjlist[a].pb(b);
  }

  ret = -1;
  for(auto const & i : start)
  {
    if(ifvisit[i])
      continue;

    ifvisit[i] = true;
    pile.push(i);

    while(not pile.empty())
    {
      cur = pile.top();
      ret = w[cur] > ret ? w[cur] : ret;
      pile.pop();

      for(auto const & j : adjlist[cur])
      {
        if(not ifvisit[j])
        {
          ifvisit[j] = true;
          pile.push(j);
        }
      }
    }
  }
  return ret;
}


int main()
{
  int n, m, t;
  while(true)
  {
    scanf("%d%d%d", &n, &m, &t);

    if(n + m + t == 0)
      return 0;

    printf("%lld\n", maxTreasure(n, m, t));
  }
  return 0;
}

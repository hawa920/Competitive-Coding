#include <bits/stdc++.h>
using namespace std;
#define pb push_back


int max_component()
{
  int nv, ne, a, b, sum, cur_v, ret;
  scanf("%d%d", &nv, &ne);
  int w[nv];
  bool ifvisit[nv];
  stack<int> pile;
  vector<int> adjlist[nv];

  for(int i = 0; i < nv; i++)
  {
    scanf("%d", &w[i]);
    ifvisit[i] = false;
  }

  for(int i = 0; i < ne; i++)
  {
    scanf("%d%d", &a, &b);
    adjlist[a].pb(b);
    adjlist[b].pb(a);
  }

  ret = -1;
  for(int i = 0; i < nv; i++)
  {
    if(ifvisit[i])
      continue;

    ifvisit[i] = true;
    sum = w[i];
    pile.push(i);
    while(not pile.empty())
    {
      cur_v = pile.top();
      pile.pop();

      for(const auto & j : adjlist[cur_v])
      {
        if(not ifvisit[j])
        {
          ifvisit[j] = true;
          pile.push(j);
          sum += w[j];
        }
      }
    }
    ret = sum > ret ? sum : ret;
  }
  return ret;
}


int main()
{
  int nc;
  scanf("%d", &nc);
  while(nc--)
  {
    printf("%d\n", max_component());
  }

  return 0;
}

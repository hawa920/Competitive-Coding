#include <bits/stdc++.h>
using namespace std;

int t, nv, ne, nq, u, v, w, s, d;
bool neg[5009];
long long dist[5009];
const int inf = 1e9 + 7;
vector<pair<int,int>> adjlist[5009];


void BellmanFord(int s)
{
  for(int i = 0; i < nv; i++)
  {
    neg[i] = false;
    dist[i]= inf;
  }
  dist[s] = 0;

  // BellmamFord Algorithm
  for(int i = 0; i < nv + 2; i++)
  {
    // Travse ne edges O(e)
    for(int j = 0; j < nv; j++)
    {
      if(adjlist[j].empty())
        continue;

      for(const auto &x : adjlist[j])
      {
        if(dist[j] != inf and dist[x.first] > dist[j] + x.second)
        {
          dist[x.first] = dist[j] + x.second;
          neg[x.first] = i >= nv ? 1 : neg[x.first];
        }
      }
    }
  }
}
int main()
{
  scanf("%d", &t);
  while(t--)
  {
    scanf("%d%d%d", &nv, &ne, &nq);
    for(int i = 0; i < nv; i++)
    {
      adjlist[i].clear();
    }
    for(int i = 0; i < ne; i++)
    {
      scanf("%d%d%d", &u, &v, &w);
      adjlist[u].push_back({v, w});
    }
    for(int i = 0; i < nq; i++)
    {
      scanf("%d%d", &s, &d);
      BellmanFord(s);
      if(dist[d] == inf or neg[d])
      {
        printf("No\n");
      }
      else
      {
        printf("%lld\n", dist[d]);
      }
    }
  }
  return 0;
}

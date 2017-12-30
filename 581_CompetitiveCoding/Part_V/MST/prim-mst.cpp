/*
 *  # Minimum Spanning Tree Algorithm
 *  Two main difference about Dijkstra & Prim's Algorithm are that,
 *    1. Dijkstra selects the nearest point to the starting point at each round, while Prim selects the nearest point to the graph
 *    2. Dijkstra considers about the path so the relax function's like dist[v] = dist[u] + w, while Prim consider only dist[v] = w
 * */

#include <bits/stdc++.h>
using namespace std;

typedef long long lld;
int t, nv, ne, u, v, w;
lld ret, dist[10009];
bool ifvisit[10009];
vector<pair<lld, lld> > adj[10009];
priority_queue<pair<lld, lld>, vector<pair<lld, lld> >, greater<pair<lld, lld> > >minheap;


int main()
{
  scanf("%d", &t);
  while(t--)
  {
    scanf("%d%d", &nv, &ne);
    ret = 0;
    for(int i = 0; i < nv; i++)
    {
      adj[i].clear();
      ifvisit[i] = false;
      dist[i] = 1e9 + 7;
    }
    for(int i = 0; i < ne; i++)
    {
      scanf("%d%d%d", &u, &v, &w);
      adj[u].push_back({v, w});
      adj[v].push_back({u, w});
    }
    minheap.push({0, 0});
    while(not minheap.empty())
    {
      pair<lld, lld> temp = minheap.top();
      minheap.pop();
      if(ifvisit[temp.second])
        continue;
      ifvisit[temp.second] = true;
      ret += temp.first;
      for(const auto &x : adj[temp.second])
      {
        if(not ifvisit[x.first] and dist[x.first] > x.second)
        {
          dist[x.first] = x.second;
          minheap.push({dist[x.first], x.first});
        }
      }
    }
    cout << ret << endl;
  }
  return 0;
}

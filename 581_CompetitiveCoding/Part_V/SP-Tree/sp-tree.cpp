#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ds_edge;
int t, nv, ne, nq, sp, u, v, w, inf = 1e9 + 7, p[10009];
bool ifvisit[10009];
long long ret, dist[10009];
vector<ds_edge> adjlist[10009];
priority_queue<ds_edge, vector<ds_edge>, greater<ds_edge>> minheap;


void dijkstra(int s)
{
  while(not minheap.empty())
    minheap.pop();

  for(int i = 0; i < nv; i++)
    dist[i] = inf, p[i] = -1, ifvisit[i] = false;
  dist[s] = 0;
  p[s] = s;

  minheap.push({0, s});
  while(not minheap.empty())
  {
    ds_edge temp = minheap.top();
    minheap.pop();
    if(ifvisit[temp.second])
      continue;

    ifvisit[temp.second] = true;
    for(const auto &x : adjlist[temp.second])
    {
      if(dist[x.first] >= dist[temp.second] + x.second)
      {
        dist[x.first] = dist[temp.second] + x.second;
        minheap.push({dist[x.first], x.first});
        if(p[x.first] == -1)
        {
          p[x.first] = temp.second;
        }
        else
        {
          p[x.first] = dist[p[x.first]] > dist[temp.second] ? p[x.first] : temp.second;
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
    for(int i = 0; i< nv; i++)
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
      ret = 0;
      scanf("%d", &sp);
      dijkstra(sp);
      bool flag = 0;
      for(int i = 0; i < nv; i++)
      {
        if(dist[i] == inf)
        {
          flag = 1;
          break;
        }
        ret += dist[i];
        if(p[i] == -1)
          continue;
        ret -= dist[p[i]];
      }
      if(not flag)
        cout << ret << endl;
      else
        cout << "No\n";
    }
  }
}

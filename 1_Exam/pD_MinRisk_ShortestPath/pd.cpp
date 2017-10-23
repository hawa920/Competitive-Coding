#include <bits/stdc++.h>
using namespace std;
typedef long long lld;

const int MAXVERTEX = 30009;
lld nv, ne, u, v, r, w, minimax_risk, shortest_path;

struct dt_adjlist
{
  lld dest, risk, weight;
};

vector<dt_adjlist> adjlist[MAXVERTEX];
lld minrisk[MAXVERTEX];
lld mindist[MAXVERTEX];
bool ifvisit[MAXVERTEX];


priority_queue<pair<lld,lld>, vector<pair<lld,lld>>, greater<pair<lld,lld>>> riskminheap;
priority_queue<pair<lld,lld>, vector<pair<lld,lld>>, greater<pair<lld,lld>>> pathminheap;


void init()
{
  for(int idx_i = 0; idx_i < MAXVERTEX; idx_i++)
  {
    adjlist[idx_i].clear();
  }

  scanf("%lld%lld", &nv, &ne);
  for(int idx_i = 0; idx_i < ne; idx_i++)
  {
    scanf("%lld%lld%lld%lld", &u, &v, &r, &w);
    adjlist[u].push_back({v, r, w});
  }
}


void findminimax_risk()
{
  pair<lld,lld> topele;
  for(int idx_i = 0; idx_i < MAXVERTEX; idx_i++)
  {
    minrisk[idx_i] = INT_MAX; // init value
    ifvisit[idx_i] = 0;
  }
  minrisk[0] = 0;
  riskminheap.push({0, 0}); // mini-max risk, vertex
  while(not riskminheap.empty())
  {
    topele = riskminheap.top();
    riskminheap.pop();
    if(ifvisit[topele.second])
      continue;

    ifvisit[topele.second] = true;

    for(const auto & idx_i : adjlist[topele.second])
    {
      if(minrisk[idx_i.dest] > max(minrisk[topele.second], idx_i.risk))
      {
        minrisk[idx_i.dest] = max(minrisk[topele.second], idx_i.risk);
        riskminheap.push({minrisk[idx_i.dest], idx_i.dest});
      }
    }
  }
  minimax_risk = minrisk[nv - 1];
}


void findshortest_path()
{
  pair<lld,lld> topele;
  for(int idx_i = 0; idx_i < MAXVERTEX; idx_i++)
  {
    mindist[idx_i] = INT_MAX;
    ifvisit[idx_i] = false;
  }

  mindist[0] = 0;
  pathminheap.push({0, 0}); // mini-distant, vertex;
  while(not pathminheap.empty())
  {
    topele = pathminheap.top();
    pathminheap.pop();
    if(ifvisit[topele.second])
      continue;

    ifvisit[topele.second] = true;

    for(const auto & idx_i : adjlist[topele.second])
    {
      if(idx_i.risk > minimax_risk)
        continue;

      if(mindist[idx_i.dest] > mindist[topele.second] + idx_i.weight)
      {
        mindist[idx_i.dest] = mindist[topele.second] + idx_i.weight;
        pathminheap.push({mindist[idx_i.dest], idx_i.dest});
      }
    }
  }
  shortest_path = mindist[nv - 1];
}



int main()
{

  int times;
  scanf("%d", &times);
  while(times--)
  {
    init();
    findminimax_risk();
    findshortest_path();
    if(minimax_risk == INT_MAX)
      printf("-1\n");
    else
      printf("%lld %lld\n", minimax_risk, shortest_path);
  }
  return 0;
}

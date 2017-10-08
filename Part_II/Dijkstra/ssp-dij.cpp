#include <bits/stdc++.h>


#define SPT 0
#define MVS 10009
#define xx  first
#define yy  second
#define pb  push_back
#define mp  make_pair


using namespace std;


typedef long long ll;
typedef pair<ll, ll> llp;
typedef vector<llp> llpv;
typedef priority_queue<llp, llpv, greater<llp> > llppq;


ll u, v, w, nv, ne, dist[MVS];
llpv adjlist[MVS];
llppq minheap;
bool ifvisit[MVS];


void init()
{
  scanf("%lld%lld", &nv, &ne);
  for(int idx_i = 0; idx_i < ne; idx_i++)
  {
    scanf("%lld%lld%lld", &u, &v, &w);
    adjlist[u].pb(mp(v, w));
    adjlist[v].pb(mp(u, w));
  }


  for(int idx_i = 0; idx_i < nv; idx_i++)
  {
    dist[idx_i] = INT_MAX;
    ifvisit[idx_i] = false;
  }

  dist[SPT] = 0;
}


void dijkstra()
{
  llp nextv;
  minheap.push(mp(0, SPT));
  while(not minheap.empty())
  {
    nextv = minheap.top();

    if(ifvisit[nextv.yy] == true)
    {
      minheap.pop();
      continue;
    }

    ifvisit[nextv.yy] = true;
    minheap.pop();

    for(llpv::iterator idx_i = adjlist[nextv.yy].begin(); idx_i != adjlist[nextv.yy].end(); idx_i++)
    {
      if(dist[(*idx_i).xx] > nextv.xx + (*idx_i).yy)
      {
        dist[(*idx_i).xx] = nextv.xx + (*idx_i).yy;
        minheap.push(mp(dist[(*idx_i).xx], (*idx_i).xx));
      }
    }
  }
}


void findmax()
{
  ll temp = dist[0];
  for(int idx_i = 0; idx_i < nv; idx_i++)
    temp = temp < dist[idx_i] ? dist[idx_i] : temp;
  printf("%lld\n", temp);
}


int main()
{
  init();
  dijkstra();
  findmax();
  return 0;
}

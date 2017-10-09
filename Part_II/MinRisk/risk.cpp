#include <bits/stdc++.h>
using namespace std;


#define pb push_back
#define mp make_pair
#define xx first
#define yy second


typedef pair<int, int> iip;
typedef vector<pair<int, int> > iipv;
typedef priority_queue<iip, iipv, greater<iip> > iippq;


int minRisk()
{
  int nv, ne, u, v, w, ret;
  scanf("%d%d", &nv, &ne);
  int risk[nv];
  iip nextv;
  iipv adjlist[nv];
  bool ifvisit[nv];
  iippq minheap;

  for(int i = 0; i < ne; i++)
  {
    scanf("%d%d%d", &u, &v, &w);
    adjlist[u].pb(mp(v, w));
  }

  for(int i = 0; i < nv; i++)
  {
    ifvisit[i] = false;
    risk[i] = INT_MAX;
  }

  risk[0] = 0;

  minheap.push(mp(0, 0));

  while(not minheap.empty())
  {
    nextv = minheap.top();
    minheap.pop();

    if(ifvisit[nextv.yy])
      continue;

    ifvisit[nextv.yy] = true;

    /* find mini max, it's pretty tricky... */
    for(const auto & i : adjlist[nextv.yy])
    {
      if(risk[i.xx] > max(risk[nextv.yy], i.yy))
      {
        risk[i.xx] = max(risk[nextv.yy], i.yy);
        minheap.push(mp(risk[i.xx], i.xx));
      }
    }
  }
  return risk[nv -1] == INT_MAX ? -1 : risk[nv - 1];
}


int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
  {
    printf("%d\n", minRisk());
  }
  return 0;
}

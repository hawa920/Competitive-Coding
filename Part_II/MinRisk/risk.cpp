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
  int rrisk[nv];
  iip nextv;
  iipv adjlist[nv];
  bool ifvisit[nv];
  iippq minheap;
  vector<int> temp;

  for(int i = 0; i < ne; i++)
  {
    scanf("%d%d%d", &u, &v, &w);
    adjlist[u].pb(mp(v, -w));
  }

  for(int i = 0; i < nv; i++)
  {
    ifvisit[i] = false;
    rrisk[i] = INT_MAX;
  }

  rrisk[0] = 0;

  minheap.push(mp(0, 0));

  while(not minheap.empty())
  {
    nextv = minheap.top();
    minheap.pop();

    if(ifvisit[nextv.yy])
      continue;

    ifvisit[nextv.yy] = true;

    for(const auto & i : adjlist[nextv.yy])
    {
      if(rrisk[i.xx] > i.yy)
      {
        rrisk[i.xx] = i.yy;
        minheap.push(mp(i.yy, i.xx));
      }

      if(i.xx == nv - 1)
      {
        temp.pb(i.yy);
      }
    }
  }
  if(temp.size() == 0)
    return -1;

  ret = temp.at(0);

  for(auto const & i : temp)
    ret = i > ret ? i : ret;

  return -ret;
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

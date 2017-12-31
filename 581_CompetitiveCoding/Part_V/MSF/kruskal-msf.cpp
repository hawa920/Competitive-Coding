#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int> edge;
int t, nv, ne, ntree, p[10009], u, v, w, ret;
priority_queue<edge, vector<edge>, greater<edge>> minheap;

int myfind(int x)
{
  return x == p[x] ? x : myfind(p[x]);
}

void myunion(int x, int y)
{
  p[myfind(x)] = myfind(y);
}

int main()
{
  scanf("%d", &t);
  while(t--)
  {
    ret = 0;
    while(not minheap.empty())
    {
      minheap.pop();
    }
    scanf("%d%d%d", &nv, &ne, &ntree);
    for(int i = 0; i < nv; i++)
    {
      p[i] = i;
    }
    for(int i = 0; i < ne; i++)
    {
      scanf("%d%d%d", &u, &v, &w);
      minheap.push(make_tuple(w, u, v));
    }
    ntree = nv - ntree;
    while(not minheap.empty() and ntree)
    {
      tie(w, u, v) = minheap.top();
      minheap.pop();
      if(myfind(u) != myfind(v))
      {
        ntree--;
        ret += w;
        myunion(u, v);
      }
    }
    cout << ret << endl;
  }
  return 0;
}

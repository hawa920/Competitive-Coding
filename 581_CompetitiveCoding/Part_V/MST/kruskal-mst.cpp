#include <bits/stdc++.h>
using namespace std;
struct ds_edge
{
  int u, v, w;
};
int t, nv, ne, u, v, w, p[10009];
long long ret;
vector<ds_edge> edge;
bool mycompare(ds_edge x, ds_edge y)
{
  return x.w < y.w;
}
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
    scanf("%d%d", &nv, &ne);
    ret = 0;
    edge.clear();
    for(int i = 0; i < nv; i++)
    {
      p[i] = i;
    }
    for(int i = 0; i < ne; i++)
    {
      scanf("%d%d%d", &u, &v, &w);
      edge.push_back({u, v, w});
    }
    sort(edge.begin(), edge.end(), mycompare);
    for(const auto &x : edge)
    {
      if(myfind(x.u) != myfind(x.v))
      {
        ret += x.w;
        myunion(x.u, x.v);
      }
    }
    cout << ret << endl;
  }
  return 0;
}

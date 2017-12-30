/*
 * 有雷！
 *
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
int t, nv, ne, u, v, w, inf = 1e9 + 7, idx, m[1024][1024]; // m 這個 2d-matriｘ 不能是 long long 不然會 TLE
lld sum, temp; // temp 跟 sum 一定要 long long 不然會 WA


int main()
{
  scanf("%d", &t);
  while(t--)
  {
    scanf("%d%d", &nv, &ne);
    for(int i = 0; i < nv; i++)
    {
      for(int j = 0; j < nv; j++)
      {
        m[i][j] = i == j ? 0 : inf;
      }
    }
    for(int i = 0; i < ne; i++)
    {
      scanf("%d%d%d", &u, &v, &w);
      m[u][v] = w;
    }
    sum = inf;
    for(int k = 0; k < nv; k++)
    {
      for(int i = 0; i < nv; i++)
      {
        temp = 0;
        for(int j = 0; j < nv; j++)
        {
          m[i][j] = min(m[i][j], m[i][k] + m[k][j]);
          temp += m[i][j];
        }
        if(temp < sum)
        {
          sum = temp;
          idx = i;
        }
      }
    }
    cout << idx << endl;
  }
  return 0;
}

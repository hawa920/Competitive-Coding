#include <bits/stdc++.h>
using namespace std;


const int MAX = 500009;
int n, l, temp[MAX], rmax, rmin;


struct dt_segtree
{
  int lbnd, rbnd, maxi, mini;
} segtree[4 * MAX];


void build(int l, int r, int idx)
{

  segtree[idx].lbnd = l;
  segtree[idx].rbnd = r;

  if(l == r)
  {
    segtree[idx].maxi = segtree[idx].mini = temp[l];
    return;
  }

  build(l, (r + l) / 2, idx << 1); // left recursion
  build((r + l) / 2 + 1, r, idx << 1 | 1); // right recursion

  segtree[idx].maxi = max(segtree[idx << 1].maxi, segtree[idx << 1 | 1].maxi);
  segtree[idx].mini = min(segtree[idx << 1].mini, segtree[idx << 1 | 1].mini);
}


void search(int l, int r, int idx)
{
  if(segtree[idx].lbnd > r or segtree[idx].rbnd < l)
    return;

  if(segtree[idx].lbnd >= l and segtree[idx].rbnd <= r)
  {
    rmax = max(rmax, segtree[idx].maxi);
    rmin = min(rmin, segtree[idx].mini);
    return;
  }
  search(l, r, idx << 1);
  search(l, r, idx << 1 | 1);
}


int maxdiff()
{
  for(int i = 1; i <= n; i++)
  {
    scanf("%d", &temp[i]);
  }

  build(1, n, 1);

  int ret = 0;

  for(int i = 1; i <= n - l + 1; i++)
  {
    rmax = -INT_MAX;
    rmin = INT_MAX;
    search(i, i + l - 1, 1);
    ret = ret > rmax - rmin ? ret : rmax - rmin;
  }
  return ret;
}


int main()
{
  while(true)
  {
    scanf("%d%d", &n, &l);
    if(n == 0 and l == 0)
      break;
    printf("%d\n", maxdiff());
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;



typedef struct segNode
{
  int l, r, maxi;
} segNode;


int orgarr[150009], sortarr[150009], t, n, cur, ofst, low, up, rmax, ret;
segNode segTree[600036];


void buildSegTree(int l, int r, int idx)
{
  segTree[idx].l = l;
  segTree[idx].r = r;

  if(l == r)
  {
    segTree[idx].maxi = 0;
    return;
  }

  int m = (l + r) / 2;
  buildSegTree(l, m, idx << 1);
  buildSegTree(m + 1, r, idx << 1 | 1);
  segTree[idx].maxi = 0;
  //segTree[idx].maxi = max(segTree[idx << 1].maxi, segTree[idx << 1 | 1].maxi);
}


void searchSegTree(int l, int r, int idx)
{
  if(r == 0)
  {
    rmax = 0;
    return;
  }
  if(segTree[idx].l > r or segTree[idx].r < l)
    return;

  if(segTree[idx].l >= l and segTree[idx].r <= r)
  {
    rmax = max(rmax, segTree[idx].maxi);
    return;
  }
  searchSegTree(l, r, idx << 1);
  searchSegTree(l, r, idx << 1 | 1);
}


void updateSegTree(int idx, int ofst, int val)
{
  if(segTree[idx].l > ofst or segTree[idx].r < ofst)
    return;


  segTree[idx].maxi = max(segTree[idx].maxi, val);
  if(segTree[idx].l == segTree[idx].r)
    return;

  updateSegTree(idx << 1, ofst, val);
  updateSegTree(idx << 1 | 1, ofst, val);
}


int main(int argc, char **argv)
{
  scanf("%d", &t);
  while(t--)
  {
    ret = 1;
    scanf("%d", &n);
    for(int i = 1; i <=  n; i++)
    {
      scanf("%d", &orgarr[i]);
      sortarr[i] = orgarr[i];
    }
    sort(&sortarr[1], &sortarr[1] + n);

    buildSegTree(1, n, 1); // 建線段樹

    for(int i = 1; i <= n; i++)
    {
      cur = orgarr[i];
      low = 1;
      up = n;
      // 二分搜
      while(low != up)
      {
        if(cur > sortarr[(low + up) / 2])
          low = (low + up) / 2 + 1;
        else
          up = (low + up) / 2;
      }

      ofst = low;
      rmax = -INT_MAX;
      searchSegTree(1, ofst - 1, 1);
      ret = max(rmax + 1, ret);
      if(rmax != -INT_MAX)
        updateSegTree(1, ofst, rmax + 1);
    }
    printf("%d\n", ret);
  }

  return 0;
}

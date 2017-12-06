#include <bits/stdc++.h>
using namespace std;

#define MAX 120009

struct ds_rect
{
  int w, l, r, f;
};


struct segN
{
  int l, r, thick, len;
} seg[MAX * 8];


int t, n, X1, X2, Y1, Y2;
long long ans; // 坑!
vector<ds_rect> rect;

bool cmp(struct ds_rect a, struct ds_rect b)
{
  return a.w < b.w;
}

void pushup(int idx)
{
  if(seg[idx].thick > 0)
    seg[idx].len = seg[idx].r - seg[idx].l;
  else if(seg[idx].l == seg[idx].r)
    seg[idx].len = 0;
  else
    seg[idx].len = seg[idx<<1].len + seg[idx<<1|1].len;
}



void update(int l, int r, int val, int idx)
{
  if(seg[idx].l > r or seg[idx].r <= l) // 現在是左包右不包, 所以要 <=
    return;

  if(seg[idx].l == l and seg[idx].r == r)
  {
    seg[idx].thick += val;
    pushup(idx);
    return;
  }

  int m = (seg[idx].l + seg[idx].r) / 2;
  if(m > r) // doubt here
    update(l, r, val, idx<<1);
  else if(m <= l)
    update(l, r, val, idx<<1|1);
  else
  {
    update(l, m, val, idx<<1);
    update(m, r, val, idx<<1|1);
  }
  pushup(idx);

}



void build(int l, int r, int idx)
{
  seg[idx].l = l;
  seg[idx].r = r;
  seg[idx].thick = 0;
  seg[idx].len = 0;
  if(r - l == 1)
    return;
  int m = (l + r) / 2;
  build(l, m, idx<<1);
  build(m, r, idx<<1|1);
}


int main()
{
  scanf("%d", &t);
  while(t--)
  {
    // 初始化
    ans = 0;
    rect.clear();
    build(0, 120001, 1);

    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
      scanf("%d%d%d%d", &X1, &Y1, &X2, &Y2);
      // validation 坑人處 PART 1
      if(X1 > X2)
        swap(X1, X2);
      if(Y1 > Y2)
        swap(Y1, Y2);
      rect.push_back({X1, Y1, Y2, 1});
      rect.push_back({X2, Y1, Y2, -1});
    }
    sort(rect.begin(), rect.end(), cmp);

    // 演算
    for(int i = 0; i < rect.size() - 1; i++)
    {
      update(rect[i].l, rect[i].r, rect[i].f, 1);
      ans += (rect[i + 1].w - rect[i].w) * seg[1].len;
    }
    cout << ans << endl;

  }


  return 0;
}


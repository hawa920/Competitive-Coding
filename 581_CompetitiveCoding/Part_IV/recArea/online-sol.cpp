#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX 30000
#define LL idx*2
#define RR idx*2+1

struct segment
{
  int l,r,h;
  int f;

} ss[2*MAX];

struct node
{
  int l,r;
  int cover;
  int len;
} tt[2*MAX*4];


int pos[2*MAX];
int nums;

int cmp(struct segment a ,struct segment b)
{
  return a.h < b.h;
}

void build(int a, int b ,int idx)
{
  tt[idx].l = a;
  tt[idx].r = b;
  tt[idx].cover = 0;
  tt[idx].len = 0;
  if(a == b)
    return ;

  int mid = (tt[idx].l+tt[idx].r)/2;
  build(a,mid,LL);
  build(mid+1,b,RR);
}

int binary(int key ,int low, int high)
{
  while(low <= high)
  {
    int mid = (low+high)>>1;
    if(pos[mid] == key)
      return mid;
    else if(key < pos[mid])
      high = mid-1;
    else
      low = mid+1;
  }
  return -1;
}

void pushup(int idx)
{
  if(tt[idx].cover)
    tt[idx].len = pos[tt[idx].r+1] - pos[tt[idx].l];
  else if(tt[idx].l == tt[idx].r)
    tt[idx].len = 0;
  else
    tt[idx].len = tt[LL].len + tt[RR].len ;
}

void update(int a, int b ,int val ,int idx)
{
  if(a>tt[idx].r or b < tt[idx].l)
    return;
  if(tt[idx].l==a && tt[idx].r==b)
  {
    tt[idx].cover += val;
    pushup(idx);
    return ;
  }
  int mid = (tt[idx].l+tt[idx].r)/2;
  if(b <= mid)
    update(a,b,val,LL);
  else if(a > mid)
    update(a,b,val,RR);
  else
  {
    update(a,mid,val,LL);
    update(mid+1,b,val,RR);
  }
  pushup(idx);
}

int main()
{
  int Case = 0;
  int t;
  int n;
  int x1, y1, x2, y2;
  scanf("%d", &t);

  while(t--)
  {
    scanf("%d", &n);
    nums=0;
    for(int i = 0; i < n; i++)
    {
      scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
      if(x1 > x2)
        swap(x1, x2);
      if(y1 > y2)
        swap(y1, y2);
      ss[nums].l = x1;
      ss[nums].r = x2;
      ss[nums].h = y1;
      ss[nums].f = 1;
      ss[nums+1].l = x1;
      ss[nums+1].r = x2;
      ss[nums+1].h = y2;
      ss[nums+1].f = -1;
      pos[nums] = x1;
      pos[nums+1] = x2;
      nums += 2;
    }
    sort(ss,ss+nums,cmp);
    sort(pos,pos+nums);
    int m = 1;
    for(int i = 1; i < nums; i++)
      if(pos[i] != pos[i-1])
        pos[m++] = pos[i];

    build(0, m-1, 1);
    long long ans = 0;
    for(int i = 0; i < nums - 1; i++)
    {
      int l = binary(ss[i].l,0,m-1);
      int r = binary(ss[i].r,0,m-1)-1;
      update(l,r,ss[i].f,1);
      ans += (ss[i+1].h-ss[i].h)*tt[1].len;
    }
    printf("%lld\n", ans);
  }
  return 0;
}

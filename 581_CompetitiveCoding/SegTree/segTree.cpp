#include <bits/stdc++.h>
using namespace std;

// 資料數上限
const int MAX = 10000;
int global_temp;

// 題目給的初始資料, 依題目設計做調整
int arr[MAX];


// 規劃樹節點
struct segNode
{
  // 假設要找最大值, 根據需求做調整
  int l, r, maxi;
};

// 宣告四倍大小的陣列表示一棵平衡樹
segNode segTree[MAX << 2]; // 最好 << 3 比較保險


// 建立線段樹
void build(int l, int r, int idx)
{
  segTree[idx].l = l;
  segTree[idx].r = r;

  if(l == r) // 如果是左閉右開 if(r-1 == 1)
  {
    // 這裡 arr 是用來初始化的資料, 根據需求做調整
    segTree[idx].maxi = arr[l]; /*= arr[r]*/
    return;
  }

  int mid = (l + r) / 2;
  build(l, mid, idx << 1);
  build(mid + 1, r, idx << 1 | 1); // 如果是左閉右開 build(mid, r, idx<<1|1);

  // 假設要找最大值, 根據需求做調整
  segTree[idx].maxi = max(segTree[idx<<1].maxi, segTree[idx<<1|1].maxi);
}

void Query(int l, int r, int idx)
{
  // l 與 r 是要查詢的區間

  // 判斷當下區間是否為無效區間
  if(l > segTree[idx].r or r < segTree[idx].l) // 如果是左閉右開 seg[idx].r <= l
    return;

  // 判斷是否為有效區間
  if(segTree[idx].l >= l and segTree[idx].r <= r)
  {
    // 這裡要有一個 global 來紀錄遞迴找到的結果
    global_temp = max(global_temp, segTree[idx].maxi);
    return;
  }
  // 如果這個區間是跨區間, 就分開找
  query(l, r, idx<<1);
  query(l, r, idx<<1|1);
}


// 單點修改
void spUpdate(int idx, int ofst, int val)
{
  // idx 為線段樹的起點 index
  // ofst 為修改的點的 ofst, 即 array[ofst]
  // val 為 array[ofst] 新的值

  // 判斷當下區間是否為有效影響區間
  if(segTree[idx].l > ofst or segTree[idx].r < ofst)
    return;

  // 更新
  segTree[idx].maxi = max(segTree[idx].maxi, val);
  // 到葉節點記得 return, 不然會 RE
  if(segTree[idx].l == segTree[idx].r)
    return;

  spUpdate(idx<<1, ofst, val);
  spUpdate(idx<<1|1, ofst, val);
}

void rgUpdate(int l, int r, int val, int idx)
{
  // 假設左閉右開
  if(seg[idx].l > r or seg[idx].r <= l)
    return;
  if(seg[idx].l == l and seg[idx].r ==r)
  {
    seg[idx].?? += val;
    lazyup(idx);
    return;
  }
  int m = (seg[idx].l + seg[idx].r) / 2;
  if(m > r)
    rgupdate(l, r, val, idx<<1);
  else if(m <= l)
    rgupdate(l, r, val, idx<<1|1);
  else
  {
    update(l, m, val, idx<<1);
    update(m, r, val, idx<<1|1);
  }
  lazyup(idx);

}

int main()
{
  return 0;
}

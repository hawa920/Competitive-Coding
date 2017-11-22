#include <bits/stdc++.h>
using namespace std;


typedef long long lld;

lld t, n, p, mid, product, num[64], inv[64];
vector<lld> half1, half2;


lld inverse(lld x)
{
  // find inverse of x
  lld ret = 1, base = x, expo = p - 2;
  while(expo > 0)
  {
    if(expo & 1)
      ret = ((ret % p) * (base % p)) % p;
    expo >>= 1;
    base = ((base % p) * (base % p)) % p;
  }
  return ret;
}


void dp1(int cur)
{
  if(cur > mid)
  {
    half1.push_back(product);
    return;
  }
  product = ((product % p) * (num[cur] % p)) % p; // 選
  dp1(cur + 1);
  product = ((product % p) * (inv[cur] % p)) % p; // 不選
  dp1(cur + 1);
}


void dp2(int cur)
{
  if(cur >= n)
  {
    half2.push_back(product);
    return;
  }
  product = ((product % p) * (inv[cur] % p)) % p; // 選
  dp2(cur + 1);
  product = ((product % p) * (num[cur] % p)) % p; // 不選
  dp2(cur + 1);
}


int main()
{
  scanf("%lld", &t);
  while(t--)
  {
    // 初始化
    half1.clear();
    half2.clear();

    scanf("%lld%lld", &n, &p);
    for(lld i = 0; i < n; i++)
    {
      scanf("%lld", &num[i]);
      inv[i] = inverse(num[i]);
    }
    mid = n / 2; // 一半
    // 爆一半正常乘積
    product = 1;
    dp1(0);
    // 搜一半inverse乘積
    product = 1;
    dp2(mid + 1);
    // 排序
    sort(half1.begin(), half1.end());
    sort(half2.begin(), half2.end());
    lld i, j, temp1, temp2, sum = 0;
    // 對兩個 sorted array 排序做O(N) traverse
    for(i = 0, j = 0; i < half1.size() && j < half2.size();)
    {
      temp1 = 0; temp2 = 0;
      if(half1.at(i) < half2.at(j))
      {
        i++;
        continue;
      }
      else if(half1.at(i) > half2.at(j))
      {
        j++;
        continue;
      }
      while(j < half2.size() && half1.at(i) == half2.at(j))
      {
        j++;
        temp2++;
      }
      while(i < half1.size() && half1.at(i) == half2.at(j - 1))
      {
        i++;
        temp1++;
      }
      sum += temp1 * temp2;
    }
    sum = sum - 1 >= 0 ? sum - 1 : 0; // 扣掉一開始 product 為 1 inverse product 也為一 (通通不選) 的可能
    printf("%lld\n", sum);
  }
}

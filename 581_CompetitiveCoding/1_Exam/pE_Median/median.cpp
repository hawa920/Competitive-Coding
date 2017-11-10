#include <bits/stdc++.h>
using namespace std;


int temp;
const int mod = 1e9 + 7;
long long ret;
priority_queue<int, vector<int>, less<int> > maxheap;
priority_queue<int, vector<int>, greater<int> > minheap;


int main()
{
  scanf("%d", &temp);
  maxheap.push(temp);
  ret = temp;

  while(scanf("%d", &temp) != EOF)
  {
    if(temp > maxheap.top())
    {
      minheap.push(temp);
      // 平衡
      if(minheap.size() - maxheap.size() == 2)
      {
        maxheap.push(minheap.top());
        minheap.pop();
      }
    }

    else
    {
      maxheap.push(temp);
      // 平衡
      if(maxheap.size() - minheap.size() == 2)
      {
        minheap.push(maxheap.top());
        maxheap.pop();
      }
    }
    ret += (minheap.size() == maxheap.size()) ? (minheap.top() + maxheap.top()) / 2 : (maxheap.size() > minheap.size() ? maxheap.top() : minheap.top());
    ret %= mod;
  }
  printf("%lld\n", ret);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;

int n, l, r;
multiset<int> v;

int main()
{
  multiset<int>::iterator p;
  while(scanf("%d", &n) != EOF and n > 0)
  {
    v.clear();
    for(int i = 0; i < n; i++)
    {
      scanf("%d%d", &l, &r);
      v.insert(l);
      if((p = v.upper_bound(r)) != v.end())
        v.erase(p);
    }
    cout << v.size() << endl;
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;

int n, l, r;
multiset<int> v;



int main()
{
    while(scanf("%d", &n) != EOF and n)
    {

        v.clear();
        for(int i = 0; i < n; i++)
        {
            scanf("%d%d", &l, &r);
            v.insert(l);
            auto it = v.upper_bound(r);
            if(it != v.end())
                v.erase(it);

        }
        cout << v.size() << endl;

    }


    return 0;
}

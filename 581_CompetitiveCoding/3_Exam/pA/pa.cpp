#include <bits/stdc++.h>
using namespace std;

#define MAX 30009

int p[MAX], gp[MAX], h[MAX], n, m, k;
vector<int> temp;

int myfind(int x)
{
    return p[x] == x ? x : myfind(p[x]);
}


void myunion(int x, int y)
{
    x = myfind(x);
    y = myfind(y);
    if(x != y)
    {
        if(h[x] < h[y])
            p[x] = y;
        else if(h[x] > h[y])
            p[y] = x;
        else
        {
            p[y] = x;
            h[x]++;
        }
    }
}





int main()
{
    while(scanf("%d%d", &n, &m) != EOF and (n or m))
    {
        for(int i = 0; i < MAX; i++)
        {
            p[i] = i;
            h[i] = 0;
        }
        for(int i = 0; i < m; i++)
        {
            scanf("%d", &k);
            for(int i = 0; i < k; i++)
            {
                scanf("%d", &gp[i]);
            }

            for(int i = 0, j = 1; j < k; j++)
            {
                myunion(gp[i], gp[j]);
            }


        }
        int ans = 0;

        int boss = myfind(0);
        for(int i = 0; i < n; i++)
        {
            if(myfind(i) == boss)
                ans++;
        }

        cout << ans << endl;

    }
}

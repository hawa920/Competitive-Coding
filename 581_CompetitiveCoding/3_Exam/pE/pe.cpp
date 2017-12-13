#include <bits/stdc++.h>
using namespace std;

vector<pair<double, double> > u, v;
const double oo = 1e9+7;
int t, n, X1, X2, Y1, Y2, temp1, temp2;
bool cmp(pair<double, double>a, pair<double, double> b)
{
  return a.second < b.second;
}

int main()
{
  scanf("%d", &t);
  while(t--)
  {
    u.clear();
    v.clear();
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
      scanf("%d%d%d%d", &X1, &Y1, &X2, &Y2);
      if(Y1 >= 0)
      {
        if(X1 == 0)
        {
          u.push_back({(double)Y1/X2, oo});
        }
        else
        {
          u.push_back({(double)Y1/X2, (double)Y2/X1});
          v.push_back({(double)Y1/X2, (double)Y2/X1});
        }
      }
      else if(Y1 < 0 and Y2 > 0)
      {
        if(X1 == 0)
        {
          u.push_back({-oo, oo});
        }
        else
        {
          u.push_back({(double)Y1/X1, (double)Y2/X1});
          v.push_back({(double)Y1/X1, (double)Y2/X1});
        }

      }

      else if(Y2 <= 0)
      {
        if(X1 == 0)
        {
          u.push_back({-oo, (double)Y2/X2});
        }
        else
        {
          u.push_back({(double)Y1/X1, (double)Y2/X2});
          v.push_back({(double)Y1/X1, (double)Y2/X2});
        }

      }

    }
    sort(u.begin(), u.end(), cmp);
    sort(v.begin(), v.end(), cmp);
    temp1 = 0;
    temp2 = 1;
    for(int i = 0; i < u.size();)
    {
      temp1++;
      double j = u[i].second;
      while(i < u.size() and j >= u[i].first)
        i++;
    }
    for(int i = 0; i < v.size();)
    {
      temp2++;
      double j = v[i].second;
      while(i < u.size() and j >= v[i].first)
        i++;
    }
    cout << min(temp1, temp2) << endl;
  }
  return 0;
}

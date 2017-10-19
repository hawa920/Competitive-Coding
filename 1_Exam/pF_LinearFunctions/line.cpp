/* -----------------------------
 *  piece-wise linear function
 * ----------------------------*/


#include <bits/stdc++.h>
using namespace std;
typedef long long lld;

#define xx first
#define yy second

struct dt_line
{
  lld lbnd, a, b; /* y = ax + b */
};


lld nl, nv, a, b, i, j, k, pt[10009], ret;
vector<pair<lld, lld> > temp;
deque<dt_line> line;


int main()
{
  while(true)
  {
    scanf("%lld%lld", &nl, &nv);

    if(nl == 0)
      return 0;

    temp.clear();
    line.clear();

    for(i = 0; i < nl; i++)
    {
      scanf("%lld%lld", &a, &b);
      temp.push_back({a, b});
    }

    sort(temp.begin(), temp.end());

    for(i = 0; i < nv; i++)
    {
      scanf("%lld", &pt[i]);
    }

    sort(pt, pt + nv);

    for(i = 0; i < temp.size(); i++)
    {
      for(j = i + 1; j < temp.size() && temp.at(i).xx == temp.at(j).xx; j++)
        ;
      i = j - 1;
      if(line.empty())
      {
        line.push_back({-INT_MAX, temp.at(i).xx, temp.at(i).yy});
      }
      else
      {
        for(k = line.size() - 1; k >= 0 and ((line.at(k).b - temp.at(i).yy) / (temp.at(i).xx - line.at(k).a)) <= line.at(k).lbnd;)
        {
          line.pop_back();
          k--;
        }

        line.push_back({(line.at(k).b - temp.at(i).yy) / (temp.at(i).xx - line.at(k).a), temp.at(i).xx, temp.at(i).yy});
      }
    }

    line.push_back({INT_MAX, 0, 0});
    ret = 0;

    for(i = 1, j = 0; i < line.size();)
    {
      while(j < nv and pt[j] <= line.at(i).lbnd)
      {
        if(pt[j] == line.at(i).lbnd)
          ret += (line.at(i-1).a * pt[j] + line.at(i-1).b) > (line.at(i).a * pt[j] + line.at(i).b) ? (line.at(i-1).a * pt[j] + line.at(i-1).b) : \
                 (line.at(i).a * pt[j] + line.at(i).b);
        else
          ret += line.at(i-1).a * pt[j] + line.at(i-1).b;
        j++;
      }
      i++;
    }

    printf("%lld\n", ret);
  }
  return 0;
}

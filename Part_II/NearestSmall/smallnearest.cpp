

/*
 * Nearest small problem,
 * Reference: https://en.wikipedia.org/wiki/All_nearest_smaller_values
 * Code below is implemented using stack
 */


#include <bits/stdc++.h>
using namespace std;
typedef long long lld;


void nearest_small(int n)
{
  int arr[n];
  lld ret(0);
  stack<int> pile;
  for(int i = 0; i < n; i++)
    scanf("%d", &arr[i]);

  for(int i = 0; i < n; i++)
  {
    while(not pile.empty() and pile.top() >= arr[i])
    {
        pile.pop();
    }

    if(pile.empty())
    {
      ; // doesn't exist
    }

    else
    {
      ret += arr[i] - pile.top();
    }

    pile.push(arr[i]);
  }
  printf("%lld\n", ret);
}


int main()
{
  int n;
  scanf("%d", &n);
  while(n != 0)
  {
    nearest_small(n);
    scanf("%d", &n);
  }
  return 0;
}



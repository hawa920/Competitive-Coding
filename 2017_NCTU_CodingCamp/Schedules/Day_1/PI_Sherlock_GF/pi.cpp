/* # AC: http://codeforces.com/problemset/problem/776/B
 * derived from erastothenes method, notice the boundary is important.*/
#include <bits/stdc++.h>
using namespace std;
#define MAX 100009

int n, eras[MAX];

void init() {

  cin >> n;
  const int bnd = sqrt(MAX);
  for(int i = 0; i < MAX; i++)
    eras[i] = 1;
  for(int i = 2; i <= bnd; i++)
    if(eras[i] == 1)
      for(int j = i * i; j < MAX; j+=i)
        eras[j] = 2;
}

void solve()  {

  if(n > 2)
    cout << "2" << endl;
  else
    cout << "1" << endl;
  for(int i = 2; i <= n+1; i++)
    cout << eras[i] << " ";
  cout << endl;
}

int main(int argc, char **argv) {

  init();
  solve();
  return 0;
}

/* #AC: http://codeforces.com/problemset/problem/26/A
 * The algorithm derives from Erastosthenes Sieve Method */
#include <bits/stdc++.h>
using namespace std;

#define MAX 3009
#define xx  first /* std::pair::first */
#define yy  second /* std::pair::second */
pair<bool, int> eras[MAX];

void init() {

  /*init*/
  for(int i = 0; i < MAX; i++)
    eras[i].xx = eras[i].yy = 0;
  /* To count the prime divisors, i's up to MAX rather than sqrt(MAX) */
  for(int i = 2; i < MAX; i++)  {
    if(! eras[i].xx)
      /* To count the prime divisors, j starts from i+i instead of i*i */
      for(int j = i + i; j < MAX; j += i) {
        eras[j].xx = 1;
        eras[j].yy ++;
      }
  }
}
void solve()  {

  int n, ans(0);
  cin >> n;
  for(int i = 2; i <= n; i++)
    if(eras[i].yy == 2)
      ans++;
  cout << ans << endl;
}
int main(int argc, char **argv) {
  init();
  solve();
  return 0;
}

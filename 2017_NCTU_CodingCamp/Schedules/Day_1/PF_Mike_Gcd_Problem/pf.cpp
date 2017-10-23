/*#AC: http://codeforces.com/problemset/problem/798/C
 * Observation and analyzation, we only have to consider 2 as divisor after checking all lucky cases.*/
#include <bits/stdc++.h>
using namespace std;

int  n, arr[100009], bnd = 31623, bndbnd = 178, ans(0); /*n < 1e5 */
bool eras[31623];

void init() {

  fill(&eras[0], &eras[0] + bnd, 0);
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", &arr[i]);
  /*erastosthenes method for finding primes*/
  for(int i = 2; i < bndbnd; i++)
    if(not eras[i])
      for(int j = i * i; j < bnd; j += i)
        eras[j] = true;
}

void solve()  {

  /*lucky case check*/
  for(int i = 2; i < bnd; i++)  {
    if(not eras[i]) {
      for(int j = 0; j < n; j++)  {
        if(arr[j] % i != 0)
          break;
        if(j == n - 1)  {
          printf("YES\n0\n");
          return;
        }
      }
    }
  }
  /* Consider 2 as the only divisor since it's impossible to find a, b that (a-b)%k = 0 and (a+b)%k = 0\
   * while a%k != 0 and b%k != 0, k=2 is only solution can satisfy the above.
   * Two odd number need 1 transferation while 1 odd and 1 even need 2 transferation.*/
  for(int i = 0; i < n - 1; i++)  {
    if(arr[i] & 1 and arr[i + 1] & 1) {
      arr[i] += 1;
      arr[i + 1] += 1;
      ans += 1;
    }
    else if(arr[i] & 1 and not (arr[i + 1] & 1)) {
      arr[i] += 1;
      ans += 2;
    }
  }
  if(arr[n - 1] & 1)
    ans += 2;
  printf("YES\n%d\n", ans);
}

int main(int argc, char **argv) {

  init();
  solve();
  return 0;
}

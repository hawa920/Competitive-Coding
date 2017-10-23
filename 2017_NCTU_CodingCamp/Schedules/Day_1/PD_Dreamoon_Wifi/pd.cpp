/* # AC: http://codeforces.com/problemset/problem/476/B
 * Combinatorics */
#include <bits/stdc++.h>
using namespace std;

int pc1(0), pc2(0), nc1(0), nc2(0), qc(0), dp(0), dn(0), u1(1), d1(1), d2(1), d3(1);
string s1, s2;

void init() {

  cin >> s1 >> s2;
  for(auto const &i : s1) {
    if(i == '+') pc1++;
    else if(i == '-') nc1++;
  }
  for(auto const &i : s2) {
    if(i == '+') pc2++;
    else if(i == '-') nc2++;
    else if(i == '?') qc++;
  }
}

void solve()  {

  if(pc1 < pc2 or nc1 < nc2)
    cout << "0.000000000000" << endl;
  else  {
    dp = pc1 - pc2;
    dn = nc1 - nc2;
    for(int i = 2; i <= (dp + dn); i++) u1 *= i;
    for(int i = 2; i <= dp; i++) d1 *= i;
    for(int i = 2; i <= dn; i++) d2 *= i;
    for(int i = 1; i <= qc; i++) d3 *= 2;
    cout << fixed << setprecision(12) << (double) u1 / (d1 * d2) / d3  << endl;
  }
}

int main(int argc, char **argv) {

  init();
  solve();
  return 0;
}

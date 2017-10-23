/*
 * Question:
 * Given a string S and a substring T, to verify if T exists in S, if it does exist, how many times and where does it occur ?
 *
 * Solution:
 * Method: Rabin-Karp Rolling Hash
 * Time Complexity: O (n)
 *
 * Pre-process:
 *
 *    build up a hashTable stores the prefix sum of the hash value from S[0] ~ S[len-1], \
 *    and Calculate the hash value of the target string T, \

 *    Traverse the hashTable from S[0] to S[slen - tlen], and calculate the hash value of this certain range,\
 *    Compare with the hash value of string T.
 *
 *    If it shares the same value, we can do a further linear check or roughly says that the two strings are the same,
 *    if not on the other way round.
 *
 *    How to deal with the collisions is one of the biggest and hardest issues of all hashings I think.
 *
 * */
#include <bits/stdc++.h>

using namespace std;

#define RHB (const int) 29         /* Rolling hash base*/
#define MOD (const int) 1000000007 /* Range of hash value, a big prime to avoud collisions */

int s_len, t_len, t_hv(0);
string s, t;
vector<long long> hashTab, baseTab;


void init() {

  cin >> s >> t;
  s_len = s.length();
  t_len = t.length();

  assert(s_len >= t_len);

  hashTab.push_back(s[0] - 'a' + 1);
  baseTab.push_back(1);

  /* initialize hash table */
  for(int i = 1; i < s_len; i++)
    hashTab.push_back((hashTab[i - 1] * RHB + (s[i] - 'a' + 1)) % MOD);

  /* initialize base table */
  for(int i = 1; i < s_len; i++)
    baseTab.push_back((baseTab[i - 1] * RHB) % MOD);

  /* get the hash value of t */
  for(int i = 0; i < t_len; i++)
    t_hv = t_hv * RHB + (t[i] - 'a' + 1);

}


__attribute__((always_inline)) inline int get_hv(int l, int r)  {

  if(l == 0)
    return hashTab[r];

  long long ret = hashTab[r] - ((hashTab[l - 1] * baseTab[r - l + 1]) % MOD);
  return (int) ret > 0 ? ret : (ret + MOD);

}

void solve()  {

  for(int i = 0; i <= s_len - t_len; i++) {

    if(t_hv == get_hv(i, i + t_len - 1))
      fprintf(stdout, "Substring occurs at s[%d]\n", i);
  }
}

int main(int argc, char **argv) {

  init();
  solve();
  return 0;
}

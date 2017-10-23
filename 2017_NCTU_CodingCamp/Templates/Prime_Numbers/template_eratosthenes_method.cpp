/*
 * Method: Using Eratosthenes Method
 * A sort of sieve method, using the fact that any composite number has at least 1 prime divisor leq to sqrt(n)
 *
 * Time complexity: O( n * loglog(n) )
 * proof -> http://www.csie.ntnu.edu.tw/~u91029/Prime.html#2
 *
 * Pseudo Code:
 *
 * for( i = 2 ~ sqrt(n) )  \
 *    if( not not_prime[i] ) \
 *      for( j = i*i; j <= n; j+=i ) \
 *        not_prime[i] = true; \
 *
 *
 * Pros: Simple and fast
 * Cons: Memory limitations, when N is large, the memory cost will be enumerous.
 *       I think the best way is to combine both Eratosthenes method and numerical method,
 *       depending on both the time and memory limitation, and decide how our code shud be.
 */





#include <bits/stdc++.h>
using namespace std;

vector<int> prime;

void getPrimes(int n_range)  {

  bool *not_prime = new bool[n_range + 1];
  memset(not_prime, sizeof(bool) * (n_range + 1), false);
  /* Algorithm part, short and simple */
  for(int i = 2; i <= sqrt(n_range); i++) {

    if(not not_prime[i])  {
      for(int j = i * i; j <= n_range; j+=i)
        not_prime[j] = true;
    }
  }
  /* scan thru the bool array and add all primes in vector */
  for(int i = 2; i <= n_range; i++) {
    if(not not_prime[i])
      prime.push_back(i);
  }
  /* Free dynamic array */
  delete not_prime;
}

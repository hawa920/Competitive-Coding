/*
 * Method: Using numerical characteristic
 * A composite number N has at least one prime divisor leq to sqrt(N)
 *
 * Time complexity: O( n * sqrt(n) )
 * Pseudo Code:
 *
 * for( i = prime[end] + 1 ~ n ) \
 *    for( j = 0; prime[j] <= sqrt(i); j++) \
 *      if( j divides i completely ) \
 *        i is not prime; \
 *    i is a prime;
 *
 *
 * Pros: n could be a large number tho efficiency will cut down
 * Cons: The preprocess of initializing the prime table could be time costy,
 *       it depends on how big the initial prime table is. The bigger it is,
 *       the less calculations there will be.
 */



#include <bits/stdc++.h>
using namespace std;
vector<int> prime;

void getPrimes(const int range_n) {

  bool is_prime;
  int base_prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29}, bound;
  prime.assign(&base_prime[0], &base_prime[0] + 10); /* initialize vector prime */

  for(int i = 31; i <= range_n; i+=2) {

    bound = sqrt(i);
    is_prime = true;

    for(int j = 0; bound >= prime[j]; j++)  {
      /* scan all primes leq to sqrt(i) */
      if(i % prime[j] == 0) {
        /* i is not a prime */
        is_prime = false;
        break;
      }
    }
    /* add i to prime list */
    if(is_prime)
      prime.push_back(i);
  }
}

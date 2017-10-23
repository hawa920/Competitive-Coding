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

#define MAX_RANGE (const int) 1e9

int range_n;
vector<int> prime;

void getPrimes() {

  cout << "Please input a range n: " << endl;
  cin >> range_n;
  /* the initial prime list holds the first ten prime integers. */
  int base_prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29}, bound;
  bool is_prime;

  prime.assign(&base_prime[0], &base_prime[0] + 10);

  for(int i = 31; i <= range_n; i+=2) {

    bound = sqrt(i);
    is_prime = true;
    /* scan all primes leq to sqrt(i) */
    for(int j = 0; bound >= prime[j]; j++)  {

      if(i % prime[j] == 0) {
        /* i is not a prime */
        is_prime = false;
        break;
      }
    }
    /* if i is a prime, add i to prime list */
    if(is_prime)
      prime.push_back(i);
  }
}

void print()  {

  vector<int>::iterator i = prime.begin();
  for( ; i != prime.end() - 1; i++)
    cout << *i << ", ";
  cout << *i << endl;

}

int main(int argc, char **argv) {

  getPrimes();
  print();
  return 0;
}

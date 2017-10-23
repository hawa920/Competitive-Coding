/* #AC: http://codeforces.com/problemset/problem/2/b
 * When it comes to trailing zero, think of the interger factorization of (2^t, 5^t), dp these two seperately will find the answer out.*/
#include <bits/stdc++.h>
using namespace std;

const int MAX = 1024, inf = 1000000009, two = 0, five = 1;

int dp[MAX][MAX][2], bt[MAX][MAX][2], temp, n, zero_row(-1), k;
bool zero_exist(false);

void backtrace(int x, int y, int z) {
  if(x == 1 and y == 1)
    return;
  if(bt[x][y][z] == 1)
    backtrace(x, y-1, z);
  else if(bt[x][y][z] == 2)
    backtrace(x-1, y, z);
  if(bt[x][y][z] == 1)
    printf("R");
  else if(bt[x][y][z] == 2)
    printf("D");
}

void dp_solve() {

  for(int i = 0; i < MAX; i++)
    for(int j = 0; j < MAX; j++)  {
      dp[i][j][0] = dp[i][j][1] = 0;
      bt[i][j][0] = bt[i][j][1] = -1 ;
    }

  scanf("%d", &n);
  for(int i = 2; i <= n; i++) /*notice the boundary*/
    dp[0][i][0] = dp[0][i][1] = dp[i][0][0] = dp[i][0][1] = inf;

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {

      scanf("%d", &temp);
      if(temp == 0) {
        zero_row = i;
        zero_exist = true;
      }
      for(dp[i][j][two] = 0; temp % 2 == 0 and temp != 0; dp[i][j][two]++) temp /= 2;
      for(dp[i][j][five] = 0; temp % 5 == 0 and temp != 0; dp[i][j][five]++) temp /= 5;
      for(int k = 0; k < 2; k++) {
        if(dp[i - 1][j][k] > dp[i][j - 1][k]) {

          dp[i][j][k] += dp[i][j - 1][k];
          bt[i][j][k] =  1; /*right*/
        }
        else  {

          dp[i][j][k] += dp[i - 1][j][k];
          bt[i][j][k] = 2; /*down*/
        }
      }
    }
  }
  k = (dp[n][n][two] < dp[n][n][five]) ? two : five;
  if(zero_exist and dp[n][n][k] > 1) {
    printf("1\n");
    for(int i = 2; i <= zero_row; i++) printf("D");
    for(int i = 2; i <= n; i++) printf("R");
    for(int i = 1; i <= (n - zero_row); i++) printf("D");
    printf("\n");
  }
  else  {
    printf("%d\n", dp[n][n][k]);
    backtrace(n, n, k);
    printf("\n");
  }
}


int main(int argc, char **argv)  {

  dp_solve();
  return 0;
}

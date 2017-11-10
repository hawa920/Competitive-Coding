#include <bits/stdc++.h>
using namespace std;


int t, n, ret, temp, arr[150009], l, r;


int main(int argc, char **argv)
{
  scanf("%d", &t);
  //arr[0] = -INT_MAX; //可有可無
  while(t--)
  {
    ret = 0;
    scanf("%d", &n);
    // 初始化
    for(int i = 1; i <= n; i++)
      arr[i] = INT_MAX;

    scanf("%d", &temp);
    arr[1] = temp; // 長度=1 的最小值等於第一個input

    for(int i = 2; i <= n; i++)
    {
      scanf("%d", &temp);
      l = 1;
      r = n;
      //二分搜
      while(r > l)
      {

        if(temp > arr[(l + r) / 2])
          l = 1 + (l + r) / 2; // 記得要加一

        else if(temp <= arr[(l + r) / 2]) // 注意邊界, 要往前找到第一個可插入的地方
          r = (l + r) / 2;
      }
      arr[l] = temp;
      ret = max(ret, l);
    }
    printf("%d\n", ret);
  }

  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <string.h>


int main()
{

  int nc, p, xlen, nlen, i, j, k;
  char n[256], x[256];
  printf("number of td:");
  scanf("%d", &nc);

  FILE *fd = fopen("td", "w");
  assert(fd != NULL);
  srand(time(NULL));

  for(k = 0; k < nc; k++)
  {
    xlen = rand() % 200 + 1;
    nlen = rand() % 200 + 1;
    for(i = 0; i < xlen; i++)
      x[i] = (rand() % 10) + '0';
    for(i = 0; i < nlen; i++)
      n[i] = (rand() % 10) + '0';
    p = rand();

    fprintf(fd, "%s %s %d\n", x, n, p);
  }

  fclose(fd);
  return 0;
}

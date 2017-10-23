#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>


int main()
{

  int n, idx_i, idx_j, a, b, nl, nv;
  printf("number of data:");
  scanf("%d", &n);


  FILE *fd = fopen("mytd", "w");
  assert(fd != NULL);
  srand(time(NULL));


  for(idx_i = 0; idx_i < n; idx_i++)
  {
    nl = rand() % 45000 + 1;
    nv = rand() % 10000 + 1;
    fprintf(fd, "%d %d\n", nl, nv);


    for(idx_j = 0; idx_j < nl; idx_j++)
    {
      a = rand();
      a = (rand() & 1) ? a : -a;
      b = rand();
      b = (rand() & 1) ? b : -b;
      fprintf(fd, "%d %d\n", a, b);
    }


    for(idx_j = 0; idx_j < nv; idx_j++)
    {
      a = rand();
      a = (rand() & 1) ? a : -a;
      fprintf(fd, "%d ", a);
    }
    fprintf(fd, "\n");
  }


  fprintf(fd, "0 0\n");
  fclose(fd);
  return 0;
}

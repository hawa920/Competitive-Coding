#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

int main()
{
  int n, i, j, size;
  FILE *fd = fopen("td", "w");
  assert(fd != NULL);

  printf("number of date to gen: \n");
  scanf("%d", &n);
  n = n > 0 ? n : -n;

  srand(time(NULL));
  fprintf(fd, "%d\n", n);

  for(i = 0; i < n; i++)
  {
    size = rand() % 150000 + 1;
    fprintf(fd, "%d\n", size);

    for(j = 0; j < size; j++)
      fprintf(fd, "%d ", rand() + 1);
    fprintf(fd, "\n");

    for(j = 0; j < size; j++)
      fprintf(fd, "%d ", rand() % 100 + 1);
    fprintf(fd, "\n");
  }

  fclose(fd);
  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  FILE *fd = fopen("in.txt", "w");
  srand(time(NULL));

  int i;
  if(fd != NULL)
  {
    for(i = 0; i < 1000000; i++)
      fprintf(fd, "%d %d %d %d %d\n", rand(), rand(), rand()%10, rand()%10, rand()%10);
  }

  fclose(fd);
  return 0;
}

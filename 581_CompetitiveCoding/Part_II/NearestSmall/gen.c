#include <stdio.h>
#include <stdlib.h>


int main()
{
  const int MAXDATA = 10;
  const int MAXMEMBER = 200000;
  int idx_i, idx_j;
  FILE *fd = fopen("td", "w+");
  if(fd != NULL)
  {
    for(idx_i = 0; idx_i < MAXDATA; idx_i++)
    {
      fprintf(fd, "%d ", MAXMEMBER);

      for(idx_j = 0; idx_j < MAXMEMBER; idx_j++)
      {
        fprintf(fd, "%d ", rand());
      }
    }

    fprintf(fd, "0");
    fclose(fd);
    return 0;
  }

  printf("error\n");
  return 0;
}

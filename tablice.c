#include <stdlib.h>
#include <stdio.h>

int main (void)
{
  int ***wsk;
  wsk = (int***)malloc(sizeof(int*)*3);
  for(int i = 0; i < 3; i++)
  {
    *(wsk+i) = (int**)malloc(sizeof(int*)*24);
    for(int j = 0; j < 24; j++)
    {
      *(*(wsk+i)+j) = (int*)malloc(sizeof(int)*30);
    }
  }
  printf("wsk = %p\n", wsk);

  return 0;
}

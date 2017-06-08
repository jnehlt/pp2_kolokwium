/*
  laboratorium 1
    cwiczenie 1;
*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define M 6 //x wiersze
#define N 9 //y kolumny

int przyjmij_wartosc(int*, int*);
void generuj(int***);
void sumuj(int**, int, int);

int main(void)
{
  int x, y;
  int** tab;

  generuj(&tab);

  if(!przyjmij_wartosc(&x, &y))
  {
    printf("error\n");
    return -1;
  }
  sumuj(tab, x, y);

  return 0;
}

int przyjmij_wartosc(int* x, int* y)
{
  printf("podaj x: ");
  scanf("%d", x);
  fflush(stdin);
  printf("podaj y: ");
  scanf("%d", y);
  fflush(stdin);
  if((*x < 1 || *y < 1) || (*x > M || *y > N))
  {
    printf("blad\n");
    return 0;
  }
  return 1;
}

void generuj(int*** tabb)
{
  int** tab;
  int x = 0, y = 0;

  tab = (int**)malloc(sizeof(int*)*N);
  for(y = 0; y < N; ++y)
  {
    *(tab + y) = (int*)malloc(sizeof(int)*M);
  }
  y = 0;  x = 0;

  for(x = 0; x < M; ++x)
  {
    for(y = 0; y < N; ++y)
    {
      *(*(tab+y)+x) = rand()%9+1;
      printf("%d  ", *(*(tab+y)+x));
    }
    printf("\n");
  }
  *tabb = tab;
  return;
}

void sumuj(int** tab, int x, int y)
{
  int buffer = 0, i = 1, suma = 0, roznica;
  while(buffer < N)
  {
    roznica = (y - i > 0) ? y - i : i - y;
    if(x-roznica != x+roznica)
    {
      if(x-roznica-1 >= 0)
      {
        printf("*(*(tab+buffer)+x-roznica-1) = %d\n", *(*(tab+buffer)+x-roznica-1));
        suma += *(*(tab+buffer)+x-roznica-1);
      }
      if(x+roznica-1 < M)
      {
        printf("*(*(tab+buffer)+x-roznica-1) = %d\n", *(*(tab+buffer)+x+roznica-1));
        suma += *(*(tab+buffer)+x+roznica-1);
      }
    }
    else
    {
      printf("*(*(tab+buffer)+x-roznica-1) = %d\n", *(*(tab+buffer)+x-roznica-1));
      suma += *(*(tab+buffer)+x-roznica-1);
    }
    ++buffer;
    ++i;
  }
  printf("suma = %d\n\n", suma);
  return;
}

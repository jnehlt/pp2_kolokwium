#include <stdlib.h>
#include <stdio.h>

struct lista;

struct lista
{
  struct lista* nastepny;
  int dane;
};

unsigned int rozm_listy (struct lista*);
struct lista* list_add_begin(struct lista*, int value);
struct lista* list_add_end(struct lista*, int value);
struct lista* list_del_node(struct lista*, int value);
void list_show(struct lista*);

int main (void)
{

  struct lista* root = NULL;

  root = list_add_begin(root, 40);
  root = list_add_begin(root, 30);
  root = list_add_begin(root, 20);
  root = list_add_begin(root, 10);
  root = list_add_end(root, 100);
  root = list_add_end(root, 200);
  root = list_add_end(root, 300);
  root = list_add_end(root, 400);

  list_show(root);
  int x = rozm_listy(root);
  printf("rozmiar = %d\n\n", x);

  return 0;

unsigned int rozm_listy (struct lista* p)
{
  unsigned int rozmiar = 0;
  while(p)
  {
    rozmiar++;
    p = p->nastepny;
  }
  return rozmiar;
}

void list_show(struct lista* p)
{
  while(p)
  {
    printf("dane = %d\n", p->dane);
    p = p->nastepny;
  }
}

struct lista* list_add_begin(struct lista* r, int value)
{
  if (r == NULL)
  {
    r = (struct lista*)malloc(sizeof(struct lista));
    r->dane = value;
    r->nastepny = NULL;
    return r;
  }
  else
  {
    struct lista* begin = (struct lista*)malloc(sizeof(struct lista));
    begin->dane = value;
    begin->nastepny = r;
    return begin;
  }
}

struct lista* list_add_end(struct lista* r, int value)
{
  struct lista* buf = r;
  while(r->nastepny)
  {
    r = r->nastepny;
  }
  struct lista* end = (struct lista*)malloc(sizeof(struct lista));
  end->dane = value;
  r->nastepny = end;
  end->nastepny = NULL;
  return buf;
}

struct lista* list_del_node(struct lista* r, int number)
{
  unsigned int i = 0;
  struct lista* buf;
  struct lista* del = (struct lista*)malloc(sizeof(struct lista));

  do{
    if(i == number-1)
    {
      r->nastepny = new->nastepny;

    }
    i++;
  }while(i < number);



}

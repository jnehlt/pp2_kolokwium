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
struct lista* list_del_node(struct lista*, int which, int number_of_nodes);
void list_show(struct lista*);

int main (void)
{
  struct lista* root = NULL;

  root = list_add_begin(root, 40);
  root = list_add_begin(root, 30);
  root = list_add_begin(root, 20);
  root = list_add_begin(root, 10);
  root = list_add_end(root, 15);
  root = list_add_end(root, 25);
  root = list_add_end(root, 35);
  root = list_add_end(root, 45);

  list_show(root);
  list_del_node(root, 8, rozm_listy(root));
  list_show(root);

  return 0;
}

unsigned int rozm_listy (struct lista* p)
{
  unsigned int rozmiar = 0;
  while(p)
  {
    rozmiar++;
    p = p->nastepny;
  }
  printf("rozmiar listy: %d\n", rozmiar);
  return rozmiar;
}

void list_show(struct lista* p)
{
  while(p)
  {
    printf("dane = %d   adres = %p\n", p->dane, p);
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
  struct lista* root = r;
  while(r->nastepny)
  {
    r = r->nastepny;
  }
  struct lista* end = (struct lista*)malloc(sizeof(struct lista));
  end->dane = value;
  r->nastepny = end;
  end->nastepny = NULL;
  return root;
}

struct lista* list_del_node(struct lista* r, int which, int number_of_nodes)
{
  int iterator;
  struct lista* root = r;
  struct lista* del = r;
  if(which < 1)
  {
    printf("Error!\nEnter number of natural!\n\n");
    return root;
  }
  if(which > number_of_nodes)
  {
    printf("Error!\nThe given number is not in the scope{%d}.\n\n", number_of_nodes);
    return root;
  }
  if(which == 1)
  {
    del = root;
    root = root->nastepny;
    free(del);
    return root;
  }

  for(iterator = 1; iterator < which-1; iterator++)
  {
    if(del->nastepny->nastepny->nastepny == NULL)
    {
      printf("\n[]D [] []\\\\//[] []D\n\n");
    }
    del = del->nastepny;
  }
  struct lista* del2 = del->nastepny;
  del->nastepny = del->nastepny->nastepny;
  free(del2);
  //printf("buff %p\n", del);
  return root;
}

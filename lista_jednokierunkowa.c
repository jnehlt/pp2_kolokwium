#include <stdlib.h>
#include <stdio.h>

typedef lista ls_t;

struct ls_t
{
  ls_t* nastepny;
  int dane;
};

unsigned int rozm_listy(ls_t*);
ls_t* list_add_begin(ls_t*, int value);
ls_t* list_add_end(ls_t*, int value);
ls_t* list_del_node(ls_t*, int which, int number_of_nodes);
void list_show(ls_t*);

int main (void)
{
  ls_t* root = NULL;

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

unsigned int rozm_listy (ls_t* p)
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

void list_show(ls_t* p)
{
  while(p)
  {
    printf("dane = %d   adres = %p\n", p->dane, p);
    p = p->nastepny;
  }
}

ls_t* list_add_begin(ls_t* r, int value)
{
  if (r == NULL)
  {
    r = (ls_t*)malloc(sizeof(ls_t));
    r->dane = value;
    r->nastepny = NULL;
    return r;
  }
  else
  {
    ls_t* begin = (ls_t*)malloc(sizeof(ls_t));
    begin->dane = value;
    begin->nastepny = r;
    return begin;
  }
}

ls_t* list_add_end(ls_t* r, int value)
{
  ls_t* root = r;
  while(r->nastepny)
  {
    r = r->nastepny;
  }
  ls_t* end = (ls_t*)malloc(sizeof(ls_t));
  end->dane = value;
  r->nastepny = end;
  end->nastepny = NULL;
  return root;
}

ls_t* list_del_node(ls_t* r, int which, int number_of_nodes)
{
  int iterator;
  ls_t* root = r;
  ls_t* del = r;

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
  for(iterator = 1; iterator < which; iterator++)
  {
    if(del->nastepny->nastepny == NULL)
    {
      ls_t* del2 = del->nastepny;
      del->nastepny = NULL;
      goto A;
    }
    del = del->nastepny;
  }
  ls_t* del2 = del->nastepny;
  del->nastepny = del->nastepny->nastepny;
  A:free(del2);
  return root;
}

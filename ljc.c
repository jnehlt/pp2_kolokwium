#include <stdlib.h>
#include <stdio.h>
#include "ljc.h"

ls_t* init_list(ls_t* r)
{
  r = (ls_t*)malloc(sizeof(ls_t));
  r->next = r;
  r->value = 0;
  return r;
}

unsigned int list_size(ls_t* r)
{
  ls_t* loop = r;
  int i = 1;
  while(r->next != loop)
  {
    r = r->next;
    ++i;
  }
  return i;
}

void list_view(ls_t* r)
{
  ls_t* loop = r;
  printf("\n+=+=+=+=+=+=+=+=+=+=+ LIST VIEW +=+=+=+=+=+=+=+=+=+=+\n");
  while(r->next != loop)
  {
    printf("r = %p   r->nastepny = %p   value = %d\n", r, r->next, r->value);
    r = r->next;
  }
  printf("r = %p   r->nastepny = %p   value = %d\n", r, r->next, r->value);
}

ls_t* list_add_begin(ls_t* r, int value)
{
  ls_t* add;
  if(add = (ls_t*)malloc(sizeof(ls_t)))
  {
    //printf("\nAllocation done.\n\n");
    add->next = r;
    add->value = value;
    ls_t* loop = r;
    while(r->next != loop)
    {
      r = r->next;
    }
    r->next = add;
  }
  else
  {
    printf("\nproblem with allocation...\n\n");
  }
  return add;
}

ls_t* list_add_end(ls_t* r, int value)
{
  ls_t* root = r;
  ls_t* add;

  while(r->next != root)
  {
    r = r->next;
  }
  if(add = (ls_t*)malloc(sizeof(ls_t)))
  {
    r->next = add;
    add->value = value;
    add->next = root;
  }
  else
  {
    printf("\nproblem with allocation...\n\n");
  }
  return root;
}

ls_t* list_del_node(ls_t* r, int which)
{
  int i = 1;
  ls_t* loop = r;
  ls_t* del;
  ls_t* buf;

  while(r->next != loop)
  {
    r = r->next;
    ++i;
  }
  r = r->next;
  if(which > i)
  {
    printf("out of range");
    return loop;
  }
   for(i = 1; i < which; ++i)
   {
     r = r->next;
   }
   del = r;
   buf = r->next;
   for(i = 1; i < which+1; ++i)
   {
     r = r->next;
   }
   r->next = buf;
   free(del);

  return loop;
}

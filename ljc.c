#include <stdlib.h>
#include <stdio.h>
#include "ljc.h"

ls_t* init_list(ls_t* r, int value)
{
  r = (ls_t*)malloc(sizeof(ls_t));
  r->next = r;
  r->value = value;
  return r;
}

unsigned int list_size(ls_t* r)
{
  if (r == NULL)
  {
    printf("\nLIST IS EMPTY\n");
    return 0;
  }
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
  if (r == NULL)
  {
    return;
  }
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
  if(which > 0)
  {
    if(r == r->next) //one element list_del_node
    {
      free(r);
      return NULL;
    }
    else
    {
      ls_t* root = r;
      int i = 1;
      while(i < which)
      {
        r = r->next;
        if(r == root) //we've got an loop...
        {
          printf("ERROR_2\nyou expect too much from me\n");
          goto RETURN;
        }
        ++i;
      }
      ls_t *temp = r;
      while(r->next != temp)
      {
        r = r->next;
      }
      r->next = r->next->next;
      if(temp == root)  //if deleting first element
      {
        r = r->next;
        return r; //you cannot return deleted element...
      }
      free(temp);
      RETURN:return root;
    }
  }
  else
  {
    printf("ERROR_1\n r u dumb? --__--\n");
    goto RETURN;
  }
}

void list_clear(ls_t** r)
{
  int size = list_size(*r);
  ls_t* temp;
  while(size--)
  {
    temp = *r;
    *r = (*r)->next;
    free(temp);
  }
  *r = NULL;
}

void list_search_with_guard(ls_t* r, int value)
{
  if(r != NULL)
  {
    //add guard at the end
    ls_t* loop = list_add_end(r, value);
    while(r->value != value)
    {
      r = r->next;
    }
    if(r->next == loop) //not found
    {
      printf("\nSzukany element [%d] nie zostal odnaleziony.\n", value);
    }
    else
    {
      printf("\nOznaleziono element [%d] pod adresem %p.\n", value, r);
    }

    list_del_node(loop, list_size(loop));
  }
}

void list_search(ls_t* r, int value)
{
  if(r != NULL)
  {
    ls_t* loop = list_add_end(r, value);
    while(r->value != value)
    {
      r = r->next;
    }
    if(r->next == loop)
    {
      printf("\nSzukany element [%d] nie zostal odnaleziony.\n", value);
    }
    else
    {
      printf("\nOznaleziono element [%d] pod adresem %p.\n", value, r);
    }
    list_del_node(loop, list_size(loop));
  }
}

ls_t* insertion_sort(ls_t* r)
{
  int size = list_size(r), i = 0;
  ls_t* buffer;
  ls_t* root = r;

  while(size) //how much iterations
  {
    int j = 0;
    while(j < i)
    {
      r = r->next;
      ++j;
//      printf("i = %d   j = %d    ", i, j);
    }
    ls_t* to_swap = r;
    //printf("size = %d\n", size);
    ++i;

    buffer = r;
    j = 0;
    while(j < size)  //find max till root
    {
      printf("r = %p value = %d    ", r, r->value);
      if(r->value > buffer->value)  //remeber that adress
      {
        buffer = r;
      }
      r = r->next;
      printf("buffer = %p\n", buffer);
      ++j;
    }
    //max found! now swap.
    j = 0;
    while(j < i-1)
    {
      r = r->next;
      ++j;
    }
    ls_t* buffer2;
    buffer2 = r;
    printf("buffer2 = %d    ",buffer2->value);
    printf("to_swap = %d\n"  , to_swap->value);


    --size;
  }
  return root;
}

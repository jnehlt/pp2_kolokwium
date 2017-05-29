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
          return root;
        }
        ++i;
      }
      ls_t *temp = r;
      while(r->next != temp)
      {
        r = r->next;
        printf("r = %p\n",r);
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

ls_t* list_clear(ls_t* r)
{
  //DOIT!!!!
  // ls_t* temp;
  // while(r->next != NULL)
  // {
  //   temp = r;
  //   r = r->next;
  //   free(temp);
  // }

  return r;
}

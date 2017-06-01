#include "ljc.h"
#include <stdio.h>

int main(void)
{
  ls_t* root;
  root = init_list(root, 0);
  root = list_add_begin(list_add_begin(root, 10), 90);
  root = list_add_begin(root, 20);
  root = list_add_begin(root, 30);
  root = list_add_begin(root, 40);
  root = list_add_end(root, 50);
  root = list_add_end(root, 60);
  root = list_add_end(root, 70);
  root = list_add_end(root, 80);
  printf("\n\nlist_size = %d\n", list_size(root));
  list_view(root);
  //list_size(root);

  // list_search_with_guard(root, 80);
  // list_search(root, 81);
  root = insertion_sort(root);

  return 0;
}

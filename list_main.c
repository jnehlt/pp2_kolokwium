#include "ljc.h"
#include <stdio.h>

int main(void)
{
  ls_t* root;
  root = init_list(root);
  root = list_add_begin(root, 10);
  root = list_add_begin(root, 20);
  root = list_add_begin(root, 30);
  root = list_add_begin(root, 40);
  root = list_add_end(root, 50);
  root = list_add_end(root, 60);
  root = list_add_end(root, 70);
  root = list_add_end(root, 80);
  printf("list_size = %d\n", list_size(root));
  list_view(root);
  root = list_del_node(root, 8);
  list_view(root);

  return 0;
}

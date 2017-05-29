#ifndef LIST_H_
  #define LIST_H_
    typedef struct ls_t ls_t;
    struct ls_t
    {
      struct ls_t* next;
      int value; //PRZEROBIĆ NA WSKAŹNIKI DO FUNKCJI
    };
    ls_t* init_list(ls_t*, int);
    ls_t* list_add_begin(ls_t*, int);
    ls_t* list_add_end(ls_t*, int);
    ls_t* list_del_node(ls_t*, int);
    ls_t* list_clear(ls_t*);
    unsigned int list_size(ls_t*);
    void list_view(ls_t*);
#endif

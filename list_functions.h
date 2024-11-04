#ifndef LIST_FUNC
#define LIST_FUNC

#include"stdio.h"
#include"stdlib.h"
#include"assert.h"
#include"..\My_labraries\colours.h"

const int lst_size = 10;
const int lst_poison = -666;

struct list_elem
{
    int next;
    int elem;
    int prev;
};

struct my_list
{
    list_elem* lst_array;
    int length;
    int size;
    FILE* log;
    FILE* graph_log;
};

int list_ctor(my_list* lst, int lst_lenght);
int list_dtor(my_list* lst);
int list_dump(my_list* lst);
int graph_dump(my_list* lst);
int insert_lst(my_list* lst, int position, int value);
int check_list(my_list* lst);

#endif
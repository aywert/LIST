#include"stdio.h"
#include"stdlib.h"
#include"assert.h"

const int lst_size = 10;
const int poison_for_lst = -666;

struct my_list
{
    int* data;
    int* next;
    int* prev;
    FILE* log;
};

int list_ctor(my_list* lst);
int list_dtor(my_list* lst);
int list_dump(my_list* lst);
int insert_lst(my_list* lst, int position, int value);
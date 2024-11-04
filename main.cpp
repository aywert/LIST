#include"list_functions.h"

int main(void)
{
    my_list lst = {};
    
    list_ctor(&lst, 20);

    for (int i = 0; i < lst.length-3; i++)
    {
        insert_lst(&lst, i, (i+1)*10);
    }

    insert_lst(&lst, 5, 555);

    for (int i = 0; i < lst.length - 1; i++)
    {
        printf("%4d", i);
    }
    printf("\n");

    int TAIL = lst.lst_array[0].next;
    printf("TAIL = %d\n", TAIL);
    for (int i = 0; i < lst.length - 1; i++)
    {
        printf("%4d", lst.lst_array[TAIL].elem);
        TAIL = lst.lst_array[TAIL].next;
    }
    printf("\n");

    list_dump(&lst);
    graph_dump(&lst);

    list_dtor(&lst);
}
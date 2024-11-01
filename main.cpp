#include"list_functions.h"

int main(void)
{
    my_list lst = {};
    
    list_ctor(&lst);

    for (int i = 0; i < 6; i++)
    {
        insert_lst(&lst, i, i);
    }

    list_dump(&lst);

    list_dtor(&lst);
}
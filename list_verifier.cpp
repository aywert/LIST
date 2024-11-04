#include"list_functions.h"

int check_list(my_list* lst)
{
    if (lst == NULL)
        printf(RED("lst = NULL\n"));

    if (lst->lst_array == NULL)
        printf(RED("lst->lst->array = NULL\n"));

    if (lst->size < 0)
        printf(RED("lst->size < 0\n"));

    if (lst->length < 0)
        printf(RED("lst->length <= 0\n"));

    if (lst->size > lst->length)
        printf(RED("lst->size >= lst->length\n"));

    if (lst->log == NULL)
        printf(RED("lst = NULL\n"));

    return 0;
}
#include"list_functions.h"

static int find_free_cell(my_list* lst);

int list_ctor(my_list* lst)
{
    assert(lst);

    lst->log = fopen("log_files/log_dump.txt", "w");

    lst->data = (int*)calloc(sizeof(int), lst_size);
    lst->next = (int*)calloc(sizeof(int), lst_size);
    lst->prev = (int*)calloc(sizeof(int), lst_size);

    for (int i = 1; i < lst_size; i++)
    {
        lst->data[i] = poison_for_lst;
        lst->next[i] = -1;
        lst->prev[i] = -1;
    }

    // lst->data[1] = 10;
    // lst->data[2] = 20;
    // lst->data[3] = 30;
    // lst->data[4] = 40;
    // lst->data[5] = 50;

    // lst->next[1] = 2;
    // lst->next[2] = 3;
    // lst->next[3] = 4;
    // lst->next[4] = 5;
    // lst->next[5] = 0;

    assert(lst);
    return 0;
}

int list_dtor(my_list* lst)
{
    fclose(lst->log);
    free(lst->data); lst->data = NULL;
    free(lst->next); lst->next = NULL;
    free(lst->prev); lst->prev = NULL;
    return 0;
}

int list_dump(my_list* lst)
{
    assert(lst);

    fputs("data:\n", lst->log);
    for (int i = 0; i < lst_size; i++)
    {
        fprintf(lst->log, "%4d ", lst->data[i]);
        
    }
    fprintf(lst->log, "\n\n");

    fputs("next:\n", lst->log);
    for (int i = 0; i < lst_size; i++)
    {
      
        fprintf(lst->log, "%4d ", lst->next[i]);
        
    }
    fprintf(lst->log, "\n\n");

    fputs("prev:\n", lst->log);
    for (int i = 0; i < lst_size; i++)
    {
        fprintf(lst->log, "%4d ", lst->prev[i]);
    }
    printf("check log_file\n");
    system("dot -T png log_files//graph_log.dot -o  log_files//graph_log.png");
    printf("Graph have been genirated\n");
    return 0;
}

static int find_free_cell(my_list* lst)
{
    for (int i = 1; i < lst_size; i++)
    {
        if (lst->data[i] == poison_for_lst)
            return i;
    }

    return 0;
}

int insert_lst(my_list* lst, int position, int value)
{
    int free = find_free_cell(lst);
    lst->data[free] = value; //присваиваем пустой ячейке данное значение
    lst->next[free] = position + 1;

    if (position == 0)
        lst->next[position] = 0;
    else
        lst->next[position] = free;

    return 0;
}
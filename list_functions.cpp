#include"list_functions.h"

static int find_free_cell(my_list* lst);

int list_ctor(my_list* lst, int lst_length)
{
    assert(lst);

    lst->length = lst_length;
    lst->size = 0;
    
    lst->log = fopen("log_files/log_dump.txt", "w");
    lst->graph_log = fopen("log_files/graph_log.dot", "w");
    lst->lst_array = (list_elem*)calloc(sizeof(list_elem), lst->length);

    assert(lst->lst_array);

    for (int i = 1; i < lst->length; i++)
    {
        lst->lst_array[i].next = -1;
        lst->lst_array[i].elem = lst_poison;
        lst->lst_array[i].prev = -1;
    }
    
    check_list(lst);
    return 0;
}

int list_dtor(my_list* lst)
{
    check_list(lst);
    fclose(lst->log);
    free(lst->lst_array);
    return 0;
}

static int find_free_cell(my_list* lst)
{
    check_list(lst);
    int i = 0;
    for (; i < lst->length; i++)
    {
        if (lst->lst_array[i].elem == lst_poison)
            return i;
    }

    printf(YELLOW("Couldn't find the place for your element.. sorry\n"));
    printf("on i  = %d\n", i);
    return -1;
}

int insert_lst(my_list* lst, int position, int value)
{
    check_list(lst);
    int free = find_free_cell(lst);
    if(free < 0)
        return 0;
    lst->size++; 
    lst->lst_array[free].elem = value; //присваиваем пустой ячейке данное значение
    lst->lst_array[free].next = position + 1;

    // if (position == 0)
    //     lst->next[position] = 0;
    // else
    lst->lst_array[free].prev = position;
    lst->lst_array[position].next = free;

    return 0;
}

int list_dump(my_list* lst)
{
    check_list(lst);

    fprintf(lst->log, "size   = %d\n", lst->size);
    fprintf(lst->log, "length = %d\n", lst->length);
    fputs("data:\n", lst->log);
    for (int i = 0; i < lst->length; i++)
    {
        fprintf(lst->log, "%4d ", lst->lst_array[i].elem);
        
    }
    fprintf(lst->log, "\n\n");

    fputs("next:\n", lst->log);
    for (int i = 0; i < lst->length; i++)
    {
      
        fprintf(lst->log, "%4d ", lst->lst_array[i].next);
        
    }
    fprintf(lst->log, "\n\n");

    fputs("prev:\n", lst->log);
    for (int i = 0; i < lst->length; i++)
    {
        fprintf(lst->log, "%4d ", lst->lst_array[i].prev);
    }
    fprintf(lst->log, "\n==========================================\n");
    printf(GREEN("check log_file\n"));
    return 0;
}

/*digraph structs {
  rankdir=LR;
  first [shape=record,label="x21 | x22| x23"];
  second [shape=record,label=" x22_1 | x22_2 | x22_3"];
  t [shape=record,label=" x22_1 | x22_2 | x22_3"];
  first -> second;
  second -> t;
}
x1 = elem 
x2 = next 
x3 = prev 
x4 = index 
*/

int graph_dump(my_list* lst)
{
    check_list(lst);
    fprintf(lst->graph_log, "digraph list {\n  rankdir=LR; \n");
    ///////////////////////////////////////////
    int TAIL = lst->lst_array[0].next;
    for (int i = 0; i < lst->length - 2; i++)
    {
        fprintf(lst->graph_log, " %d [shape=record,label= \"index = %d| elem = %d| next = %d| prev = %d \"];\n\t", TAIL, i, lst->lst_array[TAIL].elem, lst->lst_array[TAIL].next, lst->lst_array[TAIL].prev);
        TAIL = lst->lst_array[TAIL].next;
    }
    printf("\n");

    int TAIL_1 = lst->lst_array[0].next;
    for (int i = 0; i < lst->length - 2; i++)
    {
        int TAIL_2 = lst->lst_array[TAIL_1].next;
        fprintf(lst->graph_log, "%d -> %d;\n\t", TAIL_1, TAIL_2);
        TAIL_1 = TAIL_2;
    }

    // int TAIL = lst.lst_array[0].next;
    // printf("TAIL = %d\n", TAIL);
    // for (int i = 0; i < lst.length - 1; i++)
    // {
    //     printf("%4d", lst.lst_array[TAIL].elem);
    //     TAIL = lst.lst_array[TAIL].next;
    // }

    //////////////////////////////////////////////
    fprintf(lst->graph_log, "}\n");

    //system("dot -T png log_files//graph_log.dot -o  log_files//graph_log.png");
    printf(GREEN("Graph have been genirated\n"));
    return 0;
}
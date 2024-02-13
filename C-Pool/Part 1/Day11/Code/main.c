#include "mylist.h"
#include <unistd.h>

int main(int ac, char **av)
{
    linked_list_t *list = NULL;
    int count = 0;
    list = my_params_to_list(ac,av);
    count = my_list_size(list);
    printf("%d",count);
    return 1;
}

#include "libft.h"

int ft_lstsize(t_list *lst)
{
    t_list *tmp;
    tmp = lst;
    int i;
    i = 0;

    while(tmp != 0)
    {
        tmp = tmp -> next;
        i++;
    }
    return (i);
}

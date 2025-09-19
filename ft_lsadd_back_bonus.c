#include "libft.h"

void ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list *tmp;

    if (!lst || !new)
        return ;
    
    if (*lst == NULL)
    {
        *lst = new;
        return ;
    }
    ft_lstlast(*lst) -> next = new;
}


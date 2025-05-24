#include "libunit.h"

void load_test(t_list **l, const char *name, int (*func)(void))
{
    if (!l || !name || !func)
        return;
    ft_lstadd_back(l, ft_lstnew(test_new(name, func)));
}

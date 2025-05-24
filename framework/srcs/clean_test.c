#include "libunit.h"

void clean_tests(t_list **l)
{
    ft_lstclear(l, test_free);
    *l = NULL;
}

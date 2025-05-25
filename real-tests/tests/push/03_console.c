#include "cyclic_list.h"
#include "libunit.h"

int	console_p(void)
{
	t_clst	*list_a;
	t_clst	*list_b;

	list_a = clst_new(5);
	list_b = clst_new(10);
	if (!list_a || !list_b)
		return (-1);
	clst_insert(list_a, 2);
	clst_insert(list_a, 1);
	pa(list_b, list_a);
	if (clst_size(list_a) != 1 || clst_size(list_b) != 1)
	{
		clst_clear(list_a);
		clst_clear(list_b);
		return (-1);
	}
	clst_clear(list_a);
	clst_clear(list_b);
	return (0);
}

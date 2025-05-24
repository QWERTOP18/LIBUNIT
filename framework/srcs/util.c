#include "libunit.h"

void *xmalloc(size_t size)
{
    void *ptr = malloc(size);
    if (!ptr)
    {
        ft_putstr_fd("Memory allocation failed\n", STDERR_FILENO);
        exit(EXIT_FAILURE);
    }
    return ptr;
}

void *test_new(const char *name, int (*func)(void))
{
    t_unittest *test;

    if (!name || !func)
        return NULL;

    test = xmalloc(sizeof(t_unittest));
    test->name = ft_strdup(name);
    test->func = func;
    return test;
}

void test_free(void *test)
{
    if (!test)
        return;

    t_unittest *t = (t_unittest *)test;
    free(t->name);
    free(t);
}

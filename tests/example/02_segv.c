#include "libunit.h"

int segv_test(void)
{
    int *ptr = NULL;
    *ptr = 42;
    return (0);
}

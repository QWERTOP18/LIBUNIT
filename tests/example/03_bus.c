#include "libunit.h"

int bus_test(void)
{
    int *ptr = (int *)0x1;
    *ptr = 42;
    return (0);
}

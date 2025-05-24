#include "libunit.h"

int basic_test(void)
{
    if (1 + 1 != 2)
    {
        return (-1);
    }
    return (0);
}

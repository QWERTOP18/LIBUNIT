#include "libunit.h"
int launch_example();

int main()
{
    int status = 0;
    status |= launch_example();
    return status * -1;
}

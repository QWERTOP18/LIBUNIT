#include "libunit.h"
int launch_rotate();
int launch_swap();
int launch_push();
int launch_reverse_rotate();

int main()
{
    int status = 0;
    status |= launch_rotate();
    return status * -1;
}

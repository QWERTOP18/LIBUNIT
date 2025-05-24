#include "libunit.h"

int basic_test(void);
int segv_test(void);
int bus_test(void);
int ok_test(void);
int ko_test(void);

int launch_example()
{
    t_list *testlist;
    testlist = NULL;
    load_test(&testlist, "Basic test", &basic_test);
    load_test(&testlist, "Segv test", &segv_test);
    load_test(&testlist, "Bus test", &bus_test);
    load_test(&testlist, "OK test", &ok_test);
    load_test(&testlist, "KO test", &ko_test);

    return (launch_tests("EXAMPLE", testlist));
}

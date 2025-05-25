#include "libunit.h"

int run_unittest(void *vtest)
{
    t_unittest *test = (t_unittest *)vtest;

    if (!test || !test->func)
        return -1;

    pid_t pid;

    int status;
    pid = fork();
    if (pid < 0)
    {
        return -1;
    }
    else if (pid == 0)
    {
        alarm(TIMEOUT);
        exit(test->func());
    }

    wait(&status);
    // dprintf(2, "@@@@@@@satus %d\n", status);

    // if (WIFSIGNALED(status))
    // {
    //     ft_dprintf(2, "Test %s terminated by signal %d\n", test->name, WTERMSIG(status)); // debug
    //     return WTERMSIG(status);
    // }
    // else if (WIFEXITED(status))
    // {
    //     // ft_dprintf(2, "Test %s exited with status %d\n", test->name, WEXITSTATUS(status));
    //     return WEXITSTATUS(status);
    // }
    return status;
}

char *str_status(int status)
{
    if (status == 0)
        return GREEN "[OK]" RESET;
    else if (status == SIGSEGV)
        return YELLOW "[SEGV]" RESET;
    else if (status == SIGBUS)
        return YELLOW "[BUS]" RESET;
    else if (status == SIGABRT)
        return YELLOW "[ABRT]" RESET;
    else if (status == SIGFPE)
        return YELLOW "[FPE]" RESET;
    else if (status == SIGILL)
        return YELLOW "[ILL]" RESET;
    else if (status == SIGPIPE)
        return YELLOW "[PIPE]" RESET;
    else if (status == SIGALRM)
        return RED "[TIMEOUT]" RESET;
    else
        return RED "[KO]" RESET;
}

void log_result(const char *func_name, const char *test_name, int result)
{
    // dprintf(2, "@@@@@@@satus %d\n", result);
    dprintf(2, "starting test: %s , %d\n", test_name, result); // debug

    ft_putstr_fd((char *)func_name, 1);
    ft_putstr_fd(": ", 1);
    ft_putstr_fd((char *)test_name, 1);
    ft_putstr_fd(" ", 1);
    ft_putendl_fd(str_status(result), 1);
}

int launch_tests(const char *func_name, t_list *l)
{
    int success = 0;
    int lsize = ft_lstsize(l);
    t_list *current = l;
    while (current)
    {
        t_unittest *test = (t_unittest *)current->data;
        int status = run_unittest(test);
        if (status == 0)
            success++;
        log_result(func_name, test->name, status);
        current = current->next;
    }
    ft_printf("%d/%d tests checked\n", success, lsize);
    clean_tests(&l);
    if (success == lsize)
        return 0;
    return -1;
}

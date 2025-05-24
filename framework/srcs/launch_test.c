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
        status = test->func();
        exit(status);
    }

    wait(&status);
    if (WIFSIGNALED(status))
    {
        ft_dprintf(2, "Test %s terminated by signal %d\n", test->name, WTERMSIG(status)); // debug
        return -WTERMSIG(status);
    }
    else if (WIFEXITED(status))
    {
        // ft_dprintf(2, "Test %s exited with status %d\n", test->name, WEXITSTATUS(status));
        return WEXITSTATUS(status);
    }
    return -1;
}

void log_result(const char *func_name, const char *test_name, int result)
{
    ft_dprintf(2, "starting test: %s , %d\n", test_name, result); // debug
    if (result == 0)
    {
        // ft_printf("%s: %s " GREEN "[OK]" RESET "\n", func_name, test_name);
        ft_putstr_fd((char *)func_name, 2);
        ft_putstr_fd(": ", 2);
        ft_putstr_fd((char *)test_name, 2);
        ft_putstr_fd(" " GREEN "[OK]" RESET "\n", 2);
    }
    else if (result == SIGSEGV)
    {
        // ft_printf("%s: %s " YELLOW "[SEGV]" RESET "\n", func_name, test_name);
        ft_printf("%s: %s " YELLOW "[SEGV]" RESET "\n", func_name, test_name);
    }
    else if (result == SIGBUS)
    {
        ft_printf("%s: %s " YELLOW "[BUS]" RESET "\n", func_name, test_name);
    }
    else if (result == SIGPIPE)
    {
        ft_printf("%s: %s " YELLOW "[PIPE]" RESET "\n", func_name, test_name);
    }
    else
    {
        ft_printf("%s: %s " RED "[KO]" RESET "\n", func_name, test_name);
    }
}

int launch_tests(const char *func_name, t_list *l)
{
    int success = 0;
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
    ft_printf("%d/%d tests checked\n", success, ft_lstsize(l));
    clean_tests(&l);
    if (success == ft_lstsize(l))
        return 0;
    return -1;
}

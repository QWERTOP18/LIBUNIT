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
        status = test->func();
        exit(status);
    }
    else
    {
        waitpid(pid, &status, 0);
        if (WIFEXITED(status))
            return WEXITSTATUS(status);
        else if (WIFSIGNALED(status))
        {
            int signal = WTERMSIG(status);
            if (signal == SIGSEGV)
                return -2; // Segmentation fault
            else if (signal == SIGABRT)
                return -3; // Aborted
            else if (signal == SIGFPE)
                return -4; // Floating point exception
            else if (signal == SIGILL)
                return -5; // Illegal instruction
            else if (signal == SIGBUS)
                return -6; // Bus error
            else
                return -7; // Other signal
        }
        else
        {
            return -11; // Unknown error
        }
    }
}

int launch_tests(const char *func_name, t_list *l)
{
    int count = 0;
    int failed = 0;
    t_list *current = l;
    while (current)
    {
        t_unittest *test = (t_unittest *)current->content;
        if (!test || !test->name || !test->func)
        {
            current = current->next;
            continue;
        }

        int result = run_unittest(test);
        count++;

        if (result == 0)
        {
            ft_putstr_fd(func_name, STDOUT_FILENO);
            ft_putstr_fd(": ", STDOUT_FILENO);
            ft_putstr_fd(test->name, STDOUT_FILENO);
            ft_putstr_fd(" " GREEN "[OK]" RESET "\n", STDOUT_FILENO);
        }
        else
        {
            failed++;
            ft_putstr_fd(func_name, STDOUT_FILENO);
            ft_putstr_fd(": ", STDOUT_FILENO);
            ft_putstr_fd(test->name, STDOUT_FILENO);
            ft_putstr_fd(" " RED "[KO]" RESET "\n", STDOUT_FILENO);
        }
        current = current->next;
    }
    // 1/2 tests checked
    printf("%d/%d tests checked\n", count - failed, count);

    clean_tests(&l);
    return 0;
}

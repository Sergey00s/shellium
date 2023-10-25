#include "build_in.h"



int change_dir(char *path)
{
    char err[100];


    if (chdir(path) == -1)
    {    
        ft_strlcpy(err, "shellium: cd", 100);
        perror(err);
        return 1;
    }
    return 0;
}


int echo(char **args)
{
    int i;

    i = 1;
    while (args[i])
    {
        ft_putstr_fd(args[i], 1);
        if (args[i + 1])
            ft_putstr_fd(" ", 1);
        i++;
    }
    ft_putstr_fd("\n", 1);
    return 0;
}


int pwd(void)
{
    char *path;

    path = getcwd(NULL, 0);
    ft_putstr_fd(path, 1);
    ft_putstr_fd("\n", 1);
    free(path);
    return 0;
}


int exit_shell(char **args)
{
    int i;

    i = 0;
    while (args[i])
        i++;
    if (i == 1)
        exit(0);
    else if (i == 2)
        exit(ft_atoi(args[1]));
    else
    {
        ft_putstr_fd("shellium: exit: too many arguments\n", 2);
        return 1;
    }
    return 0;
}
#include "minishell.h"

int ft_isbuiltin(char *str)
{
    return(ft_strcmp(str, "echo"), ft_strcmp(str, "cd"),\
            ft_strcmp(str, "pwd"), ft_strcmp(str, "export"), \
            ft_strcmp(str, "unset"), ft_strcmp(str, "env"), \
            ft_strcmp(str, "exit"));
}
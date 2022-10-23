/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 18:40:28 by akharraz          #+#    #+#             */
/*   Updated: 2022/10/23 04:50:10 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_pwd(t_env *env)
{
    char pwd[PATH_MAX];
    char *to_free;
    getcwd(pwd, PATH_MAX);
    ft_putendl_fd(pwd, STDOUT_FILENO);
    return (0);
}

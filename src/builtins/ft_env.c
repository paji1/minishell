/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 04:37:50 by akharraz          #+#    #+#             */
/*   Updated: 2022/10/24 05:35:13 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_env(t_env *env)
{
    char    **env_tab;
    int     i;

    i = -1;
    env_tab = env_lst_to_tab(env);
    while (env_tab[++i])
       ft_putendl_fd(env_tab[i], STDOUT_FILENO);
}
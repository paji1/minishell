/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 05:17:34 by akharraz          #+#    #+#             */
/*   Updated: 2022/10/23 06:30:55 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_cd(char  **cmd)
{
    if (cmd[1])
    {
        if (!chdir(cmd[1]))
            ft_putendl_fd("salam", STDOUT_FILENO);
        else
            ft_putendl_fd("not salam", STDOUT_FILENO);
    }
}
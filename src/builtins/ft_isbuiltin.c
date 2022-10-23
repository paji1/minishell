/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isbuiltin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 18:04:17 by akharraz          #+#    #+#             */
/*   Updated: 2022/10/23 07:10:20 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_isbuiltin(char *str)
{
    return(!ft_strcmp(str, "echo") || !ft_strcmp(str, "cd") ||
            !ft_strcmp(str, "pwd") || !ft_strcmp(str, "export") || 
            !ft_strcmp(str, "unset") || !ft_strcmp(str, "env") || 
            !ft_strcmp(str, "exit"));
}

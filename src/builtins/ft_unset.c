/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:22:47 by akharraz          #+#    #+#             */
/*   Updated: 2022/11/13 06:46:23 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_unset(char **cmd ,t_env *env)
{
	int	i;

	i = 0;
	while (cmd[++i])
	{
		remove_env_node(env, cmd[i]);
	}
}
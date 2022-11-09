/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:22:47 by akharraz          #+#    #+#             */
/*   Updated: 2022/10/24 14:31:15 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_unset(char **cmd ,t_env *env)
{
	int	i;

	i = 0;
	printf("welcome to unset:\n");
	while (cmd[++i])
	{
		remove_env_node(env, cmd[i]);
		printf("%s is removed\n", cmd[i]);
	}
}
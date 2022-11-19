/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:22:47 by akharraz          #+#    #+#             */
/*   Updated: 2022/11/18 19:39:00 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_unset(char **cmd, t_env *env)
{
	int		i;
	int		err;
	t_sub	sub;

	i = 0;
	err = 0;
	ft_bzero((void *)&sub, sizeof(t_sub));
	while (cmd[++i])
	{
		if (export_isvalid("unset", cmd[i], &sub) == -1)
			err = 1;
		remove_env_node(env, cmd[i]);
	}
	return (err);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 04:37:50 by akharraz          #+#    #+#             */
/*   Updated: 2022/11/18 19:23:37 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(t_env *env, char **cmd)
{
	t_env_node	*node;

	if (cmd[1])
		return (ft_putendl_fd("minishell: env: \
			only one argumant required", 2), 1);
	node = env->head;
	while (node)
	{
		if (node->is_env)
			printf("%s=%s\n", node->key, node->value);
		node = node->next;
	}
	return (0);
}

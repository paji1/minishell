/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 04:37:50 by akharraz          #+#    #+#             */
/*   Updated: 2022/10/31 19:12:06 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(t_env *env)
{
	t_env_node	*node;

	node = env->head;
	while (node)
	{
		if (node->is_env)
			printf("%s=%s\n", node->key, node->value);
		node = node->next;
	}
	return (0);
}

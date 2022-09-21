/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 23:10:31 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/09/21 23:29:19 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int handle_herdoc(t_node *new)
{
	static t_node *node;

	if (new->token.type == HERDOC)
		return node = new, 0;
	if (!node)
		return 1;
	new->token.type = DELIMITER;
	char *str = readline(NULL);
	printf("%s\n", str);
	return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 19:23:40 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/08/16 04:40:31 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//                      +
//                 /        \                         /
//               *           +
//              /  \        /  \                      /
//            8    3       *   1
//                       /  \                         /
//                      -4  8

// (8 * 3) + (((-4) * 8) + 1)


int order(int token)
{
	if (token  == subtraction)
		return 0;
	else if (token == addition)
		return 1;
	else if (token == multiply)
		return 2;
	else if (token == division)
		return 3;
	else
		return -1;
}

void parse(char **s, t_node **node)
{
	int 	i;

	i = -1;
	while (s[++i])
	{
			if (i == 0)
				(*node) = new_node(atoi(s[i++]), NUM);
			if (i++ != 1 && *node && order(s[i - 1][0]) > order((*node)->data))
				nested(node, s[i - 1][0], atoi(s[i]));
			else
				new_head(node, s[i - 1][0], ft_atoi(s[i]));
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_types.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 23:15:58 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/08/09 23:19:04 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check_types(char *s)
{
	char *op;

	op = "-+*/";
	while(*op)
	{
		if (ft_strchr(s, *op))
			return (TOKEN);
		op++;
	}
	return (NUM);
}
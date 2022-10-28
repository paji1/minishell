/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 23:30:16 by akharraz          #+#    #+#             */
/*   Updated: 2022/10/28 11:50:01 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	export_isvalid(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (!ft_isalnum(cmd[i]) && cmd[i] != '=')
			printf("minishell: export: `%s': not a valid identifier\n", cmd);
		if (cmd[i] == '=')
			break;
		i++;
	}
	return (0);
}

void    ft_export(char **cmd, t_env *env)
{
	int i;

	i = 1;
	if (!cmd[i])
		export_print(env);
	while (cmd[i])
	{
		export_isvalid(cmd[i]);
		i++;
	}
}

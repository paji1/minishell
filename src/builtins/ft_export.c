/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 23:30:16 by akharraz          #+#    #+#             */
/*   Updated: 2022/10/29 07:35:40 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	export_is_append(char *cmd, int i)
{
	return (cmd[i] == '+' && cmd[i + 1] == '=');
}

static int	export_isvalid(char *cmd)
{
	int	i;

	i = 1;
	if (!(ft_isalpha(cmd[0]) || cmd[0] == '_'))
		return (printf("minishell: export: `%s': not a valid identifier\n", cmd), -1);
	while (cmd[i])
	{
		if (!ft_isalnum(cmd[i]) && cmd[i] != '=' && cmd[i] != '_')
			return (printf("minishell: export: `%s': not a valid identifier\n", cmd), 1);
		if (cmd[i] == '=')
			return (1);
		i++;
		if (export_is_append(cmd, i))
			return (2);
	}
	return (3);
}

void	ft_export(char **cmd, t_env *env)
{
	int	i;
	int	mode;

	i = 1;
	if (!cmd[i])
		export_print(env);
	while (cmd[i])
	{
		mode = export_isvalid(cmd[i]);
		if (mode == 3)
			add_or_change_value(env, ft_strdup(cmd[i]), "");
		if (mode == 1)
			;
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 18:40:28 by akharraz          #+#    #+#             */
/*   Updated: 2022/11/18 20:05:30 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(t_env *env)
{
	char	pwd[PATH_MAX];
	char	*to_free;

	if (!getcwd(pwd, PATH_MAX))
	{
		to_free = get_value(env, "PWD");
		ft_putendl_fd(to_free, STDOUT_FILENO);
		free(to_free);
		return (0);
	}
	ft_putendl_fd(pwd, STDOUT_FILENO);
	return (0);
}

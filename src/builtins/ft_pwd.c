/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 18:40:28 by akharraz          #+#    #+#             */
/*   Updated: 2022/11/18 19:42:43 by tel-mouh         ###   ########.fr       */
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
		return 0;
	}
	ft_putendl_fd(pwd, STDOUT_FILENO);
	return (0);
}

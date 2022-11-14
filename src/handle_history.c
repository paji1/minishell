/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_history.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 20:31:52 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/11/14 20:32:25 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void old_history(int fd)
{
	char *s;
	char *trim;

	s = get_next_line(fd);
	while (s)
	{
		trim = ft_strtrim(s,"\n");
		free(s);
		s = trim;
		add_history(s);
		free(s);
		s = get_next_line(fd);
	}
}

int create_history_file(t_vars *vars)
{
	char	*home;
	char	*temp;
	int		fd;

	home = get_value(vars->env, "HOME");
	if (!home)
		return 0;
	temp = ft_strjoin(home, "/.minishell_history");
	free(home);
	fd = open(temp, O_CREAT | O_RDWR | O_APPEND, 0777);
	free(temp);
	if (fd < 0)
		return 0;
	old_history(fd);
	return fd;
}

void handle_history(t_vars *vars)
{
	vars->fd_history = create_history_file(vars);
}

void add_history_write(t_vars *vars)
{
	add_history(vars->buff);
	if (vars->fd_history)
		ft_putendl_fd(vars->buff, vars->fd_history);
}
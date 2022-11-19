/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_close.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 16:11:06 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/11/18 21:55:58 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_before(int fd)
{
	while (fd > 2)
	{
		close(fd);
		fd--;
	}
}

int	close_in_parent(t_node *node)
{
	int	fd;

	fd = 0;
	if (node->file_in == 0 && node->file_out == 1)
		return (0);
	if (is_first(node))
	{	
		if (node->file_out != STDOUT_FILENO)
			close(node->file_out);
	}
	else
	{
		if (node->file_in != STDIN_FILENO)
			close(node->file_in);
		if (node->file_out != STDOUT_FILENO)
			close(node->file_out);
	}
	return (0);
}

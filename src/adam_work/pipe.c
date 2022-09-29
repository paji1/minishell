/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42->fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 19:12:29 by akharraz          #+#    #+#             */
/*   Updated: 2022/09/21 13:25:57 by akharraz         ###   ########->fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int creat_pipe(t_list *node)
{
	if (node->taha == 0)
	{
		if (pipe(node->fds->fd) == -1)
			return (perror("pipe"), -1);
	}
	if (node->previous)
	{
		node->fds->fd_out = node->previous->fds->fd[0];
	}
	return (0);
}

static int	dup_close(t_list *node, int i)
{
	if (i == 0)
	{
		dup2(node->fds->fd[1], STDOUT_FILENO);
		close(node->fds->fd[1]);
		close(node->fds->fd[0]);
	}
	if (i > 0)
	{
		dup2(node->fds->fd_out, STDIN_FILENO);
		dup2(node->fds->fd[1], STDOUT_FILENO);
		close(node->fds->fd[1]);
		close(node->fds->fd_out);
	}
	if (i == -1)
	{
		dup2(node->fds->fd_out, STDIN_FILENO);
		close(node->fds->fd_out);
	}
	return (0);
}

/**
 * @brief execute a command
 * 
 * @param cmd the command to execute
 * @param fd two ends of a pipe
 * @param side on the left or on the right side of pipe
 * @return int : 0 in success , -1 in failure 
 */
static int	ft_execute_command(t_list *node)
{
	pid_t		pid;
	int			child_exit_methode;
	static int	i;

	if (node->taha == 1)
		i = -1;
	printf("{{%d}}\n", i);
	pid = fork();
	if (pid == -1)
		return (printf("error fork\n"), -1);
	if (pid == 0)
	{
		dup_close(node, i);
		if (execve(node->cmd[0], node->cmd, NULL) == -1)
		{
			write(2, "error execve\n", 13);
			exit (1);
		}
	}
	if (pid > 0)
	{
		if (i == 0)
			close(node->fds->fd[1]);
		if (i > 0)
		{
			close(node->fds->fd_out);
			// close(node->fds->fd[0]);
			close(node->fds->fd[1]);
		}
		if (i == -1)
			close(node->fds->fd_out);
		if (waitpid(-1, &child_exit_methode, 0) == -1)
			return (write(2, "error waitpid\n", 14), -1);
		if (!WIFEXITED(child_exit_methode))
			return (write(2, "something went wrong!\n", 22), -1);
		i++;
	}
	return (0);
}


int	pipe_execution(t_list *node)
{

	if (node->taha == 1)
	{
		creat_pipe(node);
		ft_execute_command(node);
	}
	if (node->taha == 0)
	{
		creat_pipe(node);
		ft_execute_command(node);
		pipe_execution(node->next);
	}
	return (0);
}

 int	main(void)
{
	t_list *list;
	t_list *list1;
	t_list *list2;
	char cmd0[] = {"/bin/ls -l"};
	char cmd1[] = {"/usr/bin/wc -l"};
	char cmd2[] = {"/bin/ps"};

	list = ft_lstnew(cmd0, 0);
	list1 = ft_lstnew(cmd1, 0);
	list2 = ft_lstnew(cmd2, 1);

	ft_lstadd_back(&list, list1);
	ft_lstadd_back(&list, list2);
	// ft_lstadd_back(&list, list2);
	
	if (pipe_execution(list) == -1)
		return (write(2, "pipe execution error!!\n", 24), 1);
	return (0);
}

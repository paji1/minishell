/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 19:12:29 by akharraz          #+#    #+#             */
/*   Updated: 2022/09/21 13:25:57 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

#define RIGHT 69
#define LEFT 96
/**
 * @brief duplicate pipe'e end file descriptors
 * 
 * @param side wich end of pipe
 * @param fd 
 * @return int : 0 in success , -1 in failure
 */
int dup_close(int side, int *fd)
{
	int	res;

	res = 0;
	if (side == LEFT)
		res = dup2(fd[1], 1);
	if (side == RIGHT)
		res = dup2(fd[0], 0);
	if (res == -1 || close(fd[1]) == -1 || close(fd[0]) == -1)
		return (-1);
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
static int	ft_execute_command(char **cmd, int *fd, int side)
{
	pid_t	pid;
	int		child_exit_methode;

	pid = fork();
	if (pid == -1)
		return (printf("error fork\n"), -1);
	if (pid == 0)
	{
		dup_close(side, fd);
		if (execve(cmd[0], cmd, NULL) == -1)
		{
			write(2, "error execve\n", 13);
			exit (1);
		}
	}
	if (pid > 0)
	{
		if (side == RIGHT)
			dup_close(0, fd);
		if (waitpid(-1, &child_exit_methode, 0) == -1)
			return (write(2, "error waitpid\n", 14), -1);
		if (!WIFEXITED(child_exit_methode))
			return (write(2, "something went wrong!\n", 22), -1);
	}
	return (0);
}

/**
 * @brief execute two function in which the cmd0 output becomes cmd1 input
 * 
 * @param cmd0 first command to execute
 * @param cmd1 second command to execute
 * @return int : 0 in success , -1 in failure 
 */
static int	pipe_execution(char **cmd0, char **cmd1)
{
	int	fd[2];

	if (pipe(fd) == -1)
		return (-1);
	if (ft_execute_command(cmd0, fd, LEFT) == -1 || ft_execute_command(cmd1, fd, RIGHT) == -1)
		return (-1);
	return (0);
}

int	main(void)
{
	char *cmd0[] = {"/bin/ls", "-l", NULL};
	char *cmd1[] = {"/usr/bin/wc", "-l", NULL};

	if (pipe_execution(cmd0, cmd1) == -1)
		return (write(2, "pipe execution error!!\n", 24), 1);
	return (0);
}

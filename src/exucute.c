/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exucute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 21:17:18 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/10/06 19:10:56 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int execute_cmd(t_node *node, char **env)
{
	char **cmd;
	char *path;
	int		error;

	if (node->token.type != CMD)
		return 0;
	cmd = qto_tab(node);
	if(!cmd)
		return -1;
	error = check_cmd(node, env, &path);
	if (error == 3)
		return perror("function Not found"), -2;
	if (error == 0)
		return perror("permission dnied"), -4;
	if (execve(path, cmd, env) == -1)
		return -3;
	return 0;
}



int is_first(t_node *node)
{
	return (node->file_in == node->file_out - 1);
}

void close_before(int fd)
{
	while (fd > 2)
	{
		close(fd);
		fd--;
	}
}

int close_in_parent(t_node *node)
{
	int fd;
	
	fd = 0;
	if (node->file_in == 0 && node->file_out == 1)
		return 0;
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
	return 0;
	
}

int exucute_cmd(t_node *node, char **env)
{
	int pid;

	pid = fork();
	if (pid == -1)
		return -1;
	if (pid)
		return pid;
	if (is_first(node))
	{
		close_before(node->file_in);
		dup2(node->file_out, 1);
		if (node->file_out != STDOUT_FILENO)
			close(node->file_out);
	}
	if (!is_first(node))
	{
		dup2(node->file_in, 0);
		
		dup2(node->file_out, 1);
		close_before(node->file_out);
	}
	if (execute_cmd(node, env) < 0)
		return -1;
	return 0;
}


static int handle_exblock(t_node *node, char **env)
{
	int pid;
	if (is_sub(node) || node->node_type != BLOCK)
		return 0;
	if (exucute_cmd(node, env)  < 0)
		return 0;
	close_in_parent(node);
	return 1;
}

int	handle_expipe(t_node *node)
{
	int fd[2];

	if (node->token.type != PIP)
		return 0;
	if (pipe(fd) == -1)
		return -1;
	node->right->file_in = fd[0];
	node->right->file_out = node->file_out;
	node->left->file_in = fd[0];
	node->left->file_out = fd[1];
	return 0;
}

int handle_bin(t_node *node)
{
	if (node->token.type != AND && node->token.type != OR)
		return 0;
	node->left->file_in =  node->file_in;
	node->right->file_out = node->file_out;
	node->left->file_out = node->file_out;
	
}

static int handle_exop(t_node *node, char **env)
{
	if (!is_sub(node) && node->node_type != OP)
		return 0;
	handle_expipe(node);
	handle_bin(node);
}


void exucute(t_node *root, t_vars *vars)
{
	if (root == NULL)
		return ;
	if (handle_exblock(root, vars->env))
		vars->pid_num++;
	handle_exop(root, vars->env);
	exucute(root->left, vars);
	// if (root->token.type == AND)
	// 	wait();
	exucute(root->right, vars);
}
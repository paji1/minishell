/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 08:33:43 by akharraz          #+#    #+#             */
/*   Updated: 2022/11/19 05:31:47 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

// #####################################################
// ###                  bin                          ###
// #####################################################
int		wait_for_bin(t_node *node);
int		bin_status(t_node *node);

// #####################################################
// ###                  close                        ###
// #####################################################
void	close_before(int fd);
int		close_in_parent(t_node *node);

// #####################################################
// ###                  cmd                          ###
// #####################################################
int		execute_cmd(t_node *node, t_env *env);
int		fork_cmd(t_node *node, t_env *env);
int		check_cmd(t_node *node, t_env *env, char **path);
int		check_permission(char *cmd);
int		check_if_path(char *cmd);
int		check_if_dir(char *path);
void	print_cnf(char *key);

// #####################################################
// ###                  subshell                     ###
// #####################################################
int		handle_sub(t_node *node, t_vars *vars);

// #####################################################
// ###                  utils                        ###
// #####################################################
int		is_first(t_node *node);
// #####################################################
// ###                  execute                      ###
// #####################################################
int		handle_exop(t_node *node);
int		handle_exblock(t_node *node, t_env *env);
int		handle_expipe(t_node *node);
int		print_to_error(char *str, char *error, int re);

// #####################################################
// ###                  redirection                 ###
// #####################################################

int		handle_redirection(t_node *node, t_env *env);
int		case_so(t_node *node, t_nodeq *q);
int		case_si(t_node *node, t_nodeq *q);
int		case_herd(t_node *node, t_nodeq *q, t_env *env);
char	*get_name(int fd);
void	expand_herdoc(int *fd, t_env *env);
// #####################################################
// ###                  builtins                     ###
// #####################################################

int		execute_builtins(t_node *node, t_env *env);

// #####################################################
// ###                  env                          ###
// #####################################################

int		add_or_change_value(t_env *env, char *key, char *value);

#endif // EXECUTE_H

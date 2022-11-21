/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 23:29:53 by akharraz          #+#    #+#             */
/*   Updated: 2022/11/21 07:45:01 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

int			ft_isbuiltin(char *str);
int			ft_cd(char **cmd, t_env *env);
int			ft_echo(char **cmd);
int			ft_pwd(t_env *env);
int			ft_env(t_env *env, char **cmd);
int			ft_unset(char **cmd, t_env *env);
int			ft_export(char **cmd, t_env *env);
int			ft_exit(char **cmd);

// #####################################################
// ###               export_funcs                    ###
// #####################################################
void		export_print(t_env *env);
char		*export_strjoin(char *s1, char *s2);
int			export_isvalid(char *name, char *cmd, t_sub *sub);
t_env_node	*search_env_node(t_env *env, char *key);
void		mode_init(t_export *export, t_env *env, char **cmd);
#endif /* !BUILTINS_H */
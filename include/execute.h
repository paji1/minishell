#ifndef EXECUTE_H
# define EXECUTE_H
// #####################################################
// ###                  bin                          ###
// #####################################################
int handle_bin(t_node *node);
int wait_for_bin(t_node *node);
int bin_status(t_node *node, t_vars *vars);

// #####################################################
// ###                  close                        ###
// #####################################################
void close_before(int fd);
int close_in_parent(t_node *node);


// #####################################################
// ###                  cmd                          ###
// #####################################################
int		execute_cmd(t_node *node, t_env *env);
int		fork_cmd(t_node *node, t_env *env);
int		check_cmd(t_node *node, t_env *env, char **path);
int		check_permission(char *cmd);

// #####################################################
// ###                  subshell                     ###
// #####################################################
int handle_sub(t_node *node, t_vars *vars);

// #####################################################
// ###                  utils                        ###
// #####################################################
int is_first(t_node *node);
// #####################################################
// ###                  execute                      ###
// #####################################################
int handle_exop(t_node *node, char **env);
int handle_exblock(t_node *node, t_env *env);
int	handle_expipe(t_node *node);

// #####################################################
// ###                  resdirection                 ###
// #####################################################

int		handle_redirection(t_node *node);
// #####################################################
// ###                  builtins                     ###
// #####################################################

int     execute_builtins(t_node *node, t_env *env);

// #####################################################
// ###                  env                          ###
// #####################################################

int     add_or_change_value(t_env *env, char *key, char *value);

#endif // EXECUTE_H

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signal_herdoc.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 03:39:51 by akharraz          #+#    #+#             */
/*   Updated: 2022/11/21 07:11:42 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	herdoc_signal(int sig, siginfo_t *info, void *data)
{
	(void)sig, (void)info, (void)data;
	hide_ctrl_c();
	printf("\e[?25l");
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	g_exit.status = 130;
	g_exit.status_signal_herdoc = 1;
	printf("\e[?25h");
}

void	ignore_signal_herdoc(void)
{
	struct sigaction	act;

	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = &herdoc_signal;
	sigaction(SIGINT, &act, NULL);
	// sigaction(SIGQUIT, &act, NULL);
}

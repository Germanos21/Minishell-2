/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:35:30 by german            #+#    #+#             */
/*   Updated: 2023/02/20 16:15:37 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	quit_func(int signum)
{
	(void)signum;
	g_appinfo.exit_status = 131;
	ft_printf("Quit\n");
}

void	define_input_signals(void)
{
	signal(SIGINT, &ctrl_c);
	signal(SIGQUIT, SIG_IGN);
}

void	define_exec_signals(void)
{
	signal(SIGINT, ctrl_c);
	signal(SIGQUIT, quit_func);
}

void	ctrl_d(void)
{
	g_appinfo.exit_status = 131;
	ft_printf("Exit");
	exit_app(g_appinfo.exit_status);
}

void	ctrl_c(int sig)
{
	int		ret;

	(void)sig;
	g_appinfo.exit_status = 130;
	ret = waitpid(-1, NULL, WNOHANG);
	if (ret == -1 && sig == SIGINT)
	{
		g_appinfo.exit_status = 1;
		update_exitstatus();
		rl_on_new_line();
		rl_redisplay();
		ft_putstr_fd("  \b\b", 2);
		write(2, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

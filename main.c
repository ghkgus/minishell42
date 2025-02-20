/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwasong <hwasong@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:53:14 by hwasong           #+#    #+#             */
/*   Updated: 2025/02/19 15:53:16 by hwasong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **envp)
{
	t_shell shell;

	if (ac != 1)
	{
		show_error_msg(ac, av);
		return (0);
	}
	init_env(&shell, envp);
	minishell_loop(&shell);
	free_shell(&shell);

}

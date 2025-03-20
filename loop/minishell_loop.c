/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwasong <hwasong@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:53:58 by hwasong           #+#    #+#             */
/*   Updated: 2025/02/21 14:53:59 by hwasong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	minishell_loop(t_shell *shell, char **envp)
{
	char	*input;

	set_signal();
	while (1)
	{
		input = prompt_read();
		get_parsing_info(shell, input); // 여기에 shell -> process_list 의 정보를 담아 주면 됨
		execute_commands(shell, envp);
		free_process(shell -> process_list, input);
	}
}

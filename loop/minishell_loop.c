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

void	minishell_loop(t_shell *shell)
{
	char			*input;
	t_process_list	*process_list;

	while (1)
	{
		// 시그널 설정
		input = prompt_read(); // 사용자 입력 받기
		if (!input)
			break;
		
		process_list = get_parsing_info(shell, input);
		execute_commands(shell, process_list);
		free(input);
	}
}

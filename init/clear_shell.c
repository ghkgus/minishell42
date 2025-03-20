/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_shell.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwasong <hwasong@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 20:18:39 by hwasong           #+#    #+#             */
/*   Updated: 2025/03/20 20:18:40 by hwasong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void free_shell(t_shell *shell)
{
	clear_envp_list(shell -> envp);
}

void free_process(t_process_list *process_list, char *input)
{
	t_process	*process;
	t_process	*tmp;

	process = process_list -> head;
	while (process)
	{
		tmp = process -> next;
		free(process -> av);
		free(process);
		process = tmp;
	}
	free(process_list);
	free(input);
}

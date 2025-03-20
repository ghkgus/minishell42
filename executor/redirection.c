/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwasong <hwasong@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:55:18 by hwasong           #+#    #+#             */
/*   Updated: 2025/02/21 14:55:20 by hwasong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	setup_redirection(t_process *process)
{
	if (process -> in != STDIN_FILENO)
	{
		dup2(process -> in, STDIN_FILENO);
	}
	if (process -> out != STDOUT_FILENO)
	{
		dup2(process -> out, STDOUT_FILENO);
	}
}


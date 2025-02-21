/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwasong <hwasong@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:54:05 by hwasong           #+#    #+#             */
/*   Updated: 2025/02/21 14:54:06 by hwasong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char *prompt_read(void)
{
	char	*input;

	input = readline("minishell$ ");
	if (!input)
	{
		exit_msg();
		return NULL;
	}

	add_history(input);
	return input;
}

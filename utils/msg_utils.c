/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwasong <hwasong@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 16:21:43 by hwasong           #+#    #+#             */
/*   Updated: 2025/02/21 16:21:45 by hwasong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	show_error_msg(ac, av)
{
	(void) ac;
	(void) av;
	printf("다시 입력"); // 굳이 해야하나..?
}

void	exit_msg()
{
	printf("exit\n");
}
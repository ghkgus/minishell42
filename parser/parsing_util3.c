/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_util3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikim2 <yikim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:18:18 by yikim2            #+#    #+#             */
/*   Updated: 2025/02/18 18:03:28 by yikim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	is_char(char c, char d)
{
	if (c > ' ' && c < 127 && !is_special_char(c, d) && !is_quote(c, d))
		return (1);
	return (0);
}

int	is_quote(char c, char d)
{
	if ((c == '\'' || c == '\"') && d != '\\')
		return (1);
	return (0);
}

int	is_special_char(char c, char d)
{
	if ((c == '|' || c == '<' || c == '>') && d != '\\')
		return (1);
	return (0);
}

int is_space(char c) {
    return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f');
}

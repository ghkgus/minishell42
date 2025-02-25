/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwasong <hwasong@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:59:35 by hwasong           #+#    #+#             */
/*   Updated: 2024/03/14 23:14:26 by hwasong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	char	*str;
	size_t	num;
	size_t	i;

	i = 0;
	num = n * size;
	if (!num)
		return (malloc(0));
	if (num / size != n)
		return (NULL);
	str = (char *)malloc(n * size);
	if (!str)
		return (NULL);
	while (i < num)
		str[i++] = 0;
	return ((void *)str);
}

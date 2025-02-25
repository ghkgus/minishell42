/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwasong <hwasong@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 19:55:00 by hwasong           #+#    #+#             */
/*   Updated: 2024/02/29 21:03:40 by hwasong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	word;
	size_t			i;

	i = 0;
	str = (unsigned char *)s;
	word = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == word)
			return ((void *)(str + i));
		i++;
	}
	return (NULL);
}

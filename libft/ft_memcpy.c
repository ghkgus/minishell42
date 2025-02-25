/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwasong <hwasong@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:55:14 by hwasong           #+#    #+#             */
/*   Updated: 2024/03/18 19:39:22 by hwasong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*str;
	unsigned char	*str1;
	size_t			i;

	i = 0;
	str = (unsigned char *)dest;
	str1 = (unsigned char *)src;
	if (str == NULL && str1 == NULL)
		return (NULL);
	while (i < n)
	{
		str[i] = str1[i];
		i++;
	}
	return (dest);
}

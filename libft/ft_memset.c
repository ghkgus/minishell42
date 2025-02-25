/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwasong <hwasong@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:11:40 by hwasong           #+#    #+#             */
/*   Updated: 2024/02/27 17:10:26 by hwasong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	unsigned char	*dest;
	size_t			i;

	dest = (unsigned char *)ptr;
	i = 0;
	while (i < num)
	{
		dest[i] = (unsigned char)value;
		i++;
	}
	return (ptr);
}

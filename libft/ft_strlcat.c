/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwasong <hwasong@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:10:26 by hwasong           #+#    #+#             */
/*   Updated: 2024/03/09 16:13:56 by hwasong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	i = 0;
	if (!dst && size == 0)
		return (ft_strlen(src));
	dst_len = ft_strlen((const char *)dst);
	src_len = ft_strlen(src);
	if (size < dst_len + 1)
		return (src_len + size);
	else if (size > dst_len + 1)
	{
		while (src[i] && dst_len + i + 1 < size)
		{
			dst[dst_len + i] = src[i];
			i++;
		}
	}
	dst[dst_len + i] = '\0';
	return (src_len + dst_len);
}

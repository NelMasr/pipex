/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-masr <nel-masr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 10:48:40 by nel-masr          #+#    #+#             */
/*   Updated: 2020/11/18 17:07:29 by nel-masr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned	char	*dst_c;
	unsigned	char	*src_c;
	size_t				i;

	dst_c = (unsigned char*)dst;
	src_c = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		dst_c[i] = src_c[i];
		if (dst_c[i] == (unsigned char)c)
			return ((void *)(dst + i + 1));
		i++;
	}
	return (NULL);
}

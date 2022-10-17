/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-masr <nel-masr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 10:49:30 by nel-masr          #+#    #+#             */
/*   Updated: 2020/11/18 17:09:39 by nel-masr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void *clean_dst;

	if (!dst && !src)
		return (NULL);
	clean_dst = dst;
	while (n > 0)
	{
		*((char *)dst++) = *((char *)src++);
		n--;
	}
	return (clean_dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-masr <nel-masr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 14:44:26 by nel-masr          #+#    #+#             */
/*   Updated: 2020/11/18 17:02:23 by nel-masr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	char	*aldst;
	size_t	sum;

	sum = nmemb * size;
	if (!(aldst = malloc(sum)))
		return (NULL);
	i = 0;
	while (sum-- > 0)
	{
		aldst[i] = 0;
		i++;
	}
	return ((void *)aldst);
}

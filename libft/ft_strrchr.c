/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-masr <nel-masr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 18:41:12 by nel-masr          #+#    #+#             */
/*   Updated: 2020/11/18 17:17:10 by nel-masr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned	int	i;
	char			*reverse;

	i = 0;
	reverse = NULL;
	while (s[i])
	{
		if (s[i] == c)
			reverse = (char *)&s[i];
		i++;
	}
	if (s[i] == c)
		return ((char *)&s[i]);
	return (reverse);
}

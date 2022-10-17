/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-masr <nel-masr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 17:23:15 by nel-masr          #+#    #+#             */
/*   Updated: 2021/11/17 11:18:43 by nel-masr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ptr;
	size_t			i;
	unsigned	int	strlen_s;

	if (!s)
		return (NULL);
	i = 0;
	strlen_s = ft_strlen(s);
	if (strlen_s < start)
	{
		if (!(ptr = malloc(sizeof(char) * 1)))
			return (NULL);
		ptr[i] = '\0';
		return (ptr);
	}
	if (!(ptr = malloc((len + 1) * sizeof(char))))
		return (NULL);
	while (i < len)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

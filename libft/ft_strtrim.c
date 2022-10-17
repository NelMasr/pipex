/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-masr <nel-masr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 12:00:31 by nel-masr          #+#    #+#             */
/*   Updated: 2020/11/23 17:14:41 by nel-masr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	is_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int				i;
	unsigned	int	new_size;
	char			*trimmed;
	char			*trimmed_s;
	char			*trimmed_e;

	if (!s1)
		return (NULL);
	i = 0;
	while (s1[i] && (is_set(s1[i], set) == 1))
		i++;
	trimmed_s = (char *)&s1[i];
	i = ft_strlen(s1) - 1;
	while (i >= 0 && (is_set(s1[i], set) == 1))
		i--;
	trimmed_e = (char *)&s1[i];
	new_size = trimmed_e - trimmed_s + 2;
	if (!(trimmed = malloc(sizeof(char) * new_size)))
		return (NULL);
	ft_strlcpy(trimmed, trimmed_s, new_size);
	return (trimmed);
}

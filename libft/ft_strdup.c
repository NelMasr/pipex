/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-masr <nel-masr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 15:18:15 by nel-masr          #+#    #+#             */
/*   Updated: 2020/11/18 17:11:33 by nel-masr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		j;
	char	*target;

	i = 0;
	j = 0;
	while (s[j])
		j++;
	if (!(target = malloc((j + 1) * sizeof(char))))
		return (NULL);
	while (s[i])
	{
		target[i] = s[i];
		i++;
	}
	target[i] = '\0';
	return (target);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-masr <nel-masr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 18:08:38 by nel-masr          #+#    #+#             */
/*   Updated: 2020/11/20 17:08:30 by nel-masr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		numlen(long int nb, int sign)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		nb *= -1;
	while (nb > 0)
	{
		i++;
		nb /= 10;
	}
	if (sign == -1)
		i++;
	return (i);
}

void	convert_to_char(long int nb, int sign, char *result, int len)
{
	int	start;

	start = 0;
	result[len] = '\0';
	len -= 1;
	while (len >= 0)
	{
		result[len] = nb % 10 + '0';
		nb /= 10;
		len--;
	}
	if (sign == -1)
		result[start] = '-';
}

char	*ft_itoa(int n)
{
	long int	nb;
	int			len;
	int			sign;
	char		*result;

	sign = 1;
	if (n < 0)
	{
		nb = (long int)n * (-1);
		sign = -1;
	}
	else
		nb = n;
	len = numlen(nb, sign);
	if (!(result = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	convert_to_char(nb, sign, result, len);
	return (result);
}

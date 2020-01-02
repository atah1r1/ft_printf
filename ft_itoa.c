/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:46:43 by atahiri           #+#    #+#             */
/*   Updated: 2019/12/26 15:19:03 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_reverse(char *str)
{
	int		i;
	int		len;
	int		temp;

	i = 0;
	len = 0;
	while (str[len])
		len++;
	len -= 1;
	if (str[0] == '-')
		i = 1;
	while (i < len)
	{
		temp = str[i];
		str[i] = str[len];
		str[len] = temp;
		i++;
		len--;
	}
	return ((char)str);
}

int		ft_lenint(long x)
{
	int		sign;
	int		i;

	if (x == 0)
		return (1);
	i = 0;
	sign = 0;
	if (x < 0)
	{
		x *= -1;
		sign = 1;
	}
	while (x > 0)
	{
		x /= 10;
		i++;
	}
	return (i + sign);
}

char	*ft_itoa(long n)
{
	long	nb;
	int		i;
	int		len;
	char	*str;

	i = 0;
	nb = n;
	len = ft_lenint(nb);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (nb < 0)
	{
		str[i] = '-';
		i++;
		nb *= (-1);
	}
	while (i < len)
	{
		str[i] = (nb % 10) + '0';
		nb /= 10;
		i++;
	}
	str[i] = '\0';
	ft_reverse(str);
	return ((char*)str);
}

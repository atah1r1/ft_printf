/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_zero.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 15:51:07 by atahiri           #+#    #+#             */
/*   Updated: 2019/12/28 16:07:34 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	if_zero(t_struct *f, unsigned int out_hexa, char *s)
{
	if (out_hexa == 0 && f->dot == 1 && f->width > 0 &&
	(f->precision == 0 || f->precision == -1))
		s = "";
	else if (out_hexa == 0)
		s = "0";
}

int		plug(t_struct *f, unsigned int hexa_len, char *s)
{
	if (f->width == -1 && f->precision == -1)
	{
		f->nprinted += write(1, s, hexa_len);
		return (1);
	}
	return (0);
}

int		print_hexa(char *s)
{
	unsigned int	ret;
	int				i;

	i = 0;
	ret = 0;
	if (ft_strlen(s) != 0)
	{
		while (s[i] != '\0')
			ret += write(1, &s[i++], 1);
	}
	return (ret);
}

char	*ft_strrev(char *str)
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
	return (str);
}

int		percent(t_struct *f)
{
	int a;

	a = ' ';
	if (f->minus == 0)
	{
		if (f->zero == 1)
			a = '0';
		while (f->width-- > 1)
			f->nprinted += write(1, &a, 1);
		f->nprinted += write(1, "%", 1);
	}
	else
	{
		f->nprinted += write(1, "%", 1);
		while (f->width-- > 1)
			f->nprinted += write(1, " ", 1);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 15:43:03 by atahiri           #+#    #+#             */
/*   Updated: 2019/12/25 17:48:17 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			zero_input_u(t_struct *f, unsigned int out_int)
{
	if (out_int == 0 && f->dot == 1 && f->width > 0 &&
		(f->precision == -1 || f->precision == 0))
	{
		while (f->width-- > 0)
			f->nprinted += write(1, " ", 1);
		return (1);
	}
	else if (out_int == 0 && f->dot == 1 &&
			(f->precision == 0 || f->precision == -1))
	{
		write(1, "", 1);
		return (1);
	}
	return (0);
}

int			is_unsigned(t_struct *list, va_list ap)
{
	unsigned int	out_unsi;
	unsigned int	unsi_len;
	char			*s;

	out_unsi = (unsigned int)va_arg(ap, unsigned int);
	unsi_len = ft_intlen(out_unsi);
	s = ft_itoa(out_unsi);
	if (zero_input(list, out_unsi) == 1)
		return (0);
	if (list->width == -1 && list->precision == -1)
	{
		list->nprinted += write(1, s, unsi_len);
		return (0);
	}
	else
	{
		precision_handling(list, unsi_len);
		if (list->minus == 1)
			unsi_right(list, s, unsi_len);
		else
			unsi_left(list, s, unsi_len);
	}
	free(s);
	return (0);
}

void		precision_handling(t_struct *f, unsigned int unsi_len)
{
	if (f->dot && (f->precision > (int)unsi_len))
		f->precision -= unsi_len;
	else
		f->precision = 0;
	f->width = f->width - (f->precision + unsi_len);
}

void		unsi_right(t_struct *f, char *s, unsigned int unsi_len)
{
	while (f->precision-- > 0)
		f->nprinted += write(1, "0", 1);
	f->nprinted += write(1, s, unsi_len);
	while (f->width-- > 0)
		f->nprinted += write(1, " ", 1);
}

void		unsi_left(t_struct *f, char *s, unsigned int unsi_len)
{
	int rc;

	rc = '\0';
	if (f->zero && !f->dot)
		rc = '0';
	else
		rc = ' ';
	while (f->width-- > 0)
		f->nprinted += write(1, &rc, 1);
	while (f->precision-- > 0)
		f->nprinted += write(1, "0", 1);
	f->nprinted += write(1, s, unsi_len);
}

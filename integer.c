/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:35:58 by atahiri           #+#    #+#             */
/*   Updated: 2019/12/29 22:13:46 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		integer(t_struct *f, va_list ap)
{
	int out_int;
	int int_len;
	int refer;

	refer = 0;
	out_int = (int)va_arg(ap, int);
	int_len = ft_intlen(out_int);
	if (zero_input(f, out_int) == 1)
		return (0);
	if (f->precision == -1 && f->width == -1)
	{
		out_int < 0 ? int_len += 1 : int_len;
		f->nprinted += write(1, ft_itoa(out_int), int_len);
	}
	else
	{
		if (out_int < 0)
		{
			refer = -1;
			out_int = -out_int;
		}
		int_handle(f, out_int, refer, int_len);
	}
	return (0);
}

int		zero_input(t_struct *f, int out_int)
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
		write(1, "", 0);
		return (1);
	}
	return (0);
}

void	int_handle(t_struct *f, long out_int, int refer, int int_len)
{
	char *s;

	out_int < 0 ? out_int = -out_int : out_int;
	s = ft_itoa(out_int);
	if (f->dot && f->precision > int_len)
		f->precision -= int_len;
	else
		f->precision = 0;
	if (refer == 0)
		f->width = f->width - (f->precision + int_len);
	else
		f->width = f->width - (f->precision + int_len + 1);
	if (f->minus == 1)
		int_right(f, out_int, refer, s);
	else
		int_left(f, out_int, refer, s);
	free(s);
}

void	int_right(t_struct *f, long out_int, int refer, char *s)
{
	int ret;
	int int_len;

	ret = 0;
	int_len = ft_intlen(out_int);
	if (refer != 0)
		f->nprinted += write(1, "-", 1);
	while (f->precision > 0)
	{
		f->nprinted += write(1, "0", 1);
		f->precision--;
	}
	f->nprinted += write(1, s, int_len);
	while (f->width > 0)
	{
		f->nprinted += write(1, " ", 1);
		f->width--;
	}
}

void	int_left(t_struct *f, int out_int, int refer, char *s)
{
	int ret;
	int rc;
	int int_len;

	ret = 0;
	rc = '\0';
	int_len = ft_intlen(out_int);
	if (f->zero && !f->dot)
		rc = '0';
	else
		rc = ' ';
	if (rc == '0' && refer != 0)
	{
		f->nprinted += write(1, "-", 1);
		refer = 0;
	}
	while (f->width-- > 0)
		f->nprinted += write(1, &rc, 1);
	if (refer != 0)
		f->nprinted += write(1, "-", 1);
	while (f->precision-- > 0)
		f->nprinted += write(1, "0", 1);
	f->nprinted += write(1, s, int_len);
}

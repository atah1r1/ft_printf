/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 16:04:42 by atahiri           #+#    #+#             */
/*   Updated: 2019/12/27 16:41:35 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		string(t_struct *f, va_list ap)
{
	char	*out_str;
	int		str_len;

	out_str = (char *)va_arg(ap, char*);
	if (out_str == NULL)
		out_str = "(null)";
	str_len = ft_strlen(out_str);
	if (str_len == 0)
		out_str = ft_strdup("");
	if (f->width == -1 && f->precision == -1 && !f->dot)
	{
		f->nprinted += write(1, out_str, str_len);
		return (0);
	}
	else
	{
		if (f->minus == 1)
			string_right(f, out_str, str_len);
		else
			string_left(f, out_str, str_len);
	}
	return (0);
}

void	string_right(t_struct *f, char *out_str, int str_len)
{
	if (f->precision > 0 && str_len == 0)
		f->precision = 0;
	if ((f->precision >= 0 || f->precision == -1) && f->dot == 1)
	{
		f->precision == -1 ? f->precision = 0 : f->precision;
		f->precision > str_len ? f->precision = str_len : f->precision;
		f->nprinted += write(1, out_str, f->precision);
	}
	else
		f->nprinted += write(1, out_str, str_len);
	if (f->precision > str_len)
		f->precision = str_len;
	else if (f->dot == 0)
		f->width -= str_len;
	while (f->width > f->precision && f->width > 0)
	{
		f->nprinted += write(1, " ", 1);
		f->width--;
	}
}

void	string_left(t_struct *f, char *out_str, int str_len)
{
	if (f->dot && str_len > f->precision)
		str_len = f->precision;
	if (f->dot == 1)
		f->precision == -1 ? str_len = 0 : str_len;
	if (f->width > str_len)
	{
		while ((f->width - str_len) > 0)
		{
			f->nprinted += write(1, " ", 1);
			f->width--;
		}
	}
	if (str_len != 0)
	{
		if (f->precision > str_len)
			f->precision = str_len;
		if ((f->precision > 0 || f->precision == -1) && f->dot == 1)
			f->nprinted += write(1, out_str, f->precision);
		else
			f->nprinted += write(1, out_str, str_len);
	}
}

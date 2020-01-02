/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 18:21:45 by atahiri           #+#    #+#             */
/*   Updated: 2019/12/24 17:20:09 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	if_etoile(const char *format, t_struct *f, va_list ap)
{
	if (format[f->i] == '*')
	{
		f->width = va_arg(ap, int);
		f->etoile = 1;
		if (f->width < 0)
		{
			f->minus = 1;
			f->width = -(f->width);
		}
		while (format[f->i] == '*')
			f->i++;
	}
}

void	flags(const char *format, t_struct *f)
{
	while (ft_strchr("-0", format[f->i]))
	{
		if (format[f->i] == '-')
			f->minus = 1;
		else if (format[f->i] == '0')
			f->zero = 1;
		f->i++;
	}
}

void	width(const char *format, t_struct *f, va_list ap)
{
	if_etoile(format, f, ap);
	if (ft_strchr("0123456789", format[f->i]))
	{
		f->width = ft_atoi(&format[f->i]);
		while (format[f->i] >= 48 && format[f->i] <= 57)
		{
			f->i++;
			if (format[f->i] == '*')
			{
				f->etoile = 1;
				if (f->width < 0)
				{
					f->minus = 1;
					f->width = -(f->width);
				}
				while (format[f->i] == '*')
					f->i++;
			}
		}
	}
}

void	precision(const char *format, t_struct *f, va_list ap, int a)
{
	if (format[f->i] == '.')
	{
		f->i++;
		f->dot = 1;
	}
	if (format[f->i] >= 48 && format[f->i] <= 57)
	{
		f->precision = ft_atoi(&format[f->i]);
		while (format[f->i] >= 48 && format[f->i] <= 57)
			f->i++;
	}
	else if (format[f->i] == '*')
	{
		a = va_arg(ap, int);
		if (a < 0 && format[f->i + 1] == 's')
			f->precision = -1;
		if (a >= 0)
			f->precision = a;
		else
			f->dot = 0;
		while (format[f->i] == '*')
			f->i++;
	}
}

void	handle_data(const char *format, t_struct *f, va_list ap)
{
	flags(format, f);
	width(format, f, ap);
	precision(format, f, ap, 0);
}

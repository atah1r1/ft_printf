/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 14:43:22 by atahiri           #+#    #+#             */
/*   Updated: 2019/12/29 22:25:10 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	zerostruct(t_struct *f)
{
	f->nprinted = 0;
	f->hex = 0;
	f->i = 0;
	f->minus = 0;
	f->zero = 0;
	f->width = -1;
	f->precision = -1;
	f->dot = 0;
	f->etoile = 0;
}

void	zero2(t_struct *f)
{
	f->hex = 0;
	f->minus = 0;
	f->zero = 0;
	f->width = 0;
	f->precision = 0;
	f->dot = 0;
	f->etoile = 0;
}

int		parsel2(t_struct *f, int posi, const char *format, va_list ap)
{
	f->i = posi;
	if (!ft_strchr(CCONVERSIONS, format[posi]))
		handle_data(format, f, ap);
	else if (ft_strchr(CCONVERSIONS, format[posi]))
	{
		conversions(format, f, ap);
		zero2(f);
	}
	return (f->i - 1);
}

int		formatparse(const char *fmt, t_struct *f, va_list ap, int pos)
{
	while (fmt[pos] != '\0')
	{
		if (fmt[pos] != '%' && fmt[pos])
			f->nprinted += write(1, &fmt[pos], 1);
		else if (fmt[pos] == '%')
		{
			if (!ft_strchr(ALLSYMBOLS, fmt[pos + 1]))
				break ;
			while (ft_strchr(ALLSYMBOLS, fmt[pos + 1]))
			{
				pos += 1;
				if (ft_strchr("cspdiuxX%", fmt[pos]))
				{
					pos = parsel2(f, pos, fmt, ap) + 2;
					break ;
				}
				else
					pos = parsel2(f, pos, fmt, ap);
			}
			continue;
		}
		pos++;
	}
	return (f->nprinted);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			status;
	t_struct	*s;
	int			formatlen;

	formatlen = ft_strlen(format);
	if (!(s = (t_struct*)malloc(sizeof(t_struct))))
		return (0);
	zerostruct(s);
	va_start(ap, format);
	if (!format[0])
		return (0);
	if (formatlen == 1 && format[0] == '%')
		return (0);
	else
		status = formatparse(format, s, ap, 0);
	va_end(ap);
	free(s);
	return (status);
}

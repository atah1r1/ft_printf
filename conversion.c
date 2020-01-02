/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:27:56 by atahiri           #+#    #+#             */
/*   Updated: 2019/12/27 14:49:00 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conversions(const char *format, t_struct *f, va_list ap)
{
	if (format[f->i] == 'd' || format[f->i] == 'i')
		integer(f, ap);
	else if (format[f->i] == 'c')
		character(f, ap);
	else if (format[f->i] == 's')
		string(f, ap);
	else if (format[f->i] == 'X' || format[f->i] == 'x')
		hexadecimal(format, f, ap);
	else if (format[f->i] == 'p')
		pointer(f, ap);
	else if (format[f->i] == 'u')
		is_unsigned(f, ap);
	else
		percent(f);
}

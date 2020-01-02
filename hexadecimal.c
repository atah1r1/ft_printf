/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadecimal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 10:27:51 by atahiri           #+#    #+#             */
/*   Updated: 2019/12/28 16:43:23 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*convert_to_hexa(t_struct *f, unsigned long dec, char s)
{
	char			*s1;
	unsigned long	res;
	char			*rev;

	res = 0;
	s1 = malloc(100 * sizeof(char));
	ft_memset(s1, 0, 100);
	while (dec != 0)
	{
		res = dec % 16;
		if (res < 10)
			res += 48;
		else
		{
			if (s == 'X')
				res += 55;
			if (s == 'x')
				res += 87;
		}
		s1[f->hex++] = res;
		dec = dec / 16;
	}
	rev = s1;
	free(s1);
	return (ft_strrev(rev));
}

void			precision_handling_hexa(t_struct *f, unsigned int hexa_len)
{
	if (f->dot && (f->precision > (int)hexa_len))
		f->precision -= hexa_len;
	else
		f->precision = 0;
	f->width = f->width - (f->precision + hexa_len);
}

int				hexadecimal(const char *format, t_struct *f, va_list ap)
{
	long			out_hexa;
	unsigned int	hexa_len;
	char			*s;

	out_hexa = va_arg(ap, unsigned int);
	if (zero_input(f, out_hexa) == 1)
		return (0);
	else if (out_hexa == 0 && f->dot == 1 && f->width > 0 &&
		(f->precision == 0 || f->precision == -1))
		s = "";
	else if (out_hexa == 0)
		s = "0";
	else
		s = convert_to_hexa(f, out_hexa, (format[f->i] == 'x') ? 'x' : 'X');
	hexa_len = ft_strlen(s);
	if (plug(f, hexa_len, s) == 1)
		return (0);
	else
		precision_handling_hexa(f, hexa_len);
	if (format[f->i] == 'x' || format[f->i] == 'X')
		f->minus == 1 ? hexa_right(f, s) : hexa_left(f, s);
	return (0);
}

void			hexa_right(t_struct *f, char *s)
{
	while (f->precision-- > 0)
		f->nprinted += write(1, "0", 1);
	f->nprinted += print_hexa(s);
	while (f->width-- > 0)
		f->nprinted += write(1, " ", 1);
}

void			hexa_left(t_struct *f, char *s)
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
	f->nprinted += print_hexa(s);
}

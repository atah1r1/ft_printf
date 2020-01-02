/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 17:04:06 by atahiri           #+#    #+#             */
/*   Updated: 2019/12/27 22:22:52 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		zero_input_p(t_struct *f, void *out_pointer)
{
	if (out_pointer == 0 && f->dot == 1 && f->width > 0
	&& (f->precision == -1 || f->precision == 0))
	{
		while (f->width-- > 0)
			f->nprinted += write(1, " ", 1);
		return (1);
	}
	else if (out_pointer == 0 && f->dot == 1
	&& (f->precision == 0 || f->precision == -1))
	{
		f->nprinted += write(1, "0x", 2);
		return (1);
	}
	return (0);
}

int		pointer(t_struct *f, va_list ap)
{
	void	*out_pointer;
	char	*tb;
	int		pointer_len;

	out_pointer = va_arg(ap, unsigned long *);
	tb = convert_to_hexa(f, (unsigned long)out_pointer, 'x');
	if ((out_pointer == 0 || out_pointer == NULL) && !f->dot)
		tb = "0";
	tb = ft_strjoin("0x", tb);
	pointer_len = ft_strlen(tb);
	if (f->precision == -1 && f->width == -1)
		f->nprinted += print_hexa(tb);
	else
	{
		precision_handling_hexa(f, pointer_len);
		if (f->minus == 1)
			hexa_right(f, tb);
		else
			hexa_left(f, tb);
	}
	free(tb);
	return (0);
}

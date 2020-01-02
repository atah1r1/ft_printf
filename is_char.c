/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 16:14:28 by atahiri           #+#    #+#             */
/*   Updated: 2019/12/24 17:32:18 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	character(t_struct *f, va_list ap)
{
	int out_char;

	out_char = (int)va_arg(ap, int);
	if (f->width == -1)
		f->nprinted += write(1, &out_char, 1);
	else
	{
		if (f->minus == 1)
		{
			f->nprinted += write(1, &out_char, 1);
			while (f->width-- > 1)
				f->nprinted += write(1, " ", 1);
		}
		else
		{
			while (f->width-- > 1)
				f->nprinted += write(1, " ", 1);
			f->nprinted += write(1, &out_char, 1);
		}
	}
}

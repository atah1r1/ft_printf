/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 13:17:02 by atahiri           #+#    #+#             */
/*   Updated: 2019/12/25 16:20:58 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned int		i;
	char				*pstr;

	i = 0;
	pstr = str;
	while (i < n)
	{
		pstr[i] = c;
		i++;
	}
	return (pstr);
}

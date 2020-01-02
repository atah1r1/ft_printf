/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 22:17:53 by atahiri           #+#    #+#             */
/*   Updated: 2019/12/24 15:26:53 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *str, int c)
{
	char *chr;

	chr = (char *)str;
	while (*chr != c)
	{
		if (!*chr)
			return (NULL);
		chr++;
	}
	return (chr);
}

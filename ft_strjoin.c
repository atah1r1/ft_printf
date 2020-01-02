/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 13:33:28 by atahiri           #+#    #+#             */
/*   Updated: 2019/12/25 17:06:39 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	lens1;
	size_t	lens2;
	char	*new;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	if (!(new = (char *)malloc(lens1 + lens2 + 1)))
		return (NULL);
	while (i < lens1)
	{
		new[i] = *((unsigned char *)s1 + i);
		i++;
	}
	while (j < lens2)
		new[i++] = *((unsigned char *)s2 + j++);
	new[i] = '\0';
	return (new);
}

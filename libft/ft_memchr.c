/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 13:39:20 by tpyrogov          #+#    #+#             */
/*   Updated: 2017/11/03 13:39:22 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	sym;
	int				i;

	if (s)
	{
		i = 0;
		str = (unsigned char *)s;
		sym = (unsigned char)c;
		while (n)
		{
			if (str[i] == sym)
				return (str + i);
			i++;
			n--;
		}
	}
	return (NULL);
}

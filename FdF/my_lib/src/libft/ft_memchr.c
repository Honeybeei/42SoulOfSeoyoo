/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:39:21 by seoyoo            #+#    #+#             */
/*   Updated: 2022/08/03 21:39:21 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

// Discription
// Locates the first occurrence of c(2nd Parameter)(converted to an unsigned 
// cahr) in string s(1st Parameter). 

// 1st Parameter :	Haystack
// 2nd Parameter :	Needle
// 3rd Parameter :	Number of bytes to be searched. 
// Return values :	pointer to the byte which first occurred. Returns NULL when 
//					no such byte exists within n bytes. 

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	temp_c;
	size_t			i;

	p = (unsigned char *)s;
	i = 0;
	temp_c = (unsigned char)c;
	while (i < n)
	{
		if (p[i] == temp_c)
			return (p + i);
		i++;
	}
	return (NULL);
}

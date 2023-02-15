/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:25:55 by seoyoo            #+#    #+#             */
/*   Updated: 2022/08/03 21:41:07 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

// Discription
// Search for c(2nd Parameter) in the string(1st Parameter). It will return a 
// pointer of the first occurence of the c(converted to cahr) or NULL if the 
// character does not apperar in the string. 

// 1st Parameter :	Haystack ;)
// 2nd Parameter :	Needle
// Return values :	Pointer of the first occurence of the Needle or NULL if 
// there is no Needle in the Haystack.

char	*ft_strchr(const char *s, int c)
{
	char	*p;
	size_t	i;

	p = (char *)s;
	i = 0;
	while (p[i] != '\0')
	{
		if (p[i] == c)
			return (p + i);
		i++;
	}
	if (p[i] == c)
		return (p + i);
	return (NULL);
}

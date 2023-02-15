/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 19:08:43 by seoyoo            #+#    #+#             */
/*   Updated: 2022/08/03 21:41:03 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

// Discription
// Applies function f(2nd Parameter) to all the characters in string s(1st 
// Parameter).

// 1st Parameter :	String on wich to iterate.
// 2nd Parameter :	Fuction to be applied to each character in the s. Passing 
//					its index as first argument.
// Return values :	New string which is the result of iterated string of s by f.

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*dst;
	unsigned int	i;

	dst = ft_strdup(s);
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (dst[i] != '\0')
	{
		dst[i] = f(i, dst[i]);
		i++;
	}
	return (dst);
}

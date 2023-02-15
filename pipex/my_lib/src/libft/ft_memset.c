/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 19:30:27 by seoyoo            #+#    #+#             */
/*   Updated: 2022/08/03 21:41:12 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

// Discription
// Writes len(3rd Parameter) bytes of value c(2nd Parameter)(converted to 
// unsigned char) in string b(1st Parameter).

// 1st Parameter :	address of the first character of the string 
// 2nd Parameter :	Value which will be written to the string. This will be 
//					converted to an [unsigned char]
// 3rd Parameter :	number of bytes to set
// Return values :	1st Parameter(address of the string)

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*dst;
	size_t			i;

	dst = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		dst[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

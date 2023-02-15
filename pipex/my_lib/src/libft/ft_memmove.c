/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 22:14:47 by seoyoo            #+#    #+#             */
/*   Updated: 2022/08/03 21:41:12 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

// Discription
// memcpy copies string from the start but rev_memcpy copies the string from the
// end to prevent writing on dst(1st Parameter).

// 1st Parameter :	The address of the destination memory area.
// 2nd Parameter :	The address of the source memory area.
// 3rd Parameter :	Length of bytes to copy.
// Return values :	Destination(1st Parameter).

static void	*rev_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*temp_src;
	unsigned char	*temp_dst;

	if (dst != src)
	{
		temp_src = (unsigned char *)src;
		temp_dst = (unsigned char *)dst;
		while (n > 0)
		{
			n--;
			temp_dst[n] = temp_src[n];
			if (n == 0)
				break ;
		}
	}
	return (dst);
}

// Discription
// Same as memcpy() but this function doesn't have restrict keyword at 
// prototype. Therefore this function should always copy in a non-destructive 
// manner.

// 1st Parameter :	The address of the destination memory area.
// 2nd Parameter :	The address of the source memory area.
// 3rd Parameter :	Length of bytes to copy.
// Return values :	Destination(1st Parameter).

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst <= src)
		ft_memcpy(dst, src, len);
	else
		rev_memcpy(dst, src, len);
	return (dst);
}

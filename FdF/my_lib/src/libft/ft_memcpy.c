/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 21:38:46 by seoyoo            #+#    #+#             */
/*   Updated: 2022/08/03 21:41:13 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

// Discription
// Copies n bytes from memory area src(2nd Parameter) to memory area dst(1st 
// Parameter). If dst and src overlap, the behavior is undefined. 

// 1st Parameter :	The address of the destination memory area.
// 2nd Parameter :	The address of the source memory area.
// Return values :	Destination(1st Parameter)

// Note
// In manual, there is a keyword called "restrict" at the function's prototype. 
// This keyword ensure that memory area doesnt overlaps. However, this keyword 
// is a part of c99 standard. Therefore it is forbidden for us to use in this 
// assignment.

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*temp_src;
	unsigned char	*temp_dst;

	if (src != dst)
	{
		temp_src = (unsigned char *)src;
		temp_dst = (unsigned char *)dst;
		i = 0;
		while (i < n)
		{
			temp_dst[i] = temp_src[i];
			i++;
		}
	}
	return (dst);
}

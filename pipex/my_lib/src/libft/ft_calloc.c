/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:26:35 by seoyoo            #+#    #+#             */
/*   Updated: 2022/08/03 21:38:56 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

// Discription
// Allocate count(1st Parameter) amount with size(2nd Parameter) bytes of memory
// and and fill with bytes of zero.

// 1st Parameter :	Count of size(2nd Parameter) bytes to allocate.
// 2nd Parameter :	Size of a single object.
// Return values :	Pointer which has been mallocated. 

void	*ft_calloc(size_t count, size_t size)
{
	void	*dst;

	dst = NULL;
	dst = (void *)malloc(count * size);
	if (dst == NULL)
		return (NULL);
	ft_memset(dst, 0, count * size);
	return (dst);
}

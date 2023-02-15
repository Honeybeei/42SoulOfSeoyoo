/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 13:05:28 by seoyoo            #+#    #+#             */
/*   Updated: 2022/08/03 21:41:05 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

// Discription
// Same as strncat but much safer. Appends string src(2nd Parameter) to the end 
// of the dst(1st Parameter). It will append at most dstsize(3rd Parameter) - 
// strlen(dst) - 1 characters. It will then NUL terminate. It will not work if 
// the dstsize is 0 or the original dst string was longer than dstsize. The 
// behavior is undifined when the src and dst strings overlaps.

// 1st Parameter :	The address of the destination memory area.
// 2nd Parameter :	The address of the source memory area.
// 3rd Parameter :	Size of destination buffer. 
// Return values :	Initial length of dst + length of src

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	remaining_buffer;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dst_len < dstsize)
	{
		if (dst_len + src_len < dstsize)
		{
			ft_memcpy(dst + dst_len, src, src_len);
			dst[dst_len + src_len] = '\0';
		}
		else
		{
			remaining_buffer = dstsize - dst_len;
			ft_memcpy(dst + dst_len, src, remaining_buffer - 1);
			dst[dstsize - 1] = '\0';
		}
	}
	else
		dst_len = dstsize;
	return (dst_len + src_len);
}

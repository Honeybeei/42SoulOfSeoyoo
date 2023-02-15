/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:54:05 by seoyoo            #+#    #+#             */
/*   Updated: 2022/08/03 21:41:07 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

// Discription
// Duplicates string(malloc the pointer and copy data from s1(1st Parameter)).

// 1st Parameter :	String to duplicate.
// Return values :	The pointer pointing duplicated string.

char	*ft_strdup(const char *s1)
{
	size_t	src_len;
	char	*dst;

	src_len = ft_strlen(s1);
	dst = malloc(sizeof(char) * (src_len + 1));
	if (dst == NULL)
		return (NULL);
	ft_memcpy(dst, s1, src_len + 1);
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:17:11 by seoyoo            #+#    #+#             */
/*   Updated: 2022/08/03 21:40:59 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

// Discription
// Get a substring from string s(1st Parameter) starts from start(2nd parameter)
// which is an index of the s and the maximum length of substring sould be len
// (3rd parameter)

// 1st Parameter :	Original string which whill be the src of substring.
// 2nd Parameter :	Index of 1st Parameter which will be the start of substring
//					of s.
// 3rd Parameter :	Maximum length of the substring.
// Return values :	The substring.

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	char	*src;

	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	src = (char *)s;
	dst = malloc(sizeof(char) * (len + 1));
	if (dst == NULL)
		return (NULL);
	ft_memcpy(dst, src + start, len);
	dst[len] = '\0';
	return (dst);
}

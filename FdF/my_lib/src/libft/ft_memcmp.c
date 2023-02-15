/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:51:07 by seoyoo            #+#    #+#             */
/*   Updated: 2022/11/12 17:25:55 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

// Description
// Isn't this function identical with strncmp? The answer is No. strncmp returns
// its value when '\0' occurs. However memcmp compares till n(3rd Parameter)
// bytes even there is '\0' in the string. 

// 1st Parameter :	string 1
// 2nd Parameter :	string 2
// 3rd Parameter :	number of characters to compare.
// Return values :	diff between string 1 and string 2. 

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*temp_s1;
	unsigned char	*temp_s2;

	temp_s1 = (unsigned char *)s1;
	temp_s2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (temp_s1[i] != temp_s2[i])
			return (temp_s1[i] - temp_s2[i]);
		i++;
	}
	return (0);
}

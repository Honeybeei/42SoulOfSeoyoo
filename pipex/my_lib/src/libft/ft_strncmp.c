/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:04:26 by seoyoo            #+#    #+#             */
/*   Updated: 2022/08/03 21:41:02 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

// Discription
// strncmp compares not more than n(3rd Parameter) characters from s1(1st 
// Parameter) and s2(2nd Parameter). Characters that appear after a '\0' should 
// not be compared. Comparison of the strings should be done using unsigned 
// characters. 

// 1st Parameter :	string 1
// 2nd Parameter :	string 2
// 3rd Parameter :	number of characters to compare.
// Return values :	diff between string 1 and string 2. 

int	ft_strncmp(const char *s1, const char *s2, size_t n)
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
		else
		{
			if (temp_s1[i] == '\0')
				break ;
			i++;
		}
	}
	return (0);
}

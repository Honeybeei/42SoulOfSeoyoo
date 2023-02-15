/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:33:13 by seoyoo            #+#    #+#             */
/*   Updated: 2022/08/03 21:39:22 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

// Discription
// Convert integer n(1st Parameter) to string. Negative numvers must be handled.

// 1st Parameter :	Integer to be converted. 
// Return values :	string which is the result of convertion. 

static size_t	digit_counter(size_t num)
{
	size_t	digit;

	digit = 0;
	if (num == 0)
		return (1);
	else
	{
		while (num > 0)
		{
			num /= 10;
			digit++;
		}
		return (digit);
	}
}

static char	*palce_dicimal_char(long long num, char *dst, size_t str_len)
{
	dst[str_len] = '\0';
	if (num == 0)
		dst[0] = '0';
	else
	{
		while (num > 0)
		{
			str_len--;
			dst[str_len] = num % 10 + '0';
			num /= 10;
		}
	}
	return (dst);
}

char	*ft_itoa(int n)
{
	long long	num;
	int			sign;
	size_t		str_len;
	char		*dst;

	str_len = 0;
	num = n;
	sign = 1;
	if (num < 0)
	{
		sign = -1;
		num *= -1;
		str_len++;
	}
	str_len += digit_counter(num);
	dst = malloc(sizeof(char) * (str_len + 1));
	if (dst == NULL)
		return (NULL);
	dst = palce_dicimal_char(num, dst, str_len);
	if (sign == -1)
		dst[0] = '-';
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_itoa_signed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:12:49 by seoyoo            #+#    #+#             */
/*   Updated: 2022/08/04 01:32:47 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/my_itoa.h"

int	count_digit_signed(t_my_signed_num *num)
{
	int			digit_count;
	long long	n;

	n = num->n;
	if (n == 0)
		return (1);
	else
	{
		digit_count = 0;
		while (n != 0)
		{
			n = n / num->base;
			digit_count++;
		}
		return (digit_count);
	}
}

void	fill_str_signed(t_my_signed_num *num, int str_len)
{
	long long	n;

	n = num->n;
	if (n == 0)
		num->num_str[0] = '0';
	while (n != 0)
	{
		str_len--;
		if (n < 0)
			num->num_str[str_len] = num->symbol_list[(n % num->base) * (-1)];
		else
			num->num_str[str_len] = num->symbol_list[n % num->base];
		n = n / num->base;
	}
}

// Must free the return value!!!
char	*my_itoa_signed(long long n, char *symbol_list)
{
	t_my_signed_num	num;
	int				str_len;

	num.n = n;
	num.base = ft_strlen(symbol_list);
	num.symbol_list = symbol_list;
	str_len = count_digit_signed(&num);
	if (num.n < 0)
		str_len++;
	num.num_str = malloc(sizeof(char) * (str_len + 1));
	if (num.num_str == NULL)
		return (NULL);
	num.num_str[str_len] = '\0';
	if (num.n < 0)
		num.num_str[0] = '-';
	fill_str_signed(&num, str_len);
	return (num.num_str);
}

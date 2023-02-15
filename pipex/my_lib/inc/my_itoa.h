/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_itoa.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:13:29 by seoyoo            #+#    #+#             */
/*   Updated: 2022/06/28 21:11:31 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_ITOA_H
# define MY_ITOA_H

# include <stdlib.h>
# include "libft.h"

typedef struct s_my_signed_num
{
	long long	n;
	int			base;
	char		*symbol_list;
	char		*num_str;
}	t_my_signed_num;

typedef struct s_my_unsigned_num
{
	unsigned long long	n;
	int					base;
	char				*symbol_list;
	char				*num_str;
}	t_my_unsigned_num;

// my_itoa_signed.c
char	*my_itoa_signed(long long n, char *symbol_list);
int		count_digit_signed(t_my_signed_num *num);
void	fill_str_signed(t_my_signed_num *num, int str_len);

// my_itoa_unsigned.c
char	*my_itoa_unsigned(unsigned long long n, char *symbol_list);
int		count_digit_unsigned(t_my_unsigned_num *num);
void	fill_str_unigned(t_my_unsigned_num *num, int str_len);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 19:58:47 by seoyoo            #+#    #+#             */
/*   Updated: 2022/08/03 21:41:10 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

// Discription
// Outputs the integer n(1st Parameter) to the given file descriptor. 

// 1st Parameter :	The integer to output.
// 2nd Parameter :	The file descriptor on which to write. 
// Return values :	None. 

static void	dispaly_pos_num(long long num, int fd)
{
	char	num_arr[20];
	int		i;

	i = 0;
	while (num > 0)
	{
		num_arr[19 - i] = num % 10 + '0';
		i++;
		num /= 10;
	}
	write(fd, &num_arr[19 - i + 1], i);
}

void	ft_putnbr_fd(int n, int fd)
{
	long long	num;

	num = n;
	if (num == 0)
		write(fd, "0", 1);
	else if (num < 0)
	{
		num *= -1;
		write(fd, "-", 1);
		dispaly_pos_num(num, fd);
	}
	else
		dispaly_pos_num(num, fd);
}

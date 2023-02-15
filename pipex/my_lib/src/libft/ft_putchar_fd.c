/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 19:48:31 by seoyoo            #+#    #+#             */
/*   Updated: 2022/08/03 21:41:11 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

// Discription
// Outputs the character c(1st Parameter) to the givn file descriptor. 

// 1st Parameter :	The character to output.
// 2nd Parameter :	The file descriptor on which to write. 
// Return values :	None. 

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

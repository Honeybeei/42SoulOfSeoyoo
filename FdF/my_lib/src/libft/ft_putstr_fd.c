/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 19:52:37 by seoyoo            #+#    #+#             */
/*   Updated: 2022/08/03 21:41:09 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

// Discription
// Outputs the string s(1st Parameter) to the givn file descriptor. 

// 1st Parameter :	The string to output.
// 2nd Parameter :	The file descriptor on which to write. 
// Return values :	None. 

void	ft_putstr_fd(char *s, int fd)
{
	size_t	str_len;

	str_len = ft_strlen(s);
	write(fd, s, str_len);
}

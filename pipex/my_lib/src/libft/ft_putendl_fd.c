/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 19:56:12 by seoyoo            #+#    #+#             */
/*   Updated: 2022/08/03 21:41:10 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

// Discription
// Outputs the string s(1st Parameter) to the givn file descriptor followed by
// a newline. 

// 1st Parameter :	The string to output.
// 2nd Parameter :	The file descriptor on which to write. 
// Return values :	None. 

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}

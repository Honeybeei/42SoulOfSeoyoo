/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:41:29 by seoyoo            #+#    #+#             */
/*   Updated: 2022/08/03 21:39:26 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

// Discription
// Tests for an ASCII character (which is any character between 0 and octal 0177
// inclusive)

// 1st Parameter :	Integer to be checked
// Return values :	Return 1 if input 1 is ASCII character. Return 0 if its not.

int	ft_isascii(int c)
{
	if (0 <= c && c <= 0177)
		return (1);
	return (0);
}

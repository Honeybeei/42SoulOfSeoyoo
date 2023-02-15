/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:52:58 by seoyoo            #+#    #+#             */
/*   Updated: 2022/08/03 21:39:24 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

// Discription
// Tests for an printalbe character (which is any character between octal 040 
// and octal 0176 inclusive)

// 1st Parameter :	Integer to be checked
// Return values :	Return 1 if input 1 is printalbe character. Return 0 if its 
//					not.

int	ft_isprint(int c)
{
	if (040 <= c && c <= 0176)
		return (1);
	return (0);
}

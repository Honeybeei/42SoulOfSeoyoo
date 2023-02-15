/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:04:16 by seoyoo            #+#    #+#             */
/*   Updated: 2022/08/03 21:40:58 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

// Discription
// Convert a single characther c(1st Parameter) to upper case if it is a lower 
// case.

// 1st Parameter :	The character to be converted.
// Return values :	Corressponding upper case if the 1st Parameter is a lower 
//					case

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		c = c - 'a' + 'A';
	return (c);
}

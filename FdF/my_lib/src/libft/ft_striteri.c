/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 19:32:53 by seoyoo            #+#    #+#             */
/*   Updated: 2022/08/03 21:41:06 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

// Discription
// Applies function f(2nd Parameter) to all the characters of the string s(1st 
// Parameter). Each character is passed by address to f.

// 1st Parameter :	String on wich to iterate.
// 2nd Parameter :	Fuction to be applied to each character in the s. Passing 
//					its index as first argument.
// Return values :	None.

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned long	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, s + i);
		i++;
	}
}

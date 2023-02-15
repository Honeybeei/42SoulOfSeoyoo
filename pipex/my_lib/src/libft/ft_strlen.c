/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:58:29 by seoyoo            #+#    #+#             */
/*   Updated: 2022/08/03 21:41:03 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

// Discription
// Computes the length of the string

// 1st Parameter :	Address of the string's first character
// Return values :	Length of the string (the number of characters thant precede
//					the terminating NUL character(0x00))

// Memo
// NULL / NUL / '0' / 0 is different!!!!

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

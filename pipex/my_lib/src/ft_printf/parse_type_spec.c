/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_type_spec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 12:18:29 by seoyoo            #+#    #+#             */
/*   Updated: 2022/08/08 01:31:39 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

t_nstr	*parse_c_type(va_list *ap)
{
	t_nstr	*arg_nstr;

	arg_nstr = make_nul_nstr();
	if (arg_nstr == NULL)
		return (NULL);
	arg_nstr->c_arr_ = malloc(sizeof(char));
	arg_nstr->len_ = 1;
	arg_nstr->c_arr_[0] = (char)va_arg(*ap, int);
	return (arg_nstr);
}

t_nstr	*parse_s_type(va_list *ap)
{
	char	*arg_str;

	arg_str = va_arg(*ap, char *);
	if (arg_str == NULL)
		return (convert_2_nstr("(null)", false));
	else
		return (convert_2_nstr(arg_str, false));
}

t_nstr	*parse_p_type(va_list *ap)
{
	size_t	address;
	t_nstr	*arg_nstr;
	t_nstr	*sign_nstr;

	address = (size_t)va_arg(*ap, void *);
	arg_nstr = convert_2_nstr(my_itoa_unsigned(address, HEXADECIMAL_L), true);
	sign_nstr = convert_2_nstr("0x", false);
	return (join_2nstrs_n_free(sign_nstr, arg_nstr));
}

t_nstr	*parse_signed_int_type(va_list *ap)
{
	int	signed_int;

	signed_int = va_arg(*ap, int);
	return (convert_2_nstr(my_itoa_signed(signed_int, DECIMAL), true));
}

t_nstr	*parse_unsigned_int_type(va_list *ap, char type)
{
	size_t	unsigned_int;
	char	*num_str;

	unsigned_int = (unsigned int)va_arg(*ap, size_t);
	num_str = NULL;
	if (type == 'u')
		num_str = my_itoa_unsigned(unsigned_int, DECIMAL);
	else if (type == 'x')
		num_str = my_itoa_unsigned(unsigned_int, HEXADECIMAL_L);
	else if (type == 'X')
		num_str = my_itoa_unsigned(unsigned_int, HEXADECIMAL_U);
	return (convert_2_nstr(num_str, true));
}

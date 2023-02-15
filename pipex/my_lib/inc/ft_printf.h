/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:06:47 by seoyoo            #+#    #+#             */
/*   Updated: 2022/08/08 01:31:33 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include "my_itoa.h"
# include "my_nstr.h"
# include <stdlib.h> // malloc, free
# include <unistd.h> // write
# include <stdarg.h> // va_start, va_arg, va_copy, va_end

# ifndef ERROR
#  define ERROR 0
# endif
# define WRITE_ERROR -1
# define DECIMAL "0123456789"
# define HEXADECIMAL_L "0123456789abcdef"
# define HEXADECIMAL_U "0123456789ABCDEF"

// singlely linked list
typedef struct s_format_node
{
	t_nstr					*nstr_;
	struct s_format_node	*next_;
}	t_fmt_nd;

// ft_printf.c
int			ft_printf(const char *format, ...);
t_fmt_nd	*parse_fmt_str_to_list(char *f_str, va_list *ap);
t_nstr		*parse_type_spec(char *f_str, va_list *ap);
char		*parse_plain_str(char *f_str, t_fmt_nd *tail);
ssize_t		print_fmt_nd_list(t_fmt_nd *head);

// format_node_utils.c
t_fmt_nd	*make_t_fmt_node(void);
void		*fmt_nd_list_termination_protocol(t_fmt_nd *head);
t_fmt_nd	*add_new_node_to_list(t_fmt_nd **head_ptr, t_fmt_nd **tail_ptr);

// parse_type_spec.c
t_nstr		*parse_c_type(va_list *ap);
t_nstr		*parse_s_type(va_list *ap);
t_nstr		*parse_p_type(va_list *ap);
t_nstr		*parse_signed_int_type(va_list *ap);
t_nstr		*parse_unsigned_int_type(va_list *ap, char type);

#endif
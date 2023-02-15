/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:14:48 by seoyoo            #+#    #+#             */
/*   Updated: 2022/08/08 01:31:38 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	t_fmt_nd	*head;
	char		*f_str;
	ssize_t		printed_char_cnt;

	va_start(ap, format);
	f_str = (char *)format;
	if (f_str == NULL)
		return (ERROR);
	head = parse_fmt_str_to_list(f_str, &ap);
	if (head == NULL)
		return (ERROR);
	printed_char_cnt = print_fmt_nd_list(head);
	if (printed_char_cnt == WRITE_ERROR)
		return (WRITE_ERROR);
	fmt_nd_list_termination_protocol(head);
	va_end(ap);
	return (printed_char_cnt);
}

t_fmt_nd	*parse_fmt_str_to_list(char *f_str, va_list *ap)
{
	t_fmt_nd	*head;
	t_fmt_nd	*tail;

	head = NULL;
	while (*f_str != '\0')
	{
		if (add_new_node_to_list(&head, &tail) == NULL)
			return (NULL);
		if (*f_str == '%')
		{
			tail->nstr_ = parse_type_spec(f_str, ap);
			if (tail->nstr_ == NULL)
				return (fmt_nd_list_termination_protocol(head));
			f_str += 2;
		}
		else
			f_str = parse_plain_str(f_str, tail);
		if (f_str == NULL)
			return (fmt_nd_list_termination_protocol(head));
	}
	return (head);
}

t_nstr	*parse_type_spec(char *f_str, va_list *ap)
{
	if (f_str[1] == 'c')
		return (parse_c_type(ap));
	else if (f_str[1] == 's')
		return (parse_s_type(ap));
	else if (f_str[1] == 'p')
		return (parse_p_type(ap));
	else if (f_str[1] == 'd' || f_str[1] == 'i')
		return (parse_signed_int_type(ap));
	else if (f_str[1] == 'u' || f_str[1] == 'x' || f_str[1] == 'X')
		return (parse_unsigned_int_type(ap, f_str[1]));
	else if (f_str[1] == '%')
		return (convert_2_nstr("%", false));
	else
		return (NULL);
}

char	*parse_plain_str(char *f_str, t_fmt_nd *tail)
{
	size_t	i;

	i = 0;
	while (f_str[i] != '%' && f_str[i] != '\0')
		i++;
	tail->nstr_ = convert_2_nstr(ft_substr(f_str, 0, i), true);
	return (f_str + i);
}

ssize_t	print_fmt_nd_list(t_fmt_nd *head)
{
	ssize_t	count;
	ssize_t	temp;

	count = 0;
	while (head != NULL)
	{
		temp = write(1, head->nstr_->c_arr_, head->nstr_->len_);
		if (temp == -1)
			return (WRITE_ERROR);
		count += temp;
		head = head->next_;
	}
	return (count);
}

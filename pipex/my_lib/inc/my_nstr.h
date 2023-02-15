/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_nstr.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 21:47:30 by seoyoo            #+#    #+#             */
/*   Updated: 2022/08/08 01:28:53 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_NSTR_H
# define MY_NSTR_H

# include "libft.h"
# include <stdlib.h> // malloc, free
# include <unistd.h> // write

// non nul-terminating string type. 
typedef struct s_n_string
{
	char	*c_arr_;
	size_t	len_;
}	t_nstr;

# ifndef INITIAL_NSTR_LEN
#  define INITIAL_NSTR_LEN 0
# endif

void	*terminate_nstr(t_nstr *nstr);
t_nstr	*make_nul_nstr(void);
t_nstr	*convert_2_nstr(char *str, char should_free);
t_nstr	*join_2nstrs_n_free(t_nstr *s1, t_nstr *s2);

#endif
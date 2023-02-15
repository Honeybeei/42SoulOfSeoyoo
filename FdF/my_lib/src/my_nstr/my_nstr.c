/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_nstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 21:47:02 by seoyoo            #+#    #+#             */
/*   Updated: 2022/08/08 01:32:02 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/my_nstr.h"

/* ************************************************************************** */

void	*terminate_nstr(t_nstr *nstr)
{
	if (nstr != NULL)
	{
		if (nstr->c_arr_ != NULL)
		{
			free(nstr->c_arr_);
			nstr->c_arr_ = NULL;
		}
		nstr->len_ = 0;
		free(nstr);
		nstr = NULL;
	}
	return (NULL);
}

/* ************************************************************************** */

t_nstr	*make_nul_nstr(void)
{
	t_nstr	*nstr;

	nstr = malloc(sizeof(t_nstr));
	if (nstr == NULL)
		return (NULL);
	nstr->c_arr_ = NULL;
	nstr->len_ = INITIAL_NSTR_LEN;
	return (nstr);
}

/* ************************************************************************** */

t_nstr	*convert_2_nstr(char *str, char should_free)
{
	t_nstr	*nstr;

	nstr = make_nul_nstr();
	if (nstr == NULL)
		return (NULL);
	nstr->len_ = ft_strlen(str);
	nstr->c_arr_ = malloc(sizeof(char) * nstr->len_);
	if (nstr->c_arr_ == NULL)
		return (terminate_nstr(nstr));
	ft_memcpy(nstr->c_arr_, str, nstr->len_);
	if (should_free == true)
		free(str);
	return (nstr);
}

/* ************************************************************************** */

t_nstr	*join_2nstrs_n_free(t_nstr *s1, t_nstr *s2)
{
	t_nstr	*joined_nstr;

	joined_nstr = make_nul_nstr();
	if (joined_nstr == NULL)
		return (NULL);
	joined_nstr->len_ = s1->len_ + s2->len_;
	joined_nstr->c_arr_ = malloc(sizeof(char) * joined_nstr->len_);
	if (joined_nstr->c_arr_ == NULL)
		return (NULL);
	ft_memcpy(joined_nstr->c_arr_, s1->c_arr_, s1->len_);
	ft_memcpy(joined_nstr->c_arr_ + s1->len_, s2->c_arr_, s2->len_);
	terminate_nstr(s1);
	terminate_nstr(s2);
	return (joined_nstr);
}

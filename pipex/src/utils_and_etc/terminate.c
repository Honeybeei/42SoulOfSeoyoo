/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 10:19:49 by seoyoo            #+#    #+#             */
/*   Updated: 2022/10/28 12:37:27 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex.h"

/**
 * @brief Terminate str_arr(param). All strings and array will be freed. 
 * 
 * @param str_arr 
 * @return void* 
 */
void	*terminate_str_arr(char **str_arr)
{
	size_t	idx;

	if (str_arr == NULL)
		return (NULL);
	idx = 0;
	while (str_arr[idx] != NULL)
	{
		free(str_arr[idx]);
		idx++;
	}
	free(str_arr);
	return (NULL);
}

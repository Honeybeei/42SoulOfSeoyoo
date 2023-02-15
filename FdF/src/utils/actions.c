/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 21:12:44 by seoyoo            #+#    #+#             */
/*   Updated: 2022/11/16 19:37:21 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

/* ************************************************************************** */

/**
 * @brief Get key code from loop -> execute matching actions. 
 * 
 * @param keycode 
 * @param ptrs 
 * @return int 
 */
int	actions(int keycode, t_ptrs *ptrs)
{
	if (keycode == KEY_ESC_)
	{
		mlx_destroy_window(ptrs->mlx_ptr_, ptrs->win_ptr_);
		terminate_map(ptrs->map_);
		terminate_projection(ptrs->p_map_);
		ft_putstr_fd("\nESC Pressed. Bye!!! :)\n", 1);
		exit(EXIT_SUCCESS);
	}
	return (keycode);
}

/* ************************************************************************** */

/**
 * @brief Prepare for action. Put all major object info to ptrs. Therefore, we
 * can also access to these object in action function. 
 * 
 * @param ptrs 
 * @param img 
 * @param map 
 * @param p_map 
 */
void	prep_action(t_ptrs *ptrs, t_img *img, t_map *map, t_p_map *p_map)
{
	ptrs->img_ = img;
	ptrs->map_ = map;
	ptrs->p_map_ = p_map;
}

/* ************************************************************************** */
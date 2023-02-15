/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:57:35 by seoyoo            #+#    #+#             */
/*   Updated: 2022/11/16 19:36:21 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

/* ************************************************************************** */

int	main(int argc, char **argv)
{
	t_ptrs		ptrs;
	t_map		*map;
	t_3d_vec	view_point;
	t_img		img;
	t_p_map		*p_map;

	check_argv(argc, argv);
	ptrs.mlx_ptr_ = mlx_init();
	ptrs.win_ptr_ = mlx_new_window(ptrs.mlx_ptr_, W_W_, W_H_, "FdF");
	map = make_new_map();
	get_map_data(map, argv[1]);
	p_map = make_new_projection(map->width_, map->height_);
	get_projection_result(map, p_map, &view_point);
	img.img_ptr_ = mlx_new_image(ptrs.mlx_ptr_, p_map->img_width_,
			p_map->img_height);
	set_view_point(map, &view_point);
	img.addr_ = mlx_get_data_addr(img.img_ptr_, &img.bits_per_pixel_,
			&img.size_line_, &img.endian_);
	draw_projection_to_img(&img, p_map, COLOR_PRESET_);
	mlx_put_image_to_window(ptrs.mlx_ptr_, ptrs.win_ptr_, img.img_ptr_,
		(W_W_ - p_map->img_width_) / 2, (W_H_ - p_map->img_height) / 2);
	prep_action(&ptrs, &img, map, p_map);
	mlx_hook(ptrs.win_ptr_, EVENT_KET_PRESS_, 0, actions, &ptrs);
	mlx_loop(ptrs.mlx_ptr_);
	return (0);
}

/* ************************************************************************** */
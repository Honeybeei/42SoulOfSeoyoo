/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 00:39:14 by seoyoo            #+#    #+#             */
/*   Updated: 2022/11/20 20:39:04 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/* ************************************************************************** */

# include <fcntl.h>  // open(), close()
# include "../mlx/mlx.h"
# include "../my_lib/inc/libft.h"
# include "my_figure.h"
# include "error_handling.h"
# include "get_next_line.h"
# include "string_list.h"

/* ************************************************************************** */

//	Define for window & img

# define W_W_			1920	// Window Width preset
# define W_H_			1080	// Window Height preset
# define W_PADDING_		30		// Window Padding preset
# define COLOR_RED_		0x00FF0000
# define COLOR_GREEN_	0x0000FF00
# define COLOR_BLUE_	0x000000FF
# define COLOR_WHITE_	0x00FFFFFF
# define COLOR_PRESET_	COLOR_WHITE_
# define GAP_PRESET_	100
# define VIEW_POINT_X_	100
# define VIEW_POINT_Y_	100
# define VIEW_POINT_Z_	100
# define ALTITUDE_CONST	8

/* ************************************************************************** */

//	Define for actions

# define EVENT_KET_PRESS_	2
# define EVENT_KEY_RELEASE_	3
# define KEY_ESC_			53

/* ************************************************************************** */

// FDF STRUCT

typedef struct s_image_data
{
	void	*img_ptr_;
	char	*addr_;
	int		bits_per_pixel_;
	int		size_line_;
	int		endian_;
}	t_img;

typedef struct s_fdf_map
{
	int			width_;
	int			height_;
	int			**altitude_;
}	t_map;

typedef struct s_projected_map
{
	int			width_;
	int			height_;
	int			gap_;
	t_p_vec		**matrix_;
	int			img_width_;
	int			img_height;
}	t_p_map;

typedef struct s_fdf_pointers
{
	void	*mlx_ptr_;
	void	*win_ptr_;
	t_img	*img_;
	t_map	*map_;
	t_p_map	*p_map_;
}	t_ptrs;

/* ************************************************************************** */

//	ENUM for array

typedef enum e_edge
{
	top_ = 0,
	bottom_,
	left_,
	right_
}	t_edge;

typedef enum e_axis
{
	x_ = 0,
	y_,
	z_
}	t_axis;

/* ************************************************************************** */

// FDF ERROR Handling Macro

# define ERR_INVALID_DATA_WIDTH "Invalid width data......"
# define ERR_INVALID_DATA_HEIGHT "Invalid height data......"
# define ERR_INVALID_DATA_ALTITUDE "Invalid altitude data......"

/* ************************************************************************** */

//	UTILS

// 		actions.c
int			actions(int keycode, t_ptrs *ptrs);
void		prep_action(t_ptrs *ptrs, t_img *img, t_map *map, t_p_map *p_map);

//		draw_2d_segment.c
void		draw_segment(t_img *img, t_p_vec *a, t_p_vec *b, int color);

//		draw_2d_vector.c
void		put_pixel(t_img *img, int x, int y, int color);
void		draw_vector(t_img *img, t_p_vec *vector, int color);

//		draw_projection_to_img.c
void		draw_projection_to_img(t_img *img, t_p_map *projection, int color);

//		error_handling.c : Functions are declared in error_handling.h 

// 		map_object_management.c
t_map		*make_new_map(void);
void		*terminate_map(t_map *map);
t_map		*set_essential_map_data(t_map *map);

//		p_map_object_management.c
t_p_map		*make_new_projection(int width, int height);
void		*terminate_projection(t_p_map *projection);

//		projection.c
void		get_projection_result(t_map *map, t_p_map *p_map, t_3d_vec *view_p);

//		view_point.c
t_3d_vec	*set_view_point(t_map *map, t_3d_vec *view_point);

/* ************************************************************************** */

// PARSING_TOOLS

//		ect_functions.c
void		check_argv(int argc, char **argv);
void		*terminate_ft_split_result(char **str_arr);
int			get_width(char *str_to_split);
t_validity	check_is_num_str(char *num_str);

//		get_map_data.c
t_map		*get_map_data(t_map *map, const char *file_name);

//		get_next_line_utils.c & get_next_line.c
//			-> Functions are declared in get_next_line.h 

// 		string_list_1.c & string_list_2.c
//			-> Functions are declared in string_list.h

/* ************************************************************************** */

#endif
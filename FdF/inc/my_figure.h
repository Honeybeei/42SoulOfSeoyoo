/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_figure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 00:40:32 by seoyoo            #+#    #+#             */
/*   Updated: 2022/11/15 12:16:08 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_FIGURE_H
# define MY_FIGURE_H

/* ************************************************************************** */

# include <stdlib.h> // malloc(), free()
# include <math.h>  // floor()
# include "error_handling.h"

/* ************************************************************************** */

// Basic figures

typedef struct s_two_dimensional_vector
{
	double	x_;
	double	y_;
}	t_2d_vec;

typedef struct s_three_dimensional_vector
{
	double	x_;
	double	y_;
	double	z_;
}	t_3d_vec;

typedef struct s_two_dimensional_segment
{
	t_2d_vec	a_;
	t_2d_vec	b_;
}	t_2d_seg;

/* ************************************************************************** */

// Figures specialized for printing. 
typedef struct s_printable_two_dimensional_vector
{
	int	x_;
	int	y_;
}	t_p_vec;

/* ************************************************************************** */

//	get_distance.c
double		get_distance_between_3d_vec(t_3d_vec *v1, t_3d_vec *v2);
double		get_distance_from_center_to_3d_vec(t_3d_vec *v);

//	printable_2d_vector.c
t_p_vec		*make_p_vec(int x, int y);
void		*terminate_p_vec(t_p_vec *vector);
t_p_vec		*set_p_vec(t_p_vec *target, int x, int y);

//	three_dimensional_vector.c
t_3d_vec	*make_3d_vec(double x, double y, double z);
void		*terminate_3d_vec(t_3d_vec *vector);
t_3d_vec	*set_3d_vec(t_3d_vec *target_vec, double x, double y, double z);

//	two_dimensional_segment.c
t_2d_seg	*make_2d_seg(t_2d_vec *a, t_2d_vec *b);
void		*terminate_2d_seg(t_2d_seg *segment);
t_2d_seg	*set_2d_seg(t_2d_seg *target_seg, t_2d_vec *a, t_2d_vec *b);

// 	two_dimensional_vector.c
t_2d_vec	*make_2d_vec(double x, double y);
void		*terminate_2d_vec(t_2d_vec *vector);
t_2d_vec	*set_2d_vec(t_2d_vec *target_vec, double x, double y);

/* ************************************************************************** */

#endif
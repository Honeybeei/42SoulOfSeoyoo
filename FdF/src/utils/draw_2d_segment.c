/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2d_segment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:05:12 by seoyoo            #+#    #+#             */
/*   Updated: 2022/11/16 18:57:18 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

static void	set_start_end(t_p_vec *start, t_p_vec *end, t_p_vec *a, t_p_vec *b);
static void	draw_non_slope_seg(t_img *img, t_p_vec *a, t_p_vec *b, int color);
static void	draw_pos_slope_seg(t_img *img, t_p_vec *a, t_p_vec *b, int color);
static void	draw_neg_slope_seg(t_img *img, t_p_vec *a, t_p_vec *b, int color);

/* ************************************************************************** */

/**
 * @brief Draw two dimensional segment between coordinate a and b. 
 * 
 * @param img 
 * @param a 
 * @param b 
 * @param color 
 */
void	draw_segment(t_img *img, t_p_vec *a, t_p_vec *b, int color)
{
	int	dx;
	int	dy;

	dx = b->x_ - a->x_;
	dy = b->y_ - a->y_;
	if (dx == 0 && dy == 0)
		draw_vector(img, a, color);
	else if (dx == 0 || dy == 0)
		draw_non_slope_seg(img, a, b, color);
	else if (dx * dy > 0)
		draw_pos_slope_seg(img, a, b, color);
	else
		draw_neg_slope_seg(img, a, b, color);
}

/* ************************************************************************** */

static void	set_start_end(t_p_vec *start, t_p_vec *end, t_p_vec *a, t_p_vec *b)
{
	if (start == NULL || end == NULL || a == NULL || b == NULL)
		print_error_exit(ERR_EMPTY_PTR);
	if (a->x_ < b->x_)
	{
		set_p_vec(start, a->x_, a->y_);
		set_p_vec(end, b->x_, b->y_);
	}
	else if (a->x_ > b->x_)
	{
		set_p_vec(start, b->x_, b->y_);
		set_p_vec(end, a->x_, a->y_);
	}
	else
	{
		if (a->y_ < b->y_)
		{
			set_p_vec(start, a->x_, a->y_);
			set_p_vec(end, b->x_, b->y_);
		}
		else
		{
			set_p_vec(start, b->x_, b->y_);
			set_p_vec(end, a->x_, a->y_);
		}
	}
}

/* ************************************************************************** */

static void	draw_non_slope_seg(t_img *img, t_p_vec *a, t_p_vec *b, int color)
{
	int		d;
	t_p_vec	start;
	t_p_vec	end;

	set_start_end(&start, &end, a, b);
	d = 0;
	if (a->x_ == b->x_)
	{
		while (start.y_ + d < end.y_)
		{
			put_pixel(img, start.x_, start.y_ + d, color);
			d++;
		}
	}
	else
	{
		while (start.x_ + d < end.x_)
		{
			put_pixel(img, start.x_ + d, start.y_, color);
			d++;
		}
	}
}

/* ************************************************************************** */

static void	draw_pos_slope_seg(t_img *img, t_p_vec *a, t_p_vec *b, int color)
{
	t_p_vec	start;
	t_p_vec	end;
	double	slope;
	int		dx;
	int		dy;

	set_start_end(&start, &end, a, b);
	slope = (double)(end.y_ - start.y_) / (end.x_ - start.x_);
	dx = 0;
	while (start.x_ + dx < end.x_)
	{
		dy = (int)(floor(dx * slope + 0.5));
		put_pixel(img, start.x_ + dx, start.y_ + dy, color);
		dx++;
	}
	dy = 0;
	while (start.y_ + dy < end.y_)
	{
		dx = (int)(floor(dy / slope) + 0.5);
		put_pixel(img, start.x_ + dx, start.y_ + dy, color);
		dy++;
	}
}

/* ************************************************************************** */

static void	draw_neg_slope_seg(t_img *img, t_p_vec *a, t_p_vec *b, int color)
{
	t_p_vec	start;
	t_p_vec	end;
	double	slope;
	int		dx;
	int		dy;

	set_start_end(&start, &end, a, b);
	slope = (double)(end.y_ - start.y_) / (end.x_ - start.x_);
	dx = 0;
	while (start.x_ + dx < end.x_)
	{
		dy = (int)(floor(dx * slope + 0.5));
		put_pixel(img, start.x_ + dx, start.y_ + dy, color);
		dx++;
	}
	dy = 0;
	while (start.y_ + dy > end.y_)
	{
		dx = (int)(floor(dy * (1 / slope)) + 0.5);
		put_pixel(img, start.x_ + dx, start.y_ + dy, color);
		dy--;
	}
}

/* ************************************************************************** */
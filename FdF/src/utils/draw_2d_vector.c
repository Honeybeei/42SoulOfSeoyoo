/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2d_vector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:54:23 by seoyoo            #+#    #+#             */
/*   Updated: 2022/11/16 15:54:16 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

/* ************************************************************************** */

/**
 * @brief Put a single pixel to an image. 
 * 
 * @param img 
 * @param x 
 * @param y 
 * @param color 
 */
void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr_;
	dst += y * img->size_line_;
	dst += x * (img->bits_per_pixel_ / 8);
	*(unsigned int *)dst = color;
}

/* ************************************************************************** */

/**
 * @brief Draw printable vector to an image.
 * 
 * @param img 
 * @param vector 
 * @param color 
 */
void	draw_vector(t_img *img, t_p_vec *vector, int color)
{
	put_pixel(img, vector->x_, vector->y_, color);
}

/* ************************************************************************** */
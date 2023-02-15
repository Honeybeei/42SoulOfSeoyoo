/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 21:14:05 by seoyoo            #+#    #+#             */
/*   Updated: 2022/11/10 22:23:42 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/get_next_line.h"

/*
This function makes new head pointer node. 
*/
t_h_p_node	*make_new_h_p_node(int fd)
{
	t_h_p_node	*h_p_node;

	h_p_node = malloc(sizeof(t_h_p_node));
	h_p_node->fd = fd;
	h_p_node->head = NULL;
	h_p_node->next = NULL;
	return (h_p_node);
}

/*
This function makes new buffer pointing node which also has information about 
start index, end index, read count(result of read()), and next buffer node's 
address.
*/
t_b_node	*make_new_b_node(int fd)
{
	t_b_node	*new_node;

	new_node = malloc(sizeof(t_b_node));
	if (new_node == NULL)
		return (NULL);
	new_node->read_cnt = read(fd, new_node->buffer, BUFFER_SIZE);
	if (new_node->read_cnt <= 0)
	{
		free(new_node);
		return (NULL);
	}
	new_node->start = 0;
	new_node->end = find_closest_end(new_node);
	new_node->next = NULL;
	return (new_node);
}

/*
This function finds the closest ending point from starting point. End point must 
be new line character('\n') or the last character of current fd.
WARNING : If current buffer's last character is the last character of current
file(EOF), end is still set to -1. Therefore, in this case, current buffer's end
will be -1 and next buffer will be null. Use this to make sure the function ends
properly. 
*/
ssize_t	find_closest_end(t_b_node *buffer_node)
{
	ssize_t	idx;

	idx = buffer_node->start;
	while (idx < buffer_node->read_cnt)
	{
		if (buffer_node->buffer[idx] == '\n')
			return (idx);
		idx++;
	}
	if (buffer_node->read_cnt < BUFFER_SIZE)
		return (buffer_node->read_cnt - 1);
	return (-1);
}

/*
Function from libft
*/
void	*gnl_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*temp_src;
	unsigned char	*temp_dst;

	if (src != dst)
	{
		temp_src = (unsigned char *)src;
		temp_dst = (unsigned char *)dst;
		i = 0;
		while (i < n)
		{
			temp_dst[i] = temp_src[i];
			i++;
		}
	}
	return (dst);
}

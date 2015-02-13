/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_south.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvolberg <dvolberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 19:02:44 by dvolberg          #+#    #+#             */
/*   Updated: 2015/01/27 19:58:44 by dvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_south(t_env *env, t_pt3d pt0, t_pt3d pt1, float *d)
{
	float	ez;
	float	ht;

	ht = (pt1.z - pt0.z) / d[Y];
	ez = pt0.z;
	while (pt0.y < pt1.y)
	{
		ft_put_pixel_in_image(env, pt0, ez);
		ez += ht;
		pt0.y++;
	}
}

void	ft_south_east(t_env *env, t_pt3d pt0, t_pt3d pt1, float *d)
{
	float	e;
	float	ez;
	float	ht;

	ht = (pt1.z - pt0.z) / d[Y];
	ez = pt0.z;
	e = d[Y];
	d[Y] = e * 2;
	d[X] = d[X] * 2;
	while (1)
	{
		ft_put_pixel_in_image(env, pt0, ez);
		ez += ht;
		pt0.y += 1;
		if (pt0.y >= pt1.y)
			break ;
		e -= d[X];
		if (e < 0.0)
		{
			pt0.x += 1;
			e += d[Y];
		}
	}
}

void	ft_south_west(t_env *env, t_pt3d pt0, t_pt3d pt1, float *d)
{
	float	e;
	float	ez;
	float	ht;

	ht = (pt1.z - pt0.z) / d[Y];
	ez = pt0.z;
	e = d[Y];
	d[Y] = e * 2;
	d[X] = d[X] * 2;
	while (1)
	{
		ft_put_pixel_in_image(env, pt0, ez);
		ez += ht;
		pt0.y += 1;
		if (pt0.y >= pt1.y)
			break ;
		e += d[X];
		if (e <= 0.0)
		{
			pt0.x -= 1;
			e += d[Y];
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_west.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvolberg <dvolberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 19:03:13 by dvolberg          #+#    #+#             */
/*   Updated: 2015/01/27 19:57:53 by dvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_west(t_env *env, t_pt3d pt0, t_pt3d pt1, float *d)
{
	float	ez;
	float	ht;

	ht = (pt1.z - pt0.z) / -d[X];
	ez = pt0.z;
	while (pt0.x > pt1.x)
	{
		ft_put_pixel_in_image(env, pt0, ez);
		ez += ht;
		pt0.x--;
	}
}

void	ft_west_north(t_env *env, t_pt3d pt0, t_pt3d pt1, float *d)
{
	float	e;
	float	ez;
	float	ht;

	ht = (pt1.z - pt0.z) / -d[Y];
	ez = pt0.z;
	e = d[Y];
	d[Y] = e * 2;
	d[X] = d[X] * 2;
	while (1)
	{
		ft_put_pixel_in_image(env, pt0, ez);
		ez += ht;
		pt0.y -= 1;
		if (pt0.y <= pt1.y)
			break ;
		e -= d[X];
		if (e >= 0.0)
		{
			pt0.x -= 1;
			e += d[Y];
		}
	}
}

void	ft_west_south(t_env *env, t_pt3d pt0, t_pt3d pt1, float *d)
{
	float	e;
	float	ez;
	float	ht;

	ht = (pt1.z - pt0.z) / -d[X];
	ez = pt0.z;
	e = d[X];
	d[X] = e * 2;
	d[Y] = d[Y] * 2;
	while (1)
	{
		ft_put_pixel_in_image(env, pt0, ez);
		ez += ht;
		pt0.x -= 1;
		if (pt0.x <= pt1.x)
			break ;
		e += d[Y];
		if (e >= 0.0)
		{
			pt0.y += 1;
			e += d[X];
		}
	}
}

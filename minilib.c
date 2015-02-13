/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvolberg <dvolberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/18 19:08:01 by dvolberg          #+#    #+#             */
/*   Updated: 2015/01/27 21:31:43 by dvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	ft_dtor(float degre)
{
	return (3.14159 * degre / 180);
}

float	ft_abs(float n)
{
	return ((n < 0.0) ? -n : n);
}

int		ft_max(int n1, int n2)
{
	return ((n1 > n2) ? n1 : n2);
}

int		ft_min(int n1, int n2)
{
	return ((n1 < n2) ? n1 : n2);
}

int		expose_hook(t_env *env)
{
	if (ft_strlen(env->char_img))
		mlx_destroy_image(env->mlx, env->img);
	ft_make_draw(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	return (0);
}

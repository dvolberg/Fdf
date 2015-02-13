/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvolberg <dvolberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/31 04:29:53 by dvolberg          #+#    #+#             */
/*   Updated: 2015/01/27 21:33:24 by dvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_make_mx(float mx[3][3], t_env *env)
{
	mx[0][0] = 1;
	mx[0][1] = 0;
	mx[0][2] = 0;
	mx[1][0] = 0;
	mx[1][1] = cos(ft_dtor(env->angle[0]));
	mx[1][2] = -sin(ft_dtor(env->angle[0]));
	mx[2][0] = 0;
	mx[2][1] = sin(ft_dtor(env->angle[0]));
	mx[2][2] = cos(ft_dtor(env->angle[0]));
}

void	ft_make_my(float my[3][3], t_env *env)
{
	my[0][0] = cos(ft_dtor(env->angle[1]));
	my[0][1] = 0;
	my[0][2] = sin(ft_dtor(env->angle[1]));
	my[1][0] = 0;
	my[1][1] = 1;
	my[1][2] = 0;
	my[2][0] = -sin(ft_dtor(env->angle[1]));
	my[2][1] = 0;
	my[2][2] = cos(ft_dtor(env->angle[1]));
}

void	ft_make_mz(float mz[3][3], t_env *env)
{
	mz[0][0] = cos(ft_dtor(env->angle[2]));
	mz[0][1] = -sin(ft_dtor(env->angle[2]));
	mz[0][2] = 0;
	mz[1][0] = sin(ft_dtor(env->angle[2]));
	mz[1][1] = cos(ft_dtor(env->angle[2]));
	mz[1][2] = 0;
	mz[2][0] = 0;
	mz[2][1] = 0;
	mz[2][2] = 1;
}

void	ft_make_draw(t_env *env)
{
	unsigned int		i;
	unsigned int		j;

	i = 0;
	while (i < env->height_tab)
	{
		j = 0;
		while (j < env->width_tab)
		{
			if (j + 1 < env->width_tab)
				ft_draw_line_in_image(env, env->tab[i][j], env->tab[i][j + 1]);
			if (env->tab[i + 1])
				ft_draw_line_in_image(env, env->tab[i][j], env->tab[i + 1][j]);
			j++;
		}
		i++;
	}
}

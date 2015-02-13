/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvolberg <dvolberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 18:57:20 by dvolberg          #+#    #+#             */
/*   Updated: 2015/01/27 23:00:21 by dvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_white(int *b, int *g, int *r)
{
	*b = 255;
	*g = 255;
	*r = 255;
}

static void	ft_init_env(t_env *env)
{
	env->height = 1200;
	env->width = 1800;
	env->height_img = env->height;
	env->width_img = env->width;
	env->zoom = ft_max(env->height, env->width);
	env->origin_img = (t_pt2d *)malloc(sizeof(t_pt2d));
	env->origin_img->x = 0;
	env->origin_img->y = 0;
	env->angle[0] = 0;
	env->angle[1] = 0;
	env->angle[2] = 0;
}

static char	*ft_gettt(t_env *env)
{
	char	*ii;

	ii = mlx_get_data_addr(env->img, &env->bbp, &env->size_line, &env->endian);
	return (ii);
}

int			main(int ac, char **av)
{
	t_env	env;

	ft_init_env(&env);
	if (ac == 2)
	{
		ft_gettab(&env, av[1], &env.height_tab, &env.width_tab);
		ft_proj_tab_iso(&env);
		env.memo = ft_regu_tab(&env);
		ft_zoom_tab(&env, env.memo, 1);
		if (!(env.mlx = mlx_init()))
		{
			ft_putendl_fd("Probleme d'env", 2);
			exit (1);
		}
		env.win = mlx_new_window(env.mlx, env.width, env.height, "FDF maggle");
		env.img = mlx_new_image(env.mlx, env.width_img, env.height_img);
		env.char_img = ft_gettt(&env);
		mlx_key_hook(env.win, key_hook, &env);
		mlx_expose_hook(env.win, expose_hook, &env);
		mlx_loop(env.mlx);
	}
	else
		ft_putendl_fd("Le programme a besoin que d'un seul argument", 2);
	return (0);
}

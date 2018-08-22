/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_key_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 11:23:39 by srabah            #+#    #+#             */
/*   Updated: 2016/03/16 15:32:32 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	clear_init(t_env *e, t_thrarg *threads)
{
	int		tmp;

	mlx_destroy_image(e->mlx, e->img);
	if (!(e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT)))
		exit(1);
	e->img_addr = mlx_get_data_addr(e->img, &tmp, &tmp, &tmp);
	mlx_clear_window(e->mlx, e->win);
	core_init_threads(threads);
}

int			core_key_hook(int key, t_thrarg *threads)
{
	t_env	*e;

	e = threads[0].e;
	if (key == KEY_L)
		e->select = 5;
	if (key == KEY_K)
		e->select = 7;
	if (key == KEY_C)
		e->select = 6;
	if (e->select == 1)
		hook_cylindre(key, e);
	else if (e->select == 2)
		hook_sphere(key, e);
	else if (e->select == 3)
		hook_plan(key, e);
	else if (e->select == 4)
		hook_cone(key, e);
	else if (e->select == 5)
		hook_light(key, e);
	else if (e->select == 6)
		hook_cam(key, e);
	else if (e->select == 7)
		hook_light_bis(key, e);
	clear_init(e, threads);
	return (1);
}

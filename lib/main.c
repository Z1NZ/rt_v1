/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 11:58:14 by srabah            #+#    #+#             */
/*   Updated: 2016/03/16 15:58:27 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_lims		new_lims(int x, int y)
{
	t_lims	l;

	l.ymin = x;
	l.ymax = y;
	return (l);
}

void		init_threads(t_env *e, t_thrarg *threads)
{
	int		i;

	i = -1;
	while (++i < NUM_THREADS)
	{
		threads[i].lims = new_lims(i * HEIGHT / NUM_THREADS,
			(i + 1) * HEIGHT / NUM_THREADS);
		threads[i].e = e;
	}
}

void		windows_init(void)
{
	int			nb[5];
	t_env		*e;
	t_thrarg	threads[NUM_THREADS];

	e = ft_memalloc(sizeof(t_env));
	if (!(e->mlx = mlx_init()))
		exit(-2);
	if (!(e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "RAY-TRACING")))
		exit(1);
	if (!(e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT)))
		exit(1);
	e->img_addr = mlx_get_data_addr(e->img, &nb[0], &nb[3], &nb[4]);
	init_cylindre(e);
	init_sphere(e);
	init_plan(e);
	init_cone(e);
	init_cam(e);
	init_light(e);
	init_light_bis(e);
	init_threads(e, threads);
	core_init_threads(threads);
	mlx_hook(e->win, KEYPRESS, KEYPRESSMASK, core_key_hook, threads);
	mlx_mouse_hook(e->win, core_mouse_hook, threads);
	mlx_loop(e->mlx);
}

int			main(void)
{
	windows_init();
	return (0);
}

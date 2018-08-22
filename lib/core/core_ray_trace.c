/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_ray_trace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 11:26:43 by srabah            #+#    #+#             */
/*   Updated: 2016/03/17 21:29:50 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <unistd.h>
#include <pthread.h>

static	void	hub_hit(t_ray ray, t_env *e, int *color)
{
	double	hit;

	hit = 0.00;
	if (hit_light(ray, e->light, &hit))
		*color = e->light.color;
	if (hit_light_bis(ray, e->light_bis, &hit))
		*color = e->light_bis.color;
	if (hit_sphere(ray, e->sphere, &hit))
		if ((*color = shadow_sphere(ray, e, hit)) == 1)
			*color = core_color_add(expo_pixel_sphere(ray, e, e->light, hit),
				expo_pixel_sphere(ray, e, e->light_bis, hit));
	if (hit_plan(ray, e->plan, &hit))
		if ((*color = shadow_plan(ray, e, hit)) == 1)
			*color = core_color_add(expo_pixel_plan(ray, e, e->light, hit),
				expo_pixel_plan(ray, e, e->light_bis, hit));
	if (hit_cone(ray, e->cone, &hit))
		if ((*color = shadow_cone(ray, e, hit)) == 1)
			*color = core_color_add(expo_pixel_cone(ray, e, e->light, hit),
				expo_pixel_cone(ray, e, e->light_bis, hit));
	if (hit_cylindre(ray, e->cylindre, &hit))
		if ((*color = shadow_cylindre(ray, e, hit)) == 1)
			*color = core_color_add(expo_pixel_cylindre(ray, e, e->light, hit),
				expo_pixel_cylindre(ray, e, e->light_bis, hit));
}

void			*core_ray_trace(void *data)
{
	int		h;
	int		w;
	t_ray	ray;
	int		color;
	t_env	*e;

	e = ((t_thrarg *)data)->e;
	h = ((t_thrarg *)data)->lims.ymin;
	ray.org = e->cam.org;
	e->light.hue = e->light.ka * e->light.ia;
	e->light_bis.hue = e->light_bis.ka * e->light_bis.ia;
	while (h < ((t_thrarg *)data)->lims.ymax)
	{
		w = -1;
		while (++w < WIDTH)
		{
			ray = core_ray_init(ray, w, h);
			color = 0x00ffff;
			ray.dir = matrice_core(ray, e);
			hub_hit(ray, e, &color);
			core_put_pixel(w, h, color, e);
		}
		h++;
	}
	pthread_exit(NULL);
}

void			core_init_threads(t_thrarg *arg)
{
	pthread_t	threads[NUM_THREADS];
	int			i;

	i = -1;
	while (++i < NUM_THREADS)
		pthread_create(&threads[i], NULL, &core_ray_trace, arg + i);
	i = -1;
	while (++i < NUM_THREADS)
		pthread_join(threads[i], NULL);
	mlx_put_image_to_window(arg[0].e->mlx, arg[0].e->win, arg[0].e->img, 0, 0);
}

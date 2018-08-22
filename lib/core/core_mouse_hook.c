/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_mouse_hook.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 11:24:44 by srabah            #+#    #+#             */
/*   Updated: 2016/03/17 21:30:09 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			core_mouse_hook(int bouton, int x, int y, t_thrarg *threads)
{
	double	touch;
	t_ray	ray;
	t_env	*e;

	e = threads[0].e;
	e->select = 0;
	touch = 0.00;
	ray = core_ray_init(ray, x, y);
	ray.org = e->cam.org;
	ray.dir = matrice_core(ray, e);
	(void)bouton;
	if (hit_cylindre(ray, e->cylindre, &touch))
		e->select = 1;
	if (hit_sphere(ray, e->sphere, &touch))
		e->select = 2;
	if (hit_plan(ray, e->plan, &touch))
		e->select = 3;
	if (hit_cone(ray, e->cone, &touch))
		e->select = 4;
	if (hit_light(ray, e->light, &touch))
		e->select = 5;
	if (hit_light_bis(ray, e->light_bis, &touch))
		e->select = 7;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_cone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 12:00:40 by srabah            #+#    #+#             */
/*   Updated: 2016/03/17 22:19:17 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static double	hub_hit_shadow_cone(t_env *e, t_ray shadow)
{
	double touch;

	touch = 0.00;
	hit_sphere(shadow, e->sphere, &touch);
	hit_cylindre(shadow, e->cylindre, &touch);
	return (touch);
}

int				shadow_cone(t_ray ray, t_env *e, double hit)
{
	t_ray		shadow;
	double		touch;
	double		touch_p;

	touch_p = 0.00;
	touch = 0.00;
	shadow.org = vector_add(ray.org, vector_scalar(ray.dir, hit));
	shadow.dir = vector_sub(e->light.org, shadow.org);
	touch = hub_hit_shadow_cone(e, shadow);
	shadow.dir = vector_sub(e->light_bis.org, shadow.org);
	touch_p = hub_hit_shadow_cone(e, shadow);
	if (touch && touch_p)
		return (core_color_shadow(e->cone.color, 4));
	else if (touch || touch_p)
		return (core_color_shadow(e->cone.color, 2));
	return (1);
}

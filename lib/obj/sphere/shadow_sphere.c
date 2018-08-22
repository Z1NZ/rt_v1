/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 11:38:48 by srabah            #+#    #+#             */
/*   Updated: 2016/03/17 22:19:42 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static double	hub_hit_shadow_sphere(t_env *e, t_ray shadow)
{
	double touch;

	touch = 0.00;
	hit_cylindre(shadow, e->cylindre, &touch);
	hit_cone(shadow, e->cone, &touch);
	return (touch);
}

int				shadow_sphere(t_ray ray, t_env *e, double hit)
{
	t_ray		shadow;
	double		touch;
	double		touch_p;

	touch = 0.00;
	touch_p = 0.00;
	shadow.org = vector_add(ray.org, vector_scalar(ray.dir, hit));
	shadow.dir = vector_sub(e->light.org, shadow.org);
	touch = hub_hit_shadow_sphere(e, shadow);
	shadow.dir = vector_sub(e->light_bis.org, shadow.org);
	touch_p = hub_hit_shadow_sphere(e, shadow);
	if (touch && touch_p)
		return (core_color_shadow(e->sphere.color, 4));
	else if (touch || touch_p)
		return (core_color_shadow(e->sphere.color, 2));
	return (1);
}

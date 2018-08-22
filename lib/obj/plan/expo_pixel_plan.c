/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expo_pixel_plan.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 11:44:16 by srabah            #+#    #+#             */
/*   Updated: 2016/03/16 15:35:01 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** l est la direction du rayon de lumière
** n la normale à la surface//  le vecteur directeur du rayon réfléchi
** v le vecteur direction de la vue
*/

#include "rt.h"

int			expo_pixel_plan(t_ray ray, t_env *e, t_light light, double hit)
{
	t_vector	l;
	t_vector	n;
	t_vector	v;
	t_vector	h;
	t_vector	plan_dir;

	plan_dir = vector_normalise(e->plan.n);
	l = vector_sub(light.org, vector_scalar(ray.dir, hit));
	l = vector_normalise(l);
	v = vector_normalise(vector_sub(ray.org, vector_scalar(ray.dir, hit)));
	h = vector_normalise(vector_add(l, v));
	n = vector_normalise(e->plan.n);
	v = vector_normalise(v);
	return (core_color_spec(light.color, e->plan.color, light.hue + light.kd *
		vector_dot_product(l, n), light.ks * pow(vector_dot_product(h, n),
		light.n)));
}

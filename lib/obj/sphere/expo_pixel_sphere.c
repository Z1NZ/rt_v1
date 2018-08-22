/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expo_pixel_sphere.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 11:44:01 by srabah            #+#    #+#             */
/*   Updated: 2016/03/17 19:25:00 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
** l est la direction du rayon de lumière
** n la normale à la surface
** r le vecteur directeur du rayon réfléchi
** v  le vecteur direction de la vue
*/

int		expo_pixel_sphere(t_ray ray, t_env *e, t_light light, double hit)
{
	t_vector l;
	t_vector n;
	t_vector r;
	t_vector v;

	l = vector_sub(light.org, vector_add(ray.org,
		vector_scalar(ray.dir, hit)));
	n = vector_sub(vector_add(ray.org,
		vector_scalar(ray.dir, hit)), e->sphere.org);
	v = vector_scalar(ray.dir, hit);
	l = vector_normalise(l);
	n = vector_normalise(n);
	v = vector_normalise(v);
	r = vector_sub(l, vector_mult(n, 2 * vector_dot_product(l, n)));
	r = vector_normalise(r);
	return (core_color_spec(light.color, e->sphere.color, light.hue +
		light.kd * vector_dot_product(l, n), light.ks *
		pow(vector_dot_product(v, r), light.n)));
}

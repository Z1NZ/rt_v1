/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expo_pixel_cylindre.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 11:49:06 by srabah            #+#    #+#             */
/*   Updated: 2016/03/17 21:18:32 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
** l est la direction du rayon de lumière
** n  la normale à la surface//  le vecteur directeur du rayon réfléchi
** v  le vecteur direction de la vue
*/

int		expo_pixel_cylindre(t_ray ray, t_env *e, t_light light, double hit)
{
	t_vector	l;
	t_vector	n;
	t_vector	v;
	t_vector	h;
	double		m;

	h = vector_normalise(e->cylindre.axe);
	l = vector_sub(ray.org, e->cylindre.org);
	m = vector_dot_product(ray.dir, h) * hit + vector_dot_product(l, h);
	l = vector_sub(light.org, vector_scalar(ray.dir, hit));
	l = vector_normalise(l);
	n = vector_sub(vector_add(ray.org, vector_scalar(ray.dir, hit)),
		e->cylindre.org);
	n = vector_sub(n, vector_scalar(h, m));
	v = vector_normalise(vector_sub(ray.org, vector_scalar(ray.dir, hit)));
	h = vector_normalise(vector_add(l, v));
	n = vector_normalise(n);
	v = vector_normalise(v);
	return (core_color_spec(light.color, e->cylindre.color, light.hue +
			light.kd * vector_dot_product(l, n), light.ks *
			pow(vector_dot_product(h, n), light.n)));
}

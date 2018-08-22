/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 11:41:27 by srabah            #+#    #+#             */
/*   Updated: 2016/03/17 19:14:20 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		hit_sphere(t_ray ray, t_sphere sphere, double *hit)
{
	double		delta;
	t_vector	abc;
	t_vector	rep;

	rep = vector_sub(ray.org, sphere.org);
	abc.x = vector_dot_product(ray.dir, ray.dir);
	abc.y = 2 * (ray.dir.x * (rep.x) + (ray.dir.y * (rep.y)) + (ray.dir.z *
			(rep.z)));
	abc.z = (rep.x) * (rep.x) + (rep.y) * (rep.y) + (rep.z) * (rep.z) -
		(sphere.rayon * sphere.rayon);
	delta = abc.y * abc.y - 4 * abc.x * abc.z;
	if (delta < 0)
		return (0);
	else
		return (core_ret(abc, &(*hit), delta));
}

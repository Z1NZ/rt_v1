/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 11:58:43 by srabah            #+#    #+#             */
/*   Updated: 2016/03/17 19:16:01 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		hit_cone(t_ray ray, t_cone cone, double *hit)
{
	double		delta;
	double		c[3];
	t_vector	tcal;
	t_vector	abc;

	cone.axe = vector_normalise(cone.axe);
	tcal = vector_sub(ray.org, cone.org);
	c[2] = tan(cone.anno / 2);
	c[2] = 1 + c[2] * c[2];
	c[0] = vector_dot_product(ray.dir, cone.axe);
	c[1] = vector_dot_product(tcal, cone.axe);
	abc.x = vector_dot_product(ray.dir, ray.dir) - (c[2]) * (c[0] * c[0]);
	abc.y = 2 * (vector_dot_product(ray.dir, tcal) - (c[2]) * c[0] * c[1]);
	abc.z = vector_dot_product(tcal, tcal) - (c[2]) * (c[1] * c[1]);
	delta = abc.y * abc.y - 4 * abc.x * abc.z;
	if (delta < 0)
		return (0);
	else
		return (core_ret(abc, &(*hit), delta));
}

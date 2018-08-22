/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylindre.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 11:49:28 by srabah            #+#    #+#             */
/*   Updated: 2016/03/17 19:19:19 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		hit_cylindre(t_ray ray, t_cylindre cylindre, double *hit)
{
	double		delta;
	t_vector	abc;
	t_vector	cal_v;
	double		cal[3];

	cylindre.axe = vector_normalise(cylindre.axe);
	cal[0] = vector_dot_product(ray.dir, cylindre.axe);
	cal_v = vector_sub(ray.org, cylindre.org);
	cal[1] = vector_dot_product(cal_v, cylindre.axe);
	abc.x = vector_dot_product(ray.dir, ray.dir) - (cal[0] * cal[0]);
	abc.y = 2 * (vector_dot_product(ray.dir, cal_v) - cal[0] *
		vector_dot_product(cal_v, cylindre.axe));
	abc.z = vector_dot_product(cal_v, cal_v) - (cal[1] * cal[1]) -
		(cylindre.rayon * cylindre.rayon);
	delta = abc.y * abc.y - 4 * abc.x * abc.z;
	if (delta < 0)
		return (0);
	else
		return (core_ret(abc, &(*hit), delta));
}

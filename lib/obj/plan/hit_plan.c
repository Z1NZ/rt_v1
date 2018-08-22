/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plan.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 11:44:41 by srabah            #+#    #+#             */
/*   Updated: 2016/03/16 15:35:06 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		hit_plan(t_ray ray, t_plane plan, double *hit)
{
	double t;
	double p;

	p = vector_dot_product(plan.n, ray.dir);
	if (p != 0)
	{
		t = (-vector_dot_product(plan.n, ray.org) - plan.d) / p;
		if (t > 0)
		{
			if (*hit == 0)
			{
				*hit = t;
				return (1);
			}
			else if (t < *hit)
			{
				*hit = t;
				return (1);
			}
		}
		else
			return (0);
	}
	return (0);
}

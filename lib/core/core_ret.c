/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_ret.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 19:10:49 by srabah            #+#    #+#             */
/*   Updated: 2016/03/17 19:10:51 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		core_ret(t_vector abc, double *hit, double delta)
{
	double		d;

	d = (-abc.y - sqrt(delta)) / (2 * abc.x);
	if (d < 0)
	{
		d = (-abc.y + sqrt(delta)) / (2 * abc.x);
		if (d < 0)
			return (0);
	}
	if (*hit >= 0)
	{
		if (d < *hit)
			*hit = d;
		else if (*hit == 0)
			*hit = d;
		else
			return (0);
		return (1);
	}
	return (0);
}

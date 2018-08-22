/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_ray_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 21:23:26 by srabah            #+#    #+#             */
/*   Updated: 2016/03/17 21:30:26 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_ray	core_ray_init(t_ray ray, int w, int h)
{
	ray.dir.x = w - WIDTH / 2;
	ray.dir.y = h - HEIGHT / 2;
	ray.dir.z = DEEP;
	return (ray);
}

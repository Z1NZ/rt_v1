/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 11:39:24 by srabah            #+#    #+#             */
/*   Updated: 2016/03/16 15:35:42 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	init_sphere(t_env *e)
{
	e->sphere.color = 0xa00000;
	e->sphere.rayon = 16;
	e->sphere.org.x = 0;
	e->sphere.org.y = -20;
	e->sphere.org.z = 150;
}

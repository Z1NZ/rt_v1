/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 11:48:42 by srabah            #+#    #+#             */
/*   Updated: 2016/03/17 21:31:56 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	init_light(t_env *e)
{
	e->light.color = 0xffffff;
	e->light.rayon = 5;
	e->light.org.x = -120;
	e->light.org.y = -60;
	e->light.org.z = -150;
	e->light.ka = 0.5;
	e->light.kd = 0.5;
	e->light.ks = 0.75;
	e->light.ia = 0.5;
	e->light.n = 5;
}

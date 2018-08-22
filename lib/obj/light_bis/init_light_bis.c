/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_light_bis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 21:31:34 by srabah            #+#    #+#             */
/*   Updated: 2016/03/17 21:31:39 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	init_light_bis(t_env *e)
{
	e->light_bis.color = 0xff0000;
	e->light_bis.rayon = 5;
	e->light_bis.org.x = 120;
	e->light_bis.org.y = -60;
	e->light_bis.org.z = 150;
	e->light_bis.ka = 0.4;
	e->light_bis.kd = 0.5;
	e->light_bis.ks = 0.8;
	e->light_bis.ia = 0.5;
	e->light_bis.n = 5;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 12:00:31 by srabah            #+#    #+#             */
/*   Updated: 2016/03/16 15:33:48 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	init_cone(t_env *e)
{
	e->cone.color = 0x00aa00;
	e->cone.axe.x = 0;
	e->cone.axe.y = 5;
	e->cone.axe.z = 0;
	e->cone.rayon = 7;
	e->cone.org.x = -30;
	e->cone.org.y = 0;
	e->cone.org.z = 300;
	e->cone.angle.x = 0;
	e->cone.angle.y = 0;
	e->cone.angle.z = 0;
	e->cone.anno = 7;
}

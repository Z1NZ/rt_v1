/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cylindre.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 11:52:10 by srabah            #+#    #+#             */
/*   Updated: 2016/03/16 16:08:29 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	init_cylindre(t_env *e)
{
	e->cylindre.color = 0x00a0a0;
	e->cylindre.axe.x = 4;
	e->cylindre.axe.y = 1;
	e->cylindre.axe.z = 0;
	e->cylindre.angle.x = 0;
	e->cylindre.angle.y = 0;
	e->cylindre.angle.z = 0;
	e->cylindre.rayon = 7;
	e->cylindre.org.x = 3;
	e->cylindre.org.y = 0;
	e->cylindre.org.z = 300;
	e->cylindre.axe = vector_normalise(e->cylindre.axe);
}

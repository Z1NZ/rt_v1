/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_cone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 11:59:20 by srabah            #+#    #+#             */
/*   Updated: 2016/03/17 21:41:39 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	hook_cylindre_axe(int key, t_env *e)
{
	if (key == KEY_8)
		e->cone.angle.y += 0.1;
	if (key == KEY_2)
		e->cone.angle.y -= 0.1;
	if (key == KEY_6)
		e->cone.angle.x += 0.1;
	if (key == KEY_4)
		e->cone.angle.x -= 0.1;
	if (key == KEY_7)
		e->cone.angle.z += 0.1;
	if (key == KEY_9)
		e->cone.angle.z -= 0.1;
}

void		hook_cone(int key, t_env *e)
{
	if (key == UP)
		e->cone.org.y++;
	if (key == DOWN)
		e->cone.org.y--;
	if (key == RIGHT)
		e->cone.org.x++;
	if (key == LEFT)
		e->cone.org.x--;
	if (key == KEY_0)
		e->cone.org.z++;
	if (key == KEY_1)
		e->cone.org.z--;
	if (key == KEY_PLUS)
		e->cone.rayon++;
	if (key == KEY_MOINS)
		e->cone.rayon--;
	hook_cylindre_axe(key, e);
	if (key == KEY_9 || key == KEY_7 || key == KEY_4 ||
			key == KEY_6 || key == KEY_2 || key == KEY_8)
		e->cone.axe = matrice_core_obj(e->cone.axe, e->cone.angle);
}

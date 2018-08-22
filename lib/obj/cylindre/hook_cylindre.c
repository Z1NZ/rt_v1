/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_cylindre.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 11:51:30 by srabah            #+#    #+#             */
/*   Updated: 2016/03/17 18:47:25 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	hook_cylindre_axe(int key, t_env *e)
{
	if (key == KEY_8)
		e->cylindre.angle.y += 0.1;
	if (key == KEY_2)
		e->cylindre.angle.y += 0.1;
	if (key == KEY_6)
		e->cylindre.angle.x += 0.1;
	if (key == KEY_4)
		e->cylindre.angle.x += 0.1;
	if (key == KEY_7)
		e->cylindre.angle.z += 0.1;
	if (key == KEY_9)
		e->cylindre.angle.z += 0.1;
}

void		hook_cylindre(int key, t_env *e)
{
	if (key == UP)
		e->cylindre.org.y++;
	if (key == DOWN)
		e->cylindre.org.y--;
	if (key == RIGHT)
		e->cylindre.org.x++;
	if (key == LEFT)
		e->cylindre.org.x--;
	if (key == KEY_0)
		e->cylindre.org.z++;
	if (key == KEY_1)
		e->cylindre.org.z--;
	if (key == KEY_PLUS)
		e->cylindre.rayon++;
	if (key == KEY_MOINS)
		e->cylindre.rayon--;
	hook_cylindre_axe(key, e);
	if (key == KEY_9 || key == KEY_7 || key == KEY_4 ||
			key == KEY_6 || key == KEY_2 || key == KEY_8)
		e->cylindre.axe = matrice_core_obj(e->cylindre.axe, e->cylindre.angle);
}

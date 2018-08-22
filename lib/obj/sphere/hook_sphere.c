/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 11:39:56 by srabah            #+#    #+#             */
/*   Updated: 2016/03/16 15:35:37 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	hook_sphere(int key, t_env *e)
{
	if (key == UP)
		e->sphere.org.y++;
	if (key == DOWN)
		e->sphere.org.y--;
	if (key == RIGHT)
		e->sphere.org.x++;
	if (key == LEFT)
		e->sphere.org.x--;
	if (key == KEY_0)
		e->sphere.org.z++;
	if (key == KEY_1)
		e->sphere.org.z--;
	if (key == KEY_PLUS)
		e->sphere.rayon++;
	if (key == KEY_MOINS)
		e->sphere.rayon--;
}

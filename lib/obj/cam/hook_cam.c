/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_cam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 12:01:21 by srabah            #+#    #+#             */
/*   Updated: 2016/03/16 15:33:21 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	hook_cam(int key, t_env *e)
{
	if (key == UP)
		e->cam.org.y--;
	if (key == DOWN)
		e->cam.org.y++;
	if (key == RIGHT)
		e->cam.org.x++;
	if (key == LEFT)
		e->cam.org.x--;
	if (key == KEY_0)
		e->cam.org.z++;
	if (key == KEY_1)
		e->cam.org.z--;
	if (key == KEY_8)
		e->cam.angle.x += 0.1;
	if (key == KEY_2)
		e->cam.angle.x -= 0.1;
	if (key == KEY_6)
		e->cam.angle.y += 0.1;
	if (key == KEY_4)
		e->cam.angle.y -= 0.1;
	if (key == KEY_PLUS)
		e->cam.angle.z += 0.1;
	if (key == KEY_MOINS)
		e->cam.angle.z -= 0.1;
}

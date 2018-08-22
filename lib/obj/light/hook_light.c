/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 11:48:28 by srabah            #+#    #+#             */
/*   Updated: 2016/03/16 15:34:30 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	hook_light(int key, t_env *e)
{
	if (key == UP)
		e->light.org.y++;
	if (key == DOWN)
		e->light.org.y--;
	if (key == RIGHT)
		e->light.org.x++;
	if (key == LEFT)
		e->light.org.x--;
	if (key == KEY_0)
		e->light.org.z++;
	if (key == KEY_1)
		e->light.org.z--;
}

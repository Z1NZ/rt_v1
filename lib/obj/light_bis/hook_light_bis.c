/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_light_bis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 21:31:27 by srabah            #+#    #+#             */
/*   Updated: 2016/03/17 21:31:29 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	hook_light_bis(int key, t_env *e)
{
	if (key == UP)
		e->light_bis.org.y++;
	if (key == DOWN)
		e->light_bis.org.y--;
	if (key == RIGHT)
		e->light_bis.org.x++;
	if (key == LEFT)
		e->light_bis.org.x--;
	if (key == KEY_0)
		e->light_bis.org.z++;
	if (key == KEY_1)
		e->light_bis.org.z--;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_plan.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 11:45:16 by srabah            #+#    #+#             */
/*   Updated: 2016/03/16 15:35:11 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	hook_plan(int key, t_env *e)
{
	if (key == UP)
		e->plan.n.y++;
	if (key == DOWN)
		e->plan.n.y--;
	if (key == RIGHT)
		e->plan.n.x++;
	if (key == LEFT)
		e->plan.n.x--;
	if (key == SHIFT)
		e->plan.n.z++;
	if (key == CONTROL)
		e->plan.n.z--;
}

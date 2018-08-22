/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_put_pixel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 11:25:29 by srabah            #+#    #+#             */
/*   Updated: 2016/03/16 15:32:38 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	core_put_pixel(int x, int y, int color, t_env *e)
{
	int		*real;

	if (x + y * HEIGHT > WIDTH * HEIGHT
		|| x > WIDTH || y > HEIGHT || x < 0 || y < 0)
		return ;
	real = (int*)e->img_addr;
	real[x + y * WIDTH] = color;
}

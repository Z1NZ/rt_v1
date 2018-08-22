/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_colore_add.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 14:27:05 by srabah            #+#    #+#             */
/*   Updated: 2016/03/16 15:32:27 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		core_color_add(int a_color, int b_color)
{
	int color[7];

	color[0] = (a_color & 0xFF0000) >> 16;
	color[1] = (a_color & 0x00FF00) >> 8;
	color[2] = (a_color & 0x0000FF);
	color[3] = (b_color & 0xFF0000) >> 16;
	color[4] = (b_color & 0x00FF00) >> 8;
	color[5] = (b_color & 0x0000FF);
	color[5] = CLAMP((color[5] + color[2]), 0, 255);
	color[4] = CLAMP((color[4] + color[1]), 0, 255);
	color[3] = CLAMP((color[3] + color[0]), 0, 255);
	color[6] = (color[3] << 16) + (color[4] << 8) + color[5];
	return (color[6]);
}

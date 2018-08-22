/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_color_spec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 14:30:04 by srabah            #+#    #+#             */
/*   Updated: 2016/03/16 15:32:05 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		core_color_spec(int color_obj, int color_lig, double il, double ib)
{
	int color[7];

	color[0] = (color_obj & 0xFF0000) >> 16;
	color[1] = (color_obj & 0x00FF00) >> 8;
	color[2] = (color_obj & 0x0000FF);
	color[3] = (color_lig & 0xFF0000) >> 16;
	color[4] = (color_lig & 0x00FF00) >> 8;
	color[5] = (color_lig & 0x0000FF);
	color[5] = CLAMP(il * color[5] + ib * color[2], 0, 255);
	color[4] = CLAMP(il * color[4] + ib * color[1], 0, 255);
	color[3] = CLAMP(il * color[3] + ib * color[0], 0, 255);
	color[6] = (color[3] << 16) + (color[4] << 8) + color[5];
	return (color[6]);
}

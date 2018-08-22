/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_color_shadow.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 18:15:27 by srabah            #+#    #+#             */
/*   Updated: 2016/03/17 18:32:41 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		core_color_shadow(int color_obj, double p_div)
{
	int color[4];

	color[0] = (color_obj & 0xFF0000) >> 16;
	color[1] = (color_obj & 0x00FF00) >> 8;
	color[2] = (color_obj & 0x0000FF);
	color[0] = CLAMP(color[0] / p_div, 0, 255);
	color[1] = CLAMP(color[1] / p_div, 0, 255);
	color[2] = CLAMP(color[2] / p_div, 0, 255);
	color[3] = (color[2] << 16) + (color[1] << 8) + color[0];
	return (color[3]);
}

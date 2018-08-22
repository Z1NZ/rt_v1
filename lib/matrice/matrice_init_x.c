/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice_init_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 12:02:07 by srabah            #+#    #+#             */
/*   Updated: 2016/03/16 15:33:03 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_matrice	*matrice_init_x(double angle)
{
	t_matrice *ptr;

	ptr = ft_memalloc(sizeof(t_matrice));
	ptr->m[0][0] = 1.0;
	ptr->m[0][1] = 0.0;
	ptr->m[0][2] = 0.0;
	ptr->m[1][0] = 0.0;
	ptr->m[1][1] = cos(angle);
	ptr->m[1][2] = -sin(angle);
	ptr->m[2][0] = 0.0;
	ptr->m[2][1] = sin(angle);
	ptr->m[2][2] = cos(angle);
	return (ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice_init_z.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 12:02:16 by srabah            #+#    #+#             */
/*   Updated: 2016/03/16 15:33:10 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_matrice	*matrice_init_z(double angle)
{
	t_matrice *ptr;

	ptr = ft_memalloc(sizeof(t_matrice));
	ptr->m[0][0] = cos(angle);
	ptr->m[0][1] = -sin(angle);
	ptr->m[0][2] = 0.0;
	ptr->m[1][0] = sin(angle);
	ptr->m[1][1] = cos(angle);
	ptr->m[1][2] = 0.0;
	ptr->m[2][0] = 0.0;
	ptr->m[2][1] = 0.0;
	ptr->m[2][2] = 1.0;
	return (ptr);
}

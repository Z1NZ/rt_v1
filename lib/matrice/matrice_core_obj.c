/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice_core_obj.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 12:01:50 by srabah            #+#    #+#             */
/*   Updated: 2016/03/16 15:32:56 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vector	matrice_core_obj(t_vector obj, t_vector angle)
{
	t_matrice *ptr_x;
	t_matrice *ptr_y;
	t_matrice *ptr_z;
	t_matrice *ptr_r;
	t_matrice *tmp;

	ptr_x = matrice_init_x(angle.x);
	ptr_y = matrice_init_y(angle.y);
	ptr_z = matrice_init_z(angle.z);
	ptr_r = matrice_product(ptr_y, ptr_x);
	free(ptr_x);
	free(ptr_y);
	tmp = matrice_product(ptr_z, ptr_r);
	obj = vector_add(obj, vector_matrice(*tmp, obj));
	free(ptr_z);
	free(tmp);
	free(ptr_r);
	return (obj);
}

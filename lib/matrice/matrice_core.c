/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice_core.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 12:02:01 by srabah            #+#    #+#             */
/*   Updated: 2016/03/17 14:05:26 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vector	matrice_core(t_ray ray, t_env *e)
{
	t_matrice *ptr_x;
	t_matrice *ptr_y;
	t_matrice *ptr_z;
	t_matrice *ptr_r;
	t_matrice *tmp;

	ptr_x = matrice_init_x(e->cam.angle.x);
	ptr_y = matrice_init_y(e->cam.angle.y);
	ptr_z = matrice_init_z(e->cam.angle.z);
	ptr_r = matrice_product(ptr_y, ptr_x);
	free(ptr_x);
	free(ptr_y);
	tmp = matrice_product(ptr_z, ptr_r);
	ray.dir = vector_add(ray.dir, vector_matrice(*tmp, ray.dir));
	free(ptr_z);
	free(tmp);
	free(ptr_r);
	return (ray.dir);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_matrice.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 12:03:00 by srabah            #+#    #+#             */
/*   Updated: 2016/03/16 15:33:17 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vector		vector_matrice(t_matrice m, t_vector v)
{
	t_vector	res;

	res.x = v.x * m.m[0][0] + v.y * m.m[0][1] + v.z * m.m[0][2];
	res.y = v.x * m.m[1][0] + v.y * m.m[1][1] + v.z * m.m[1][2];
	res.z = v.x * m.m[2][0] + v.y * m.m[2][1] + v.z * m.m[2][2];
	return (res);
}

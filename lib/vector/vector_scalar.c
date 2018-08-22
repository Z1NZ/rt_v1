/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_scalar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 11:37:41 by srabah            #+#    #+#             */
/*   Updated: 2016/03/16 15:36:16 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vector	vector_scalar(t_vector a, double scalar)
{
	t_vector res;

	res.x = a.x * scalar;
	res.y = a.y * scalar;
	res.z = a.z * scalar;
	return (res);
}

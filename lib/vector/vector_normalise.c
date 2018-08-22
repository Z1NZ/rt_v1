/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_normalise.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 11:37:57 by srabah            #+#    #+#             */
/*   Updated: 2016/03/16 15:36:11 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vector	vector_normalise(t_vector a)
{
	t_vector	res;
	double		n;

	n = vector_norm(a);
	res.x = a.x / n;
	res.y = a.y / n;
	res.z = a.z / n;
	return (res);
}

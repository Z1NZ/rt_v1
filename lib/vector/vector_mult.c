/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_mult.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 18:58:10 by srabah            #+#    #+#             */
/*   Updated: 2016/03/17 18:58:12 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vector	vector_mult(t_vector a, double cof)
{
	t_vector res;

	res.x = a.x * cof;
	res.y = a.y * cof;
	res.z = a.z * cof;
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice_product.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 12:02:21 by srabah            #+#    #+#             */
/*   Updated: 2016/03/16 15:33:13 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_matrice	*matrice_product(t_matrice *ptr1, t_matrice *ptr2)
{
	int			i;
	int			j;
	int			k;
	t_matrice	*ptr3;

	i = -1;
	ptr3 = ft_memalloc(sizeof(t_matrice));
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
		{
			k = -1;
			while (++k < 3)
				ptr3->m[i][j] += ptr1->m[i][k] * ptr2->m[k][j];
		}
	}
	return (ptr3);
}

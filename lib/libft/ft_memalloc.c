/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 12:03:39 by srabah            #+#    #+#             */
/*   Updated: 2016/03/16 15:32:50 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <stdlib.h>
#include <string.h>

void	*ft_memalloc(size_t size)
{
	void	*new_space;

	if (!size)
		return (NULL);
	new_space = (void*)malloc(size * sizeof(void*));
	if (!new_space)
		return (NULL);
	ft_bzero(new_space, size);
	return (new_space);
}

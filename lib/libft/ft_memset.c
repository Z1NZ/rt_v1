/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 12:03:45 by srabah            #+#    #+#             */
/*   Updated: 2016/03/16 15:32:53 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*bstr;

	bstr = b;
	while (len)
	{
		*bstr = (unsigned char)c;
		bstr++;
		len--;
	}
	return (b);
}

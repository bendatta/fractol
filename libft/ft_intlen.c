/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 22:30:32 by baudiber          #+#    #+#             */
/*   Updated: 2017/11/16 01:43:26 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_intlen(int nb)
{
	size_t	i;

	i = 0;
	if (nb == 0)
		i = 1;
	if (nb < 0)
	{
		i++;
		nb = -nb;
	}
	while (nb)
	{
		i++;
		nb = nb / 10;
	}
	return (i);
}

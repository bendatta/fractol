/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 15:22:02 by baudiber          #+#    #+#             */
/*   Updated: 2018/10/23 00:03:38 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** finds the id of the thread (tid)
*/

int		find_thread(t_setup *stp)
{
	pthread_t	tid;
	int			i;

	tid = pthread_self();
	i = -1;
	while (++i < MAX_THREADS)
	{
		if (pthread_equal(stp->tids[i], tid))
			break ;
	}
	return (i);
}

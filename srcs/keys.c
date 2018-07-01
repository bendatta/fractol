/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 23:27:34 by baudiber          #+#    #+#             */
/*   Updated: 2018/07/01 02:09:10 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int		mouse_move(int button, int x, int y, t_setup *stp)
{
	if (button == 1)
	{
		printf("%f, %f\n", stp->frac.x1, stp->frac.y1);
		stp->frac.x1 = x - H;
		stp->frac.y1 = y - H;
		stp->frac.zoom += 10;
	}
	//6 = scroll down
	if (button == 7)
	{
		stp->frac.zoom += 10;
	}
	draw(stp);
	printf("%d\n", button);
	return (0);
}

int		stp_key(int key, t_setup *stp)
{
	if (key == 53)
		exit(0);
	if (key == 49)
	{
		stp->mandelbrot = 1;
	}
	//w
	if (key == 13)
	{
		stp->frac.zoom *= 1.2;
	}
	//s
	if (key == 1)
	{
		stp->frac.zoom /= 1.2;
	}
	draw(stp);
	return (0);
}

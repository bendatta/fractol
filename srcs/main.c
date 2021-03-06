/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 22:52:59 by baudiber          #+#    #+#             */
/*   Updated: 2018/10/23 01:12:41 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** saves the right fractal functions in the function ptr
*/

char	*which_frac(t_setup *stp, char *av, int ac)
{
	if (!ft_strcmp(av, "mandelbrot") && ac == 2)
		stp->ft_frac = draw_mandelbrot;
	else if (!ft_strcmp(av, "julia") && ac == 2)
		stp->ft_frac = draw_julia;
	else if (!ft_strcmp(av, "tricorn") && ac == 2)
		stp->ft_frac = draw_tricorn;
	else if (!ft_strcmp(av, "burningship") && ac == 2)
		stp->ft_frac = draw_bship;
	else if (!ft_strcmp(av, "multibrot3") && ac == 2)
		stp->ft_frac = draw_multibrot3;
	else if (!ft_strcmp(av, "juliargh") && ac == 2)
		stp->ft_frac = draw_juliargh;
	else if (!ft_strcmp(av, "juliaiaia") && ac == 2)
		stp->ft_frac = draw_juliaiaia;
	else if (!ft_strcmp(av, "tree") && ac == 2)
		return (av);
	else if (!ft_strcmp(av, "multibrot") && ac == 3)
		stp->ft_frac = draw_multibrot;
	if (stp->ft_frac)
		return (av);
	else
		return (NULL);
}

void	print_help(void)
{
	ft_putendl("~~~~~~~~~ HELP ~~~~~~~~~~");
	ft_putendl("H key: turn off/on HUD");
	ft_putendl("Esc: quit program");
	ft_putendl("~~~~~~~~~FRACTALS~~~~~~~~");
	ft_putendl("Scroll wheel & mouse 1&2: targeted zoom");
	ft_putendl("Arrow keys: pan");
	ft_putendl("Space: freeze julia");
	ft_putendl("I/K keys: add iterations");
	ft_putendl("C key: rainbow colors");
	ft_putendl("R key: reset view");
	ft_putendl("X key: crosshair");
	ft_putendl("~~~~~~~~~~ TREE ~~~~~~~~~");
	ft_putendl("R key: randomized tree");
	ft_putendl("UP/DOWN keys: move tree");
	ft_putendl("LEFT/RIGHT keys: change size (max:200)");
	ft_putendl("I/K keys: change depth (max:20)");
}

void	ft_errors(int type)
{
	if (type == 1)
		ft_putendl("usage : ./fractol <mandelbrot> / <julia> / <juliargh>\
/ <juliaiaia> / <burningship> / <tricorn> / <multibrot3>\
/ <multibrot> <1-100> / <tree>");
	else if (type == 2)
		ft_putendl("multibrot number should be between 1 and 100");
	exit(0);
}

void	check_multibrot(char *str, t_setup *stp)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			ft_errors(1);
		i++;
	}
	stp->n = ft_atoi(str);
	if (stp->n > 100 || stp->n <= 0)
		ft_errors(2);
}

int		main(int ac, char **av)
{
	t_setup stp;

	if (ac > 3 || ac < 2)
		ft_errors(1);
	ft_bzero(&stp, sizeof(t_setup));
	if (!(stp.av = which_frac(&stp, av[1], ac)))
		ft_errors(1);
	if (ac == 3)
		check_multibrot(av[2], &stp);
	print_help();
	stp.resi = 0;
	init_res(&stp);
	init_mlx(&stp);
	init_var(&stp);
	fractol(&stp);
	return (0);
}

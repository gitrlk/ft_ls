/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarol <jecarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 19:53:02 by jecarol           #+#    #+#             */
/*   Updated: 2017/04/17 19:53:27 by jecarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

int					main(int argc, char **argv)
{
	char			flags[ft_strlen(MACROFLAGS + 1)];
	int				i;
	static t_list	*arglist = NULL;

	i = 0;
	ft_bzero(&flags, ft_strlen(MACROFLAGS + 1));
	while (i++ < argc)
	{
		if (argv[i] && argv[i][0] == '-' && argv[i][1] == '-' &&
		argv[i][2] == '\0')
			break ;
		if (argv[i] && argv[i][0] == '-' && argv[i][1])
			getflags(flags, argv[i] + 1);
		else
			break ;
	}
	if (argc > 1)
		arglist = ft_getargs(argc, argv, i);
	ft_ls(flags, arglist);
	return (0);
}

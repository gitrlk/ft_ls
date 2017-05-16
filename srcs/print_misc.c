/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_misc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarol <jecarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 17:42:44 by jecarol           #+#    #+#             */
/*   Updated: 2017/04/17 22:52:10 by jecarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void		ft_printpath(char *path, t_checks *vals, char *flags)
{
	if (((vals->checker && vals->empty > 1) ||
	(ft_strchr(flags, 'R') && vals->firstnewline != 0) ||
	(vals->filesnewline == 1) ||
	(!vals->dont && vals->firstnewline != 0 && !ft_strchr(flags, 'R'))))
		ft_putchar('\n');
	ft_putstr(path);
	ft_putchar(':');
	ft_putchar('\n');
	vals->firstnewline += 1;
}

int			ft_how_long(int i)
{
	int		size;

	size = 1;
	while (i /= 10)
		size++;
	return (size);
}

void		ft_putstr_spaces_char(char *str, int spacesnbr)
{
	int		i;

	i = 0;
	ft_putstr(str);
	if (spacesnbr < 0)
		spacesnbr = 0;
	while (i != spacesnbr)
	{
		ft_putchar(' ');
		i++;
	}
}

void		ft_putstr_spaces_nbr(int value, int spacesnbr)
{
	int		i;

	i = 0;
	if (spacesnbr < 0)
		spacesnbr = 0;
	while (i != spacesnbr)
	{
		ft_putchar(' ');
		i++;
	}
	ft_putnbr(value);
}

void		ft_print_total(int total, int totalcheck, t_list *tmp, char *flags)
{
	t_list	*tmp1;
	int		i;

	i = 0;
	tmp1 = tmp;
	while (tmp1)
	{
		if (!ft_strchr(flags, 'a'))
			if ((ft_strcmp((((t_ls*)tmp1->content)->name), ".") &&
			ft_strcmp((((t_ls*)tmp1->content)->name), "..")))
				i = 1;
		if (ft_strchr(flags, 'a'))
			i = 1;
		tmp1 = tmp1->next;
	}
	if (!totalcheck && i)
	{
		ft_putstr("total ");
		ft_putnbr(total);
		ft_putchar('\n');
	}
}

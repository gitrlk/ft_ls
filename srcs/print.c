/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarol <jecarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 17:30:38 by jecarol           #+#    #+#             */
/*   Updated: 2017/04/17 22:51:50 by jecarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void			ft_actual_l_print(t_list *tmp, char *flags, t_getsize *stock)
{
	t_getsize	*currentsize;
	t_getsize	*spacesnmbr;

	currentsize = ft_memalloc(sizeof(t_getsize));
	spacesnmbr = ft_memalloc(sizeof(t_getsize));
	if (!ft_strchr(flags, 'a'))
	{
		if (((((t_ls*)tmp->content)->name)[0] != '.') ||
		((((t_ls*)tmp->content)->name)[0] == '.' &&
		(((t_ls*)tmp->content)->name)[1] == '/'))
		{
			ft_get_spaces_nbr(tmp, currentsize, stock, spacesnmbr);
			ft_padd_l(tmp, spacesnmbr, stock);
		}
	}
	else if (ft_strchr(flags, 'a'))
	{
		ft_get_spaces_nbr(tmp, currentsize, stock, spacesnmbr);
		ft_padd_l(tmp, spacesnmbr, stock);
	}
	ft_memdel((void**)&currentsize);
	ft_memdel((void**)&spacesnmbr);
}

int				ft_print_l(t_list *tmp, char *flags, int *checker,
				int totalcheck)
{
	t_list		*temp;
	t_getsize	*stock;
	int			totalblk;

	totalblk = 0;
	temp = tmp;
	stock = ft_memalloc(sizeof(t_getsize));
	while (temp)
	{
		if (ft_strchr(flags, 'a'))
			ft_get_max_size(temp, stock, &totalblk);
		else if (!ft_strchr(flags, 'a'))
			ft_get_max_size_no_dot(temp, stock, &totalblk);
		temp = temp->next;
	}
	ft_print_total(totalblk, totalcheck, tmp, flags);
	while (tmp)
	{
		ft_actual_l_print(tmp, flags, stock);
		*checker = 1;
		tmp = tmp->next;
	}
	ft_memdel((void**)&stock);
	return (0);
}

int				ft_printdircontent(t_list *dircontent, char *flags,
				int *checker, int totalcheck)
{
	t_list		*tmp;

	if (!dircontent)
		return (0);
	tmp = dircontent;
	if (ft_strchr(flags, 'l'))
		return (ft_print_l(tmp, flags, checker, totalcheck));
	while (dircontent)
	{
		if (ft_strchr(flags, 'a'))
			ft_putendl((((t_ls*)dircontent->content)->name));
		if (!ft_strchr(flags, 'a') && (((t_ls*)dircontent->content)->name)[0]
		!= '.')
			ft_putendl((((t_ls*)dircontent->content)->name));
		dircontent = dircontent->next;
	}
	*checker = 1;
	return (0);
}

void			ft_permissiondenied(char *path)
{
	ft_putstr("ft_ls: ");
	ft_putstr(path);
	ft_putstr(": ");
	ft_putendl("Permission denied");
}

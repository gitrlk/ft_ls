/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_more.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarol <jecarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 20:00:47 by jecarol           #+#    #+#             */
/*   Updated: 2017/04/17 21:43:49 by jecarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

int				ft_check_if_dont(t_list *filelist)
{
	t_list		*tmp;
	int			i;

	i = 0;
	tmp = filelist;
	while (tmp)
	{
		if ((((t_ls*)tmp->content)->mode)[0] == 'd' ||
		(((t_ls*)tmp->content)->mode)[0] == 'l')
			i = 1;
		tmp = tmp->next;
	}
	return (i);
}

void			ft_print_files_assist(char *flags, t_list *temp,
				t_getsize *stock, int *totalblk)
{
	if (ft_strchr(flags, 'a'))
		ft_get_max_size(temp, stock, totalblk);
	else if (!ft_strchr(flags, 'a'))
		ft_get_max_size_no_dot(temp, stock, totalblk);
}

int				ft_print_l_files(t_list *tmp, char *flags, t_checks *vals,
				int totalcheck)
{
	t_list		*temp;
	t_getsize	*stock;
	int			totalblk;

	totalcheck = 1;
	totalblk = 0;
	temp = tmp;
	stock = ft_memalloc(sizeof(t_getsize));
	while (temp)
	{
		ft_print_files_assist(flags, temp, stock, &totalblk);
		temp = temp->next;
	}
	while (tmp)
	{
		if ((((t_ls*)tmp->content)->mode[0]) != 'd')
		{
			ft_actual_l_print(tmp, flags, stock);
			vals->checker++;
		}
		tmp = tmp->next;
	}
	vals->filesnewline = 1;
	ft_memdel((void**)&stock);
	return (0);
}

int				ft_printfilelist(t_list *dircontent, char *flags,
				t_checks *vals, int totalcheck)
{
	t_list		*tmp;

	tmp = dircontent;
	if (ft_strchr(flags, 'l'))
		return (ft_print_l_files(tmp, flags, vals, totalcheck));
	while (dircontent)
	{
		if ((((t_ls*)dircontent->content)->mode)[0] == '-' ||
		((((t_ls*)dircontent->content)->name)[0] == '.' &&
		(((t_ls*)dircontent->content)->name)[1] == '/'))
		{
			if (ft_strchr(flags, 'a'))
				ft_putendl((((t_ls*)dircontent->content)->name));
			if (((!ft_strchr(flags, 'a') &&
			(((t_ls*)dircontent->content)->name)[0] != '.') ||
			((((t_ls*)dircontent->content)->name)[0] == '.' &&
			(((t_ls*)dircontent->content)->name)[1] == '/')) &&
			(((t_ls*)dircontent->content)->mode)[0] == '-')
				ft_putendl((((t_ls*)dircontent->content)->name));
		}
		dircontent = dircontent->next;
	}
	vals->filesnewline = 1;
	return (0);
}

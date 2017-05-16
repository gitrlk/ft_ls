/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarol <jecarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 17:52:16 by jecarol           #+#    #+#             */
/*   Updated: 2017/04/15 01:31:06 by jecarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void		ft_get_max_size(t_list *temp, t_getsize *stock, int *totalblk)
{
	*totalblk += ((((t_ls*)temp->content)->bloks));
	if (ft_strlen((((t_ls*)temp->content)->mode)) > (size_t)stock->mode)
		stock->mode = ft_strlen((((t_ls*)temp->content)->mode));
	if (ft_how_long((((t_ls*)temp->content)->links)) > stock->links)
		stock->links = ft_how_long((((t_ls*)temp->content)->links));
	if (ft_strlen((((t_ls*)temp->content)->owner)) > (size_t)stock->user)
		stock->user = ft_strlen((((t_ls*)temp->content)->owner));
	if (ft_strlen((((t_ls*)temp->content)->group)) > (size_t)stock->group)
		stock->group = ft_strlen((((t_ls*)temp->content)->group));
	if (ft_how_long((((t_ls*)temp->content)->major)) > stock->major)
		stock->major = ft_how_long((((t_ls*)temp->content)->major));
	if (ft_how_long((((t_ls*)temp->content)->size)) > stock->size)
		stock->size = ft_how_long((((t_ls*)temp->content)->size));
}

void		ft_get_max_size_no_dot(t_list *temp, t_getsize *stock,
			int *totalblk)
{
	if ((((t_ls*)temp->content)->name)[0] != '.')
	{
		*totalblk += ((((t_ls*)temp->content)->bloks));
		if (ft_strlen((((t_ls*)temp->content)->mode)) > (size_t)stock->mode)
			stock->mode = ft_strlen((((t_ls*)temp->content)->mode));
		if (ft_how_long((((t_ls*)temp->content)->links)) > stock->links)
			stock->links = ft_how_long((((t_ls*)temp->content)->links));
		if (ft_strlen((((t_ls*)temp->content)->owner)) > (size_t)stock->user)
			stock->user = ft_strlen((((t_ls*)temp->content)->owner));
		if (ft_strlen((((t_ls*)temp->content)->group)) > (size_t)stock->group)
			stock->group = ft_strlen((((t_ls*)temp->content)->group));
		if (ft_how_long((((t_ls*)temp->content)->major)) > stock->major)
			stock->major = ft_how_long((((t_ls*)temp->content)->major));
		if (ft_how_long((((t_ls*)temp->content)->size)) > stock->size)
			stock->size = ft_how_long((((t_ls*)temp->content)->size));
	}
}

void		ft_get_spaces_nbr(t_list *tmp, t_getsize *currentsize,
			t_getsize *stock, t_getsize *spacesnmbr)
{
	currentsize->links = ft_how_long((((t_ls*)tmp->content)->links));
	spacesnmbr->links = stock->links - currentsize->links;
	currentsize->user = ft_strlen((((t_ls*)tmp->content)->owner));
	spacesnmbr->user = stock->user - currentsize->user;
	currentsize->group = ft_strlen((((t_ls*)tmp->content)->group));
	spacesnmbr->group = stock->group - currentsize->group;
	currentsize->major = ft_how_long((((t_ls*)tmp->content)->major));
	spacesnmbr->major = stock->major - currentsize->major;
	currentsize->size = ft_how_long((((t_ls*)tmp->content)->size));
	spacesnmbr->size = stock->size - currentsize->size;
}

void		ft_add_major(t_list *tmp, t_getsize *spacesnmbr, t_getsize *stock)
{
	int i;

	i = 0;
	if ((((t_ls*)tmp->content)->major) != -1)
	{
		ft_putstr_spaces_nbr((((t_ls*)tmp->content)->major), spacesnmbr->major);
		ft_putchar(',');
		ft_putstr("  ");
	}
	else
	{
		while (i < stock->major)
		{
			ft_putchar(' ');
			i++;
		}
		i = 0;
		while (i < spacesnmbr->major)
		{
			ft_putchar(' ');
			i++;
		}
		ft_putstr("  ");
	}
}

void		ft_padd_l(t_list *tmp, t_getsize *spacesnmbr, t_getsize *stock)
{
	ft_putstr((((t_ls*)tmp->content)->mode));
	ft_putchar(' ');
	ft_putstr_spaces_nbr((((t_ls*)tmp->content)->links), spacesnmbr->links);
	ft_putchar(' ');
	ft_putstr_spaces_char((((t_ls*)tmp->content)->owner), spacesnmbr->user);
	ft_putstr("  ");
	ft_putstr_spaces_char((((t_ls*)tmp->content)->group), spacesnmbr->group);
	ft_putstr("  ");
	ft_add_major(tmp, spacesnmbr, stock);
	ft_putstr_spaces_nbr((((t_ls*)tmp->content)->size), spacesnmbr->size);
	ft_putchar(' ');
	ft_putstr((((t_ls*)tmp->content)->date));
	ft_putchar(' ');
	ft_putstr((((t_ls*)tmp->content)->name));
	if ((((t_ls*)tmp->content)->linkpath))
	{
		ft_putstr(" -> ");
		ft_putendl((((t_ls*)tmp->content)->linkpath));
	}
	else
		ft_putchar('\n');
}

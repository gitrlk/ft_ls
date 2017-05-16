/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparedir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarol <jecarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 17:06:23 by jecarol           #+#    #+#             */
/*   Updated: 2017/04/17 19:13:13 by jecarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void				ft_dirlistassist(t_ls *info, int checker, char *path,
					t_list **lst)
{
	t_list			*tmp;

	info = ft_memalloc(sizeof(t_ls));
	ft_fillinfo(info, checker, path);
	tmp = ft_lstnew(info, sizeof(t_ls));
	if (!lst)
		lst = &tmp;
	else
		ft_lstaddend(lst, tmp);
	ft_memdel((void**)&info);
}

t_list				*ft_lscurrentdir(void)
{
	t_list			*lst;
	t_ls			*currentdir;

	currentdir = ft_memalloc(sizeof(t_ls));
	currentdir->name = ft_strdup(".");
	currentdir->p_d = 0;
	lst = ft_lstnew(currentdir, sizeof(t_ls));
	free(currentdir);
	return (lst);
}

t_list				*ft_createdirlist(t_list *validargs, t_checks *vals)
{
	DIR				*dirpath;
	t_list			*tmp;
	t_list			*lst;
	t_ls			*info;

	lst = NULL;
	info = NULL;
	tmp = validargs;
	if (!validargs && !vals->checker)
	{
		lst = ft_lscurrentdir();
		vals->noargs = 1;
		return (lst);
	}
	while (tmp)
	{
		if (!(dirpath = opendir((((t_ls*)tmp->content)->name))) && errno != 20)
			ft_dirlistassist(info, 1, (((t_ls*)tmp->content)->name), &lst);
		else if ((dirpath = opendir((((t_ls*)tmp->content)->name))))
			ft_dirlistassist(info, 0, (((t_ls*)tmp->content)->name), &lst);
		if (dirpath)
			closedir(dirpath);
		tmp = tmp->next;
	}
	return (lst);
}

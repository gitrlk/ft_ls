/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarol <jecarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 17:02:08 by jecarol           #+#    #+#             */
/*   Updated: 2017/04/17 19:51:36 by jecarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void				ft_arglistchecker(t_list *tmperror, int *checker)
{
	DIR				*dirpath;

	while (tmperror)
	{
		if (!(dirpath = opendir((((t_ls*)tmperror->content)->name)))
		&& errno == 2 && ft_strcmp((((t_ls*)tmperror->content)->name), "--"))
		{
			ft_error(0, (((t_ls*)tmperror->content)->name));
			*checker = 1;
		}
		if (dirpath)
			closedir(dirpath);
		tmperror = tmperror->next;
	}
}

t_list				*ft_getvalidargs(t_list *arg)
{
	t_list			*lst;
	t_list			*tmp;
	DIR				*dirpath;
	t_ls			*info;

	lst = NULL;
	tmp = NULL;
	while (arg)
	{
		if ((dirpath = opendir((((t_ls*)arg->content)->name))) || errno != 2)
		{
			info = ft_memalloc(sizeof(t_ls));
			info->name = ft_strdup((((t_ls*)arg->content)->name));
			tmp = ft_lstnew(info, sizeof(t_ls));
			ft_memdel((void**)&info);
			if (!lst)
				lst = tmp;
			else
				ft_lstadd(&lst, tmp);
		}
		if (dirpath)
			closedir(dirpath);
		arg = arg->next;
	}
	return (lst);
}

void				ft_check_maxlenerror(t_list *lst)
{
	t_list			*tmp;
	struct stat		lenchecker;

	tmp = lst;
	while (tmp)
	{
		lstat((((t_ls*)tmp->content)->name), &lenchecker);
		if (errno == ENAMETOOLONG)
		{
			ft_error(0, (((t_ls*)tmp->content)->name));
			exit(0);
		}
		tmp = tmp->next;
	}
}

t_list				*ft_getargs(int argc, char **argv, int i)
{
	t_list			*lst;
	t_list			*tmp;
	t_ls			*info;

	lst = NULL;
	tmp = NULL;
	while (i < argc)
	{
		info = ft_memalloc(sizeof(t_ls));
		info->name = ft_strdup(argv[i]);
		tmp = ft_lstnew(info, sizeof(t_ls));
		ft_memdel((void**)&info);
		if (!lst)
			lst = tmp;
		else
			ft_lstadd(&lst, tmp);
		i++;
	}
	ft_check_maxlenerror(lst);
	return (lst);
}

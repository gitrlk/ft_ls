/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_treatment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarol <jecarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 16:52:46 by jecarol           #+#    #+#             */
/*   Updated: 2017/04/17 21:11:00 by jecarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

int					ft_set_checker(t_list *filelist)
{
	t_list			*tmp;
	int				i;

	i = 0;
	tmp = filelist;
	while (tmp)
	{
		if ((((t_ls*)tmp->content)->mode)[0] == '-')
			i++;
		tmp = tmp->next;
	}
	return (i);
}

void				ft_filelistassist(char *element, char *path, t_list **lst,
					int slash)
{
	t_list			*tmp;
	t_ls			*info;

	info = ft_memalloc(sizeof(t_ls));
	ft_filleleminfo(element, path, info, slash);
	tmp = ft_lstnew(info, sizeof(t_ls));
	if (!lst)
		lst = &tmp;
	else
		ft_lstaddend(lst, tmp);
	ft_memdel((void**)&info);
}

void				ft_caller(int slash, char *path, char *element,
					t_list **lst)
{
	if (slash)
		path = ft_strjoin("/", element);
	else if (!slash)
		path = ft_strdup(element);
	ft_filelistassist(element, path, lst, slash);
}

t_list				*ft_createfilelist(t_list *validargs)
{
	struct stat		stats;
	t_list			*tmp;
	t_list			*lst;
	char			*path;
	static int		slash = 0;

	lst = NULL;
	tmp = validargs;
	path = NULL;
	while (tmp)
	{
		if ((((t_ls*)tmp->content)->name)[0] != '/')
		{
			if (lstat(ft_strjoin("/", (((t_ls*)tmp->content)->name)), &stats))
				ft_caller(slash++, path, (((t_ls*)tmp->content)->name), &lst);
		}
		else if ((((t_ls*)tmp->content)->name)[0] == '/')
		{
			if (lstat(ft_strjoin((((t_ls*)tmp->content)->name), "/"), &stats))
				ft_caller(slash, path, (((t_ls*)tmp->content)->name), &lst);
		}
		tmp = tmp->next;
	}
	return (lst);
}

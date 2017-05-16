/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workondir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarol <jecarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 17:05:08 by jecarol           #+#    #+#             */
/*   Updated: 2017/04/17 21:25:39 by jecarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void				ft_getdircontent(t_list **dircontent, DIR *dirpath,
					char *path)
{
	t_ls			*info;
	t_list			*tmp;
	struct dirent	*infostruct;

	while ((infostruct = readdir(dirpath)))
	{
		info = ft_memalloc(sizeof(t_ls));
		ft_fillfileinfo(info, infostruct, path);
		tmp = ft_lstnew(info, sizeof(t_ls));
		ft_memdel((void**)&info);
		if (!dircontent)
			dircontent = &tmp;
		else
			ft_lstaddend(dircontent, tmp);
	}
}

void				ft_reclook(char *flags, t_list *dircontent, char *path,
					t_checks vals)
{
	if (ft_strchr(flags, 'R') && ft_strchr(flags, 'a'))
		while (dircontent)
		{
			if ((((t_ls*)dircontent->content)->mode[0]) == 'd' &&
			ft_strcmp((((t_ls*)dircontent->content)->name), "..") &&
			ft_strcmp((((t_ls*)dircontent->content)->name), "."))
				ft_lookindir(ft_strjoin(ft_strjoin(path, "/"),
				(((t_ls*)dircontent->content)->name)), flags, vals);
			dircontent = dircontent->next;
		}
	else if (ft_strchr(flags, 'R'))
		while (dircontent)
		{
			if ((((t_ls*)dircontent->content)->mode[0]) == 'd' &&
			(((t_ls*)dircontent->content)->name)[0] != '.')
				ft_lookindir(ft_strjoin(ft_strjoin(path, "/"),
				(((t_ls*)dircontent->content)->name)), flags, vals);
			dircontent = dircontent->next;
		}
}

void				ft_lookindir(char *path, char *flags, t_checks vals)
{
	t_list			*dircontent;
	t_list			*tmp;
	DIR				*dirpath;

	dircontent = NULL;
	if (((((vals.checker && vals.empty && !vals.noargs) || vals.empty > 1 ||
	(vals.morethanone > 1 && !vals.dont))) || ft_strchr(flags, 'R')))
		ft_printpath(path, &vals, flags);
	if (!(dirpath = opendir(path)))
		ft_error(0, path);
	if (dirpath)
		ft_getdircontent(&dircontent, dirpath, path);
	tmp = dircontent;
	tmp = sort_parser(tmp, flags);
	ft_printdircontent(tmp, flags, &vals.checker, 0);
	ft_reclook(flags, dircontent, path, vals);
	(dirpath ? closedir(dirpath) : 0);
	free(tmp);
}

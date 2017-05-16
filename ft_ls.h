/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarol <jecarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 15:08:53 by jecarol           #+#    #+#             */
/*   Updated: 2017/04/17 22:51:32 by jecarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <sys/xattr.h>
# include <time.h>
# include <stdio.h>
# include <sys/errno.h>

# include "libft/libft.h"

typedef struct				s_ls
{
	char					*statspath;
	char					mode[15];
	int						p_d;
	char					*name;
	int						type;
	char					*path;
	int						links;
	char					*owner;
	char					*group;
	int						major;
	long long				size;
	long long				bloks;
	long					epoch;
	char					*date;
	char					*newpath;
	char					*linkpath;
}							t_ls;

typedef struct				s_getsize
{
	int						mode;
	int						links;
	int						user;
	int						group;
	int						size;
	int						date;
	int						major;
}							t_getsize;

typedef struct				s_checks
{
	int						noargs;
	int						checker;
	int						empty;
	int						newline;
	int						filesnewline;
	int						dont;
	int						morethanone;
	int						firstnewline;
}							t_checks;

t_list						*sort_parser(t_list *lst, char *flags);
int							sort_rev_ascii(char *a, char *b);
int							sort_ascii(char *a, char *b);
t_list						*ft_sort(t_list *lst);
t_list						*ft_sort_rev(t_list *lst);
t_list						*ft_createdirlist(t_list *validargs,
							t_checks *vals);
void						ft_arglistchecker(t_list *tmperror, int *checker);
t_list						*ft_getvalidargs(t_list *arglist);
long						ft_error(int nbr, const char *content);
int							ft_fillinfo(t_ls *info, int checker, char *path);
int							ft_printdircontent(t_list *dircontent, char *flags,
							int *checker, int totalcheck);
void						ft_lookindir(char *path, char *flags,
							t_checks vals);
t_list						*ft_sort_time(t_list *lst);
t_list						*ft_sort_time_rev(t_list *lst);
t_list						*ft_createfilelist(t_list *validargs);
t_list						*ft_getargs(int argc, char **argv, int i);
void						ft_printpath(char *path, t_checks *vals,
							char *flags);
int							ft_how_long(int i);
void						ft_putstr_spaces_char(char *str, int spacesnbr);
void						ft_putstr_spaces_nbr(int value, int spacesnbr);
void						ft_print_total(int total, int totalcheck,
							t_list *tmp, char *flags);
void						ft_get_max_size(t_list *temp, t_getsize *stock,
							int *totalblk);
void						ft_get_max_size_no_dot(t_list *temp,
							t_getsize *stock, int *totalblk);
void						ft_get_spaces_nbr(t_list *tmp,
							t_getsize *currentsize,
							t_getsize *stock, t_getsize *spacesnmbr);
void						ft_padd_l(t_list *tmp, t_getsize *spacesnmbr,
							t_getsize *stock);
int							ft_fillfileinfo(t_ls *info,
							struct dirent *infostruct, char *path);
void						ft_getinfonewpath(char *path,
							char **newpath, char *name);
void						ft_modeset(struct stat stats, char *mode);
void						ft_getdatefromepoch(time_t epoch, char **date);
int							ft_filleleminfo(char *element,
							char *path, t_ls *info, int slash);
int							ft_printfilelist(t_list *dircontent, char *flags,
							t_checks *vals, int totalcheck);
void						ft_actual_l_print(t_list *tmp, char *flags,
							t_getsize *stock);
int							ft_check_if_dont(t_list *filelist);
void						getflags(char *flags, char *content);
int							ft_ls(char *flags, t_list *arglist);
int							ft_set_checker(t_list *filelist);

# define MACROFLAGS "lrRta"
# define MAXFILENAMELEN 255

#endif

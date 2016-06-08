/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvenance <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 11:46:58 by vvenance          #+#    #+#             */
/*   Updated: 2016/06/08 11:47:05 by vvenance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "libft.h"

static t_file	*ft_search_fd(t_list **lst, int fd)
{
	t_list	*tmp;
	t_file	file;

	tmp = *lst;
	while (tmp)
	{
		if (((t_file*)(tmp->content))->fd == fd)
			return (tmp->content);
		tmp = tmp->next;
	}
	file.fd = fd;
	file.str = ft_strnew(BUFF_SIZE);
	if (!file.str || !(tmp = ft_lstnew(&file, sizeof(file))))
	{
		free(file.str);
		return (NULL);
	}
	ft_lstadd(lst, tmp);
	return ((t_file*)tmp->content);
}

static int		ft_save_line(t_file *file, char **line)
{
	char	*eol;
	int		ret;

	ret = 0;
	if ((eol = ft_strchr(file->str, '\n')))
	{
		*eol = '\0';
		eol++;
		ret = 1;
	}
	*line = ft_strdup(file->str);
	if (!*line)
		return (-1);
	if (ret)
		ft_strcpy(file->str, eol);
	else
		ft_strclr(file->str);
	return (ret);
}

static int		ft_readnextline(char *buf, char **line, t_file *file)
{
	char	*tmp;
	int		ret;

	ret = 0;
	if ((tmp = ft_strchr(buf, '\n')))
	{
		*tmp = '\0';
		tmp++;
		ft_strcpy(file->str, tmp);
		ret = 1;
	}
	tmp = *line;
	*line = ft_strjoin(*line, buf);
	if (!*line)
		return (-1);
	free(tmp);
	return (ret);
}

int				ft_get_next_line(int const fd, char **line)
{
	static t_list	*lst;
	char			buf[BUFF_SIZE + 1];
	int				retour_read;
	t_file			*file;

	if (fd == -1 || !line || BUFF_SIZE <= 0 || !(file = ft_search_fd(&lst, fd)))
		return (-1);
	if (!(retour_read = ft_save_line(file, line)))
	{
		while ((retour_read = read(fd, buf, BUFF_SIZE)))
		{
			if (retour_read < 0)
				return (-1);
			buf[retour_read] = '\0';
			if ((retour_read = ft_readnextline(buf, line, file)))
				return (retour_read);
		}
		if (**line)
			return (1);
		return (0);
	}
	return (retour_read);
}

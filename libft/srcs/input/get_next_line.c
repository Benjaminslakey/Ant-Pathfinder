/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 12:46:07 by bslakey           #+#    #+#             */
/*   Updated: 2017/01/30 18:05:12 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static t_list		*find_fd(int fd)
{
	static t_list	*head;
	t_list			*temp;

	temp = head;
	while (temp)
	{
		if ((int)temp->content_size == fd)
			return (temp);
		temp = temp->next;
	}
	temp = ft_lstnew("\0", 1);
	temp->content_size = fd;
	ft_lstadd(&head, temp);
	return (temp);
}

static void			merge(t_list *node, char const *buff, int size)
{
	char	*temp;

	if (node->content == NULL)
	{
		node->content = ft_strndup(buff, size);
		return ;
	}
	temp = node->content;
	node->content = ft_strjoin(temp, buff);
	free(temp);
	free((void*)buff);
}

int					get_next_line(const int fd, char **line)
{
	int				i;
	int				ret;
	char			*ptr;
	char			buf[BUFF_SIZE];
	t_list			*n;

	i = 0;
	ret = 0;
	ERR_GUARD((fd < 0 || line == NULL || read(fd, buf, 0) < 0), -1);
	n = find_fd(fd);
	while (!ft_strchr(n->content, '\n') && (ret = read(fd, buf, BUFF_SIZE)))
		merge(n, ft_strndup(buf, ret), ret);
	if (ret > 0 && ret < BUFF_SIZE && ft_strlen(n->content) == 0)
		ft_strclr(*line);
	ERR_GUARD(ft_strlen(n->content) == 0, 0);
	ptr = n->content;
	i = d_strlen(ptr, i, '\n');
	*line = (ptr[i] == '\n') ? ft_strndup(ptr, i) : ft_strdup(ptr);
	if ((ret == 0 && ptr[i] == 0))
		ft_strclr(ptr);
	if (ptr[i] == '\n')
		n->content = ft_str_replace(&ptr, ptr + i + 1);
	return (1);
}

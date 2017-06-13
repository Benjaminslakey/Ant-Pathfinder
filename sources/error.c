/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 07:35:29 by bslakey           #+#    #+#             */
/*   Updated: 2017/02/09 16:51:02 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int 		chk_comm(char *command)
{
    if (!ft_strcmp(command, "##") || ft_strcmp(command, "#"))
        return (0);
    else
        return (-1);
}

int 		chk_linkformat(char *link)
{
    int 	i;
    int 	errnum;
    char 	**temp;

    i = -1;
    errnum = SUCCESS;
    temp = ft_strsplit(link, '-');
    while (temp[++i])
        ;
    ERR_GUARD((i != 2), ERR);
    if (!ft_strcmp(temp[0], "L") || !ft_strcmp(temp[0], "#") ||
            !ft_strcmp(temp[1], "L") || !ft_strcmp(temp[1], "#"))
        errnum = ERR;
    free_strings(&temp);
    return (errnum);
}

int 		chk_roomformat(char *room)
{
    int 	i;
    int     errnum;
    char 	**s;

    errnum = SUCCESS;
    i = -1;
    s = ft_strsplit(room, ' ');
    while (s[++i])
        ;
    ERR_GUARD((i != 3), -1);
    if (!ft_strcspn(s[1], "-0123456789") || !ft_strcspn(s[2], "-0123456789"))
        errnum = ERR;
    if (!ft_strcmp(s[0], "L") || !ft_strcmp(s[0], "#")) {
        errnum = ERR;
        //printf(RED"room name error\n"CRESET);
    }
    free_strings(&s);
    return (errnum);
}

int			errchk_input(char **file)
{
    int 	i;
    int 	err;
    int     start;
    int     end;

    i = -1;
    err = -1;
    start = 0;
    end = 0;
    while (file[++i])
    {
        if (!ft_strcmp(file[i], "##start") && !chk_roomformat(file[i + 1]))
            start = 1;
        else if (!ft_strcmp(file[i], "##end") && !chk_roomformat(file[i + 1]))
            end = 1;
        else if (!ft_strcmp(file[i], ""))
            return (ERR);
        else if (chk_roomformat(file[i]) < 0 && chk_linkformat(file[i]) < 0
                && chk_comm(file[i]) < 0)
            return (1);
    }
    ERR_GUARD((start == 0 || end == 0), 12);
    return (err);
}
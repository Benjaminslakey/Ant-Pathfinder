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
#include <stdio.h>

int 		chk_comm(char *command)
{
    if (!ft_strncmp(command, "#", 1) || !ft_strncmp(command, "##", 2))
        return (SUCCESS);
    else
        return (ERR);
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
    else if (chr_count(link, ' ') > 0)
        errnum = ERR;
    free_strings(&temp);
    return (errnum);
}

int 		chk_roomformat(char *room)
{

    int 	i;
    int     errnum;
    char 	**s;

    s = NULL;
    errnum = SUCCESS;
    i = -1;
    s = ft_strsplit(room, ' ');
    while (s[++i])
        ;
    ERR_GUARD((i != 3), -1);
    if (chr_count(room, ' ') > 2)
        errnum = ERR;
    if (chr_count(s[0], '-') > 0)
        errnum = ERR;
    else if (!ft_strcspn(s[1], "-0123456789") || !ft_strcspn(s[2], "-0123456789"))
        errnum = ERR;
    else if (!ft_strncmp(s[0], "L", 1) || !ft_strncmp(s[0], "#", 1))
        errnum = ERR;
    free_strings(&s);
    return (errnum);
}

int         chk_start_end(char **file)
{
    int     i;
    int     start;
    int     end;
    bool    svalid;
    bool    evalid;

    i = -1;
    start = 0;
    end = 0;
    svalid = false;
    evalid = false;
    while (file[++i])
    {
        if (!ft_strcmp(file[i], "##start") && ++start < 2 &&
                !chk_roomformat(file[i + 1]))
                svalid = true;
        else if (!ft_strcmp(file[i], "##end") && ++end < 2 &&
                !chk_roomformat(file[i + 1]))
                evalid = true;
    }
    ERR_GUARD((start != 1 || end != 1), ERR);
    ERR_GUARD((!svalid || !evalid), ERR);
    return (SUCCESS);
}

int			errchk_input(char **file)
{
    int 	i;
    bool    ants_given;

    i = -1;
    ants_given = false;
    if (chk_start_end(file) == ERR)
        return (1);
    while (file[++i])
    {
        if (ft_str_isnum(file[i]) && ants_given == false)
            ants_given = true;
        else if (!ft_strcmp(file[i], "L"))
            return (6);
        else if (!ft_strcmp(file[i], ""))
            return (2);
        else if (chk_roomformat(file[i]) < 0 && chk_linkformat(file[i]) < 0
                && chk_comm(file[i]) < 0)
            return (5);
    }
    return (SUCCESS);
}
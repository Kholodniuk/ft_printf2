/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 14:05:51 by skholodn          #+#    #+#             */
/*   Updated: 2017/03/16 14:06:36 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     parse_fd(t_e *e, char *fmt, va_list ar)
{
    if (ft_strstr_stop(fmt, "{fd}"))
    {
        e->fd = va_arg(ar, int);
        return (1);
    }
    return (0);
}

void    find_fd(t_e *e, char **fmt, va_list ar)
{
    if (!parse_fd(e, *fmt, ar))
    {
        write(1, "{", 1);
        (*fmt)++;
    }
    else
        *fmt = ft_strchr(*fmt, '}') + 1;
}

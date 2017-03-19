/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 15:04:37 by skholodn          #+#    #+#             */
/*   Updated: 2017/03/06 15:04:39 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_s *str_init(char *arg, t_e *e)
{
    t_s     *s;
    int     sz_space;

    s = malloc(sizeof(t_s));
    s->size_space = 0;
    s->size_str = (arg == NULL ? 6 : (int)ft_strlen(arg));
    if (e->precision < s->size_str && e->precision != -1)
        s->size_str = e->precision;
    s->str = ft_strnew((size_t)s->size_str);
    s->str = (arg == NULL ? ft_strncpy(s->str, "(null)", (size_t)s->size_str) : ft_strncpy(s->str, arg, (size_t)s->size_str));
    if (e->width > s->size_str)
        s->size_space = (e->width - s->size_str);
    sz_space = s->size_space;
    s->space = ft_strnew((size_t)sz_space);
    while (--sz_space != -1)
    {
        if (e->f->minus || !e->f->zero)
            s->space[sz_space] = ' ';
        else
            s->space[sz_space] = '0';
    }
    return (s);
}

void    free_str(t_s *s)
{
    ft_strdel(&s->str);
    free(s->space);
    s->str = NULL;
    free(s);
}

void    get_str(char *arg, t_e *e)
{
    t_s *s;

    s = str_init(arg, e);
    if (arg && e->f->minus)
    {
        e->bits_count += write(e->fd, s->str, ft_strlen(s->str));
        e->bits_count += write(e->fd, s->space, ft_strlen(s->space));
    }
    else
    {
        e->bits_count += write(e->fd, s->space, ft_strlen(s->space));
        e->bits_count += write(e->fd, s->str, ft_strlen(s->str));
    }
    free_str(s);
}

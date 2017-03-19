/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 13:47:14 by skholodn          #+#    #+#             */
/*   Updated: 2017/03/06 13:47:17 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static  void    u_make_str(uintmax_t value, uintmax_t base, char *str, int *i)
{
    static char *a = "0123456789ABCDEF";

    if (value >= base)
        u_make_str(value / base, base, str, i);
    str[(*i)++] = a[MOD(value % base)];
}


char            *u_itoa_base(uintmax_t value, uintmax_t base)
{
    char    *str;
    int     i;

    if (base < 2 || base > 16 || !(str = ft_strnew(60)))
        return (0);
    i = 0;
    u_make_str(value, base, str, &i);
    str[i] = '\0';
    return (str);
}
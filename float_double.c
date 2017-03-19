/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 21:49:25 by skholodn          #+#    #+#             */
/*   Updated: 2017/03/15 21:49:54 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//void	last_transf(char *str, t_e *e)
//{
//    if (e->f->minus)
//
//}

//long double fraction_nb(long double nb)
//{
//    if ((nb - FLOOR(nb)) == 0.5 && (long long)FLOOR(nb) % 2 == 0)
//        return (FLOOR(nb));
//    else if (CEIL(nb) - nb == 0.5)
//        return (CEIL(nb));
//    if (nb - FLOOR(nb) >= 0.5)
//        return (CEIL(nb));
//    return (FLOOR(nb));
//}
long double	ft_ceil(long double nbr)
{
    long double	i;

    i = (long long)nbr;
    if (nbr <= i)
        return (i);
    return (i + 1);
}

long double	ft_floor(long double nbr)
{
    long double	i;

    i = (long long)nbr;
    if (nbr >= i)
        return (i);
    return (i - 1);
}

long double	fraction_nb(long double nbr)
{
    if (nbr - ft_floor(nbr) == 0.5 && (long long)ft_floor(nbr) % 2 == 0)
        return (ft_floor(nbr));
    else if (ft_ceil(nbr) - nbr == 0.5)
        return (ft_ceil(nbr));
    if(nbr - ft_floor(nbr) >= 0.5)
        return (ft_ceil(nbr));
    else
        return (ft_floor(nbr));
}

void    put_nb_str(uintmax_t nb, char **str)
{
    if (nb >= 10)
    {
        put_nb_str(nb / 10, str);
        put_nb_str(nb % 10, str);
    }
    else
    {
        **str = (char)(nb + '0');
        (*str)++;
    }
}

//char		*round_me(long double nbr, t_e *func, char *str)
//{
//    int			i;
//    int			acc;
//    int 		j;
//
//    j = 0;
//    acc = func->precision;
//    while (acc > 0)
//    {
//        nbr *= 10;
//        if (acc == 1)
//            nbr = get_size_nb(nbr);
//        i = (int) nbr;
//        str[j] = (char)(i + '0');
//        nbr = nbr - i;
//        acc--;
//        j++;
//    }
//    str[j] = '\0';
//    return (str);
//}
//
//char		*round_me_d(long double nbr, t_e *func, char *str)
//{
//    int			p;
//    long long	nbr_l;
//    int i;
//    char *string;
//    char *tmp;
//
//    i = 0;
//    p = func->precision;
//    while (p > 0 && p-- > 0)
//        nbr *= 10;
//    nbr_l = fraction_nb(nbr);
//    p = func->precision - get_size_nb(nbr_l);
//    while (p > 0)
//    {
//        str[i++] = '0';
//        p--;
//    }
//    str[i] = '\0';
//    tmp = str;
//    string = u_itoa_base(nbr_l, 10);
//    str = ft_strjoin(tmp, string);
// //   free(tmp);
//    free(string);
//    return (str);
//}

void    round_me_d(long double nb, t_e *e, char *str)
{
    long long   nb_len;
    int         if_prec;

    if_prec = e->precision;
    while (if_prec > 0 && if_prec-- > 0)
        nb *= 10;
    nb_len = fraction_nb(nb);
    if_prec = e->precision - get_size_nb(nb_len);
    while (if_prec > 0 && if_prec-- > 0)
    {
        *str = '0';
        str++;
    }
    put_nb_str(nb_len, &str);
}

void    round_me(long double nb, t_e *e, char *str)
{
    int     if_prec;
    int     i;

    if_prec = e->precision;
    while (if_prec > 0)
    {
        nb *= 10;
        if (if_prec == 1)
            nb = fraction_nb(nb);
        i = (int)nb;
        *str = i + '0';
        nb = nb - i;
        str++;
        if_prec--;
    }
}

char    *itoa_double(long double val, t_e *e)
{
    int         total_size; // 0
    int         size_sign; // 1
    int         size_width_len; // 3
    int         size_exponenta; // 4
    int         size_dot; // 5
    int         size_presigion; // 6
    char        sign;
    char        *str;
    char        *s;
    long long   round_nb;

    size_sign = 0;
    sign = 0;
    if (val < 0 || (1 / val) < 0)
    {
        val = MOD(val);
        sign = '-';
    }
    else if (e->f->plus)
        sign = '+';
    else if (e->f->space)
        sign = ' ';
    if (sign == ' ' || sign == '-' || sign == '+')
        size_sign = 1;
    if (e->precision == 0)
        val = fraction_nb(val);
    round_nb = (long long)MOD(val);
    size_exponenta = get_size_nb(round_nb);
    size_width_len = 0;
    size_presigion = e->precision;
    size_dot = (size_presigion || e->f->hash) ? 1 : 0;
    total_size = size_sign + size_exponenta + size_dot + size_presigion;
    if (e->f->zero && e->width > total_size && !e->f->minus)
    {
        size_width_len = e->width - total_size;
        total_size = e->width;
    }
    str = ft_strnew((size_t)total_size);
    s = str;
    int     i = 0;
    if (sign != 0)
    {
        *str = sign;
        str++;
        i++;
    }
    while ((size_width_len - size_sign) > i++)
    {
        *str = '0';
        str++;
    }
    put_nb_str(round_nb, &str);
    if (size_dot)
    {
        *str = '.';
        str++;
    }
    if (size_presigion > 0 && size_presigion < 16)
        round_me_d(MOD(val) - (long double)round_nb, e, str);
    else
        round_me(MOD(val) - (long double)round_nb, e, str);

    return (s);
}

void    get_f(long double nb, t_e *e)
{
    char    *res;

    res = NULL;
    if (e->f->minus)
        e->f->zero = 0;
    if (e->precision == -1 && !(e->spec == 'g' || e->spec == 'G' || e->spec == 'a' || e->spec == 'A'))
        e->precision = 6;
    if (nb != nb)
        res = (e->spec == 'g' || e->spec == 'e' || e->spec == 'f' || e->spec == 'a') ? ft_strdup("nan") : ft_strdup("NAN");
    else if (nb == -0.1 / 0.0)
        res = (e->spec == 'g' || e->spec == 'e' || e->spec == 'f' || e->spec == 'a') ? ft_strdup("-inf") : ft_strdup("-INF");
    else if (nb == 0.1 / 0.0)
        res = (e->spec == 'g' || e->spec == 'e' || e->spec == 'f' || e->spec == 'a') ? ft_strdup("inf") : ft_strdup("INF");
    if (res == NULL)
        res = itoa_double(nb, e);

    e->bits_count += write(e->fd, res, ft_strlen(res));
    free(res);
}
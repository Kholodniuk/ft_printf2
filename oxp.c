/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oxp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 15:03:19 by skholodn          #+#    #+#             */
/*   Updated: 2017/03/20 13:38:20 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_lower(t_oxp *oxp)
{
	int		i;

	if (oxp->prefix != NULL && oxp->prefix[1] == 'X')
		oxp->prefix[1] = 'x';
	i = 0;
	while (oxp->nbr[i])
	{
		oxp->nbr[i] = (char)ft_tolower(oxp->nbr[i]);
		i++;
	}
}

void	init_char_oxp(t_oxp *oxp, t_e *e)
{
	int		sz_zero;
	int		sz_space;

	sz_space = oxp->size_space;
	sz_zero = oxp->size_zero;
	oxp->zero = ft_strnew((size_t)sz_zero);
	while (--sz_zero > -1)
		oxp->zero[sz_zero] = '0';
	oxp->space = ft_strnew((size_t)sz_space);
	while (--sz_space > -1)
		oxp->space[sz_space] = ' ';
	oxp->prefix = ft_strnew((size_t)oxp->size_prefix);
	if (oxp->size_prefix == 2)
		oxp->prefix = ft_strcat(oxp->prefix, "0X");
	else if (oxp->size_prefix == 1)
		oxp->prefix = ft_strcat(oxp->prefix, "0");
	if (e->spec == 'x' || e->spec == 'p')
		get_lower(oxp);
}

t_oxp	*init_oxp(uintmax_t nb, t_e *e)
{
	t_oxp	*oxp;

	oxp = malloc(sizeof(t_oxp));
	if (e->spec == 'o' || e->spec == 'O')
		oxp->nbr = GET_NB ? ft_strnew(0) : u_itoa_base(nb, 8);
	else
		oxp->nbr = GET_HEX ? ft_strnew(0) : u_itoa_base(nb, 16);
	oxp->size_nbr = (int)ft_strlen(oxp->nbr);
	oxp->size_space = 0;
	oxp->size_prefix = 0;
	if (P_N_X >= 0 && nb && (e->precision < e->width))
		oxp->size_space = 1;
	if (e->spec == 'p' || ((e->spec == 'x' || e->spec == 'X')
				&& e->f->hash && nb != 0))
		oxp->size_prefix = 2;
	else if ((e->spec == 'o' || e->spec == 'O') && e->f->hash)
		oxp->size_prefix = 1;
	oxp->size_zero = 0;
	get_if_oxp(&nb, e, oxp);
	init_char_oxp(oxp, e);
	return (oxp);
}

void	free_oxp(t_oxp *oxp)
{
	ft_strdel(&oxp->prefix);
	ft_strdel(&oxp->space);
	ft_strdel(&oxp->zero);
	ft_strdel(&oxp->nbr);
	free(oxp);
}

void	get_oxp(uintmax_t nb, t_e *e)
{
	t_oxp	*oxp;

	oxp = init_oxp(nb, e);
	if (e->f->minus == 1)
	{
		e->bits_count += write(e->fd, oxp->prefix, ft_strlen(oxp->prefix));
		e->bits_count += write(e->fd, oxp->zero, ft_strlen(oxp->zero));
		e->bits_count += write(e->fd, oxp->nbr, ft_strlen(oxp->nbr));
		e->bits_count += write(e->fd, oxp->space, ft_strlen(oxp->space));
	}
	else
	{
		e->bits_count += write(e->fd, oxp->space, ft_strlen(oxp->space));
		e->bits_count += write(e->fd, oxp->prefix, ft_strlen(oxp->prefix));
		e->bits_count += write(e->fd, oxp->zero, ft_strlen(oxp->zero));
		e->bits_count += write(e->fd, oxp->nbr, ft_strlen(oxp->nbr));
	}
	free_oxp(oxp);
}

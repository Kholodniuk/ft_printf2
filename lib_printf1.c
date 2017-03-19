/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_printf1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 15:24:17 by skholodn          #+#    #+#             */
/*   Updated: 2017/03/04 15:24:22 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


char	*ft_strdup(const char *src)
{
    int		lng;
    char	*copy;

    lng = 0;
    while (src[lng])
        lng++;
    copy = (char *)malloc(sizeof(char) * (lng + 1));
    if (!copy)
        return (0);
    ft_strcpy(copy, src);
    return (copy);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 16:48:12 by skholodn          #+#    #+#             */
/*   Updated: 2017/03/03 16:48:44 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** LIBRARIES
*/

# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>
# include <stdlib.h>
# include <wchar.h>
# include <string.h>
# include <stddef.h>

# define DIGIT(d) (d >= '0' && d <= '9' ? 1 : 0)
# define MOD(x) ((x) < 0 ? -(x) : (x))
# define CEIL(x) ((x) <= (long long)(x) ? (x) : (x + 1))
# define FLOOR(x) ((x) >= (long long)(x) ? (x) : (x - 1))

# define SPEC "sSpdDioOuUxXcC"

# define H_H (**fmt == 'h' && *(*fmt + 1) == 'h')
#define L_L (**fmt == 'l' && *(*fmt + 1) == 'l')
# define P_N (e->precision - di->size_nbr)
# define W_N (e->width - di->size_nbr)
# define P_N_U (e->precision - u->size_nbr)
# define W_N_U (e->width - u->size_nbr)
# define P_N_X (e->precision - oxp->size_nbr)
# define W_N_X (e->width - oxp->size_nbr)

# define    BLACK           	"\033[22;30m"
# define    BLACK_COLOR     	"{black}"
# define    RED             	"\033[22;31m"
# define    RED_COLOR       	"{red}"
# define    GREEN           	"\033[22;32m"
# define    GREEN_COLOR     	"{green}"
# define    BROWN           	"\033[22;33m"
# define    BROWN_COLOR     	"{brown}"
# define    BLUE            	"\033[22;34m"
# define    BLUE_COLOR      	"{blue}"
# define    MAGENTA         	"\033[22;35m"
# define    MAGENTA_COLOR   	"{magenta}"
# define    CYAN            	"\033[22;36m"
# define    CYAN_COLOR      	"{cyan}"
# define    GRAY            	"\033[22;37m"
# define    GRAY_COLOR      	"{gray}"
# define    DARK_GRAY       	"\033[01;30m"
# define    DARK_GRAY_COLOR 	"{dark gray}"
# define    LIGHT_RED			"\033[01;31m"
# define    LIGHT_RED_COLOR 	"{light red}"
# define    LIGHT_GREEN     	"\033[01;32m"
# define    LIGHT_GREEN_COLOR	"{light green}"
# define    LIGHT_YELLOW   		"\033[01;33m"
# define    LIGHT_YELLOW_COLOR  "{light yellow}"
# define    LIGHT_BLUE     		"\033[01;34m"
# define    LIGHT_BLUE_COLOR    "{light blue}"
# define    LIGHT_MAGENTA  		"\033[01;35m"
# define    LIGHT_MAGENTA_COLOR "{light magenta}"
# define    LIGHT_CYAN     		"\033[01;36m"
# define    LIGHT_CYAN_COLOR    "{light cyan}"
# define    WHITE          		"\033[01;37m"
# define    WHITE_COLOR     	"{white}"
# define    EOC            		"\033[0m"
# define    EOC_COLOR           "{eoc}"

#define NP_NULL "<NULL>" // - 0
#define NP_SOH "<SOH>"   // - 1
#define NP_STX "<STX>"	 // - 2
#define NP_ETX "<ETX>"	 // - 3
#define NP_EOT "<EOT>"	 // - 4
#define NP_ENQ "<ENQ>"	 // - 5
#define NP_ACK "<ACK>"	 // - 6
#define NP_BEL "<BEL>"	 // - 7
#define NP_BS "<BS>"	 // - 8
#define NP_HT "<HT>"	 // - 9
#define NP_LF "<LF>"	 // - 10
#define NP_VT "<VT>"	 // - 11
#define NP_FF "<FF>"	 // - 12
#define NP_CR "<CR>"	 // - 13
#define NP_SO "<SO>"	 // - 14
#define NP_SI "<SI>"	 // - 15
#define NP_DLE "<DLE>"	 // - 16
#define NP_DC1 "<DC1>"	 // - 17
#define NP_DC2 "<DC2>"	 // - 18
#define NP_DC3 "<DC3>"	 // - 19
#define NP_DC4 "<DC4>"	 // - 20
#define NP_NAK "<NAK>"	 // - 21
#define NP_SYN "<SYN>"	 // - 22
#define NP_ETB "<ETB>"	 // - 23
#define NP_CAN "<CAN>"	 // - 24
#define NP_EM "<EM>"	 // - 25
#define NP_SUB "<SUB>"	 // - 26
#define NP_ESC "<ESC>"	 // - 27
#define NP_FS "<FS>"	 // - 28
#define NP_GS "<GS>"	 // - 29
#define NP_RS "<RS>"	 // - 30
#define NP_US "<US>"	 // - 31
#define NP_CHAR "<NOT A NON-PRINTABLE CHAR>"


typedef struct s_di
{
    int         size_zero;
    int         size_space;
    int         size_nbr;
    int         size_sign;
    char        *zero;
    char        *space;
    char        *nbr;
    char        *sign;
}               t_di;

typedef struct s_u
{
    int         size_zero;
    int         size_space;
    int         size_nbr;
    char        *zero;
    char        *space;
    char        *nbr;
}               t_u;

typedef struct s_oxp
{
    int         size_zero;
    int         size_space;
    int         size_nbr;
    int         size_prefix;
    char        *zero;
    char        *space;
    char        *nbr;
    char        *prefix;
}               t_oxp;

typedef struct s_feg
{
    int         size_space;
    int         size_exp;
    int         size_dot;
    int         size_fract;
    int         size_sign;
    int         size_nbr;
    char        *space;
    char        *nbr;
    char        *exp;
    char        *dot;
    char        *fract;
    char        *sign;
}               t_feg;

typedef struct s_s
{
    int         size_space;
    int         size_str;
    char        *space;
    char        *str;
}               t_s;


typedef struct s_fl
{
    int     plus;
    int     minus;
    int     space;
    int     hash;
    int     zero;
    int     apostrophe;
}               t_fl;

typedef struct  s_e
{
    int         bits_count;
    t_fl        *f;
    int         mod;
    int         width;
    int         precision;
    int         dollar;
    char        spec;
    int         fd;
}               t_e;

int     ft_printf(char *fmt, ...);
int     ft_vsprintf(int bits_count, char *fmt, va_list ar);
void    parse_persent(t_e *e, char **fmt, va_list ar, va_list tmp);
void    make_fprintf(t_e *e, va_list ar);
void    get_nbr(intmax_t nb, t_e *e);
void    get_unbr(uintmax_t nb, t_e *e);
void    get_oxp(uintmax_t nb, t_e *e);
void    get_str(char *arg, t_e *e);
void    apply_width(t_e *e);
void    get_char(int c, t_e *e);
void    get_wstr(wchar_t *str, t_e *e);
void    get_n(int	*n, t_e *e);
int     parse_color(t_e *e, char *fmt, va_list ar);
void    find_color(t_e *e, char **fmt, va_list ar);
void    get_f(long double nb, t_e *e);
void    get_noprint(char *str, t_e *e);
void    get_iso_data(long date, t_e *e);
void    get_binary(unsigned char c, t_e *e);

char    *ft_strcat(char *dest, const char *src);
size_t  ft_strlen(const char *str);
char    *ft_strnew(size_t size);
int     ft_atoi(const char *s);
int     ft_tolower(int c);
char    *ft_strncpy(char *dest, const char *src, size_t len);
char    *ft_strcpy(const char *dest, const char *src);
char    *ft_strchr(const char *s, int c);
void    ft_strdel(char **str);
char    *ft_strdup(const char *src);
int     ft_strstr_stop(const char *str, const char *to_find);

char    *u_itoa_base(uintmax_t value, uintmax_t base);
char    *itoa_double(long double val, t_e *e);
int     get_size_nb(uintmax_t nb);

#endif
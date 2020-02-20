#ifndef PRINTF_H
# define PRINTF_H

# include <stdint.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"


typedef struct  s_float
{
	char	sign;
	int		exp;
	char	*mantissa;
}				t_float;

typedef struct  s_lfloat
{
	char	sign;
	int		exp;
	char	*mantissa;
}				t_lfloat;

char			*ft_strjoin_pf(char *s1, char c, int n);
char			*ft_strjoin_pf_2(char **s1, char c);
char			*ft_joinstr_pf(char *s1, char c, int n);

int				display_null(void);
int				display_nil(void);
int				ft_printf(const char *format, ...);
int				display_nbr(intmax_t n, int *f_type, int f);
int				display_un_nbr(uintmax_t n, int *f_type, int f);
void			display_str(const char *s, int len);
void			display_float(const char *s, int len, int *f_t, int neg);
intmax_t		get_nbr(va_list args, int *f_type);
uintmax_t		get_nbr_un(va_list args, int *f_type);
int				pf_atoi(const char *str);
int				check_flags(char *conv, char *flags, int *f_type, char *str);
int				check_wildcard(int *f_type);
void			check_f_asterix(va_list args, int *f_type);
int				get_conversion(char s, char *conv);
int				get_width(char *str, int *f_type, int *k);
int				get_precision(char *str, int *f_type, int *k);
int				get_l_type(int *f_type, char *s, int *k);
int				c_type(va_list args, int *f_type);
int				p_type(va_list args, int *f_type);
int				perc_type(va_list args, int *f_type);
int				s_type(va_list args, int *f_type);
int				d_type(va_list args, int *f_type);
int				o_type(va_list args, int *f_type);
int				u_type(va_list args, int *f_type);
int				ul_type(va_list args, int *f_type);
int				x_type(va_list args, int *f_type);
int				X_type(va_list args, int *f_type);
int				f_type(va_list args, int *f_t);
int				lf_type(va_list args, int *f_t);
int				fill_w_char(int *f_type, int neg, int f_plus, char f);
int				check_f_space(int *f_type, int neg);
int				check_f_plus(int *f_type, int neg);
int				check_f_hash(int *f_type, char f);
int				check_neg(int *f_type, int neg);
int				check_precision(int *f_type, intmax_t d);
int				check_ul_precision(int *f_type, uintmax_t d);
int				len(intmax_t num);
char			*d_to_o(intmax_t dig);
char			*d_to_x(intmax_t dig);
char			*d_to_X(intmax_t dig);
int				put_converted_num(char *s, int *f_type, char conv);

/*
** Float
*/

char			*get_btoi(char *s);
char			*get_btofr(char *s);
char			*handle_mantissa(t_float *fdb);
char			*strshift(char **s, size_t n);
t_float			*get_fdb(double d);
char			*s_division(char **s);
char			*add_int(char **s1, char *s2, int f);
char			*add_frac(char **s1, char *s2);

/*
** Float_L
*/

char			*handle_lmantissa(t_lfloat *fdb);
t_lfloat		*get_lfdb(long double d);

#endif

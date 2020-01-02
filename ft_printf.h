/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 14:46:01 by atahiri           #+#    #+#             */
/*   Updated: 2019/12/28 16:43:26 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# define CCONVERSIONS 	"cspdiuxX%"
# define ALLSYMBOLS 	"cspdiuxX%-.*0123456789"
# define CFLAGS "-.*0123456789"

typedef	struct	s_struct
{
	int				nprinted;
	int				i;
	int				hex;
	int				minus;
	int				zero;
	int				width;
	int				dot;
	int				etoile;
	int				precision;
}				t_struct;

void			conversions(const char *format, t_struct *f, va_list ap);
void			flags(const char *format, t_struct *f);
void			if_etoile(const char *format, t_struct *f, va_list ap);
void			width(const char *format, t_struct *f, va_list ap);
void			precision(const char *format, t_struct *f, va_list ap, int a);
void			handle_data(const char *format, t_struct *f, va_list ap);
void			zerostruct(t_struct *list);
void			zero2(t_struct *list);
void			*ft_memset(void *str, int c, size_t n);
void			int_handle(t_struct *f, long out_int, int refer, int int_len);
void			int_right(t_struct *f, long out_int, int refer, char *s);
void			precision_handling(t_struct *f, unsigned int unsi_len);
void			unsi_right(t_struct *f, char *s, unsigned int unsi_len);
void			unsi_left(t_struct *f, char *s, unsigned int unsi_len);
void			string_right(t_struct *f, char *out_str, int str_len);
void			string_left(t_struct *f, char *out_str, int str_len);
void			int_left(t_struct *f, int out_int, int refer, char *s);
void			if_zero(t_struct *f, unsigned int out_hexa, char *s);
void			character(t_struct *f, va_list ap);
void			hexa_right(t_struct *f, char *s);
void			hexa_left(t_struct *f, char *s);
void			precision_handling_hexa(t_struct *f, unsigned int hexa_len);
int				parsel2(t_struct *f, int posi, const char *format, va_list ap);
int				ft_printf(const char *format, ...);
int				hexadecimal(const char *format, t_struct *f, va_list ap);
int				ft_intlen(long x);
int				zero_input_p(t_struct *f, void *out_pointer);
int				formatparse(const char *fmt, t_struct *f, va_list ap, int pos);
int				ft_lenint(long x);
int				integer(t_struct *f, va_list ap);
int				zero_input(t_struct *f, int out_int);
int				ft_atoi(const char *str);
int				ft_strlen(const char *str);
int				zero_input_u(t_struct *f, unsigned int out_int);
int				is_unsigned(t_struct *list, va_list ap);
int				string(t_struct *f, va_list ap);
int				plug(t_struct *f, unsigned int hexa_len, char *s);
int				print_hexa(char *s);
int				pointer(t_struct *f, va_list ap);
int				percent(t_struct *f);
char			*ft_strchr(const char *str, int c);
char			ft_reverse(char *str);
char			*ft_strrev(char *str);
char			*ft_itoa(long n);
char			*ft_strdup(const char *s1);
char			*convert_to_hexa(t_struct *f, unsigned long dec, char s);
char			*ft_strjoin(char const *s1, char const *s2);
#endif

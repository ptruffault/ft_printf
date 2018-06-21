#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include "../libft/includes/libft.h"
#include <stdarg.h>
#include <stdint.h>
#include <wchar.h>


#define TEST_FLAG(x)  ((p->flag && ft_strchr(p->flag, x)) ? 1 : 0)
#define TEST_SPEC_NBR(x) ((x == 'd' || x == 'i' || x == 'o' ||x == 'O' || x == 'u' || x == 'U' || x == 'x' || x == 'X' || x == 'p') ? 1 : 0)
#define TEST_SPEC_CHAR(x) ((x == 's' || x == 'S' || x == 'c' || x == 'C') ? 1 : 0)

enum 	e_lenght
{

	hh = 0,
	h = 1,
	l = 2,
	ll = 3,
	j = 4,
	z = 5,
	t = 6,
	off = 7
};


typedef struct 	s_param
{
	char 			spec;  //
	char 			*flag;
	int 			width;
	int 			precision;
	enum e_lenght	elen;
	char 			signe;
	int 			opts_len;	


	char 			*value;
	int 			var_len;
	struct  s_param *next;	
}				t_param;


int ft_printf(char *format, ...);




//tools.c
char	*my_strjoin(char *s1, char *s2);
void	ft_putnchar(char c, int n);
char	*ft_strmap_i(char *s, int (*f)(int));
char	*ft_strndup_fr(char *str, int n);

//tools_tparam.c
char *ft_flag(t_param *param, char *ptr);
char *ft_width(t_param *param, char *ptr);
char *ft_precision(t_param *param, char *ptr);
char *ft_length(t_param *param, char *ptr);
char *ft_modifier(t_param *param, char *ptr);
t_param *init_tparam(char *format, va_list *ap);
void	free_tparam(t_param *p);
void	del_tparam(t_param *p);


//get_value
char 	*get_value(t_param *param, va_list *ap);
char 	*get_ox(t_param *p);

//wchar_t
char		*ft_wstr(int *arr, int precision);
char		*ft_wchar(int wchar);
#endif
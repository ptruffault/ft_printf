#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include "../libft/includes/libft.h"
#include <stdarg.h>
#include <stdint.h>


#define TEST_FLAG(x)  ((p->flag && ft_strchr(p->flag, x)) ? 1 : 0)


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


	char 	*value;
	int 	var_len;
	char 	signe;
	
}				t_param;


//TMP.c
void	ft_put_param(t_param *param);




char	*my_strjoin(char *s1, char *s2);
char  	*my_strjoin_fr(char *s1, char *s2);
//tools.c
char 	*ft_arr_to_str(char **arr);
char	*ft_strmap_i(char const *s, int (*f)(int));
void	error(char *descript, char *opts);
void	warning(char *descript, char *opts);
char 	*ft_stradd_char(char *str, char c);

char 	*ft_strnew_nchar(char c, int n);
int 	next_word(char *str);
void	ft_free(void *ptr);
char 	*ft_strjoin_fr(char *s1, char *s2);
char 	*char_to_str(char c);

//tools_tparam.c
char *ft_flag(t_param *param, char *ptr);
char *ft_width(t_param *param, char *ptr);
char *ft_precision(t_param *param, char *ptr);
char *ft_length(t_param *param, char *ptr);
char *ft_modifier(t_param *param, char *ptr);


//param.c
int		init(t_param *param, char *format);

//base
char		*ft_itoa_base_intmax(intmax_t value, int base);
char		*ft_itoa_base_unintmax(uintmax_t value, int base);



char	*add_value(char *format ,char *str, int *i, int *j, va_list *ap);

//get_value
char 	*get_value(t_param *param, va_list *ap);
char *get_dat_flag(t_param *p);
char 	*get_dioux(t_param *p, va_list *ap);
#endif
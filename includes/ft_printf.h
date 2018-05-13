#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include "../libft/libft.h"
#include <stdarg.h>

# define ALL_SPEC(c) (ALL_NUM(c) || OTHER(c) || CHAR_STR(c) ? 1 : 0)
//
# define ALL_NUM(c) (DEC_BASE(c) || DIFF_BASE(c) ? 1 : 0)

# define INT_NUM(c) ((c == 'd') || (c == 'D') || (c == 'i') ? 1 : 0)
# define UINT_NUM(c) ((c == 'u')  || (c == 'U') ? 1 : 0)
# define DEC_BASE(c) (INT_NUM(c) || UINT_NUM(c) ? 1 : 0)

# define DIFF_BASE(c) (OCTAL_BASE(c) || HEX_BASE(c) || BI_BASE(c) ? 1 : 0)
# define OCTAL_BASE(c) ((c == 'O') || (c == 'o') ? 1 : 0)
# define HEX_BASE(c) ((c == 'x') || (c == 'X') ? 1 : 0)
# define BI_BASE(c) ((c == 'b') || (c == 'B') ? 1 : 0)

# define STR_TYPE(c) ((c == 's') || (c == 'S') ? 1 : 0)
# define CHAR_TYPE(c) ((c == 'c')  || (c == 'C') ? 1 : 0)
# define CHAR_STR(c) STR_TYPE(c) || CHAR_TYPE(c)

# define OTHER(c) ((c == '%') || (c == 'p') ? 1 : 0)

typedef struct 	s_param
{
	char 	type;
	char 	*flag;
	int 	width;
	int 	precision;
	char 	*length;

	char *value;
	char sign;
	int var_len;
}				t_param;


//TMP.c
void	ft_put_param(t_param *param);

//tools.c
void	error(char *descript, char *opts);
void	warning(char *descript, char *opts);
char 	*ft_stradd_char(char *str, char c);
char 	*ft_strdel_char(char *str, char c);
char 	*ft_strnew_nchar(char c, int n);
int 	next_word(char *str);
void	ft_free(void *ptr);
char 	*ft_strjoin_fr(char *s1, char *s2);
char 	*ft_strndup_fr(char *str, int n);
char 	*char_to_str(char c);

//tools_tparam.c
char *ft_flag(t_param *param, char *ptr);
char *ft_width(t_param *param, char *ptr);
char *ft_precision(t_param *param, char *ptr);
char *ft_length(t_param *param, char *ptr);
char *ft_modifier(t_param *param, char *ptr);


//param.c
int		init(t_param *param, char *format);


//get_value
int get_value(t_param *param, va_list *ap);
char 	*ft_get_ap_value(t_param *param, va_list *ap);

#endif
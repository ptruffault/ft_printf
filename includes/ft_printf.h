#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/includes/libft.h"
# include <stdarg.h>
# include <stdint.h>
# include <wchar.h>
# define TEST(x) ((ft_strchr("#0 -+.0123456789lhjtz", x)) || TEST_SPEC(x))
# define TEST_SPEC(x) (TEST_SPEC_NBR(x) || TEST_SPEC_CHAR(x) || TEST_SPEC_WEIRD(x))
# define TEST_SPEC_NBR(x) (TEST_SIGN(x) || TEST_UNSIGN(x))
# define TEST_SPEC_CHAR(x) (TEST_STR(x) || TEST_CHAR(x))
# define TEST_UNSIGN(x) (TEST_X(x) || TEST_O(x) || TEST_U(x))
# define TEST_SIGN(x) (x == 'd' || x == 'D' || x == 'i')
# define TEST_SPEC_WEIRD(x) ((x == '%' || x == 'p' ))
# define TEST_X(x) (x == 'x' || x == 'X')
# define TEST_O(x) (x == 'o' ||x == 'O')
# define TEST_U(x) (x == 'u' || x == 'U')
# define TEST_STR(x) (x == 's' || x == 'S')
# define TEST_CHAR(x) (x == 'c' || x == 'C')
# define TEST_FLAG(str, x) (str != NULL && (ft_strchr(str, x)))
# define TEST_2OPTS(str, x) (TEST_FLAG(str, x) && *(ft_strchr(str, x) + 1) == 'x')

typedef struct	s_param
{
	char			spec;
	char			*flag;
	int				width;
	int				precision;
	char 			*length;
	char			signe;
	int				opts_len;
	char			*value;
	int				var_len;
	int				exep;
	struct s_param	*next;
}				t_param;

int		ft_printf(char *format, ...);
int		print(char *format, t_param *p);
char	*my_strjoin(char *s1, char *s2);
void	ft_putnchar(char c, int n);
char	*ft_strmap_i(char *s, int (*f)(int));
char	*ft_strndup_fr(char *str, int n);
t_param 	*read_option(char *format, va_list *ap, t_param *p);
t_param	*init_tparam(char *format, va_list *ap);
void	free_tparam(t_param *p);
char	*get_value(t_param *param, va_list *ap);
char	*get_ox(t_param *p, char *tmp_val);
char	*ft_wstr(int *arr, int precision);
char	*ft_wchar(int wchar);
#endif

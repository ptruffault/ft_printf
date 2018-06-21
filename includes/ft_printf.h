#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/includes/libft.h"
# include <stdarg.h>
# include <stdint.h>
# include <wchar.h>
# define TEST_FLAG(x)  ((p->flag && ft_strchr(p->flag, x)) ? 1 : 0)
# define TEST_SPEC_NBR(x) ((TEST_SIGN(x) || TEST_UNSIGN(x) || x == 'p') ? 1 : 0)
# define TEST_SPEC_CHAR(x) ((TEST_STR(x) || TEST_CHAR(x)) ? 1 : 0)
# define TEST_SIGN(x) ((x == 'd' || x == 'D' || x == 'i') ? 1 : 0)
# define TEST_UNSIGN(x) ((TEST_X(x) || TEST_O(x) || TEST_U(x)) ? 1 : 0)
# define TEST_X(x) ((x == 'x' || x == 'X')? 1 : 0)
# define TEST_O(x) ((x == 'o' ||x == 'O') ? 1 : 0)
# define TEST_U(x) ((x == 'u' || x == 'U') ? 1 : 0)
# define TEST_STR(x) ((x == 's' || x == 'S') ? 1 : 0)
# define TEST_CHAR(x) ((x == 'c' || x == 'C') ? 1 : 0)

enum	e_lenght
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

typedef struct	s_param
{
	char			spec;
	char			*flag;
	int				width;
	int				precision;
	enum e_lenght	elen;
	char			signe;
	int				opts_len;
	char			*value;
	int				var_len;
	struct s_param	*next;
}				t_param;

int		ft_printf(char *format, ...);
void	print(char *format, t_param *p);
char	*my_strjoin(char *s1, char *s2);
void	ft_putnchar(char c, int n);
char	*ft_strmap_i(char *s, int (*f)(int));
char	*ft_strndup_fr(char *str, int n);
char	*ft_flag(t_param *param, char *ptr);
char	*ft_width(t_param *param, char *ptr);
char	*ft_precision(t_param *param, char *ptr);
char	*ft_length(t_param *param, char *ptr);
char	*ft_modifier(t_param *param, char *ptr);
t_param	*init_tparam(char *format, va_list *ap);
void	free_tparam(t_param *p);
char	*get_value(t_param *param, va_list *ap);
char	*get_ox(t_param *p);
char	*ft_wstr(int *arr, int precision);
char	*ft_wchar(int wchar);
#endif

#include "../../includes/ft_printf.h"

char	*get_ox(t_param *p, char *tmp_val)
{
	char *ret;

	ret = NULL;
	if (p->spec != 'o' && p->spec != 'x' && p->spec != 'O' && p->spec != 'X'
	&& p->spec != 'p')
		warning_c("'#' incompatible with :", p->spec);
	else if (ft_atoi(tmp_val) != 0 && p->spec == 'x' && !(ret = ft_strdup("0x\0")))
		return (NULL);
	else if (ft_atoi(tmp_val) != 0 && p->spec == 'X' && !(ret = ft_strdup("0X\0")))
		return (NULL);
	else if ((p->spec == 'o' || p->spec == 'O') && !(ret = ft_strdup("0\0")))
		return (NULL);
	else if (p->spec == 'p' && !(ret = ft_strdup("0x")))
		return (NULL);
	p->var_len = p->var_len + ft_strlen(ret);
	return (ret);
}

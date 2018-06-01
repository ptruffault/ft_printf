#include "../../includes/ft_printf.h"

char *get_ox(t_param *p)
{
	char *ret;

	if (p->spec != 'o' && p->spec != 'x' && p->spec != 'O' && p->spec != 'X' && p->spec != 'p')
		warning("flag '#' incompatible with type sprecifier :", char_to_str(p->spec));
	else if (((p->spec == 'o' || p->spec =='O') && !(ret = ft_strdup("0\0")))
	|| (p->spec == 'x' && !(ret = ft_strdup("oX\0")))
	|| (p->spec == 'X' && !(ret = ft_strdup("0X\0")))
	|| (p->spec == 'p' && !(ret = ft_strdup("0x\0"))))
		return (NULL);
	p->var_len = p->var_len + ft_strlen(ret);
	return (ret);
}


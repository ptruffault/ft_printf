#include "../../includes/ft_printf.h"

char *get_dat_flag(t_param *p)
{
	char *ret;

	if ((p->spec == 'o' && !(ret = ft_strdup("0")))
	|| (p->spec == 'x' && !(ret = ft_strdup("oX")))
	|| (p->spec == 'X' && !(ret = ft_strdup("0X"))))
		return (NULL);
	else if (p->spec != 'o' && p->spec != 'x' && p->spec != 'O')
		warning("flag '#' incompatible with type sprecifier :", char_to_str(p->spec));
	return (ret);
}


#include "../../includes/ft_printf.h"

void	warning(char *descript, char *opts)
{
	ft_putstr_fd("\033[1;32m\033[04mft_printf\033[00m:", 2);
	ft_putstr_fd("\033[1;35mWARNING\n\033[00m\t", 2);
	ft_putstr_fd(descript, 2);
	if (opts)
	{
		ft_putstr_fd(" \033[00m'\033[1;32m", 2);
		ft_putstr_fd(opts, 2);
		ft_putstr_fd("\033[00m'",2);
	}
	ft_putchar_fd('\n', 2);
}

void	error(char *descript, char *opts)
{
	ft_putstr_fd("\033[1;32m\033[04mft_printf :", 2);
	ft_putstr_fd("\033[00;31mERROR\n\033[00m\t", 2);
	ft_putstr_fd(descript, 2);
	if (opts)
	{
		ft_putstr_fd(" \033[00m'\033[1;32m", 2);
		ft_putstr_fd(opts, 2);
		ft_putstr_fd("\033[00m'",2);
	}
	ft_putchar_fd('\n', 2);
}
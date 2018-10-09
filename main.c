/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 18:14:16 by ptruffau          #+#    #+#             */
/*   Updated: 2018/10/04 18:14:18 by ptruffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void test_sS(void)
{
	printf("%.4s\n", "42");
	ft_printf("%.4s\n", "42");

	printf("%.4s\n", "42 is the answer");
	ft_printf("%.4s\n", "42 is the answer");

	printf("%15.4s\n", "42");
	ft_printf("%15.4s\n", "42");

	printf("%15.4s\n", "I am 42");
	ft_printf("%15.4s\n", "I am 42");

	printf("%15.4s\n", "42 is the answer");
	ft_printf("%15.4s\n", "42 is the answer");

	printf("%4.15s\n", "42");
	ft_printf("%4.15s\n", "42");

	printf("%4.15s\n", "I am 42");
	ft_printf("%4.15s\n", "I am 42");

	printf("%4.15s\n", "42 is the answer");
	ft_printf("%4.15s\n", "42 is the answer");

	printf("%4.s\n", "42");
	ft_printf("%4.s\n", "42");

	printf("%.4S\n", L"我是一只猫。");
	ft_printf("%.4S\n", L"我是一只猫。");

	printf("%15.4S\n", L"我是一只猫。");
	ft_printf("%15.4S\n", L"我是一只猫。");


	printf("%4.15S\n", L"我是一只猫。");
	ft_printf("%4.15S\n", L"我是一只猫。");

	printf("%4.S\n", L"我是一只猫。");
	ft_printf("%4.S\n", L"我是一只猫。");

	printf("%4.1S\n", L"Jambon");
	ft_printf("%4.1S\n", L"Jambon");
}

void test_hh(void)
{

	printf("%hhd\n", CHAR_MAX + 42);
	ft_printf("%hhd\n", CHAR_MAX + 42);

	printf("%hhd\n", -129);
	ft_printf("%hhd\n", -129);

	printf("%hhd\n", CHAR_MIN - 42);
	ft_printf("%hhd\n", CHAR_MIN - 42);

	printf("%hhu, %hhu\n", 0, UCHAR_MAX);
	ft_printf("%hhu, %hhu\n", 0, UCHAR_MAX);

	printf("%hhi%hhi\n", 0, 42);
	ft_printf("%hhi%hhi\n", 0, 42);

}

void test_pourcent(void)
{
	printf("%.3%\n");
	ft_printf("%.3%\n");

	printf("%%%%%%\n");
	ft_printf("%%%%%%\n");
}

void	test_cC(void)
{
	
	printf("%c\n",0 );
	ft_printf("%c\n", 0);

	printf("%.2c\n", NULL);
	ft_printf("%.2c\n", NULL);

	printf("null %c and text\n", 0);
	ft_printf("null %c and text\n", 0);

	printf("% c", 0);
	ft_printf("% c", 0);

	printf("{%03c}\n", 0);
	ft_printf("{%03c}\n", 0);

}

void invalid_test(void)
{
	printf("{%10R}\n");
	ft_printf("{%10R}\n");
}

void pointeur(void)
{
	printf("%.5p\n", 0);
	ft_printf("%.5p\n", 0);

	printf("{%05p}\n", 0);
	ft_printf("{%05p}\n", 0);

}


int		main(int argc, char **argv)
{
	//test_hh();
	//test_pourcent();
	//test_cC();
	//invalid_test();
	//pointeur();
	printf("{%05.s}\n", 0);
	ft_printf("{%05.s}\n", 0);

}

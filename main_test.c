#include "includes/ft_printf.h"

/*
# 0142 (signed char)
  ft_printf("%hhd", 128);
  1. (    3) -->128<--
  2. (    4) -->-128<--

# 0144 (signed char)
  ft_printf("%hhd", -129);
  1. (    4) -->-129<--
  2. (    3) -->127<--
*/

# 0005 
  ft_printf("% hZ");
  1. (    2) -->hZ<--
  2. (    1) -->Z<--

# 0008 
  ft_printf("% hZ%");
  1. (    2) -->hZ<--
  2. (    1) -->Z<--

# 0009 (char *)
  ft_printf("% Z", "test");
  1. (    2) --> Z<--
  2. (    1) -->Z<--

# 0010 (char *)
  ft_printf("% Z ", "test");
  1. (    3) --> Z <--
  2. (    2) -->Z <--

# 0011 (char *)
  ft_printf("% Z%s", "test");
  1. (    6) --> Ztest<--
  2. (    5) -->Ztest<--

# 0013 (char *)
  ft_printf("%%%", "test");
  1. (    5) -->%test<--
  2. (    1) -->%<--

# 0014 (char *)
  ft_printf("%%   %", "test");
  1. (    8) -->%   test<--
  2. (    4) -->%   <--

# 0019 (int)
  ft_printf("% Z", 42);
  1. (    2) --> Z<--
  2. (    1) -->Z<--

# 0030 (size_t)
  ft_printf("%zhd", 4294967296);
  1. (    1) -->0<--
  2. (   10) -->4294967296<--

# 0038 (int)
  ft_printf("@main_ftprintf: %####0000 33..1..#00d\\n", 256);
  1. (   51) -->^[[04m^[[1;35mWarning:^[[00m'#' incompatible with : ^[[1;32m(^[[00md^[[1;32m)^[[00m$\n@main_ftprintf:                               256\\n<--
  2. (   51) -->@main_ftprintf:                               256\\n<--

# 0039 (int)
  ft_printf("@main_ftprintf: %####0000 33..1d", 256);
  1. (   49) -->^[[04m^[[1;35mWarning:^[[00m'#' incompatible with : ^[[1;32m(^[[00md^[[1;32m)^[[00m$\n@main_ftprintf:                               256<--
  2. (   49) -->@main_ftprintf:                               256<--

# 0040 (int)
  ft_printf("@main_ftprintf: %###-#0000 33...12..#0+0d", 256);
  1. (   49) -->^[[04m^[[1;35mWarning:^[[00m'#' incompatible with : ^[[1;32m(^[[00md^[[1;32m)^[[00m$\n@main_ftprintf: +256                             <--
  2. (   49) -->@main_ftprintf: +256                             <--

int main(void)
{
  ft_printf("%%%", "test");
  printf("%%%", "test");
 //printf("%%%\n", "test");
	return 0;
}
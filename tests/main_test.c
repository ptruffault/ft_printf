#include "../includes/ft_printf.h"
/*
# 0080 (char)
  ft_printf("%2c", 0);
  1. (    3) -->  ^@<--
  2. (    2) --> ^@<--

# 0082 (char)
  ft_printf("% c", 0);
  1. (    0) --><--
  2. (    1) -->^@<--

# 0150 (long long)
  ft_printf("%lld", -9223372036854775808);
  1. (   21) -->--9223372036854775808<--
  2. (   20) -->-9223372036854775808<--

# 0152 (intmax_t)
  ft_printf("%jd", -9223372036854775808);
  1. (   21) -->--9223372036854775808<--
  2. (   20) -->-9223372036854775808<--

# 0195 (unsigned long)
  ft_printf("%hU", 4294967296);
  1. (    1) -->0<--
  2. (   10) -->4294967296<--
*/
int main(void)
{ 



	
	return 0;
}
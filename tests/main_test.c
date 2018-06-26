#include "../includes/ft_printf.h"
/*
 ft_printf("%x", 0);                           -> "0"
 ft_printf("%X", 0);                           -> "0"
 ft_printf("%x", 4294967296);                  -> "0"
 ft_printf("%X", 4294967296);                  -> "0"
 ft_printf("%x", test);                        -> "0"
 ft_printf("%hx", 4294967296);                 -> "0"
 ft_printf("%hhX", 4294967296);                -> "0"
 ft_printf("%#x", 0);                          -> "0"
 ft_printf("@moulitest: %#.x %#.0x", 0, 0);    -> "@moulitest:  "
 ft_printf("@moulitest: %.x %.0x", 0, 0);      -> "@moulitest:  "
 ft_printf("@moulitest: %5.x %5.0x", 0, 0);    -> "@moulitest:            "
 ft_printf("@moulitest: %s", NULL);            -> "@moulitest: (null)"
 ft_printf("%.2c", NULL);                      -> "^@"
 ft_printf("%s %s", NULL, string);             -> "(null) string"
 ft_printf("@moulitest: %c", 0);               -> "@moulitest: ^@"
 ft_printf("%2c", 0);                          -> " ^@"
 ft_printf("null %c and text", 0);             -> "null ^@ and text"
 ft_printf("% c", 0);                          -> "^@"
 ft_printf("@moulitest: %o", 0);               -> "@moulitest: 0"
 ft_printf("@moulitest: %.o %.0o", 0, 0);      -> "@moulitest:  "
 ft_printf("@moulitest: %5.o %5.0o", 0, 0);    -> "@moulitest:            "
 ft_printf("@moulitest: %#.o %#.0o", 0, 0);    -> "@moulitest: 0 0"
 ft_printf("%d", 1);                           -> "1"
 ft_printf("the %d", 1);                       -> "the 1"
 ft_printf("%d is one", 1);                    -> "1 is one"
 ft_printf("%d", -1);                          -> "-1"
 ft_printf("%+d", 0);                          -> "+0"
 ft_printf("%+d", 4242424242424242424242);     -> "-1"
 ft_printf("%0+5d", 42);                       -> "+0042"
 ft_printf("%05d", -42);                       -> "-0042"
 ft_printf("%0+5d", -42);                      -> "-0042"
 ft_printf("%hd", −32768);                   -> "0"
 ft_printf("%hd", −32769);                   -> "0"
 ft_printf("%hhd", 128);                       -> "-128"
 ft_printf("%hhd", -129);                      -> "127"
 ft_printf("%lld", -9223372036854775808);      -> "-9223372036854775808"
 ft_printf("%jd", -9223372036854775808);       -> "-9223372036854775808"
 ft_printf("%zd", -0);                         -> "0"
 ft_printf("%zd", -1);                         -> "-1"
 ft_printf("%d", 1);                           -> "1"
 ft_printf("%d %d", 1, -2);                    -> "1 -2"
 ft_printf("%d %d %d", 1, -2, 33);             -> "1 -2 33"
 ft_printf("%d %d %d %d", 1, -2, 33, 42);      -> "1 -2 33 42"
 ft_printf("%d %d %d %d gg!", 1, -2, 33, 42, 0); -> "1 -2 33 42 gg!"
 ft_printf("%03.2d", 0);                       -> " 00"
 ft_printf("%03.2d", 1);                       -> " 01"
 ft_printf("%03.2d", -1);                      -> "-01"
 ft_printf("@moulitest: %.d %.0d", 0, 0);      -> "@moulitest:  "
 ft_printf("@moulitest: %5.d %5.0d", 0, 0);    -> "@moulitest:            "
 ft_printf("%u", 0);                           -> "0"
 ft_printf("%u", 1);                           -> "1"
 ft_printf("%u", 4294967296);                  -> "0"
 ft_printf("%hU", 4294967296);                 -> "4294967296"

 */


int main(void)
{
	ft_printf("%x", 0);
	ft_printf("%X", 0); 
	ft_printf("%x", 4294967296);
	ft_printf("%X", 4294967296);

	return 0;
}
#include "header.h"
#include <stdio.h>

int	main(void)
{
	printf("%d\n", printf("Char: %c, Int: %d, Int: %i, Percent: %%, String: %s\n", '$', 555, -777, "@it_works@"));
	printf("%d\n", ft_printf("Char: %c, Int: %d, Int: %i, Percent: %%, String: %s\n", '$', 555, -777, "@it_works@"));
	printf("%d\n", printf("Char: %c, Int: %d\n", '$', 1234567890));
	printf("%d\n", ft_printf("Char: %c, Int: %d\n", '$', 1234567890));
	
	
	
	/*	char *str = "String";
	int	val = write(1, str, 6);
	printf("\n%d\n", val);

	int ret = printf("STR %d lol\n", 123);
	printf("%d\n", ret);
	printf("$%10d$\n", 1000);  //align right
	printf("$%-10d$\n", 1000); //align left
	printf("$%.10d$\n", 1000);
	printf("$%010d$\n", 1000);
	printf("%+d %+d\n", 1000, -1000); //print sign
	printf("% d % d\n", 1000, -1000); //space is sign place, if "+" print space, if "-" print "-"
	printf("%x %#x\n", 1000, 1000); //print
	printf("$%10s$\n", "lol");
	printf("$%.10s$\n", "lol");*/
}

#include <stdio.h>
#include <stdarg.h>

int	sumnum(int num, ...)
{
	int		sum;
	va_list	ptr;

	va_start(ptr, num);
	sum = 0;
	while (num)
	{
		sum += va_arg(ptr, int);
		--num;
	}
	va_end(ptr);
	return (sum);
}

void	printstrs(int num, ...)
{
	char	*str;
	va_list	ptr;

	va_start(ptr, num);
	while (num)
	{
		printf("%s\n", va_arg(ptr, char *));
		--num;
	}
}

int	main(void)
{
	printf("summ=%d\n", sumnum(5, 15, 5, 7, 3, 100));
	printstrs(3, "lol", "kek", "wow");
}

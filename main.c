#include "printf.h"
#include <limits.h>
#include <stdio.h>

int main() {
	int *s;
	int ds = 21474;
//	int i_max = 2147483647;
//	int i_min = -2147483648;
	int ret1;
	int ret2;
//	char c = 255;

	s = &ds;
//	printf("%%Hello, World!\n%s\n%hhX\n%p\n", "fs", c, s);
//	printf("Halo! %s __ %% _%c _ %% __%+035d _ %%\n", "Yo!", 'k', -2147483647);
//	ret2 = ft_printf("H%-s _ %% _%0+ #5-c _%+013d _ %x, %o, %p", "Yo!", 'k', -2147483647, ds, 211, s);
//	printf("Halo!_%0d _ %%\n", -123);
//	ft_printf("Halo!_%0d _ %%", -123);
//	printf("Halo!_%-+d _ %%\n", -123);
//	ft_printf("Halo!_%-+d _ %%", -123);
//	printf("Halo!_%- 8d _ %%\n", -123);
//	ft_printf("Halo!_%- 8d _ %%", -123);
//	printf("Halo!_%08d _ %%\n", -123);
//	ft_printf("Halo!_%08d _ %%", -123);
//	printf("Halo!_% 1d _ %%\n", -123);
//	ft_printf("Halo!_% 1d _ %%", -123);
//	ret1 = printf("Halo!_%28.24lX _ %%_pointer: %p. dec: %0+13d End!", 92233720368547758, s, i_max);
//	ret2 = ft_printf("Halo!_%28.24lX _ %%_pointer: %p. dec: %0+13d End!", 92233720368547758, s, i_max);
	ret1 = printf("%#010.3f, %Lf", 0.12500016, 45654654.8989L);
	ret2 = ft_printf("%#010.3f, %Lf", 0.12500016, 45654654.8989L);
	ft_putchar('\n');
	ft_putnbr(ret1);
	ft_putchar(':');
	ft_putnbr(ret2);
	ft_putchar('\n');
	return (ret2);
}

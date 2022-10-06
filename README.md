# Ft_printf @ SBER school 21 (42)

**Recode of C's printf for understanding of variadic functions and printing.**

[Program Specs](https://github.com/kravchenkovmiit/ft_printf/blob/master/ft_printf.pdf)

[School Code Formatting Standards - The Norm](https://github.com/kravchenkovmiit/flt/blob/master/Norm.pdf)

## Compiling
`make libftprintf.a`

## Usage
Use it like you would use the `printf` function:

```c

printf("printf:    %#010.3f, %Lf\n", 0.12500016, 45654654.8989L);
ft_printf("ft_printf: %#010.3f, %Lf\n", 0.12500016, 45654654.8989L);
ft_printf("Hello! %-s _ %% _%0+ #5-c _%+013d _ %x, %o, %p\n", "Yo!", 'k', -2147483647, ds, 211, s);

```
```
printf:    000000.125, 45654654.898900
ft_printf: 000000.125, 45654654.898900

Hello! Yo! _ % _k     _-002147483647 _ 53e2, 323, 0x7ffe0d768b9c
```

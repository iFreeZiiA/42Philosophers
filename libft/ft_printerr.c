/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printerr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alearroy <alearroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:23:06 by alearroy          #+#    #+#             */
/*   Updated: 2025/01/16 16:26:48 by alearroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbrerr_ptr(unsigned long long n, char *base, int *nb_print)
{
	if (n >= 16)
		ft_putnbrerr_ptr(n / 16, base, nb_print);
	ft_pferr_putchar(base[n % 16], nb_print);
}

void	selecterr_format(va_list args, int word, int *nb_print)
{
	if (word == 'c')
		ft_pferr_putchar(va_arg(args, int), nb_print);
	else if (word == 's')
		ft_pferr_putstr(va_arg(args, char *), nb_print);
	else if (word == 'p')
		ft_pointererr(va_arg(args, unsigned long long), nb_print);
	else if (word == 'd' || word == 'i')
		ft_pferr_putnbr(va_arg(args, int), nb_print);
	else if (word == 'u')
		ft_pferr_putnbr(va_arg(args, unsigned int), nb_print);
	else if (word == 'x')
		ft_putnbrerr_hexa(va_arg(args, int), HEXA_LOW, nb_print);
	else if (word == 'X')
		ft_putnbrerr_hexa(va_arg(args, int), HEXA_CAP, nb_print);
	else if (word == '%')
		ft_pferr_putchar('%', nb_print);
}

int	ft_printerr(const char *str, ...)
{
	va_list	args;
	char	*malloc_str;
	int		nb_print;
	int		i;

	malloc_str = ft_strdup(str);
	if (!malloc_str)
		return (0);
	i = 0;
	nb_print = 0;
	va_start(args, str);
	while (malloc_str[i])
	{
		if (malloc_str[i] != '%')
			ft_pferr_putchar(malloc_str[i], &nb_print);
		else if (str[i + 1])
			selecterr_format(args, malloc_str[++i], &nb_print);
		i++;
	}
	va_end(args);
	free (malloc_str);
	return (nb_print);
}

/* #include "stdio.h"

int main() {
	int	num = 42;
	unsigned int	u_num = 42;
	char	*str = "Hello, World!";
	char	c = 'A';
	void	*ptr = (void *)0x7ffeefbff5c0;

	printf("Using printf:\n");
	printf("Integer: %d\n", num);
	printf("Hexadecimal (lowercase): %x\n", num);
	printf("Hexadecimal (uppercase): %X\n", num);
	printf("Pointer: %p\n", ptr);
	printf("Unsigned Integer: %u\n", u_num);
	printf("String: %s\n", str);
	printf("Character: %c\n", c);

	printf("\nUsing ft_printf:\n");
	ft_printf("Integer: %d\n", num);
	ft_printf("Hexadecimal (lowercase): %x\n", num);
	ft_printf("Hexadecimal (uppercase): %X\n", num);
	ft_printf("Pointer: %p\n", ptr);
	ft_printf("Unsigned Integer: %u\n", u_num);
	ft_printf("String: %s\n", str);
	ft_printf("Character: %c\n", c);
	return (0);
} */
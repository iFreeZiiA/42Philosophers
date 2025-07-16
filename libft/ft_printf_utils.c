/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alearroy <alearroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:15:54 by alearroy          #+#    #+#             */
/*   Updated: 2024/11/12 16:33:11 by alearroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_pf_putchar(char c, int *nb_print)
{
	write(1, &c, 1);
	*nb_print += 1;
}

void	ft_pf_putstr(char *str, int *nb_print)
{
	int	i;

	if (!str)
		str = "(null)";
	i = ft_strlen(str);
	write(1, str, i);
	*nb_print += i;
}

void	ft_pf_putnbr(long long n, int *nb_print)
{
	if (n < 0)
	{
		ft_pf_putchar('-', nb_print);
		n = -n;
	}
	if (n >= 10)
		ft_pf_putnbr(n / 10, nb_print);
	ft_pf_putchar((n % 10) + '0', nb_print);
}

void	ft_putnbr_hexa(unsigned int n, char *base, int *nb_print)
{
	if (n >= 16)
		ft_putnbr_hexa(n / 16, base, nb_print);
	ft_pf_putchar(base[n % 16], nb_print);
}

void	ft_pointer(unsigned long long pointer, int *nb_print)
{
	if (!pointer)
	{
		ft_pf_putstr("(nil)", nb_print);
		return ;
	}
	ft_pf_putstr("0x", nb_print);
	if (pointer >= 16)
		ft_putnbr_ptr(pointer / 16, HEXA_LOW, nb_print);
	ft_pf_putchar(HEXA_LOW[pointer % 16], nb_print);
}

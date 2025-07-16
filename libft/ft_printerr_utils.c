/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printerr_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alearroy <alearroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:23:33 by alearroy          #+#    #+#             */
/*   Updated: 2025/02/19 18:52:03 by alearroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_pferr_putchar(char c, int *nb_print)
{
	write(2, &c, 1);
	*nb_print += 1;
}

void	ft_pferr_putstr(char *str, int *nb_print)
{
	int	i;

	if (!str)
		str = "(null)";
	i = ft_strlen(str);
	write(1, str, i);
	*nb_print += i;
}

void	ft_pferr_putnbr(long long n, int *nb_print)
{
	if (n < 0)
	{
		ft_pferr_putchar('-', nb_print);
		n = -n;
	}
	if (n >= 10)
		ft_pferr_putnbr(n / 10, nb_print);
	ft_pferr_putchar((n % 10) + '0', nb_print);
}

void	ft_putnbrerr_hexa(unsigned int n, char *base, int *nb_print)
{
	if (n >= 16)
		ft_putnbrerr_hexa(n / 16, base, nb_print);
	ft_pferr_putchar(base[n % 16], nb_print);
}

void	ft_pointererr(unsigned long long pointer, int *nb_print)
{
	if (!pointer)
	{
		ft_pferr_putstr("(nil)", nb_print);
		return ;
	}
	ft_pferr_putstr("0x", nb_print);
	if (pointer >= 16)
		ft_putnbrerr_ptr(pointer / 16, HEXA_LOW, nb_print);
	ft_pferr_putchar(HEXA_LOW[pointer % 16], nb_print);
}

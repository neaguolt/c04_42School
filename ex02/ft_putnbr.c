/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deb <neaguolt@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 19:39:28 by deb               #+#    #+#             */
/*   Updated: 2024/08/06 21:24:16 by deb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb);

void	ft_putnbr(int nb)
{
	char	digits[10];
	int		it;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return;
	}
	if (nb == 0)
	{
		write(1, "0", 1);
		return;
	}
	if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
	}
	it = 9;
	while (nb > 0)
	{
		digits[it] = (nb % 10) + '0';
		nb = nb / 10;
		it--;
	}
	write(1, &digits[it + 1], (9 - it));
}

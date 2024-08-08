/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deb <neaguolt@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 19:30:30 by deb               #+#    #+#             */
/*   Updated: 2024/08/08 16:52:09 by deb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_base(int nbr, char *base);
int		is_valid(char ch);
int		valid_base(char *base);

int	is_valid(char ch)
{
	if (((ch > 47) && (ch < 58)) || ((ch > 64) && (ch < 91))
		|| ((ch > 96) && (ch < 123)))
		return (1);
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	char	buffer[33];
	int		size;
	int		it;

	size = valid_base(base);
	it = 0;
	buffer[32] = '\0';
	if (nbr == 0)
		write(1, "0", 1);
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr == -2147483648)
		write(1, "10000000000000000000000000000000", 33);
	if (size)
	{
		while (nbr > 0)
		{
			buffer[31 - it++] = base[nbr % size];
			nbr = nbr / size;
		}
		write(1, &buffer[32 - it], it);
	}
}

int	valid_base(char *base)
{
	int	it;
	int	it2;

	if (*base == '\0' || *(base + 1) == '\0' || !is_valid(*base))
		return (0);
	it = 1;
	while (is_valid(base[it]))
	{
		it2 = it - 1;
		while (it2 + 1)
		{
			if (base[it] == base[it2])
				return (0);
			it2--;
		}
		it++;
	}
	return (it);
}
/*
int	main(void)
{
	ft_putnbr_base(-2147483648, "01");
} */

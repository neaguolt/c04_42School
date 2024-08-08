/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deb <neaguolt@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:54:23 by deb               #+#    #+#             */
/*   Updated: 2024/08/08 19:10:41 by deb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_atoi_base(char *str, char *base);

int	valid_base(char *base);

int	valid_ch(char ch);

int	index_ch(char ch, char *base);

int	index_ch(char ch, char *base)
{
	int	it;

	it = 0;
	while (base[it] && ch != base[it])
		it++;
	return (it);
}

int	valid_ch(char ch)
{
	if (((ch > 47) && (ch < 58)) || ((ch > 64) && (ch < 91))
		|| ((ch > 96) && (ch < 123)))
		return (1);
	return (0);
}

int	valid_base(char *base)
{
	int	it;
	int	it2;

	if (!*base || !base[1] || !valid_ch(*base))
		return (0);
	it = 1;
	while (valid_ch(base[it]))
	{
		it2 = it -1;
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

int	ft_atoi_base(char *str, char *base)
{
	int	size;
	int	it;
	int	nbr;

	size = valid_base(base);
	if (size)
	{
		it = 0;
		nbr = 0;
		while (*str == ' ' || *str == '+' || *str == '-')
		{
			if (*str == '-')
				it++;
			str++;
		}
		while (valid_ch(*str))
		{
			nbr = nbr * size + index_ch(*str, base);
			str++;
		}
		if (it % 2)
			nbr = -nbr;
		return (nbr);
	}
	return (0);
}
/*
int	main(void)
{
	printf("Nr is: %d\n", ft_atoi_base("     +---59", "0123456789abcdef"));
	return (0);
} */

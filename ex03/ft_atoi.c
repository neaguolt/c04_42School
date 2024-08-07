/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deb <neaguolt@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:54:06 by deb               #+#    #+#             */
/*   Updated: 2024/08/07 17:17:37 by deb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *str);

int		validch(char ch);

int		generate_int(char *str, int size);

char	*is_no(char *str, int *size);

char	*is_no(char *str, int *size)
{
	int	it;

	it = 0;
	while (*str != '\0' && validch(*str) && *str == '0')
	{
		it++;
		str++;
	}
	if (it)
	{
		if ((*str == '\0') || ((*str < 47) && (*str > 58)))
		{
			*size = 1;
			return (str - 1);
		}
		else
			it = 0;
	}
	while ((str[it] != '\0') && (str[it] > 47) && (str[it] < 58))
		it++;
	*size = it;
	return (str);
}

int	validch(char ch)
{
	if (ch != '\0')
	{
		if ((ch > 47) && (ch < 58))
			return (1);
		if ((ch == ' ') || (ch == '-') || (ch == '+'))
			return (1);
	}
	return (0);
}

int	generate_int(char *str, int size)
{
	int	no;
	int	it;
	int	pow;

	it = 0;
	no = 0;
	while (size - 1)
	{
		it = size - 1;
		pow = 1;
		while (it--)
			pow = pow * 10;
		if (*str == '0')
			pow = pow * (*str - 47);
		else
			pow = pow * (*str - 48);
		size--;
		str++;
		no = no + pow;
	}
	no = no + *str -48;
	return (no);
}

int	ft_atoi(char *str)
{
	int		isminus;
	int		no;
	int		size;
	char	*str2;

	isminus = 0;
	size = 0;
	while (validch(*str))
	{
		if (*str == '-')
			isminus = !isminus;
		str2 = is_no(str, &size);
		if (size)
		{
			no = generate_int(str2, size);
			if (isminus)
				no = -no;
			return (no);
		}
		str++;
	}
	return (0);
}
/*
int	main(void)
{
	int	no1;

	no1 = ft_atoi("abc123");
} */

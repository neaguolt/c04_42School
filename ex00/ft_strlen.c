/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deb <neaguolt@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 19:16:26 by deb               #+#    #+#             */
/*   Updated: 2024/08/06 19:25:15 by deb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str);

int	ft_strlen(char *str)
{
	int	it;
	char	*original;

	it = 0;
	original = str;
	while (*str != '\0')
	{
		it++;
		str++;
	}
	str = original;
	return (it);
}

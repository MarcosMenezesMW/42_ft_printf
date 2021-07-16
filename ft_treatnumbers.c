/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treatnumbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <mwmms@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 20:43:45 by mameneze          #+#    #+#             */
/*   Updated: 2021/07/16 17:46:56 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_number_len(char conversion, unsigned int number)
{
	int	len;

	len = 0;
	if (conversion == 'x' || conversion == 'X' || conversion == 'p')
	{
		while (number != 0)
		{
			number /= 16;
			len++;
		}
	}
	return (len);
}

int	treat_integer(int number, int width)
{
	char	*str;
	int		len;

	str = ft_itoa(number);
	len = ft_strlen(str);
	print_spaces(width - len);
	write(1, str, len);
	free(str);
	return (len);
}

int	treat_uint(unsigned int number, int width)
{
	char	*str;
	int		len;
	int		keptlen;
	long	n_value;

	if (number == 0)
		return (write(1, "0", 1), 1);
	len = 0;
	n_value = number;
	while (number != 0)
	{
		number /= 10;
		len++;
	}
	keptlen = len;
	str = malloc(len + 1);
	str[len] = '\0';
	while (len-- != 0)
	{
		str[len] = n_value % 10 + '0';
		n_value /= 10;
	}
	print_spaces(width - keptlen);
	write(1, str, keptlen);
	free(str);
	return (keptlen);
}

int	treat_hexa(char conversion, unsigned int number, int width)
{
	char	*hexa;
	char	*str;
	int		len;
	int		keptlen;

	if (number == 0)
		return (write(1, "0", 1), 1);
	if (conversion == 'x')
		hexa = "0123456789abcdef";
	else
		hexa = "0123456789ABCDEF";
	len = get_number_len(conversion, number);
	keptlen = len;
	str = malloc(len + 1);
	str[len] = '\0';
	while (len-- > 0)
	{
		str[len] = hexa[number % 16];
		number /= 16;
	}
	print_spaces(width - keptlen);
	write(1, str, keptlen);
	free(str);
	return (keptlen);
}

int	treat_pointer(size_t address, int width)
{
	char	*hexa;
	char	*str;
	int		len;
	int		keptlen;
	size_t	num;
	
	if (address == 0)
		return (write(1, "0", 1), 1);
	len = 2;
	num = address;
	hexa = "0123456789abcdef";
	while (num != 0 && ++len)
		num /= 16;
	keptlen = len;
	str = malloc(len + 3);
	str[len] = '\0';
	while (len-- > 0)
	{
		str[len] = hexa[address % 16];
		address /= 16;
	}
	str[0] = '0';
	str[1] = 'x';
	print_spaces(width - keptlen);
	write(1, str, keptlen);
	free(str);
	return (keptlen);
}

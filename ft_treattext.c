/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treattext.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <mwmms@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 20:23:26 by mameneze          #+#    #+#             */
/*   Updated: 2021/07/16 16:15:21 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int treat_char(char c, int width)
{
	print_spaces(width);
	write(1, &c, 1);
	return (2);	
}

int	treat_string(char *str, int width)
{
	int	len;

	len = ft_strlen(str);
	print_spaces(width - len);
	write(1, str, len);
	return (len + 1);
}

int	print_spaces(int width)
{
	int	len;
	len = width;
	while (width-- > 0)
		write(1, " ", 1);
	return (len);
}

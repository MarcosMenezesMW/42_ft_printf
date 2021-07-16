/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <mwmms@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 17:24:58 by mameneze          #+#    #+#             */
/*   Updated: 2021/07/14 23:41:12 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
int	isconversion(const char format)
{
	char	*flaglist;

	flaglist = "cspdiuxX";
	if (ft_strchr(flaglist, format) == NULL)
		return (0);
	else
		return (1);
}

int	check_conversion(char c, va_list ap, int width)
{
	if (c == 'c')
		return (print_spaces(width - 1), (ft_put_char(va_arg(ap, int))));
	else if (c == 's')
		return (treat_string(va_arg(ap, char *), width));
	else if (c == 'p')
		return (treat_pointer(va_arg(ap, size_t), width));
	else if (c == 'd' || c == 'i')
		return (treat_integer(va_arg(ap, int), width));
	else if (c == 'u')
		return (treat_uint(va_arg(ap, unsigned int), width));
	else if (c == 'x')
		return (treat_hexa(c, va_arg(ap, unsigned int), width));
	else if (c == 'X')
		return (treat_hexa(c, va_arg(ap, unsigned int), width));
	else if (c == '%')
		return (ft_put_char('%'));
	else
		return (0);
}

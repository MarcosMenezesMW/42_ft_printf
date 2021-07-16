/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <mwmms@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 17:00:52 by mameneze          #+#    #+#             */
/*   Updated: 2021/07/14 22:39:54 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	treat_conditions(const char *format, int c_len, va_list ap, int *ptd)
{
	int	width;

	width = 0;
	if (format[c_len] == '%')
	{
		c_len++;
		if (!ft_isdigit(format[c_len]) && !isconversion(format[c_len]))
			*ptd += ft_put_char(format[c_len]);
		if (ft_isdigit(format[c_len]))
		{
			while (format[c_len] >= '0' && format[c_len] <= '9')
			{
				width = (width * 10) + (format[c_len++] - '0');
			}
			*ptd += width;
		}
		if (isconversion(format[c_len]))
			*ptd += check_conversion(format[c_len], ap, width);
	}
	else
		*ptd += ft_put_char(format[c_len]);
	return (c_len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		ptd;

	i = -1;
	ptd = -1;
	va_start(ap, format);
	while (format[++i])
	{
		i = treat_conditions(format, i, ap, &ptd);
	}
	return (ptd);
}

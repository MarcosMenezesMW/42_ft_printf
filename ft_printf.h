/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <mwmms@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 18:20:23 by mameneze          #+#    #+#             */
/*   Updated: 2021/07/16 16:21:39 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdarg.h>
# include "./Libft/libft.h"

int		print_spaces(int width);
int		ft_printf(const char *format, ...);
int		ft_put_char(char c);
int		isconversion(const char format);
int		check_conversion(char c, va_list ap, int width);
int		treat_char(char c, int width);
int		treat_string(char *str, int width);
int		treat_pointer(size_t address, int width);
int		treat_integer(int number, int width);
int		treat_uint(unsigned int number, int width);
int		treat_hexa(char conversion, unsigned int number, int width);

#endif

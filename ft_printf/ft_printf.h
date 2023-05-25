/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbranco- <jbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:57:56 by jbranco-          #+#    #+#             */
/*   Updated: 2022/12/10 14:50:14 by jbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

size_t	ft_putstr(char *str);
size_t	ft_putnbr_u(size_t n);
size_t	ft_putpointer_hex(size_t n);

int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_puthex_lower(size_t n);
int		ft_puthex_upper(size_t n);
int		ft_putnbr(int n);
int		val_size_hex(size_t n);
int		val_size_dec(int n);
int		val_size_u(int n);

#endif

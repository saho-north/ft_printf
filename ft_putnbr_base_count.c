/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_count.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 00:55:30 by sakitaha          #+#    #+#             */
/*   Updated: 2023/08/14 17:23:11 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_putnbr_ul_base_count(unsigned long num, const char *base)
{
	ssize_t	ret;
	size_t	base_size;
	char	c;

	if (!base)
		return (-1);
	base_size = ft_strlen(base);
	if (num < base_size)
	{
		c = base[num];
		if (write(1, &c, 1) < 0)
			return (-1);
		return (1);
	}
	ret = ft_putnbr_ul_base_count(num / base_size, base);
	if (ret < 0)
		return (-1);
	c = base[num % base_size];
	if (write(1, &c, 1) < 0)
		return (-1);
	return (ret + 1);
}

ssize_t	ft_putnbr_base_count(int n, const char *base)
{
	unsigned long	num;
	ssize_t			ret;
	bool			is_minus;

	if (n < 0)
	{
		if (write(1, "-", 1) < 0)
			return (-1);
		num = (unsigned long)((n + 1) * -1) + 1;
		is_minus = true;
	}
	else
	{
		num = (unsigned long)n;
		is_minus = false;
	}
	ret = ft_putnbr_ul_base_count(num, base);
	if (ret < 0)
		return (-1);
	if (is_minus)
		ret++;
	return (ret);
}

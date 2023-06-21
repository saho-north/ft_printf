/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 21:48:40 by sakitaha          #+#    #+#             */
/*   Updated: 2023/06/22 00:24:24 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_putptr_fd_count(void *ptr, int fd)
{
	ssize_t	ret;

	if (!ptr)
		return (ft_putstr_fd_count("(nil)", fd));
	ret = ft_putstr_fd_count("0x", fd);
	if (ret < 0)
		return (-1);
	ret = ft_putnbr_fd_bc_unsigned((unsigned long)ptr, "0123456789abcdef", fd);
	if (ret < 0)
		return (-1);
	return (ret + 2);
}
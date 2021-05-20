/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efrancon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:27:19 by efrancon          #+#    #+#             */
/*   Updated: 2021/05/20 14:27:20 by efrancon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	nb = (unsigned)n;
	if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
		nb %= 10;
	}
	ft_putchar_fd(nb + '0', fd);
}

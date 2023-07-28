/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:38:12 by jihyjeon          #+#    #+#             */
/*   Updated: 2023/07/27 19:20:22 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	to_hex(long long ad)
{
	if (ad <16)
		write (1, &"0123456789abcdef"[ad], 1);
	else
	{
		to_hex (ad / 16);
		to_hex (ad % 16);
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	int i;

	i = 0;
	while ((size) && (addr[i]))
	{
		to_hex ((long long)&addr[i]);
		write (1, ": ", 2);
		i += 16;
	}
}

int main (void)
{
	char s1[] = "iloveyou iloveyou iloveyou iloveyou iloveyou iloveyou";
	ft_print_memory(s1, 56);
}

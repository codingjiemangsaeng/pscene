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
#include <stdio.h>
#include <string.h>

void	hex_addr(long long ad, unsigned int n)
{
	while(ad == 0 && n < 16)
	{
		write (1, &"0123456789abcdef"[ad], 1);
		n++;
	}
	if (ad != 0)
	{
		hex_addr (ad / 16, ++n);
		write (1, &"0123456789abcdef"[ad % 16], 1);
	}
}

void hex_con(void *addr, unsigned int i, unsigned int size){
	unsigned int ix;
	
	ix = i;
	while(i < ix + 16){
		if(i>=size)
			write(1, "  ", 2);
		else
		{
			write(1, &"0123456789abcdef"[(*((unsigned char *)addr +i))/16], 1);
			write(1, &"0123456789abcdef"[(*((unsigned char *)addr +i))%16], 1);
		}
		if(i%2)
			write(1, " ", 1);
		i++;
	}
}

void print_able(void *addr, unsigned int i, unsigned int size){
	unsigned int ix;
	
	ix = i;
	while(i < ix + 16){
		if(i>=size)
			write(1, " ", 1);
		else if (*(char *)(addr + i)>=32 && *(char *)(addr + i)<= 126)
			write(1, (char *)(addr + i), 1);
		else
			write(1, ".", 1);
		i++;
	}
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int i;
	
	i = 0;
	while (i < size)
	{
		hex_addr ((long long)&addr[i], 0);
		write (1, ": ", 2);
		hex_con (addr, i, size);
		print_able(addr, i, size);
		i += 16;
	}
	return (addr);
}

int main() {
	char *test = "\220Salut lasd wlaks' \320asdkas\220da klaskd\1 aksdjladkjwdn andawkw\1\1asdasdajwkd";
	char *test30 = "\0";
	ft_print_memory(test, strlen(test));
	printf("\n\n");
	ft_print_memory(test30, strlen(test30));
	printf("\n\n------------------------------\n\n");
}

//
//  main.c
//  C02
//
//  Created by Jihyun Jeong on 7/26/23.
//

#include <stdio.h>
#include <string.h>
//char    *ft_strcpy(char *dest, char *src)
//{
//    while (*src)
//    {
//        *dest = *src;
//        dest++;
//        src++;
//    }
//    *dest = '\0';
//    return (dest);
//}

//unsigned int    ft_strlcpy(char *dest, char *src, unsigned int size)
//{
//    unsigned int    i;
//    unsigned int    len;
//
//    i = 0;
//    len = 0;
//    while (*(src + len))
//        len ++;
//    while (*(src + i) && i + 1 < size)
//    {
//        *(dest + i) = *(src + i);
//        i ++;
//    }
//    while (size > 0)
//    {
//        *(dest + i) = '\0';
//    }
//
//    return (len);
//}

//int main (){
//    char s1[20] = "I love you baby ...";
////    printf("%u\n", ft_strlcpy(s1,"Hell",7));
////    printf("%lu" , strlcpy(s1,"Hell",7));
////    printf("%c", s1[7]);
//    printf("%p",&s1[0]);
//}

#include <unistd.h>

void    to_hex(long long ad, int n)
{
//    char buf[16];
//
    if (ad <16){
        while (n<16){
            to_hex(ad/16, ++n);
        }
        write (1, &"0123456789abcdef"[ad], 1);
    }
    else
    {
        to_hex (ad / 16,++n);
        to_hex (ad % 16,n);
    }
}


void    *ft_print_memory(void *addr, unsigned int size)
{
    int i;

    i = 0;
    while (i <= size)
    {
        to_hex ((long long)&addr[i], 0);
        write (1, ": \n4", 3);
        i += 16;
    }
    return (addr);
}

int main (void)
{
    char s1[] = "iloveyou iloveyou iloveyou iloveyou iloveyou iloveyou";
    ft_print_memory(s1, 56);
}

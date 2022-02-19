/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 17:13:36 by mnajid            #+#    #+#             */
/*   Updated: 2022/02/19 17:14:17 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdarg.h>
#include<unistd.h>
#include<stdio.h>
void ft_putchar(int c,int *len)
{
    write(1,&c,1);
    (*len)++;
}

void ft_putstr(char *str,int *len)
{
    int i;
    i = 0;
    if(!str)
        ft_putstr("(null)",len);
    else
        while (str[i])
            ft_putchar(str[i++],len);    
}
void ft_putnbr(int n,int *len)
{
    long nb;
    nb = n;
    if(nb < 0)
    {
        ft_putchar('-',len);
        nb *= -1;
    }
    if(nb < 10)
    {
        ft_putchar(nb + 48,len);
    }
    else
    {
        ft_putnbr(nb/10,len);
        ft_putchar(nb%10 + 48,len);
    }
}

void ft_puthex(unsigned int nb,int *len)
{
    char *set;
    set = "0123456789abcdef";
    if(nb < 16)
    {
        ft_putchar(set[nb],len);
    }
    else
    {
        ft_puthex(nb/16,len);
        ft_putchar(set[nb%16],len);
    }
}


void ft_check_format(va_list args,char c,int *len)
{
    if(c == 'c')
        ft_putchar(va_arg(args,int),len);
    else if(c == 's')
        ft_putstr(va_arg(args,char *),len);
    else if(c == 'd')
        ft_putnbr(va_arg(args,int),len);
    else if(c == 'x')
        ft_puthex(va_arg(args,unsigned int),len);
}
int	ft_printf(const char *format, ...)
{
    va_list args;
    int len;
    int i;
    i = 0;
    len = 0;

    va_start(args,format);
    while (format[i])
    {
        if( format[i] == '%')
        {
            i++;
            ft_check_format(args,format[i],&len);
        }
        else
        {
            write(1,&format[i],1);
            len++;
        }
        i++;
    }
    va_end(args);
    return(len);
}
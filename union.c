/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 17:13:20 by mnajid            #+#    #+#             */
/*   Updated: 2022/02/19 17:13:26 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int main(int ac, char **av)
{
    int used[255];
    int i,j;
    if (ac == 3)
    {
        i = 0 ;
        while (i < 255)
            used[i++] = 0;
        i = 1;
        while (i < 3)
        {
            j = 0;
            while (av[i][j])
            {
                if(!used[(unsigned char)av[i][j]])
                {
                    used[(unsigned char)av[i][j]] = 1;
                    write(1,&av[i][j],1);
                }
                j++;
            }
            i++;
        }
    }
    write(1,"\n",1);
    return(0);
}
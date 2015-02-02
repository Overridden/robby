/*
** basic_tools.c for robby in /home/nguye_1//projects/prog_elem_c/robby
** 
** Made by alexandre1 nguyen
** Login   <nguye_1@epitech.net>
** 
** Started on  Fri Jun 21 20:52:54 2013 alexandre1 nguyen
** Last update Fri Jun 28 11:09:17 2013 alexandre1 nguyen
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "robby.h"

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    i += 1;
  return (i);
}

int		my_strcmp(char *str1, char *str2)
{
  int		i;

  i = 0;
  while (str1[i] && str2[i])
    {
      if (str1[i] != str2[i])
	return (EXIT_FAILURE);
      i += 1;
    }
  if (i != my_strlen(str1) || i != my_strlen(str2))
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

void		ps(char *str)
{
  if (write(1, str, my_strlen(str)) < 0)
    return ;
  return ;
}
